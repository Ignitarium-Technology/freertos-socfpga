/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for fpga partial reconfiguration
 */


/**
 * @file fpga_pr_sample.c
 * @brief Sample Application for fpga partial reconfiguration.
 */

/**
 * @defgroup fpga_pr_sample Partial reconfiguration
 * @ingroup samples
 *
 * Sample Application for Partial Reconfiguration.
 *
 * @details
 * @section fpga_desc Description
 * This is a sample application to demonstrate the use of the fpga freeze ip to
 * perform partial reconfiguration. The application initially loads the core.rbf
 * and configures the FPGA. Initially, the PR region contains persona0. Then it
 * freezes the particular PR region, and loads the persona1 bitstream. Now the PR
 * region contains persona1 bitstream.
 *
 * The same is confirmed by reading the sysid located at address 0x20020000
 *
 * @section fgpa_pre Prerequisites
 * The required rbf file should be available in the sdmmc before running the sample.
 * By default, the name of the core rbf file is core.rbf and persona1 rbf file is p0.rbf.
 * The below macros can be configured to use different rbf :
 * - @c CORE_RBF  - core rbf file
 * - @c PERSONA1_RBF - persona1 rbf file
 *
 * @section fpga_howto How to Run
 * 1. Follow the common README for build and flashing instructions.
 * 2. Copy all the required rbf file to the SD card, and run the sample. <br>
 * @note File names should conform to the 8.3 format (maximum 8 characters for the name and 3 for the extension).
 *
 * @section fpga_res Expected Results
 * If the bitstream configuration fails in the initial stage, the failure will be shown in the console
 * and the application exits. After persona1 is loaded, the sysid is validated to confirm the successful
 * loading of the persona1 rbf.
 * The success/failure logs are displayed in the console.
 * @{
 */
/** @} */

#include "socfpga_defines.h"
#include "osal_log.h"
#include "socfpga_bridge.h"
#include "socfpga_mmc.h"
#include "socfpga_fpga_manager.h"
#include "fpga_pr_sample.h"
#include "socfpga_freeze_ip.h"

#define CORE_RBF        "/core.rbf"
#define PERSONA1_RBF    "/p1.rbf"

static int load_bitstream(const char *rbf)
{
    uint8_t *rbf_ptr;
    uint32_t file_size = 0U;

    rbf_ptr = mmc_read_file(SOURCE_SDMMC, rbf, &file_size);
    if (rbf_ptr == NULL)
    {
        ERROR("Unable to read bitstream from memory !!!");
        return 0;
    }

    if (load_fpga_bitstream(rbf_ptr, file_size) != 0)
    {
        ERROR("Failed to load bitstream !!!");
        vPortFree(rbf_ptr);
        return 0;
    }

    vPortFree(rbf_ptr);
    PRINT("bitstream configuration successful");

    return 1;
}

static int do_partial_reconfiguration(const char *rbf)
{
    if (do_freeze_pr_region() != 0)
    {
        return -1;
    }

    /* Load the bitstream */
    if (load_bitstream(rbf) == 0)
    {
        ERROR("Bitstream loading failed");
        return -1;
    }
    osal_task_delay(100);

    if (do_unfreeze_pr_region() != 0)
    {
        return -1;
    }

    return 1;
}

void partial_reconfiguration_sample(void)
{
    uint32_t sysid, freeze_reg_version;

    /* Load the core.rbf with persona0 instantiated */
    if (load_bitstream(CORE_RBF) == 0)
    {
        ERROR("Bitstream loading failed");
        return;
    }

    /* Enable the lwhps2fpga bridge */
    if (enable_lwhps2fpga_bridge() != 0)
    {
        ERROR("Failed to enable the FPGA2HPS bridge !!!");
        return;
    }

    /* By default, person0 sysid is present in the core.rbf */
    sysid = RD_REG32(SYSID_REG);
    if (sysid != PERSONA0_SYSID)
    {
        ERROR("Incorrect sysid");
        return;
    }

    PRINT("SYS ID 0 : %x", sysid);

    freeze_reg_version = RD_REG32(PR_FREEZE_BASE + FREEZE_REG_VERSION_OFF);
    if (freeze_reg_version != FREEZE_REG_VERSION)
    {
        ERROR("Freeze IP version does not match");
        return;
    }
    PRINT("Freeze IP Version : %x", freeze_reg_version);

    /* Process for Partial Reconfiguration */
    if (do_partial_reconfiguration(PERSONA1_RBF) == 1)
    {
        PRINT("PR configuration done");
    }
    else
    {
        ERROR("PR Configuration failed");
        return;
    }

    sysid = RD_REG32(SYSID_REG);
    if (sysid != PERSONA1_SYSID)
    {
        ERROR("Incorrect sysid");
        return;
    }
    PRINT("SYS ID 1 : %x", sysid);

    PRINT("PR sample completed ");
}
