/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI argument validation functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "osal_log.h"
#include "socfpga_defines.h"

/*@brief Maximum number of supported instances for I2C*/
#define MAX_I2C_NUM_INST    5

/*@brief Maximum number of pinmux that can configured as I2C SDA*/
#define MAX_I2C_SDA_PINS    3

/*@brief Maximum number of pinmux that can configured as I2C SCL*/
#define MAX_I2C_SCL_PINS    3

/*@brief Table of pinmux that can be configured as SDA for each instance
 *     I2C0         - [pin4sel, pin22sel, pin26sel]
 *     I2C1         - [pin2sel, pin20sel, pin36sel]
 *     I2C2_EMAC0   - [pin8sel, pin34sel, pin46sel]
 *     I2C2_EMAC1   - [pin8sel, pin42sel, pin8sel ]
 *     I2C2_EMAC2   - [pin6sel, pin32sel, pin44sel]
 */
const uint32_t i2c_sda_pins[MAX_I2C_NUM_INST][MAX_I2C_SDA_PINS] =
{
    {0x10D13010, 0x10D13058, 0x10D13068},
    {0x10D13008, 0x10D13050, 0x10D13090},
    {0x10D13028, 0x10D13088, 0x10D13118},
    {0x10D13020, 0x10D13108, 0x10D13020},
    {0x10D13018, 0x10D13080, 0x10D13110}
};

/*@brief Table of pinmux that can be configured as SCL for each instance
 *     I2C0         - [pin4sel, pin23sel, pin27sel]
 *     I2C1         - [pin3sel, pin21sel, pin37sel]
 *     I2C2_EMAC0   - [pin9sel, pin35sel, pin47sel]
 *     I2C2_EMAC1   - [pin9sel, pin43sel, pin9sel ]
 *     I2C2_EMAC2   - [pin7sel, pin33sel, pin44sel]
 */
const uint32_t i2c_scl_pins[MAX_I2C_NUM_INST][MAX_I2C_SCL_PINS] =
{
    {0x10D13014, 0x10D1305C, 0x10D1306C},
    {0x10D1300C, 0x10D13054, 0x10D13094},
    {0x10D1302C, 0x10D1308C, 0x10D1311C},
    {0x10D13024, 0x10D1310C, 0x10D1310C},
    {0x10D1301C, 0x10D13084, 0x10D13114}
};

/*@brief Table of states for a pimux to be configured as a SCL/SDA
 */
const uint8_t i2c_mux_sel[MAX_I2C_NUM_INST][MAX_I2C_SDA_PINS] =
{
    {4, 4, 4},
    {4, 4, 4},
    {4, 4, 4},
    {4, 4, 4},
    {4, 4, 4}
};

/**
 * @brief Get the decimal value from the cli command and validate it.
 */
int cli_get_decimal(const char *cmd, const char *param, const char *input,
        long int lo_bound,long int hi_bound, uint32_t *val)
{
    char   *endptr = NULL;
    long parsed;
    int err = 0;

    parsed = strtoul(input, &endptr, 10);
    if (*endptr != '\0')
    {
        if (*endptr != ' ')
        {
            err = 1;
        }
    }
    if (err == 0)
    {
        if ((parsed < lo_bound) || (parsed > hi_bound))
        {
            err = 1;
        }
    }
    if (err > 0)
    {
        ERROR(
                "Invalid value for parameter = %s;"
                "\r\nIt shall be a valid decimal between %ld and %ld"
                "\r\nPlease try '%s help'.",
                param, lo_bound, hi_bound, cmd);
        return -1;
    }
    *val = (uint32_t) parsed;
    return 0;
}

/**
 * @brief Get the hexa decimal value from the cli command and validate it.
 */
int cli_get_hex(const char  *cmd, const char  *param, const char  *input,
        long int lo_bound, long int hi_bound, uint32_t *val)
{
    char *endptr = NULL;
    long parsed;
    int err = 0;

    parsed = strtoul(input, &endptr, 16);

    if (*endptr != '\0')
    {
        if (*endptr != ' ')
        {
            err = 1;
        }
    }
    if (err == 0)
    {
        if ((parsed < lo_bound) || (parsed > hi_bound))
        {
            err = 1;
        }
    }
    if (err > 0)
    {
        ERROR(
                "Invalid value for parameter = %s;"
                "\r\nIt shall be a valid hexadecimal between 0x%lX and 0x%lX"
                "\r\nPlease try '%s help'.",
                param, lo_bound, hi_bound, cmd);
        return -1;

    }
    *val = (uint32_t)parsed;
    return 0;
}


/**
 * @brief Get the file name for FAT cli and check if it is valid.
 */
int cli_get_file_name(const char *name, const char *command)
{
    char cmpBuf[14];
    char *file_name = strrchr(name, '/');
    int err = 0;
    char *ext = NULL;

    file_name = file_name + 1;
    int len = strlen(file_name);
    if (len > 12)
    {
        err = 1;
    }
    if (err == 0)
    {
        strcpy(cmpBuf, file_name);
        ext = strrchr(file_name, '.');
        if ((ext == file_name) || (*(ext + 1) == '\0'))
        {
            ERROR("File name should not end or start with '.' ");
            return -1;
        }

        if (ext != NULL)
        {
            size_t name_len = (size_t)(ext - file_name);
            size_t ext_len = strlen(ext + 1);
            if ((name_len > 8) || (ext_len > 3))
            {
                err = 1;
            }
        }
        if ((ext == NULL) && (strlen(file_name ) > 8))
        {
            err = 1;
        }
    }
    if (err == 1)
    {
        ERROR("Invalid file name."
                "\r\nThe FAT file system supports LFN 8.3 format, ie 8 characters for"
                "\r\nfilename and 3 charaters for extension."
                "\r\nPlease try '%s help' ",
                command);
        return -1;
    }
    return 0;
}

/**
 * @brief Get the directory name for FAT cli and check if it is valid.
 */
int cli_get_dir_name(const char *name, const char *command)
{
    char *dir_name = strrchr(name, '/');
    int len = strlen(dir_name + 1);

    if (len > 8)
    {
        ERROR("Invalid directory name."
                "\r\nThe FAT  file system only support"
                "\r\n8 characters for directory name"
                "\r\nPlease try '%s help' ", command);
        return -1;
    }
    return 0;
}

/**
 * @brief Get the state of the pinmux
 */
uint8_t pinmux_get_sel(uint32_t pin_reg)
{
    uint32_t val;
    uint8_t pinVal;

    val = RD_REG32(pin_reg);
    pinVal = (uint8_t)(val &  0xF);
    return pinVal;
}

/**
 * @brief Check if I2C instance is supported in hardware.
 */
int cli_is_pinmux_i2c(uint8_t instance)
{
    /*Iterate throught all the pinmuxes that can
     * be configured as SCL and SDA for the instance
     * and compare with the values in the LUT to check
     * if the i2c instance is supported in hardware.
     */
    for (int i = 0; i < MAX_I2C_SDA_PINS; i++)
    {
        uint32_t sda_reg = i2c_sda_pins[instance][i];
        uint32_t scl_reg = i2c_scl_pins[instance][i];
        uint8_t sel = i2c_mux_sel[instance][i];

        if ((pinmux_get_sel(sda_reg) == sel) &&
                (pinmux_get_sel(scl_reg) == sel))
        {
            return 0;
        }
    }
    ERROR("Instance not supported in current image.");
    return -1;
}

/**
 * @brief Check if IP is valid.
 */
int cli_is_valid_ip(const char *ip)
{
    int num, dots = 0;
    const char *ptr = ip;
    char *endptr;
    int err = 0;

    if (ip == NULL)
    {
        return -1;
    }
    while (*ptr)
    {
        if (isdigit((unsigned char)*ptr) == 0)
        {
            return -1;
        }
        num = strtol(ptr, &endptr, 10);
        if ((num < 0) || (num > 255))
        {
            return -1;
        }
        if ((endptr - ptr > 1) && (*ptr == '0'))
        {
            return -1;
        }

        ptr = endptr;
        if (*ptr == '.')
        {
            dots++;
            ptr++;
            if (*ptr == '\0')
            {
                return -1;
            }
        }
        else if (*ptr != '\0')
        {
            return 0;
        }
    }
    if (dots != 3)
    {
        err = -1;
        PRINT("Invalid IP address");
    }
    return err;
}
