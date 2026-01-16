
/*
 * FreeRTOS V3.1.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
 * Sample application for ping server. Modified for SoC FPGA
 */


/* ICMP ping Function */
#include "main_freertosplus_basic.h"
#include "osal.h"

/**
 * @file basic_freertosplus_icmp.c
 * @brief Sample Application for ICMP ping server.
 */

/**
 * @defgroup ping_sample Ethernet - ICMP Ping Server
 * @ingroup samples
 *
 * Sample Application for FreeRTOS+Ping Server
 *
 * @details
 * @section ping_desc Description
 * This is a simple program that demonstrates how to create a Ping server using FreeRTOS+ICMP.
 * The server waits for incoming ping client connections on a specified port. Once a client
 *
 * Each message is sent with an incrementing count. This demonstrates socket handling,
 * connection acceptance, message formatting, and transmission over TCP using the FreeRTOS+TCP stack.
 *
 * @section ping_pre Prerequisites
 * - Ensure FreeRTOS+TCP is correctly configured and integrated with the network driver.
 * - Network PHY and MAC drivers must be initialized and functioning.
 * - A static IP or DHCP setup must be in place for the FreeRTOS+TCP stack.
 *
 * @section ping_howto How to Run
 * 1. Follow the platform-specific README to build and flash the application.
 * 2. Connect the device to a LAN where the host PC resides.
 * 3. Run ping server.
 * 4. Once connected, observe the periodic server messages on the client terminal.
 *
 * @section ping_res Expected Results
 * - The ICMP server starts listening on the configured port.
 * - prints the recieved checksum.
 *
 * @{
 */
/** @} */


void vPingTask(void *pvParameters)
{
	(void)pvParameters;
	uint16_t usRequestSequenceNumber,usReplySequenceNumber;
	uint32_t ulIPAddress = 0;
	const TickType_t xDelay = pdMS_TO_TICKS(1000);

	/* The pcIPAddress parameter holds the destination IP address as a string in
       decimal dot notation (for example, "192.168.1.10"). Convert the string into
       the required 32-bit format. */
	ulIPAddress = FreeRTOS_inet_addr(PING_SERVER_IP);

	/* Wait for network initalization */
	ulTaskNotifyTake(pdTRUE,portMAX_DELAY);

	/* Send a ping containing 8 data bytes. Wait (in the Blocked state) a
       maximum of 100ms for a network buffer into which the generated ping request
       can be written and sent. */
	for(;;){
		usRequestSequenceNumber = FreeRTOS_SendPingRequest(ulIPAddress, 8,xDelay );
		if( usRequestSequenceNumber == pdFAIL )
		{
			FreeRTOS_printf(("Ping to server failed\n"));
			/* The ping could not be sent because a network buffer could not be
		       obtained within 100ms of FreeRTOS_SendPingRequest() being called. */
		}
		else
		{
			FreeRTOS_printf(("Sent ping request to server, sequence number: %u\n ",
						usRequestSequenceNumber));

			/* The ping was sent. Wait 200ms for a reply. The sequence number from
		    	each reply is sent from the vApplicationPingReplyHook() on the
		    	xPingReplyQueue queue (this is not standard behavior, but implemented in
		    	the example function above). It is assumed the queue was created before
		    	this function was called!
		    */
			if( osal_queue_receive( xPingReplyQueue,&usReplySequenceNumber,
					100 / portTICK_PERIOD_MS ) == pdPASS )

			{
				/* A ping reply was received. Was it a reply to the ping just sent? */
				if( usRequestSequenceNumber == usReplySequenceNumber )
				{
					/* This was a reply to the request just sent. */
				}
			}
			/* Ping request send successful */
		}
		/* Delay for a while */
		osal_task_delay(xDelay);

	}
}

/* If ipconfigSUPPORT_OUTGOING_PINGS is set to 1 in FreeRTOSIPConfig.h then
   vApplicationPingReplyHook() is called by the TCP/IP stack when the stack receives a
   ping reply. */
void vApplicationPingReplyHook( ePingReplyStatus_t eStatus, uint16_t usIdentifier )
{
	switch( eStatus )
	{
	case eSuccess:
		FreeRTOS_printf(("Ping reply received, with Identifier: %u\n",usIdentifier));

		/* A valid ping reply has been received. Post the sequence number
		on the queue that is read by the vSendPing() function below. Do
		not wait more than 10ms trying to send the message if it cannot be
		sent immediately because this function is called from the TCP/IP
		RTOS task - blocking in this function will block the TCP/IP RTOS task.
		 */
		xQueueSend( xPingReplyQueue, &usIdentifier, 10 / portTICK_PERIOD_MS );
		break;

	case eInvalidChecksum :
		FreeRTOS_printf(("Ping reply received with invalid checksum, Identifier: %u\n",usIdentifier));
		break;
	case eInvalidData :
		/* A reply was received but it was not valid. */
		FreeRTOS_printf(("Unknown ping reply received with invalid data, Identifier: %u\n",usIdentifier));
		break;
	}
}
