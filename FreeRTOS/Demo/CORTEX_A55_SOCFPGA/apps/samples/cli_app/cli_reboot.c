/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of reboot command
 */

/**
 * @defgroup cli_reboot Reboot
 * @ingroup cli
 *
 * Perform system reboot operations
 *
 * @details
 * It supports the following commands:
 * - reboot &lt;type&gt;
 * - reboot help
 *
 * Typical usage:
 * - Use 'reboot cold' for a cold reboot.
 * - Use 'reboot warm' for a warm reboot.
 *
 * @section rbt_commands Commands
 * @subsection reboot reboot
 * Reboot system <br>
 *
 * Usage: <br>
 * reboot &lt;type&gt; <br>
 *
 * It requires the following arguments:
 * - type - The reboot type. Valid values are: <br>
 * - cold – REBOOT_COLD <br>
 * - warm – REBOOT_WARM <br>
 *
 * @subsection rbt_help reboot help
 * Show reboot command help <br>
 *
 * Usage: <br>
 * reboot help <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <socfpga_reboot_mngr.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "semphr.h"


void cold_reboot_callback(void *buff)
{
    (void)buff;
    printf("\r\n Initiating a COLD REBOOT \r\n");
}
void warm_reboot_callback(void *buff)
{
    (void)buff;
    printf("\r\n Initiating a WARM REBOOT \r\n");
}

BaseType_t cmd_reboot(char *write_buffer, size_t write_buffer_len,
        const char *command_string)
{
    (void) write_buffer;
    (void) write_buffer_len;

    const char *parameter1, *parameter2;
    char *space_pos;
    BaseType_t parameter1_str_len, parameter2_str_len, ret;
    ret = pdFALSE;
    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1,
            &parameter1_str_len);

    if (parameter1 == NULL)
    {
        ret = pdTRUE;
    }

    if (strncmp(parameter1, "help", 4) == 0)
    {
        printf("\rPerform reboot operations"
                "\r\n\nIt supports the following subcommands:"
                "\r\n  reboot warm"
                "\r\n  reboot cold"
                "\r\n  reboot help"
                "\r\n\nTypical usage:"
                "\r\n- Use reboot command to do warm/cold reboot."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  reboot <type> help\r\n"
                );
        return pdFALSE;
    }

    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
            &parameter2_str_len);

    space_pos = strchr(parameter1, ' ');
    if (space_pos != NULL)
    {
        *space_pos = '\0';
    }

    space_pos = strchr(parameter2, ' ');
    if (space_pos != NULL)
    {
        *space_pos = '\0';
    }

    /* check for warm reboot */
    if (strncmp(parameter1, "warm", 4) == 0)
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\r\nDo warm reboot."
                    "\r\n\nUsage:"
                    "\r\n reboot warm"
                    );
            return pdFALSE;
        }
        reboot_mngr_set_callback(warm_reboot_callback, REBOOT_WARM);
        reboot_mngr_do_reboot(REBOOT_WARM);
    }
    else if (!strncmp(parameter1, "cold", strlen("cold")))
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\r\nDo cold reboot."
                    "\r\n\nUsage:"
                    "\r\n reboot cold"
                    );
            return pdFALSE;
        }
        reboot_mngr_set_callback(cold_reboot_callback, REBOOT_COLD);
        reboot_mngr_do_reboot(REBOOT_COLD);
    }
    else
    {
        printf("Unsupported reboot command \r\n");
        ret = pdTRUE;
    }

    if (ret != pdFALSE)
    {
        printf("Incorrect command parameter(s).\r\n");
        printf("Type help to see the available commands r\n");
        ret = pdFALSE;
    }
    return ret;
}
