/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA i2c
 */

#include "socfpga_defines.h"
#include "socfpga_i2c.h"
#include "socfpga_i2c_ll.h"
#include "socfpga_i2c_reg.h"

#define I2C_CONTRL_STD_SPEED     (0x01U)
#define I2C_CONTRL_FAST_SPEED    (0x02U)
#define I2C_CONTRL_HIGH_SPEED    (0x03U)

/*
 * Clock counts for various speed modes
 *
 * The peripheral clock for i2c is 100 MHz
 */

#define SS_SCL_HCNT_VAL    400U
#define SS_SCL_LCNT_VAL    470U
#define FS_SCL_HCNT_VAL    60U
#define FS_SCL_LCNT_VAL    130U

/**
 * @brief Enable I2C interrupt
 */
void i2c_enable_interrupt(uint32_t base_addr, uint32_t interrupt_req)
{
    uint32_t val;
    val = RD_REG32(base_addr + I2C_INTR_MASK);
    if ((interrupt_req & I2C_TX_EMPTY_INT) == I2C_TX_EMPTY_INT)
    {
        val |= I2C_INTR_MASK_M_TX_EMPTY_MASK;
    }
    if ((interrupt_req & I2C_RX_FULL_INT) == I2C_RX_FULL_INT)
    {
        val |= I2C_INTR_MASK_M_RX_FULL_MASK;
    }
    if ((interrupt_req & I2C_TX_ABORT_INT) == I2C_TX_ABORT_INT)
    {
        val |= I2C_INTR_MASK_M_TX_ABRT_MASK;
    }
    WR_REG32(base_addr + I2C_INTR_MASK, val);
}

/**
 * @brief Disable I2C interrupt
 */
void i2c_disable_interrupt(uint32_t base_addr, uint32_t interrupt_req)
{
    uint32_t val;
    val = RD_REG32(base_addr + I2C_INTR_MASK);
    if ((interrupt_req & I2C_TX_EMPTY_INT) == I2C_TX_EMPTY_INT)
    {
        val &= ~(I2C_INTR_MASK_M_TX_EMPTY_MASK);
    }
    if ((interrupt_req & I2C_RX_FULL_INT) == I2C_RX_FULL_INT)
    {
        val &= ~(I2C_INTR_MASK_M_RX_FULL_MASK);
    }
    if ((interrupt_req & I2C_TX_ABORT_INT) == I2C_TX_ABORT_INT)
    {
        val &= ~(I2C_INTR_MASK_M_TX_ABRT_MASK);
    }
    WR_REG32(base_addr + I2C_INTR_MASK, val);
}

/**
 * @brief Get I2C interrupt status
 */
uint32_t i2c_get_interrupt_status(uint32_t base_addr)
{
    uint32_t res = I2C_NO_INT;
    uint32_t val;
    val = RD_REG32(base_addr + I2C_INTR_STAT);
    if ((val & I2C_INTR_STAT_R_TX_EMPTY_MASK) != 0U)
    {
        res |= I2C_TX_EMPTY_INT;
    }
    if ((val & I2C_INTR_STAT_R_RX_FULL_MASK) != 0U)
    {
        res |= I2C_RX_FULL_INT;
    }
    if ((val & I2C_INTR_MASK_M_TX_ABRT_MASK) != 0U)
    {
        res |= I2C_TX_ABORT_INT;
    }
    return res;
}

/**
 * @brief Clear I2C interrupt
 */
void i2c_clear_interrupt(uint32_t base_addr)
{
    /*
     * reading Clear Interrupt register will clear all the interrupts
     * than can be cleared by software
     */
    (void)RD_REG32(base_addr + I2C_CLR_INTR);
}

/**
 * @brief Set target address
 */
void i2c_set_target_addr(uint32_t base_addr, uint32_t slave_addr)
{
    uint32_t val;
    /*Disable i2c*/
    val = RD_REG32(base_addr + I2C_ENABLE);
    val &= ~(1U << I2C_ENABLE_ENABLE_POS);
    WR_REG32(base_addr + I2C_ENABLE, val);

    /*
     * Set the Target address
     * And keep the 10 bit addressing enable cleared
     */
    val = ((slave_addr) << I2C_TAR_IC_TAR_POS);
    WR_REG32(base_addr + I2C_TAR, val);

    /*Enable i2c*/
    val = RD_REG32(base_addr + I2C_ENABLE);
    val |= (1U << I2C_ENABLE_ENABLE_POS);
    WR_REG32(base_addr + I2C_ENABLE, val);
}

/**
 * @brief Write data to the I2C FIFO
 */
uint16_t i2c_write_fifo(uint32_t base_addr, uint8_t *const buf, uint32_t nbytes,
        BaseType_t no_stop_flag)
{
    uint16_t nwr;
    uint32_t val;
    /*Write data to the data command register*/
    for (nwr = 0; nwr < nbytes; nwr++)
    {
        /* Exit if fifo is full */
        if (((RD_REG32(base_addr + I2C_STATUS)) & I2C_STATUS_TFNF_MASK) == 0U)
        {
            break;
        }
        /* For the last byte we may need to add stop */
        else if ((nwr == (nbytes - 1U)) && (!no_stop_flag))
        {
            /* Write with stop */
            val = buf[nwr];
            val |= ((uint32_t)1U << I2C_DATA_CMD_STOP_POS);
        }
        else
        {
            /* Write with no stop */
            val = buf[nwr];
        }

        WR_REG32(base_addr + I2C_DATA_CMD, val);
    }
    return nwr;
}

/**
 * @brief Enqueue read commands
 */
uint16_t i2c_enq_read_cmd(uint32_t base_addr, uint32_t nbytes, BaseType_t no_stop_flag)
{
    uint16_t ncmd;
    uint32_t val;

    for (ncmd = 0; ncmd < nbytes; ncmd++)
    {
        /* exit if fifo full*/
        if (((RD_REG32(base_addr + I2C_STATUS)) & I2C_STATUS_TFNF_MASK) == 0U)
        {
            break;
        }
        /* For the last byte we may need to add stop */
        else if ((ncmd == (nbytes - 1U)) && (!no_stop_flag))
        {
            /* read command with stop */
            val = ((uint32_t)1U << I2C_DATA_CMD_STOP_POS) | ((uint32_t)1U << I2C_DATA_CMD_CMD_POS);
        }
        else
        {
            /*  read command with no stop */
            val = ((uint32_t)1U << I2C_DATA_CMD_CMD_POS);
        }

        WR_REG32(base_addr + I2C_DATA_CMD, val);
    }
    return ncmd;
}

/**
 * @brief Read data from the I2C FIFO
 */
uint16_t i2c_read_fifo(uint32_t base_addr, uint8_t *const buf, uint32_t nbytes)
{
    uint16_t nrd;
    uint32_t val;

    for (nrd = 0; nrd < nbytes; nrd++)
    {
        /* Exit if fifo is empty */
        if (((RD_REG32(base_addr + I2C_STATUS)) & I2C_STATUS_RFNE_MASK) == 0U)
        {
            break;
        }
        val = RD_REG32(base_addr + I2C_DATA_CMD);
        buf[nrd] = (uint8_t)val & I2C_DATA_CMD_DAT_MASK;
    }
    return nrd;
}

/**
 * @brief Configure I2C master parameters
 */
uint32_t i2c_config_master(uint32_t base_addr, uint32_t speed)
{
    uint32_t val;

    /* Disable i2c module while configuring the speed */
    val = RD_REG32(base_addr + I2C_ENABLE);
    val &= ~(1U << I2C_ENABLE_ENABLE_POS);
    WR_REG32(base_addr + I2C_ENABLE, val);

    if (speed <= I2C_STANDARD_MODE_BPS)
    {
        val = RD_REG32(base_addr + I2C_CON) & ~I2C_CON_SPEED_MASK;
        val |= (I2C_CONTRL_STD_SPEED << I2C_CON_SPEED_POS);
        WR_REG32(base_addr + I2C_CON, val);

        WR_REG32(base_addr + I2C_SS_SCL_HCNT, SS_SCL_HCNT_VAL);
        WR_REG32(base_addr + I2C_SS_SCL_LCNT, SS_SCL_HCNT_VAL);
    }
    else if ((speed > I2C_STANDARD_MODE_BPS) && (speed <=
            I2C_FAST_MODE_PLUS_BPS))
    {
        val = RD_REG32(base_addr + I2C_CON) & ~I2C_CON_SPEED_MASK;
        val |= (I2C_CONTRL_FAST_SPEED << I2C_CON_SPEED_POS);
        WR_REG32(base_addr + I2C_CON, val);

        WR_REG32(base_addr + I2C_FS_SCL_HCNT, FS_SCL_HCNT_VAL);
        WR_REG32(base_addr + I2C_FS_SCL_LCNT, FS_SCL_HCNT_VAL);
    }
    else if ((speed > I2C_FAST_MODE_PLUS_BPS) && (speed <= I2C_HIGH_SPEED_BPS))
    {
        val = RD_REG32(base_addr + I2C_CON) & ~I2C_CON_SPEED_MASK;
        val |= (I2C_CONTRL_HIGH_SPEED << I2C_CON_SPEED_POS);
        WR_REG32(base_addr + I2C_CON, val);
        WR_REG32(base_addr + I2C_SS_SCL_HCNT, SS_SCL_HCNT_VAL);
        WR_REG32(base_addr + I2C_SS_SCL_LCNT, SS_SCL_HCNT_VAL);

    }
    else
    {
        return 0;
    }

    /* Enable the i2c module */
    val = RD_REG32(base_addr + I2C_ENABLE);
    val |= (1U << I2C_ENABLE_ENABLE_POS);
    WR_REG32(base_addr + I2C_ENABLE, val);

    return 1;
}

/**
 * @brief Get I2C configuration parameters
 */
uint32_t i2c_get_config(uint32_t base_addr)
{
    uint32_t baud = 0U;
    i2c_mode_t val = (i2c_mode_t)((RD_REG32(base_addr + I2C_CON) &
            I2C_CON_SPEED_MASK) >> I2C_CON_SPEED_POS);

    if (val == I2C_MODE_FAST)
    {
        baud = I2C_FAST_MODE_BPS;
    }
    else if (val == I2C_MODE_HS)
    {
        baud = I2C_HIGH_SPEED_BPS;
    }
    else
    {
        baud = I2C_STANDARD_MODE_BPS;
    }
    return baud;
}

/**
 * @brief Initializes I2C peripheral
 */
void i2c_init(uint32_t base_addr)
{
    uint32_t val;
    /*Disable i2c*/
    WR_REG32(base_addr + I2C_ENABLE, 0);

    /*
     * Configure I2C control register
     * 1. Enable master mode
     * 2. Set to standard speed
     * 3. Disable i2c slave
     * 4. Set restart enable
     */
    val = 1U << I2C_CON_MASTER_MODE_POS;
    val |= 1U << I2C_CON_IC_SLAVE_DISABLE_POS;
    val |= 1U << I2C_CON_IC_RESTART_EN_POS;
    val |= I2C_CONTRL_STD_SPEED << I2C_CON_SPEED_POS;
    WR_REG32(base_addr + I2C_CON, val);

    /* Mask all interrupts */
    WR_REG32(base_addr + I2C_INTR_MASK, 0);

    /*Enable i2c*/
    val = (1U << I2C_ENABLE_ENABLE_POS);
    WR_REG32(base_addr + I2C_ENABLE, val);
}

/**
 * @brief Cancel current transaction
 */
void i2c_ll_cancel(uint32_t base_addr)
{
    uint32_t val;
    /* Abort current operation */
    val = RD_REG32(base_addr + I2C_ENABLE);
    val |= I2C_ENABLE_ABORT_MASK;
    WR_REG32(base_addr + I2C_ENABLE, val);

    /* Clear all abort interrupts */
    (void)RD_REG32(base_addr + I2C_CLR_TX_ABRT);
}
