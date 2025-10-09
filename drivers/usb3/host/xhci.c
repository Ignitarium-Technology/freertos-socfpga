/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA USB3.1 XHCI controller.
 */

#include "xhci.h"
#include "socfpga_defines.h"
#include "osal.h"
#include "osal_log.h"

int is_ptr_mem_aligned(uint64_t addr, uint32_t byte)
{
    uint64_t fact = 0UL;

    /* Check if the address is byte aligned or not */
    switch (byte)
    {
        case 8U:
            fact = 0x7UL;
            break;

        case 16U:
            fact = 0xFUL;
            break;

        case 32U:
            fact = 0x1FUL;
            break;

        case 64U:
            fact = 0x3FUL;
            break;

        case 128U:
            fact = 0x7FUL;
            break;

        default:
            fact = 0xFFUL;
            break;
    }

    if (fact == 0xFFUL)
    {
        return ENOMEM;
    }

    if ((addr & fact) == 0UL)
    {
        return 0;
    }

    return -EIO;
}

int configure_xhci_max_slots(struct xhci_data *xhci)
{
    volatile uint32_t config_reg_val;
    uint32_t max_slots;

    max_slots = xhci->xhc_cap_ptr->hcsparams1_params.max_dev_slots;

    DEBUG("MaxSlots is : %x", max_slots);

    config_reg_val = RD_REG32((USBBASE + USB3_CONFIG));
    max_slots |= (config_reg_val & (~USB3_CONFIG_MAXSLOTSEN_MASK));
    WR_REG32((USBBASE + USB3_CONFIG), max_slots);

    config_reg_val = RD_REG32((USBBASE + USB3_CONFIG));
    if ((config_reg_val & USB3_CONFIG_MAXSLOTSEN_MASK) == 0U)
    {
        ERROR("Max Slot Enable Bit Not configurred Correctly");
        return -EIO;
    }
    return 0;
}

void start_xhci_controller(void)
{
    uint32_t reg_val;

    reg_val = RD_REG32((USBBASE + USB3_USBCMD));
    reg_val |= (START_XHCI << USB3_USBCMD_R_S_POS);
    WR_REG32((USBBASE + USB3_USBCMD), reg_val);
}

void wait_for_controller_ready(void)
{
    uint32_t reg_val;

    do
    {
        reg_val = RD_REG32((USBBASE + USB3_USBSTS));
        /* check for CNR flag */
        if ((reg_val & USB3_USBSTS_CNR_MASK) == 0U)
        {
            break;
        }

        osal_task_delay(10);

    }while(true);

    INFO("xHCI Controller Ready");
}

int xhci_reset(void)
{
    volatile uint32_t reg_val, err_flag = 0U, loop = 1000U;

    reg_val = RD_REG32((USBBASE + USB3_USBCMD));
    /* Reset the Host Controller */
    reg_val |= (USB3_USBCMD_HCRST_MASK);
    WR_REG32((USBBASE + USB3_USBCMD), reg_val);

    INFO("Initiating Controller Reset");
    do
    {
        reg_val = RD_REG32((USBBASE + USB3_USBCMD));
        if ((reg_val & USB3_USBCMD_HCRST_MASK) == 0U)
        {
            err_flag = 1U;
            break;
        }
        osal_task_delay(10);

        --loop;
    }while(loop > 0U);

    if (err_flag == 0U)
    {
        INFO("Timeout Occurred");
        return -ETIMEDOUT;
    }

    INFO("xHCI controller reset successful");
    return 0;
}
