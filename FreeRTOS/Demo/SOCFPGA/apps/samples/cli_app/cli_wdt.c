/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for WDT
 */

/**
 * @defgroup cli_wdt Watchdog Timer
 * @ingroup cli
 *
 * Perform watchdog timer operations
 *
 * @details
 * It supports the following commands:
 * - wdog test &lt;service_period&gt; &lt;number_of_services&gt; &lt;init_timeout&gt; &lt;timeout&gt;
 * - wdog help
 *
 * Typical usage:
 * - Use 'wdog test' command to perform a watchdog timer test.
 *
 * @section wdt_commands Commands
 * @subsection wdt_test wdog test
 * Perform Watchdog timer test <br>
 *
 * Usage: <br>
 *   wdog test &lt;service_period&gt; &lt;number_of_services&gt; &lt;init_timeout&gt; &lt;timeout&gt; <br>
 *
 * It requires the following arguments:
 * - service_period       The time in seconds to wait before servicing the WDT timer. The range is 0 to 20 seconds.
 * - number_of_services   The number of times to service the WDT timer. It should be a positive number less than 256.
 * - init_timeout         Timeout in milliseconds. In the hardware there are only 16 timeout values possible.
 *                        The init timeout will be selected such that the configured timeout is at least as long as the desired time
 *                        out.
 * - timeout              Timeout in milliseconds. In the hardware there are only 16 timeout values possible.
 *                        The timeout will be selected such that the configured timeout is at least as long as the desired time
 *                        out.
 *
 * The supported timeout in hardware corresponds to 2 ^ (n + 16) clock ticks where n can be from 0 to 15. For example, if the WDT clock
 * is 100 MHz and n = 14, it will give approximately 10000 milli seconds or 10 seconds timeout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <socfpga_uart.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "cli_utils.h"
#include <socfpga_watchdog.h>
#include <osal_log.h>

#define MAX_SERVICE_TIME    20
#define MAX_SERVICE_NUM     255

typedef struct
{
    uint32_t service;
    uint32_t nservice;
    uint32_t init_timeout;
    uint32_t timeout;
} wdt_test_t;

wdt_test_t wdt_opts;
wdt_handle_t wdt_handle;

void wdt_test_callback( void *puser_context )
{
    (void) puser_context;
    PRINT("Woof!! from watchdog");
    while (1)
        ;
}

void wdt_test( void *params )
{
    int retval = 0;
    wdt_test_t *pwdt_opts = (wdt_test_t*) params;
    wdt_timeout_config_t timeoutconfig = WDT_TIMEOUT_INTR;

    wdt_handle = wdt_open(0);
    if (wdt_handle == NULL)
    {
        PRINT("WDT Instance error");
        goto end;
    }

    retval = wdt_ioctl(wdt_handle, WDT_SET_INIT_TIMEOUT,
            &pwdt_opts->init_timeout);
    if (retval != 0)
    {
        ERROR("init_timeout time not set");
        goto end;
    }

    retval = wdt_ioctl(wdt_handle, WDT_SET_TIMEOUT,
            &pwdt_opts->timeout);
    if (retval != 0)
    {
        ERROR("timeout time not set");
        goto end;
    }

    retval = wdt_ioctl(wdt_handle, WDT_SET_TIMEOUT_BEHAVIOUR,
            &timeoutconfig);
    if (retval != 0)
    {
        ERROR("Interrupt not set.");
        goto end;
    }
    wdt_set_callback(wdt_handle, wdt_test_callback, NULL);

    retval = wdt_start(wdt_handle);      //start the watchdog timer
    if (retval != 0)
    {
        ERROR("Timer not started.");
        goto end;
    }

    for (uint32_t num_service = 0; num_service < pwdt_opts->nservice;
            num_service++)
    {
        osal_delay_ms((pwdt_opts->service * 1000));
        wdt_restart(wdt_handle);
        PRINT("%d : Servicing WDT timer.", num_service);
    }
end: vTaskSuspend(NULL);
}

BaseType_t cmd_wdt( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void) write_buffer_len;
    int ret;
    const char *parameter1, *parameter2, *parameter3, *parameter4,
            *parameter5;
    BaseType_t parameter1_str_len, parameter2_str_len,
            parameter3_str_len, parameter4_str_len,
            parameter5_str_len;

    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1,
            &parameter1_str_len);
    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
            &parameter2_str_len);
    parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
            &parameter3_str_len);
    parameter4 = FreeRTOS_CLIGetParameter(command_string, 4,
            &parameter4_str_len);
    parameter5 = FreeRTOS_CLIGetParameter(command_string, 5,
            &parameter5_str_len);

    if (!strncmp(parameter1, "test", strlen("test")))
    {
        if (!strncmp(parameter2, "help", strlen("help")))
        {
            printf("\r\nPerform Watchdog timer test\r\n"
                    "\r\n\nUsage:"
                    "\r\n  wdog test <service_period> <number_of_services> <init_timeout> <timeout>"
                    "\r\n\nIt supports the following arguments:"
                    "\r\n  service_period        The time in seconds to wait before servicing the WDT timer."
                    "\r\n  number_of_services    The number of times to service the WDT timer."
                    "\r\n  init_timeout          Select time period for init_timeout  between 0ms and 20000ms. The timeout will be selected such that"
                    "\r\n                        desired timeout is as long as one of the 16 timeout values supported in hardware"
                    "\r\n  timeout               Select time period for timeout  between 0ms and 20000ms. The timeout will be selected such that"
                    "\r\n                        desired timeout is as long as one of the 16 timeout values timeout supported in hardware."
                    "\r\nSupported init_timeout and timeout values corresponds to 2 ^ (n + 16) clock ticks where n can be from 0 to 15."
                    "\r\nFor example, if the WDT clock is 100 MHz and n = 14, it will give approximately 10000 milli seconds or 10 seconds timeout\r\n");
            return pdFALSE;
        }
        if ((parameter2 == NULL) || (parameter3 == NULL) ||
                (parameter4 == NULL)
                || (parameter5 == NULL))
        {
            ERROR("Incorrect number of  arguments for wdog test");
            return pdFAIL;
        }

        ret = cli_get_decimal("wdt test","service_period", parameter2, 0,
                MAX_SERVICE_TIME, &wdt_opts.service);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_get_decimal("wdt test","number_of_services", parameter3, 0,
                MAX_SERVICE_NUM, &wdt_opts.nservice);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_get_decimal("wdt test","init_timeout", parameter4, 0, 40000,
                &wdt_opts.init_timeout);
        if (ret != 0)
        {
            return pdFAIL;
        }
        ret = cli_get_decimal("wdt test","timeout", parameter5, 0, 40000,
                &wdt_opts.timeout);
        if (ret != 0)
        {
            return pdFAIL;
        }
        if (xTaskCreate(wdt_test, "wdttest_task", configMINIMAL_STACK_SIZE,
                &wdt_opts, tskIDLE_PRIORITY, NULL) != pdPASS)
        {
            ERROR("task creation failed");
            while (1)
                ;
        }
        else
        {
            PRINT("Test started.");
        }
    }
    else if (!strncmp(parameter1, "help", strlen("help")))
    {
        printf("\rPerform Watchdog timer operations"
                "\r\n\nIt supports the following commands:"
                "\r\n  wdog test <service_period> <number_of_services> <init_timeout> <timeout>"
                "\r\n  wdog help"
                "\r\n\nTypical usage:"
                "\r\n- Use the 'wdog test' command to start the watchdog timer test"
                "\r\n\nFor command specific help, try:"
                "\r\n  wdog <command> help\r\n");
    }
    else
    {
        ERROR("Unknown WDT command."
                "\r\nUse 'wdog help' for more information.");
    }
    write_buffer[ 0 ] = 0;
    return pdFALSE;
}
