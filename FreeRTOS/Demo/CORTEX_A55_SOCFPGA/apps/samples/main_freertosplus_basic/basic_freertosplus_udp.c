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
 * Sample application for udp server. Modified for SoC FPGA
 */

#include "main_freertosplus_basic.h"

/**
 * @file basic_freertosplus_udp.c
 * @brief Sample Application for UDP server.
 */

/**
 * @defgroup udp_sample Ethernet - UDP Server
 * @ingroup samples
 *
 * Sample Application for FreeRTOS+UDP Server
 *
 * @details
 * @section udp_desc Description
 * This is a simple program that demonstrates how to create a UDP server using FreeRTOS+TCP/IP stack.
 * The server waits for incoming UDP client connections on a specified port. Once a client
 * connects, it sends back a periodic message in the format:
 * `Message no.%d: Hello, This is FreeRTOS UDP server!`
 *
 * Each message is sent with an incrementing count. This demonstrates socket handling,
 * connection acceptance, message formatting, and transmission over TCP using the FreeRTOS+TCP stack.
 *
 * @section udp_pre Prerequisites
 * - Ensure FreeRTOS+TCP is correctly configured and integrated with the network driver.
 * - Network PHY and MAC drivers must be initialized and functioning.
 * - A static IP or DHCP setup must be in place for the FreeRTOS+TCP stack.
 *
 * @section udp_howto How to Run
 * 1. Follow the platform-specific README to build and flash the application.
 * 2. Connect the device to a LAN where the host PC resides.
 * 3. Run a TCP client tool (e.g., `netcat` or `telnet`) from a host PC to connect to the server:
 *    - Example: `nc -u <board-ip> <port>`
 * 4. Once connected, observe the periodic server messages on the client terminal.
 *
 * @section udp_res Expected Results
 * - The TCP server starts listening on the configured port.
 * - Upon connection from a client, the server starts sending messages like:
 *   - `Message no.1: Hello, This is FreeRTOS UDP server!`
 *   - `Message no.2: Hello, This is FreeRTOS UDP server!`
 *   - ...
 * - Disconnecting and reconnecting clients should still allow proper operation.
 *
 * @section udp_custom Customization
 * - Modify the `ulPort` variable to change the server port.
 * - Adjust the message interval or contents as needed.
 * - Can be extended to support multiple concurrent client connections with minor enhancements.
 * @{
 */
/** @} */

/* UDP server */
void vUDPServerTask(void *pvParameters)
{
	(void)pvParameters;
	struct freertos_sockaddr xBindAddress, xClient;
	Socket_t xListeningSocket;
	socklen_t xClientLength = sizeof(xClient);
	const TickType_t xSendTimeOut = 200 / portTICK_PERIOD_MS;
	int32_t lReceivedBytes;
	uint8_t ucTxBuffer[BUFFER_SIZE];
	uint8_t ucRxBuffer[BUFFER_SIZE];
	uint32_t ulCount =0;

	/* Wait for network initalization */
	ulTaskNotifyTake(pdTRUE,portMAX_DELAY);

	/* Create the UDP socket */
	xListeningSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_DGRAM, FREERTOS_IPPROTO_UDP);

	/* Check for errors. */
	configASSERT( xListeningSocket != FREERTOS_INVALID_SOCKET );

	/* Ensure calls to FreeRTOS\_sendto() timeout if a network buffer cannot be
	 * obtained within 200ms.
	 */
	FreeRTOS_setsockopt( xListeningSocket, 0, FREERTOS_SO_SNDTIMEO, &xSendTimeOut,
			sizeof( xSendTimeOut ) );


	memset( &xBindAddress, 0, sizeof(xBindAddress) );

	/* Bind the socket to port 9640 */
	xBindAddress.sin_port = FreeRTOS_htons(UDP_SERVER_PORT);
	xBindAddress.sin_family = FREERTOS_AF_INET; /* FREERTOS_AF_INET6 to be used for IPv6 */
	FreeRTOS_bind(xListeningSocket, &xBindAddress, sizeof(xBindAddress));

	for (;;)
	{

		/* Receive data from the client */
		lReceivedBytes = FreeRTOS_recvfrom(xListeningSocket, ucRxBuffer, sizeof(ucRxBuffer), 0, &xClient, &xClientLength);

		if (lReceivedBytes > 0)
		{
			ucRxBuffer[lReceivedBytes] = '\0';
			FreeRTOS_printf(("%d bytes received from client: %s\n", lReceivedBytes, ucRxBuffer ));

			/* Send the data back to the client */
			sprintf( (char *)ucTxBuffer,
					"Message no.%d: Hello, This is FreeRTOS UDP server!",ulCount++);
			FreeRTOS_sendto(xListeningSocket, ucTxBuffer, strlen((char *)ucTxBuffer), 0, &xClient, xClientLength);
		}
		else{
			FreeRTOS_printf(("Receive failed\n"));
			ulCount = 0;
		}
	}
}
