/*
 * SPDX-FileCopyrightText: Copyright (C) 2025-2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * A sample hello world application
 */

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "socfpga_console.h"
#include "socfpga_interrupt.h"
#include "portmacro.h"

static void setup_hardware( void )
{
    /* Initialize the GIC. */
    interrupt_init_gic();

    #if configENABLE_CONSOLE_UART
        /* Initialize the console uart*/
        console_init( configCONSOLE_UART_ID, "115200-8N1" );
    #endif
}
/*-----------------------------------------------------------*/

void run_hello_world( void *param )
{
uint32_t task_id = ( uint32_t ) ( uintptr_t ) param;
uint32_t core_id = ulGetCoreId();

    do
    {
        printf( "\n\rhello world %d, core_id: %d", task_id, core_id );
        vTaskDelay( pdMS_TO_TICKS( 500 ) );
    }while( 1 );
}
/*-----------------------------------------------------------*/

int main( void )
{
BaseType_t xReturn;
TaskHandle_t xTasks[ configNUMBER_OF_CORES ] = { 0 };
const char *task_names[] = {
    "hello_world",
    "hello_world_2",
    "hello_world_3",
    "hello_world_4"
};
uint32_t ulIndex = 0;

    setup_hardware();

    for( ulIndex = 0; ulIndex < configNUMBER_OF_CORES; ulIndex++ )
    {
        /* Create tasks based on number of enabled cores, pass the index as an
         * argument to distinguish between different tasks */
        xReturn = xTaskCreate( run_hello_world, task_names[ulIndex],
                configMINIMAL_STACK_SIZE * 2, ( void * ) ( uintptr_t ) ulIndex,
                configMAX_PRIORITIES - 1, &xTasks[ ulIndex ] );
        if( xReturn == pdPASS )
        {
            #if configNUMBER_OF_CORES > 1
                vTaskCoreAffinitySet( xTasks[ ulIndex ], ( 1U << ulIndex ) );
            #endif
        }
        else
        {
            break;
        }
    }

    if( ulIndex > 0 )
    {
        vTaskStartScheduler();
    }
    /* Should never reach here */
    return 0;
}
/*-----------------------------------------------------------*/


void vApplicationIdleHook( void )
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
     to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
     task.  It is essential that code added to this hook function never attempts
     to block in any way (for example, call xQueueReceive() with a block time
     specified, or call vTaskDelay()).  If the application makes use of the
     vTaskDelete() API function (as this demo application does) then it is also
     important that vApplicationIdleHook() is permitted to return to its calling
     function, because it is the responsibility of the idle task to clean up
     memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    /* This is called from RTOS tick handler
       Not used in this demo, But defined to keep the configuration sharing
       simple */
}
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
     configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
     function that will get called if a call to pvPortMalloc() fails.
     pvPortMalloc() is called internally by the kernel whenever a task, queue,
     timer or semaphore is created.  It is also called by various parts of the
     demo application.  If heap_1.c or heap_2.c are used, then the size of the
     heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
     FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
     to query the size of free heap space that remains (although it does not
     provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();

    for( ; ; )
    {
    }
}
/*-----------------------------------------------------------*/
