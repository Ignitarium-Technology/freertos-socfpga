/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for reset manager driver
 */

#ifndef __SOCFPGA_RST_MNGR_H__
#define __SOCFPGA_RST_MNGR_H__

/**
 * @file    socfpga_rst_mngr.h
 * @brief   This file contains all the Reset Manager HAL API definitions
 */

#include <stdint.h>
#include <errno.h>

/**
 * @defgroup rst Reset Manager
 * @ingroup drivers
 * @brief APIs for SoC FPGA Reset Manager driver.
 * @details This is the Reset Manager driver implementation for SoC FPGA.
 * It provides APIs for asserting, deasserting, and toggling
 * hardware peripheral resets.
 * @{
 */

/**
 * @defgroup rst_fns Functions
 * @ingroup rst
 * Reset Manager HAL APIs
 */

/**
 * @defgroup rst_enums Enumerations
 * @ingroup rst
 * Reset Manager Specific Enumerations
 */

#include <stdint.h>

/**
 * @brief Peripheral IDs for Reset Manager
 * @ingroup rst_enums
 */
typedef enum
{
    RST_PERIPHERAL_START = 0,  /*!<Starting of the hardware peripheral IDs*/
    RST_TSN0 = 0, /*!<Hardware peripheral ID for XGMAC1*/
    RST_TSN1, /*!<Hardware peripheral ID for XGMAC2*/
    RST_TSN2, /*!<Hardware peripheral ID for XGMAC3*/
    RST_USB0, /*!<Hardware peripheral ID for USB instance 0*/
    RST_USB1, /*!<Hardware peripheral ID for USB instance 1*/
    RST_NAND, /*!<Hardware peripheral ID for NAND Flash*/
    RST_SOFTPHY, /*!<Hardware peripheral ID for Soft PHY*/
    RST_SDMMC, /*!<Hardware peripheral ID for SDMMC*/
    RST_TSN0ECC, /*!<Hardware peripheral ID for XGMAC0 ECC diagnostics*/
    RST_TSN1ECC, /*!<Hardware peripheral ID for XGMAC1 ECC diagnostics*/
    RST_TSN2ECC, /*!<Hardware peripheral ID for XGMAC2 ECC diagnostics*/
    RST_USB0ECC, /*!<Hardware peripheral ID for USB2.0 ECC diagnostics*/
    RST_USB1ECC, /*!<Hardware peripheral ID for USB3.1 ECC diagnostics*/
    RST_NANDECC, /*!<Hardware peripheral ID for NAND Flash ECC diagnostics*/
    RST_RSRVD1, /*!<Reserved*/
    RST_SDMMCECC, /*!<Hardware peripheral ID for SDMMC ECC diagnostics*/
    RST_DMA, /*!<Hardware peripheral ID for DMA*/
    RST_SPIM0, /*!<Hardware peripheral ID for SPI Master 0*/
    RST_SPIM1, /*!<Hardware peripheral ID for SPI Master 1*/
    RST_SPIS0, /*!<Hardware peripheral ID for SPI Slave 0*/
    RST_SPIS1, /*!<Hardware peripheral ID for SPI Slave 1*/
    RST_DMAECC, /*!<Hardware peripheral ID for DMA ECC diagnostics*/
    RST_EMACPTP, /*!<Hardware peripheral ID for XGMAC PTP block*/
    RST_RSRVD2, /*!<Reserved*/
    RST_DMAIF0, /*!<Hardware peripheral ID for DMA Interface 0 for FPGA block*/
    RST_DMAIF1, /*!<Hardware peripheral ID for DMA Interface 1 for FPGA block*/
    RST_DMAIF2, /*!<Hardware peripheral ID for DMA Interface 2 for FPGA block*/
    RST_DMAIF3, /*!<Hardware peripheral ID for DMA Interface 3 for FPGA block*/
    RST_DMAIF4, /*!<Hardware peripheral ID for DMA Interface 4 for FPGA block*/
    RST_DMAIF5, /*!<Hardware peripheral ID for DMA Interface 5 for FPGA block*/
    RST_DMAIF6, /*!<Hardware peripheral ID for DMA Interface 6 for FPGA block*/
    RST_DMAIF7, /*!<Hardware peripheral ID for DMA Interface 7 for FPGA block*/
    RST_WATCHDOG0, /*!<Hardware peripheral ID for Watchdog 0*/
    RST_WATCHDOG1, /*!<Hardware peripheral ID for Watchdog 1*/
    RST_WATCHDOG2, /*!<Hardware peripheral ID for Watchdog 2*/
    RST_WATCHDOG3, /*!<Hardware peripheral ID for Watchdog 3*/
    RST_L4SYSTIMER0, /*!<Hardware peripheral ID for System Timer 0*/
    RST_L4SYSTIMER1, /*!<Hardware peripheral ID for System Timer 1*/
    RST_SPTIMER0, /*!<Hardware peripheral ID for Timer instance 0*/
    RST_SPTIMER1, /*!<Hardware peripheral ID for Timer instance 1*/
    RST_I2C0, /*!<Hardware peripheral ID for I2C instance 0*/
    RST_I2C1, /*!<Hardware peripheral ID for I2C instance 1*/
    RST_I2C2, /*!<Hardware peripheral ID for I2C instance 2*/
    RST_I2C3, /*!<Hardware peripheral ID for I2C instance 3*/
    RST_I2C4, /*!<Hardware peripheral ID for I2C instance 4*/
    RST_I3C0, /*!<Hardware peripheral ID for I3C instance 0*/
    RST_I3C1, /*!<Hardware peripheral ID for I3C instance 1*/
    RST_RSRVD3, /*!<Reserved*/
    RST_UART0, /*!<Hardware peripheral ID for UART instance 0*/
    RST_UART1, /*!<Hardware peripheral ID for UART instance 1*/
    RST_RSRVD4, /*!<Reserved*/
    RST_RSRVD5, /*!<Reserved*/
    RST_RSRVD6, /*!<Reserved*/
    RST_RSRVD7, /*!<Reserved*/
    RST_RSRVD8, /*!<Reserved*/
    RST_RSRVD9, /*!<Reserved*/
    RST_GPIO0, /*!<Hardware peripheral ID for GPIO instance 0*/
    RST_GPIO1, /*!<Hardware peripheral ID for GPIO instance 1*/
    RST_WATCHDOG4, /*!<Hardware peripheral ID for Watchdog 4*/
    RST_RSRVD10, /*!<Reserved*/
    RST_RSRVD11, /*!<Reserved*/
    RST_RSRVD12, /*!<Reserved*/
    RST_RSRVD13, /*!<Reserved*/
    RST_RSRVD14, /*!<Reserved*/
    RST_SOC2FPGA_BRIDGE, /*!<Hardware peripheral ID for SOC to FPGA Bridge*/
    RST_LWSOC2FPGA_BRIDGE, /*!<Hardware peripheral ID for Low Power SOC to FPGA Bridge*/
    RST_FPGA2SOC_BRIDGE, /*!<Hardware peripheral ID for FPGA to SOC Bridge*/
    RST_FPGA2SDRAM_BRIDGE = 67, /*!<Hardware peripheral ID for FPGA to SDRAM Bridge*/
    RST_PERIPHERAL_END = 67 /*!<End of the hardware peripheral IDs*/
} reset_periphrl_t;

/**
 * @addtogroup rst_fns
 * @{
 */

/**
 * @brief Assert reset to a hardware peripheral.
 *        The application can call this function to keep the peripheral mentioned in inactive state.
 *
 * @param[in] per The peripheral ID of the hardware.
 *
 * @return
 *   - 0: on success
 *   - -EINVAL: if per is invalid
 */
int32_t rstmgr_assert_reset(reset_periphrl_t per);

/**
 * @brief Activate a hardware peripheral.
 *        The application must call this function to activate the mentioned peripheral to use.
 *
 * @param[in] per The peripheral ID of the hardware.
 *
 * @return
 * - 0: on success
 * - -EINVAL: if per is invalid
 */
int32_t rstmgr_deassert_reset(reset_periphrl_t per);

/**
 * @brief Toggle the activation state of a hardware peripheral.
 *        The application can call this function to restart the hardware peripheral.
 *
 * @param[in] per The peripheral ID of the hardware.
 *
 * @return
 * - 0: on success
 * - -EINVAL: if per is invalid
 */
int32_t rstmgr_toggle_reset(reset_periphrl_t per);

/**
 * @brief Get the state of a hardware peripheral.
 *        The application can call this function to get the status of the hardware peripheral.
 *
 * @param[in]  per    The peripheral ID of the hardware.
 * @param[out] status Reset status of the peripheral.
 *
 * @return
 * - 0: on success
 * - -EINVAL: if per is invalid
 */
int32_t rstmgr_get_reset_status(reset_periphrl_t per, uint8_t *status);
/** @} */
/** @} */

#endif /* __SOCFPGA_RST_MNGR_H__ */
