/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for uart
 */

/**
 * @file uart_sample.c
 * @brief Sample Application for UART
 */
#include <string.h>
#include <stdint.h>

#include "osal.h"
#include <task.h>

#include "socfpga_uart.h"

/**
 * @defgroup uart_sample UART
 * @ingroup samples
 *
 * Sample Application for UART
 *
 * @details
 * @section uart_desc Description
 * This is a simple program to demonstrate the use of uart driver. It will receive
 * characters one at a time and store them until a new line character is received.
 * Once it receives the new line character, it will send back all the stored
 * characters.
 *
 * @section uart_pre Prerequisites
 * - Configuration:
 * - To prevent conflict with console output, ensure the macro below is configured as follows
 * @c FreeRTOS/Demo/SOCFPGA/FreeRTOSConfig.h: <br>
 * @c \#define @c configENABLE_CONSOLE_UART @c 0
 * - This disables the default console UART, allowing this sample to use the UART exclusively.
 *
 * @section uart_howto How to Run
 * 1. Follow the common README for build and flashing instructions.
 * 2. Connect a serial terminal to the board's UART interface.
 * 3. Configure the terminal with the following settings:
 * - Baud rate: 115200
 * - Data bits: 8
 * - Parity: None
 * - Stop bits: 1
 * - Flow control: None
 * 4. Type text into the terminal and press Enter.
 *
 * @section uart_res Expected Results
 * - Characters typed on the terminal are buffered and not echoed immediately.
 * - When Enter is pressed (newline received), all previously typed characters are echoed back.
 * - If the entered string is "exit" it will exit the program
 * @{
 */
/** @} */

/* test configurations */
#define RX_TASK_PRIORITY    (configMAX_PRIORITIES - 2)


#define PROMPT_STR    "\n\rsocfpga> "

#define HELP_STR \
    "This is a simple echo back program for demonstrating the"   \
    " UART driver.\n\rType any string under 1000 characters and" \
    " press enter.\n\rThe program will echo back the string\n\r" \
    " The program will exit if the string is \"exit\".\n\r"

#define EXIT_STR    "exit"

#define EXIT_MSG    "Exiting the echo program\n\r"

#define UART_INSTANCE    0

osal_mutex_def_t eol_sem_mem;
osal_semaphore_t eol_sem;

uart_handle_t handle;
int exit_flag = 0;

uint8_t read_buf[1000] = { 0 };

uint8_t write_buf[1000] = { 0 };

/**
 * @brief read and store rx bytes
 *
 * Once new line is received signals the write thread.
 */
void read_thread()
{
    uint32_t read_pos = 0;
    uint8_t ch = 0U;

    while (1)
    {
        if (uart_read_sync(handle, &ch, 1) != 0)
        {
            break;
        }

        if ((ch == '\r') && (read_pos > 0))
        {
            read_buf[read_pos] = '\0';
            memcpy(write_buf, read_buf, (read_pos + 1));
            read_pos = 0;
            if (strncmp((const char *)write_buf, EXIT_STR,
                    sizeof(EXIT_STR)) == 0)
            {
                exit_flag = 1;
            }
            osal_semaphore_post(eol_sem);
            if (exit_flag)
            {
                break;
            }
        }
        else if (read_pos < (sizeof(read_buf) - 1))
        {
            read_buf[read_pos++] = ch;
        }
    }
    vTaskDelete(NULL);
}

/**
 * @brief Open UART and configure it
 * Write back the received characters
 */
void uart_task(void)
{
    eol_sem = osal_semaphore_create(&eol_sem_mem);
    uart_config_t config;

    handle = uart_open(UART_INSTANCE);

    if (handle == NULL)
    {
        vTaskDelete(NULL);
    }

    config.wlen = 8;
    config.baud = 115200;
    config.parity = UART_PARITY_NONE;
    config.stop_bits = UART_STOP_BITS_1;

    if (uart_ioctl(handle, UART_SET_CONFIG, &config) != 0)
    {
        uart_close(handle);
        vTaskDelete(NULL);
    }

    xTaskCreate(read_thread, "read_thread", configMINIMAL_STACK_SIZE, NULL,
            RX_TASK_PRIORITY, NULL);

    uart_write_sync(handle, (uint8_t *)HELP_STR, sizeof(HELP_STR));

    while (1)
    {
        if (uart_write_sync(handle, (uint8_t *)PROMPT_STR,
                sizeof(PROMPT_STR)) != 0)
        {
            vTaskDelete(NULL);
        }

        /* wait until a new line is received by the read thread */
        osal_semaphore_wait(eol_sem, 0xFFFFFFFF);

        if (exit_flag)
        {
            /* print the exit message and exit */
            if (uart_write_sync(handle, (uint8_t *)EXIT_MSG,
                    sizeof(EXIT_MSG)) != 0)
            {
                vTaskDelete(NULL);
            }
            break;
        }

        /* echo back the received characters */
        if (uart_write_sync(handle, write_buf, strlen((const
                char *)write_buf)) != 0)
        {
            vTaskDelete(NULL);
        }
    }

    osal_semaphore_delete(eol_sem);
    uart_close(handle);
}
