/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for ethernet sample app
 */

#ifndef __MAIN_BASIC_APP_H__
#define __MAIN_BASIC_APP_H__

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_DHCP.h"
#include "FreeRTOS_Sockets.h"
#include "NetworkInterface.h"

/* Define Macros */
#define DEMO_PING              0
#define DEMO_TCP               0
#define DEMO_UDP               0
#define DEMO_ECHOTCP           1
#define DEMO_IPERF             0
#define TCP_SERVER_PORT        9640
#define UDP_SERVER_PORT        8897
#define PING_SERVER_IP         "192.168.1.100"
#define FREERTOS_IP            "192.168.1.6"
#define QUEUE_LENGTH           10
#define NETWORK_BUFFER_SIZE    30
#define BUFFER_SIZE            1400

/*Enable the macro to avail DHCP*/
#define DEMO_DHCP              1

/* Function prototypes */
#if (DEMO_DHCP == 1)
void setup_dhcp_demo();
#else
void setup_static_demo();
#endif
void vPingTask( void *pvParameters );
void vTCPServerTask( void *pvParameters );
void vUDPServerTask( void *pvParameters );
void vSimpleTCPServerTask( void *pvParameters );

/* This example code snippet assumes the queue has already been created! */
extern QueueHandle_t xPingReplyQueue;

/* Ping notify Handler */
extern TaskHandle_t PingTaskHandle;

/* TCP notify Handler */
extern TaskHandle_t TCPTaskHandle;
extern TaskHandle_t EchoTCPServerTaskHandle;

/* UDP notify Handler */
extern TaskHandle_t UDPTaskHandle;

/* ICMP ping Reply Hook Function */
void vApplicationPingReplyHook( ePingReplyStatus_t eStatus,
        uint16_t usIdentifier );

/* DHCP Hook Functions */
const char*pcApplicationHostnameHook( void );
eDHCPCallbackAnswer_t xApplicationDHCPHook( eDHCPCallbackPhase_t eDHCPPhase,
        uint32_t ulIPAddress );
void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent );

#endif /* __MAIN_BASIC_APP_H__ */
