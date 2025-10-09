/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for HPS bridge
 */

/**
 * @defgroup cli_bridge Bridge
 * @ingroup cli
 *
 * Perform bridge operations
 *
 * @details
 * It supports the following subcommands:
 * - bridge disable &lt;instance&gt;
 * - bridge enable  &lt;instance&gt;
 * - bridge help
 *
 * Typical usage:
 * - Use 'bridge enable'  to enable a particular bridge.
 * - Use 'bridge disable' to disable a particular bridge.
 *
 * @section bridge_commands Commands
 * @subsection bridge_enable bridge enable
 * Enable the bridge  <br>
 *
 * Usage:  <br>
 *   bridge enable &lt;instance&gt;  <br>
 *
 * It requires the following arguments:
 * - instance - The instance of the bridge. The instances are mapped as below:  <br>
 *   - 0 - HPS2FPGA bridge  <br>
 *   - 1 - LWHPS2FPGA bridge  <br>
 *   - 2 - FPGA2HPS bridge  <br>
 *   - 3 - FPGA2SDRAM bridge  <br>
 *
 * @subsection bridge_disable bridge disable
 * Disable the bridge  <br>
 *
 * Usage:  <br>
 *   bridge disable &lt;instance&gt;  <br>
 *
 * It requires the following arguments:
 * - instance - The instance of the bridge. The instances are mapped as below:  <br>
 *   - 0 - HPS2FPGA bridge  <br>
 *   - 1 - LWHPS2FPGA bridge  <br>
 *   - 2 - FPGA2HPS bridge  <br>
 *   - 3 - FPGA2SDRAM bridge  <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "cli_utils.h"
#include "osal_log.h"
#include "socfpga_bridge.h"

BaseType_t cmd_bridge( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    char *space_pos;
    const char *parameter1, *parameter2;
    BaseType_t parameter1_str_len, parameter2_str_len;

    int ret = 0;
    uint32_t bridge_num;
    int enable_flag = -1;
    int ret_val;

    (void) write_buffer;
    (void) write_buffer_len;

    parameter1 = FreeRTOS_CLIGetParameter(
            /* The command string itself. */
            command_string,
            /* Return the first parameter. */
            1,
            /* Store the parameter string length. */
            &parameter1_str_len);

    parameter2 = FreeRTOS_CLIGetParameter(
            /* The command string itself. */
            command_string,
            /* Return the first parameter. */
            2,
            /* Store the parameter string length. */
            &parameter2_str_len);
    space_pos = strchr(parameter1, ' ');
    if (space_pos != NULL)
    {
        *space_pos = '\0';
    }

    if (strncmp(parameter1, "help", 4) == 0)
    {
        printf("\r\nPerform bridge operations"
                "\r\n\nIt supports the following subcommands:"
                "\r\n  bridge disable <bridge_number>"
                "\r\n  bridge enable <bridge_number>"
                "\r\n  bridge help"
                "\r\n\nTypical usage:"
                "\r\n - Use enable command to enable a particular bridge."
                "\r\n - Use disable command to disable a particular bridge."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  bridge <command> help\r\n"
                );

        return pdFALSE;
    }

    if (strncmp(parameter1, "enable", 6) == 0)
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\rEnable the bridge"
                    "\r\n\nUsage:"
                    "\r\n  bridge enable <instance>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance    The instance of the bridge. The instance are mapped as below:"
                    "\r\n  			  0 - HPS2FPGA bridge"
                    "\r\n    		  1 - LWHPS2FPGA bridge "
                    "\r\n    		  2 - FPGA2HPS bridge"
                    "\r\n    		  3 - FPGA2SDRAM bridge"
                    );

            return pdFALSE;
        }
        enable_flag = 1;
    }
    else if (strncmp(parameter1, "disable", 7) == 0)
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\rDisable the bridge"
                    "\r\n\nUsage:"
                    "\r\n  bridge disable <instance>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance    The instance of the bridge. The instance are mapped as below:"
                    "\r\n           	  0 - HPS2FPGA bridge"
                    "\r\n              1 - LWHPS2FPGA bridge "
                    "\r\n              2 - FPGA2HPS bridge"
                    "\r\n              3 - FPGA2SDRAM bridge"
                    );

            return pdFALSE;
        }
        enable_flag = 0;
    }
    else
    {
        PRINT("Invalid bridge Command");
        PRINT("Enter 'help' to view a list of available commands.");
        return pdFALSE;
    }

    if (enable_flag == 1)
    {
        if (parameter2 == NULL)
        {
            PRINT("Invalid argument for bridge enable command");
            return pdFAIL;
        }
        ret_val = cli_get_decimal("bridge enable","instance", parameter2, 0, 3,
                &bridge_num);
        if (ret_val != 0)
        {
            return pdFAIL;
        }
    }
    else
    {
        if (parameter2 == NULL)
        {
            PRINT("Invalid argument for bridge disable command");
            return pdFAIL;
        }
        ret_val = cli_get_decimal("bridge disable","instance", parameter2, 0, 3,
                &bridge_num);
        if (ret_val != 0)
        {
            return pdFAIL;
        }
    }
    switch (bridge_num)
    {
    case 0:
        if (enable_flag == 1)
        {
            ret = enable_hps2fpga_bridge();
        }
        else
        {
            ret = disable_hps2fpga_bridge();
        }
        break;

    case 1:
        if (enable_flag == 1)
        {
            ret = enable_lwhps2fpga_bridge();
        }
        else
        {
            ret = disable_lwhps2fpga_bridge();
        }
        break;

    case 2:
        if (enable_flag == 1)
        {
            ret = enable_fpga2hps_bridge();
        }
        else
        {
            ret = disable_fpga2hps_bridge();
        }
        break;

    case 3:
        if (enable_flag == 1)
        {
            ret = enable_fpga2sdram_bridge();
        }
        else
        {
            ret = disable_fpga2sdram_bridge();
        }
        break;

    default:
        PRINT(
                "Invalid bridge number.\r\nPlease type help to see available options ");
        break;
    }

    if (enable_flag == 1)
    {
        if (ret == 0)
        {
            PRINT("Enabled the bridge successfully");
        }
        else
        {
            ERROR("Failed to enable the bridge");
        }
    }
    else
    {
        if (ret == 0)
        {
            PRINT("Disabled the bridge successfully");
        }
        else
        {
            ERROR("Failed to disable the bridge");
        }
    }
    return pdFALSE;
}
