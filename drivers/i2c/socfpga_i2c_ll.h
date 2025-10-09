/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for i2c ll driver
 */

#ifndef __SOCFPGA_I2C_LL_H__
#define __SOCFPGA_I2C_LL_H__

#include <stdint.h>

/*Max number of i2c instances*/
#define MAX_I2C_INSTANCES    5U

#define I2C_NO_INT          0U           /*!< No interrupt*/
#define I2C_TX_EMPTY_INT    1U           /*!< Tx FIFO Empty interrupt*/
#define I2C_RX_FULL_INT     2U           /*!< Rx FIFO Full interrupt*/
#define I2C_TX_ABORT_INT    4U           /*!< Tx Abort interrupt*/

void i2c_enable_interrupt(uint32_t base_addr, uint32_t interrupt_req);

void i2c_disable_interrupt(uint32_t base_addr, uint32_t interrupt_req);

uint32_t i2c_get_interrupt_status(uint32_t base_addr);

void i2c_clear_interrupt(uint32_t base_addr);

void i2c_set_target_addr(uint32_t base_addr, uint32_t slave_addr);

uint16_t i2c_write_fifo(uint32_t base_addr, uint8_t *const buffer, uint32_t
        bytes, BaseType_t no_stop_flag);

uint16_t i2c_enq_read_cmd(uint32_t base_addr, uint32_t bytes, BaseType_t
        no_stop_flag);

uint16_t i2c_read_fifo(uint32_t base_addr, uint8_t *const buffer, uint32_t
        bytes);

uint32_t i2c_config_master(uint32_t base_addr, uint32_t speed);

void i2c_init(uint32_t base_addr);

void i2c_ll_cancel(uint32_t base_addr);

uint32_t i2c_get_config(uint32_t base_addr);

#endif   /* ifndef __SOCFPGA_I2C_LL_H__ */
