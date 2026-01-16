/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for QSPI flash
 */

/**
 * @defgroup cli_qspi QSPI
 * @ingroup cli
 *
 * Perform flash operations on a flash device connected to QSPI bus
 *
 * @details
 * It supports the following commands:
 * - qspi erase &lt;instance&gt; &lt;address&gt; &lt;bytes&gt;
 * - qspi write &lt;instance&gt; &lt;address&gt; &lt;data&gt;...
 * - qspi read  &lt;instance&gt; &lt;address&gt; &lt;bytes&gt;
 * - qspi help
 *
 * Typical usage:
 * - Use 'qspi erase' command to erase the QSPI flash.
 * - Use 'qspi write' command to write data to the QSPI flash.
 * - Use 'qspi read' command to read data from the QSPI flash.
 *
 * @section qspi_commands Commands
 * @subsection qspi_erase qspi erase
 * Erase QSPI flash data  <br>
 *
 * Usage: <br>
 *   qspi erase &lt;instance&gt; &lt;address&gt; &lt;bytes&gt; <br>
 *
 * It requires the following arguments:
 * - instance -  Instance of the QSPI flash device.
 * - address -   Target memory address (hex or decimal).
 * - bytes -     Number of bytes to erase (positive integer).
 *
 * @subsection qspi_write qspi write
 * Write data to QSPI flash  <br>
 *
 * Usage: <br>
 *   qspi write &lt;instance&gt; &lt;address&gt; &lt;data&gt;... <br>
 *
 * It requires the following arguments:
 * - instance  Instance of the QSPI flash device.
 * - address   Target memory address (hex or decimal).
 * - data      One or more data values to write (each a positive integer).
 * <br>
 * @subsection qspi_read qspi read
 * Read data from QSPI flash
 *
 * Usage: <br>
 *   qspi read &lt;instance&gt; &lt;address&gt; &lt;bytes&gt;
 *
 * It requires the following arguments:
 * - instance  Instance of the QSPI flash device.
 * - address   Target memory address (hex or decimal).
 * - bytes     Number of bytes to read (positive integer).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <socfpga_uart.h>
#include <FreeRTOS_CLI.h>
#include "cli_app.h"
#include "socfpga_flash.h"
#include "socfpga_qspi.h"
#include "socfpga_cache.h"
#include "osal_log.h"
#include "cli_utils.h"

#define READ_CMD         ("read")
#define WRITE_CMD        ("write")
#define ERASE_CMD        ("erase")
#define SECTOR_SIZE      (1024 * 4)

#define CLI_QSPI_OK      0
#define CLI_QSPI_FAIL    1

uint8_t wrbuf[ 256 ] = { 0 };
uint8_t rdbuf[ 256 ] = { 0 };

BaseType_t cmd_qspi( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void) write_buffer_len;
    (void) write_buffer;

    const char *param1;
    const char *param2;
    const char *param3;
    const char *param4;
    BaseType_t param1_str_len;
    BaseType_t param2_str_len;
    BaseType_t param3_str_len;
    BaseType_t param4_str_len;
    BaseType_t ret = pdTRUE;

    char temp_str[ 6 ] = { 0 };
    uint32_t instance;
    flash_handle_t flash_handle;
    uint32_t targ_addr;
    uint32_t size;
    uint32_t status;
    int32_t idx;
    int32_t erase_cnt;
    int ret_val;

    param1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len); /* get first command */
    strncpy(temp_str, param1, param1_str_len);

    if (strncmp( param1, "help", 4) == 0)
    {
        printf("\r\nPerform flash operations on a flash device connected to qspi"
                "\r\n\nIt supports the following subcommands:"
                "\r\n  qspi erase <instance> <address> <bytes>"
                "\r\n  qspi write <instance> <address> <value>"
                "\r\n  qspi read <instance> <address> <bytes>"
                "\r\n  qspi help"
                "\r\n\nTypical usage:"
                "\r\n- Use erase command to erase the qspi."
                "\r\n- Use write command to write data to the qspi after an erase."
                "\r\n- Use read  command to read data from the qspi."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  qspi <command> help\r\n"
                );

        return pdFALSE;
    }
    param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); /* get instance */

    if (strncmp(param1, ERASE_CMD, 5) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nErase qspi flash data"
                    "\r\n\nUsage:"
                    "\r\n  qspi erase <instance> <address> <bytes>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance  instance of the qspi flash device."
                    "\r\n  address   target memory address."
                    "\r\n  bytes     number of bytes to be erased. The argument should be a postive integer."
                    );

            return pdFALSE;
        }

        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len); /* get address */
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len); /* get no. of bytes to be erased */

        if ((param2 == NULL) || (param3 == NULL) || (param4 == NULL))
        {
            PRINT("Incorrect number of arguments for qspi erase command.");
            PRINT("Please try 'qspi erase help'");
            return pdFAIL;
        }

        ret_val =
                cli_get_decimal("qspi erase","instance", param2, 0, 3, &instance);
        if (ret_val != 0)
        {
            return pdFAIL;
        }

        flash_handle = flash_open(instance);
        if (flash_handle == NULL)
        {
            ERROR("Invalid QSPI instance");
            return pdFAIL;
        }

        ret_val =
                cli_get_hex("qspi erase","address", param3, 0, 0x7FFFFFE, &targ_addr);
        if (ret_val != 0)
        {
            flash_close(flash_handle);
            return pdFAIL;
        }
        ret_val =
                cli_get_decimal("qspi erase","bytes", param4, 1, 0x7FFFFFF, &size);
        if (ret_val != 0)
        {
            flash_close(flash_handle);
            return pdFAIL;
        }
        erase_cnt = flash_erase_sectors(flash_handle, targ_addr, size);
        if (erase_cnt >= 0)
        {
            status = CLI_QSPI_OK;
            PRINT("Erase completed");
        }
        else
        {
            status = CLI_QSPI_FAIL;
            ERROR("Erase Failed");
        }

        flash_close(flash_handle);
        osal_delay_ms(10);

    }
    else if (strcmp(temp_str, WRITE_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nWrite data to qspi flash"
                    "\r\n\nUsage:"
                    "\r\n  qspi write <instance> <address> <data>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance  instance of the qspi flash device."
                    "\r\n  address   target memory address."
                    "\r\n  data      One or more 8 bit hexa decimal values separated by space."
                    "\r\n  NOTE:     Erase before write to avoid data corruption."
                    );

            return pdFALSE;
        }

        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);

        if ((param2 == NULL) || (param3 == NULL) || (param4 == NULL))
        {
            PRINT("Incorrect number of arguments for qspi write command.");
            PRINT("Please try 'qspi write help'");
            return pdFAIL;
        }

        ret_val =
                cli_get_decimal("qspi write","instance", param2, 0, 3, &instance);
        if (ret_val != 0)
        {
            return pdFAIL;
        }
        flash_handle = flash_open(instance);
        if (flash_handle == NULL)
        {
            ERROR("QSPI instance is busy");
            return pdFAIL;
        }
        ret_val =
                cli_get_hex("qspi write","address", param3, 0, 0x7FFFFFE, &targ_addr);
        if (ret_val != 0)
        {
            flash_close(flash_handle);
            return pdFAIL;
        }
        size = 0;
        idx = 4;
        memset(wrbuf, 0, sizeof(wrbuf));
        while (true)
        {
            param4 = FreeRTOS_CLIGetParameter(command_string, idx,
                    &param4_str_len);
            if (param4 == NULL)
            {
                break;
            }
            uint32_t writeVal;
            ret_val = cli_get_hex("qspi write","data", param4, 0, 255, &writeVal);
            if (ret_val != 0)
            {
                flash_close(flash_handle);
                return pdFAIL;
            }
            wrbuf[ size ] = (uint8_t)writeVal;
            size++;
            idx++;
        }
        cache_force_write_back((void*) wrbuf, (size));
        status = flash_write_sync(flash_handle, targ_addr, wrbuf, size);
        if (status != 0)
        {
            ERROR("Write Failed");
            flash_close(flash_handle);
            return pdFAIL;
        }

        flash_close(flash_handle);
        PRINT("Write Success");
    }
    else if (strcmp(temp_str, READ_CMD) == 0)
    {
        if (strncmp( param2, "help", 4 ) == 0)
        {
            printf("\r\nRead data from qspi flash"
                    "\r\n\nUsage:"
                    "\r\n  qspi read <instance> <address> <bytes>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance  instance of the qspi flash device."
                    "\r\n  address   target memory address."
                    "\r\n  bytes     number of bytes to be read. The argument should be a postive integer."
                    );

            return pdFALSE;
        }

        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len);
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len);

        if ((param2 == NULL) || (param3 == NULL) || (param4 == NULL))
        {
            PRINT("Incorrect number of arguments for qspi read command.");
            PRINT("Please try 'qspi read help' ");
            return pdFAIL;
        }
        ret_val =
                cli_get_decimal("qspi read","instance", param2, 0, 3, &instance);
        if (ret_val != 0)
        {
            return pdFAIL;
        }

        flash_handle = flash_open(instance);
        if (flash_handle == NULL)
        {
            ERROR("QSPI instance is busy");
            return pdFAIL;
        }
        ret_val =
                cli_get_hex("qspi read","address", param3, 0, 0x7FFFFFE, &targ_addr);
        if (ret_val != 0)
        {
            flash_close(flash_handle);
            return pdFAIL;
        }
        ret_val = cli_get_decimal("qspi read","bytes", param4, 1, 0x7FFFFFF, &size);
        if (ret_val != 0)
        {
            flash_close(flash_handle);
            return pdFAIL;
        }
        memset(rdbuf, 0, sizeof(rdbuf));
        cache_force_invalidate((void*) rdbuf, (size));
        status = flash_read_sync(flash_handle, targ_addr, rdbuf, (size));
        if (status != 0)
        {
            ERROR("Read Failed");
            flash_close(flash_handle);
            return pdFAIL;
        }
        cache_force_invalidate((void*) rdbuf, (size));

        flash_close(flash_handle);

        PRINT("%d bytes data in 0x%x: ", size, targ_addr);
        for (uint32_t i = 0; i < size; i++)
        {
            printf(" 0x%X", rdbuf[ i ]);
        }
    }
    else
    {
        PRINT("Invalid QSPI command.");
        PRINT("Enter 'qspi help' to see the list of available commands.");
        return pdFAIL;
    }
    /*For cli return pdFALSE for success*/
    if (ret == pdTRUE)
    {
        ret =  pdFALSE;
    }
    return ret;

}
