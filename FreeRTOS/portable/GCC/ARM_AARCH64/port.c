/*
 * FreeRTOS Kernel V10.5.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Copyright (c) 2025-2026 Altera Corporation.
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
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <string.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "arm_gic_reg.h"
#include "socfpga_interrupt.h"
#ifndef configINTERRUPT_CONTROLLER_BASE_ADDRESS
    #error configINTERRUPT_CONTROLLER_BASE_ADDRESS must be defined.  See https: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET
    #error configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET must be defined.  See https: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configUNIQUE_INTERRUPT_PRIORITIES
    #error configUNIQUE_INTERRUPT_PRIORITIES must be defined.  See https: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configMAX_API_CALL_INTERRUPT_PRIORITY
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be defined.  See https: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#if configMAX_API_CALL_INTERRUPT_PRIORITY == 0
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must not be set to 0
#endif

#if configMAX_API_CALL_INTERRUPT_PRIORITY > configUNIQUE_INTERRUPT_PRIORITIES
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be less than or equal to configUNIQUE_INTERRUPT_PRIORITIES as the lower the numeric priority value the higher the logical interrupt priority
#endif

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1
    /* Check the configuration. */
    #if ( configMAX_PRIORITIES > 32 )
        #error configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
    #endif
#endif /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

/* In case security extensions are implemented. */
#if configMAX_API_CALL_INTERRUPT_PRIORITY <= ( configUNIQUE_INTERRUPT_PRIORITIES / 2 )
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be greater than ( configUNIQUE_INTERRUPT_PRIORITIES / 2 )
#endif

/* Some vendor specific files default configCLEAR_TICK_INTERRUPT() in
   portmacro.h. */
#ifndef configCLEAR_TICK_INTERRUPT
    #define configCLEAR_TICK_INTERRUPT()
#endif

/* A critical section is exited when the critical section nesting count reaches
   this value. */
#define portNO_CRITICAL_NESTING          ( ( size_t ) 0 )

/* In all GICs 255 can be written to the priority mask register to unmask all
   (but the lowest) interrupt priority. */

/* Tasks are not created with a floating point context, but can be given a
   floating point context after they have been created.  A variable is stored as
   part of the tasks context that holds portNO_FLOATING_POINT_CONTEXT if the task
   does not have an FPU context, or any other value if the task does have an FPU
   context. */
#define portNO_FLOATING_POINT_CONTEXT    ( ( StackType_t ) 0 )

/* Constants required to setup the initial task context. */
#define portSP_ELx                       ( ( StackType_t ) 0x01 )
#define portSP_EL0                       ( ( StackType_t ) 0x00 )

#define portEL1                          ( ( StackType_t ) 0x04 )
#define portINITIAL_PSTATE               ( portEL1 | portSP_EL0 )
#define portMAX_PRIORITY_VALUE           ( 15U )

/* Used by portASSERT_IF_INTERRUPT_PRIORITY_INVALID() when ensuring the binary
 * point is zero. */
#define portBINARY_POINT_BITS            ( ( uint8_t ) 0x03 )

/* Masks all bits in the APSR other than the mode bits. */
#define portAPSR_MODE_BITS_MASK          ( 0x0C )

/* The I bit in the DAIF bits. */
#define portDAIF_I                       ( 0x80 )

/* The space required to hold the FPU registers. There are 32 128 bit registers.
   So total of 512bytes are present. Hence 64 ( 64*8 ) double words. */
#define portFPU_REGISTER_WORDS    ( 64 )

/* Macro to unmask all interrupt priorities. */
#define portCLEAR_INTERRUPTS() vPortClearInterruptMask( pdFALSE )

/* Hardware specifics used when sanity checking the configuration. */
/* #define portINTERRUPT_PRIORITY_REGISTER_OFFSET       0x400UL */
#define portINTERRUPT_PRIORITY_REGISTER_OFFSET    0x4UL
#define portMAX_8_BIT_VALUE                       ( ( uint8_t ) 0xff )
#define portBIT_0_SET                             ( ( uint8_t ) 0x01 )

/* Mask for generating SGI */
/* Only the core values is passed along with the mask as target list */
#define ICC_SGI_TARGET_MASK                       ( 0xFF00FF00FF0000ULL )
/*-----------------------------------------------------------*/
/*
 * Starts the first task executing.  This function is necessarily written in
 * assembly code so is implemented in portASM.s.
 */
extern void vPortRestoreTaskContext( void );

/*
 * Boot process for secondary cores in SMP. This function is also written in
 * assembly and implemented in cpu_init.S
 */
extern void _secondary_boot( void );
/*-----------------------------------------------------------*/

/* A variable is used to keep track of the critical section nesting.  This
 * variable has to be stored as part of the task context and must be initialised to
 * a non zero value to ensure interrupts don't inadvertently become unmasked before
 * the scheduler starts.  As it is stored as part of the task context it will
 * automatically be set to 0 when the first task is started. */
volatile uint64_t ullCriticalNesting[ configNUMBER_OF_CORES ] = {
    [0 ... ( configNUMBER_OF_CORES - 1 )] = 0
};

/* Saved as part of the task context.  If ullPortTaskHasFPUContext is non-zero
 * then floating point context must be saved and restored for the task. */
uint64_t ullPortTaskHasFPUContext[ configNUMBER_OF_CORES ] = {
    [0 ... ( configNUMBER_OF_CORES - 1 )] = 0
};

/* Set to 1 to pend a context switch from an ISR. */
uint64_t ullPortYieldRequired[ configNUMBER_OF_CORES ] = {
    [0 ... ( configNUMBER_OF_CORES - 1 )] = pdFALSE
};

/* Counts the interrupt nesting depth.  A context switch is only performed if
 * if the nesting depth is 0. */
uint64_t ullPortInterruptNesting[ configNUMBER_OF_CORES ] = {
    [0 ... ( configNUMBER_OF_CORES - 1 )] = 0
};

SpinLock_t xSpinLocks[PORT_SPIN_LOCK_COUNT] =
{
    [0 ... ( PORT_SPIN_LOCK_COUNT - 1 )] = { .ulOwnerId = 0xFFFFFFFF }
};

static BaseType_t xCoreReady[ configNUMBER_OF_CORES ] = { pdFALSE };

static BaseType_t xSchedulerStarted = pdFALSE;

/* Variable to store the boot core affinity. */
static uint32_t ulBootCoreId = 0U;

/* Initializing the MPIDR array based on the number of cores
   the user has enabled */
__attribute__( ( used ) ) const uint32_t ulCoreMpidrList[ configNUMBER_OF_CORES ] =
{
#if ( configSMP_CORE0_ENABLE > 0 )
    ( uint32_t ) configSMP_CORE0_MPIDR,
#endif
#if ( configSMP_CORE1_ENABLE > 0 )
    ( uint32_t ) configSMP_CORE1_MPIDR,
#endif
#if ( configSMP_CORE2_ENABLE > 0 )
    ( uint32_t ) configSMP_CORE2_MPIDR,
#endif
#if ( configSMP_CORE3_ENABLE > 0 )
    ( uint32_t ) configSMP_CORE3_MPIDR,
#endif
};

/* Used in the ASM code. */
__attribute__( ( used ) ) const uint64_t ullICCEOIR = portICCEOIR_END_OF_INTERRUPT_REGISTER_ADDRESS;
__attribute__( ( used ) ) const uint64_t ullICCIAR = portICCIAR_INTERRUPT_ACKNOWLEDGE_REGISTER_ADDRESS;
__attribute__( ( used ) ) const uint64_t ullICCPMR = portICCPMR_PRIORITY_MASK_REGISTER_ADDRESS;
__attribute__( ( used ) ) const uint64_t ullMaxAPIPriorityMask = ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );

/*-----------------------------------------------------------*/

BaseType_t xPortStartSchedulerOnCore( void );

static void vCoreInit( uint32_t ulCoreId, void *pvEntryPoint );
void vCoreYield( void *pvParam );

uint32_t ulRawReadICC_RPR_EL1( void )
{
uint32_t rpr = 0;

    __asm__ __volatile__ ( "mrs %0, ICC_RPR_EL1\n\t" : "=r" ( rpr ) :  : "memory" );
    return rpr;
}
/*-----------------------------------------------------------*/

uint32_t ulRawReadICC_BPR1_EL1( void )
{
uint32_t bpr = 0;

    __asm__ __volatile__ ( "mrs %0, ICC_BPR1_EL1\n\t" : "=r" ( bpr ) :  : "memory" );
    return bpr;
}
/*-----------------------------------------------------------*/

void ulRawWriteICC_PMR_EL1( uint32_t pmr )
{
    __asm__ __volatile__ ( "msr ICC_PMR_EL1, %0\n\t" : : "r" ( pmr ) : "memory" );
}
/*-----------------------------------------------------------*/

uint32_t ulRawReadICC_PMR_EL1( void )
{
uint32_t pmr = 0;

    __asm__ __volatile__ ( "mrs %0, ICC_PMR_EL1\n\t" : "=r" ( pmr ) :  : "memory" );
    return pmr;
}
/*-----------------------------------------------------------*/

uint32_t ulRawReadSPsel( void )
{
uint32_t ulCurMode = 0;

    __asm__ __volatile__ ( "mrs %0, SPSel\n\t" : "=r" ( ulCurMode ) : : "memory" );
    ulCurMode &= 0x01;

    return ulCurMode;
}
/*-----------------------------------------------------------*/

/* See header file for description. */
StackType_t * pxPortInitialiseStack( StackType_t * pxTopOfStack,
                                     TaskFunction_t pxCode,
                                     void * pvParameters )
{
    configASSERT( pxTopOfStack != NULL );
    configASSERT( pxCode != NULL );

    /* Setup the initial stack of the task.  The stack is set exactly as
     * expected by the portRESTORE_CONTEXT() macro. */

    /* First all the general purpose registers. */
    pxTopOfStack--;
    *pxTopOfStack = 0x0101010101010101ULL;        /* X1 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) pvParameters; /* X0 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0303030303030303ULL;        /* X3 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0202020202020202ULL;        /* X2 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0505050505050505ULL;        /* X5 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0404040404040404ULL;        /* X4 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0707070707070707ULL;        /* X7 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0606060606060606ULL;        /* X6 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0909090909090909ULL;        /* X9 */
    pxTopOfStack--;
    *pxTopOfStack = 0x0808080808080808ULL;        /* X8 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1111111111111111ULL;        /* X11 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1010101010101010ULL;        /* X10 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1313131313131313ULL;        /* X13 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1212121212121212ULL;        /* X12 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1515151515151515ULL;        /* X15 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1414141414141414ULL;        /* X14 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1717171717171717ULL;        /* X17 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1616161616161616ULL;        /* X16 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1919191919191919ULL;        /* X19 */
    pxTopOfStack--;
    *pxTopOfStack = 0x1818181818181818ULL;        /* X18 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2121212121212121ULL;        /* X21 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2020202020202020ULL;        /* X20 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2323232323232323ULL;        /* X23 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2222222222222222ULL;        /* X22 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2525252525252525ULL;        /* X25 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2424242424242424ULL;        /* X24 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2727272727272727ULL;        /* X27 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2626262626262626ULL;        /* X26 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2929292929292929ULL;        /* X29 */
    pxTopOfStack--;
    *pxTopOfStack = 0x2828282828282828ULL;        /* X28 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x00;         /* XZR - has no effect, used so there are an even number of registers. */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x00;         /* X30 - procedure call link register. */
    pxTopOfStack--;

    *pxTopOfStack = portINITIAL_PSTATE;
    pxTopOfStack--;

    *pxTopOfStack = ( StackType_t ) pxCode; /* Exception return address. */

    #if( configUSE_TASK_FPU_SUPPORT == 1 )
    {
        pxTopOfStack -= portFPU_REGISTER_WORDS;
        memset( pxTopOfStack, 0x00, portFPU_REGISTER_WORDS * sizeof( StackType_t ) );

        /* The task will start with a critical nesting count of 0 as interrupts are
         * enabled. */
        pxTopOfStack--;
        *pxTopOfStack = portNO_CRITICAL_NESTING;

        pxTopOfStack--;
        *pxTopOfStack = pdTRUE;
        ullPortTaskHasFPUContext[ ulGetCoreId() ] = pdTRUE;
    }
    #else
        /* The task will start with a critical nesting count of 0 as interrupts are
         * enabled. */
        pxTopOfStack--;
        *pxTopOfStack = portNO_CRITICAL_NESTING;

        /* The task will start without a floating point context.  A task that uses
         * the floating point hardware must call vPortTaskUsesFPU() before executing
         * any floating point instructions. */
        pxTopOfStack--;
        *pxTopOfStack = portNO_FLOATING_POINT_CONTEXT;
    #endif

    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler( void )
{
uint32_t ulCoreId = 0U;
uint32_t ulAPSR = 0U;
uint32_t ulCoreIndex = 0U;
uint32_t ulSpinLockIndex = 0U;
volatile uint32_t ulDelayIndex = 0U;

    #if ( configASSERT_DEFINED == 1 )
    {
        /* Max value possible for priority */
        configASSERT( portMAX_PRIORITY_VALUE >= portLOWEST_INTERRUPT_PRIORITY );
    }
    #endif /* configASSERT_DEFINED */

    /* Disable interrupts to prevent interrupts before scheduler starts */
    portDISABLE_INTERRUPTS();

    ulBootCoreId = ulGetCoreId();

    for( ulSpinLockIndex = 0U; ulSpinLockIndex < PORT_SPIN_LOCK_COUNT; ulSpinLockIndex++ )
    {
        xSpinLocks[ ulSpinLockIndex ].ulOwnerId = 0xFFFFFFFF;
    }
    __asm volatile ( "MRS %0, CurrentEL" : "=r" ( ulAPSR ) );
    ulAPSR &= portAPSR_MODE_BITS_MASK;

    configASSERT( ulAPSR == portEL1 );

    /* Continue only if the binary point value is set to its lowest possible
     * setting.  See the comments in vPortValidateInterruptPriority() below for
     * more information. */
    configASSERT( ( ulRawReadICC_BPR1_EL1() & portBINARY_POINT_BITS ) <= portMAX_BINARY_POINT_VALUE );

    /* Initialize the secondary cores */
    for( ulCoreIndex = 0U; ulCoreIndex < configNUMBER_OF_CORES; ulCoreIndex++ )
    {
        if( ulCoreIndex == ulBootCoreId )
        {
            continue;
        }
        /* Core ids are in multiples of 256, we start initialising cores
         * that are after the boot core. If the boot core is 2 and the number
         * of cores is 2, cores will start the scheduler in 2->3 order.
         */
        ulCoreId = ( uint32_t ) ulCoreMpidrList[ ulCoreIndex ];
        vCoreInit( ulCoreId, _secondary_boot );

        /* Once the core is up, it uses FreeRTOS indexing */
        while( xCoreReady[ ulCoreIndex ] != pdTRUE )
        {
            /* Wait for the core to set the corresponding index as ready */
            for( ulDelayIndex = 0U; ulDelayIndex < 1000U; ulDelayIndex++ )
            {
                __asm__ volatile( "nop" );
            }
            __asm__ volatile( "dmb sy" ::: "memory" );
        }
    }
    xPortStartSchedulerOnCore();

    /* Should never reach here */
    return 0;
}
/*-----------------------------------------------------------*/

static void vCoreInit( uint32_t ulCoreId, void *pvEntryPoint )
{
    configASSERT( pvEntryPoint != NULL );

    __asm__ volatile (
        "LDR    X0,=0xC4000003\n"
        "MOV    X1, %0\n"
        "MOV    X2, %1\n"
        "MOV    X3, XZR\n"
        "SMC    #0\n"
        :
        : "r"(ulCoreId), "r"(pvEntryPoint)
        : "x0","x1","x2","x3","memory"
    );
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

void __attribute__(( used )) vCoreEntry( void )
{
volatile uint32_t ulDelayIndex = 0U;

    xCoreReady[ ulGetCoreId() ] = pdTRUE;

    /* GIC is initialized before the scheduler starts. Here we enable the
       redistributor of the current core. */
    interrupt_enable_core_redis();

    while( xSchedulerStarted != pdTRUE )
    {
        /* Wait for the boot core to start the scheduler. */
        for( ulDelayIndex = 0U; ulDelayIndex < 1000U; ulDelayIndex++ )
        {
            __asm__ volatile( "nop" );
        }
        __asm__ volatile( "dmb sy" ::: "memory" );
    }
    /* Start the scheduler on the core */
    xPortStartSchedulerOnCore();
}
/*-----------------------------------------------------------*/

BaseType_t xPortStartSchedulerOnCore( void )
{
    /* Interrupts are turned off in the CPU itself to ensure a tick does
     * not execute while the scheduler is being started.  Interrupts are
     * automatically turned back on in the CPU when the first task starts
     * executing. */
    portDISABLE_INTERRUPTS();

    /* Register the core to core interrupt for yields.*/
    configASSERT( interrupt_register_isr(YIELD_CORE_INTR, vCoreYield,
            NULL ) == 0 );

    configASSERT( interrupt_enable( YIELD_CORE_INTR,
            ( configMAX_API_CALL_INTERRUPT_PRIORITY + 1 )) == 0 );

    if( ulGetCoreId() == ulBootCoreId )
    {
        /* Start the timer that generates the tick ISR. */
        #ifdef configSETUP_TICK_INTERRUPT
            configSETUP_TICK_INTERRUPT();
        #else
            vPortSocfpgaTimerInit();
        #endif
        /* Once the timer interrupt is setup, other cores can schedule tasks */
        xSchedulerStarted = pdTRUE;
        __asm__ volatile( "dmb sy" ::: "memory" );
    }

    /* Start the first task executing. */
    vPortRestoreTaskContext();

    /* Should never reach here */
    return 0;
}
/*-----------------------------------------------------------*/

uint32_t ulGetCoreId( void )
{
    #if ( configNUMBER_OF_CORES == 1 )
        return 0;
    #else
        uint64_t ullCoreAffinity = 0U;
        uint32_t ulCoreId = 0U;
        uint32_t ulIndex = 0U;

        __asm__ volatile ( "MRS %0, MPIDR_EL1" : "=r" ( ullCoreAffinity ) );
        ulCoreId = ( uint32_t ) ( ullCoreAffinity & 0xFF00U );

        for( ulIndex = 0; ulIndex < configNUMBER_OF_CORES; ulIndex++ )
        {
            if( ulCoreMpidrList[ ulIndex ] == ulCoreId )
            {
                return ulIndex;
            }
        }

        return 0;
    #endif
}

void vPortEndScheduler( void )
{
    /* Not implemented in ports where there is nothing to return to.
     * Artificially force an assert. */
    configASSERT( ullCriticalNesting[ ulGetCoreId() ] == 1000ULL );
}
/*-----------------------------------------------------------*/

#if configNUMBER_OF_CORES == 1
/* Index 0 used to indicate primary core */
void vPortEnterCritical( void )
{
    /* Mask interrupts up to the max syscall interrupt priority. */
    portDISABLE_INTERRUPTS();

    /* Now interrupts are disabled ullCriticalNesting can be accessed
     * directly.  Increment ullCriticalNesting to keep a count of how many times
     * portENTER_CRITICAL() has been called. */
    ullCriticalNesting[ 0 ]++;

    /* This is not the interrupt safe version of the enter critical function so
     * assert() if it is being called from an interrupt context.  Only API
     * functions that end in "FromISR" can be used in an interrupt.  Only assert if
     * the critical nesting count is 1 to protect against recursive calls if the
     * assert function also uses a critical section. */
    if( ullCriticalNesting[ 0 ] == 1ULL )
    {
        configASSERT( ullPortInterruptNesting[0] == 0 );
    }
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
    if( ullCriticalNesting[0] > portNO_CRITICAL_NESTING )
    {
        /* Decrement the nesting count as the critical section is being
         * exited. */
        ullCriticalNesting[0]--;

        /* If the nesting level has reached zero then all interrupt
         * priorities must be re-enabled. */
        if( ullCriticalNesting[0] == portNO_CRITICAL_NESTING )
        {
            /* Critical nesting has reached zero so all interrupt priorities
             * should be unmasked. */
            portENABLE_INTERRUPTS();
        }
    }
}
/*-----------------------------------------------------------*/
#endif

void FreeRTOS_Tick_Handler( void )
{
    /* Must be the lowest possible priority. */
    #if !defined( QEMU )
    {
        configASSERT( ulRawReadICC_RPR_EL1() >= ( uint32_t ) ( portLOWEST_USABLE_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) );
    }
    #endif

    /* Interrupts should not be enabled before this point. */
    #if ( configASSERT_DEFINED == 1 )
    {
    uint32_t ulMaskBits;

    __asm volatile ( "mrs %0, daif" : "=r" ( ulMaskBits )::"memory" );
        configASSERT( ( ulMaskBits & portDAIF_I ) != 0 );
    }
    #endif /* configASSERT_DEFINED */

    /* Set interrupt mask before altering scheduler structures.   The tick
     * handler runs at the lowest priority, so interrupts cannot already be masked,
     * so there is no need to save and restore the current mask value.  It is
     * necessary to turn off interrupts in the CPU itself while the ICCPMR is being
     * updated. */
    portDISABLE_INTERRUPTS();

    configCLEAR_TICK_INTERRUPT();

    /* Increment the RTOS tick. */
    #if configNUMBER_OF_CORES > 1
        /* We are still in the ISR for the Tick interrupt */
        /* The single core function already performs check to see
         * if its in ISR */
        BaseType_t xInterruptStatus;
        xInterruptStatus = portENTER_CRITICAL_FROM_ISR();
    #endif
    if( xTaskIncrementTick() != pdFALSE )
    {
        ullPortYieldRequired[ ulGetCoreId() ] = pdTRUE;
    }
    #if configNUMBER_OF_CORES > 1
        portEXIT_CRITICAL_FROM_ISR( xInterruptStatus );
    #endif
    /* Ensure all interrupt priorities are active again. */
    portENABLE_INTERRUPTS();
}
/*-----------------------------------------------------------*/

void vPortTaskUsesFPU( void )
{
    /* A task is registering the fact that it needs an FPU context.  Set the
     * FPU flag (which is saved as part of the task context). */
    ullPortTaskHasFPUContext[ ulGetCoreId() ] = pdTRUE;

    /* Consider initialising the FPSR here - but probably not necessary in
     * AArch64. */
}
/*-----------------------------------------------------------*/

#if ( configASSERT_DEFINED == 1 )

    void vPortValidateInterruptPriority( void )
    {
        /* The following assertion will fail if a service routine (ISR) for
         * an interrupt that has been assigned a priority above
         * configMAX_SYSCALL_INTERRUPT_PRIORITY calls an ISR safe FreeRTOS API
         * function.  ISR safe FreeRTOS API functions must *only* be called
         * from interrupts that have been assigned a priority at or below
         * configMAX_SYSCALL_INTERRUPT_PRIORITY.
         *
         * Numerically low interrupt priority numbers represent logically high
         * interrupt priorities, therefore the priority of the interrupt must
         * be set to a value equal to or numerically *higher* than
         * configMAX_SYSCALL_INTERRUPT_PRIORITY.
         *
         * FreeRTOS maintains separate thread and ISR API functions to ensure
         * interrupt entry is as fast and simple as possible. */
        configASSERT( ulRawReadICC_RPR_EL1() >= ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) );

        /* Priority grouping:  The interrupt controller (GIC) allows the bits
         * that define each interrupt's priority to be split between bits that
         * define the interrupt's pre-emption priority bits and bits that define
         * the interrupt's sub-priority.  For simplicity all bits must be defined
         * to be pre-emption priority bits.  The following assertion will fail if
         * this is not the case (if some bits represent a sub-priority).
         *
         * The priority grouping is configured by the GIC's binary point register
         * (ICCBPR).  Writting 0 to ICCBPR will ensure it is set to its lowest
         * possible value (which may be above 0). */
        configASSERT( ( ulRawReadICC_BPR1_EL1() & portBINARY_POINT_BITS ) <= portMAX_BINARY_POINT_VALUE );
    }
/*-----------------------------------------------------------*/


#endif /* configASSERT_DEFINED */
/*-----------------------------------------------------------*/
/* vApplicationIRQHandler() is just a normal C function. */
void vApplicationIRQHandler( uint32_t ulICCIAR )
{
    /* Nesting count should always be 0, else an interrupt pre-empted
     * a critical section, which should never happen. */
    configASSERT( ullCriticalNesting[ulGetCoreId()] == 0 );
    interrupt_irq_handler( ulICCIAR );
}
/*-----------------------------------------------------------*/
/* Callback function for core to core interrupt */
/*-----------------------------------------------------------*/

BaseType_t xPortIsInsideInterrupt( void )
{
BaseType_t xReturn = pdFALSE;

    /*Check the stackpointer in use to determine the mode
     * 0 - EL1t
     * 1 - EL1h
     * */
    if( xSchedulerStarted == pdTRUE )
    {
        if( ulRawReadSPsel() != 0U )
        {
            xReturn = pdTRUE;
        }
        else
        {
            xReturn = pdFALSE;
        }
    }
    return xReturn;
}
/*-----------------------------------------------------------*/

inline void vGetLock( uint32_t ulLockType, uint32_t ulCoreId )
{
SpinLock_t *pxLock = &xSpinLocks[ulLockType];

    configASSERT( ulLockType < PORT_SPIN_LOCK_COUNT );

    if (pxLock->ulOwnerId == ulCoreId)
    {
        pxLock->ulRecurCount++;
        return;
    }

    /* 1. Set w2 with new lock value
     * 2. Wait for lock to be 0
     * 3. Write new value for lock
     * 4. Check if write successful
     * 5. Repeat from 2 if any step failed */

    __asm__ __volatile__(
    "  sevl                \n"
    "  mov   w2, #1        \n"
    "1:wfe                 \n"
    "  ldaxr w1, [%0]      \n"
    "  cbnz  w1, 1b        \n"
    "  stxr  w3, w2, [%0]  \n"
    "  cbnz  w3, 1b        \n"
    "  dmb   sy            \n"
        :
        : "r" (&pxLock->ulLock)
        : "w1", "w2", "w3", "memory"
    );

    pxLock->ulOwnerId = ulCoreId;
    pxLock->ulRecurCount = 1;
}

inline int vReleaseLock( uint32_t ulLockType, uint32_t ulCoreId )
{
int lRet = 1;
SpinLock_t *pxLock = &xSpinLocks[ulLockType];

    if (pxLock->ulOwnerId != ulCoreId)
    {
        return lRet;
    }
    if (--pxLock->ulRecurCount > 0)
    {
        return pxLock->ulLock;
    }

    configASSERT( ulLockType < PORT_SPIN_LOCK_COUNT );

    /*
     * The lock is owned and not a recursive unlock, reset the
     * owner id before releasing the lock
     */
    pxLock->ulOwnerId = 0xFFFFFFFF;

    lRet = 0;
    __asm__ __volatile__(
        "dmb sy\n"
        "stlr wzr, [%0]\n"
        :
        : "r" (&pxLock->ulLock)
        : "memory");
    return lRet;
}

inline void vYieldCore( uint32_t ulCoreId )
{
uint64_t ulSgiTarget = 0;

    /* Core IDs used by FreeRTOS range from 0 -> (configNUMBER_OF_CORES - 1).
     * We take this core ID and map it to its corresponding MPIDR. */
    ulCoreId = ( uint32_t ) ulCoreMpidrList[ ulCoreId ];
    ulSgiTarget = ( ( ( uint64_t ) ulCoreId ) << 8 ) | ( 1 << 0 );

    /*Send SGI to target core, signalling it to yield */
    __asm__ volatile ("MSR ICC_SGI1R_EL1, %0\n\t" :: "r"(ulSgiTarget) : "memory");
    __asm__ volatile ("ISB SY\n\t");
}

void vCoreYield( void *pvParam )
{
    ( void ) pvParam;
    ullPortYieldRequired[ ulGetCoreId() ] = pdTRUE;
}
