/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL implementation for fpga manager
 */

/*
 * This is the driver implementation for the FPGA manager. The FPGA manger uses
 * SIP-SVC calls to invoke services from Secure Device Manager to load the
 * bit streams.
 *
 *                +----------------------+
 *                |   Application        |
 *                +---------+------------+
 *                          |
 *                          v
 *          +---------------------------------+
 *          |       FPGA Manager Driver       |
 *          |                                 |
 *          |   +----------------------+      |
 *          |   |       SIP-SVC        |      |
 *          |   +----------------------+      |
 *          +---------------+-----------------+
 *                          |
 *                          v
 *              +-----------------------+
 *              |         ATF           |
 *              | (ARM Trusted Firmware)|
 *              +----------+------------+
 *                          |
 *                          v
 *              +----------------------+
 *              |         SDM          |
 *              |Secure Device Manager)|
 *              +----------------------+
 */

#include <string.h>
#include "osal.h"
#include "osal_log.h"
#include "socfpga_sip_handler.h"
#include "socfpga_mbox_client.h"
#include "socfpga_fpga_manager.h"

/* SMC SiP service function identifier for version 1 */
#define FPGA_CONFIG_START             (0xC2000001U)
#define FPGA_CONFIG_WRITE_COMPLETE    (0xC2000003U)
#define FPGA_CONFIG_WRITE             (0x42000002U)
#define FPGA_CONFIG_ISDONE            (0xC2000004U)

#define SMC_CMD_SUCCESS        (0x0)
#define SMC_STATUS_BUSY        (0x1)
#define SMC_STATUS_REJECTED    (0x2)
#define SMC_STATUS_ERROR       (0x4)

/**
 * @brief Send the bitstream data to the fpga via SDM
 */
static int send_fpga_bitstream(void *rbf_ptr, size_t file_size)
{
    uint64_t sdm_args[8];
    uint64_t resp_buffer[3];
    int smc_ret;
    int retry = 100;

    /* clear all arguments for CONFIG_START command */
    (void)memset(sdm_args, 0, sizeof(sdm_args));
    sdm_args[0] = 0UL;

    smc_ret = smc_call(FPGA_CONFIG_START, sdm_args);

    if (smc_ret != SMC_CMD_SUCCESS)
    {
        ERROR("Failed to start the fpga configuration. sip smc return, %d", smc_ret);
        return -EIO;
    }

    /* Send the bitstream to the SDM via SiP SMC service */

    sdm_args[0] = (uint64_t)rbf_ptr;
    sdm_args[1] = (uint64_t)file_size;

    smc_ret = smc_call(FPGA_CONFIG_WRITE, sdm_args);

    if (smc_ret != SMC_CMD_SUCCESS)
    {
        PRINT("Failed to send bitstream, sip smc return, %d", smc_ret);
        return -EIO;
    }

    PRINT("Bitstream data send successfully");

    /* Clear response buffer */
    memset(resp_buffer, 0x0, sizeof(resp_buffer));

    do
    {
        /* Check if the bitstream write is completed or not */
        smc_ret = smc_call(FPGA_CONFIG_WRITE_COMPLETE, resp_buffer);

        if (smc_ret == SMC_CMD_SUCCESS)
        {
            int flag = 0;
            for (int i = 0; i < 3; i++)
            {
                /* If command is successful, check if all the response data is 0 */
                if (resp_buffer[i] != 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                /* Check for reconfig status */
                memset(sdm_args, 0, sizeof(sdm_args));
                smc_ret = smc_call(FPGA_CONFIG_ISDONE, sdm_args);
                if (smc_ret == SMC_CMD_SUCCESS)
                {
                    INFO("Fpga configuration completed, sip smc ret %d", smc_ret);
                    return 0;
                }
                else
                {
                    ERROR("SiP smc command failed, ret %d", smc_ret);
                    return -EIO;
                }
            }
        }
        else if (smc_ret == SMC_STATUS_ERROR)
        {
            ERROR("Failed to write bitstream data, sip smc return, %d", smc_ret);
            return -EIO;
        }
        else if (smc_ret == SMC_STATUS_BUSY)
        {
            DEBUG("sip smc status busy");
        }

        osal_delay_ms(10);

    } while(--retry > 0);

    if (retry <= 0)
    {
        ERROR("Timeout occurred");
        return -ETIMEDOUT;
    }

    return -EIO;
}

int load_fpga_bitstream(uint8_t *rbf_ptr, uint32_t rbf_file_size)
{
    int ret;

    ret = send_fpga_bitstream(rbf_ptr, rbf_file_size);

    if (ret != 0)
    {
        ERROR("FPGA configuration failed");
        return ret;
    }

    INFO("FPGA Configuration OK.");

    return 0;
}
