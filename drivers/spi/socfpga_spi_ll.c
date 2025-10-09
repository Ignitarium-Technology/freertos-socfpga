/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SPI
 */

#include "socfpga_defines.h"
#include "socfpga_spi_ll.h"
#include "socfpga_clk_mngr.h"
#include "socfpga_spi_reg.h"
#include "socfpga_rst_mngr.h"

/**
 * @brief Enable the clock for the SPI instance.
 */
static void spi_enable_clock(uint32_t instance)
{
    uint32_t val;
    val = RD_REG32(CLK_PERPLL);
    if (instance == 1U)
    {
        val |= ((uint32_t)1U << (CLK_SPIM1_SHIFT + instance));
    }
    else
    {
        val |= (1U << (CLK_SPIM0_SHIFT + instance));
    }
    WR_REG32(CLK_PERPLL_EN, val);
}

/**
 * @brief Disable the clock for the SPI instance.
 */
static void spi_disable_clock(uint32_t instance)
{
    uint32_t val;
    val = RD_REG32(CLK_PERPLL);
    if (instance == 1U)
    {
        val &= ~((uint32_t)1U << (CLK_SPIM1_SHIFT + instance));
    }
    else
    {
        val &= ~(1U << (CLK_SPIM0_SHIFT + instance));
    }
    WR_REG32(CLK_PERPLL_EN, val);
}

/**
 * @brief Enable SPI serial interface.
 */
void spi_enable(uint32_t base_address)
{
    uint32_t val;
    val = 0U;
    val |= 1U << SPI_SSIENR_SSI_EN_POS;
    WR_REG32((base_address + SPI_SSIENR), val);
}

/**
 * @brief Disable SPI serial interface.
 */
void spi_disable(uint32_t base_address)
{
    uint32_t val;
    val = 0U;
    val &= ~(1U >> SPI_SSIENR_SSI_EN_POS);
    WR_REG32((base_address + SPI_SSIENR), val);
}

/**
 * @brief Set SPI FIFO threshold.
 */
static void spi_set_fifo_threshold(uint32_t base_address)
{
    uint32_t val;

    /*transmit FIFO threshold setting*/
    val = RD_REG32(base_address + SPI_TXFTLR);
    val |= (SPI_TX_FIFO_THRESHOLD << SPI_TXFTLR_TFT_POS);
    WR_REG32((base_address + SPI_TXFTLR), val);

    /*receive FIFO threshold setting*/
    val = RD_REG32(base_address + SPI_RXFTLR);
    val |= (SPI_RX_FIFO_THRESHOLD << SPI_RXFTLR_RFT_POS);
    WR_REG32((base_address + SPI_RXFTLR), val);
}

/**
 * @brief Initialize SPI instance.
 */
void spi_init(uint32_t instance)
{
    int32_t i;
    spi_enable_clock(instance);

    if (instance == 1U)
    {
        if (rstmgr_assert_reset(RST_SPIM1) != 0)
        {
            return;
        }
    }
    else
    {
        if (rstmgr_assert_reset(RST_SPIM0) != 0)
        {
            return;
        }
    }

    for (i = 0; i < 100; i++)
    {
    }
    if (instance == 1U)
    {
        if (rstmgr_deassert_reset(RST_SPIM1) != 0)
        {
            return;
        }
    }
    else
    {
        if (rstmgr_deassert_reset(RST_SPIM0) != 0)
        {
            return;
        }
    }

    spi_set_fifo_threshold(GET_BASE_ADDRESS(instance));
}

/**
 * @brief Deinitialize SPI instance.
 */
void spi_deinit(uint32_t instance)
{
    spi_disable(GET_BASE_ADDRESS(instance));
    spi_disable_clock(instance);
    spi_enable(GET_BASE_ADDRESS(instance));
}

/**
 * @brief Set SPI configuration.
 */
void spi_set_config(uint32_t base_address, uint32_t freq, spi_mode_t mode)
{
    uint32_t sclk_dvsr;
    uint32_t spi_clk = 0U;
    uint32_t val;

    spi_disable(base_address);

    val = RD_REG32(base_address + SPI_CTRLR0);
    val &= ~((uint32_t)3U >> SPI_CTRLR0_SPI_FRF_POS);
    WR_REG32((base_address + SPI_CTRLR0), val);

    switch (mode)
    {
        case SPI_MODE1:
            val |= 1U << SPI_CTRLR0_SCPH_POS;
            WR_REG32((base_address + SPI_CTRLR0), val);
            break;

        case SPI_MODE2:
            val |= 1U << SPI_CTRLR0_SCPOL_POS;
            WR_REG32((base_address + SPI_CTRLR0), val);
            break;

        case SPI_MODE3:
            val |= 1U << SPI_CTRLR0_SCPH_POS;
            val |= 1U << SPI_CTRLR0_SCPOL_POS;
            WR_REG32((base_address + SPI_CTRLR0), val);
            break;

        default:
            /* mode SPI_MODE0 */
            break;
    }

    if (clk_mngr_get_clk(CLOCK_SSPI, &spi_clk) != 0U)
    {
        return;
    }
    if (freq == 0U)
    {
        return;
    }

    sclk_dvsr = spi_clk / freq;
    val = RD_REG32(base_address + SPI_BAUDR);
    val |= sclk_dvsr;
    WR_REG32((base_address + SPI_BAUDR), val);
}

/**
 * @brief Get SPI configuration parameters
 */
void spi_get_config(uint32_t base_address, uint32_t *freq, spi_mode_t *mode)
{
    uint32_t val;
    uint32_t bf_val;
    val = 0U;
    bf_val = 0U;

    *freq = spi_get_freq(base_address);

    val = RD_REG32(base_address + SPI_CTRLR0);
    bf_val = (val >> SPI_CTRLR0_SCPH_POS) & 3U;

    if (bf_val == 3U)
    {
        *mode = SPI_MODE3;
    }

    else if (bf_val == 2U)
    {
        *mode = SPI_MODE2;
    }

    else if (bf_val == 1U)
    {
        *mode = SPI_MODE1;
    }

    else
    {
        *mode = SPI_MODE0;
    }
}

/**
 * @brief Set SPI transfer mode.
 */
void spi_set_transfermode(uint32_t base_address, uint32_t mode)
{
    uint32_t val = 0U;

    val = RD_REG32(base_address + SPI_CTRLR0);

    val &= ~((uint32_t)3U << SPI_CTRLR0_TMOD_POS);
    val |= mode << SPI_CTRLR0_TMOD_POS;

    WR_REG32((base_address + SPI_CTRLR0), val);
}

/**
 * @brief Get SPI transfer frequency.
 */
uint32_t spi_get_freq(uint32_t base_address)
{
    uint32_t sclk_dvsr, spi_clk = 0U;
    uint32_t freq;

    if (clk_mngr_get_clk(CLOCK_SSPI, &spi_clk) != 0U)
    {
        return 0U;
    }
    if (spi_clk == 0U)
    {
        return 0U;
    }

    sclk_dvsr = RD_REG32(base_address + SPI_BAUDR);
    if (sclk_dvsr == 0U)
    {
        return 0U;
    }
    freq = spi_clk / sclk_dvsr;

    return freq;
}

/**
 * @brief Select SPI slave
 */
void spi_select_chip(uint32_t instance, uint32_t slave)
{
    uint32_t base_address;
    uint32_t val;
    base_address = GET_BASE_ADDRESS(instance);

    val = RD_REG32(base_address + SPI_SER);
    val &= ~(SPI_SER_SER_MASK << 0);
    WR_REG32((base_address + SPI_SER), val);

    switch (slave)
    {
        case 1U:
            val = 1U;
            break;
        case 2U:
            val = 2U;
            break;
        case 3U:
            val = 4U;
            break;
        case 4U:
            val = 8U;
            break;
        default:
            val = 0U;
            break;
    }
    WR_REG32((base_address + SPI_SER), val);
}

/**
 * @brief Write data to Tx FIFO.
 */
uint16_t spi_write_fifo(uint32_t base_address, uint8_t *buffer, uint16_t bytes)
{
    uint16_t bytes_done = 0;

    /* dummy write */
    if (buffer == NULL)
    {
        while (bytes > 0U)
        {
            if (((RD_REG32(base_address + SPI_SR) >> SPI_SR_TFNF_POS) & 1U) ==
                    1U)
            {
                WR_REG32((base_address + SPI_DR0), 0x55U);
                bytes_done++;
                bytes--;
            }
            else
            {
                break;
            }
        }
    }

    else
    {
        while (bytes > 0U)
        {
            if (((RD_REG32(base_address + SPI_SR) >> SPI_SR_TFNF_POS) & 1U) ==
                    1U)
            {
                WR_REG32((base_address + SPI_DR0), buffer[bytes_done]);
                bytes_done++;
                bytes--;
            }
            else
            {
                break;
            }
        }
    }
    return bytes_done;
}

/**
 * @brief Read data from Rx FIFO.
 */
uint16_t spi_read_fifo(uint32_t base_address, uint8_t *buffer, uint16_t bytes)
{
    uint16_t bytes_done = 0;

    /* dummy read */
    if (buffer == NULL)
    {
        while (bytes > 0U)
        {
            if (((RD_REG32(base_address + SPI_SR) >> SPI_SR_RFNE_POS) & 1U) ==
                    1U)
            {
                (void)RD_REG32(base_address + SPI_DR0);
                bytes_done++;
                bytes--;
            }
            else
            {
                break;
            }
        }

    }

    else
    {
        while (bytes > 0U)
        {
            if (((RD_REG32(base_address + SPI_SR) >> SPI_SR_RFNE_POS) & 1U) ==
                    1U)
            {
                buffer[bytes_done] = (uint8_t)RD_REG32(base_address + SPI_DR0);
                bytes_done++;
                bytes--;
            }
            else
            {
                break;
            }
        }
    }
    return bytes_done;
}

/**
 * @brief Get SPI interrupt status.
 */
uint8_t spi_get_interrupt_status(uint32_t base_address)
{
    volatile uint32_t val;

    val = RD_REG32(base_address + SPI_ISR);
    val &= 0xFFU;

    if (val == TX_EMPTY)
    {
        return SPI_TX_EMPTY_INT;
    }
    if (((val >> SPI_ISR_RXFIS_POS) & 1U) == 1U)
    {
        return SPI_RX_FULL_INT;
    }
    return SPI_NO_INTERRUPT;
}

/**
 * @brief Enable SPI interrupts
 */
void spi_enable_interrupt(uint32_t base_address, uint32_t ir_id)
{
    uint32_t val;
    val = RD_REG32(base_address + SPI_IMR);

    switch (ir_id)
    {
        case SPI_TX_EMPTY_INT:
            val |= 1U << SPI_IMR_TXEIM_POS;
            break;

        case SPI_RX_FULL_INT:
            val |= 1U << SPI_IMR_RXFIM_POS;
            break;

        case SPI_ALL_INTERRUPTS:
            val |= (63U << SPI_IMR_TXEIM_POS);
            break;

        default:
            /* do nothing */
            break;
    }

    WR_REG32((base_address + SPI_IMR), val);
}

/**
 * @brief Disable SPI interrupts
 */
void spi_disable_interrupt(uint32_t base_address, uint32_t ir_id)
{
    uint32_t val;
    val = RD_REG32(base_address + SPI_IMR);

    switch (ir_id)
    {
        case SPI_TX_EMPTY_INT:
            val &= ~(1U << SPI_IMR_TXEIM_POS);
            break;

        case SPI_RX_FULL_INT:
            val &= ~(1U << SPI_IMR_RXFIM_POS);
            break;

        case SPI_ALL_INTERRUPTS:
            val &= ~(63U << SPI_IMR_TXEIM_POS);
            break;

        default:
            /* do nothing */
            break;
    }

    WR_REG32((base_address + SPI_IMR), val);
}
