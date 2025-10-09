/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for console driver
 */


#ifndef __SOCFPGA_CONSOLE_H__
#define __SOCFPGA_CONSOLE_H__

#include <errno.h>

/* ***
 * @brief Initialise the console for system prints
 *
 * @param id : Uart ID to use
 * @param configString : uart configuration to use
 *          Should be of format <baudrate>-<bit len><parity><number of stop bit>
 *          Eg: 115200-8N1
 * */
int console_init(int id, const char *config_str);
int console_write(unsigned char *const buffer, int length);
int console_read(unsigned char *const buffer, int length);
void console_clear_pending();
int console_deinit();

#endif /* __SOCFPGA_CONSOLE_H__ */
