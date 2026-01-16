/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for CLI application
 */


#ifndef __CLI_APP_H__
#define __CLI_APP_H__

BaseType_t cmd_wdt( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
BaseType_t cmd_gpio( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
BaseType_t cmd_timer( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
BaseType_t cmd_i2c( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
BaseType_t cmd_eth( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
BaseType_t cmd_reboot( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );

void cli_task( void *params );
void cli_demo();
BaseType_t cmd_qspi( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t cmd_i3c( char * pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
BaseType_t cmd_spi(char *pcWriteBuffer, size_t xWriteBufferLen,const char *pcCommandString);
BaseType_t cmd_fpga_manager( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t cmd_bridge( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t fat_ops( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t cmd_fcs(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t cmd_rsu(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t cmd_ros(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);

#endif
