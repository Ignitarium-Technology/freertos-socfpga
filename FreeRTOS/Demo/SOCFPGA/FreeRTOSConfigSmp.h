/*
 * SPDX-FileCopyrightText: Copyright (C) 2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for core configuration
 */

#ifndef FREERTOS_CONFIG_SMP_H
#define FREERTOS_CONFIG_SMP_H

#define configMAX_NUM_CORES     4
/* SMP core enable controls. */
#define configSMP_CORE0_ENABLE  1
#define configSMP_CORE1_ENABLE  0
#define configSMP_CORE2_ENABLE  0
#define configSMP_CORE3_ENABLE  0

#if defined( AGILEX3 )
    #undef configSMP_CORE2_ENABLE
    #undef configSMP_CORE3_ENABLE
    #define configSMP_CORE2_ENABLE 0
    #define configSMP_CORE3_ENABLE 0
#endif

#if ( ( configSMP_CORE0_ENABLE != 0 ) && ( configSMP_CORE0_ENABLE != 1 ) )
    #error configSMP_CORE0_ENABLE must be 0 or 1
#endif
#if ( ( configSMP_CORE1_ENABLE != 0 ) && ( configSMP_CORE1_ENABLE != 1 ) )
    #error configSMP_CORE1_ENABLE must be 0 or 1
#endif
#if ( ( configSMP_CORE2_ENABLE != 0 ) && ( configSMP_CORE2_ENABLE != 1 ) )
    #error configSMP_CORE2_ENABLE must be 0 or 1
#endif
#if ( ( configSMP_CORE3_ENABLE != 0 ) && ( configSMP_CORE3_ENABLE != 1 ) )
    #error configSMP_CORE3_ENABLE must be 0 or 1
#endif

/* SMP core MPIDR values. */
#define configSMP_CORE0_MPIDR   0x0
#define configSMP_CORE1_MPIDR   0x100
#define configSMP_CORE2_MPIDR   0x200
#define configSMP_CORE3_MPIDR   0x300

#define configSMP_ENABLED_CORE_COUNT ( \
    ( configSMP_CORE0_ENABLE ) + \
    ( configSMP_CORE1_ENABLE ) + \
    ( configSMP_CORE2_ENABLE ) + \
    ( configSMP_CORE3_ENABLE ) )

#endif /* FREERTOS_CONFIG_SMP_H */
