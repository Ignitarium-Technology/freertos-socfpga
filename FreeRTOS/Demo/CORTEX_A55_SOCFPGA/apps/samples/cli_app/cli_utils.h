/*
 * Common IO - basic V1.0.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 */

#ifndef __CLI_UTILS_H__
#define __CLI_UTILS_H__

#include <stdint.h>

/**
 * @file  cli_utils.h
 * @brief This file contains  definitions for cli
 *        argument validation functions
 */

/**
 * @brief Validate the decimal function argument for CLI.
 *
 * @param[in] cli command.
 * @param[in] Input parameter name.
 * @param[in] Input parameter.
 * @param[in] Lower boundary for argument.
 * @param[in] Upper boundary for argument.
 * @param[out] Pointer to value to be returned.
 *
 * @return
 * -  0         if operation succeeded.
 * - -1         if operation failed.
 */
int cli_get_decimal(const char *cmd, const char *param, const char *input,
        long lo_bound,long hi_bound, uint32_t *val);

/**
 * @brief Validate the hexa decimal function argument  for CLI.
 *
 * @param[in] cli command.
 * @param[in] Input parameter name.
 * @param[in] Input parameter.
 * @param[in] Lower boundary for argument.
 * @param[in] Upper boundary for argument.
 * @param[out] Pointer to value to be returned.
 *
 * @return
 * -  0         if operation succeeded.
 * - -1         if operation failed.
 */
int cli_get_hex(const char *cmd, const char *param, const char *input,
        long lo_bound,long hi_bound, uint32_t *val);

/**
 * @brief Validate file name length for  CLI.
 *
 * @param[in] string to be validated.
 * @param[in] Command which uses the string.
 *
 * @return
 * -  0         if operation succeeded.
 * - -1         if operation failed.
 */
int cli_get_file_name(const char *name, const char *command);

/**
 * @brief Validate directory  name length for  CLI.
 *
 * @param[in] string to be validated.
 * @param[in] Command which uses the string.
 *
 * @return
 * -  0         if operation succeeded.
 * - -1         if operation failed.
 */
int cli_get_dir_name(const char *name, const char *command);

/**
 * @brief To check if I2C instance is supported.
 *
 * @param[in] I2C instance to be validated
 *
 * @return
 * -  0         if instance is supported.
 * - -1         if instance is not supported.
 */
int cli_is_pinmux_i2c(uint8_t instance);

/**
 * @brief To check if IP is valid.
 *
 * @param[in] IP to be validated.
 *
 * @return
 * -  0         if IP is valid.
 * - -1         if IP is not valid.
 */
int cli_is_valid_ip(const char *ip);

#endif
