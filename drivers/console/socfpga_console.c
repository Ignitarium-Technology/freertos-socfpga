/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Console driver implementation using UART driver
 */

#include <stdio.h>
#include <socfpga_uart.h>
#include "socfpga_console.h"
#include "osal.h"

#define RETRY_MAX_COUNT    10

#define MAX_PIPE_SIZE        4096
#define MAX_INT_BUFF_SIZE    128

static osal_mutex_t buffer_mutex;
static osal_mutex_def_t buffer_mutex_mem;
static osal_pipe_t buffer_pipe;
static uint8_t intermediate_buffer[MAX_INT_BUFF_SIZE];
uart_handle_t hconsole_uart = NULL;
uart_config_t console_config;

int console_init(int id, const char *config_str)
{
    int ret = 0;
    int baudrate;
    int word_length;
    char parity;
    int num_stop_bits;

    /* example: 115200-8N1 */
    if (sscanf(config_str, "%d-%d%c%d", &baudrate, &word_length, &parity, &num_stop_bits) < 4)
    {
        ret = -EINVAL;
    }
    else
    {
        hconsole_uart = uart_open(id);
        if (hconsole_uart == NULL)
        {
            ret = -EBUSY;
        }


        console_config.baud = baudrate;
        /* Set word length (default value is 8) */
        switch (word_length) {
            case 5:
                console_config.wlen = 5;
                break;
            case 6:
                console_config.wlen = 6;
                break;
            case 7:
                console_config.wlen = 7;
                break;
            case 8:
                console_config.wlen = 8;
                break;
            default:
                console_config.wlen = 8;
                break;
        }
        /* Set parity (default is None) */
        switch (parity) {
            case 'n':
            case 'N':
                console_config.parity = UART_PARITY_NONE;
                break;
            case 'o':
            case 'O':
                console_config.parity = UART_PARITY_ODD;
                break;
            case 'e':
            case 'E':
                console_config.parity = UART_PARITY_EVEN;
                break;
            default:
                console_config.parity = UART_PARITY_NONE;
                break;
        }
        if (num_stop_bits > 1)
        {
            console_config.stop_bits = UART_STOP_BITS_1;
        }
        else
        {
            console_config.stop_bits = UART_STOP_BITS_2;
        }

        ret = uart_ioctl(hconsole_uart, UART_SET_CONFIG, &console_config);
    }

    if (ret == 0)
    {
        buffer_mutex = osal_mutex_create(&buffer_mutex_mem);
        buffer_pipe = osal_pipe_create(MAX_PIPE_SIZE);
    }

    return ret;
}

int console_write(unsigned char *const buffer, int length)
{
    int ret;
    uint32_t num_bytesin_pipe = 0;
    int32_t console_state;

    if (osal_get_kernel_state() == OSAL_KERNEL_NOT_RUNNING)
    {
        return 0;
    }


    ret = uart_ioctl(hconsole_uart, UART_GET_TX_STATE, &console_state);
    if (console_state == -EBUSY)
    {
        if (osal_mutex_lock(buffer_mutex, 0xFFFFFFFFU))
        {
            osal_pipe_send(buffer_pipe, buffer, length);
            osal_mutex_unlock(buffer_mutex);
        }
        return 0;
    }

    if (!xPortIsInsideInterrupt())
    {
        if (osal_mutex_lock(buffer_mutex, 0xFFFFFFFFU))
        {
            num_bytesin_pipe = osal_pipe_bytes_available(buffer_pipe);
            osal_mutex_unlock(buffer_mutex);
        }
        if (num_bytesin_pipe > 0)
        {
            int bytes_read = 0;
            do {
                if (osal_mutex_lock(buffer_mutex, 0xFFFFFFFFU))
                {
                    bytes_read = osal_pipe_receive(buffer_pipe, intermediate_buffer,
                            MAX_INT_BUFF_SIZE);
                    osal_mutex_unlock(buffer_mutex);
                }
                ret = uart_write_sync(hconsole_uart, intermediate_buffer, bytes_read);
            } while(bytes_read);
        }

        ret = uart_write_sync(hconsole_uart, buffer, length);
    }
    else
    {
        ret = uart_write_async(hconsole_uart, buffer, length);
    }
    return ret;
}

void console_clear_pending()
{
    int32_t console_state;
    uint32_t num_bytesin_pipe;

    num_bytesin_pipe = osal_pipe_bytes_available(buffer_pipe);
    if (num_bytesin_pipe > 0)
    {
        int bytes_read = 0;
        do {
            /* Check if lock could be acquired.
             * Use non blocking apis only to make this
             * usable from idle tasks.
             * As Idle task should not be blocked/suspended.
             * */
            uart_ioctl(hconsole_uart, UART_GET_TX_STATE, &console_state);
            if (console_state == -EBUSY)
            {
                break;
            }
            if (osal_mutex_lock(buffer_mutex, 0))
            {
                bytes_read = osal_pipe_receive(buffer_pipe, intermediate_buffer, MAX_INT_BUFF_SIZE);
                osal_mutex_unlock(buffer_mutex);
                uart_write_async(hconsole_uart, intermediate_buffer, bytes_read);
            }
        } while(bytes_read);
    }
}

int console_read(unsigned char *const buffer, int length)
{
    return uart_read_sync(hconsole_uart, buffer, length);
}

int console_deinit()
{
    int ret = uart_close(hconsole_uart);
    if (ret == 0)
    {
        hconsole_uart = NULL;
    }
    return ret;
}
