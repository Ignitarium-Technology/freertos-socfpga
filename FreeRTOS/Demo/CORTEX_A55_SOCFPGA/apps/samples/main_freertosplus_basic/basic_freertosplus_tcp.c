
/*
 * FreeRTOS V3.1.0
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
 * Sample application for TCP server. Modified for SoC FPGA
 *
 */


#include "main_freertosplus_basic.h"

/**
 * @file basic_freertosplus_tcp.c
 * @brief Sample Application for TCP server.
 */

/**
 * @defgroup tcp_sample Ethernet - TCP Server
 * @ingroup samples
 *
 * Sample Application for FreeRTOS+TCP Server
 *
 * @details
 * @section tcp_desc Description
 * This is a simple program that demonstrates how to create a TCP server using FreeRTOS+TCP.
 * The server waits for incoming TCP client connections on a specified port. Once a client
 * connects, it sends back a periodic message in the format:
 * `Message no.%d: Hello, This is FreeRTOS TCP server!`
 *
 * Each message is sent with an incrementing count. This demonstrates socket handling,
 * connection acceptance, message formatting, and transmission over TCP using the FreeRTOS+TCP stack.
 *
 * @section tcp_pre Prerequisites
 * - Ensure FreeRTOS+TCP is correctly configured and integrated with the network driver.
 * - Network PHY and MAC drivers must be initialized and functioning.
 * - A static IP or DHCP setup must be in place for the FreeRTOS+TCP stack.
 *
 * @section tcp_howto How to Run
 * 1. Follow the platform-specific README to build and flash the application.
 * 2. Connect the device to a LAN where the host PC resides.
 * 3. Run a TCP client tool (e.g., `netcat` or `telnet`) from a host PC to connect to the server:
 *    - Example: `nc <board-ip> <port>`
 * 4. Once connected, observe the periodic server messages on the client terminal.
 *
 * @section tcp_res Expected Results
 * - The TCP server starts listening on the configured port.
 * - Upon connection from a client, the server starts sending messages like:
 *   - `Message no.1: Hello, This is FreeRTOS TCP server!`
 *   - `Message no.2: Hello, This is FreeRTOS TCP server!`
 *   - ...
 *
 * @section tcp_custom Customization
 * - Modify the `ulPort` variable to change the server port.
 * - Can be extended to support multiple concurrent client connections with minor enhancements.
 * @{
 */
/** @} */

/* TCP server */

static int8_t ucRxBuffer[BUFFER_SIZE];
static int8_t ucTxBuffer[BUFFER_SIZE];

void vTCPServerTask(void *pvParameters)
{
	(void)pvParameters;
	struct freertos_sockaddr xServerAddress, xClientAddress;
	Socket_t xListeningSocket, xConnectedSocket;
	socklen_t xClientSize = sizeof( xClientAddress );
	static const TickType_t receive_timeout = portMAX_DELAY;
	BaseType_t xReceivedBytes = 0;
	const BaseType_t xBacklog = 20;
	uint32_t ulCount = 0;

	/* Wait for network initalization */
	ulTaskNotifyTake(pdTRUE,portMAX_DELAY);

	/* Create the TCP socket */
	xListeningSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_STREAM, FREERTOS_IPPROTO_TCP);

	/* Check the socket was created. */
	configASSERT( xListeningSocket != FREERTOS_INVALID_SOCKET );
	FreeRTOS_setsockopt(
			xListeningSocket, 0, FREERTOS_SO_RCVTIMEO, &receive_timeout, sizeof(receive_timeout));

	/* Bind the socket to port 9640 */
	xServerAddress.sin_port = FreeRTOS_htons(TCP_SERVER_PORT);
	xServerAddress.sin_family = FREERTOS_AF_INET; /* FREERTOS_AF_INET6 to be used for IPv6 */
	xServerAddress.sin_address.ulIP_IPv4 = FreeRTOS_GetIPAddress();
	FreeRTOS_bind(xListeningSocket, &xServerAddress, sizeof(xServerAddress));

	/* Get available HEAP space */
	size_t freeHeapSize = xPortGetFreeHeapSize();
	FreeRTOS_printf(("Free Heap Size: %zu\n", freeHeapSize));

	/* Listen for incoming connections */
	FreeRTOS_listen(xListeningSocket, xBacklog);
	FreeRTOS_printf(("Server listening\n"));

	for (;;)
	{
		/* Accept a new connection */
		xConnectedSocket = FreeRTOS_accept(xListeningSocket, &xClientAddress, &xClientSize);
		configASSERT( xConnectedSocket != FREERTOS_INVALID_SOCKET );
		ulCount = 0;
		if (xConnectedSocket != FREERTOS_INVALID_SOCKET)
		{
			FreeRTOS_printf(("Client connected\n"));
			while(1)
			{
				/* Receive data from the client */
				xReceivedBytes = FreeRTOS_recv(xConnectedSocket, ucRxBuffer, sizeof(ucRxBuffer), 0);

				if( xReceivedBytes > 0 )
				{
					ucRxBuffer[xReceivedBytes] = '\0';
					/* Data was received, process it here. */
					FreeRTOS_printf(("%lu bytes received from client: %s\n",xReceivedBytes, ucRxBuffer));

					/* Send response to the client */
					sprintf((char *)ucTxBuffer,
							"Message no.%d: Hello, This is FreeRTOS TCP server!",ulCount++);
					FreeRTOS_send(xConnectedSocket,ucTxBuffer, strlen((char *)ucTxBuffer),0);
				}
				else if( xReceivedBytes == 0 )
				{
					/* No data was received, but FreeRTOS\_recv() did not return an error.
                   		Timeout? */
					FreeRTOS_printf(("Client disconnected\n"));
				}
				else
				{
					/* Error (maybe the connected socket already shut down the socket?).
					 *  Attempt graceful shutdown.
					 */
					FreeRTOS_printf(("Recv failed\n"));
					break;
				}
			}
			/* Shutdown is complete, close the socket safely */
			FreeRTOS_closesocket(xConnectedSocket);
		}

	}
}
