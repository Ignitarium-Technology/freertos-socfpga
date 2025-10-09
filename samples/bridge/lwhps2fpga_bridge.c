/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of LWHPS2FPGA bridge sample application
 */

#include "bridge_sample.h"
#include "osal_log.h"
#include "socfpga_defines.h"

#define LED_ON     (1U)
#define LED_OFF    (0U)

/* Enable this macro to run the LED toggling sample */
#define LED_SAMPLE    (0)

int lwhps2fpga_bridge_sample(void)
{
    uint64_t *write_ptr;
    uint64_t temp;
    uint32_t sysid_id;
    const uint64_t data = 0x11111111;

    /* Read the sysid signature */
    sysid_id = *((volatile uint32_t *)((LWH2F_BASE + LWH2F_SYSID_ID_BASE)));

    PRINT("SYSID_ID : %x", sysid_id);

    /* Enable the LED sample using the LED_SAMPLE macro */
#if LED_SAMPLE

    PRINT("Toggling LED Sample.\r\nLED D16 on the PDK will be toggled");

    /* Toggle the LED connected to the lwhps2fpga bridge
     * The LED mapped is D16 on the PDK
     */
    for (int i = 0; i < 10; i++)
    {
        WR_REG32((LWH2F_BASE + LWH2F_LED_OFFSET), LED_ON);
        osal_task_delay(500);
        WR_REG32((LWH2F_BASE + LWH2F_LED_OFFSET), LED_OFF);
        osal_task_delay(500);
    }

    PRINT("LED toggling completed");
#endif

    /* write and read the memories in the FPGA fabric */
    write_ptr = (uint64_t *)((LWH2F_BASE + LWH2F_BUF0));

    PRINT("WRITE DATA");

    PRINT("write buffer : %lx", data);

    *write_ptr = data;

    PRINT("READ DATA");

    /* read from first word */
    temp = *write_ptr;
    PRINT("read buffer : %lx", temp);

    if (temp != data)
    {
        ERROR("Buffer comparison failed");
        return -1;
    }

    return 0;
}

