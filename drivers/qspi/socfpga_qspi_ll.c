/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for QSPI
 */

#include <string.h>
#include <FreeRTOSConfig.h>

#include "socfpga_defines.h"
#include "socfpga_qspi_reg.h"
#include "socfpga_qspi_ll.h"

/**
 * @brief Check whether the flash device is busy.
 *
 * @param NONE
 *
 * @return 0 if the device is idle.
 * @return 1 if the device is busy.
 */
uint32_t qspi_is_busy(void)
{
    uint32_t count = 0U;
    uint32_t status = 0U;
    /* Check the busy status for
     * some iterartions as this a
     * retimed signal
     */
    while (count < 1000U)
    {
        if ((RD_REG32(QSPI_CFG) & QSPI_CFG_IDLE_MASK) != 0U)
        {
            /* Idle mode */
            status = 0U;
            break;
        }
        count++;
    }
    if (count >= 1000U)
    {
        status = 1U;
    }
    return status;
}

/**
 * @brief Disable the QSPI controller.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_disable(void)
{
    uint32_t cfg = RD_REG32(QSPI_CFG);
    cfg &= ~(QSPI_CFG_EN_MASK);
    WR_REG32(QSPI_CFG, cfg);
}

/**
 * @brief Read the lower 4 bytes of response from flash.
 *
 * @param NONE
 *
 * @return data The lower 4 bytes of data.
 */
uint32_t qspi_flash_cmd_rddata0(void)
{
    return RD_REG32(QSPI_FLASHCMDRDDATALO);
}

/**
 * @brief Read the higher 4 bytes of response from flash.
 *
 * @param NONE
 *
 * @return data The higher 4 bytes of data.
 */
uint32_t qspi_flash_cmd_rddata1(void)
{
    return RD_REG32(QSPI_FLASHCMDRDDATAUP);
}

/**
 * @brief Write the lower 4 bytes of data to be sent to the flash device.
 *
 * @param[in] data The lower 4 bytes of data to be sent to the flash device.
 *
 * @return NONE
 */
void qspi_flash_cmd_wrdata0(uint32_t data)
{
    WR_REG32(QSPI_FLASHCMDWRDATALO, data);
}

/**
 * @brief Write the higher 4 bytes of data to be sent to the flash device.
 *
 * @param[in] data The higher 4 bytes of data to be sent to the flash device.
 *
 * @return NONE
 */
void qspi_flash_cmd_wrdata1(uint32_t data)
{
    WR_REG32(QSPI_FLASHCMDWRDATAUP, data);
}

/**
 * @brief Set the instruction width.
 *
 * @param[in] width The instruction width that has to be configured.
 *
 * @return NONE
 */
void qspi_set_instruction_width(uint32_t width)
{
    uint32_t devrd = RD_REG32(QSPI_DEVRD);
    devrd = (devrd & ~((uint32_t)0x3U << 8U)) | ((width & 0x3U) << 8U);
    WR_REG32(QSPI_DEVRD, devrd);
}

/**
 * @brief Set the address width in the devrd register.
 *
 * @param[in] width The address width.
 *
 * @return NONE
 */
void qspi_set_addr_width(uint32_t width)
{
    uint32_t devrd = RD_REG32(QSPI_DEVRD);
    devrd = (devrd & ~((uint32_t)0x3U << 12U)) | ((width & 0x3U) << 12U);
    WR_REG32(QSPI_DEVRD, devrd);
}

/**
 * @brief Set the data width in devrd register.
 *
 * @param[in] width The data width.
 *
 * @return NONE
 */
void qspi_set_data_width(uint32_t width)
{
    uint32_t devrd = RD_REG32(QSPI_DEVRD);
    devrd = (devrd & ~((uint32_t)0x3U << 16U)) | ((width & 0x3U) << 16U);
    WR_REG32(QSPI_DEVRD, devrd);
}

/**
 * @brief Enable or disable the mode bit in the devrd register.
 *
 * @param[in] enable 1 for enable and 0 for disable.
 *
 * @return NONE
 */
void qspi_enable_mode_bit(uint32_t enable)
{
    uint32_t devrd = RD_REG32(QSPI_DEVRD);
    if (enable != 0U)
    {
        devrd |= ((uint32_t)1U << 20U);
    }
    else
    {
        devrd &= ~((uint32_t)1U << 20U);
    }
    WR_REG32(QSPI_DEVRD, devrd);
}

/**
 * @brief Enable fast read mode.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_enable_fast_read_mode(void)
{
    uint32_t devrd = RD_REG32(QSPI_DEVRD);
    devrd &= ~(0xFU);
    devrd |= (0xBU);
    WR_REG32(QSPI_DEVRD, devrd);
}

/**
 * @brief Obtain a flash handle.
 *
 * @param[in] flash_dev Instance of the I3C controller.
 *
 * @return NULL if invalid argument is passed.
 * @return flash_handle_t if open is successful.
 */
void qspi_cfg_write_mode(void)
{
    uint32_t devwr = RD_REG32(QSPI_DEVWR);
    devwr &= ~(0xFU);
    devwr |= (0x2U);
    WR_REG32(QSPI_DEVWR, devwr);
}

/**
 * @brief Configure the dummy delay.
 *
 * @param[in] dum_delay The dummy delay value.
 *
 * @return NONE
 */
void qspi_set_dummy_delay(uint8_t dum_delay)
{
    uint32_t delay = RD_REG32(QSPI_DEVRD);
    delay = (delay & ~((uint32_t)0x1FU << 24U)) | (((uint32_t)dum_delay &
            0x1FU) << 24U);
    WR_REG32(QSPI_DEVRD, delay);
}

/**
 * @brief Set the number of bytes per page.
 *
 * @param[in] page_bytes The number of bytes to be configured per page.
 *
 * @return NONE
 */
void qspi_set_bytes_per_page(uint32_t page_bytes)
{
    uint32_t devsz = RD_REG32(QSPI_DEVSZ);
    devsz = (devsz & ~(0xFFFU << 4U)) | ((page_bytes & 0xFFFU) << 4U);
    WR_REG32(QSPI_DEVSZ, devsz);
}

/**
 * @brief Set the nss delay value in delay register.
 *
 * @param[in] nss_delay The nss delay value.
 *
 * @return NONE
 */
void qspi_set_nss_delay(uint32_t nss_delay)
{
    uint32_t delay = RD_REG32(QSPI_DELAY);
    delay = (delay & ~((uint32_t)0xFFU << 24U)) | ((nss_delay & 0xFFU) << 24U);
    WR_REG32(QSPI_DELAY, delay);
}

/**
 * @brief Set the btwn delay value in delay register.
 *
 * @param[in] btwn_delay The btwn delay value.
 *
 * @return NONE
 */
void qspi_set_btwn_delay(uint32_t btwn_delay)
{
    uint32_t delay = RD_REG32(QSPI_DELAY);
    delay = (delay & ~((uint32_t)0xFFU << 16U)) | ((btwn_delay & 0xFFU) << 16U);
    WR_REG32(QSPI_DELAY, delay);
}

/**
 * @brief Set the after delay in the delay register.
 *
 * @param[in] after_delay The after delay value.
 *
 * @return NONE
 */
void qspi_set_after_delay(uint32_t after_delay)
{
    uint32_t delay = RD_REG32(QSPI_DELAY);
    delay = (delay & ~((uint32_t)0xFFU << 8U)) | ((after_delay & 0xFFU) << 8U);
    WR_REG32(QSPI_DELAY, delay);
}

/**
 * @brief Set the init delay in the delay register.
 *
 * @param[in] init_delay The init delay value.
 *
 * @return NONE
 */
void qspi_set_init_delay(uint32_t init_delay)
{
    uint32_t delay = RD_REG32(QSPI_DELAY);
    delay = (delay & ~0xFFU) | (init_delay & 0xFFU);
    WR_REG32(QSPI_DELAY, delay);
}

/**
 * @brief Set the remap address.
 *
 * @param[in] address The remap address to be configured.
 *
 * @return NONE
 */
void qspi_set_remap_address(uint32_t address)
{
    WR_REG32(QSPI_REMAPADDR, address);
}

/**
 * @brief Set the baud divisor.
 *
 * @param[in] divisor The baud divisor factor.
 *
 * @return NONE
 */
void qspi_set_baud_divisor(uint32_t divisor)
{
    uint32_t cfg = RD_REG32(QSPI_CFG);
    cfg = (cfg & ~((uint32_t)0xFU << 19U)) | (divisor << 19U);
    WR_REG32(QSPI_CFG, cfg);
}

/**
 * @brief Enable the qspi controller.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_enable(void)
{
    uint32_t cfg = RD_REG32(QSPI_CFG);
    cfg |= (QSPI_CFG_EN_MASK);
    WR_REG32(QSPI_CFG, cfg);
}

/**
 * @brief Set the indirect read start address.
 *
 * @param[in] address The start address.
 *
 * @return NONE
 */
void qspi_set_indwrstaddr(uint32_t address)
{
    WR_REG32(QSPI_INDWRSTADDR, address);
}

/**
 * @brief Set the indirect write count.
 *
 * @param[in] n_bytes The number of bytes.
 *
 * @return NONE
 */
void qspi_set_indwrcnt(uint32_t n_bytes)
{
    WR_REG32(QSPI_INDWRCNT, n_bytes);
}

/**
 * @brief Start the indirect write operation.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_start_indwr(void)
{
    uint32_t indwr = RD_REG32(QSPI_INDWR);
    indwr |= (1U << 0U);
    WR_REG32(QSPI_INDWR, indwr);
}

/**
 * @brief Set the indirect write water mark level.
 *
 * @param[in] level The write water mark level.
 *
 * @return NONE
 */
void qspi_set_indwrwater(uint32_t level)
{
    WR_REG32(QSPI_INDWRWATER, level);
}

/**
 * @brief Set the indirect read water mark level.
 *
 * @param[in] level The read water mark level.
 *
 * @return NONE
 */
void qspi_set_indrdwater(uint32_t level)
{
    WR_REG32(QSPI_INDRDWATER, level);
}

/**
 * @brief Set the indirect read start address.
 *
 * @param[in] address The start address for indirect read.
 *
 * @return NONE
 */
void qspi_set_indrdstaddr(uint32_t address)
{
    WR_REG32(QSPI_INDRDSTADDR, address);
}

/**
 * @brief Set the indirect read count.
 *
 * @param[in] n_bytes The number of bytes for indirect read.
 *
 * @return NONE
 */
void qspi_set_indrdcnt(uint32_t n_bytes)
{
    WR_REG32(QSPI_INDRDCNT, n_bytes);
}

/**
 * @brief Start the indirect read operation.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_start_indrd(void)
{
    uint32_t indrd = RD_REG32(QSPI_INDRD);
    indrd |= (1U << 0U);
    WR_REG32(QSPI_INDRD, indrd);
}

/**
 * @brief Indicate that command is associated with an address.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_set_enablecmdaddr(void)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= QSPI_FLASHCMD_ENCMDADDR_MASK;
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Set the number of address bytes required for the flash command address.
 *
 * @param[in] addr_bytes The number of bytes required.
 *
 * @return NONE
 */
void qspi_set_flashcmdaddrbytes(uint32_t addr_bytes)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= ((addr_bytes - 1U) << QSPI_FLASHCMD_NUMADDRBYTES_POS);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Set the flash command address register.
 *
 * @param[in] address The address to be configured to the flash command address register.
 *
 * @return NONE
 */
void qspi_set_flashcmdaddr(uint32_t address)
{
    WR_REG32(QSPI_FLASHCMDADDR, address);
}

/**
 * @brief Set the flash command in the flash command register.
 *
 * @param[in] cmd_opcode The opcode to be configured in the flash command register.
 *
 * @return NONE
 */
void qspi_set_flashcmd(uint32_t cmd_opcode)
{
    uint32_t flashcmd = 0;
/*    flashcmd &= ~( QSPI_FLASHCMD_NUMDUMMYBYTES_MASK
 | QSPI_FLASHCMD_WR_DATA_BYTES_MASK |
            QSPI_FLASHCMD_ENWRDATA_MASK | QSPI_FLASHCMD_NUMADDRBYTES_MASK |
            QSPI_FLASHCMD_ENMODEBIT_MASK | QSPI_FLASHCMD_ENCMDADDR_MASK |
            QSPI_FLASHCMD_RD_DATA_BYTES_MASK | QSPI_FLASHCMD_ENRDDATA_MASK |
            QSPI_FLASHCMD_CMDOPCODE_MASK);*/
    flashcmd = ((uint32_t)cmd_opcode << 24U);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Start the flash operation.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_flashcmd_exec(void)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= (QSPI_FLASHCMD_EXECUTE_POS << 0);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Enable read data from flash.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_flashcmd_read_data(void)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= ((uint32_t)1U << QSPI_FLASHCMD_ENRDDATA_POS);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Enable the sending of data to the flash device.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_flashcmd_write_data(void)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= ((uint32_t)1U << QSPI_FLASHCMD_ENWRDATA_POS);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Set the number of bytes to be read from flash.
 *
 * @param[in] bytes The number of bytes.
 *
 * @return NONE
 */
void qspi_flashcmd_read_bytes(uint32_t bytes)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= ((bytes - 1U) << QSPI_FLASHCMD_RD_DATA_BYTES_POS);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Set the number of bytes to be written for command to be sent to flash.
 *
 * @param[in] bytes The number of bytes.
 *
 * @return NONE
 */
void qspi_flashcmd_write_bytes(uint32_t bytes)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd |= ((bytes - 1U) << QSPI_FLASHCMD_WR_DATA_BYTES_POS);
    WR_REG32(QSPI_FLASHCMD, flashcmd);
}

/**
 * @brief Read the status of the flash command operation from the flash command.
 *
 * @param NONE
 *
 * @return value in flash command register.
 */
uint32_t qspi_get_flashcmd_stat(void)
{
    uint32_t flashcmd = RD_REG32(QSPI_FLASHCMD);
    flashcmd &= (QSPI_FLASHCMD_EXECSTAT_POS);
    return flashcmd;
}

/**
 * @brief Configure the chip select.
 *
 * @param[in] cs The chip select.
 *
 * @return NONE
 */
void qspi_select_chip(uint32_t cs)
{
    uint32_t cfg = RD_REG32(QSPI_CFG);
    cfg &= ~(QSPI_CFG_PERCSLINES_MASK);
    cfg |= ((0U << cs) << QSPI_CFG_PERCSLINES_POS);
    WR_REG32(QSPI_CFG, cfg);
}

/**
 * @brief Get the fill level of the SRAM.
 *
 * @param NONE
 *
 * @return level The fill level of the SRAM.
 */
uint32_t qspi_get_sramfill(void)
{
    return RD_REG32(QSPI_SRAMFILL);
}

/**
 * @brief Check the status of the indirect write operation.
 *
 * @param NONE
 *
 * @return status The status of the indirect write operation.
 */
uint32_t qspi_get_indwr_multiop_status(void)
{
    return ((RD_REG32(QSPI_INDWR) & 0x60U) >> 5U);
}

/**
 * @brief Clear the indirect write operation done write status.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_clear_indwr_op_status(void)
{
    uint32_t cfg = RD_REG32(QSPI_INDWR);
    cfg |= (1U << 5U);
    WR_REG32(QSPI_INDWR, cfg);
}

/**
 * @brief Clear the indirect read operation done status.
 *
 * @param NONE
 *
 * @return NONE
 */
void qspi_clear_indrd_op_status(void)
{
    uint32_t cfg = RD_REG32(QSPI_INDRD);
    cfg |= ((uint32_t)1 << (uint32_t)5);
    WR_REG32(QSPI_INDRD, cfg);
}

/**
 * @brief Get the value of a register.
 *
 * @param[in] reg The register whose value is to be obtained.
 *
 * @return The value within the register.
 */
uint32_t qspi_reg_get_data(uint32_t reg)
{
    return RD_REG32(reg);
}

/**
 * @brief Obtain the interrupt status.
 *
 * @param NONE
 *
 * @return status Returns the value of the irqstat register.
 */
uint32_t qspi_get_int_status(void)
{
    uint32_t status = RD_REG32(QSPI_IRQSTAT);
    return status;
}

/**
 * @brief Set interrupt status (to clear).
 *
 * @param[in] status The value that has to be written to the irq register.
 *
 * @return NONE
 */
void qspi_set_int_status(uint32_t status)
{
    WR_REG32(QSPI_IRQSTAT, status);
}

/**
 * @brief Enable the interrupt in irqmask register.
 *
 * @param[in] irqmask The mask for the interrupts that have to be enabled.
 *
 * @return NONE
 */
void qspi_enable_interrupt(uint32_t irqmask)
{
    uint32_t temp_mask = RD_REG32(QSPI_IRQMASK);
    temp_mask |= irqmask;
    WR_REG32(QSPI_IRQMASK, temp_mask);
}

/**
 * @brief Disable the interrupt in irqmask register.
 *
 * @param[in] irqmask The mask for disabling the interrupt.
 *
 * @return NONE
 */
void qspi_disable_interrupt(uint32_t irqmask)
{

    uint32_t temp_mask = RD_REG32(QSPI_IRQMASK);
    temp_mask &= ~irqmask;
    WR_REG32(QSPI_IRQMASK, temp_mask);
}
