/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for SPI low level driver
 */

#ifndef __SOCFPGA_SPI_LL_H__
#define __SOCFPGA_SPI_LL_H__

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "socfpga_spi.h"

#include "socfpga_spi_reg.h"

#define SPI_GET_INT_ID(instance)    (((instance) == 1U) ? SPI1IRQ: SPI0IRQ)

#define SPI_TX_RX_MOD    0x00U
#define SPI_TX_MOD       0x01U
#define SPI_RX_MOD       0x02U

#define SPI_TX_FIFO_THRESHOLD    127U
#define SPI_RX_FIFO_THRESHOLD    0U

#define SPI_NO_INTERRUPT      0x00U
#define SPI_TX_EMPTY_INT      0x01U
#define SPI_RX_FULL_INT       0x02U
#define SPI_ALL_INTERRUPTS    0x03U

#define TX_EMPTY    0x01U
#define RX_FULL     0x10U

void spi_init(uint32_t instance);
void spi_deinit(uint32_t instance);

void spi_select_chip(uint32_t instance, uint32_t slave);
void spi_set_config(uint32_t base_address, uint32_t freq, spi_mode_t mode);
void spi_get_config(uint32_t base_address, uint32_t *freq, spi_mode_t *mode);
void spi_set_transfermode(uint32_t base_address, uint32_t mode);

void spi_enable(uint32_t base_address);
void spi_disable(uint32_t base_address);

uint32_t spi_get_freq(uint32_t base_address);

uint16_t spi_write_fifo(uint32_t base_address, uint8_t *buffer, uint16_t bytes);
uint16_t spi_read_fifo(uint32_t base_address, uint8_t *buffer, uint16_t bytes);

uint8_t spi_get_interrupt_status(uint32_t base_address);
void spi_enable_interrupt(uint32_t base_address, uint32_t ir_id);
void spi_disable_interrupt(uint32_t base_address, uint32_t ir_id);

#endif /* __SOCFPGA_SPI_H__ */
