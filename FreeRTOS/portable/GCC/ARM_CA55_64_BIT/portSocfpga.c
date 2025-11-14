/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Port layer for FreeRTOS Kernel V10.5.1 for Agilex5 A55 processor
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

#include <socfpga_interrupt.h>

#define AGX5_CNTV_CTL_ENABLE            ( 1 << 0 )
#define TMR_DELAY_SECS                  ( 1 )
#define coretimerTIMER_INITIAL_VALUE    0
/*-----------------------------------------------------------*/

static uint64_t ullCounterFreq = 0;
static uint64_t ullCounterCurrVal = 0;
static uint64_t ullCounterReloadVal = 0;

/*-----------------------------------------------------------*/
static void vPortAgilex5A55SetVirtualTimerControl( uint32_t ulTimerControl )
{
    asm volatile ( "MSR CNTV_CTL_EL0, %0" : : "r" ( ulTimerControl ) );
}
/*-----------------------------------------------------------*/

static void vPortAgilex5A55SetVirtualTimerValue( uint32_t ulTimerValue )
{
    asm volatile ( "MSR CNTV_TVAL_EL0, %0" : : "r" ( ulTimerValue ) );
}
/*-----------------------------------------------------------*/

static void vPortAgilex5A55SetVirtualTimerCompareValue( void )
{
    /* The value of the counter will be equal to or greater than
     * ullCounterCurrval when this function is called.
     */
    ullCounterCurrVal += ullCounterReloadVal;
    asm volatile ( "MSR CNTV_CVAL_EL0, %0" : : "r" ( ullCounterCurrVal ) );
}
/*-----------------------------------------------------------*/

static uint32_t vPortAgilex5A55TGetFrequency( void )
{
uint32_t uFreq;

    asm volatile ( "MRS %0, CNTFRQ_EL0" : "=r" ( uFreq ) );
    return uFreq;
}
/*-----------------------------------------------------------*/

void vPortAgilex5A55TimerIRQHandler( void * data )
{
    ( void ) data;

    /* Configure when the next interrupt will be triggered. */
    vPortAgilex5A55SetVirtualTimerCompareValue();

    /* Call the Tick handler. */
    FreeRTOS_Tick_Handler();

}
/*-----------------------------------------------------------*/

void vPortAgilex5A55TimerInit( void )
{
    /*Register the callback*/
    interrupt_register_isr( EL1VIRT_TMR_INTR, vPortAgilex5A55TimerIRQHandler, NULL );

    /* Configure interrupt. */
    interrupt_enable( EL1VIRT_TMR_INTR, interrupt_min_interrupt_priority );

    /* Calculate the timer delay */
    ullCounterFreq = vPortAgilex5A55TGetFrequency();
    ullCounterReloadVal = ( TMR_DELAY_SECS * ullCounterFreq ) / configTICK_RATE_HZ;

    /* Get the current value of the timer */
    __asm__ volatile("mrs %0, CNTVCT_EL0" : "=r"(ullCounterCurrVal));

    /*Set the intial timer delay and enable timer interrupts */
    vPortAgilex5A55SetVirtualTimerCompareValue();
    vPortAgilex5A55SetVirtualTimerControl( AGX5_CNTV_CTL_ENABLE );
}
/*-----------------------------------------------------------*/
