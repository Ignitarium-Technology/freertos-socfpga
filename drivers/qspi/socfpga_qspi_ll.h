/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for QSPI low level driver
 */

#ifndef __SOCFPGA_QSPI_LL_H__
#define __SOCFPGA_QSPI_LL_H__

#include <stdint.h>


uint32_t qspi_is_busy(void);

void qspi_disable(void);

uint32_t qspi_get_int_status(void);

void  qspi_clear_indwr_op_status(void);

void  qspi_clear_indrd_op_status(void);

void qspi_set_int_status(uint32_t status);

void qspi_enable_interrupt(uint32_t irqmask);

void qspi_disable_interrupt(uint32_t irqmask);

void qspi_set_instruction_width(uint32_t width);

void qspi_enable_mode_bit(uint32_t enable);

void qspi_set_bytes_per_page(uint32_t page_bytes);

void qspi_set_nss_delay(uint32_t nss_delay);

void qspi_set_btwn_delay(uint32_t btwn_delay);

void qspi_set_after_delay(uint32_t after_delay);

void qspi_set_init_delay(uint32_t init_delay);

void qspi_set_remap_address(uint32_t address);

void qspi_set_baud_divisor(uint32_t divisor);

void qspi_enable(void);

void qspi_set_indwrstaddr(uint32_t address);

void qspi_set_indwrcnt(uint32_t n_bytes);

void qspi_start_indwr(void);

void qspi_set_indrdstaddr(uint32_t address);

void qspi_set_indrdcnt(uint32_t n_bytes);

void qspi_start_indrd(void);

void qspi_set_flashcmdaddr(uint32_t address);

void qspi_set_flashcmd(uint32_t cmd_opcode);

void qspi_flashcmd_exec(void);

void qspi_select_chip(uint32_t cs);

uint32_t qspi_get_flashcmd_stat(void);

uint32_t qspi_get_sramfill(void);

void qspi_set_indwrwater(uint32_t level);

void qspi_set_indrdwater(uint32_t level);

uint32_t qspi_reg_get_data(uint32_t reg);

void qspi_enable_fast_read_mode(void);

void qspi_set_addr_width(uint32_t width);

void qspi_set_data_width(uint32_t width);

void qspi_set_dummy_delay(uint8_t dum_delay);

void qspi_cfg_write_mode(void);

void qspi_set_flashcmdaddrbytes(uint32_t addr_bytes);

void qspi_flashcmd_write_bytes(uint32_t bytes);

void qspi_flashcmd_read_bytes(uint32_t bytes);

void qspi_flashcmd_read_data(void);

void qspi_set_enablecmdaddr(void);

uint32_t qspi_flash_cmd_rddata0(void);

uint32_t qspi_flash_cmd_rddata1(void);

void qspi_flashcmd_write_data(void);

void qspi_flash_cmd_wrdata0(uint32_t data);

void qspi_flash_cmd_wrdata1(uint32_t data);

uint32_t qspi_get_indwr_multiop_status(void);

#endif // __SOCFPGA_QSPI_H__
