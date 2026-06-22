/******************************************************************************
* Copyright (c) 2022 - 2023 Advanced Micro Devices, Inc. All Rights Reserved.
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
******************************************************************************/
/*
 * SPDX-FileCopyrightText: Copyright (C) 2025-2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Modifications for SoC FPGA
 */
#include "FreeRTOSConfig.h"

.global _boot
.global _secondary_boot
.global _core_setup
.global _prestart
.global _cpu_init_hook
.global _freertos_vector_table

.extern vCoreEntry
.extern ulCoreMpidrList
.set vector_base, _freertos_vector_table

/*
 * Stack total: 1Mb
 * 256kb for each EL
 * Ad per the current LD script
 * 0xFFEFFFFF   0xFFF3FFFF  0xFFF7FFFF  0xFFFBFFFF
   |    XXX     |    EL2    |    EL1    |    EL0    |
 **/
.set _STACK_START, __stack_top

.macro GET_CORE_ID reg
#if ( configNUMBER_OF_CORES == 1 )
    mov     \reg, #0
#else
    mrs     x27, MPIDR_EL1
    and     x27, x27, #0xFF00
    mov     \reg, #0
1:
    ldr     x28, =ulCoreMpidrList
    ldr     w28, [x28, \reg, LSL #2]
    cmp     w28, w27
    beq     2f
    add     \reg, \reg, #1
    cmp     \reg, #configNUMBER_OF_CORES
    blt     1b
    mov     \reg, #0
2:
#endif
.endm

/* Boot core execution starts here */
_boot:
    bl _stack_setup
    bl _core_setup

    /*
     * _mmu_configure(uint64_t setup)
     * setup=1: setup PT, setup=0: do not setup PT
     */
    mov x0, #1
    bl _mmu_configure
    bl _mainCRTStartup
    b error

/* Secondary cores execution starts here */
_secondary_boot:
    bl _stack_setup
    bl _core_setup

    /*
     * _mmu_configure(uint64_t setup)
     * setup=1: setup PT, setup=0: do not setup PT
     */
    mov x0, #0
    bl _mmu_configure
    /* vCoreEntry should not return */
    bl vCoreEntry
    b error

/* Calculate and setup stack for each EL */
_stack_setup:
    GET_CORE_ID x3

    ldr x0, =_STACK_START
    ldr x1, =_STACK_EL012
    msub x0, x1, x3, x0      /* x0 = __stack_top - (_STACK_EL012 * core_id) */
    /* EL2 top */
    mov sp, x0
    /* EL1 top = EL2 top - EL2 size */
    ldr x1, =_EL2_STACK_SIZE
    sub x0, x0, x1
    msr sp_el1, x0
    /* EL0 top = EL1 top - EL1 size */
    ldr x1, =_EL1_STACK_SIZE
    sub x0, x0, x1
    msr sp_el0, x0

    ret

/* Contains setup instructions required by all cores */
_core_setup:
    mov x0, #0
    mov x1, #0
    mov x2, #0
    mov x3, #0
    mov x4, #0
    mov x5, #0
    mov x6, #0
    mov x7, #0
    mov x8, #0
    mov x9, #0
    mov x10, #0
    mov x11, #0
    mov x12, #0
    mov x13, #0
    mov x14, #0
    mov x15, #0
    mov x16, #0
    mov x17, #0
    mov x18, #0
    mov x19, #0
    mov x20, #0
    mov x21, #0
    mov x22, #0
    mov x23, #0
    mov x24, #0
    mov x25, #0
    mov x26, #0
    mov x27, #0
    mov x28, #0
    mov x29, #0
    /* X30 contains the return address */

    MOV x1, #1

    ISB
    MSR ICC_SRE_EL2, x0
    ISB
    /* SRE = 1, Enable the Ssystem register interface for the current security level. */
    MSR ICC_SRE_EL1, x1

    /* Read currentEL and jump based in current exception level */
    mrs x0, currentEL
    cmp x0, #0x8
    beq SwitchToEL1

    cmp x0, #0x4
    beq setupEL1

    /* Go to error if current exception level is neither EL3 nor EL1 */
    b error

SwitchToEL1:
    /* Initialize VBAR_EL3 */
    ldr x1, =vector_base
    msr VBAR_EL2, x1
    ldr x1, =vector_base
    msr VBAR_EL1, x1

    /* Clear the hcr_el2 */
    msr hcr_el2, xzr
    ldr x1, =0x30C50838
    msr sctlr_el2, x1
    msr sctlr_el1, x1


    msr sctlr_el1, xzr
    mrs x0, hcr_el2
    /* RW=1  EL1 Execution state is AArch64 */
    orr x0, x0,  #(1<<31)
    /* E2H=1 EL2 host enable */
    orr x0, x0,  #(1<<34)
    msr hcr_el2, x0


    /*
     * Use the EL1 stack from EL1
     * M[4:0]=00101 EL1h must match HCR_EL2.RW.
     */
    mov x0, #0b00101
    msr spsr_el2, x0

    mov x0, #0x33ff
    msr cptr_el2, x0

    /* Set the address to jump to after eret executes */
    adr x0, setupEL1
    msr elr_el2, x0

    eret

setupEL1:
    /* Set vector table base address */
    ldr x1, =vector_base
    msr VBAR_EL1,x1

    /* Trap floating point access only in case of standalone BSP */
    mrs x0, CPACR_EL1
    orr x0, x0, #(0x3 << 20)
    msr CPACR_EL1, x0
    isb

    /*
     * Clear FPUStatus variable to make sure that it contains current
     * status of FPU i.e. disabled. In case of a warm restart execution
     * when bss sections are not cleared, it may contain previously updated
     * value which does not hold true now.
     */

    /* Disable MMU first */
    mrs x1, SCTLR_EL1
    bic x1, x1, #0x1
    orr x1, x1, #0x2
    msr     SCTLR_EL1, x1
    /* Use the EL0 stack from EL1 */
    mov x0, #0b00100
    msr spsr_el1, x0
    isb
    dsb sy
    ret

error:  b   error

.end
