/* iperf configurations */
#ifndef __IPERF_TASK_H__
#define __IPERF_TASK_H__

#include <FreeRTOSConfig.h>

#define ipconfigIPERF_PRIORITY_IPERF_TASK ( configMAX_PRIORITIES - 3 )

#define USE_IPERF                               1
//#define ipconfigIPERF_DOES_ECHO_UDP             0

#define ipconfigIPERF_VERSION                   3
#define ipconfigIPERF_STACK_SIZE_IPERF_TASK     (configMINIMAL_STACK_SIZE + 680)

#define ipconfigIPERF_TX_BUFSIZE                ( 256 * ipconfigTCP_MSS )
#define ipconfigIPERF_TX_WINSIZE                ( 128 )
#define ipconfigIPERF_RX_BUFSIZE                ( 256 * ipconfigTCP_MSS )
#define ipconfigIPERF_RX_WINSIZE                ( 128 )

/* The iperf module declares a character buffer to store its send data. */
#define ipconfigIPERF_RECV_BUFFER_SIZE          ( 16 * ipconfigTCP_MSS )

#define ipconfigIPERF_USE_ZERO_COPY 0

void vIPerfInstall( void );

#endif /* __IPERF_TASK_H__ */
