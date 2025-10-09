/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for RSU
 */

/**
 * @defgroup cli_rsu RSU
 * @ingroup cli
 *
 * Perform operations on RSU
 *
 * @details
 * It supports the following commands:
 * -rsu count
 * -rsu log
 * -rsu info    &lt;slot&gt;
 * -rsu erase   &lt;slot&gt;
 * -rsu program &lt;slot&gt; &lt;file&gt;
 * -rsu verify  &lt;slot&gt; &lt;file&gt;
 * -rsu load    &lt;slot&gt;
 * -rsu help
 *
 * Typical usage:
 * - Use  'rsu count' command to get the number of slots..
 * - Use  'rsu log'   command to get current slot details.
 * - Use  'rsu erase' command to erase a slot.
 * - Use  'rsu program' command to program a slot with sdcard file..
 * - Use  'rsu verify'  command to verify a slot with a sdcard file.
 * - Use  'rsu load'    command to load a slot after reboot..
 * @section rsu_commands Commands
 * @subsection rsu_count rsu count
 * Count the number of rsu slots  <br>
 *
 * Usage:  <br>
 *   rsu count  <br>
 *
 * No arguments.  <br>
 *
 * @subsection rsu_log rsu log
 * List the details of current slot  <br>
 *
 * Usage:  <br>
 *   rsu log <br>
 *
 * No arguments
 *
 * @subsection rsu_info rsu info
 * Get the information about the slot number  <br>
 *
 * Usage:  <br>
 *   rsu info &lt;slot_num&gt;  <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 *
 * @subsection rsu_erase rsu erase
 * Erase the content of the slot  <br>
 *
 * Usage:  <br>
 *   rsu erase &lt;slot_num&gt;  <br>
 *
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 *
 * @subsection rsu_program rsu program
 * Write image to a given slot  <br>
 *
 * Usage:  <br>
 *   rsu program &lt;slot_num&gt; &lt;file&gt; <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 * - file    -      The name of the sdcard image(use absolute path).  <br>
 *
 * @subsection rsu_verify rsu verify
 * Verify image in the slot to the file  <br>
 *
 * Usage:  <br>
 *   rsu verify &lt;slot_num&gt; &lt;file&gt; <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 * - file    -      The name of the sdcard image(use absolute path).  <br>
 *
 * @subsection rsu_load rsu load
 * Load the image in the given slot after reboot  <br>
 *
 * Usage:  <br>
 *   rsu load &lt;slot_num&gt; <br>
 * It requires the following arguments:
 * - slot_num -      The slot number  <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <socfpga_uart.h>
#include <FreeRTOS_CLI.h>
#include "cli_app.h"
#include "cli_utils.h"
#include "osal_log.h"
#include <libRSU.h>

#define SLOT_COUNT_CMD    ("count")
#define SLOT_INFO_CMD     ("info")
#define SLOT_ERASE_CMD    ("erase")
#define SLOT_PRGM_CMD     ("program")
#define SLOT_LOAD_CMD     ("load")
#define STATUS_LOG_CMD    ("log")
#define SLOT_VRFY_CMD     ("verify")


BaseType_t cmd_rsu( char *write_buffer, size_t write_buffer_len,
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
    int ret;
    long int total_slots;

    param1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len);
    strncpy(temp_str, param1, param1_str_len);

    if (strncmp( param1, "help", 4) == 0)
    {
        printf("\r\nPerform rsu operations in a rsu suppoted image"
                "\r\n\nIt supports the following sub commands:"
                "\r\n  rsu count"
                "\r\n  rsu log"
                "\r\n  rsu info    <slot>"
                "\r\n  rsu erase   <slot>"
                "\r\n  rsu program <slot> <file>"
                "\r\n  rsu verify  <slot> <file>"
                "\r\n  rsu load    <slot>"
                "\r\n  rsu help"
                "\r\n\nTypical usage:"
                "\r\n- Use count command to get the number of slots."
                "\r\n- Use log command to get current slot details."
                "\r\n- Use info command to get details of a slot."
                "\r\n- Use erase command to erase a slot."
                "\r\n- Use program command to program a slot with sdcard file."
                "\r\n- Use verify command to verify a slot with a sdcard file."
                "\r\n- Use load command to load a slot after reboot."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  rsu <command> help\r\n"
                );

        return pdFALSE;
    }

    param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
    if (strcmp(temp_str, STATUS_LOG_CMD) == 0)
    {
        struct rsu_status_info info;
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        if (rsu_status_log(&info) != 0)
        {
            ERROR("Failed to fetch status log");
            librsu_exit();
            return pdFAIL;
        }
        printf("\r\n      VERSION: 0x%08X", (int)info.version);
        printf("\r\n        STATE: 0x%08X", (int)info.state);
        printf("\r\nCURRENT IMAGE: 0x%016lX", info.current_image);
        printf("\r\n   FAIL IMAGE: 0x%016lX", info.fail_image);
        printf("\r\n    ERROR LOC: 0x%08X", (int)info.error_location);
        printf("\r\nERROR DETAILS: 0x%08X\r\n", (int)info.error_details);
        if (RSU_VERSION_DCMF_VERSION(info.version) &&
                RSU_VERSION_ACMF_VERSION(info.version))
        {
            printf("\r\nRETRY COUNTER: 0x%08X", (int)info.retry_counter);
        }
        librsu_exit();
        return pdFALSE;
    }
    else if (strcmp(temp_str, SLOT_INFO_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nGet the slot info"
                    "\r\n\nUsage:"
                    "\r\n  rsu info <slot>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   slot number of the slot."
                    );
            return pdFALSE;
        }
        struct rsu_slot_info info;
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (param2 == NULL)
        {
            PRINT("Incorrect number of arguments for rsu info command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret = cli_get_decimal("rsu info","slot", param2, 0, (total_slots - 1),
                &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_get_info(slot_num, &info) != 0)
        {
            ERROR("Failed to get slot info");
            librsu_exit();
            return pdFAIL;
        }
        printf("\r\n      NAME: %s", info.name);
        printf("\r\n    OFFSET: 0x%016lX", info.offset);
        printf("\r\n      SIZE: 0x%08X", info.size);
        if (info.priority)
        {
            printf("\r\n  PRIORITY: %i", info.priority);
        } else
        {
            printf("\r\n  PRIORITY: [disabled]");
        }
        librsu_exit();
        return pdFALSE;
    }
    else if (strcmp(temp_str, SLOT_COUNT_CMD) == 0)
    {
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        int slotCount = rsu_slot_count();
        if (slotCount < 0)
        {
            ERROR("Failed to get the slot count");
            librsu_exit();
            return pdFAIL;
        }
        PRINT("THE SLOT COUNT IS :%d", slotCount);
        librsu_exit();
        return pdFALSE;
    }
    else if (strcmp(temp_str, SLOT_ERASE_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nErase rsu slot"
                    "\r\n\nUsage:"
                    "\r\n  rsu erase <slot>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot      slot in the rsu image to be erased."
                    );

            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (param2 == NULL)
        {
            PRINT(
                    "Incorrect number of arguments for rsu slot_erase command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret = cli_get_decimal("rsu erase","slot", param2, 0,
                (total_slots - 1), &slot_num);
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
            printf("\r\nProgram rsu slot with sdcard file"
                    "\r\n\nUsage:"
                    "\r\n  rsu program <slot> <file>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   rsu slot that has to be programmed"
                    "\r\n  file   file to be programmed from sdcard(Ex: /app.rpd)"
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        if ((param2 == NULL) || (param3 == NULL))
        {
            PRINT(
                    "Incorrect number of arguments for rsu slot_program command");
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
                cli_get_decimal("rsu program","slot", param2, 0,
                (total_slots - 1), &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_program_file(slot_num, (char *)param3) != 0)
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
            printf("\r\nVerify rsu slot with sdcard file"
                    "\r\n\nUsage:"
                    "\r\n  rsu vefify <slot> <file>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   rsu slot that has to be programmed"
                    "\r\n  file   file to be verified  from sdcard(Ex: /app.rpd)"
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        if ((param2 == NULL) || (param3 == NULL))
        {
            PRINT(
                    "Incorrect number of arguments for rsu slot_verify command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret = cli_get_decimal("rsu verify","slot", param2, 0,
                (total_slots - 1), &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        if (rsu_slot_verify_file(slot_num, (char *)param3) != 0)
        {
            ERROR("Failed to verify slot %d", slot_num);
            librsu_exit();
            return pdFAIL;
        }
        PRINT("SLOT %d VERIFICATION SUCCESSFUL", slot_num);
        librsu_exit();
        return pdFALSE;
    }
    else if ((strcmp(temp_str, SLOT_LOAD_CMD) == 0))
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nLoad image from the slot"
                    "\r\n\nUsage:"
                    "\r\n  rsu load <slot>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  slot   rsu slot that has to be loaded"
                    );
            return pdFALSE;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        if (param2 == NULL)
        {
            PRINT("Incorrect number of arguments for rsu slot_load command");
            PRINT("Enter 'help' to view the list of available commands");
            return pdFAIL;
        }
        if (librsu_init("") != 0)
        {
            ERROR("Failed to initialize libRSU");
            return pdFAIL;
        }
        total_slots = rsu_slot_count();
        ret = cli_get_decimal("rsu load","slot", param2, 0, (total_slots - 1),
                &slot_num);
        if (ret != 0)
        {
            librsu_exit();
            return pdFAIL;
        }
        PRINT("REBOOTING SYSTEM FOR SLOT LOAD");
        if (rsu_slot_load_after_reboot(slot_num) != 0)
        {
            ERROR("Failed to load slot %d", slot_num);
            librsu_exit();
            return pdFAIL;
        }
        librsu_exit();
        return pdFALSE;
    }
    else
    {
        PRINT("Invalid command for rsu");
        printf("Enter 'help' to view the list of available commands.");
        return pdFAIL;
    }
    return pdFALSE;
}
