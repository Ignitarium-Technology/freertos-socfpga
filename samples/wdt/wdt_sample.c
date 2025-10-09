/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for wdt
 */

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "osal_log.h"
#include "task.h"
#include "semphr.h"
#include "socfpga_watchdog.h"
#include "osal.h"

/**
 * @defgroup wdt_sample Watchdog Timer
 * @ingroup samples
 *
 * Sample application for Watchdog Timer
 * @details
 * @section wdt_desc Description
 * This sample application demonstrates the use of watchdog timer APIs.
 * The sample application will use four parameters. init_timeout time, timeout,
 * service period and number of services. It will service (restart) the WDT
 * every service period from a thread context. But stops doing it after the
 * given number of services. The timeout behavior will be set to interrupt.
 * We will get an interrupt after a timeout expiry. Since we stop restarting
 * the timer, it will then reboot the system after the next timeout expiry.
 *
 * @note This program will reboot the system.
 *
 * @section wdt_param Configurable Parameters
 * - init_timeout and timeout value can be configured in milli second units.
 * - Service time can be configured in the sample structure @c opts .
 * - Instance can be configured by changing the value in @c WDT_INSTANCE macro.
 *
 * @section wdt_how_to How to Run
 * 1. Follow the common README instructions to build and flash the application.
 * 2. Run the application on the board.
 * 3. Monitor UART terminal output for WDT service messages, callback notification,
 *    and system reboot.
 *
 * @section wdt_result Expected Results
 * - The watchdog timer is periodically serviced for the given number of times.
 * - A timeout interrupt is received after a timeout expiry.
 * - The system is rebooted on the next timeout expiry.
 */
typedef struct
{
    uint32_t service;
    uint32_t nservice;
    uint32_t init_timeout;
    uint32_t timeout;
} wdt_sample_t;

wdt_handle_t handle;
volatile int callback_cnt = 0;
SemaphoreHandle_t callback_sem;

/* test configuration */
#define TASK_PRIORITY    (config_max_priorities - 2)

/* WDT instance used in this sample */
#define WDT_INSTANCE    0

wdt_sample_t opts =
{
    /* Use approximately 5 seconds time out */
    .init_timeout = 5000,
    .timeout = 5000,

    /* Service every 2 seconds */
    .service = 2,
    /* Service two times */
    .nservice = 2
};

void wdt_callback(void *arg)
{
    handle = (wdt_handle_t)arg;

    /*
     * When we get the callback first time we will service it so that
     * we get time to print out a message from the thread
     */
    if (callback_cnt == 0)
    {
        callback_cnt++;
        wdt_restart(handle);
        osal_semaphore_post(callback_sem);
    }
    else
    {
        /*
         * When the callback hits again we will hang here.
         * The system will reset after timeout expiry
         */
        while (1);
    }
}

void wdt_task(void)
{
    int retval = 0;

    callback_sem = osal_semaphore_create(NULL);
    wdt_timeout_config_t timeout_config = WDT_TIMEOUT_INTR;

    PRINT("WDT sample application");

    PRINT("Configuring the WDT ...");

    handle = wdt_open(0);
    if (handle == NULL)
    {
        ERROR("Opening WDT instance failed");
        return;
    }

    retval = wdt_ioctl(handle, WDT_SET_TIMEOUT_BEHAVIOUR, &timeout_config);
    if (retval != 0)
    {
        ERROR("Configuring timeout behaviour failed");
        wdt_close(handle);
        return;
    }

    retval = wdt_ioctl(handle, WDT_SET_INIT_TIMEOUT, &opts.init_timeout);
    if (retval != 0)
    {
        ERROR("Configuring init_timeout failed");
        wdt_close(handle);
        return;
    }

    retval = wdt_ioctl(handle, WDT_SET_TIMEOUT, &opts.timeout);
    if (retval != 0)
    {
        ERROR("Configuring timeout failed");
        wdt_close(handle);
        return;
    }

    wdt_set_callback(handle, wdt_callback, handle);

    PRINT("WDT configuration done.");

    retval = wdt_start(handle);

    if (retval != 0)
    {
        ERROR("WDT start failed");
        wdt_close(handle);
        return;
    }

    PRINT("WDT started.");

    for (uint32_t num_service = 0; num_service < opts.nservice; num_service++)
    {
        osal_task_delay((opts.service * 1000));
        wdt_restart(handle);
        PRINT("Serviced WDT.");
    }

    PRINT("WDT service stopped");
    /*
     * At this point we have stopped servicing the interrupt.
     * We will wait for the interrupt on the timeout  expiry.
     *
     * We will keep a 25 seconds timeout for receiving the interrupt
     */

    retval = osal_semaphore_wait(callback_sem, 25 * 1000);
    if (retval == pdTRUE)
    {
        PRINT("WDT timeout expiry interrupt occurred");
        /*
         * At this point we will suspend this task.
         * In the callback function we will just hang. And on timeout the system reset will occur
         */
        vTaskSuspend(NULL);
    }
    else
    {
        ERROR("WDT timeout expiry interrupt did not occur");
    }

    vTaskSuspend(NULL);
}
