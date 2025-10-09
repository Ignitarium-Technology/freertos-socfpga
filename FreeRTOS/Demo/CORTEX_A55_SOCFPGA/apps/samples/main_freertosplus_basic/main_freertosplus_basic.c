/*
 * FreeRTOS+TCP V3.1.0
 * Copyright (C) 2022 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
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
 * Ethernet Sample application. Modified for SoC FPGA.
 */

/**
 * @defgroup enet_sample Ethernet
 *
 * Sample Application for Ethernet
 *
 * Network Demo Test Commands
 *
 * @details
 * # Test Ping Server (check connectivity to board)
 * ping <IP address>
 * ping -6 <IPv6 address>%<interface>
 *
 * # Test TCP Echo Server (open TCP client, type messages and expect echo)
 * nc -v <IP address> <PORT>
 * nc -6 -v <IPv6 address>%<interface> <PORT>
 *
 * # Test TCP Server (send file/data to board over TCP)
 * nc <IP address> <PORT> < input.txt
 *
 * # Test UDP Echo Server (open UDP client, type messages and expect echo)
 * nc -u -v <IP address> <PORT>
 * nc -u -6 -v <IPv6 address>%<interface> <PORT>
 */


#include <stdlib.h>
#include "main_freertosplus_basic.h"
#include "osal.h"
#include "iperf_task.h"

QueueHandle_t xPingReplyQueue;

/* Task notify Handlers */
TaskHandle_t PingTaskHandle = NULL;
TaskHandle_t TCPTaskHandle = NULL;
TaskHandle_t UDPTaskHandle = NULL;
TaskHandle_t EchoTCPServerTaskHandle = NULL;

void vApplicationTickHook( void )
{
    /*
     * This is called from RTOS tick handler
     * Not used in this demo, But defined to keep the configuration sharing
     * simple
     * */
}

/** Main Application to start **/
void main_freertosplus_basic( void )
{
    BaseType_t xReturned;
    osal_queue_def_t q;

    /*To supress warning*/
    (void)xReturned;
    /* Initialize FreeRTOS+TCP server for IP address */
#if	 DEMO_DHCP
    setup_dhcp_demo();
#else
    setup_static_demo();
#endif
    q.depth = QUEUE_LENGTH;
    q.item_sz = sizeof(uint16_t);
    /* Create the queue for ping replies */
    xPingReplyQueue = osal_queue_create(&q);

    if ( xPingReplyQueue == NULL )
    {
        /* Queue creation failed; handle error (e.g., reset system or halt) */
        FreeRTOS_printf(("Queue creation failed\n"));
    }
#if (DEMO_PING == 1)
    /* Task to ping the target ip */
    xReturned = xTaskCreate(
            vPingTask,  				/* Function that implements task */
            "PingTask", 				/* Task name for the task */
            configMINIMAL_STACK_SIZE*10,	/* Stack size in bytes */
            NULL, 				/* Parameter passed into the task */
            tskIDLE_PRIORITY+1, 		/* Priority at which task is created */
            &PingTaskHandle);		/* Task handle to keep track of the task */

#elif  (DEMO_TCP == 1)
    /* Task for TCP communication */
    xReturned = xTaskCreate(vTCPServerTask, "TCPServer", configMINIMAL_STACK_SIZE*10,
            NULL,tskIDLE_PRIORITY+1, &TCPTaskHandle);

#elif (DEMO_ECHOTCP == 1)
    /* Task for TCP communication */
    xReturned = xTaskCreate(vSimpleTCPServerTask, "EchoServer", configMINIMAL_STACK_SIZE,
            NULL, tskIDLE_PRIORITY +1, &EchoTCPServerTaskHandle);
#elif (DEMO_UDP == 1)
    /* Task for UDP communication */
    xReturned = xTaskCreate(vUDPServerTask, "UDPServer", configMINIMAL_STACK_SIZE,
            NULL, tskIDLE_PRIORITY+1, &UDPTaskHandle);

#elif (DEMO_IPERF == 1)
    vIPerfInstall();
#endif
    /* Start the scheduler */
    vTaskStartScheduler();

    /* The code should never reach here */
    for ( ;; )
        ;
}

uint32_t ulApplicationGetNextSequenceNumber( uint32_t ulSourceAddress,
        uint16_t usSourcePort, uint32_t ulDestinationAddress,
        uint16_t usDestinationPort )
{
    uint32_t ulReturn;
    uint32_t ulRandomNumber;
    ulReturn = ulSourceAddress ^ ulDestinationAddress;
    ulReturn += (uint32_t) usSourcePort + (uint32_t) usDestinationPort;
    if ( xApplicationGetRandomNumber(&ulRandomNumber) == pdPASS )
        ulReturn ^= ulRandomNumber;

    return ulRandomNumber;
}
BaseType_t xApplicationGetRandomNumber( uint32_t *pulNumber )
{
    if ( pulNumber == NULL )
        return pdFAIL;

    *pulNumber = (uint32_t) rand();

    return pdPASS;

}
