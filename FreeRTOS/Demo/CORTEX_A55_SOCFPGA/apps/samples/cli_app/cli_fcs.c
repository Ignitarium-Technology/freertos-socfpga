/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for FCS
 */
/**
 * @defgroup cli_fcs FCS
 * @ingroup cli
 *
 * Performs cryptographic services
 *
 * @details
 * It supports the following subcommands:
 * - fcs open_session
 * - fcs close_session
 * - fcs random_number &lt;rand_size&gt; &lt;file&gt;
 * - fcs import_key &lt;file&gt;
 * - fcs export_key &lt;file&gt;
 * - fcs remove_key &lt;key_id&gt;
 * - fcs get_key_info &lt;key_id&gt; &lt;file&gt;
 * - fcs create_key &lt;file&gt;
 * - fcs provision_data &lt;file&gt;
 * - fcs counter_set &lt;file&gt;
 * - fcs counter_set_preauth &lt;type&gt; &lt;value&gt;
 * - fcs sdos_encrypt &lt;owner_id&gt; &lt;identifier&gt; &lt;input_file&gt; &lt;output_file&gt;
 * - fcs sdos_decrypt &lt;input_file&gt; &lt;output_file&gt;
 * - fcs get_digest &lt;key_id&gt; &lt;op_mode&gt; &lt;dig_size&gt; &lt;src_file&gt; &lt;digest_file&gt;
 * - fcs mac_verify &lt;key_id&gt; &lt;dig_size&gt; &lt;src_file&gt; &lt;mac_file&gt;
 * - fcs chip_id
 * - fcs attestation_get_cert &lt;cert_req&gt; &lt;file&gt;
 * - fcs attestation_cert_reload &lt;cert_req&gt;
 * - fcs mctp_cmd_send &lt;input_file&gt; &lt;output_file&gt;
 * - fcs jtag_idcode
 * - fcs device_identity &lt;file&gt;
 * - fcs aes_cryption &lt;key_id&gt; &lt;crypt_mode&gt; &lt;block_mode&gt; &lt;tag_len&gt; &lt;iv_src&gt; &lt;iv_file&gt; &lt;aad_file&gt; &lt;input_file&gt; &lt;output_file&gt;
 * - fcs ecdsa_hash_sign &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;output_file&gt;
 * - fcs ecdsa_hash_verify &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt; [pubkey_file]
 * - fcs ecdsa_sha2_sign &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;output_file&gt;
 * - fcs ecdsa_sha2_verify &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt; [pubkey_file]
 * - fcs ecdsa_get_public_key &lt;key_id&gt; &lt;ecc_algo&gt; &lt;file&gt;
 * - fcs ecdh_request &lt;key_id&gt; &lt;ecc_algo&gt; &lt;pub_key_file&gt; &lt;shared_sec_file&gt;
 * - fcs hkdf_request &lt;key_id&gt; &lt;step_type&gt; &lt;mac_mode&gt; &lt;input_file&gt; &lt;input_file_2&gt; &lt;key_object_file&gt;
 * - fcs validate_image &lt;cert_file&gt;
 *
 * Typical usage:
 * - Use 'fcs open_session' to initiate a session for cryptographic functions.
 * - Ensure correct keys are present for performing cryptographic operations.
 * - Import a corresponding cryptographic key before executing a function.
 * - Provide File names as `/source/file_name`. Source should be `/sd/` for SD/MMC and `/usb/` for USB.
 *
 * For help on a specific command, use:
 *   fcs &lt;command&gt; help
 *
 * @section fcs_commands Commands
 * @subsection fcs_open_session fcs open_session
 * Opens a service session.  <br>
 *
 * Usage:  <br>
 *   fcs open_session  <br>
 *
 * @subsection fcs_close_session fcs close_session
 * Closes a service session.  <br>
 *
 * Usage:  <br>
 *   fcs close_session  <br>
 *
 * @subsection fcs_random_number fcs random_number
 * Generates a random number.  <br>
 *
 * Usage:  <br>
 *   fcs random_number &lt;rand_size&gt; &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - rand_size    – Size of random number in bytes (maximum 4084).  <br>
 * - file         – File name to store the random number <br>
 *
 * @subsection fcs_import_key fcs import_key
 * Imports a service key identified by the given session.  <br>
 *
 * Usage:  <br>
 *   fcs import_key &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - file         – ile name containing the key to be imported <br>
 *
 * @subsection fcs_export_key fcs export_key
 * Exports a service key identified by the given session.<br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to be exported.  <br>
 * - file         – File name to store the exported key <br>
 *
 * Usage:  <br>
 *   fcs export_key &lt;file&gt;  <br>
 *
 * @subsection fcs_remove_key fcs remove_key
 * Removes a service key identified by the given session. <br>
 *
 * Usage:  <br>
 *   fcs remove_key &lt;key_id&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to be removed <br>
 *
 * @subsection fcs_get_key_info fcs get_key_info
 * Get the service key information. <br>
 *
 * Usage:  <br>
 *   fcs get_key_info &lt;key_id&gt; &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to get information  <br>
 * - file         – File name to store the key information.  <br>
 *
 * @subsection fcs_create_key fcs create_key
 * Create a service key.  <br>
 *
 * Usage:  <br>
 *   fcs create_key &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - file         – File name to store the created key <br>
 *
 * @subsection fcs_provision_data fcs provision_data
 * Retrieves the provision data.  <br>
 *
 * Usage:  <br>
 *   fcs provision_data &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - file         –  File name to store provision data <br>
 *
 * @subsection fcs_counter_set fcs counter_set
 * Sets the service counter with the provided certificate.  <br>
 *
 * Usage:  <br>
 *   fcs counter_set &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - file         – File name containing counter set certificate <br>
 *
 * @subsection fcs_counter_set_preauth fcs counter_set_preauth
 * Sets counter value w/o signed certificate. <br>
 *
 * Usage:  <br>
 *   fcs counter_set_preauth &lt;type&gt; &lt;value&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - type         – (1-5) - type of counter  <br>
 * - value        – Value to set.  <br>
 * - Ensure certificate is already sent to device with this capabililty
 *
 * @subsection fcs_sdos_encrypt fcs sdos_encrypt
 * Perform encryption on file data  <br>
 *
 * Usage:  <br>
 * fcs sdos_encrypt &lt;owner_id&gt; &lt;identifier&gt; &lt;iv_file&gt; &lt;input_file&gt; &lt;output_file&gt;
 *
 * It requires the following arguments:
 * - owner_id     – 8-byte owner identifier.
 * - identifier   – 2-byte application-specific object identifier.
 * - iv_file      – File containing 16 bytes of IV. Must follow 'gc/source/filename` format.
 * - input_file   – File containing plaintext. Must follow 'gc/source/filename` format.
 * - output_file  – File to store ciphertext. Must follow 'gc/source/filename` format.
 *
 * @subsection fcs_sdos_decrypt fcs sdos_decrypt
 * Perform decryption on file data <br>
 *
 * Usage:  <br>
 *   fcs sdos_decrypt &lt;input_file&gt; &lt;output_file&gt; <br>
 *
 * It requires the following arguments:
 * - input_file   – File containing ciphertext. Must follow 'gc/source/filename` format.
 * - output_file  – File to store decrypted plaintext. Must follow 'gc/source/filename` format.
 *
 * @subsection fcs_get_digest fcs get_digest
 * Computes the digest data for specified key ID, SHA operation mode and SHA digest size <br>
 *
 * Usage:  <br>
 *   fcs get_digest &lt;key_id&gt; &lt;op_mode&gt; &lt;dig_size&gt; &lt;src_file&gt; &lt;digest_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to be used for digest <br>
 * - op_mode      – Operation mode: 1 - SHA2, 2 - HMAC <br>
 * - dig_size     – Digest size: 0 - 256, 1 - 384, 2 - 512  <br>
 * - src_file     – File name containing the data to get digest <br>
 * - digest_file  – File name to store the digest <br>
 *
 * @subsection fcs_mac_verify fcs mac_verify
 * Verfies the MAC. <br>
 *
 * Usage:  <br>
 *   fcs mac_verify &lt;key_id&gt; &lt;dig_size&gt; &lt;src_file&gt; &lt;mac_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to be used for MAC verification <br>
 * - dig_size     – Digest size: 0 - 256, 1 - 384, 2 - 512 <br>
 * - src_file     – File name containing the data to verify MAC  <br>
 * - mac_file     – File name containing the MAC to verify. Should be generated using fcs get_digest in HMAC mode <br>
 *
 * @subsection fcs_chip_id fcs chip_id
 * Get the chip ID. <br>
 *
 * Usage:  <br>
 *   fcs chip_id  <br>
 *
 * @subsection fcs_attestation_get_cert fcs attestation_get_cert
 * Request to get the certificate. <br>
 *
 * Usage:  <br>
 *   fcs attestation_get_cert &lt;cert_req&gt; &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - cert_req     – Bitmask for certificate type <br>
 * - file         – File name to store the certificate <br>
 *
 * @subsection fcs_attestation_cert_reload fcs attestation_cert_reload
 * Reloads the attestation certificate. <br>
 *
 * Usage:  <br>
 *   fcs attestation_cert_reload &lt;cert_req&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - cert_req     – Bitmask for certificate type <br>
 *
 * @subsection fcs_mctp_cmd_send fcs mctp_cmd_send
 * Sends a MCTP request. <br>
 *
 * Usage:  <br>
 *   fcs mctp_cmd_send &lt;input_file&gt; &lt;output_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - input_file   – File name containing the MCTP header and payload <br>
 * - output_file  – File name to store the MCTP response <br>
 *
 * @subsection fcs_jtag_idcode fcs jtag_idcode
 * Get the JTAG IDCODE. <br>
 *
 * Usage:  <br>
 *   fcs jtag_idcode  <br>
 *
 * @subsection fcs_device_identity fcs device_identity
 * Get the device identity. <br>
 *
 * Usage:  <br>
 *   fcs device_identity &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - file         – File name to store device identity <br>
 *
 * @subsection fcs_aes_cryption fcs aes_cryption
 * Request AES encryption/decryption operation <br>
 *
 * Usage:  <br>
 *   fcs aes_cryption &lt;key_id&gt; &lt;crypt_mode&gt; &lt;block_mode&gt; &lt;tag_len&gt; &lt;iv_src&gt; &lt;iv_file&gt; &lt;aad_file&gt; &lt;input_file&gt; &lt;output_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – Key ID to be used for AES cryption  <br>
 * - crypt_mode   – 0 = Encrypt, 1 = Decrypt (0 for GCM-GHASH).  <br>
 * - block_mode   – Block mode: 0 = ECB, 1 = CBC, 2 = CTR, 3 = GCM, 4 = GCM-GHASH.  <br>
 * - tag_len      – (For GCM, GCM-GHASH) Tag length: 0 = 32-bit, 1 = 64-bit, 2 = 96-bit, 3 = 128-bit.  <br>
 * - iv_src       – (For GCM, GCM-GHASH) IV source: 0 = external, 1 = internal (DRNG), 2 = internal (IV base + key).  <br>
 * - iv_file      – (For non-ECB modes) File name containing 16 bytes of IV <br>
 * - aad_file     – (For GCM, GCM-GHASH) File name containing AAD data <br>
 * - input_file   – File name to read input data <br>
 * - output_file  – File name to store output data <br>
 *
 * @subsection fcs_ecdsa_hash_sign fcs ecdsa_hash_sign
 * Signs the hash using the specified key ID, ECC curve and source data. <br>
 *
 * Usage:  <br>
 *   fcs ecdsa_hash_sign &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id         – ID of the key to be used for hash verification <br>
 * - ecc_algo       – ECC algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384  <br>
 * - input_file     – File name to read input data <br>
 * - signature_file – File name which to store signature <br>
 *
 * @subsection fcs_ecdsa_hash_verify fcs ecdsa_hash_verify
 * Verfies the hash using the specified key ID, ECC curve, source data, signature data and public key data if key ID is not known.  <br>
 *
 * Usage:  <br>
 *   fcs ecdsa_hash_verify &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt; [pubkey_file]  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id         – ID of the key to be used for hash verification, 0 for using public key <br>
 * - ecc_algo       – ECC algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384.  <br>
 * - input_file     – File name to read input data <br>
 * - signature_file – File name which contains signature of input <br>
 * - pubkey_file    – Public file if key id is not known(provide key id as 0). <br>
 *                    This file is optional and only provided when key id is 0 <br>
 *
 * @subsection fcs_ecdsa_sha2_sign fcs ecdsa_sha2_sign
 * Signs the data using SHA2 with the specified key_id, ECC curve and source data. <br>
 *
 * Usage:  <br>
 *   fcs ecdsa_sha2_sign &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id         – ID of the key to be used for SHA2 data sign. <br>
 * - ecc_algo       – ECC algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384.  <br>
 * - input_file     – File name to read input data  <br>
 * - signature_file – File name which to store signature  <br>
 *
 * @subsection fcs_ecdsa_sha2_verify fcs ecdsa_sha2_verify
 * Verfies the hash using the specified key ID, ECC curve, source data, signature data and public key data if key ID is not known. <br>
 *
 * Usage:  <br>
 *   fcs ecdsa_sha2_verify &lt;key_id&gt; &lt;ecc_algo&gt; &lt;input_file&gt; &lt;signature_file&gt; [pubkey_file]  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id         – ID of the key to be used for SHA2 data verification, 0 for using public key <br>
 * - ecc_algo       – ECC algorithm: 1 = NISTP256, 2 = NISTP384, 3 = Brainpool256, 4 = Brainpool384.  <br>
 * - input_file     – File name to read input data <br>
 * - signature_file – File name which contains signature of input <br>
 * - pubkey_file    – Public file if key id is not known(provide key id as 0). <br>
 *                    This file is optional and only provided when key id is 0 <br>
 *
 * @subsection fcs_ecdsa_get_public_key fcs ecdsa_get_public_key
 * Generates a public key for the specified key ID and ECC curve. <br>
 *
 * Usage:  <br>
 *   fcs ecdsa_get_public_key &lt;key_id&gt; &lt;ecc_algo&gt; &lt;file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id       – ID of the key to be used for public key retrieval <br>
 * - ecc_algo     – ECC algorithm used by the key: 1 = NISTP256, 2 = NISTP384, 3 = Brainpool256, 4 = Brainpool384.  <br>
 * - file         – File name to store the public key <br>
 *
 * @subsection fcs_ecdh_request fcs ecdh_request
 * Generates shared secret. <br>
 *
 * Usage:  <br>
 *   fcs ecdh_request &lt;key_id&gt; &lt;ecc_algo&gt; &lt;pub_key_file&gt; &lt;shared_sec_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - key_id           – ID of the key to be used for ECDH  <br>
 * - ecc_algo         – ECC algorithm: 1 = NISTP256, 2 = NISTP384, 3 = Brainpool256, 4 = Brainpool384.  <br>
 * - pubkey_file      – File name containing the public key <br>
 * - shared_sec_file  – File name to store the shared secret  <br>
 *
 * @subsection fcs_hkdf_request fcs hkdf_request
 * Request HKDF operation. <br>
 *
 * Usage:  <br>
 *   fcs hkdf_request &lt;key_id&gt; &lt;step_type&gt; &lt;mac_mode&gt; &lt;input_file&gt; &lt;input_file_2&gt; &lt;key_object_file&gt;  <br>
 *
 * It requires the following arguments:
 * - key_id           - ID of the key to be used for HKDF request, provide as 0.  <br>
 * - step_type        - 0 - Extract then expand, 1 - Expand only(non-GCM), 2 - Expand only(GCM).  <br>
 * - mac_mode         - 0 - SHA256, 1 - SHA384, 2 - SHA512.  <br>
 * - input_file       - File name containing shared secret or fixed info according to step_type. <br>
 *                      48 bytes shared secret for step 0. <br>
 *                      80 bytes maximum fixed info for others.  <br>
 * - input_file_2     - File name containing 80 bytes maximum fixed info for step 0 and step 2. <br>
 *                      Not applicable to step_type 1.  <br>
 * - key_object_file  - File name containing output key object. <br>
 *                      HMAC384 exchange key object for step 0. <br>
 *                      HMAC384 sign/verify/exchange key object for step 1. <br>
 *                      AES256 encryption/decryption for step 2.  <br>
 *
 * @subsection fcs_validate_image fcs validate_image
 * Validates the image using the specified certificate file. <br>
 *
 * Usage:  <br>
 *   fcs validate_image &lt;cert_file&gt;  <br>
 *
 * It requires the following arguments:  <br>
 * - cert_file  - File name containing the certificate to validate the image <br>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <socfpga_uart.h>
#include "osal_log.h"
#include "ff_sddisk.h"
#include "FreeRTOS_CLI.h"
#include "socfpga_fcs.h"
#include "libfcs.h"

#define FCS_CLI_CONTEXT_ID  1U

/* FAT macros and globals*/
#define MOUNTED          1
#define UNMOUNTED        0
#define MOUNT_SD_CARD    -1
#define MOUNT_USB        0
static const char *sdmmc_mount = "/sd/";
static const char *usb_mount = "/usb/";

struct cli_descriptor
{
    int session_opened;
    char uuid[FCS_UUID_SIZE];
};

struct cli_descriptor cli;

static FF_Disk_t *disk_obj = NULL;
static uint8_t mount_status = UNMOUNTED;

static int fat_get_disk_type(const char *mptr)
{
    if( strncmp(mptr, sdmmc_mount, 3) == 0 )
    {
        return 0;
    }
    else if(strncmp(mptr, usb_mount, 5) == 0 )
    {
        return 1;
    }
    else
    {
        return -1;
    }

    return -1;
}

static int fat_mount( const char *mount_name )
{
    int mount_type = fat_get_disk_type(mount_name);
    if(mount_type == 0)
    {
        disk_obj = FF_SDDiskInit(mount_name, MOUNT_SD_CARD);
    }
    else if(mount_type == 1)
    {
        disk_obj = FF_SDDiskInit(mount_name, MOUNT_USB);
    }
    else
    {
        ERROR("Invalid mount point");
        return -1;
    }
    if (disk_obj != NULL)
    {
        mount_status = MOUNTED;
        return mount_type;
    }
    else
    {
        ERROR("Mounting Failed");
        return -1;
    }
}

static void fat_unmount( void )
{
    if(disk_obj == NULL )
    {
        ERROR("No mounted devices");
        return;
    }
    FF_Unmount(disk_obj);
    FF_SDDiskDelete(disk_obj);
    disk_obj = NULL;
    mount_status = UNMOUNTED;
}
static uint32_t fat_get_size( const char *file )
{
    int ret;
    uint32_t file_size;
    FF_Error_t err;
    FF_FILE *file_obj;
    ret = fat_mount(file);
    if (disk_obj == NULL)
    {
        ERROR("Failed to mount");
        return 0;
    }
    if(ret == 0)
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 3, FF_MODE_READ, &err);
    }
    else
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 4, FF_MODE_READ, &err);
    }
    if ((file_obj == NULL) || (err != FF_ERR_NONE))
    {
        PRINT("Failed to open file for reading");
        FF_Unmount(disk_obj);
        FF_SDDiskDelete(disk_obj);
        return 0;
    }

    ret = FF_GetFileSize(file_obj, &file_size);
    if( ret != 0 )
    {
        ERROR("Error getting file size ");
        return 0;
    }
    FF_Close(file_obj);
    return file_size;
}
static uint32_t fat_read( const char *file, void *buffer )
{
    FF_Error_t err;
    uint32_t bytes_read = 0;
    FF_FILE *file_obj;
    int ret;
    ret = fat_mount(file);
    if (disk_obj == NULL)
    {
        ERROR("Failed to mount");
        return 0;
    }
    if (ret == 0)
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 3,
            FF_MODE_READ, &err);
    }
    else if(ret == 1)
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 4,
            FF_MODE_READ, &err);
    }
    if (file_obj != NULL)
    {
        bytes_read = FF_Read(file_obj, 1, file_obj->ulFileSize, (uint8_t*)buffer);
        FF_Close(file_obj);
    }
    fat_unmount();
    return bytes_read;
}

static void fat_write( const char *file, const char *buffer, uint32_t data_size)
{
    FF_Error_t err;
    uint32_t bytes_written;
    FF_FILE *file_obj;
    int ret;
    ret = fat_mount(file);
    if (disk_obj == NULL)
    {
        ERROR("Failed to mount");
        return;
    }
    if (ret == 0)
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 3,
            (FF_MODE_APPEND | FF_MODE_CREATE | FF_MODE_WRITE), &err);
    }
    else if(ret == 1)
    {
        file_obj = FF_Open(disk_obj->pxIOManager, file + 4,
            (FF_MODE_APPEND | FF_MODE_CREATE | FF_MODE_WRITE), &err);
    }
    if (buffer == NULL)
    {
        buffer = " ";
    }

    if (file_obj == NULL)
    {
        printf("\r\nERROR: Failed to open the file\n");
        return;
    }

    bytes_written = FF_Write(file_obj, 1U, (data_size),
            (uint8_t*) buffer);

    if (bytes_written < (data_size))
    {
        printf("\r\nERROR: Failed to write to the file \n");
    }
    else
    {
        printf("\r\nWritten to file successfully.\n");
    }
    FF_Close(file_obj);
    fat_unmount();
}
/******************************************************************************/
BaseType_t cmd_fcs( char *write_buffer, size_t write_buffer_len,
        const char *command_string)
{
    (void) write_buffer;
    (void) write_buffer_len;
    (void) command_string;
    const char *param1, *param2, *param3, *param4, *param5,
            *param6, *param7, *param8, *param9, *param10;
    char temp_str[50], help_str[5], *file, *buf, *key_buf, *resp_buf, *space_pos,
            verify_status[4];
    BaseType_t param1_str_len, param2_str_len, param3_str_len,
            param4_str_len, param5_str_len, param6_str_len,
            param7_str_len, param8_str_len, param9_str_len,
            param10_str_len;

    uint32_t rand_size, key_id, bytes_read, status, resp_size, status_len;
    int ret;


    memset(temp_str, 0, sizeof(temp_str));
    memset(help_str, 0, sizeof(help_str));
    param1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len);
    strncpy(temp_str, param1, param1_str_len);

    if(strcmp(temp_str, "help") == 0)
    {
        printf("\rPerforms cryptographic services");
        printf("\r\n\nIt supports the following commands");
        printf("\r\n  open_session               fcs open_session");
        printf("\r\n  close_session              fcs close_session");
        printf("\r\n  random_number              fcs random_number <rand_size> <file>");
        printf("\r\n  import_key                 fcs import_key <file>");
        printf("\r\n  export_key                 fcs export_key <file>");
        printf("\r\n  remove_key                 fcs remove_key <key_id>");
        printf("\r\n  get_key_info               fcs get_key_info <key_id> <file>");
        printf("\r\n  create_key                 fcs create_key <file>");
        printf("\r\n  provision_data             fcs provision_data <file>");
        printf("\r\n  counter_set                fcs counter_set <file>");
        printf("\r\n  counter_set_preauth        fcs counter_set_preauth <type> <value>");
        printf("\r\n  sdos_encrypt               fcs sdos_encrypt <owner_id> <identifier> <iv_file> <input_file> <output_file>");
        printf("\r\n  sdos_decrypt               fcs sdos_decrypt <input_file> <output_file>");
        printf("\r\n  get_digest                 fcs get_digest <key_id> <op_mode> <dig_size> <src_file> <digest_file>");
        printf("\r\n  mac_verify                 fcs mac_verify <key_id> <dig_size> <src_file> <mac_file>");
        printf("\r\n  chip_id                    fcs chip_id");
        printf("\r\n  attestation_get_cert       fcs attestation_get_cert <cert_req> <file>");
        printf("\r\n  attestation_cert_reload    fcs attestation_cert_reload <cert_req>");
        printf("\r\n  mctp_cmd_send              fcs mctp_cmd_send  <input_file> <output_file>");
        printf("\r\n  jtag_idcode                fcs jtag_idcode");
        printf("\r\n  device_identity            fcs device_identity <file>");
        printf("\r\n  aes_cryption               fcs aes_cryption <key_id> <crypt_mode> <block_mode> [tag_len] [iv_src] [iv_file] [aad_file] <input_file> <output_file>");
        printf("\r\n  ecdsa_hash_sign            fcs ecdsa_hash_sign <key_id> <ecc_algo> <input_file> <output_file>");
        printf("\r\n  ecdsa_hash_verify          fcs ecdsa_hash_verify <key_id> <ecc_algo> <input_file> <signature_file> [pubkey_file]");
        printf("\r\n  ecdsa_sha2_sign            fcs ecdsa_sha2_sign <key_id> <ecc_algo> <input_file> <output_file>");
        printf("\r\n  ecdsa_sha2_verify          fcs ecdsa_sha2_verify <key_id> <ecc_algo> <input_file> <signature_file> [pubkey_file]");
        printf("\r\n  ecdsa_get_public_key       fcs ecdsa_get_public_key <key_id> <ecc_algo> <file>");
        printf("\r\n  ecdh_request               fcs ecdh_request <key_id> <ecc_algo> <pub_key_file> <shared_sec_file>");
        printf("\r\n  hkdf_request               fcs hkdf_request <key_id> <step_type> <mac_mode> <input_file> <input_file_2> <key_object_file>");
        printf("\r\n  validate_image             fcs validate_image <cert_file>");
        printf("\r\n\nTypical usage:");
        printf("\r\n- Use fcs open_session to initiate a sesion to perform cryptographic functions");
        printf("\r\n- Ensure correct keys are present for performing cryptographic functions");
        printf("\r\n- Import a functions corresponding cryptographic key before performing the function");
        printf("\r\n- Provide file names as /source/file_name. Source should be /sd/ for sdmmc and /usb/ for USB");
        printf("\r\n\nFor help on a specific command, perform:");
        printf("\r\n  fcs <command> help\r\n");
    }
    else if(strcmp(temp_str, "open_session") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rOpens a service session.");
            printf("\r\n\nUsage:");
            printf("\r\n  fcs open_session");
            return pdFALSE;
        }
        if(cli.session_opened == 1)
        {
            printf("\r\nERROR: Session already opened");
            return pdFALSE;
        }
        ret = fcs_open_service_session(cli.uuid);
        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to open session");
            return pdFALSE;
        }
        printf("\n\nSession opened successfully");
        cli.session_opened = 1;
    }
    else if(strcmp(temp_str, "close_session") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rCloses a service session.");
            printf("\r\n\nUsage:");
            printf("\r\n  fcs close_session");
            return pdFALSE;
        }
        else
        {
            if(cli.session_opened == 0)
            {
                printf("\r\nERROR: Session not opened");
                return pdFALSE;
            }
            ret = fcs_close_service_session(cli.uuid);
            if (ret != 0)
            {
                printf("\r\nERROR: Failed to close session");
                return pdFALSE;
            }
            else
            {
                printf("\r\nSession closed successfully");
                cli.session_opened = 0;
            }
            return pdFALSE;
        }
    }
    else if(strcmp(temp_str, "random_number") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGenerates a random number.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs random_number <rand_size> <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  rand_size  - Size of random number in bytes, maximum of 4084");
            printf("\r\n  file       - File name to store the random number");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs random_number help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        rand_size = atoi(param2);
        file = (char*)param3;
        buf = pvPortMalloc(rand_size);
        if (buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for random number buffer");
            return pdFALSE;
        }
        ret = fcs_random_number_ext(cli.uuid, FCS_CLI_CONTEXT_ID, buf, rand_size);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to generate random number");
            vPortFree(buf);
            return pdFALSE;
        }
        fat_write(file, buf, rand_size);
        printf("\r\nRandom number generated successfully");
        vPortFree(buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "import_key") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rImports a service key identified by the given session.");
            printf("\r\n\nUsage:");
            printf("\r\n  fcs import_key <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  file  - File name containing the key to be imported");
            return pdFALSE;
        }
        if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs import_key help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        file = (char*)param2;
        key_buf = pvPortMalloc(fat_get_size(file));
        if (key_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for key buffer");
            return pdFALSE;
        }
        bytes_read = fat_read(file, key_buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read key from file");
            vPortFree(key_buf);
            return pdFALSE;
        }
        ret = fcs_import_service_key(cli.uuid, key_buf, bytes_read, (char*)&status, &status_len);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to import key");
            vPortFree(key_buf);
            return pdFALSE;
        }
        printf("\r\nKey imported successfully");
        vPortFree(key_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "export_key") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rExports a service key identified by the given session.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs export_key <key_id> <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id  - ID of the key to be exported");
            printf("\r\n  file    - File name to store the exported key");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs export_key help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        key_id = atoi(param2);
        file = (char*)param3;
        key_buf = pvPortMalloc(FCS_MAX_KEY_SIZE);
        if (key_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for key buffer");
            return pdFALSE;
        }
        ret = fcs_export_service_key(cli.uuid, key_id, key_buf, &bytes_read);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to export key");
            vPortFree(key_buf);
            return pdFALSE;
        }
        printf("\r\nKey exported successfully");
        fat_write(file, key_buf, bytes_read);
        vPortFree(key_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "remove_key") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rRemoves a service key identified by the given session.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs remove_key <key_id>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id  - ID of the key to be removed");
            return pdFALSE;
        }
        if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs remove_key help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        key_id = atoi(param2);
        ret = fcs_remove_service_key(cli.uuid, key_id);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to remove key");
            return pdFALSE;
        }
        printf("\r\nKey removed successfully");
    }
    else if(strcmp(temp_str, "get_key_info") == 0)
    {
    param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
    param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
    strncpy(help_str, param2, param2_str_len);
    if (strcmp(help_str, "help") == 0)
    {
        printf("\rGet the service key information.");
        printf("\r\n\nUsage");
        printf("\r\n  fcs get_key_info <key_id> <file>");
        printf("\r\n\nIt requires the following arguments");
        printf("\r\n  key_id  - ID of the key to get information");
        printf("\r\n  file    - File name to store the key information");
        return pdFALSE;
    }
    if (param2 == NULL || param3 == NULL)
    {
        printf("\r\nERROR: Incorrect parameters");
        printf("\r\nEnter fcs get_key_info help for more information");
        return pdFALSE;
    }
    if(cli.session_opened == 0)
    {
        printf("\r\nERROR: Session not opened");
        return pdFALSE;
    }
    key_id = atoi(param2);
    file = (char*)param3;
    key_buf = pvPortMalloc(FCS_MAX_KEY_SIZE);
    if (key_buf == NULL)
    {
        printf("\r\nERROR: Failed to allocate memory for key buffer");
        return pdFALSE;
    }
    ret = fcs_get_service_key_info(cli.uuid, key_id, key_buf, &bytes_read);
    if (ret != 0)
    {
        printf("\r\nERROR: Failed to get key information");
        vPortFree(key_buf);
        return pdFALSE;
    }
    printf("\r\nKey information retrieved successfully");
    fat_write(file, key_buf, bytes_read);
    vPortFree(key_buf);
    return pdFALSE;
    }
    else if(strcmp(temp_str, "create_key") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
    strncpy(help_str, param2, param2_str_len);
    if (strcmp(help_str, "help") == 0)
    {
        printf("\rCreate a service key.");
        printf("\r\n\nUsage");
        printf("\r\n  fcs create_key <file>");
        printf("\r\n\nIt requires the following arguments");
        printf("\r\n  file  - File name to store the created key");
        return pdFALSE;
    }
    if (param2 == NULL)
    {
        printf("\r\nERROR: Incorrect parameters");
        printf("\r\nEnter fcs create_key help for more information");
        return pdFALSE;
    }
    if(cli.session_opened == 0)
    {
        printf("\r\nERROR: Session not opened");
        return pdFALSE;
    }
    file = (char*)param2;
    key_buf = pvPortMalloc(fat_get_size(file));
    if (key_buf == NULL)
    {
        printf("\r\nERROR: Failed to allocate memory for key buffer");
        return pdFALSE;
    }
    bytes_read = fat_read(file, key_buf);
    if( bytes_read == 0)
    {
        printf("\r\nERROR: Failed to read key from file");
        vPortFree(key_buf);
        return pdFALSE;
    }
    ret = fcs_create_service_key(cli.uuid, key_buf, bytes_read, (char*)&status, status_len);
    if (ret != 0)
    {
        printf("\r\nERROR: Failed to create key");
        vPortFree(key_buf);
        return pdFALSE;
    }
    printf("\r\nKey creation command executed successfully");
    printf("\r\nStatus: %x", status);
    vPortFree(key_buf);
    return pdFALSE;
    }
    else if(strcmp(temp_str, "provision_data") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
    strncpy(help_str, param2, param2_str_len);
    if (strcmp(help_str, "help") == 0)
    {
        printf("\rRetrieves the provision data.");
        printf("\r\n\nUsage");
        printf("\r\n  fcs provision_data <file>");
        printf("\r\n\nIt requires the following arguments");
        printf("\r\n  file  - File name to store provision data");
        return pdFALSE;
    }
    if (param2 == NULL)
    {
        printf("\r\nERROR: Incorrect parameters");
        printf("\r\nEnter fcs provision_data help for more information");
        return pdFALSE;
    }
    file = (char*)param2;
    buf = pvPortMalloc(FCS_PROV_DATA_MAX_SIZE);
    if (buf == NULL)
    {
        printf("\r\nERROR: Failed to allocate memory for provision data buffer");
        return pdFALSE;
    }
    ret = fcs_service_get_provision_data(buf, &resp_size);
    if (ret != 0)
    {
        printf("\r\nERROR: Failed to get provision data");
        vPortFree(buf);
        return pdFALSE;
    }
    printf("\r\nProvision data retrieved successfully");
    fat_write(file, buf, resp_size);
    vPortFree(buf);
    return pdFALSE;
    }
    else if(strcmp(temp_str, "counter_set") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
    if (strcmp(help_str, "help") == 0)
    {
        printf("\rSets the service counter with the provided certificate.");
        printf("\r\n\nUsage");
        printf("\r\n  fcs counter_set <file>");
        printf("\r\n\nIt requires the following arguments");
        printf("\r\n  file  - File name containing counter set certificate");
        return pdFALSE;
    }
    if (param2 == NULL)
    {
        printf("\r\nERROR: Incorrect parameters");
        printf("\r\nEnter fcs counter_set help for more information");
        return pdFALSE;
    }
    file = (char*)param2;
    buf = pvPortMalloc(fat_get_size(file));
    if (buf == NULL)
    {
        printf("\r\nERROR: Failed to allocate memory for counter set buffer");
        return pdFALSE;
    }
    bytes_read = fat_read(file, buf);
    if (bytes_read == 0)
    {
        printf("\r\nERROR: Failed to read counter set certificate from file");
        vPortFree(buf);
        return pdFALSE;
    }
    /* value of test bit is irrelevant as any test bit value is already provided
     * in the certificate. Any change to this will invalidate the signature */
    ret = fcs_service_counter_set(buf, bytes_read, 1,
            (char*)&status);
    if (ret != 0)
    {
        printf("\r\nERROR: Failed to set counter");
        vPortFree(buf);
        return pdFALSE;
    }
    printf("\r\nCounter set successfully");
    printf("\r\nStatus: %x", status);
    vPortFree(buf);
    }
    else if(strcmp(temp_str, "counter_set_preauth") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rSets counter value w/o signed certificate.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs counter_set_preauth <type> <value>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  type   - Type of counter (1-5)");
            printf("\r\n  value  - Value to set");
            printf("\r\n           Ensure certificate is already sent to device with this capabililty");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs counter_set_preauth help for more information");
            return pdFALSE;
        }
        int type = atoi(param2);
        int value = atoi(param3);
        ret = fcs_service_counter_set_preauthorized(type, value,
                1);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to set preauthorized counter");
            return pdFALSE;
        }
        printf("\r\nPreauthorized counter set successfully");
        return pdFALSE;
    }
    else if(strcmp(temp_str, "sdos_encrypt") == 0)
    {
        struct fcs_sdos_enc_req req;
        struct fcs_sdos_crypt_header *sdos_header;
        char *iv_data;

        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rPerform encryption on file data");
            printf("\r\n\nUsage");
            printf("\r\n  fcs sdos_encrypt <owner_id> <identifier> <iv_file> <input_file> <output_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  owner_id     - 8 bytes owner ID");
            printf("\r\n  identifier   - 2 bytes application specific object identifier");
            printf("\r\n  iv_file      - File name containing 16bytes IV");
            printf("\r\n  input_file   - File name containing the data to be encrypted, maximum size of 32672 bytes");
            printf("\r\n  output_file  - File name to store the encrypted data");
            return pdFALSE;
        }
        if( param2 == NULL || param3 == NULL || param4 == NULL ||
                param5 == NULL )
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs sdos_encrypt help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        req.own = (uint64_t)atoi(param2);
        req.id = (uint16_t)atoi(param3);
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        iv_data = pvPortMalloc(fat_get_size(file));
        if (iv_data == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for IV data");
            return pdFALSE;
        }
        bytes_read = fat_read(file, iv_data);
        file = (char*)param5;
        space_pos = strchr(param5, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }

        if(fat_get_size(file) > FCS_SDOS_DEC_MAX_RESP)
        {
            printf("\r\nERROR: File size too large");
            vPortFree(iv_data);
            return pdFALSE;
        }
        buf = pvPortMalloc(FCS_SDOS_DEC_MAX_RESP);
        resp_buf = pvPortMalloc(FCS_SDOS_ENC_MAX_RESP);
        if (buf == NULL || resp_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for SDOS buffer");
            return pdFALSE;
        }
        sdos_header = (struct fcs_sdos_crypt_header *)buf;
        memset(sdos_header, 0, sizeof(struct fcs_sdos_crypt_header));
        memcpy(sdos_header->iv_field, iv_data, 16);
        sdos_header->magic_number = FCS_SDOS_MAGIC_NUMBER;
        sdos_header->app_spec_obj_info = req.id;
        memcpy(sdos_header->owner_id, &req.own, sizeof(req.own));
        sdos_header->hdr_pad = FCS_SDOS_HEADER_PADDING;
        sdos_header->srk_indx = 0;
        bytes_read = fat_read(file, buf + sizeof(struct fcs_sdos_crypt_header));
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
            vPortFree(resp_buf);
            vPortFree(iv_data);
            return pdFALSE;
        }
        sdos_header->pad = 0;
        if(bytes_read % 32)
        {
            sdos_header->pad = 32 - (bytes_read % 32);
        }
        sdos_header->data_len = bytes_read + sdos_header->pad;
        if(bytes_read < FCS_SDOS_MIN_INPUT ||
                bytes_read > FCS_SDOS_MAX_INPUT)
        {
            printf("\r\nData size not valid");
            vPortFree(buf);
            vPortFree(resp_buf);
            vPortFree(iv_data);
            return pdFALSE;
        }
        req.src = buf;
        req.src_sz = bytes_read + sdos_header->pad + sizeof(struct fcs_sdos_crypt_header);
        req.dst = resp_buf;
        req.dst_sz = &resp_size;
        req.op_mode = FCS_SDOS_ENCRYPT_MODE;

        ret = fcs_sdos_encrypt(cli.uuid, FCS_CLI_CONTEXT_ID, &req);
        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to encrypt data");
            vPortFree(buf);
            vPortFree(resp_buf);
            vPortFree(iv_data);
            return pdFALSE;
        }
        printf("\r\nData encrypted successfully");
        file = (char*)param6;
        fat_write(file, resp_buf, resp_size);
        vPortFree(buf);
        vPortFree(resp_buf);
        vPortFree(iv_data);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "sdos_decrypt") == 0)
    {
        struct fcs_sdos_dec_req req;

        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rPerform decryption on file data");
            printf("\r\n\nUsage");
            printf("\r\n  fcs sdos_decrypt <input_file> <output_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  input_file   - File name containing the data to be decrypted");
            printf("\r\n  output_file  - File name to store the decrypted data");
            printf("\r\n                 Ensure the input file is obtained using sdos_encrypt");
            return pdFALSE;
        }

        if (param2 == NULL || param3 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs sdos_decrypt help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        file = (char*)param2;
        space_pos = strchr(param2, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(FCS_SDOS_ENC_MAX_RESP);
        resp_buf = pvPortMalloc(FCS_SDOS_DEC_MAX_RESP);
        if (buf == NULL || resp_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for SDOS buffer");
            return pdFALSE;
        }
        bytes_read = fat_read(file, buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        req.src = buf;
        req.src_sz = bytes_read;
        req.dst = resp_buf;
        req.dst_sz = &resp_size;
        req.pad = 0;
        if(bytes_read % 32)
        {
            req.pad = 32 - (bytes_read % 16);
        }
        req.op_mode = FCS_SDOS_DECRYPT_MODE;

        ret = fcs_sdos_decrypt(cli.uuid, FCS_CLI_CONTEXT_ID, &req);

        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to decrypt data");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        printf("\r\nData decrypted successfully");
        file = (char*)param3;
        fat_write(file, resp_buf, resp_size);
        vPortFree(buf);
        vPortFree(resp_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "get_digest") == 0)
    {
        struct fcs_digest_get_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rComputes the digest data for specified key ID, SHA operation mode and "
                   "\r\nSHA digest size");
            printf("\r\n\nUsage");
            printf("\r\n  fcs get_digest <key_id> <op_mode> <dig_size> <src_file> <digest_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id       - ID of the key to be used for digest");
            printf("\r\n  op_mode      - Operation mode: 1 - SHA2, 2 - HMAC");
            printf("\r\n  dig_size     - Digest size: 0 - 256, 1 - 384, 2 - 512");
            printf("\r\n  src_file     - File name containing the data to get digest");
            printf("\r\n  digest_file  - File name to store the digest");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
                param5 == NULL || param6 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs get_digest help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        key_id = atoi(param2);
        int op_mode = atoi(param3);
        int dig_size = atoi(param4);
        file = (char*)param5;
        space_pos = strchr(param5, ' ');
        buf = pvPortMalloc(fat_get_size(file));
        resp_buf = pvPortMalloc(64);
        if (buf == NULL || resp_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for digest buffer");
            return pdFALSE;
        }
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        bytes_read = fat_read(file, buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        req.sha_op_mode = op_mode;
        req.sha_digest_sz = dig_size;
        req.src = buf;
        req.src_len = bytes_read;
        req.digest = resp_buf;
        req.digest_len = &resp_size;

        ret = fcs_get_digest(cli.uuid, FCS_CLI_CONTEXT_ID, key_id, &req);
        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to get digest");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        printf("\r\nDigest retrieved successfully");
        file = (char*)param6;
        fat_write(file, resp_buf, resp_size);
        vPortFree(buf);
        vPortFree(resp_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "mac_verify") == 0)
    {
        struct fcs_mac_verify_req req;

        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rVerfies the MAC.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs mac_verify <key_id> <dig_size> <src_file> <mac_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id    - ID of the key to be used for MAC verification");
            printf("\r\n  dig_size  - Digest size: 0 - 256, 1 - 384, 2 - 512");
            printf("\r\n  src_file  - File name containing the data to verify MAC");
            printf("\r\n  mac_file  - File name containing the MAC to verify. Should be generated using fcs get_digest in HMAC mode");
            return pdFALSE;
        }
        if( param2 == NULL || param3 == NULL || param4 == NULL ||
                param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs mac_verify help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        key_id = atoi(param2);
        int dig_size = atoi(param3);
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if( space_pos != NULL )
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file) + 64);
        if (buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for MAC buffer");
            return pdFALSE;
        }
        bytes_read = fat_read(file, buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
        }
        req.dig_sz = dig_size;
        req.src = buf;
        req.user_data_sz = bytes_read;
        req.src_sz = bytes_read;
        file = (char*)param5;
        bytes_read = fat_read(file, buf + bytes_read);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
        }
        req.src_sz += bytes_read;
        req.dst = verify_status;
        req.dst_sz = &resp_size;

        ret = fcs_mac_verify(cli.uuid, FCS_CLI_CONTEXT_ID, key_id, &req);
        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to verify MAC");
            vPortFree(buf);
            return pdFALSE;
        }
        printf("\r\nMAC verification command executed successfully");
        printf("\r\nStatus: %x%x%x%x", verify_status[0], verify_status[1],
                verify_status[2], verify_status[3]);
        vPortFree(buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "chip_id") == 0)
    {
        uint32_t chip_low, chip_high;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGet the chip ID.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs chip_id");
            return pdFALSE;
        }
        int ret = fcs_get_chip_id(&chip_low, &chip_high);
        if( ret != 0 )
        {
            printf("\r\nERROR: Failed to get chip ID");
            return pdFALSE;
        }
        printf("\r\nChip ID: %X%X", chip_low, chip_high);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "attestation_get_certificate") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rRequest to get the certificate.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs attestation_get_certificate <cert_type> <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  cert_type  - Bitmask for certificate type");
            printf("\r\n  file       - File name to store the certificate");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs attestation_get_certificate help for more information");
            return pdFALSE;
        }
        int cert_type = atoi(param2);
        file = (char*)param3;
        buf = pvPortMalloc(FCS_ATTEST_CERT_MAX_SIZE);
        if (buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for certificate buffer");
            return pdFALSE;
        }
        ret = fcs_attestation_get_certificate(cert_type, buf, &resp_size);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to get attestation certificate");
            vPortFree(buf);
            return pdFALSE;
        }
        printf("\r\nAttestation certificate retrieved successfully");
        fat_write(file, buf, resp_size);
        vPortFree(buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "attestation_certificate_reload") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rReloads the attestation certificate.");
            printf("\r\n\nUsage");
            printf("\r\n  attestation_certificate_reload - fcs attestation_certificate_reload <cert_type>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  cert_type  - Bitmask for certificate type");
            return pdFALSE;
        }
        if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs attestation_certificate_reload help for more information");
            return pdFALSE;
        }
        int cert_type = atoi(param2);
        ret = fcs_attestation_certificate_reload(cert_type);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to reload attestation certificate");
            return pdFALSE;
        }
        printf("\r\nAttestation certificate reloaded successfully");
        return pdFALSE;
    }
    else if(strcmp(temp_str, "mctp_cmd_send") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rSends a MCTP request.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs mctp_cmd_send <input_file> <output_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  input_file   - File name containing the MCTP header and payload");
            printf("\r\n  output_file  - File name to store the MCTP response");
            return pdFALSE;
        }
        if( param2 == NULL || param3 == NULL )
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs mctp_cmd_send help for more information");
            return pdFALSE;
        }
        file = (char*)param2;
        space_pos = strchr(param2, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file));
        resp_buf = pvPortMalloc(FCS_MCTP_MAX_SIZE);
        if (buf == NULL || resp_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for MCTP buffer");
            return pdFALSE;
        }
        bytes_read = fat_read(file, buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read data from file");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        ret = fcs_mctp_cmd_send(buf, bytes_read, resp_buf, &resp_size);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to send MCTP command");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        printf("\r\nMCTP command sent successfully");
        file = (char*)param3;
        fat_write(file, resp_buf, resp_size);
        vPortFree(buf);
        vPortFree(resp_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "jtag_idcode") == 0)
    {
        uint32_t jtag_id_code;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGet the JTAG IDCODE.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs jtag_idcode");
            return pdFALSE;
        }
        int ret = fcs_get_jtag_idcode(&jtag_id_code);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to retrieve JTAG ID code");
            return pdFALSE;
        }
        printf("JTAG ID code: %08X\n", jtag_id_code);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "device_identity") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGet the device identity.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs device_identity <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  file - File name to store device identity");
            return pdFALSE;
        }
        if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs device_identity help for more information");
            return pdFALSE;
        }
        file = (char*)param2;
        buf = pvPortMalloc(4096);
        if (buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for device identity buffer");
            return pdFALSE;
        }
        ret = fcs_get_device_identity(buf, &resp_size);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to get device identity");
            vPortFree(buf);
            return pdFALSE;
        }
        printf("\r\nDevice identity retrieved successfully");
        fat_write(file, buf, resp_size);
        vPortFree(buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "aes_cryption") == 0)
    {

        struct fcs_aes_req req;

        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);
        param7 = FreeRTOS_CLIGetParameter(command_string, 7, &param7_str_len);
        param8 = FreeRTOS_CLIGetParameter(command_string, 8, &param8_str_len);
        param9 = FreeRTOS_CLIGetParameter(command_string, 9, &param9_str_len);
        param10 = FreeRTOS_CLIGetParameter(command_string, 10, &param10_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rRequest AES encryption/decryption operation.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs aes_cryption <key_id> <crypt_mode> <block_mode> [tag_len] [iv_src] [iv_file] [aad_file] <input_file> <output_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id_id    - Key ID to be used for AES cryption");
            printf("\r\n  crypt_mode   - 0 - Encrypt, 1 - Decrypt(0 for GCM-GHASH)");
            printf("\r\n  block_mode   - Block mode: 0 - ECB, 1 - CBC, 2 - CTR, 3 - GCM, 4 - GCM-GHASH");
            printf("\r\n  tag_len      - (for GCM, GCM-GHASH),Tag length: 0 - 32 bit, 1 - 64 bit, 2 - 96 bit, 3 - 128 bit");
            printf("\r\n  iv_src       - (for GCM, GCM-GHASH),IV source: 0 - external, 1 - internal with DRNG, 2 - internal using IV base with associated key");
            printf("\r\n  iv_file      - (for non ECB modes) File name containing 16 bytes of IV");
            printf("\r\n  aad_file     - (for GCM, GCM-GHASH), File name containing AAD data");
            printf("\r\n  input_file   - File name to read input data");
            printf("\r\n  output_file  - File name to store output data");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL || param6 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs aes_cryption help for more information");
            return pdFALSE;
        }
        key_id = atoi(param2);
        int crypt_mode = atoi(param3);
        int block_mode = atoi(param4);
        if(block_mode == FCS_AES_ECB)
        {
            file = (char*)param5;
            space_pos = strchr(param5, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            buf = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, buf);
            resp_buf = pvPortMalloc(bytes_read);
            req.aad = NULL;
            req.aad_len = 0;
            req.block_mode = block_mode;
            req.crypt_mode = crypt_mode;
            req.input = buf;
            req.ip_len = bytes_read;
            req.iv = NULL;
            req.iv_len = 0;
            req.iv_source = 0;
            req.op_len = &resp_size;
            req.output = resp_buf;
            req.tag = NULL;
            req.tag_len = 0;

            ret = fcs_aes_crypt(cli.uuid, key_id, FCS_CLI_CONTEXT_ID, &req);

            vPortFree(buf);
            file = (char*)param6;
        }
        else if(block_mode == FCS_AES_CBC || block_mode == FCS_AES_CTR)
        {
            if(param7 == NULL)
            {
                printf("\r\nERROR: Incorrect parameters");
                printf("\r\nEnter fcs aes_cryption help for more information");
                return pdFALSE;
            }
            file = (char*)param5;
            space_pos = strchr(param5, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            char *iv_data = pvPortMalloc(16);
            bytes_read = fat_read(file, iv_data);
            req.iv = iv_data;
            req.iv_len = bytes_read;
            file = (char*)param6;
            space_pos = strchr(param6, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            buf = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, buf);
            resp_buf = pvPortMalloc(bytes_read);
            req.aad = NULL;
            req.aad_len = 0;
            req.block_mode = block_mode;
            req.crypt_mode = crypt_mode;
            req.input = buf;
            req.ip_len = bytes_read;
            req.iv_source = 0;
            req.op_len = &resp_size;
            req.output = resp_buf;
            req.tag = NULL;
            req.tag_len = 0;

            ret = fcs_aes_crypt(cli.uuid, key_id, FCS_CLI_CONTEXT_ID, &req);

            vPortFree(iv_data);
            vPortFree(buf);

            file = (char*)param7;
        }
        else if(block_mode == FCS_AES_GCM || block_mode == FCS_AES_GCM_GHASH)
        {
            if(param7 == NULL || param8 == NULL || param9 == NULL || param10 == NULL)
            {
                printf("\r\nERROR: Incorrect parameters");
                printf("\r\nEnter fcs aes_cryption help for more information");
                return pdFALSE;
            }
            req.block_mode = block_mode;
            req.crypt_mode = crypt_mode;
            req.tag_len = atoi(param5);
            req.iv_source = atoi(param6);
            file = (char*)param7;
            space_pos = strchr(param7, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            char *iv_data = pvPortMalloc(16);
            bytes_read = fat_read(file, iv_data);
            req.iv = iv_data;
            req.iv_len = bytes_read;
            file = (char*)param8;
            space_pos = strchr(param8, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            char *aad_data = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, aad_data);
            req.aad = aad_data;
            req.aad_len = bytes_read;
            file = (char*)param9;
            space_pos = strchr(param9, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            buf = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, buf);
            resp_buf = pvPortMalloc(bytes_read + 16);
            if(crypt_mode == FCS_AES_ENCRYPT && block_mode == FCS_AES_GCM)
            {
                req.tag = resp_buf + bytes_read;
            }
            else if((block_mode == FCS_AES_GCM && crypt_mode == FCS_AES_DECRYPT) ||
                    block_mode == FCS_AES_GCM_GHASH)
            {
                req.tag = buf + (bytes_read - 16);
                bytes_read -= 16;
            }
            req.input = buf;
            req.ip_len = bytes_read;
            req.op_len = &resp_size;
            req.output = resp_buf;

            ret = fcs_aes_crypt(cli.uuid, key_id, FCS_CLI_CONTEXT_ID, &req);

            vPortFree(iv_data);
            vPortFree(aad_data);
            vPortFree(buf);

            file = (char*)param10;
        }
        else
        {
            printf("\r\nERROR:Invalid block mode");
            printf("\r\nEnter fcs aes_cryption help for more information");
            return pdFALSE;
        }
        if(ret != 0)
        {
            printf("\r\nERROR:AES cryption failed");
            vPortFree(resp_buf);
            return pdFALSE;
        }
        printf("\r\nAES cryption completed successfully");
        if(block_mode == FCS_AES_GCM && crypt_mode == FCS_AES_ENCRYPT)
        {
            /* Writing the tag data also*/
            fat_write(file, resp_buf, resp_size + 16);
            printf("\r\nGCM Tag appended to end of file");
        }
        else
        {
            fat_write(file, resp_buf, resp_size);
        }
        vPortFree(resp_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdsa_hash_sign") == 0)
    {
        struct fcs_ecdsa_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rSigns the hash using the specified key ID, ECC curve and source data.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs ecdsa_hash_sign <key_id> <ecc_algo> <input_file> <signature_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id          - ID of the key to be used for hash signing");
            printf("\r\n  ecc_algo        - ECC algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  input_file      - File name to read input data");
            printf("\r\n  signature_file  - File name which to store signature");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdsa_hash_sign help for more information");
            return pdFALSE;
        }

        key_id = atoi(param2);
        int ecc_algo = atoi(param3);
        req.ecc_curve = ecc_algo;
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.src = buf;
        req.src_len = bytes_read;

        char *sig_buf = pvPortMalloc(120);
        req.dst = sig_buf;
        req.dst_len = &resp_size;

        ret = fcs_ecdsa_hash_sign(cli.uuid, FCS_CLI_CONTEXT_ID,
                key_id, &req);

        if (ret != 0)
        {
            printf("\r\nERROR: Failed to sign");
            vPortFree(buf);
            vPortFree(sig_buf);
            return pdFALSE;
        }
        printf("\r\nHash data signed successfully");

        file = (char*)param5;
        fat_write(file, sig_buf, resp_size);
        vPortFree(buf);
        vPortFree(sig_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdsa_hash_verify") == 0)
    {
        struct fcs_ecdsa_verify_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rVerfies the hash using the specified key ID, ECC curve, source data,"
                    "\r\nsignature data and public key data if key ID is not known.");
            printf("\r\nfcs ecdsa_hash_verify <key_id> <ecc_algo> <input_file> <signature_file> [pubkey_file]");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id          - ID of the key to be used for hash verification, 0 for using public key");
            printf("\r\n  ecc_algo        - ECC algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  input_file      - File name to read input data");
            printf("\r\n  signature_file  - File name which contains signature of input");
            printf("\r\n  pubkey_file     - Public key file if key id is not known(provide key id as 0)."
                   "\r\n                    This file is optional and only provided when key id is 0");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdsa_hash_verify help for more information");
            return pdFALSE;
        }

        key_id = atoi(param2);
        int ecc_algo = atoi(param3);
        req.ecc_curve = ecc_algo;
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file) + 240);
        bytes_read = fat_read(file, buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.src = buf;
        req.src_len = bytes_read;

        file = (char*)param5;
        space_pos = strchr(param5, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        char *sig_buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, sig_buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            vPortFree(sig_buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.signature = sig_buf;
        req.signature_len = bytes_read;
        char *pubkey_buf = NULL;
        bytes_read = 0;
        if(key_id == 0 && param6 == NULL)
        {
            printf("\r\nNo public key provided");
            printf("\r\nEnter fcs ecdsa_hash_verify help for more information");
            return pdFALSE;
        }
        if( param6 != NULL && key_id == 0)
        {
            file = (char*)param6;
            pubkey_buf = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, pubkey_buf);
            if(bytes_read == 0)
            {
                vPortFree(buf);
                vPortFree(sig_buf);
                vPortFree(pubkey_buf);
                printf("\r\nERROR: Failed to read file");
                return pdFALSE;
            }
        }
        req.pubkey = pubkey_buf;
        req.pubkey_len = bytes_read;
        req.dst = verify_status;
        req.dst_len = &resp_size;

        ret = fcs_ecdsa_hash_verify(cli.uuid, FCS_CLI_CONTEXT_ID,
                key_id, &req);

        if (ret != 0)
        {
            printf("\r\nERROR: Failed to verify");
            vPortFree(buf);
            vPortFree(sig_buf);
            if(pubkey_buf != NULL)
            {
                vPortFree(pubkey_buf);
            }
            return pdFALSE;
        }
        printf("\r\nECDSA hash data verification command executed successfully");
        printf("\r\nStatus: %x%x%x%x", verify_status[0], verify_status[1],
                verify_status[2], verify_status[3]);

        vPortFree(buf);
        vPortFree(sig_buf);
        if(pubkey_buf != NULL)
        {
            vPortFree(pubkey_buf);
        }
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdsa_sha2_sign") == 0)
    {
        struct fcs_ecdsa_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rSigns the data using SHA2 with the specified key_id, ECC curve and source data.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs ecdsa_sha2_sign <key_id> <ecc_algo> <input_file> <signature_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id          - ID of the key to be used for SHA2 data sign");
            printf("\r\n  ecc_algo        - ECC Algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  input_file      - File name to read input data");
            printf("\r\n  signature_file  - File name which to store signature");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdsa_sha2_sign help for more information");
            return pdFALSE;
        }

        key_id = atoi(param2);
        int ecc_algo = atoi(param3);
        req.ecc_curve = ecc_algo;
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.src = buf;
        req.src_len = bytes_read;

        char *sig_buf = pvPortMalloc(120);
        req.dst = sig_buf;
        req.dst_len = &resp_size;

        ret = fcs_ecdsa_sha2_data_sign(cli.uuid, FCS_CLI_CONTEXT_ID,
                key_id, &req);

        if (ret != 0)
        {
            printf("\r\nERROR: Failed to sign");
            vPortFree(buf);
            vPortFree(sig_buf);
            return pdFALSE;
        }
        printf("\r\nData signed successfully");

        file = (char*)param5;
        fat_write(file, sig_buf, resp_size);
        vPortFree(buf);
        vPortFree(sig_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdsa_sha2_verify") == 0)
    {
        struct fcs_ecdsa_verify_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rVerifies the data using sha2 with the specifed key ID, ECC curve, source data,"
                   "\r\nsignature data and public key data if key ID is not known.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs ecdsa_sha2_verify <key_id> <ecc_algo> <input_file> <signature_file> [pubkey_file]");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id          - ID of the key to be used for SHA2 data verification, 0 for using public key");
            printf("\r\n  ecc_algo        - ECC Algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  input_file      - File name to read input data");
            printf("\r\n  signature_file  - File name which contains signature of input");
            printf("\r\n  pubkey_file     - Public key file if key id is not known(provide key id as 0)."
                   "\r\n                    This file is optional and only provided when key id is 0");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdsa_sha2_verify help for more information");
            return pdFALSE;
        }

        key_id = atoi(param2);
        int ecc_algo = atoi(param3);
        req.ecc_curve = ecc_algo;
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file) + 240);
        bytes_read = fat_read(file, buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.src = buf;
        req.src_len = bytes_read;

        file = (char*)param5;
        space_pos = strchr(param5, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        char *sig_buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, sig_buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            vPortFree(sig_buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.signature = sig_buf;
        req.signature_len = bytes_read;
        char *pubkey_buf = NULL;
        bytes_read = 0;
        if(key_id == 0 && param6 == NULL)
        {
            printf("\r\nNo public key provided");
            printf("\r\nEnter fcs ecdsa_sha2_verify help for more information");
            return pdFALSE;
        }
        if( param6 != NULL && key_id == 0)
        {
            file = (char*)param6;
            pubkey_buf = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, pubkey_buf);
            if(bytes_read == 0)
            {
                vPortFree(buf);
                vPortFree(sig_buf);
                vPortFree(pubkey_buf);
                printf("\r\nERROR: Failed to read file");
                return pdFALSE;
            }
        }
        req.pubkey = pubkey_buf;
        req.pubkey_len = bytes_read;
        req.dst = verify_status;
        req.dst_len = &resp_size;

        ret = fcs_ecdsa_sha2_data_verify(cli.uuid, FCS_CLI_CONTEXT_ID,
                key_id, &req);

        if (ret != 0)
        {
            printf("\r\nERROR: Failed to verify");
            vPortFree(buf);
            vPortFree(sig_buf);
            if(pubkey_buf != NULL)
            {
                vPortFree(pubkey_buf);
            }
            return pdFALSE;
        }
        printf("\r\nECDSA SHA2 data verification command executed successfully");
        printf("\r\nStatus: %x%x%x%x", verify_status[0], verify_status[1],
                verify_status[2], verify_status[3]);

        vPortFree(buf);
        vPortFree(sig_buf);
        if(pubkey_buf != NULL)
        {
            vPortFree(pubkey_buf);
        }
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdsa_get_public_key") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGenerates a public key for the specified key ID and ECC curve.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs ecdsa_get_public_key <key_id> <ecc_algo> <file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id      - ID of the key to be used for public key retrieval");
            printf("\r\n  ecc_algo    - ECC Algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  file        - File name to store the public key");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdsa_get_public_key help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        key_id = atoi(param2);
        int ecc_algo = atoi(param3);
        file = (char*)param4;
        buf = pvPortMalloc(120);
        if (buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for public key buffer");
            return pdFALSE;
        }
        ret = fcs_ecdsa_get_pub_key(cli.uuid, FCS_CLI_CONTEXT_ID, key_id, ecc_algo,
                buf, &resp_size);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to get public key");
            vPortFree(buf);
            return pdFALSE;
        }
        printf("\r\nPublic key retrieved successfully");
        fat_write(file, buf, resp_size);
        vPortFree(buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "ecdh_request") == 0)
    {
        struct fcs_ecdh_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rGenerates shared secret.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs ecdh_request <key_id> <ecc_algo> <pub_key_file> <shared_sec_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id           - ID of the key to be used for ECDH");
            printf("\r\n  ecc_algo         - ECC Algorithm: 1 - NISTP256, 2 - NISTP384, 3 - Brainpool256, 4 - Brainpool384");
            printf("\r\n  pub_key_file     - File name containing the public key");
            printf("\r\n  shared_sec_file  - File name to store the shared secret");
            return pdFALSE;
        }

        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs ecdh_request help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }

        key_id = atoi(param2);
        req.ecc_curve = atoi(param3);
        file = (char*)param4;
        space_pos = strchr(param4, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }

        buf = pvPortMalloc(fat_get_size(file));
        resp_buf = pvPortMalloc(FCS_ECDH_MAX_RESP);
        if (buf == NULL || resp_buf == NULL)
        {
            printf("\r\nERROR: Failed to allocate memory for ECDH buffers");
            return pdFALSE;
        }

        bytes_read = fat_read(file, buf);
        if (bytes_read == 0)
        {
            printf("\r\nERROR: Failed to read public key from file");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }
        req.pubkey = buf;
        req.pubkey_len = bytes_read;
        req.shared_secret = resp_buf;
        req.shared_secret_len = &resp_size;
        ret = fcs_ecdh_request(cli.uuid, key_id, FCS_CLI_CONTEXT_ID, &req);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to complete ECDH request");
            vPortFree(buf);
            vPortFree(resp_buf);
            return pdFALSE;
        }

        printf("\r\nECDH request completed successfully");
        file = (char*)param5;
        fat_write(file, resp_buf, resp_size);
        vPortFree(buf);
        vPortFree(resp_buf);
        return pdFALSE;
    }
    else if(strcmp(temp_str, "hkdf_request") == 0)
    {
        struct fcs_hkdf_req req;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len);
        param6 = FreeRTOS_CLIGetParameter(command_string, 6, &param6_str_len);
        param7 = FreeRTOS_CLIGetParameter(command_string, 7, &param7_str_len);

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rRequest HKDF operation.");
            printf("\r\n\nUsage");
            printf("\r\n  fcs hkdf_request <key_id> <step_type> <mac_mode> <input_file> <input_file_2> <key_object_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  key_id           - ID of the key to be used for HKDF request, provide as 0");
            printf("\r\n  step_type        - 0 - Extract then expand, 1 - Expand only(non-GCM), 2 - Expand only(GCM)");
            printf("\r\n  mac_mode         - 0 - SHA256, 1 - SHA384, 2 - SHA512");
            printf("\r\n  input_file       - File name containing shared secret or fixed info according to step_type"
                   "\r\n                     48 bytes shared secret for step 0"
                   "\r\n                     80 bytes maximum fixed info for others");
            printf("\r\n  input_file_2     - File name containing 80 bytes maximum fixed info for step 0 and step 2."
                   "\r\n                     Not applicable to step_type 1");
            printf("\r\n  key_object_file  - File name containing output key object"
                   "\r\n                     HMAC384 exchange key object for step 0"
                   "\r\n                     HMAC384 sign/verify/exchange key object for step 1"
                   "\r\n                     AES256 encryption/decryption for step 2");
            return pdFALSE;
        }
        if (param2 == NULL || param3 == NULL || param4 == NULL ||
            param5 == NULL || param6 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs hkdf_request help for more information");
            return pdFALSE;
        }

        key_id = atoi(param2);
        int step_type = atoi(param3);
        int mac_mode = atoi(param4);
        req.step_type =step_type;
        req.mac_mode = mac_mode;

        file = (char*)param5;
        space_pos = strchr(param5, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }
        buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        if(bytes_read > 80)
        {
            printf("\r\nERROR: Invalid input file size");
            vPortFree(buf);
            return pdFALSE;
        }
        req.input1 = buf;
        req.input1_len = bytes_read;

        file = (char*)param6;
        char *buf_2 = NULL;
        bytes_read = 0;
        if(step_type != 1)
        {
            space_pos = strchr(param6, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            buf_2 = pvPortMalloc(fat_get_size(file));
            bytes_read = fat_read(file, buf_2);
            if(bytes_read == 0)
            {
                vPortFree(buf);
                vPortFree(buf_2);
                printf("\r\nERROR: Failed to read file");
                return pdFALSE;
            }
            if(bytes_read > 80)
            {
                printf("\r\nERROR:Invalid input file size");
                vPortFree(buf);
                vPortFree(buf_2);
                return pdFALSE;
            }
            file = (char*)param7;
        }
        req.input2 = buf_2;
        req.input2_len = bytes_read;

        key_buf = pvPortMalloc(fat_get_size(file));
        bytes_read = fat_read(file, key_buf);
        if(bytes_read == 0)
        {
            vPortFree(buf);
            vPortFree(buf_2);
            vPortFree(key_buf);
            printf("\r\nERROR: Failed to read file");
            return pdFALSE;
        }
        req.output_key_obj = key_buf;
        req.output_key_obj_len = bytes_read;

        ret = fcs_hkdf_request(cli.uuid, key_id, &req);

        if (ret != 0)
        {
            printf("\r\nERROR: Failed perform HKDF request");
            vPortFree(buf);
            vPortFree(key_buf);
            if(buf_2 != NULL)
            {
                vPortFree(buf_2);
            }
            return pdFALSE;
        }
        printf("\r\nHKDF request completed");
        vPortFree(buf);
        vPortFree(key_buf);
        if(buf_2 != NULL)
        {
            vPortFree(buf_2);
        }
        return pdFALSE;
    }
    else if(strcmp(temp_str, "validate_image") == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, "help") == 0)
        {
            printf("\rValidates the image using the specified certificate.");
            printf("\r\n\nUsage:");
            printf("\r\n  fcs validate_image <cert_file>");
            printf("\r\n\nIt requires the following arguments");
            printf("\r\n  cert_file  - File name containing the certificate");
            return pdFALSE;
        }
        if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect parameters");
            printf("\r\nEnter fcs validate_image help for more information");
            return pdFALSE;
        }
        if(cli.session_opened == 0)
        {
            printf("\r\nERROR: Session not opened");
            return pdFALSE;
        }
        file = (char*)param2;
        ret = fcs_validate_hps_image(cli.uuid, file);
        if (ret != 0)
        {
            printf("\r\nERROR: Failed to validate image");
            return pdFALSE;
        }
        printf("\r\nImage validated successfully");
        return pdFALSE;
    }
    else
    {
        printf("Invalid command. Type 'fcs help' for a list of commands.\n");
    }
    return pdFALSE;
}

