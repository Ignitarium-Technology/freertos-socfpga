/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL driver implementation for reset manager
 */

#include "socfpga_rst_mngr_reg.h"
#include "socfpga_rst_mngr.h"
#include "socfpga_defines.h"
#include "osal.h"

int32_t rstmgr_assert_reset(reset_periphrl_t per)
{
    uint8_t bit_pos;
    uint32_t val;
    uint32_t base_addr;
    if ((per < RST_PERIPHERAL_START) || (per > RST_PERIPHERAL_END))
    {
        return -EINVAL;
    }
    base_addr = RSTMGR_GET_BASE_ADDR(per);
    bit_pos = RSTMGR_GET_BIT_POS(per);
    /* set specified bit in the register */
    val = RD_REG32(base_addr);
    val |= ((uint32_t)1U << bit_pos);
    WR_REG32(base_addr, val);
    return 0;
}

int32_t rstmgr_deassert_reset(reset_periphrl_t per)
{
    uint8_t bit_pos;
    uint32_t val;
    uint32_t base_addr;
    if ((per < RST_PERIPHERAL_START) || (per > RST_PERIPHERAL_END))
    {
        return -EINVAL;
    }
    base_addr = RSTMGR_GET_BASE_ADDR(per);
    bit_pos = RSTMGR_GET_BIT_POS(per);
    /* clear specified bit in the register */
    val = RD_REG32(base_addr);
    val &= ~((uint32_t)1U << bit_pos);
    WR_REG32(base_addr, val);
    return 0;
}

int32_t rstmgr_toggle_reset(reset_periphrl_t per)
{
    if ((per < RST_PERIPHERAL_START) || (per > RST_PERIPHERAL_END))
    {
        return -EINVAL;
    }
    if (rstmgr_assert_reset(per) != 0)
    {
        return -EINVAL;
    }
    osal_task_delay(1);
    return 0;
}

int32_t rstmgr_get_reset_status(reset_periphrl_t per, uint8_t *stat)
{
    uint8_t bit_pos;
    uint32_t base_addr;
    if ((per < RST_PERIPHERAL_START) || (per > RST_PERIPHERAL_END))
    {
        return -EINVAL;
    }
    base_addr = RSTMGR_GET_BASE_ADDR(per);
    bit_pos = RSTMGR_GET_BIT_POS(per);
    /* get specified bit from the register */
    *stat = (uint8_t)(RD_REG32(base_addr) >> bit_pos) & 1U;
    return 0;
}
