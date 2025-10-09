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

#define AGX5_CNTP_CTL_ENABLE            ( 1 << 0 )
#define TMR_DELAY_SECS                  ( 1 )
#define coretimerTIMER_INITIAL_VALUE    0
/*-----------------------------------------------------------*/

static uint64_t ullCounterFreq = 0;

/*-----------------------------------------------------------*/
static void vPortAgilex5A55SetPhysicalTimerControl( uint32_t uTimerControl )
{
    asm volatile ( "MSR CNTP_CTL_EL0, %0" : : "r" ( uTimerControl ) );
}
/*-----------------------------------------------------------*/

static void vPortAgilex5A55SetPhysicalTimerValue( uint32_t uTimerValue )
{
    asm volatile ( "MSR CNTP_TVAL_EL0, %0" : : "r" ( uTimerValue ) );
}
/*-----------------------------------------------------------*/

static uint32_t vPortAgilex5A55TGetFrequency()
{
uint32_t uFreq;

    asm volatile ( "MRS %0, CNTFRQ_EL0" : "=r" ( uFreq ) );
    return uFreq;
}
/*-----------------------------------------------------------*/

void vPortAgilex5A55TimerIRQHandler( void * data )
{
    ( void ) data;
    /* Disable timer to clear interrupt. */
    vPortAgilex5A55SetPhysicalTimerControl( 0 );

    /* Set timer delay. */
    vPortAgilex5A55SetPhysicalTimerValue( ( ( TMR_DELAY_SECS ) *ullCounterFreq ) / ( configTICK_RATE_HZ ) );

    /* Call the Tick handler. */
    FreeRTOS_Tick_Handler();

    /* Enable the timer. */
    vPortAgilex5A55SetPhysicalTimerControl( AGX5_CNTP_CTL_ENABLE );
}
/*-----------------------------------------------------------*/

void vPortAgilex5A55TimerInit( void )
{
    /*Register the callback*/
    interrupt_register_isr( EL1PHY_TMR_INTR, vPortAgilex5A55TimerIRQHandler, NULL );

    /* Configure interrupt. */
    interrupt_enable( EL1PHY_TMR_INTR, interrupt_min_interrupt_priority );

    /* Set the tickrate. */
    vPortAgilex5A55SetPhysicalTimerValue( coretimerTIMER_INITIAL_VALUE );

    /*Load initial timer period and kick the timer*/
    ullCounterFreq = vPortAgilex5A55TGetFrequency();
    vPortAgilex5A55SetPhysicalTimerValue( ( ( TMR_DELAY_SECS ) *ullCounterFreq ) / ( configTICK_RATE_HZ ) );
    vPortAgilex5A55SetPhysicalTimerControl( AGX5_CNTP_CTL_ENABLE );
}
/*-----------------------------------------------------------*/
