/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * sample implementation for SEU
 */

/**
 * @file seu_sample.c
 * @brief Sample Application for seu operations.
 */

/**
 * @defgroup seu_sample SEU
 * @ingroup samples
 *
 * Sample Application for SEU (Single Event Upset) Injection and Validation
 *
 * @details
 * @section seu_desc Description
 * This sample demonstrates the ability of the system to handle SEU (Single Event Upset)
 * scenarios. It performs operations such as injecting SEU-safe errors, reading back
 * error-injected data, and retrieving SEU-related error statistics for system validation.
 *
 * @section seu_pre Prerequisites
 * - A system or FPGA image (SOF) with SEU feature enabled.
 * - Properly initialized SEU-related hardware or memory regions.
 *
 * @section seu_howto How to Run
 * 1. Follow the common README for building and flashing instructions.
 * 2. Ensure that the board is running a SEU-enabled SOF image.
 * 3. Run the sample binary. The application will:
 *    - Inject known SEU-safe errors into memory.
 *    - Read back and verify that the error injection is as expected.
 *    - Fetch and display SEU error detection statistics.
 *
 * @section seu_res Expected Results
 * - Successful injection and detection of SEU events.
 * - Accurate reporting of SEU statistics and error types.
 * - Demonstrates the system's capability to detect, report, and tolerate SEU faults.
 *
 * @{
 */
/** @} */



#include <stdint.h>
#include "socfpga_seu.h"
#include "socfpga_mbox_client.h"
#include "osal.h"
#include "osal_log.h"

/* Single bit error */
#define ECC_ERROR_TYPE    0x1

#define RAM_ID             0x1
#define ECC_SECTOR_ADDR    0xFF
#define SEU_SECTOR_ADDR    0x5

#define SEU_ERR_INJ_TIMEOUT    2000U

osal_semaphore_def_t seu_semphr_def_inject;
osal_semaphore_t seu_semphr_inject;

void seu_injection_done()
{
    osal_semaphore_post(seu_semphr_inject);
}

void seu_task(void)
{
    uint8_t ret;
    read_err_data_t seu_err_data;
    seu_err_params_t err_params;
    seu_stat_t seu_err_stats;
    seu_semphr_inject = osal_semaphore_create(&seu_semphr_def_inject);

    PRINT("Sample applicaton for seu and ecc error injection starts");
    ret = seu_init();
    if (ret != 0)
    {
        ERROR("SEU init failed");
        return;
    }

    /* Callback for error injection */
    seu_set_call_back(seu_injection_done);

    err_params.sector_addr = SEU_SECTOR_ADDR;
    err_params.cram_sel0 = 0;
    err_params.cram_sel1 = 0;
    err_params.injection_cycle = 0;
    err_params.no_of_injection = 0;

    PRINT("Injecting SEU error");
    ret = seu_insert_safe_err(err_params);
    if (ret != 0)
    {
        ERROR("SEU error injection Failed");
        return;
    }

    /* Waiting for error injection interrupt */
    osal_semaphore_wait(seu_semphr_inject, SEU_ERR_INJ_TIMEOUT);
    PRINT("SEU error injection done");
    PRINT("Reading SEU error data");
    seu_err_data = seu_read_err();
    if (seu_err_data.op_state != 0)
    {
        ERROR("Error Read Failed");
        return;
    }
    PRINT("Error Count %u", seu_err_data.err_cnt);
    PRINT("Injected Sector Address %u", seu_err_data.sector_addr);
    PRINT("Error Type %u \n", seu_err_data.err_type);
    PRINT("Node Specific Status %u ", seu_err_data.node_specific_status);
    PRINT("Correction Status %u ", seu_err_data.correction_status);

    PRINT("Reading SEU error stats");
    seu_err_stats = seu_read_stat(SEU_SECTOR_ADDR);
    if (seu_err_stats.op_state != 0)
    {
        ERROR(" Error Stat Failed \n");
        return;
    }
    PRINT("SEU Cycle %u ", seu_err_stats.t_seu_cycle);
    PRINT("SEU Detect %u ", seu_err_stats.t_seu_detect);
    PRINT("SEU correct  %u ", seu_err_stats.t_seu_correct);
    PRINT("SEU Inject Detect %u ", seu_err_stats.t_seu_inject_detect);
    PRINT("SDM SEU Poll Interval %u ", seu_err_stats.t_sdm_seu_poll_interval);

    PRINT("Inserting ECC error");
    ret = seu_insert_ecc_err(ECC_ERROR_TYPE, RAM_ID, ECC_SECTOR_ADDR);
    if (seu_err_stats.op_state != 0)
    {
        ERROR("ECC Error Insertion Failed");
        return;
    }
    PRINT("ECC Error Insertion Done");
    ret = seu_deinit();
    if (ret != 0)
    {
        ERROR("Failed to close SEU\n");
    }

    PRINT("Sample applicaton for seu and ecc error injection completed");
}
