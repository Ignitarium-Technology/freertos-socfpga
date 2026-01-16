/*
 * FreeRTOS V202212.01
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"

/* Interface include files. */
#include "RegTests.h"

/* Tasks that implement register tests. */
static void prvRegisterTest1Task( void * pvParameters );
static void prvRegisterTest2Task( void * pvParameters );
static void prvRegisterTest3Task( void * pvParameters );
static void prvRegisterTest4Task( void * pvParameters );

/* Flag that will be latched to pdTRUE should any unexpected behaviour be
 * detected in any of the tasks. */
static volatile BaseType_t xErrorDetected = pdFALSE;

/* Counters that are incremented on each cycle of a test.  This is used to
 * detect a stalled task - a test that is no longer running. */

static volatile uint64_t ulRegisterTest1Counter = 0;
static volatile uint64_t ulRegisterTest2Counter = 0;
static volatile uint64_t ulRegisterTest3Counter = 0;
static volatile uint64_t ulRegisterTest4Counter = 0;

/*-----------------------------------------------------------*/

static void prvRegisterTest1Task( void * pvParameters )
{
    ( void ) pvParameters;

    portTASK_USES_FLOATING_POINT();

    for( ; ; )
    {
        #if 1
            /* Load initial values to all 31 registers ( 64 bit registers ) */
            __asm volatile
            (
                "	mov x0, #10	\n"
                "	mov x1, #11	\n"
                "	mov x2, #12	\n"
                "	mov x3, #13	\n"
                "	mov x4, #14	\n"
                "	mov x5, #15	\n"
                "	mov x6, #16	\n"
                "	mov x7, #17	\n"
                "	mov x8, #18	\n"
                "	mov x9, #19	\n"
                "	mov x10, #20 \n"
                "	mov x11, #21 \n"
                "	mov x12, #22 \n"
                "	mov x13, #23 \n"
                "	mov x14, #24 \n"
                "	mov x15, #25 \n"
                "	mov x16, #26 \n"
                "	mov x17, #27 \n"
                "	mov x18, #28 \n"
                "	mov x19, #29 \n"
                "	mov x20, #30 \n"
                "	mov x21, #31 \n"
                "	mov x22, #32 \n"
                "	mov x23, #33 \n"
                "	mov x24, #34 \n"
                "	mov x25, #35 \n"
                "	mov x26, #36 \n"
                "	mov x27, #37 \n"
                "	mov x28, #38 \n"
                "	mov x29, #39 \n"
                "	mov x30, #40 \n"

                /*
                 * Load all the FP 128 bit registers with tpre-defined values
                 */

                "	fmov d0, x0	\n"
                "	fmov d1, x1	\n"
                "	fmov d2, x2	\n"
                "	fmov d3, x3	\n"
                "	fmov d4, x4	\n"
                "	fmov d5, x5	\n"
                "	fmov d6, x6	\n"
                "	fmov d7, x7	\n"
                "	fmov d8, x8	\n"
                "	fmov d9, x9	\n"
                "	fmov v10.d[1], x10 \n"
                "	fmov d11, x11 \n"
                "	fmov d12, x12 \n"
                "	fmov d13, x13 \n"
                "	fmov d14, x14 \n"
                "	fmov d15, x15 \n"
                "	fmov d16, x16 \n"
                "	fmov d17, x17 \n"
                "	fmov d18, x18 \n"
                "	fmov d19, x19 \n"
                "	fmov d20, x20 \n"
                "	fmov d21, x21 \n"
                "	fmov d22, x22 \n"
                "	fmov d23, x23 \n"
                "	fmov d24, x24 \n"
                "	fmov d25, x25 \n"
                "	fmov d26, x26 \n"
                "	fmov d27, x27 \n"
                "	fmov d28, x28 \n"
                "	fmov d29, x29 \n"
                "	fmov d30, x30 \n"
                "	fmov d31, xzr \n"

                /* Compare all the values remain the same during context switch happends */
                "loop_again1:		\n"

                "	cmp x0, #10	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x1, #11	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x2, #12	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x3, #13	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x4, #14	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x5, #15	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x6, #16	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x7, #17	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x8, #18	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x9, #19	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x10, #20	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x11, #21	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x12, #22	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x13, #23	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x14, #24	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x15, #25	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x16, #26	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x17, #27	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x18, #28	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x19, #29	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x20, #30	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x21, #31	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x22, #32	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x23, #33	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x24, #34	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x25, #35	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x26, #36	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x27, #37	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x28, #38	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x29, #39	\n"
                "	b.ne exit_loop1	\n"
                "	cmp x30, #40	\n"
                "	b.ne exit_loop1	\n"

                /* Compare the floating point registers	*/

                "	fmov x0, d0	\n"
                "	cmp x0, #10	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d1	\n"
                "	cmp x0, #11	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d2	\n"
                "	cmp x0, #12	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d3	\n"
                "	cmp x0, #13	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d4	\n"
                "	cmp x0, #14	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d5	\n"
                "	cmp x0, #15	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d6	\n"
                "	cmp x0, #16	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d7	\n"
                "	cmp x0, #17	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d8	\n"
                "	cmp x0, #18	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d9	\n"
                "	cmp x0, #19	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, v10.d[1]	\n"
                "	cmp x0, #20	\n"
                "	b.ne exit_loop1	\n"

                "	fmov x0, d11	\n"
                "	cmp x0, #21	\n"
                "	b.ne exit_loop1	\n"

                "	ldr x3, =ulRegisterTest1Counter	\n"/*Load the counter variable to a register */
                "	ldr x4, [x3] 	\n"
                "	add x4, x4, #1	\n"               /* increment the counter variable */
                "	str x4, [x3]	\n"               /* store back the updated value to the 'c' counter variable */
                "	mov x3, #13	\n"                   /* replace the register original values before looping again */
                "	mov x4, #14	\n"
                "	mov x0, #10	\n"                   /* replace the register original values before looping again */
                "	b loop_again1	\n"

                "exit_loop1 :		\n"     /*Incase register values don't match, the counter doesnt increment, and test fails */
                "	b exit_loop1	\n"
            );
        #endif /* if 1 */

        /* 1. Fill the registers stored as part of task context with known values.
           2. Force a context switch.
           3. Verify that all the registers contain expected values.
           4. If all the register contain expected values, increment ulRegisterTest1Counter. */
    }
}
/*-----------------------------------------------------------*/

static void prvRegisterTest2Task( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        #if 1
            __asm volatile
            (
                "	mov x0, #101 \n"
                "	mov x1, #111 \n"
                "	mov x2, #121 \n"
                "	mov x3, #131 \n"
                "	mov x4, #141 \n"
                "	mov x5, #151 \n"
                "	mov x6, #161 \n"
                "	mov x7, #171 \n"
                "	mov x8, #181 \n"
                "	mov x9, #191 \n"
                "	mov x10, #201 \n"
                "	mov x11, #211 \n"
                "	mov x12, #221 \n"
                "	mov x13, #231 \n"
                "	mov x14, #241 \n"
                "	mov x15, #251 \n"
                "	mov x16, #261 \n"
                "	mov x17, #271 \n"
                "	mov x18, #281 \n"
                "	mov x19, #291 \n"
                "	mov x20, #301 \n"
                "	mov x21, #311 \n"
                "	mov x22, #321 \n"
                "	mov x23, #331 \n"
                "	mov x24, #341 \n"
                "	mov x25, #351 \n"
                "	mov x26, #361 \n"
                "	mov x27, #371 \n"
                "	mov x28, #381 \n"
                "	mov x29, #391 \n"
                "	mov x30, #401 \n"

                /* Load floating point registers	*/
                "	fmov d0, x0 \n"
                "	fmov d1, x1 \n"
                "	fmov d2, x2 \n"
                "	fmov d3, x3 \n"
                "	fmov d4, x4 \n"
                "	fmov d5, x5 \n"
                "	fmov d6, x6 \n"
                "	fmov d7, x7 \n"
                "	fmov d8, x8 \n"
                "	fmov d9, x9 \n"
                "	fmov v10.d[1], x10 \n"
                "	fmov d11, x11 \n"
                "	fmov d12, x12 \n"
                "	fmov d13, x13 \n"
                "	fmov d14, x14 \n"
                "	fmov d15, x15 \n"
                "	fmov d16, x16 \n"
                "	fmov d17, x17 \n"
                "	fmov d18, x18 \n"
                "	fmov d19, x19 \n"
                "	fmov d20, x20 \n"
                "	fmov d21, x21 \n"
                "	fmov d22, x22 \n"
                "	fmov d23, x23 \n"
                "	fmov d24, x24 \n"
                "	fmov d25, x25 \n"
                "	fmov d26, x26 \n"
                "	fmov d27, x27 \n"
                "	fmov d28, x28 \n"
                "	fmov d29, x29 \n"
                "	fmov d30, x30 \n"
                "	fmov d31, xzr \n"

                "loop_again2:		\n"
                "	cmp x0, #101	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x1, #111	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x2, #121	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x3, #131	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x4, #141	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x5, #151	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x6, #161	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x7, #171	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x8, #181	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x9, #191	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x10, #201	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x11, #211	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x12, #221	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x13, #231	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x14, #241	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x15, #251	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x16, #261	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x17, #271	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x18, #281	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x19, #291	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x20, #301	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x21, #311	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x22, #321	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x23, #331	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x24, #341	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x25, #351	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x26, #361	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x27, #371	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x28, #381	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x29, #391	\n"
                "	b.ne exit_loop2	\n"
                "	cmp x30, #401	\n"
                "	b.ne exit_loop2	\n"

                /*Compare floating point registers */


                "	ldr x3, =ulRegisterTest2Counter	\n"
                "	ldr x4, [x3] 	\n"
                "	add x4, x4, #1	\n"
                "	str x4, [x3]	\n"
                "	mov x4, #141	\n"
                "	mov x3, #131	\n"
                "	mov x0, #101	\n"
                "	b loop_again2	\n"

                "exit_loop2 :	\n"
                "	b exit_loop2	\n"
            );
        #endif /* if 1 */

        /* 1. Fill the registers stored as part of task context with known values.
           2. Force a context switch.
           3. Verify that all the registers contain expected values.
           4. If all the register contain expected values, increment ulRegisterTest2Counter. */
    }
}
/*-----------------------------------------------------------*/

static void prvRegisterTest3Task( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        #if 1
            __asm volatile
            (
                "	mov x0, #102	\n"
                "	mov x1, #112	\n"
                "	mov x2, #122	\n"
                "	mov x3, #132	\n"
                "	mov x4, #142	\n"
                "	mov x5, #152	\n"
                "	mov x6, #162	\n"
                "	mov x7, #172	\n"
                "	mov x8, #182	\n"
                "	mov x9, #192	\n"
                "	mov x10, #202	\n"
                "	mov x11, #212	\n"
                "	mov x12, #222	\n"
                "	mov x13, #232	\n"
                "	mov x14, #242	\n"
                "	mov x15, #252	\n"
                "	mov x16, #262	\n"
                "	mov x17, #272	\n"
                "	mov x18, #282	\n"
                "	mov x19, #292	\n"
                "	mov x20, #302	\n"
                "	mov x21, #312	\n"
                "	mov x22, #322	\n"
                "	mov x23, #332	\n"
                "	mov x24, #342	\n"
                "	mov x25, #352	\n"
                "	mov x26, #362	\n"
                "	mov x27, #372	\n"
                "	mov x28, #382	\n"
                "	mov x29, #392	\n"
                "	mov x30, #402	\n"

                /*floating point */
                "	fmov d0, x0	\n"
                "	fmov d1, x1	\n"
                "	fmov d2, x2	\n"
                "	fmov d3, x3	\n"
                "	fmov d4, x4	\n"
                "	fmov d5, x5	\n"
                "	fmov d6, x6	\n"
                "	fmov d7, x7	\n"
                "	fmov d8, x8	\n"
                "	fmov d9, x9	\n"
                "	fmov v10.d[1], x10 \n"
                "	fmov d11, x11 \n"
                "	fmov d12, x12 \n"
                "	fmov d13, x13 \n"
                "	fmov d14, x14 \n"
                "	fmov d15, x15 \n"
                "	fmov d16, x16 \n"
                "	fmov d17, x17 \n"
                "	fmov d18, x18 \n"
                "	fmov d19, x19 \n"
                "	fmov d20, x20 \n"
                "	fmov d21, x21 \n"
                "	fmov d22, x22 \n"
                "	fmov d23, x23 \n"
                "	fmov d24, x24 \n"
                "	fmov d25, x25 \n"
                "	fmov d26, x26 \n"
                "	fmov d27, x27 \n"
                "	fmov d28, x28 \n"
                "	fmov d29, x29 \n"
                "	fmov d30, x30 \n"
                "	fmov d31, xzr \n"

                "loop_again3:		\n"
                "	cmp x0, #102	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x1, #112	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x2, #122	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x3, #132	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x4, #142	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x5, #152	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x6, #162	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x7, #172	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x8, #182	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x9, #192	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x10, #202	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x11, #212	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x12, #222	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x13, #232	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x14, #242	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x15, #252	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x16, #262	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x17, #272	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x18, #282	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x19, #292	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x20, #302	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x21, #312	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x22, #322	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x23, #332	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x24, #342	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x25, #352	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x26, #362	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x27, #372	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x28, #382	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x29, #392	\n"
                "	b.ne exit_loop3	\n"
                "	cmp x30, #402	\n"
                "	b.ne exit_loop3	\n"

                "	ldr x3, =ulRegisterTest3Counter	\n"
                "	ldr x4, [x3] 	\n"
                "	add x4, x4, #1	\n"
                "	str x4, [x3]	\n"
                "	mov x3, #132	\n"
                "	mov x4, #142	\n"
                "	b loop_again3	\n"

                "exit_loop3 :	\n"
                "	b exit_loop3	\n"
            );
        #endif /* if 1 */

        /* 1. Fill the registers stored as part of task context with known values.
           2. Force a context switch.
           3. Verify that all the registers contain expected values.
           4. If all the register contain expected values, increment ulRegisterTest3Counter. */
    }
}
/*-----------------------------------------------------------*/

static void prvRegisterTest4Task( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        #if 1
            __asm volatile
            (
                "	mov x0, #103 \n"
                "	mov x1, #113 \n"
                "	mov x2, #123 \n"
                "	mov x3, #133 \n"
                "	mov x4, #143 \n"
                "	mov x5, #153 \n"
                "	mov x6, #163 \n"
                "	mov x7, #173 \n"
                "	mov x8, #183 \n"
                "	mov x9, #193 \n"
                "	mov x10, #203	\n"
                "	mov x11, #213	\n"
                "	mov x12, #223	\n"
                "	mov x13, #233	\n"
                "	mov x14, #243	\n"
                "	mov x15, #253	\n"
                "	mov x16, #263	\n"
                "	mov x17, #273	\n"
                "	mov x18, #283	\n"
                "	mov x19, #293	\n"
                "	mov x20, #303	\n"
                "	mov x21, #313	\n"
                "	mov x22, #323	\n"
                "	mov x23, #333	\n"
                "	mov x24, #343	\n"
                "	mov x25, #353	\n"
                "	mov x26, #363	\n"
                "	mov x27, #373	\n"
                "	mov x28, #383	\n"
                "	mov x29, #393	\n"
                "	mov x30, #403	\n"
                /* FP registers	*/

                "loop_again4:		\n"
                "	cmp x0, #103	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x1, #113	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x2, #123	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x3, #133	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x4, #143	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x5, #153	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x6, #163	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x7, #173	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x8, #183	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x9, #193	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x10, #203	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x11, #213	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x12, #223	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x13, #233	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x14, #243	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x15, #253	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x16, #263	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x17, #273	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x18, #283	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x19, #293	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x20, #303	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x21, #313	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x22, #323	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x23, #333	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x24, #343	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x25, #353	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x26, #363	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x27, #373	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x28, #383	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x29, #393	\n"
                "	b.ne exit_loop4	\n"
                "	cmp x30, #403	\n"
                "	b.ne exit_loop4	\n"

                "	ldr x3, =ulRegisterTest4Counter	\n"
                "	ldr x4, [x3] 	\n"
                "	add x4, x4, #1	\n"
                "	str x4, [x3]	\n"
                "	mov x3, #133	\n"
                "	mov x4, #143	\n"
                "	b loop_again4	\n"

                "exit_loop4 :	\n"
                "	b exit_loop4	\n"
            );
        #endif /* if 1 */

        /* 1. Fill the registers stored as part of task context with known values.
           2. Force a context switch.
           3. Verify that all the registers contain expected values.
           4. If all the register contain expected values, increment ulRegisterTest4Counter. */
    }
}
/*-----------------------------------------------------------*/

void vStartRegisterTasks( UBaseType_t uxPriority )
{
    vPortTaskUsesFPU();
    BaseType_t ret;

    ret = xTaskCreate( prvRegisterTest1Task, "RegTest1", configMINIMAL_STACK_SIZE, NULL, uxPriority, NULL );
    configASSERT( ret == pdPASS );

    ret = xTaskCreate( prvRegisterTest2Task, "RegTest2", configMINIMAL_STACK_SIZE, NULL, uxPriority, NULL );
    configASSERT( ret == pdPASS );

    ret = xTaskCreate( prvRegisterTest3Task, "RegTest3", configMINIMAL_STACK_SIZE, NULL, uxPriority, NULL );
    configASSERT( ret == pdPASS );

    ret = xTaskCreate( prvRegisterTest4Task, "RegTest4", configMINIMAL_STACK_SIZE, NULL, uxPriority, NULL );
    configASSERT( ret == pdPASS );
}
/*-----------------------------------------------------------*/

BaseType_t xAreRegisterTasksStillRunning( void )
{
static uint32_t ulLastRegisterTest1Counter = 0, ulLastRegisterTest2Counter = 0;
static uint32_t ulLastRegisterTest3Counter = 0, ulLastRegisterTest4Counter = 0;

    /* If the register test task is still running then we expect the loop
       counters to have incremented since this function was last called. */
    if( ulLastRegisterTest1Counter == ulRegisterTest1Counter )
    {
        xErrorDetected = pdTRUE;
    }

    if( ulLastRegisterTest2Counter == ulRegisterTest2Counter )
    {
        xErrorDetected = pdTRUE;
    }

    if( ulLastRegisterTest3Counter == ulRegisterTest3Counter )
    {
        xErrorDetected = pdTRUE;
    }

    if( ulLastRegisterTest4Counter == ulRegisterTest4Counter )
    {
        xErrorDetected = pdTRUE;
    }

    ulLastRegisterTest1Counter = ulRegisterTest1Counter;
    ulLastRegisterTest2Counter = ulRegisterTest2Counter;
    ulLastRegisterTest3Counter = ulRegisterTest3Counter;
    ulLastRegisterTest4Counter = ulRegisterTest4Counter;

    /* Errors detected in the task itself will have latched xErrorDetected
       to true. */
    return ( BaseType_t ) !xErrorDetected;
}
/*-----------------------------------------------------------*/
