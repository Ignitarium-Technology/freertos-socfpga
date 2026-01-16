/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for I3C bus
 */

/**
 * @defgroup cli_ros ROS
 * @ingroup cli
 *
 * Perform operations on ROS
 *
 * @details
 * It supports the following commands:
 * -ros erase   &lt;slot&gt;
 * -ros program &lt;slot&gt; &lt;file&gt;
 * -ros verify  &lt;slot&gt; &lt;file&gt;
 * -ros help
 *
 * Typical usage:
 * - Use  'ros erase' command to erase a slot.
 * - Use  'ros program' command to program a slot with sdcard file..
 * - Use  'ros verify' command to verify a slot with a sdcard file.
 * @section ros_commands Commands
 * @subsection ros_erase ros erase
 * Erase the content of the slot  <br>
 *
 * Usage:  <br>
 *   ros erase &lt;slot_num&gt;  <br>
 *
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 *
 * @subsection ros_program ros program
 * Write image to a given slot  <br>
 *
 * Usage:  <br>
 *   ros program &lt;slot_num&gt; &lt;file&gt; <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 * - file    -      The name of the sdcard image(use absolute path).  <br>
 *
 * @subsection ros_verify ros verify
 * Verify image in the slot to the file  <br>
 *
 * Usage:  <br>
 *   ros verify &lt;slot_num&gt; &lt;file&gt; <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 * - file    -      The name of the sdcard image(use absolute path).  <br>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <socfpga_uart.h>
#include <FreeRTOS_CLI.h>
#include "cli_app.h"
#include "osal_log.h"
#include "cli_utils.h"
#include <libRSU.h>

#define SLOT_ERASE_CMD    ("erase")
#define SLOT_PRGM_CMD     ("program")
#define SLOT_VRFY_CMD     ("verify")


BaseType_t cmd_ros( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void) write_buffer_len;
    (void) write_buffer;

    const char *param1;
    const char *param2;
    const char *param3;

    BaseType_t param1_str_len;
    BaseType_t param2_str_len;
    BaseType_t param3_str_len;

    uint32_t slot_num;
    char temp_str[20] = { 0 };
    long int total_slots;
    int ret;

    param1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len);
    strncpy(temp_str, param1, param1_str_len);

    if (strncmp( param1, "help", 4) == 0)
    {
        printf("\r\nPerform ros operations in a rsu suppoted image"
                "\r\n\nIt supports the following sub commands:"
                "\r\n  ros erase   <slot>"
                "\r\n  ros program <slot> <file>"
                "\r\n  ros verify  <slot> <file>"
                "\r\n  ros help"
                "\r\n\nTypical usage:"
                "\r\n- Use erase command to erase a slot."
                "\r\n- Use program command to program a slot with sdcard file."
                "\r\n- Use verify command to verify a slot with a sdcard file."
                "\r\n  ros <command> help\r\n"
                );

        return pdFALSE;
    }

    param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
    if (strcmp(temp_str, SLOT_ERASE_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nErase ros slot"
                    "\r\n\nUsage:"
                    "\r\n  ros erase <slot>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot      slot in the rsu image to be erased."
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (param2 == NULL)
        {
            PRINT(
                    "Incorrect number of arguments for ros slot_erase command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret = cli_get_decimal("ros erase","slot", param2, 0,
                (total_slots - 1),
                &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_erase(slot_num) != 0)
        {
            ERROR("Failed to ersase the slot : %d", slot_num);
            librsu_exit();
            return pdFAIL;
        }
        PRINT("SLOT %d ERASED SUCCESSFULLY", slot_num);
        librsu_exit();
        return pdFALSE;
    }
    else if (strcmp(temp_str, SLOT_PRGM_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nProgram  slot with sdcard file"
                    "\r\n\nUsage:"
                    "\r\n  ros program <slot> <file>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   ros slot that has to be programmed"
                    "\r\n  file   file to be programmed from sdcard(Ex: /fip.bin)"
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        if ((param2 == NULL) || (param3 == NULL))
        {
            PRINT(
                    "Incorrect number of arguments for ros slot_program command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("\r\nFailed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret =
                cli_get_decimal("ros program","slot", param2, 0,
                (total_slots - 1),
                &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_program_file_raw(slot_num,(char *) param3) != 0)
        {
            ERROR("Failed to program slot %d", slot_num);
            librsu_exit();
            return pdFAIL;
        }
        PRINT("SLOT %d PROGRAMMING SUCCESSFUL", slot_num);
        librsu_exit();
        return pdFALSE;
    }
    else if (strcmp(temp_str, SLOT_VRFY_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nVerify ros slot with sdcard file"
                    "\r\n\nUsage:"
                    "\r\n  ros verify <slot> <file>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   ros slot that has to be programmed"
                    "\r\n  file   file to be verified  from sdcard(Ex: /fip.rpd)"
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        if ((param2 == NULL) || (param3 == NULL))
        {
            PRINT(
                    "Incorrect number of arguments for ros slot_verify command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret =
                cli_get_decimal("ros verify","slot", param2, 0,
                (total_slots - 1),
                &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_verify_file_raw(slot_num,(char *) param3) != 0)
        {
            ERROR("Failed to verify slot %d", slot_num);
            librsu_exit();
            return pdFAIL;
        }
        PRINT("SLOT %d VERIFICATION SUCCESSFUL", slot_num);
        librsu_exit();
        return pdFALSE;
    }
    else
    {
        PRINT("Invalid command for ros");
        PRINT("Enter 'help' to view the list of available commands.");
        return pdFAIL;
    }
    return pdFALSE;
}
