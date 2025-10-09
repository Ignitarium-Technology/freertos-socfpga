/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for I2C bus
 */

/**
 * @defgroup cli_i2c I2C
 * @ingroup cli
 *
 * Perform I2C operations
 *
 * @details
 * It supports the following subcommands:
 * - i2c read &lt;instance&gt; &lt;target_address&gt; &lt;register_address&gt;
 * - i2c write &lt;instance&gt; &lt;target_address&gt; &lt;register_address&gt; &lt;data&gt;
 * - i2c help
 *
 * Typical usage:
 * - Use 'i2c read' command to perform write operations on an I2C device.
 * - Use 'i2c write' command to perform write operations on an I2C device.
 *
 * @section i2c_commands Commands
 * @subsection i2c_read i2c read
 * Read one byte of data from an I2C device <br>
 *
 * Usage: <br>
 * i2c read &lt;instance&gt; &lt;target_address&gt; &lt;register_address&gt; <br>
 *
 * It requires the following arguments:
 * - instance - The instance of the I2C bus. Valid range is 0 to 4. <br>
 * - target_address - The address of the I2C slave. Supports 7-bit address in hexadecimal format (e.g., 0x50). <br>
 * - register_address - The register address to read from. Hex value in the range 0x0000 to 0x3FFF. <br>
 *
 * @subsection i2c_write i2c write
 * Write a single byte of data to an I2C device <br>
 *
 * Usage: <br>
 * i2c write &lt;instance&gt; &lt;target_address&gt; &lt;register_address&gt; &lt;data&gt; <br>
 *
 * It requires the following arguments:
 * - instance - The instance of the I2C bus. Valid range is 0 to 4. <br>
 * - target_address - The address of the I2C slave. Supports 7-bit address in hexadecimal format (e.g., 0x50). <br>
 * - register_address - The register address to write to. Hex value in the range 0x0000 to 0x3FFF. <br>
 * - data - The data byte to write. Valid range is 0x00 to 0xFF. <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include "semphr.h"
#include <socfpga_uart.h>
#include <socfpga_timer.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "socfpga_i2c.h"
#include "cli_utils.h"
#include "osal_log.h"

BaseType_t cmd_i2c( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void)write_buffer_len;
    const char *parameter1;
    const char *parameter2;
    const char *parameter3;
    const char *parameter4;
    const char *parameter5;
    char temp_string[ 6 ] = { 0 };
    const char *read_cmd = "read";
    const char *write_cmd = "write";
    uint32_t data = 0;
    uint32_t i2c_inst;
    i2c_handle_t i2c_hdl;
    uint32_t slave_id;
    uint32_t reg_addr;
    uint8_t wbuf[3];
    uint8_t rbuf;
    int ret;
    i2c_config_t config;
    BaseType_t parameter1_str_len;
    BaseType_t parameter2_str_len;
    BaseType_t parameter3_str_len;
    BaseType_t parameter4_str_len;
    BaseType_t parameter5_str_len;

    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1,
            &parameter1_str_len);
    strncpy(temp_string, parameter1, parameter1_str_len);

    if (strncmp(temp_string, "help", 4) == 0)
    {
        printf("\rPerform i2c operations"
                "\r\n\nIt supports the following subcommands:"
                "\r\n  i2c read  <instance> <target_address> <register_address>"
                "\r\n  i2c write <instance> <target_address> <register_address> <value>"
                "\r\n  i2c help"
                "\r\n\nTypical usage:"
                "\r\n- Use read/write command to perform write/read operations on i2c device."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  i2c <command> help\r\n");

        return pdFALSE;
    }
    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
            &parameter2_str_len);
    if (strcmp(temp_string, read_cmd) == 0)
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\r\nRead one byte of data from an i2c device."
                    "\r\n\nUsage:"
                    "\r\n  i2c read  <instance> <target_address> <register_address>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance            The instance of the I2C bus. Valid range is 0 to 4."
                    "\r\n  target_address      The address of I2C slave.Supports 7 bit address in hexadecimal format. Example: 0x50."
                    "\r\n  register_address    The register address to read data. It is a hexadecimal value in the range 0x0000 to 0x3FFF.");
            return pdFALSE;
        }

        parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                &parameter3_str_len);
        parameter4 = FreeRTOS_CLIGetParameter(command_string, 4,
                &parameter4_str_len);
        if ((parameter2 == NULL) || (parameter3 == NULL) ||
                (parameter4 == NULL))
        {
            ERROR("Incorrect Number of arguments for i2c read command");
            printf("\r\nEnter 'help' to view a list of available commands.");
            return pdFALSE;
        }
        ret = cli_get_decimal("i2c read","instance", parameter2, 0, 4,
                &i2c_inst);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_is_pinmux_i2c(i2c_inst);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_get_hex("i2c read", "target_address", parameter3, 0x0,
                0x7F, &slave_id);
        if (ret != 0)
        {
            return pdFAIL;
        }
        i2c_hdl = i2c_open(i2c_inst);
        if (i2c_hdl == NULL)
        {
            ERROR("I2C Bus already in use");
            return pdFALSE;
        }
        config.clk = I2C_STANDARD_MODE_BPS;
        i2c_ioctl(i2c_hdl, I2C_SET_MASTER_CFG, &config);
        i2c_ioctl(i2c_hdl, I2C_SET_SLAVE_ADDR, (uint16_t *)&slave_id);
        ret = cli_get_hex("i2c read", "register_address", parameter4, 0x0,
                0x3FFF, &reg_addr);
        if (ret != 0)
        {
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        wbuf[ 0 ] = (uint8_t) (((uint16_t)reg_addr >> 8) & 0xFF);
        wbuf[ 1 ] = (uint8_t) ((uint16_t)reg_addr & 0xFF);
        if (i2c_write_sync(i2c_hdl, wbuf, 2) != 0)
        {
            printf("Read failed. \n\r");
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        if (i2c_read_sync(i2c_hdl, &rbuf, 1) != 0)
        {
            printf("Read failed \n\r");
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        i2c_close(i2c_hdl);
        printf("Data in 0x%x is 0x%x \n\r", reg_addr, rbuf);
    }
    else if (strcmp(temp_string, write_cmd) == 0)
    {
        if (strncmp(parameter2, "help", 4) == 0)
        {
            printf("\r\nWrite a single byte data to an i2c device"
                    "\r\n\nUsage:"
                    "\r\n  i2c write  <instance> <target_address> <register_address> <data>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance            The instance of the I2C bus. Valid range is 0 to 4."
                    "\r\n  target_address      The address of I2C slave. Supports 7 bit address in hexadecimal format. Example: 0x50."
                    "\r\n  register_address    The register address to read data. Valid address range is 0x0000 to 0x3FFF."
                    "\r\n  data                The data to be written to the device. It is a hexadecimal value in the range 0x00 to 0xFF."
                    );
            return pdFALSE;
        }

        parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                &parameter3_str_len);
        parameter4 = FreeRTOS_CLIGetParameter(command_string, 4,
                &parameter4_str_len);
        parameter5 = FreeRTOS_CLIGetParameter(command_string, 5,
                &parameter5_str_len);
        if ((parameter2 == NULL) || (parameter3 == NULL) ||
                (parameter4 == NULL) || (parameter5 == NULL))
        {
            ERROR("Incorrect Number of arguments for i2c write command");
            printf("\r\nEnter 'help' to view a list of available commands.");
            return pdFALSE;
        }
        ret = cli_get_decimal("i2c write","instance", parameter2, 0, 4,
                &i2c_inst);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_is_pinmux_i2c(i2c_inst);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_get_hex("i2c write", "target_address", parameter3, 0x0,
                0x7F, &slave_id);
        if (ret != 0)
        {
            return pdFAIL;
        }
        i2c_hdl = i2c_open(i2c_inst);
        if (i2c_hdl == NULL)
        {
            ERROR("I2C Bus already in use");
            return pdFALSE;
        }
        config.clk = I2C_STANDARD_MODE_BPS;
        i2c_ioctl(i2c_hdl, I2C_SET_MASTER_CFG, &config);
        i2c_ioctl(i2c_hdl, I2C_SET_SLAVE_ADDR, (uint16_t *)&slave_id);
        ret = cli_get_hex("i2c write", "register_address", parameter4, 0x0,
                0x3FFF, &reg_addr);
        if (ret != 0)
        {
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        ret =
                cli_get_hex("i2c write", "data", parameter5, 0x0, 0xFF,
                &data);
        if (ret != 0)
        {
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        wbuf[ 0 ] = (uint8_t) (((uint16_t)reg_addr >> 8) & 0xFF);
        wbuf[ 1 ] = (uint8_t) ((uint16_t)reg_addr & 0xFF);
        wbuf[ 2 ]  = (uint8_t) data;
        if (i2c_write_sync(i2c_hdl, wbuf, 3) != 0)
        {
            printf("Write failed \n\r");
            i2c_close(i2c_hdl);
            return pdFAIL;
        }
        i2c_close(i2c_hdl);
        printf("Write completed\n\r");
    }
    else
    {
        strncpy(write_buffer, "Invalid I2C command",
                strlen("Invalid I2C command "));
        return pdFAIL;
    }
    return pdFALSE;
}
