/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for network
 */

/**
 * @defgroup cli_enet Ethernet
 * @ingroup cli
 *
 * Perform ethernet operations.
 *
 * @details
 * It supports the following commands:
 * - eth config &lt;IP_Address&gt; &lt;port&gt;
 * - eth config
 * - eth start &lt;IP_Protocol&gt; &lt;IP&gt;&lt;port&gt;
 * - eth send &lt;Message&gt;
 * - eth stop
 *
 * Typical usage:
 * - Use 'eth config' command to configure the IP address and port.
 * - Use 'eth start' command to start the server.
 * - Use 'eth send' command to send message over TCP/UDP.
 * - Use 'eth stop' command to stop the server.
 *
 * @section enet_commands Commands
 * @subsection eth_config eth config
 * Config ethernet IP Address  <br>
 *
 * Usage: <br>
 *   eth config &lt;IP_Address&gt; &lt;port&gt; <br>
 * It does not require arguments if it is to be configured as DHCP <br>
 * It requires the following arguments if it is to be configured as static:
 * - IP address  IP address.
 * - port        port for communication.
 *
 * @subsection eth_start eth start
 * Start server over TCP/UDP protocol  <br>
 *
 * Usage: <br>
 *   eth start &lt;IP_Protocol&gt; &lt;IP_Address&gt; &lt;port&gt; <br>
 *   Remote PC: @code start nc [flags for udp or tcp] @endcode with socfpga's IP address and port.
 *   eg: $nc -u &lt;dest_IP_Address&gt; &lt;dest_port&gt;
 *   To listen to a port:nc -u -l &lt;udp_port&gt;
 *
 *
 * It does not require arguments if the server to be over TCP protocol.
 * It requires the following arguments if the server to be over UDP protocol:
 * - IP address  IP address
 * - port        port for communication.
 * <br>
 * @subsection eth_send eth send
 * send messages over TCP/UDP protocol
 *
 * Usage: <br>
 *   eth send &lt;Message&gt;
 *
 * It requires the following arguments:
 * - Messages Message to be send.
 *
 * @subsection eth_stop eth stop
 * stop the server
 * Usage: <br>
 *   eth stop
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "SocfpgaNetworkInterface.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_DHCP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_IPv6.h"
#include "FreeRTOS_Routing.h"
#include "socfpga_uart.h"
#include "osal_log.h"
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "cli_utils.h"

#if (ipconfigUSE_DHCP == 0)
#error "CLI application requires DHCP to be enabled"
#endif

#define QUEUE_LENGTH           10
#define NETWORK_BUFFER_SIZE    3000
#define BUFFER_SIZE            14000
#define PORT_NUM               9640
#define MIN_IP_LEN             7
#define MIN_PORT_LEN           1
/*Add Ethernet instance*/
#define INSTANCE_ID            2

static NetworkInterface_t xInterfaces[ 2 ];
static NetworkEndPoint_t xEndPoints[ 2 ];
static TaskHandle_t CliTCPTaskHandle = NULL;
static TaskHandle_t CliUDPTaskHandle = NULL;
static Socket_t xTcpListeningSocket, xTcpConnectedSocket;
static Socket_t xUdpListeningSocket;
static BaseType_t DHCPIsEnabled;
static BaseType_t isTCPRunning = pdFALSE;
static BaseType_t config_done_state = pdFALSE;

static uint8_t ucRxBuffer[ BUFFER_SIZE ];
static void vCliUDPServerTask( void *pvParameters );
static void vCliTCPServerTask( void *pvParameters );
BaseType_t xApplicationGetRandomNumber( uint32_t *pulNumber );
const char*pcApplicationHostnameHook( void );
void vApplicationPingReplyHook( ePingReplyStatus_t eStatus,
        uint16_t usIdentifier );
uint32_t ulApplicationGetNextSequenceNumber( uint32_t ulSourceAddress,
        uint16_t usSourcePort, uint32_t ulDestinationAddress,
        uint16_t usDestinationPort );

static char ipv6_addr[40];
static char ipv6_prefix[40];
static char ipv6_gateway_addr[40];
static char ipv6_dns_server_addr[40];
static uint8_t ucBuffer[NETWORK_BUFFER_SIZE];
/* Define the network mask */
static const uint8_t ucNetMask[4] = { 255, 255, 255, 0 };

/* Define the gateway address */
static const uint8_t ucGatewayAddress[4] = { 192, 168, 1, 1 };

/* The following is the address of an OpenDNS server. */
static const uint8_t ucDNSServerAddress[4] = { 192, 168, 1, 1 };
static const uint8_t ucMACAddress[6] = { 0xAA, 0xDA, 0xAF, 0xB1,
                                         0x6A, 0xC0 };

typedef enum
{
    ETH_STATE_INACTIVE,
    ETH_STATE_DO_CONFIG,
    ETH_STATE_CONFIG_DONE,
    ETH_STATE_SERVER_START,
    ETH_STATE_SERVER_RUNNING,
    ETH_STATE_SERVER_STOP,
} ETH_STATE;

typedef enum
{
    ETH_RAW,
    ETH_TCP,
    ETH_UDP
} ETH_IP;

typedef struct
{
    int ipPort;
    ETH_IP connType;
    uint8_t ipAddr[ 4 ];
} CRNT_CONN;

CRNT_CONN ethHndlr;
ETH_STATE crntState = ETH_STATE_INACTIVE;

eDHCPCallbackAnswer_t xApplicationDHCPHook( eDHCPCallbackPhase_t eDHCPPhase,
        uint32_t ulIPAddress )
{
    (void) ulIPAddress;
    eDHCPCallbackAnswer_t xResult = eDHCPContinue;

    switch (eDHCPPhase)
    {
    case eDHCPPhasePreDiscover: /* Driver is about to ask for a DHCP offer. */
        if (DHCPIsEnabled == pdFALSE)
        {
            xResult = (BaseType_t) eDHCPStopNoChanges;
        }
        /* Returning eDHCPContinue. */
        break;
    case eDHCPPhasePreRequest: /* Driver is about to request DHCP an IP address. */
        if (DHCPIsEnabled == pdFALSE)
        {
            xResult = (BaseType_t) eDHCPStopNoChanges;
        }
        break;
    }
    return xResult;
}

/* @brief : state machine to handle the tcp/udp server*/
static void eth_sm( ETH_STATE reqstate )
{
    BaseType_t xReturned;
    if (reqstate == ETH_STATE_DO_CONFIG)
    {
        if (crntState == ETH_STATE_INACTIVE)
        {
            if (DHCPIsEnabled == pdTRUE) {
                if (config_done_state == pdFALSE)
                {
                    config_done_state =pdTRUE;

                    ( void ) pxFillInterfaceDescriptor( INSTANCE_ID,
                            &(xInterfaces[ 0 ]));
                    FreeRTOS_FillEndPoint( &(xInterfaces[ 0 ]),
                            &(xEndPoints[ 0 ]),ethHndlr.ipAddr, ucNetMask,
                            ucGatewayAddress, ucDNSServerAddress,
                            ucMACAddress );
                    xEndPoints[ 0 ].bits.bWantDHCP = pdTRUE;
                    xEndPoints[ 0 ].bits.bIPv6 = pdFALSE_UNSIGNED;
                    PRINT("Initiating DHCP client to obtain IP");
                    PRINT("Using default port 9640");
                    if (FreeRTOS_IPInit_Multi() == pdPASS) {
                        PRINT(
                                "Successfully configured dynamic IP Address");
                    } else {
                        ERROR(
                                "Dynamic IP Address configuration failed");
                    }
                }
                else
                {
                    ERROR("Configuration change cannot be done");
                }
            } else {

                if (config_done_state == pdFALSE)
                {

                    config_done_state =pdTRUE;
                    ( void ) pxFillInterfaceDescriptor( INSTANCE_ID,
                            &(xInterfaces[ 0 ]));
                    FreeRTOS_FillEndPoint( &(xInterfaces[ 0 ]),
                            &(xEndPoints[ 0 ]),ethHndlr.ipAddr, ucNetMask,
                            ucGatewayAddress, ucDNSServerAddress,
                            ucMACAddress );

                    /* Initialize the TCP/IP stack. */
                    if (FreeRTOS_IPInit_Multi() == pdPASS) {
                        PRINT(
                                "Successfully configured static IP Address");
                    } else {
                        ERROR(
                                "Static IP Address configuration failed");
                    }
                }
                else
                {
                    ERROR("Configuration change cannot be done");
                }
            }
            crntState = ETH_STATE_CONFIG_DONE;
        }
        else if (crntState == ETH_STATE_CONFIG_DONE)
        {
            ERROR("Configuration change cannot be done.");
        }
        else if (crntState == ETH_STATE_SERVER_RUNNING)
        {
            ERROR(
                    "Configuration cannot be done. Server is running.");
        }
    }
    else if (reqstate == ETH_STATE_SERVER_START)
    {
        if (crntState == ETH_STATE_CONFIG_DONE)
        {
            if (ethHndlr.connType == ETH_TCP)
            {
                /* Task for TCP communication */
                if (CliTCPTaskHandle == NULL)
                {
                    xReturned = xTaskCreate(vCliTCPServerTask, "TCPServer",
                            configMINIMAL_STACK_SIZE, NULL,
                            tskIDLE_PRIORITY + 1,
                            &CliTCPTaskHandle);
                    if (xReturned == pdPASS)
                    {
                        PRINT("TCP server started");
                    }
                    else
                    {
                        ERROR("Failed to start TCP server");
                    }
                }
                else
                {
                    vTaskResume(CliTCPTaskHandle);
                    PRINT("TCP server started");
                }
                isTCPRunning = pdTRUE;
                crntState = ETH_STATE_SERVER_RUNNING;
            }
            else if (ethHndlr.connType == ETH_UDP)
            {
                if (CliUDPTaskHandle == NULL)
                {
                    /* Task for UDP communication */
                    xReturned = xTaskCreate(vCliUDPServerTask, "UDPServer",
                            configMINIMAL_STACK_SIZE, NULL,
                            tskIDLE_PRIORITY + 1,
                            &CliUDPTaskHandle);
                    if (xReturned == pdPASS)
                    {
                        PRINT("UDP server started");
                    }
                    else
                    {
                        ERROR("UDP server start failed");
                    }
                }
                else
                {
                    vTaskResume(CliUDPTaskHandle);
                    PRINT("UDP server started");

                }
                crntState = ETH_STATE_SERVER_RUNNING;
            }
        }
        else if (crntState == ETH_STATE_INACTIVE)
        {
            ERROR("Server not started");
        }
        else if (crntState == ETH_STATE_SERVER_RUNNING)
        {
            ERROR("Server already running");
        }
        else
        {
            ERROR("Invalid operation");
        }
    }
    else if (reqstate == ETH_STATE_SERVER_STOP)
    {
        PRINT("Stopping the server");

        if (crntState == ETH_STATE_SERVER_RUNNING)
        {
            if (ethHndlr.connType == ETH_TCP)
            {
                vTaskSuspend(CliTCPTaskHandle);
                isTCPRunning = pdFALSE;
                crntState = ETH_STATE_CONFIG_DONE;
            }
            else if (ethHndlr.connType == ETH_UDP)
            {
                vTaskSuspend(CliUDPTaskHandle);
                crntState = ETH_STATE_CONFIG_DONE;
            }
        }
        else
        {
            ERROR("No server running to stop");
        }
    }
}

/**
 * @func : cmd_eth
 * @brief : callback function to configure and run tcp/udp server
 */

BaseType_t cmd_eth( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void) write_buffer_len;
    char tempString[ 4 ] = { 0 };
    char *ipBuf;
    int udpPort;
    const char *parameter1;
    const char *parameter2;
    const char *parameter3;
    const char *parameter4;
    BaseType_t parameter1_str_len;
    BaseType_t parameter2_str_len;
    BaseType_t parameter3_str_len;
    BaseType_t parameter4_str_len;
    const char *start = "start";
    const char *config = "config";
    const char *send = "send";
    const char *stop = "stop";
    const char *tcp = "tcp";
    const char *udp = "udp";
    int ret;
    int port;
    uint32_t ip[4];
    char *space_pos = NULL;
    static struct freertos_sockaddr xClient;
    static socklen_t xClientLength = sizeof(xClient);

    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1,
            &parameter1_str_len);

    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
            &parameter2_str_len);

    strncpy(tempString, parameter1, parameter1_str_len);
    if (strncmp(parameter1, "help", 4) == 0)
    {
        printf("\r\nPerform ethernet operations"
                "\r\n\nIt supports the following sub commands:"
                "\r\n   eth config <IP address> <port>"
                "\r\n   eth config"
                "\r\n   eth start <IP protocol> <client IP> <client port>"
                "\r\n   eth send <data>"
                "\r\n   eth stop"
                "\r\n\n Typical usage:\n"
                "\r\n- Use eth config to configure IP address and port"
                "\r\n- Use eth start to establish a TCP/UDP server."
                "\r\n- Use eth stop to stop the server."
                "\r\n\nFor help on the specific commands do:"
                "\r\n  eth <command> help\r\n"
                );

        return pdFALSE;
    }
    else if (strncmp(parameter2, "help", 4) == 0)
    {
        if (strncmp(parameter1,"config",6) == 0)
        {
            printf("\r\nConfig ethernet IP Address"
                    "\r\n\nUsage:"
                    "\r\n  eth config <IP address> <port>"
                    "\r\n  It does not require arguments if it is to be configured as DHCP"
                    "\r\n\nIt requires the following arguments if it is to be configured as static:"
                    "\r\n  IP address  IP address"
                    "\r\n  port        port for communication"
                    );
        }
        else if (strncmp(parameter1,"start",5) == 0)
        {
            printf("\r\nStart server over TCP/UDP protocol"
                    "\r\n\nUsage:"
                    "\r\n  eth start <IP Protocol> <IP address> <port>"
                    "\r\n\nIt requires following argument if the server to be over TCP protocol"
                    "\r\n  IP Protcol  protocol for communication"
                    "\r\n\nIt requires the following arguments if the server to be over UDP protocol:"
                    "\r\n  IP Protcol  protocol for communication (tcp for TCP/udp for UDP)"
                    "\r\n  IP address  client IP address"
                    "\r\n  port        client port for communication"
                    );
        }
        else if (strncmp(parameter1,"send",4) == 0)
        {
            printf("\r\nsend messages over TCP/UDP protocol"
                    "\r\n\nUsage:"
                    "\r\n  eth send <Message>"
                    "\r\n\nIt requires the following argument:"
                    "\r\n  Message     Message to be send"
                    );
        }
        else if (strncmp(parameter1,"stop",4) == 0)
        {
            printf("\r\nStop server over TCP/UDP protocol"
                    "\r\n\nUsage:"
                    "\r\neth stop"
                    );
        }
        else
        {
            ERROR("Wrong parameter.");
        }
        return pdFALSE;
    }

    if (strcmp(tempString, config) == 0)
    {
        parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
                &parameter2_str_len);
        if (parameter2_str_len < MIN_IP_LEN)
        {
            ethHndlr.ipPort = PORT_NUM;
            ethHndlr.connType = ETH_RAW;
            DHCPIsEnabled = pdTRUE;
            eth_sm(ETH_STATE_DO_CONFIG);
        }
        else
        {
            parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                    &parameter3_str_len);
            if (parameter3 == NULL)
            {
                ERROR("Invalid arguments for eth config");
                return pdFAIL;
            }
            ret = cli_get_decimal("eth  config","port", parameter3, 0, 65535,
                    (uint32_t *)&port);
            if (ret != 0)
            {
                return pdFAIL;
            }

            space_pos = strchr(parameter2, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            ret = cli_is_valid_ip(parameter2);
            if (ret != 0)
            {
                ERROR("Invalid parameter  for parameter = IP address");
                return pdFAIL;
            }
            sscanf(parameter2, "%d.%d.%d.%d", (int*) &ethHndlr.ipAddr[ 0 ],
                    (int*) &ethHndlr.ipAddr[ 1 ], (int*) &ethHndlr.ipAddr[ 2 ],
                    (int*) &ethHndlr.ipAddr[ 3 ]);
            ethHndlr.ipPort = port;
            ethHndlr.connType = ETH_RAW;
            DHCPIsEnabled = pdFALSE;
            eth_sm(ETH_STATE_DO_CONFIG);
        }
    }
    else if (strcmp(tempString, start) == 0)
    {

        parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
                &parameter2_str_len);
        memset(tempString, 0, sizeof(tempString));
        strncpy(tempString, parameter2, parameter2_str_len);
        if (strcmp(tempString, tcp) == 0)
        {
            ethHndlr.connType = ETH_TCP;
            eth_sm(ETH_STATE_SERVER_START);
        }
        else if (strcmp(tempString, udp) == 0)
        {
            parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                    &parameter3_str_len);
            parameter4 = FreeRTOS_CLIGetParameter(command_string, 4,
                    &parameter4_str_len);
            if ((parameter3_str_len < MIN_IP_LEN) ||
                    (parameter4_str_len < MIN_PORT_LEN))
            {
                ERROR("Add port and IP address of client");
                return pdFALSE;
            }
            space_pos = strchr(parameter3, ' ');
            if (space_pos != NULL)
            {
                *space_pos = '\0';
            }
            ret = cli_is_valid_ip(parameter3);
            if (ret != 0)
            {
                ERROR("Invalid parameter  for parameter = IP address");
                return pdFAIL;
            }
            ipBuf = (char*)malloc(parameter3_str_len + 1);
            strncpy(ipBuf, parameter3, parameter3_str_len);
            ret =
                    cli_get_decimal("eth start","port", parameter4, 0, 65535,
                    (uint32_t *)&port);
            if (ret != 0)
            {
                return pdFAIL;
            }
            udpPort = (int)port;
            memset( &xClient, 0, sizeof(xClient) );
            sscanf(ipBuf, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
            xClient.sin_address.ulIP_IPv4 = FreeRTOS_inet_addr_quick( ip[0], ip[1], ip[2],ip[3] );
            xClient.sin_port = FreeRTOS_htons(udpPort);
            xClient.sin_family = FREERTOS_AF_INET;
            free(ipBuf);
            ethHndlr.connType = ETH_UDP;
            eth_sm(ETH_STATE_SERVER_START);
        }
        else
        {
            ERROR("Invalid arguments");
        }
    }
    else if (strcmp(tempString, send) == 0)
    {
        parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
                &parameter2_str_len);
        if (parameter2 == NULL)
        {
            PRINT("Invalid arguments for eth send");
            return pdFAIL;
        }
        if ((CliTCPTaskHandle != NULL) && (isTCPRunning))
        {
            /* Send message to the client */
            vTaskSuspend(CliTCPTaskHandle);
            FreeRTOS_send(xTcpConnectedSocket, parameter2,
                    strlen((char*) parameter2), 0);
            PRINT("Initiated send command");
            vTaskResume(CliTCPTaskHandle);
        }
        else if (CliUDPTaskHandle != NULL)
        {
            vTaskSuspend(CliUDPTaskHandle);
            FreeRTOS_sendto(xUdpListeningSocket, parameter2,
                    strlen((char*) parameter2), 0, &xClient, xClientLength);
            vTaskResume(CliUDPTaskHandle);

            PRINT("Initiated send command");
        }
        else
        {
            ERROR("No server running.");
        }
    }
    else if (strcmp(tempString, stop) == 0)
    {
        if ((CliTCPTaskHandle != NULL) && (isTCPRunning))
        {
            ethHndlr.connType = ETH_TCP;
            eth_sm(ETH_STATE_SERVER_STOP);
        }
        else if (CliUDPTaskHandle != NULL)
        {
            ethHndlr.connType = ETH_UDP;
            eth_sm(ETH_STATE_SERVER_STOP);
        }
        else
        {
            ERROR("No server running.");
        }
    }
    else
    {
        strncpy(write_buffer, "Invalid  command", strlen("Invalid  command "));
        return pdFAIL;
    }
    return pdFALSE;
}

void vCliTCPServerTask( void *pvParameters )
{
    (void) pvParameters;
    struct freertos_sockaddr xServerAddress, xClientAddress;
    socklen_t xClientSize = sizeof(xClientAddress);
    static const TickType_t receive_timeout = portMAX_DELAY;
    BaseType_t xReceivedBytes = 0;
    const BaseType_t xBacklog = 20;
    /* Create the TCP socket */
    xTcpListeningSocket = FreeRTOS_socket(FREERTOS_AF_INET,
            FREERTOS_SOCK_STREAM, FREERTOS_IPPROTO_TCP);

    /* Check the socket was created. */
    configASSERT(xTcpListeningSocket != FREERTOS_INVALID_SOCKET);
    FreeRTOS_setsockopt(xTcpListeningSocket, 0, FREERTOS_SO_RCVTIMEO,
            &receive_timeout, sizeof(receive_timeout));

    /* Bind the socket to port */
    xServerAddress.sin_port = FreeRTOS_htons(ethHndlr.ipPort);
    xServerAddress.sin_family = FREERTOS_AF_INET; /* FREERTOS_AF_INET6 to be used for IPv6 */
    xServerAddress.sin_address.ulIP_IPv4 = FreeRTOS_GetIPAddress();
    FreeRTOS_bind(xTcpListeningSocket, &xServerAddress, sizeof(xServerAddress));

    /* Listen for incoming connections */
    FreeRTOS_listen(xTcpListeningSocket, xBacklog);

    for (;;)
    {
        /* Accept a new connection */
        xTcpConnectedSocket = FreeRTOS_accept(xTcpListeningSocket,
                &xClientAddress, &xClientSize);
        if (xTcpConnectedSocket == FREERTOS_INVALID_SOCKET)
        {
            ERROR("Unable to create socket.");
        }
        if (xTcpConnectedSocket != FREERTOS_INVALID_SOCKET)
        {
            PRINT("Client connected");
            while (1)
            {
                /* Receive data from the client */
                xReceivedBytes = FreeRTOS_recv(xTcpConnectedSocket, ucRxBuffer,
                        sizeof(ucRxBuffer), 0);

                if (xReceivedBytes > 0)
                {
                    ucRxBuffer[ xReceivedBytes ] = '\0';
                    /* Data was received, process it here. */
                    PRINT("%lu bytes received from client: %s",
                            xReceivedBytes, ucRxBuffer);
                }
                else if (xReceivedBytes == 0)
                {
                    /* No data was received, but FreeRTOS\_recv() did not return an error.
                       Timeout? */
                    PRINT("Client disconnected");
                }
                else
                {
                    break;
                }
            }
            /* Shutdown is complete, close the socket safely */
        }
    }
}

void vCliUDPServerTask( void *pvParameters )
{
    (void) pvParameters;
    struct freertos_sockaddr xBindAddress, xClient;
    socklen_t xClientLength = sizeof(xClient);
    const TickType_t xSendTimeOut = 200 / portTICK_PERIOD_MS;
    int32_t lReceivedBytes;

    /* Create the UDP socket */
    xUdpListeningSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_DGRAM,
            FREERTOS_IPPROTO_UDP);

    /* Check for errors. */
    configASSERT(xUdpListeningSocket != FREERTOS_INVALID_SOCKET);

    /* Ensure calls to FreeRTOS\_sendto() timeout if a network buffer cannot be
     * obtained within 200ms.
     */
    FreeRTOS_setsockopt(xUdpListeningSocket, 0, FREERTOS_SO_SNDTIMEO,
            &xSendTimeOut, sizeof(xSendTimeOut));

    memset(&xBindAddress, 0, sizeof(xBindAddress));

    xBindAddress.sin_port = FreeRTOS_htons(ethHndlr.ipPort);
    xBindAddress.sin_family = FREERTOS_AF_INET; /* FREERTOS_AF_INET6 to be used for IPv6 */
    FreeRTOS_bind(xUdpListeningSocket, &xBindAddress, sizeof(xBindAddress));

    for ( ;;)
    {

        /* Receive data from the client */
        lReceivedBytes = FreeRTOS_recvfrom(xUdpListeningSocket, ucRxBuffer,
                sizeof(ucRxBuffer), 0, &xClient, &xClientLength);

        if (lReceivedBytes > 0)
        {
            ucRxBuffer[ lReceivedBytes ] = '\0';
            PRINT("%d bytes received from client: %s",
                    lReceivedBytes, ucRxBuffer);
        }
    }
}

/*
 * @brief calls when network connects or disconnects
 */

void vApplicationIPNetworkEventHook_Multi( eIPCallbackEvent_t eNetworkEvent,
        struct xNetworkEndPoint *pxEndPoint )
{

    /* Check this was a network up event, as opposed to a network down event. */
    if (eNetworkEvent == eNetworkUp)
    {

        /* Network is up, application tasks can start */
        uint32_t pulIPAddress, pulNetMask, pulGatewayAddress,
                pulDNSServerAddress;


        if ((pxEndPoint->bits.bIPv6 == 0) &&
                (pxEndPoint->bits.bEndPointUp == 1))
        {
            FreeRTOS_GetEndPointConfiguration( &pulIPAddress, &pulNetMask,
                    &pulGatewayAddress, &pulDNSServerAddress, pxEndPoint );

            printf("\r\nIPv4 Network interface test is up");

            FreeRTOS_inet_ntoa(pulIPAddress, (char *)ucBuffer);
            printf("\r\nIPv4 Address: %s", ucBuffer);

            FreeRTOS_inet_ntoa(pulNetMask, (char *)ucBuffer);
            printf("\r\nIPv4 Subnet Mask: %s", ucBuffer);

            FreeRTOS_inet_ntoa(pulGatewayAddress, (char *)ucBuffer);
            printf("\r\nIPv4 Gateway Address: %s", ucBuffer);

            FreeRTOS_inet_ntoa(pulDNSServerAddress, (char *)ucBuffer);
            printf("\r\nIPv4 DNS Server Address: %s", ucBuffer);
        }
        else if ((pxEndPoint->bits.bIPv6 == 1) &&
                (pxEndPoint->bits.bEndPointUp == 1))
        {
            printf("\r\nIPv6 Network interface is up");

            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xIPAddress.ucBytes,
                    ipv6_addr, 40);
            printf("\r\nIPv6 Address: %s", ipv6_addr);

            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xPrefix.ucBytes,
                    ipv6_prefix, 40);
            printf("\r\nIPv6 Prefix: %s", ipv6_prefix);

            FreeRTOS_inet_ntop6(
                    pxEndPoint->ipv6_settings.xGatewayAddress.ucBytes,
                    ipv6_gateway_addr, 40);
            printf("\r\nIPv6 Gateway Address: %s", ipv6_gateway_addr);

            FreeRTOS_inet_ntop6(
                    pxEndPoint->ipv6_settings.xDNSServerAddresses[0].ucBytes,
                    ipv6_dns_server_addr, 40);
            printf("\r\nIPv6 DNS Server Address: %s", ipv6_dns_server_addr);
        }
    }
}

uint32_t ulApplicationGetNextSequenceNumber( uint32_t ulSourceAddress,
        uint16_t usSourcePort, uint32_t ulDestinationAddress,
        uint16_t usDestinationPort )
{
    uint32_t ulReturn;
    uint32_t ulRandomNumber;
    ulReturn = ulSourceAddress ^ ulDestinationAddress;
    ulReturn += (uint32_t) usSourcePort + (uint32_t) usDestinationPort;
    if (xApplicationGetRandomNumber(&ulRandomNumber) == pdPASS)
        ulReturn ^= ulRandomNumber;

    return ulRandomNumber;
}

BaseType_t xApplicationGetRandomNumber( uint32_t *pulNumber )
{
    if (pulNumber == NULL)
        return pdFAIL;

    *pulNumber = (uint32_t) rand();

    return pdPASS;

}

const char*pcApplicationHostnameHook( void )
{
    return "AGLEX5_device";
}

/*
 * @brief function to meet stack dependency
 */
void vApplicationPingReplyHook( ePingReplyStatus_t eStatus,
        uint16_t usIdentifier )
{
    (void) eStatus;
    (void) usIdentifier;
}

eDHCPCallbackAnswer_t xApplicationDHCPHook_Multi(
        eDHCPCallbackPhase_t eDHCPPhase,
        struct xNetworkEndPoint *pxEndPoint,
        IP_Address_t *pxIPAddress )
{
    /*INFO:Not significant for the sample*/
    (void)eDHCPPhase;
    (void)pxEndPoint;
    (void)pxIPAddress;
    return eDHCPContinue;
}

uint32_t ulApplicationTimeHook( void )
{
    return xTaskGetTickCount() * portTICK_PERIOD_MS;
}
