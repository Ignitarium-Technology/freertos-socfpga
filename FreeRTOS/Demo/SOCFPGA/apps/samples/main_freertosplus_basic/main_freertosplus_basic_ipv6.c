 /*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * IPV6 Sample application for SoC FPGA.
 */

#include "SocfpgaNetworkInterface.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IPv6.h"
#include "FreeRTOS_Routing.h"
#include "main_freertosplus_basic.h"

#define EMAC_INSTANCE_0    0
#define EMAC_INSTANCE_1    1
#define EMAC_INSTANCE_2    2

const IPv6_Address_t xIPAddress =
{ .ucBytes =
  { 0xfe, 0x80, 0,0,0,0,0,0, 0x02,0x12,0x34,0x56,0x78,0x90,0xab,
    0xcd } };
const IPv6_Address_t xPrefix    =
{ .ucBytes = { 0xfe, 0x80, 0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } };
const IPv6_Address_t xGateway   =
{ .ucBytes =
  { 0xfe, 0x80, 0,0,0,0,0,0, 0x13,0x75,0x83,0xe3,0x22,0x32,0x52,
    0xb9 } };
const IPv6_Address_t xDNS       =
{ .ucBytes =
  { 0xfe, 0x80, 0,0,0,0,0,0, 0x13,0x75,0x83,0xe3,0x22,0x32,0x52,
    0xb9 } };
static const uint8_t ucMAC[6] = { 0xAA, 0xDA, 0xAF, 0xB1, 0x6A, 0xC0 };

static const uint8_t ucIPAddress[4] = { 192, 168, 1, 6 };
static const uint8_t ucNetMask[4] = { 255, 255, 255, 0 };
static const uint8_t ucGateway[4] = { 192, 168, 1, 1 };
static const uint8_t ucDNSServer[ 4 ] = { 192, 168, 1, 1};

static NetworkInterface_t xInterfaces[ 2 ];
static NetworkEndPoint_t xEndPoints[ 2 ];


void setup_dhcp_demo()
{
    ( void ) pxFillInterfaceDescriptor( EMAC_INSTANCE_2 , &(xInterfaces[ 0 ]));

    FreeRTOS_FillEndPoint_IPv6( &(xInterfaces[ 0 ]),
            &(xEndPoints[ 1 ]),
            &xIPAddress,
            &xPrefix,
            64,
            &xGateway,
            &xDNS,
            ucMAC );

    xEndPoints[1].bits.bIPv6 = pdTRUE_UNSIGNED;

#if ((ipconfigUSE_DHCP != 0) && (ipconfigUSE_DHCPv6 != 0))
    {
        xEndPoints[ 1 ].bits.bWantDHCP = pdTRUE;
        xEndPoints[ 1 ].bits.bWantRA = 1;
    }
#endif
    FreeRTOS_FillEndPoint(
            &(xInterfaces[ 0 ]),
            &(xEndPoints[ 0 ]),
            ucIPAddress,
            ucNetMask,
            ucGateway,
            ucDNSServer,
            ucMAC );


    xEndPoints[ 0 ].bits.bIPv6 = pdFALSE_UNSIGNED;
#if (ipconfigUSE_DHCP != 0)
    {
        xEndPoints[ 0 ].bits.bWantDHCP = pdTRUE;
    }
#endif
    (void)FreeRTOS_IPInit_Multi();
}


void setup_static_demo()
{
    ( void ) pxFillInterfaceDescriptor( EMAC_INSTANCE_2, &(xInterfaces[ 0 ]));

    FreeRTOS_FillEndPoint_IPv6( &(xInterfaces[ 0 ]),
            &(xEndPoints[ 1 ]),
            &xIPAddress,
            &xPrefix,
            64,
            &xGateway,
            &xDNS,
            ucMAC );

    xEndPoints[1].bits.bIPv6 = pdTRUE_UNSIGNED;

    FreeRTOS_FillEndPoint(
            &(xInterfaces[ 0 ]),
            &(xEndPoints[ 0 ]),
            ucIPAddress,
            ucNetMask,
            ucGateway,
            ucDNSServer,
            ucMAC );

    xEndPoints[ 0 ].bits.bIPv6 = pdFALSE_UNSIGNED;
    (void)FreeRTOS_IPInit_Multi();
}

void vApplicationIPNetworkEventHook_Multi( eIPCallbackEvent_t eNetworkEvent,
        struct xNetworkEndPoint *pxEndPoint )
{
    char ipv6_addr[40];
    char ipv6_prefix[40];
    char ipv6_gateway_addr[40];
    char ipv6_dns_server_addr[40];

    uint8_t ucBuffer[NETWORK_BUFFER_SIZE];
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


            FreeRTOS_printf(("IPv4 Network interface is up\n"));
            FreeRTOS_inet_ntoa( pulIPAddress, (char *)ucBuffer );
            FreeRTOS_printf(("IPv4 Address: %s\n", ucBuffer));

            FreeRTOS_inet_ntoa( pulNetMask, (char *)ucBuffer );
            FreeRTOS_printf(("IPv4 Subnet Mask: %s\n", ucBuffer));

            FreeRTOS_inet_ntoa( pulGatewayAddress, (char *)ucBuffer );
            FreeRTOS_printf(("IPv4 Gateway Address: %s\n", ucBuffer));

            FreeRTOS_inet_ntoa( pulDNSServerAddress, (char *)ucBuffer );
            FreeRTOS_printf(("IPv4 DNS Server Address: %s\n", ucBuffer));
        }
        else if ((pxEndPoint->bits.bIPv6 == 1) &&
                (pxEndPoint->bits.bEndPointUp == 1))
        {
            FreeRTOS_printf(("IPv6 Network interface is up\n"));
            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xIPAddress.ucBytes,ipv6_addr,40);
            FreeRTOS_printf(("IPv6 Address: %s\n",ipv6_addr));

            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xPrefix.ucBytes,ipv6_prefix,40);
            FreeRTOS_printf(("IPv6 Prefix: %s\n",ipv6_prefix));

            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xGatewayAddress.ucBytes,ipv6_gateway_addr,40);
            FreeRTOS_printf(("IPv6 Gateway Address: %s\n",ipv6_gateway_addr));

            FreeRTOS_inet_ntop6(pxEndPoint->ipv6_settings.xDNSServerAddresses[0].ucBytes,ipv6_dns_server_addr,40);
            FreeRTOS_printf(("IPv6 DNS Server Address: %s\n",ipv6_dns_server_addr));
        }


#if DEMO_PING
        /* Notify to ping task to send ping request to server */
        xTaskNotifyGive(PingTaskHandle);
#endif
#if DEMO_TCP
        /* Notify to TCP task to initiate server and client communication */
        xTaskNotifyGive(TCPTaskHandle);
#endif
#if DEMO_UDP
        /* Notify to UDP task to initiate server and client communication */
        xTaskNotifyGive(UDPTaskHandle);
#endif
#if DEMO_ECHOTCP
        /* Notify to UDP task to initiate server and client communication */
        xTaskNotifyGive(EchoTCPServerTaskHandle);
#endif
    }

    else if (eNetworkEvent == eNetworkDown)
    {
        /* Network is down */
        printf("Network is Down\n");
    }
    else
    {
        printf("Unknown network event\n");
    }
}
const char *pcApplicationHostnameHook( void ){
    return "AGLEX5_device";
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

#if ipconfigIPv4_BACKWARD_COMPATIBLE
void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent )
{
    /*INFO:Not significant for the sample*/
    (void)eNetworkEvent;
}
#endif

eDHCPCallbackAnswer_t xApplicationDHCPHook( eDHCPCallbackPhase_t eDHCPPhase,
        uint32_t ulIPAddress )
{
    /*INFO:Not significant for the sample*/
    (void)eDHCPPhase;
    (void)ulIPAddress;
    return eDHCPContinue;
}

uint32_t ulApplicationTimeHook( void )
{
    return xTaskGetTickCount() * portTICK_PERIOD_MS;
}
