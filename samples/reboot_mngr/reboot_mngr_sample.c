/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for SoC FPGA reboot manager
 */

/**
 * @file reboot_mngr_sample.c
 * @brief Sample Application for Reboot Manager
 */

#include <stdlib.h>
#include <string.h>
#include "osal.h"
#include "osal_log.h"
#include <task.h>
#include "socfpga_reboot_mngr.h"
#include "socfpga_defines.h"

/**
 * @defgroup rbt_sample Reboot Manager
 * @ingroup samples
 *
 * Sample Application for Reboot Manager
 *
 * @details
 * @section rbt_desc Description
 * This sample application demonstrates the use of the reboot manager driver to
 * perform cold or warm reboot. It sets a user-defined callback function that
 * is invoked before the reboot occurs.
 *
 * @section rbt_param Configurable Parameters
 * The reboot type can be configured using the @c DO_COLD_BOOT macro.
 * If set to 1, a cold reboot is performed; otherwise, a warm reboot.
 * @note The sample application will reboot the system.
 *
 * @section rbt_how_to How to Run
 * 1. Follow the common README instructions to build and flash the application.
 * 2. Run the application on the board.
 * 3. Output can be observed in the UART terminal.
 *
 * @section rbt_result Expected Results
 * - The application will print a message indicating the type of reboot
 * being performed.
 * - The system will reboot, either performing a cold or warm reboot based
 * on the configuration.
 * - The user-defined callback function will be invoked before the reboot.
 */

/**
 * @brief Set the value 1 for cold reboot and 0 for warm reboot
 */
#define DO_COLD_BOOT    1

/**
 * @brief Callback function for handing off before warm boot
 */
void warm_reboot_callback(void *buff)
{
    (void)buff;
    PRINT("Warm reboot");
}

/**
 * @brief Callback function for handing off before cold boot
 */

void cold_reboot_callback(void *buff)
{
    (void)buff;
    PRINT("Cold reboot");
}

void reboot_task(void)
{
    int status;
#if (DO_COLD_BOOT == 1)
    PRINT("Cold reboot example");
    PRINT("Set user callback for cold boot");
    reboot_mngr_set_callback(cold_reboot_callback, REBOOT_COLD);
    PRINT("Triggering cold boot ...");
    status = reboot_mngr_do_reboot(REBOOT_COLD);
#else
    PRINT("Warm reboot example");
    PRINT("Set user callback for warm boot");
    reboot_mngr_set_callback(warm_reboot_callback, REBOOT_WARM);
    PRINT("Triggering warm boot ...");
    status = reboot_mngr_do_reboot(REBOOT_WARM);
#endif
    if (status != 0)
    {
        ERROR("Reboot request failed with error code  %d", status);
    }
}
