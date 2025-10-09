/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for FCS
 */

/**
 * @defgroup fcs_sample FCS
 * @ingroup samples
 *
 * Sample Application for FCS.
 *
 * @details
 * @section fcs_desc Description
 * This is a sample application to demonstrate some of the cryptographic functionalities provided by the SDM.
 * A cryptographic session is to be opened to perform the cryptographic functions.
 * If the functions require a key, it may be imported or created. The user can access these functions through the libFCS library.
 *
 * @section fcs_pre Prerequisites
 * All the required keys should be available in the sdmmc before running the sample.
 * The names of the corresponding keys and their corresponding key IDs should be changed in the sample.
 *
 * @section fcs_param Configurable Parameters
 * - All key names can be configured at their corrseponding macros
 * - All key IDs can be configured at their corresponding macros
 * - Modes of operation can also be configured for ECC related cryptographic functions
 * - Input size can be configured in @c INPUT_DATA_SIZE macro
 * @note Ensure the correct key ID and modes are provided
 * @section fcs_howto How to Run
 * 1. Follow the common README for build and flashing instructions.
 * 2. Copy all the required key files to the SD card.
 * 3. Ensure key ID matches the keys in the SD card. Change the corresponding macros if it doesnt.
 * 4. Run the sample.
 *
 * @section fcs_res Expected Results
 * - The success/failure logs are displayed in the console.
 * @{
 */
/** @} */

#include <stdint.h>

#include "osal.h"
#include "osal_log.h"
#include "string.h"
#include "socfpga_fcs.h"
#include "socfpga_smmu.h"
#include "ff_sddisk.h"
#include "libfcs.h"

#define READ_MODE        0x01
#define MOUNTED          1
#define UNMOUNTED        0
#define MOUNT_SD_CARD    -1

#define MAX_KEY_SIZE       240U
#define INPUT_DATA_SIZE    128U

#define CHIP_SEL_0      0x00000000
#define AES_FILE        "/gc256"
#define AES_AAD_SIZE    32
#define AES_KEY_ID      0x5C
#define AES_IV_SIZE     16U
#define AES_TAG_SIZE    16U

#define DIGEST_KEY_FILE    "/hm256"
#define DIGEST_KEY_ID      22U

#define ECC_FILE               "/bp384"
#define ECC_FILE_KEY_ID        43U
#define ECC_MODE               4U
#define ECC_EXCHANGE_FILE      "/bpe384"
#define ECC_EXCHANGE_KEY_ID    45U

#define VALID_DATA_RES    0x000900D

static FF_Disk_t *disk_obj = NULL;
static uint8_t mount_status = UNMOUNTED;

/*Functions to read data from a file_name*/
static void fat_mount(const char *MountName)
{

    disk_obj = FF_SDDiskInit(MountName, MOUNT_SD_CARD);
    if (disk_obj != NULL)
    {
        mount_status = MOUNTED;
    }
    else
    {
        ERROR("Mounting Failed");
    }
}

static void fat_unmount(void)
{
    if (disk_obj == NULL)
    {
        ERROR("No mounted devices");
        return;
    }
    FF_Unmount(disk_obj);
    FF_SDDiskDelete(disk_obj);
    disk_obj = NULL;
    mount_status = UNMOUNTED;
}

static uint32_t fat_get_size(const char *file_name)
{
    int ret;
    uint32_t file_size;
    FF_Error_t error;
    FF_FILE *file;
    fat_mount("root");
    if (disk_obj == NULL)
    {
        ERROR("Failed to mount");
        return 0;
    }
    file = FF_Open(disk_obj->pxIOManager, file_name, FF_MODE_READ, &error);
    if ((file == NULL) || (error != FF_ERR_NONE))
    {
        ERROR("Failed to open file_name for reading\r\n");
        FF_Unmount(disk_obj);
        FF_SDDiskDelete(disk_obj);
        return 0;
    }

    ret = FF_GetFileSize(file, &file_size);
    if (ret != 0)
    {
        ERROR("Error getting file_name size ");
        return 0;
    }
    FF_Close(file);
    return file_size;
}

static uint32_t fat_read(const char *file_name, void *buffer)
{
    FF_Error_t error;
    uint32_t bytes_read = 0;
    FF_FILE *file;
    fat_mount("root");
    if (disk_obj == NULL)
    {
        ERROR("Failed to mount");
        return 0;
    }
    file = FF_Open(disk_obj->pxIOManager, file_name, FF_MODE_READ, &error);
    if ((file == NULL) || (error != FF_ERR_NONE))
    {
        ERROR("Failed to open file_name for reading\r\n");
        FF_Unmount(disk_obj);
        FF_SDDiskDelete(disk_obj);
        return 0;
    }
    if (file != NULL)
    {
        bytes_read = FF_Read(file, 1, file->ulFileSize, (uint8_t *)buffer);
        FF_Close(file);
    }
    fat_unmount();
    return bytes_read;
}

static void print_data(char *data, int size)
{
    int i;
    for (i = 0; i < (int)size; i++)
    {
        printf("%02x", data[i]);
        if (((i + 1) % 2) == 0)
        {
            printf("\t");
        }
        if (((i + 1) % 8) == 0)
        {
            printf("\r\n");
        }
    }
    printf("\r\n");
}

/* Sample application of QSPI modification using FCS */
static void fcs_qspi_sample()
{
    int ret, i;
    uint32_t chip_sel;
    char *input_data = (char *)pvPortMalloc(INPUT_DATA_SIZE);
    if (input_data == NULL)
    {
        ERROR("Failed to allocate memory");
        return;
    }
    /*Preparing data for input*/
    for (i = 0; i < INPUT_DATA_SIZE; i++)
    {
        input_data[i] = i;
    }
    PRINT("Input data");
    print_data(input_data, INPUT_DATA_SIZE);
    /*Opening a QSPI channel*/
    ret = fcs_qspi_open();
    if (ret != 0)
    {
        ERROR("Failed to open QSPI channel");
        vPortFree(input_data);
        return;
    }
    chip_sel = CHIP_SEL_0;
    ret = fcs_qspi_set_cs(chip_sel);
    if (ret)
    {
        ERROR("Failed to perform chip select");
    }
    else
    {
        /*
         * Erase a sector to prepare to write, erase requires
         * multiples of 1024 bytes
         */
        ret = fcs_qspi_erase(0x1000, 1024);
        if (ret)
        {
            ERROR("Failed to erase");
        }
        /* Write input data then read back */
        ret = fcs_qspi_write(0x1000, input_data, INPUT_DATA_SIZE / 4);
        if (ret)
        {
            ERROR("Failed to write");
        }
        else
        {
            PRINT("Resetting input buffer");
            memset(input_data, 0, INPUT_DATA_SIZE);
            ret = fcs_qspi_read(0x1000, input_data, INPUT_DATA_SIZE / 4);
            if (ret)
            {
                ERROR("Failed to read flash");
            }
            else
            {
                PRINT("Data from flash");
                print_data(input_data, INPUT_DATA_SIZE);
            }
        }
    }
    /* Close the QSPI channel */
    ret = fcs_qspi_close();
    if (ret)
    {
        ERROR("Failed to close QSPI channel");
    }
    vPortFree(input_data);
}
static void fcs_sample_encryption(char *session_id)
{
    int ret, i;
    char *aesfile = AES_FILE, *key_buf, *input_data, *resp_data,
            *iv_data, *tag_data;
    uint32_t bytes_read, context_id = 1, cipher_len = INPUT_DATA_SIZE;
    struct fcs_aes_req aes_req;

    key_buf = (char *)pvPortMalloc(fat_get_size(aesfile));
    PRINT("Importing AES key");
    /* Read the appropriate key for the following AES operation */
    bytes_read = fat_read(aesfile, (void *)key_buf);
    ret = fcs_import_service_key(session_id, key_buf, bytes_read, NULL, 0);
    if (ret)
    {
        ERROR("Failed to import AES key");
        return;
    }

    input_data = (char *)pvPortMalloc(INPUT_DATA_SIZE);
    resp_data = (char *)pvPortMalloc(INPUT_DATA_SIZE);

    /* setting data */
    PRINT("Plaintext");
    for (i = 0; i < (int)INPUT_DATA_SIZE; i++)
    {
        input_data[i] = i;
    }
    print_data(input_data, INPUT_DATA_SIZE);
    PRINT("Sample using AES256-GCM ....");
    PRINT("Generating IV ....");

    /* GCM modes require a IV and AAD data, which we randomly generate. */
    iv_data = (char *)pvPortMalloc(16);
    if ((iv_data == NULL))
    {
        ERROR("Failed to allocate memory");
        return;
    }
    char *aad_data = (char *)pvPortMalloc(AES_AAD_SIZE);
    if ((aad_data == NULL))
    {
        ERROR("Failed to allocate memory");
        return;
    }
    /* 16 byte random data for IV */
    ret = fcs_random_number_ext(session_id, context_id, iv_data, AES_IV_SIZE);
    if (ret != 0)
    {
        ERROR("Failed to generate IV");
        return;
    }
    PRINT("\r\nIV generated");
    for (i = 0; i < (int)AES_IV_SIZE; i++)
    {
        printf("%02x", iv_data[i]);
    }
    printf("\r\n");
    /* AAD_SIZE random bytes for AAD data */
    ret = fcs_random_number_ext(session_id, context_id, aad_data, AES_AAD_SIZE);
    if (ret != 0)
    {
        ERROR("Failed to generate AAD");
        return;
    }
    PRINT("\r\nAAD generated");
    for (i = 0; i < (int)AES_AAD_SIZE; i++)
    {
        printf("%02x", aad_data[i]);
    }
    printf("\r\n");

    /* Memory to store response tag data */
    tag_data = (char *)pvPortMalloc(16);

    aes_req.crypt_mode = FCS_AES_ENCRYPT_MODE;
    aes_req.block_mode = FCS_AES_GCM;
    aes_req.iv_source = 0;
    aes_req.iv = iv_data;
    aes_req.iv_len = AES_IV_SIZE;
    aes_req.tag = tag_data;
    aes_req.tag_len = 0x3;
    aes_req.aad_len = AES_AAD_SIZE;
    aes_req.aad = aad_data;
    aes_req.input = input_data;
    aes_req.ip_len = INPUT_DATA_SIZE;
    aes_req.output = resp_data;
    aes_req.op_len = &cipher_len;

    PRINT("Encrypting ....");
    ret = fcs_aes_crypt(session_id, AES_KEY_ID, context_id, &aes_req);
    if (ret)
    {
        ERROR("Failed to encrypt data");
        return;
    }
    PRINT("Ciphertext");
    print_data(resp_data, cipher_len);

    PRINT("Tag Data");
    print_data(tag_data, AES_TAG_SIZE);

    PRINT("Copying ciphertext to input location");
    memcpy(input_data, resp_data, INPUT_DATA_SIZE);

    PRINT("Decrypting....");
    aes_req.crypt_mode = FCS_AES_DECRYPT_MODE;
    context_id++;
    ret = fcs_aes_crypt(session_id, AES_KEY_ID, context_id, &aes_req);
    PRINT("STATUS : %d", ret);

    if (ret)
    {
        ERROR("Failed to decrypt data");
    }
    PRINT("Deciphered data");
    print_data(resp_data, INPUT_DATA_SIZE);
    printf("\r\n");
    (void)fcs_remove_service_key(session_id, AES_KEY_ID);
    vPortFree(iv_data);
    vPortFree(input_data);
    vPortFree(resp_data);
    vPortFree(key_buf);
}

static void fcs_sample_get_digest(char *session_id)
{
    char *key_buf, *input_data, *resp_data,
            res_match_status[4];
    uint32_t bytes_read, context_id = 2, digest_size = 0U,
            valid_data = VALID_DATA_RES,
            match_size;
    int i, ret;
    struct fcs_digest_get_req digest_req;
    struct fcs_mac_verify_req mac_verify;

    PRINT("Importing HMAC key");
    key_buf = (char *)pvPortMalloc(fat_get_size(DIGEST_KEY_FILE));
    bytes_read = fat_read(DIGEST_KEY_FILE, (void *)key_buf);
    ret = fcs_import_service_key((char *)session_id, key_buf, bytes_read, NULL,
            0);
    if (!ret)
    {
        PRINT("Input data");
        /* Setting input data */
        input_data = (char *)pvPortMalloc(INPUT_DATA_SIZE + 64);
        for (i = 0; i < (int)INPUT_DATA_SIZE; i++)
        {
            input_data[i] = i;
        }
        print_data(input_data, INPUT_DATA_SIZE);
        printf("\r\n");

        resp_data = (char *)pvPortMalloc(64);
        memset(resp_data, 0, 32);

        context_id++;
        digest_req.sha_op_mode = FCS_DIGEST_OPMODE_HMAC;
        digest_req.sha_digest_sz = FCS_DIGEST_SIZE_256;
        digest_req.src = input_data;
        digest_req.src_len = INPUT_DATA_SIZE;
        digest_req.digest = resp_data;
        digest_req.digest_len = &digest_size;
        PRINT("Generating Digest ....");
        ret = fcs_get_digest(session_id, context_id, DIGEST_KEY_ID,
                &digest_req);
        PRINT("STATUS : %d", ret);

        if (!ret)
        {
            PRINT("Digest Data");
            print_data(resp_data, digest_size);
            /* When using HMAC mode, we get a MAC. Verifying this MAC */
            PRINT("Verifying MAC ....");
            context_id++;
            memcpy(input_data + INPUT_DATA_SIZE, resp_data, digest_size);
            mac_verify.op_mode = FCS_DIGEST_OPMODE_HMAC;
            mac_verify.dig_sz = FCS_DIGEST_SIZE_256;
            mac_verify.src = input_data;
            mac_verify.src_sz = INPUT_DATA_SIZE + digest_size;
            mac_verify.dst = res_match_status;
            mac_verify.dst_sz = &match_size;
            mac_verify.user_data_sz = INPUT_DATA_SIZE;
            ret = fcs_mac_verify(session_id, context_id, DIGEST_KEY_ID,
                    &mac_verify);
            if (!memcmp(res_match_status, &valid_data,
                    sizeof(res_match_status)))
            {
                PRINT("MAC is valid");
            }
            else
            {
                ERROR("MAC is invalid");
            }
        }
        else
        {
            ERROR("Get digest operation failed");
        }
    }
    else
    {
        ERROR("Failed to import HMAC key");
    }
    vPortFree(key_buf);
}

static void fcs_sample_ecdh(char *session_id)
{
    int ret;
    char *key_buf, *pubkey_data, *resp_data;
    uint32_t bytes_read, context_id = 5, pubkey_size, shared_sec_size;
    struct fcs_ecdh_req ecdh_req;

    PRINT("Importing ECDSA Brainpool 384 key");
    key_buf = (char *)pvPortMalloc(fat_get_size(ECC_FILE));
    if (key_buf == NULL)
    {
        ERROR("Failed to allocate memory");
        return;
    }
    bytes_read = fat_read(ECC_FILE, (void *)key_buf);
    ret = fcs_import_service_key(session_id, key_buf, bytes_read, NULL, 0);
    if (ret)
    {
        ERROR("Failed to import key");
        return;
    }
    PRINT("Generating public key ....");
    pubkey_size = 256;
    pubkey_data = (char *)pvPortMalloc(256);
    if (pubkey_data == NULL)
    {
        ERROR("Failed to allocate memory");
        return;
    }
    ret = fcs_ecdsa_get_pub_key(session_id, context_id, ECC_FILE_KEY_ID,
            ECC_MODE, pubkey_data, &pubkey_size);
    if (ret)
    {
        ERROR("Failed to get public key");
    }
    PRINT("Public Key Data");
    print_data(pubkey_data, pubkey_size);

    /* Using the obtained public key and generating a shared secret.
     * This requires a exchange type key */
    PRINT("Importing ECDSA Brainpool 384 Exchange key");
    bytes_read = fat_read(ECC_EXCHANGE_FILE, (void *)key_buf);
    ret = fcs_import_service_key(session_id, key_buf, bytes_read, NULL, 0);
    if (ret)
    {
        ERROR("Failed to import key");
        return;
    }
    resp_data = (char *)pvPortMalloc(96);
    if (resp_data == NULL)
    {
        ERROR("Failed to allocate memory");
        return;
    }
    ecdh_req.ecc_curve = ECC_MODE;
    ecdh_req.pubkey = pubkey_data;
    ecdh_req.pubkey_len = pubkey_size;
    ecdh_req.shared_secret = resp_data;
    ecdh_req.shared_secret_len = &shared_sec_size;
    PRINT("Generating Shared Secret ....");
    memset(resp_data, 0x0, 48);
    ret = fcs_ecdh_request(session_id, ECC_EXCHANGE_KEY_ID, context_id,
            &ecdh_req);
    if (ret)
    {
        ERROR("Failed to generate shared secret");
        return;
    }
    PRINT("Shared Secret");
    print_data(resp_data, shared_sec_size);
    vPortFree(pubkey_data);
    vPortFree(resp_data);
    vPortFree(key_buf);
}

static void fcs_sample_signing(char *session_id)
{
    int ret, i;
    char *input_data, *resp_data,
            res_match_status[4];
    uint32_t context_id = 4, sign_size = 0U, status_size = 0U,
            valid_data = VALID_DATA_RES;
    struct fcs_ecdsa_req ecdsa_req;
    struct fcs_ecdsa_verify_req ecdsa_ver_req;

    PRINT("Input Data");
    input_data = (char *)pvPortMalloc(INPUT_DATA_SIZE);
    resp_data = (char *)pvPortMalloc(FCS_MAX_SIG_SIZE);
    for (i = 0; i < INPUT_DATA_SIZE; i++)
    {
        input_data[i] = i;
    }
    print_data(input_data, INPUT_DATA_SIZE);
    ecdsa_req.ecc_curve = 4;
    ecdsa_req.src = input_data;
    ecdsa_req.src_len = 48;
    ecdsa_req.dst = resp_data;
    ecdsa_req.dst_len = &sign_size;

    /* Hash sign input size requires same number of bits as in input key. */
    PRINT("Hash sign and verify operations");
    PRINT("Generating Signature ....");
    ret = fcs_ecdsa_hash_sign(session_id, context_id, ECC_FILE_KEY_ID,
            &ecdsa_req);
    if (ret)
    {
        ERROR("Failed to generate signature");
        return;
    }

    PRINT("Signature");
    print_data(resp_data, sign_size);

    ecdsa_ver_req.ecc_curve = 4;
    ecdsa_ver_req.src = input_data;
    /* Here we use a 348 bit key so 48 bytes */
    ecdsa_ver_req.src_len = 48;
    ecdsa_ver_req.signature = resp_data;
    ecdsa_ver_req.signature_len = sign_size;
    ecdsa_ver_req.pubkey = NULL;
    ecdsa_ver_req.pubkey_len = 0;
    ecdsa_ver_req.dst = res_match_status;
    ecdsa_ver_req.dst_len = &status_size;

    PRINT("Verifying signature ....");
    ret = fcs_ecdsa_hash_verify(session_id, context_id, ECC_FILE_KEY_ID,
            &ecdsa_ver_req);
    if (!memcmp(res_match_status, &valid_data, sizeof(res_match_status)))
    {
        PRINT("Signature is valid");
    }
    else
    {
        ERROR("Signature is invalid");
    }
    /* Size limitation is not present for sha2_sign */
    PRINT("SHA2 sign and verify operations");
    PRINT("Generating Signature ....");

    for (i = 0; i < INPUT_DATA_SIZE; i++)
    {
        input_data[i] = i;
    }
    ecdsa_req.ecc_curve = ECC_MODE;
    ecdsa_req.src = input_data;
    ecdsa_req.src_len = INPUT_DATA_SIZE;
    ecdsa_req.dst = resp_data;
    ecdsa_req.dst_len = &sign_size;

    ret = fcs_ecdsa_sha2_data_sign(session_id, context_id, ECC_FILE_KEY_ID,
            &ecdsa_req);
    if (ret)
    {
        ERROR("Failed to generate signature");
        return;
    }

    PRINT("Signature");
    print_data(resp_data, sign_size);
    PRINT("Verifying signature ....");

    ecdsa_ver_req.ecc_curve = ECC_MODE;
    ecdsa_ver_req.src = input_data;
    ecdsa_ver_req.src_len = INPUT_DATA_SIZE;
    ecdsa_ver_req.signature = resp_data;
    ecdsa_ver_req.signature_len = sign_size;
    ecdsa_ver_req.pubkey = NULL;
    ecdsa_ver_req.pubkey_len = 0;
    ecdsa_ver_req.dst = res_match_status;
    ecdsa_ver_req.dst_len = &status_size;

    ret = fcs_ecdsa_sha2_data_verify(session_id, context_id, ECC_FILE_KEY_ID,
            &ecdsa_ver_req);
    if (!memcmp(res_match_status, &valid_data, sizeof(res_match_status)))
    {
        PRINT("Signature is valid");
    }
    else
    {
        ERROR("Signature is invalid");
    }
    vPortFree(input_data);
    vPortFree(resp_data);
}

void fcs_task()
{
    int ret;
    char sess_uuid[FCS_UUID_SIZE];
    PRINT("FCS Sample");
    PRINT("Initialising libFCS");
    /* Initialise libfcs with a log level */
    ret = libfcs_init("log_off");

    if (!ret)
    {
        /* To perform cryptographic sessions, we are required to
         * open a session */
        PRINT("Opening FCS service session");
        ret = fcs_open_service_session(sess_uuid);
        if (ret == 0)
        {
            PRINT("QSPI sample");
            fcs_qspi_sample();
            PRINT("AES Encryption");
            fcs_sample_encryption(sess_uuid);
            PRINT("Digest Generation");
            fcs_sample_get_digest(sess_uuid);
            PRINT("Public Key and ECDH");
            fcs_sample_ecdh(sess_uuid);
            /* Using the same keys for the signing tests*/
            PRINT("Hash signing and SHA-2 signing");
            fcs_sample_signing(sess_uuid);
            ret = fcs_close_service_session(sess_uuid);
            if (ret)
            {
                ERROR("Failed to close FCS service session");
            }
        }
        else
        {
            ERROR("Failed to open FCS service session");
        }
        /* Free the FCS resources after use */
        ret = fcs_deinit();
        if (ret)
        {
            ERROR("Failed to free FCS resources");
        }
    }
    else
    {
        ERROR("Failed to initialise FCS");
        return;
    }
    PRINT("FCS Sample completed");
}
