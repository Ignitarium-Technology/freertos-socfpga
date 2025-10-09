/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL driver implementation for Clock manager
 */

#include <errno.h>
#include "socfpga_clk_mngr_reg.h"
#include "socfpga_sys_mngr_reg.h"
#include "socfpga_clk_mngr.h"
#include "socfpga_defines.h"
#include "osal_log.h"

#define CLK_SUCCESS    0U
#define CLK_ERROR      1U
/**
 * @brief Read Source VCO clock for given block
 */
static uint32_t pclk_mngr_get_src_ref_clk(uint32_t pll_glob_reg_val)
{
    uint32_t src_clk_value = 0U, ref_clk_value = 0U, aref_clk_div;
    uint32_t src_pll_value;
    src_pll_value = (pll_glob_reg_val & CLK_MNGR_PLLGLOB_PSRC_MASK) >>
            CLK_MNGR_PLLGLOB_PSRC_POS;
    /*The clock reference values were updated in Boot scratch register by ATF.*/
    switch (src_pll_value)
    {
        case PSRC_EOSC1_CLK:
            src_clk_value = RD_REG32(
                    SYS_MNGR_BASE_ADDR + SYS_MNGR_BOOT_SCRATCH_COLD1);
            break;

        case PSRC_CBINTOSC_CLK:
            src_clk_value = CLKMGR_INTOSC_CLOCK_RATE_HZ;
            break;

        case PSRC_F2S_FREE_CLK:
            src_clk_value = RD_REG32(
                    SYS_MNGR_BASE_ADDR + SYS_MNGR_BOOT_SCRATCH_COLD2);
            break;

        default:
            ERROR("Not a valid block to get clock frequency");
            break;

    }
    if (src_clk_value != 0U)
    {
        aref_clk_div = (pll_glob_reg_val & CLK_MNGR_PLLGLOB_AREFCLKDIV_MASK) >>
                CLK_MNGR_PLLGLOB_AREFCLKDIV_POS;
        if (aref_clk_div == 0U)
        {
            ERROR("aref_clk_div is 0");
            return ref_clk_value;
        }
        ref_clk_value = src_clk_value / aref_clk_div;
    }
    return ref_clk_value;
}

/**
 * @brief Read Reference clock value of given PLL source
 */
static uint32_t pclk_mngr_get_clk(uint32_t clk_src_reg, uint32_t
        pll_channel_config_reg_main, uint32_t
        pll_channel_config_reg_peri)
{
    uint32_t src_clk;
    uint32_t clk_src, clk_mdiv, ref_clk_val = 0U;
    uint32_t clk_div_ctrl_reg_val = 0U, pll_channel_config_reg_val = 0U,
            pll_glob_reg_val = 0U, pll_clk_slice_div;
    clk_src = RD_REG32(clk_src_reg);
    src_clk = (uint32_t)((clk_src & CLK_MNGR_NOCCLK_SRC_MASK) >>
            CLK_MNGR_NOCCLK_SRC_POS);
    switch (src_clk)
    {
        case MAIN_PLL_CLK_SRC:
            clk_div_ctrl_reg_val = RD_REG32(
                    CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_PLLM);
            pll_channel_config_reg_val = RD_REG32(pll_channel_config_reg_main);
            pll_glob_reg_val = RD_REG32(
                    CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_PLLGLOB);
            break;

        case PERI_PLL_CLK_SRC:
            clk_div_ctrl_reg_val = RD_REG32(
                    CLK_MNGR_BASE_ADDR + PERPLL_CLK_MNGR_PLLM);
            pll_channel_config_reg_val = RD_REG32(pll_channel_config_reg_peri);
            pll_glob_reg_val = RD_REG32(
                    CLK_MNGR_BASE_ADDR + PERPLL_CLK_MNGR_PLLGLOB);
            break;

        default:
            ERROR(" Not a valid block to get clock frequency");
            break;
    }
    ref_clk_val = pclk_mngr_get_src_ref_clk(pll_glob_reg_val);
    if (ref_clk_val != 0U)
    {

        clk_mdiv = (clk_div_ctrl_reg_val & CLK_MNGR_PLLM_MDIV_MASK);
        ref_clk_val = ref_clk_val * clk_mdiv;

        pll_clk_slice_div = (pll_channel_config_reg_val &
                CLK_MNGR_PLLC0_DIV_MASK);
        if (pll_clk_slice_div == 0U)
        {
            ERROR(" PLL Clock Slice Div is 0 ");
            return ref_clk_val;
        }
        ref_clk_val = ref_clk_val / pll_clk_slice_div;
    }
    return ref_clk_val;
}

/**
 * @brief Read L3 Main Free clock
 */
static uint32_t pclk_mngr_get_l3_main_free_clk(void)
{
    uint32_t l3_main_free_clk = 0U;
    l3_main_free_clk = pclk_mngr_get_clk(
            CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCCLK, CLK_MNGR_BASE_ADDR +
            MAINPLL_CLK_MNGR_PLLC3, CLK_MNGR_BASE_ADDR + PERPLL_CLK_MNGR_PLLC1);
    return l3_main_free_clk;
}

/**
 * @brief Read L4 SP clock
 */
static uint32_t pclk_mngr_get_l4_sp_clk(void)
{
    uint32_t l4_sp_clk, l4_sp_clk_div;
    l4_sp_clk = pclk_mngr_get_l3_main_free_clk();
    if (l4_sp_clk != 0U)
    {
        l4_sp_clk_div = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
        l4_sp_clk_div = (l4_sp_clk_div & CLK_MNGR_NOCDIV_L4SPCLK_MASK) >>
                CLK_MNGR_NOCDIV_L4SPCLK_POS;
        l4_sp_clk = l4_sp_clk >> l4_sp_clk_div;
    }
    return l4_sp_clk;
}

/**
 * @brief Read L4 Main clock
 */
static uint32_t pclk_mngr_get_sp_timer_clk(void)
{
    return pclk_mngr_get_l4_sp_clk();
}

/**
 * @brief Read L4 Sys Free clock
 */
static uint32_t pclk_mngr_get_uart_clk(void)
{
    return pclk_mngr_get_l4_sp_clk();
}

/**
 * @brief Read L4 Sys Free clock
 */
static uint32_t pclk_mngr_get_i2c_clk(void)
{
    return pclk_mngr_get_l4_sp_clk();
}

/**
 * @brief Read L4 Sys Free clock
 */
static uint32_t pclk_mngr_get_l4_sys_free_clk(void)
{
    uint32_t l4_sys_free_clk, l4_sys_free_clk_div;
    l4_sys_free_clk = pclk_mngr_get_l3_main_free_clk();
    if (l4_sys_free_clk != 0U)
    {
        l4_sys_free_clk_div = RD_REG32(
                CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
        l4_sys_free_clk_div = (l4_sys_free_clk_div &
                CLK_MNGR_NOCDIV_L4SYSFREECLK_MASK) >>
                CLK_MNGR_NOCDIV_L4SYSFREECLK_POS;
        l4_sys_free_clk = l4_sys_free_clk >> l4_sys_free_clk_div;
    }
    return l4_sys_free_clk;
}

/**
 * @brief Read WDT clock
 */
static uint32_t pclk_mngr_get_wdt_clk(void)
{
    return pclk_mngr_get_l4_sys_free_clk();
}

/**
 * @brief Read Osc1 Timer clock
 */
static uint32_t pclk_mngr_get_osc1_timer_clk(void)
{
    return pclk_mngr_get_l4_sys_free_clk();
}

/**
 * @brief Read QSPI clock
 */
static uint32_t pclk_mngr_get_qspi_clk(void)
{
    uint32_t qspi_clk;
    /*The clock reference values were updated in Boot scratch0 register by ATF.*/
    qspi_clk = RD_REG32(SYS_MNGR_BASE_ADDR + SYS_MNGR_BOOT_SCRATCH_COLD0);
    qspi_clk = qspi_clk * QSPI_CLOCK_MULTIPLIER;
    return qspi_clk;
}

/**
 * @brief Read L4 Main clock
 */
static uint32_t pclk_mngr_get_l4_main_clk(void)
{
    uint32_t l4_main_clk;
    l4_main_clk = pclk_mngr_get_l3_main_free_clk();
    return l4_main_clk;
}

/**
 * @brief Read SSPI clock
 */
static uint32_t pclk_mngr_get_sspi_clk(void)
{
    uint32_t sspi_clk;
    sspi_clk = pclk_mngr_get_l4_main_clk();
    return sspi_clk;
}

/**
 * @brief Read L4 MP clock
 */
static uint32_t pclk_mngr_get_l4_mp_clk(void)
{
    uint32_t l4_mp_clk, l4_mp_clk_div;
    l4_mp_clk = pclk_mngr_get_l3_main_free_clk();
    if (l4_mp_clk != 0U)
    {
        l4_mp_clk_div = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
        l4_mp_clk_div = (l4_mp_clk_div & CLK_MNGR_NOCDIV_L4MPCLK_MASK) >>
                CLK_MNGR_EN_L4MPCLKEN_POS;
        l4_mp_clk = l4_mp_clk >> l4_mp_clk_div;
    }
    return l4_mp_clk;
}

/**
 * @brief Get SDMMC clock
 */
static uint32_t pclk_mngr_get_sdmmc_clk(void)
{
    uint32_t sdmmc_clk;
    sdmmc_clk = pclk_mngr_get_l4_mp_clk();
    return sdmmc_clk;
}

/**
 * @brief Get MPU clock
 */
static uint32_t pclk_mngr_get_mpu_clk(void)
{
    uint32_t mpu_clk = 0U;
    mpu_clk = pclk_mngr_get_clk(CLK_MNGR_BASE_ADDR + CLK_MNGR_DSUCTR,
            CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_PLLC2, CLK_MNGR_BASE_ADDR +
            PERPLL_CLK_MNGR_PLLC0);
    return mpu_clk;
}

/**
 * @brief Set L4 Sys Free clock divisor
 */
static uint32_t pclk_mngr_set_l4_sys_free_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_L4SYSFREECLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= (0U << CLK_MNGR_NOCDIV_L4SYSFREECLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= 1U << CLK_MNGR_NOCDIV_L4SYSFREECLK_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= 2U << CLK_MNGR_NOCDIV_L4SYSFREECLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set L4 MP clock divisor
 */
static uint32_t pclk_mngr_set_l4_mp_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_L4MPCLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= (0U << CLK_MNGR_NOCDIV_L4MPCLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= 1U << CLK_MNGR_NOCDIV_L4MPCLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set L4 SP clock divisor
 */
static uint32_t pclk_mngr_set_l4_sp_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_L4SPCLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= (0U << CLK_MNGR_NOCDIV_L4SPCLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= 1U << CLK_MNGR_NOCDIV_L4SPCLK_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= 2U << CLK_MNGR_NOCDIV_L4SPCLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set Soft PHY clock divisor
 */
static uint32_t pclk_mngr_set_soft_phy_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_SOFTPHYDIV_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_SOFTPHYDIV_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_SOFTPHYDIV_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= (uint32_t)2 << CLK_MNGR_NOCDIV_SOFTPHYDIV_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set CCU clock divisor
 */
static uint32_t pclk_mngr_set_ccu_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_CCUDIV_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_CCUDIV_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_CCUDIV_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set MPU Peripheral clock divisor
 */
static uint32_t pclk_mngr_set_mpu_periph_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_MPUPERIPHDIV_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_MPUPERIPHDIV_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_MPUPERIPHDIV_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= (uint32_t)2 << CLK_MNGR_NOCDIV_MPUPERIPHDIV_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set CS clock divisor
 */
static uint32_t pclk_mngr_set_cs_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_CSCLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_CSCLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_CSCLK_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= (uint32_t)2 << CLK_MNGR_NOCDIV_CSCLK_POS;
    }
    else if (divisor == 8U)
    {
        reg_val |= (uint32_t)3 << CLK_MNGR_NOCDIV_CSCLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set CS Trace clock divisor
 */
static uint32_t pclk_mngr_set_cs_trace_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_CSTRACECLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_CSTRACECLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_CSTRACECLK_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= (uint32_t)2 << CLK_MNGR_NOCDIV_CSTRACECLK_POS;
    }
    else if (divisor == 8U)
    {
        reg_val |= (uint32_t)3 << CLK_MNGR_NOCDIV_CSTRACECLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Set CS PDBG clock divisor
 */
static uint32_t pclk_mngr_set_cs_pdbg_clk_div(uint8_t divisor)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    reg_val &= ~CLK_MNGR_NOCDIV_CSPDBGCLK_MASK;
    if (divisor == 1U)
    {
        reg_val |= ((uint32_t)0 << CLK_MNGR_NOCDIV_CSPDBGCLK_POS);
    }
    else if (divisor == 2U)
    {
        reg_val |= (uint32_t)1 << CLK_MNGR_NOCDIV_CSPDBGCLK_POS;
    }
    else if (divisor == 4U)
    {
        reg_val |= (uint32_t)2 << CLK_MNGR_NOCDIV_CSPDBGCLK_POS;
    }
    else if (divisor == 8U)
    {
        reg_val |= (uint32_t)3 << CLK_MNGR_NOCDIV_CSPDBGCLK_POS;
    }
    else
    {
        ERROR("Not a valid divisor for the block");
        return -EINVAL;
    }
    WR_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV, reg_val);
    return 0;
}

/**
 * @brief Get L4 Sys Free clock divisor
 */
static uint8_t pclk_mngr_get_l4_sys_free_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_L4SYSFREECLK_POS) & 3U;

    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get L4 MP clock divisor
 */
static uint8_t pclk_mngr_get_l4_mp_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_L4MPCLK_POS) & 3U;

    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get L4 SP clock divisor
 */
static uint8_t pclk_mngr_get_l4_sp_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_L4SPCLK_POS) & 3U;

    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get Soft PHY clock divisor
 */
static uint8_t pclk_mngr_get_soft_phy_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_SOFTPHYDIV_POS) & 3U;

    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get CCU clock divisor
 */
static uint8_t pclk_mngr_get_ccu_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_CCUDIV_POS) & 3U;

    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get MPU Peripheral clock divisor
 */
static uint8_t pclk_mngr_get_mpu_periph_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_MPUPERIPHDIV_POS) & 3U;

    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get CS clock divisor
 */
static uint8_t pclk_mngr_get_cs_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_CSCLK_POS) & 3U;

    if (div == 3U)
    {
        return 8U;
    }
    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get CS Trace clock divisor
 */
static uint8_t pclk_mngr_get_cs_trace_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_CSTRACECLK_POS) & 3U;

    if (div == 3U)
    {
        return 8U;
    }
    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

/**
 * @brief Get CS PDBG clock divisor
 */
static uint8_t pclk_mngr_get_cs_pdbg_clk_div(void)
{
    uint32_t reg_val = RD_REG32(CLK_MNGR_BASE_ADDR + MAINPLL_CLK_MNGR_NOCDIV);
    uint32_t div = (reg_val >> CLK_MNGR_NOCDIV_CSPDBGCLK_POS) & 3U;

    if (div == 3U)
    {
        return 8U;
    }
    if (div == 2U)
    {
        return 4U;
    }
    if (div == 1U)
    {
        return 2U;
    }
    if (div == 0U)
    {
        return 0U;
    }
    return -EINVAL;
}

int32_t clk_mngr_get_clk(clock_block_t clock_block_name, uint32_t *pclock_rate)
{
    int32_t l_ret = 0;
    switch (clock_block_name)
    {
        case CLOCK_MPU:
            *pclock_rate = pclk_mngr_get_mpu_clk();
            break;

        case CLOCK_SDMMC:
            *pclock_rate = pclk_mngr_get_sdmmc_clk();
            break;

        case CLOCK_QSPI:
            *pclock_rate = pclk_mngr_get_qspi_clk();
            break;

        case CLOCK_SP_TIMER:
            *pclock_rate = pclk_mngr_get_sp_timer_clk();
            break;
        case CLOCK_OSC1TIMER:
            *pclock_rate = pclk_mngr_get_osc1_timer_clk();
            break;
        case CLOCK_SSPI:
            *pclock_rate = pclk_mngr_get_sspi_clk();
            break;

        case CLOCK_UART:
            *pclock_rate = pclk_mngr_get_uart_clk();
            break;

        case CLOCK_WDT:
            *pclock_rate = pclk_mngr_get_wdt_clk();
            break;

        case CLOCK_I2C:
            *pclock_rate = pclk_mngr_get_i2c_clk();
            break;

        default:
            ERROR(" Not a valid block to get clock frequency");
            *pclock_rate = 0U;
            break;
    }

    if (*pclock_rate == 0U)
    {
        l_ret = -EINVAL;
    }
    return l_ret;
}

int32_t clk_mngr_set_divisor(uint32_t clock_type, uint8_t divisor)
{
    int32_t ret = 1;
    switch (clock_type)
    {
        case L4_SYS_FREE_CLK:
            if (pclk_mngr_set_l4_sys_free_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case L4_MP_CLK:
            if (pclk_mngr_set_l4_mp_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case L4_SP_CLK:
            if (pclk_mngr_set_l4_sp_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case SOFT_PHY_DIV:
            if (pclk_mngr_set_soft_phy_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case CCU_DIV:
            if (pclk_mngr_set_ccu_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case MPU_PERIPH_DIV:
            if (pclk_mngr_set_mpu_periph_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case CS_CLK:
            if (pclk_mngr_set_cs_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case CS_TRACE_CLK:
            if (pclk_mngr_set_cs_trace_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        case CS_PDBG_CLK:
            if (pclk_mngr_set_cs_pdbg_clk_div(divisor) != 0U)
            {
                ret = -1;
            }
            break;

        default:
            ERROR("Not a valid clock type");
            ret = -1;
            break;
    }

    if (ret == -1)
    {
        return -EINVAL;
    }

    return 0;
}

int32_t clk_mngr_get_divisor(uint32_t clock_type, uint8_t *divisor)
{
    switch (clock_type)
    {
        case L4_SYS_FREE_CLK:
            *divisor = pclk_mngr_get_l4_sys_free_clk_div();
            break;

        case L4_MP_CLK:
            *divisor = pclk_mngr_get_l4_mp_clk_div();
            break;

        case L4_SP_CLK:
            *divisor = pclk_mngr_get_l4_sp_clk_div();
            break;

        case SOFT_PHY_DIV:
            *divisor = pclk_mngr_get_soft_phy_div();
            break;

        case CCU_DIV:
            *divisor = pclk_mngr_get_ccu_div();
            break;

        case MPU_PERIPH_DIV:
            *divisor = pclk_mngr_get_mpu_periph_div();
            break;

        case CS_CLK:
            *divisor = pclk_mngr_get_cs_clk_div();
            break;

        case CS_TRACE_CLK:
            *divisor = pclk_mngr_get_cs_trace_clk_div();
            break;

        case CS_PDBG_CLK:
            *divisor = pclk_mngr_get_cs_pdbg_clk_div();
            break;

        default:
            ERROR("Not a valid clock type");
            *divisor = 0U;
            break;
    }

    if (*divisor == 0U)
    {
        return -EINVAL;
    }
    return 0;
}
