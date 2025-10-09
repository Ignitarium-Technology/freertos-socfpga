/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level routines for freeze IP
 */


#include "socfpga_defines.h"
#include "socfpga_freeze_ip_ll.h"

/*
 * @brief Freeze the PR region
 */
int freeze_pr_region(void)
{
    volatile uint32_t reg_val;
    int timeout = 1000;

    reg_val = RD_REG32(PR_FREEZE_BASE + FREEZE_CSR_CTRL);
    reg_val |= FREEZE_CSR_CTRL_FREEZE_REQ;
    WR_REG32((PR_FREEZE_BASE + FREEZE_CSR_CTRL), reg_val);

    do
    {
        reg_val = RD_REG32((PR_FREEZE_BASE + FREEZE_CSR_STATUS));
        if ((reg_val & FREEZE_CSR_STATUS_FREEZE_STATUS_MASK) ==
                FREEZE_CSR_STATUS_FREEZE_STATUS_MASK)
        {
            break;
        }
        osal_task_delay(1);

        --timeout;
    } while(timeout > 0);

    if (timeout == 0)
    {
        return -ETIMEDOUT;
    }

    reg_val = RD_REG32(PR_FREEZE_BASE + FREEZE_CSR_CTRL);
    reg_val |= FREEZE_CSR_CTRL_RESET_REQ;
    WR_REG32((PR_FREEZE_BASE + FREEZE_CSR_CTRL), reg_val);

    return 0;
}

/*
 * @brief Unfreeze the PR region
 */
int unfreeze_pr_region(void)
{
    volatile uint32_t reg_val;
    int timeout = 1000;

    reg_val = RD_REG32(PR_FREEZE_BASE + FREEZE_CSR_CTRL);
    reg_val &= ~FREEZE_CSR_CTRL_RESET_REQ;
    WR_REG32((PR_FREEZE_BASE + FREEZE_CSR_CTRL), reg_val);

    reg_val = RD_REG32(PR_FREEZE_BASE + FREEZE_CSR_CTRL);
    reg_val |= FREEZE_CSR_CTRL_UNFREEZE_REQ;
    WR_REG32((PR_FREEZE_BASE + FREEZE_CSR_CTRL), reg_val);

    do
    {
        reg_val = RD_REG32(PR_FREEZE_BASE + FREEZE_CSR_STATUS);
        if ((reg_val & FREEZE_CSR_STATUS_UNFREEZE_STATUS_MASK) ==
                FREEZE_CSR_STATUS_UNFREEZE_STATUS_MASK)
        {
            break;
        }

        --timeout;
    } while(timeout > 0);

    if (timeout == 0)
    {
        return -ETIMEDOUT;
    }

    return 0;
}

