/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA PHY
 */
#include "socfpga_defines.h"
#include "socfpga_xgmac_phy_ll.h"
#include "socfpga_xgmac_reg.h"
#include "socfpga_xgmac_ll.h"

static inline bool check_mdio_busy(uint32_t base_address)
{
    /* Read the mdio cmd control register */
    uint32_t status = RD_REG32(
            base_address + XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA);

    if ((status & XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SBUSY_MASK) != 0U)
    {
        /* mdio operation is busy */
        return 1;
    }
    else
    {
        /* MDIO is not busy */
        return 0;
    }
}

uint16_t read_phy_reg(uint32_t base_address, uint32_t phy_address, uint8_t
        phy_reg)
{
    uint32_t data;
    uint32_t addr_data;
    uint8_t count = 0;
    uint8_t max_cnt = 100;

    if (base_address == 0U)
    {
        return 0U;
    }
    /* Check MDIO sbusy bit status */
    while (check_mdio_busy(base_address))
    {
        if (count > max_cnt)
        {
            return 0U;
        }
        for (uint32_t i = 0U; i < max_cnt; i++)
        {
        }
        count++;
    }

    /* Set clause 22 format for PHY address */
    data = RD_REG32(base_address + XGMAC_MDIO_CLAUSE_22_PORT);
    data |= ((uint32_t)1 << phy_address);

    /* selecting clause to given PHY address port. */
    WR_REG32(base_address + XGMAC_MDIO_CLAUSE_22_PORT, data);

    /*
     * Read command address register and mask with our PHY address and PHY
     * register value.
     */
    addr_data = RD_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_ADDRESS);

    /*Mask PHY address and register */
    addr_data = (phy_address << XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_PA_POS) |
            ((uint32_t)phy_reg << XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_RA_POS);

    WR_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_ADDRESS, addr_data);

    /*
     * Read data from MDIO control data register. Mask with the
     * data which we want make.
     */

    /* 3'b010 corresponds to clk_csr_i: 250-300 MHz, with MDC clock: clk_csr_i/122 */
    data = ((uint32_t)4 << XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CR_POS);

    /* Mask with data var for read operation */
    data |= (XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SAADR_MASK) |
            (XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CMD_MASK) |
            (XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SBUSY_MASK);

    /* Write masked data to cmd cntrl data register */
    WR_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA, data);

    /* wait for some time */
    for (int i = 0; i < 10000; i++)
    {
    }

    /* Verify MDIO sbusy bit status */
    count = 0;
    while (check_mdio_busy(base_address))
    {
        if (count > max_cnt)
        {
            return 0U;
        }
        for (uint32_t i = 0U; i < max_cnt; i++)
        {
        }
        count++;
    }
    for (volatile uint32_t i = 0U; i < 100000U; i++)
    {
    }

    /* Read the data from the cmd control data register */
    data = RD_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA);
    uint16_t least_bits = (uint16_t)(data & 0xFFFFU);

    return least_bits;
}

int8_t write_phy_reg(uint32_t base_address, uint32_t phy_address, uint8_t
        phy_reg, uint16_t reg_val)
{
    uint32_t data;
    uint32_t addr_data;
    uint32_t count = 0;
    uint32_t max_cnt = 100;

    if (base_address == 0U)
    {
        return -1;
    }
    /* Check MDIO sbusy bit status */
    while (check_mdio_busy(base_address))
    {
        if (count > max_cnt)
        {
            return -1;
        }
        for (uint32_t i = 0U; i < max_cnt; i++)
        {
        }
        count++;
    }

    /* Set clause 22 format for PHY address */
    data = RD_REG32(base_address + XGMAC_MDIO_CLAUSE_22_PORT);
    data |= ((uint32_t)1 << phy_address);

    /* Selecting clause to given PHY address port. */
    WR_REG32(base_address + XGMAC_MDIO_CLAUSE_22_PORT, data);

    /*
     * Read command address register and mask with our PHY address and PHY
     * register value.
     */
    addr_data = RD_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_ADDRESS);

    /* Mask the phy_address and phy_register to mdio_register */
    addr_data = (phy_address << XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_PA_POS) |
            ((uint32_t)phy_reg << XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_RA_POS);

    WR_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_ADDRESS, addr_data);

    /*
     * Read data MDIO control data register. Mask with the
     * data which we want make.
     */
    data = RD_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA);

    /* Set the application Clock Range 350-400 MHz */
    data = ((uint32_t)4 << XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CR_POS);

    data |= (XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SAADR_MASK) |
            ((uint32_t)1 << XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CMD_POS) |
            (XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SBUSY_MASK) |
            ((uint32_t)reg_val << XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SDATA_POS);

    /* Write masked data to MDIO cmd cntrl data register */
    WR_REG32(base_address + XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA, data);

    for (uint32_t i = 0U; i < (max_cnt * 10000U); i++)
    {
    }
    count = 0U;
    while (check_mdio_busy(base_address))
    {
        if (count > max_cnt)
        {
            return -1;
        }
        for (uint32_t i = 0U; i < max_cnt; i++)
        {
        }
        count++;
    }

    return 0;
}
