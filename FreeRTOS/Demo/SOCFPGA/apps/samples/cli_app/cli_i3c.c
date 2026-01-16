/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for I3C bus
 */

/**
 * @defgroup cli_i3c I3C
 * @ingroup cli
 *
 * Perform operations on I3C bus
 *
 * @details
 * It supports the following commands:
 * - i3c list
 * - i3c attach &lt;instance&gt; &lt;device_id&gt;
 * - i3c write &lt;instance&gt; &lt;device_id&gt; &lt;target_address&gt; &lt;data&gt;...
 * - i3c read  &lt;instance&gt; &lt;device_id&gt; &lt;target_address&gt; &lt;size&gt;
 * - i3c help
 *
 * Typical usage:
 * - Use 'i3c list' once to get the slave device IDs.
 * - Use 'i3c attach' to attach the desired slave to the I3C bus.
 * - Use 'i3c write' to perform data write operations.
 * - Use 'i3c read' to perform data read operations.
 *
 * @section i3c_commands Commands
 * @subsection i3c_list i3c list
 * List I3C slave devices  <br>
 *
 * Usage:  <br>
 *   i3c list  <br>
 *
 * No arguments.  <br>
 *
 * @subsection i3c_attach i3c attach
 * Attach slave to I3C bus  <br>
 *
 * Usage:  <br>
 *   i3c attach &lt;instance&gt; &lt;device_id&gt;  <br>
 *
 * It requires the following arguments:
 * - instance -     The instance of the I3C driver. Valid values are 0 and 1.  <br>
 * - device_id -    The ID of the slave device. Use `i3c list` to get the ID.  <br>
 *
 * @subsection i3c_write i3c write
 * Write data to a given memory location  <br>
 *
 * Usage:  <br>
 *   i3c write &lt;instance&gt; &lt;device_id&gt; &lt;target_address&gt; &lt;data&gt;...  <br>
 *
 * It requires the following arguments:
 * - instance -        The instance of the I3C driver. Valid values are 0 and 1.  <br>
 * - device_id -       The ID of the slave device. Use `i3c list` to get the ID.  <br>
 * - target_address -  The address of the memory location (hex 0x00–0x3FFFF).  <br>
 * - data -            One or more data bytes to write (hex 0x00–0xFF).  <br>
 *
 * @subsection i3c_read i3c read
 * Read data from a given memory location  <br>
 *
 * Usage:  <br>
 *   i3c read &lt;instance&gt; &lt;device_id&gt; &lt;target_address&gt; &lt;size&gt;  <br>
 *
 * It requires the following arguments:
 * - instance -        The instance of the I3C driver. Valid values are 0 and 1.  <br>
 * - device_id -       The ID of the slave device. Use `i3c list` to get the ID.  <br>
 * - target_address -  The address of the memory location (hex 0x00–0x3FFFF).  <br>
 * - size -            Number of bytes to read.  <br>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <socfpga_uart.h>
#include <FreeRTOS_CLI.h>
#include "cli_app.h"
#include "cli_utils.h"
#include "socfpga_i3c.h"

#define LIST_CMD             ("list")
#define ADD_I2C_CMD          ("add_i2c")
#define ADD_I3C_CMD          ("add_i3c")
#define READ_CMD             ("read")
#define WRITE_CMD            ("write")
#define INIT_CMD             ("init")
#define HELP_CMD             ("help")

#define CLI_I3C_FAIL         1

#define CTRL_1               0x10
#define CTRL_2               0x11
#define CTRL_3               0x12

#define DEV_ADDRESS          0
#define LPS27HHW_DEV_ID      0xB3
#define EEPROM_ADDRESS       0x50
#define EEPROM_START_ADDR    0x00
#define WHOAMI               0x0F
#define MAX_48BIT            ((1ULL << 48) - 1)

uint8_t i3c_wrbuf[100] = {0};
uint8_t i3c_rdbuf[100] = {0};
uint8_t xfer_data[100] = {0};
struct i3c_xfer_request xfer_cmd[2] = {0};
int num_dev = 0;
int initialized = 0;

struct i3c_i3c_device connected_devices[] =
{
    {
        .static_address = DEV_ADDRESS,
        .device_id = 0x0,
        .preferred_dynamic_address = 0
    },

    {
        .static_address = 0x0,
        .device_id = 0x0,
        .preferred_dynamic_address = 0
    },
};

struct i3c_dev_list dev_list = {0};

int is_48bit_unsigned_hex(const char *hex_str)
{
    char *end;
    unsigned long long val = strtoull(hex_str, &end, 0);

    if (*end != '\0')
    {
        return 0;
    }
    return val <= MAX_48BIT;
}

BaseType_t cmd_i3c( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void) write_buffer_len;
    (void) write_buffer;

    const char *param1;
    const char *param2;
    const char *param3;
    const char *param4;
    const char *param5;
    BaseType_t param1_str_len;
    BaseType_t param2_str_len;
    BaseType_t param3_str_len;
    BaseType_t param4_str_len;
    BaseType_t param5_str_len;

    char temp_str[8] = { 0 };
    char help_str[5] = { 0 };
    uint32_t instance;
    uint8_t targ_addr;
    uint32_t size = 0;
    uint32_t idx = 0;
    uint64_t dev_id = 0;
    uint16_t dynamic_addr = 0;
    int ret;

    dev_list.num_devices = 2;
    dev_list.list = connected_devices;

    param1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len);
    strncpy(temp_str, param1, param1_str_len);

    if (strcmp(temp_str, LIST_CMD) == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len);
        strncpy(temp_str, param2, param2_str_len);
        if (strcmp(temp_str, HELP_CMD) == 0)
        {
            printf("\rList the available slave devices."
                    "\r\n\nUsage:"
                    "\r\n  i3c list");
            return pdFALSE;
        }
        printf("I3C device list:\r\n");
        if ((dev_list.list[0].device_id == 0) &&
                (dev_list.list[1].static_address == 0))
        {
            printf("Devices not added");
            return pdFALSE;
        }
        if (dev_list.list[1].static_address != 0)
        {
            printf(" Legacy I2C Device %d: \r\n", 1);
            printf(
                    "\tDevice ID: 0x%lx\r\n\tStatic Address: 0x%x\r\n\tPreferred Dynamic Address: 0x%x\r\n",
                    (uint64_t)dev_list.list[1].device_id, dev_list.list[1].static_address,
                    dev_list.list[1].preferred_dynamic_address);
        }
        if ((dev_list.list[0].device_id != 0))
        {
            printf("I3C Device %d: \r\n", 0);
            printf(
                    "\tDevice ID: 0x%lx\r\n\tStatic Address: 0x%x\r\n\tPreferred Dynamic Address: 0x%x\r\n",
                    (uint64_t) dev_list.list[0].device_id, dev_list.list[0].static_address,
                    dev_list.list[0].preferred_dynamic_address);
        }
        return pdFALSE;
    }
    else if ((strcmp(temp_str, ADD_I2C_CMD)) == 0)
    {
        if (connected_devices[1].static_address != 0x0)
        {
            if (initialized == 1)
            {
                printf("\r\nBus is already initialized");
                return pdFAIL;
            }
        }
        if ((num_dev >= 1) && (connected_devices[1].static_address != 0x0))
        {
            printf(
                    "\r\nThe CLI supports maximun two devices(one I2C slave and one I3C slave"
                    "\r\nReplacing previously added I2C device\r\n");
            num_dev--;
        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); //static address

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, HELP_CMD) == 0)
        {
            printf("\rAdd I2C slave to I3C bus"
                    "\r\n\nUsage:"
                    "\r\n  i3c add_i2c <address>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  address     The static address of the I2C device in hex.");
            return pdFALSE;
        }
        else if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect number of arguments."
                    "\r\nEnter 'i3c add_i2c help' for more information.");
            return pdFAIL;
        }
        uint32_t addr;
        ret = cli_get_hex("i3c add_i2c","address", param2, 0, 0x7F, &addr);
        if (ret !=  0)
        {
            return pdFAIL;
        }
        connected_devices[1].static_address = (uint8_t)addr;
        num_dev++;
        printf ("\r\nAdded the I2C device");
    }
    else if ((strcmp(temp_str, ADD_I3C_CMD)) == 0)
    {
        if (connected_devices[0].device_id != 0x0)
        {
            if (initialized == 1)
            {
                printf("\r\nBus is already initialized");
                return pdFAIL;
            }
        }
        if ((num_dev >= 1) && (connected_devices[0].device_id != 0x0))
        {
            printf(
                    "\r\nThe CLI supports maximun two devices(one I2C slave and one I3C slave"
                    "\r\nRemoving previously added I3C device\r\n");
            num_dev--;

        }
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); //device_id

        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, HELP_CMD) == 0)
        {
            printf("\rAdd I3C slave to I3C bus"
                    "\r\n\nUsage:"
                    "\r\n  i3c add_i3c <device_id>"
                    "\r\n\nIt requires The following arguments:"
                    "\r\n  device_id    48 bit provisional id in hex format");
            return pdFALSE;
        }
        else if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect number of arguments."
                    "\r\nEnter 'i3c add_i3c help' for more information.");
            return pdFAIL;
        }
        int64_t id = strtol(param2, NULL, 16);
        if (id < 0)
        {
            printf("\r\nERROR: Invalid device id"
                    "\r\nEnter 'i3c add_i3c  help' for more information.");
            return pdFAIL;
        }
        ret = is_48bit_unsigned_hex(param2);
        if (ret == 0)
        {
            printf("\r\nERROR: Invalid device id"
                    "\r\n Enter 'i3c add_i3c  help' for more information.");
            return pdFAIL;
        }
        connected_devices[0].device_id = strtol(param2, NULL, 16);
        num_dev++;
        printf ("\r\nAdded the I3C device");
    }
    else if (strcmp(temp_str, INIT_CMD) == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); //instance
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len); //devID

        if (num_dev == 0)
        {
            printf(
                    "No devices added to the I3C bus. Use add_i3c or add_i2c to add devices");
            return pdFAIL;
        }
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, HELP_CMD) == 0)
        {
            printf("\rAttach slave to I3C bus"
                    "\r\n\nUsage:"
                    "\r\n  i3c init <instance>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance     The instance of the I3C driver. Valid values are 0 and 1.");
            return pdFALSE;
        }
        else if (param2 == NULL)
        {
            printf("\r\nERROR: Incorrect number of arguments."
                    "\r\nEnter 'i3c init help' for more information.");
            return pdFAIL;
        }
        ret =  cli_get_decimal("i3c init","instance", param2, 0, 1, &instance);
        if (ret != 0)
        {
            return pdFAIL;
        }
        if (i3c_open(instance) != 0)
        {
            printf("\r\nI3C instance not initialized");
            return pdFAIL;
        }

        if (i3c_ioctl(instance, I3C_IOCTL_TARGET_ATTACH, &dev_list) != 0)
        {
            printf("\r\nI3C Target not attached");
            return pdFAIL;
        }

        if (i3c_ioctl(instance, I3C_IOCTL_BUS_INIT, &connected_devices[0]) != 0)
        {
            printf("\r\nDynamic address not assigned to devices");
            return pdFAIL;
        }
        initialized = 1;
        printf ("\r\nInitialized the I3C bus");
        return pdFALSE;
    }
    else if (strcmp(temp_str, WRITE_CMD) == 0)
    {

        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); //instance
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len); //devID
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len); //target address
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, HELP_CMD) == 0)
        {
            printf("\rWrite data to a given memory location"
                    "\r\n\nUsage:"
                    "\r\n  i3c write <instance> <device_id> <target_address> <data>..."
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance          The instance of the I3C driver. Valid values are 0 and 1."
                    "\r\n  device_id         The ID of the slave device. Use list command to get device ID."
                    "\r\n  target_address    The address of the memory location. It is a hexadecimal value from 0x00 to 0x3FFFF."
                    "\r\n  data              Data written to the memory. User can provide multiple values. Valid data range is from 0x00 to 0xFF.");
            return pdFALSE;
        }
        if (initialized == 0)
        {
            printf("\r\nI3C bus not initilazed. Use i3c init before read/write");
            return pdFAIL;
        }
        else if ((param2 == NULL) || (param3 == NULL) || (param4 == NULL))
        {
            printf("\r\nIncorrect number of arguments."
                    "\r\nEnter 'i3c write help' for more information.");
            return pdFAIL;
        }
        ret =  cli_get_decimal("i3c write","instance", param2, 0, 1, &instance);
        if (ret != 0)
        {
            return pdFAIL;
        }
        dev_id = strtol(param3, NULL, 16);
        uint32_t addr;
        ret = cli_get_hex("i3c write","target_address", param4, 0, 0x3FFFE, &addr);
        if (ret !=  0)
        {
            return pdFAIL;
        }
        targ_addr = (uint8_t)addr;
        idx = 5;
        while (true)
        {
            param5 = FreeRTOS_CLIGetParameter(command_string, idx,
                    &param5_str_len);
            if (param5 == NULL)
            {
                break;
            }
            uint32_t write_val;
            ret = cli_get_hex("i3c write","data", param5, 0, 255, &write_val);
            if (ret != 0)
            {
                return pdFAIL;
            }
            i3c_wrbuf[size] = (uint8_t)write_val;
            size++;
            idx++;
        }
        if (dev_id == 0)
        {
            /* Legacy I2C */
            xfer_data[0] = (targ_addr >> 8) & 0xFF;
            xfer_data[1] = targ_addr & 0xFF;
            for (uint32_t i = 0; i < size; i++)
            {
                xfer_data[2 + i] = i3c_wrbuf[i];
            }
            xfer_cmd[0].buffer = xfer_data;
            xfer_cmd[0].length = size + 2;
            xfer_cmd[0].read = false;
            if (i3c_transfer_sync(instance, EEPROM_ADDRESS, &xfer_cmd[0], 1,
                    true) != 0)
            {
                printf("\r\nWrite failed. Make sure the device is attached.");
                return pdFAIL;
            }
        }
        else
        {
            /* I3C device */
            for (int i = 0; i < dev_list.num_devices; i++)
            {
                if (dev_list.list[i].device_id == dev_id)
                {
                    dynamic_addr = dev_list.list[i].dynamic_address;
                    break;
                }
            }
            if (dynamic_addr == 0)
            {
                printf("\r\nDevice not found");
                return pdFAIL;
            }

            xfer_data[0] = targ_addr;
            for (idx = 0; idx < size; idx++)
            {
                xfer_data[1 + idx] = i3c_wrbuf[idx];
            }
            xfer_cmd[0].buffer = xfer_data;
            xfer_cmd[0].length = size + 1;
            xfer_cmd[0].read = 0;

            if (i3c_transfer_sync(instance, dynamic_addr, &xfer_cmd[0], 1,
                    false) != 0)
            {
                printf("\r\nWrite failed. Make sure the device is attached.");
                return pdFAIL;
            }
        }
        printf("\r\nWrite successful");
        return pdFALSE;
    }

    else if (strcmp(temp_str, READ_CMD) == 0)
    {
        param2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); //instance
        param3 = FreeRTOS_CLIGetParameter(command_string, 3, &param3_str_len); //devID
        param4 = FreeRTOS_CLIGetParameter(command_string, 4, &param4_str_len); //target address
        param5 = FreeRTOS_CLIGetParameter(command_string, 5, &param5_str_len); //size
        strncpy(help_str, param2, param2_str_len);
        if (strcmp(help_str, HELP_CMD) == 0)
        {
            printf("\rRead data from a given memory location"
                    "\r\n\nUsage:"
                    "\r\n  i3c read <instance> <device_id> <target_address> <size>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  instance          The instance of the I3C driver. Valid values are 0 and 1."
                    "\r\n  device_id         The ID of the slave device. Use list command to get device ID."
                    "\r\n  target_address    The address of the memory location. It is a hexadecimal value from 0x00 to 0x3FFFF."
                    "\r\n  size              Number of bytes to read.");
            return pdFALSE;
        }
        if (initialized == 0)
        {
            printf("\r\nI3C bus not initilazed. Use i3c init before read/write");
            return pdFAIL;
        }
        else if ((param2 == NULL) || (param3 == NULL) ||
                (param4 == NULL) || (param5 == NULL))
        {
            printf("\r\nIncorrect number of arguments"
                    "\r\nEnter 'i3c read help' for more information.");
            return pdFAIL;
        }
        ret =  cli_get_decimal("i3c read","instance", param2, 0, 1, &instance);
        if (ret != 0)
        {
            return pdFAIL;
        }
        int64_t id = strtol(param3, NULL, 16);
        if (id < 0)
        {
            printf("\r\nInvalid device id"
                    "\r\nEnter 'i3c read help' for more information.");
            return pdFAIL;

        }
        dev_id = strtol(param3, NULL, 16);
        ret =  cli_get_decimal("i3c read","size", param5, 1, 64, &size);
        if (ret != 0)
        {
            return pdFAIL;
        }
        uint32_t addr;
        ret = cli_get_hex("i3c read","target_address", param4, 0, 0x3FFFF, &addr);
        if (ret != 0)
        {
            return pdFAIL;
        }
        targ_addr = (uint8_t)addr;
        if (dev_id == 0)
        {
            /* Legacy I2C */
            xfer_data[0] = (targ_addr >> 8) & 0xFF;
            xfer_data[1] = targ_addr & 0xFF;

            xfer_cmd[0].buffer = xfer_data;
            xfer_cmd[0].length = 2;
            xfer_cmd[0].read = false;

            xfer_cmd[1].buffer = i3c_rdbuf;
            xfer_cmd[1].length = size;
            xfer_cmd[1].read = true;

            if (i3c_transfer_sync(instance, EEPROM_ADDRESS, xfer_cmd, 2,
                    true) != 0)
            {
                printf("\r\nRead failed. Make sure the device is attached.");
                return pdFAIL;
            }
        }
        else
        {
            /* I3C device */
            int lRet = i3c_ioctl(instance, I3C_IOCTL_GET_DYNADDRESS,
                    &connected_devices[ 0 ]);
            if (lRet != 0)
            {
                printf("\r\nFailed to get the dynamic address");
                return pdFAIL;
            }
            for (int i = 0; i < dev_list.num_devices; i++)
            {
                if (dev_list.list[i].device_id == dev_id)
                {
                    dynamic_addr = dev_list.list[i].dynamic_address;
                    break;
                }
            }
            if (dynamic_addr == 0)
            {
                printf("\r\nDevice not found");
                return pdFAIL;
            }

            xfer_cmd[0].buffer = &targ_addr;
            xfer_cmd[0].length = sizeof(targ_addr);
            xfer_cmd[0].read = 0;

            memset(i3c_rdbuf, 0, size);
            xfer_cmd[1].buffer = i3c_rdbuf;
            xfer_cmd[1].length = size;
            xfer_cmd[1].read = 1;

            if (i3c_transfer_sync(instance, dynamic_addr, xfer_cmd, 2, false) != 0)
            {
                printf("\r\nRead failed. Make sure the device is attached.");
                return pdFAIL;
            }
        }
        printf("\r\n%d bytes data at 0x%x: \n\r", size, targ_addr);
        for (uint32_t i = 0; i < size; i++)
        {
            printf(" 0x%x", i3c_rdbuf[i]);
        }
        return pdFALSE;
    }

    else if (strcmp(temp_str, HELP_CMD) == 0)
    {
        printf("\rPerform operations on I3C bus(CLI supports a maximum of one i2c device and a i3c device )"
                "\r\n\nIt supports the following commands:"
                "\r\n  i3c add_i2c <device_address>"
                "\r\n  i3c add_i3c <device_id>"
                "\r\n  i3c init <instance>"
                "\r\n  i3c list"
                "\r\n  i3c write <instance> <device_id> <target_address> <data>..."
                "\r\n  i3c read <instance> <device_id> <target_address> <size>"
                "\r\n  i3c help"
                "\r\n\nTypical usage:"
                "\r\n- Use add_i2c command once to add I2C slave."
                "\r\n- Use add_i3c command once to add I3C slave."
                "\r\n- Use init command once to initialiaze to I3C bus."
                "\r\n- Use list command once to get the slave device ID."
                "\r\n- Use write/read command to perform desired write/read operations");
        return pdFALSE;
    }
    else
    {
        printf("\r\nERROR: Invalid command for i3c");
        printf("\r\nEnter 'i3c help' for more information.");
        return pdFAIL;
    }
    return pdFALSE;
}
