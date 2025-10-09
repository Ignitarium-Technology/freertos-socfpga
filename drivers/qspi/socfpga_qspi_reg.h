/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * SoC FPGA QSPI register definitions
 */

#ifndef __SOCFPGA_QSPI_REG_H__
#define __SOCFPGA_QSPI_REG_H__

#include <stdint.h>

#define PAGE_SIZE                            256U

/* QSPI Base Address */
#define QSPI_CSR_BASE_ADDRESS                0x108D2000U
#define QSPI_DATA_BASE                       0x10900000U
#define QSPI_DATA_END                        0x109FFFFFU

/* QSPI Configuration Register */
#define QSPI_CFG_OFFSET          0x0U
#define QSPI_CFG                 QSPI_CSR_BASE_ADDRESS + QSPI_CFG_OFFSET

/* Device Read Instruction Configuration Register */
#define QSPI_DEVRD_OFFSET        0x4U
#define QSPI_DEVRD               QSPI_CSR_BASE_ADDRESS + QSPI_DEVRD_OFFSET

/* Device Write Instruction Configuration Register */
#define QSPI_DEVWR_OFFSET        0x8U
#define QSPI_DEVWR               QSPI_CSR_BASE_ADDRESS + QSPI_DEVWR_OFFSET

/* QSPI Device Delay Register */
#define QSPI_DELAY_OFFSET        0xCU
#define QSPI_DELAY               QSPI_CSR_BASE_ADDRESS + QSPI_DELAY_OFFSET

/* Read Data Capture Register */
#define QSPI_RDDATACAP_OFFSET               0x10U
#define QSPI_RDDATACAP               QSPI_CSR_BASE_ADDRESS + QSPI_RDDATACAP_OFFSET

/* Device Size Configuration Register */
#define QSPI_DEVSZ_OFFSET        0x14U
#define QSPI_DEVSZ               QSPI_CSR_BASE_ADDRESS + QSPI_DEVSZ_OFFSET

/* SRAM Partition Configuration Register */
#define QSPI_SRAMPART_OFFSET            0x18U
#define QSPI_SRAMPART            QSPI_CSR_BASE_ADDRESS + QSPI_SRAMPART_OFFSET

/* Indirect AHB Address Trigger Register */
#define QSPI_INDADDRTRIG_OFFSET            0x1CU
#define QSPI_INDADDRTRIG            QSPI_CSR_BASE_ADDRESS + QSPI_INDADDRTRIG_OFFSET

/* DMA Peripheral Configuration Register */
#define QSPI_DMAPER_OFFSET       0x20U

/* Remap Address Register */
#define QSPI_REMAPADDR_OFFSET    0x24U
#define QSPI_REMAPADDR           QSPI_CSR_BASE_ADDRESS + QSPI_REMAPADDR_OFFSET

/* Mode Bit Configuration Register */
#define QSPI_MODEBIT             0x28U

/* SRAM Fill Register */
#define QSPI_SRAMFILL_OFFSET     0x2CU
#define QSPI_SRAMFILL            QSPI_CSR_BASE_ADDRESS + QSPI_SRAMFILL_OFFSET

/* TX Threshold Register */
#define QSPI_TET                 0x30U

/* RX Threshold Register */
#define QSPI_RXT                 0x34U

/* Interrupt Status Register */
#define QSPI_IRQSTAT_OFFSET               0x40U
#define QSPI_IRQSTAT               QSPI_CSR_BASE_ADDRESS + QSPI_IRQSTAT_OFFSET

/* Interrupt Mask Register */
#define QSPI_IRQMASK_OFFSET      0x44U
#define QSPI_IRQMASK             QSPI_CSR_BASE_ADDRESS + QSPI_IRQMASK_OFFSET

/* Lower Write Protection Register */
#define QSPI_LOWWRPROT           0x50U

/* Upper Write Protection Register */
#define QSPI_UPPWRPROT           0x54U

/* Write Protection Control Register */
#define QSPI_WRPROT_OFFSET              0x58U
#define QSPI_WRPROT              QSPI_CSR_BASE_ADDRESS + QSPI_WRPROT_OFFSET

/* Indirect Read Transfer Control Register */
#define QSPI_INDRD_OFFSET        0x60U
#define QSPI_INDRD               QSPI_CSR_BASE_ADDRESS + QSPI_INDRD_OFFSET

/* Indirect Read Transfer Watermark Register */
#define QSPI_INDRDWATER_OFFSET            0x64U
#define QSPI_INDRDWATER            QSPI_CSR_BASE_ADDRESS + QSPI_INDRDWATER_OFFSET

/* Indirect Read Transfer Start Address Register */
#define QSPI_INDRDSTADDR_OFFSET             0x68U
#define QSPI_INDRDSTADDR             QSPI_CSR_BASE_ADDRESS + QSPI_INDRDSTADDR_OFFSET

/* Indirect Read Transfer Number Bytes Register */
#define QSPI_INDRDCNT_OFFSET            0x6CU
#define QSPI_INDRDCNT            QSPI_CSR_BASE_ADDRESS + QSPI_INDRDCNT_OFFSET

/* Indirect Write Transfer Control Register */
#define QSPI_INDWR_OFFSET        0x70U
#define QSPI_INDWR               QSPI_CSR_BASE_ADDRESS + QSPI_INDWR_OFFSET

/* Indirect Write Transfer Watermark Register */
#define QSPI_INDWRWATER_OFFSET            0x74U
#define QSPI_INDWRWATER            QSPI_CSR_BASE_ADDRESS + QSPI_INDWRWATER_OFFSET

/* Tx FIFO Threshold */
#define QSPI_TXTHRESH_OFFSET                 0x30U
#define QSPI_TXTHRESH                  QSPI_CSR_BASE_ADDRESS + QSPI_TXTHRESH_OFFSET

/* Rx FIFO Threshold */
#define QSPI_RXTHRESH_OFFSET                 0x34U
#define QSPI_RXTHRESH                 QSPI_CSR_BASE_ADDRESS + QSPI_RXTHRESH_OFFSET

/* Indirect Write Transfer Start Address Register */
#define QSPI_INDWRSTADDR_OFFSET             0x78U
#define QSPI_INDWRSTADDR             QSPI_CSR_BASE_ADDRESS + QSPI_INDWRSTADDR_OFFSET

/* Indirect Write Transfer Number Bytes Register */
#define QSPI_INDWRCNT_OFFSET            0x7CU
#define QSPI_INDWRCNT            QSPI_CSR_BASE_ADDRESS + QSPI_INDWRCNT_OFFSET

/* Flash Command Control Register */
#define QSPI_FLASHCMD_OFFSET     0x90U
#define QSPI_FLASHCMD            QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMD_OFFSET

/* Flash Command Address Register */
#define QSPI_FLASHCMDADDR_OFFSET 0x94U
#define QSPI_FLASHCMDADDR        QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMDADDR_OFFSET

/* Flash Command Read Data Register (Lower) */
#define QSPI_FLASHCMDRDDATALO_OFFSET       0xA0U
#define QSPI_FLASHCMDRDDATALO       QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMDRDDATALO_OFFSET

/* Flash Command Read Data Register (Upper) */
#define QSPI_FLASHCMDRDDATAUP_OFFSET       0xA4U
#define QSPI_FLASHCMDRDDATAUP       QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMDRDDATAUP_OFFSET

/* Flash Command Write Data Register (Lower) */
#define QSPI_FLASHCMDWRDATALO_OFFSET       0xA8U
#define QSPI_FLASHCMDWRDATALO       QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMDWRDATALO_OFFSET

/* Flash Command Write Data Register (Upper) */
#define QSPI_FLASHCMDWRDATAUP_OFFSET       0xACU
#define QSPI_FLASHCMDWRDATAUP       QSPI_CSR_BASE_ADDRESS + QSPI_FLASHCMDWRDATAUP_OFFSET

/* Module ID Register */
#define QSPI_MODULEID_OFFSET     0xFCU

/*Interrupt Masks*/
#define QSPI_INDOPDONE_M                     0x04U
#define QSPI_XFERLVL_M                       0x40U
#define QSPI_SRAMFULL_M                      0x1000U

#define QSPI_XFERLVLBRCH                     0x40U
#define QSPI_SRAMFULL                        0x1000U

#define QSPI_FLASHCMD_EXECUTE_POS            1U
#define QSPI_FLASHCMD_EXECSTAT_POS           2U
#define QSPI_FLASHCMD_NUMDUMMYBYTES_POS      7U
#define QSPI_FLASHCMD_NUMDUMMYBYTES_MASK     ((uint32_t) 0x1FU << QSPI_FLASHCMD_NUMDUMMYBYTES_POS)
#define QSPI_FLASHCMD_WR_DATA_BYTES_POS      12U
#define QSPI_FLASHCMD_WR_DATA_BYTES_MASK     ((uint32_t) 7U << QSPI_FLASHCMD_WR_DATA_BYTES_POS)
#define QSPI_FLASHCMD_ENWRDATA_POS           15U
#define QSPI_FLASHCMD_ENWRDATA_MASK          ((uint32_t) 1U << QSPI_FLASHCMD_ENWRDATA_POS)
#define QSPI_FLASHCMD_NUMADDRBYTES_POS       16U
#define QSPI_FLASHCMD_NUMADDRBYTES_MASK      ((uint32_t) 3U << QSPI_FLASHCMD_NUMADDRBYTES_POS)
#define QSPI_FLASHCMD_ENMODEBIT_POS          18U
#define QSPI_FLASHCMD_ENMODEBIT_MASK         ((uint32_t) 1U << QSPI_FLASHCMD_ENMODEBIT_POS)
#define QSPI_FLASHCMD_ENCMDADDR_POS          19U
#define QSPI_FLASHCMD_ENCMDADDR_MASK         ((uint32_t) 1U << QSPI_FLASHCMD_ENCMDADDR_POS)
#define QSPI_FLASHCMD_RD_DATA_BYTES_POS      20U
#define QSPI_FLASHCMD_RD_DATA_BYTES_MASK     ((uint32_t) 7U << QSPI_FLASHCMD_RD_DATA_BYTES_POS)
#define QSPI_FLASHCMD_ENRDDATA_POS           23U
#define QSPI_FLASHCMD_ENRDDATA_MASK          ((uint32_t) 1U << QSPI_FLASHCMD_ENRDDATA_POS)
#define QSPI_FLASHCMD_CMDOPCODE_POS          24U
#define QSPI_FLASHCMD_CMDOPCODE_MASK         ((uint32_t) 0xFFU << QSPI_FLASHCMD_CMDOPCODE_POS)
#define QSPI_DEVRD_INSTWIDTH_POS             8U
#define QSPI_DEVRD_INSTWIDTH_MASK            0x3U
#define QSPI_DEVRD_ADDRWIDTH_POS             12U
#define QSPI_DEVRD_ADDRWIDTH_MASK            0x3U
#define QSPI_DEVRD_DATAWIDTH_POS             16U
#define QSPI_DEVRD_DATAWIDTH_MASK            0x3U
#define QSPI_DEVRD_MODEBIT_POS               20U
#define QSPI_DEVRD_MODEBIT_MASK              1U
#define QSPI_DUMMY_DELAY_POS                 24U
#define QSPI_DUMMY_DELAY_MASK                0x1FU
#define QSPI_SUBSECTOR_BYTES_POS             16U
#define QSPI_SUBSECTOR_BYTES_MASK            0x1FU
#define QSPI_PAGE_BYTES_POS                  4U
#define QSPI_PAGE_BYTES_MASK                 0xFFFU
#define QSPI_DEVSZ_NUM_ADDR_BYTES_MASK       0xFU
#define QSPI_NSS_DELAY_POS                   24U
#define QSPI_NSS_DELAY_MASK                  0xFFU
#define QSPI_BTWN_DELAY_POS                  16U
#define QSPI_BTWN_DELAY_MASK                 0xFFU
#define QSPI_AFTER_DELAY_POS                 8U
#define QSPI_AFTER_DELAY_MASK                0xFFU
#define QSPI_INIT_DELAY_POS                  0U
#define QSPI_INIT_DELAY_MASK                 0xFFU
#define QSPI_BAUD_DIVISOR_POS                19U
#define QSPI_BAUD_DIVISOR_MASK               0xFU
#define QSPI_INDWR_START_POS                 0U
#define QSPI_INDWR_START_MASK                1U
#define QSPI_INDRD_START_POS                 0U
#define QSPI_INDRD_START_MASK                1U
#define QSPI_FLASHCMD_CMD_POS                24U
#define QSPI_INDWR_STATUS_MASK               0x4U
#define QSPI_INDRD_STATUS_MASK               0x4U
#define QSPI_INDRD_MULTIPLEOP_STATUS_POS     5U
#define QSPI_INDRD_MULTIPLEOP_STATUS_MASK    0x60U
#define QSPI_INDWR_MULTIPLEOP_STATUS_POS     5U
#define QSPI_INDWR_MULTIPLEOP_STATUS_MASK    0x60U




/* Bit Masks and Position for CFG Register */

/* 31U: Idle (STATUS read-only bit) */
#define QSPI_CFG_IDLE_MASK          ((uint32_t) 1U << 31U)
#define QSPI_CFG_IDLE_POS           31U

/* 22U:19U Baud Rate Divider */
#define QSPI_CFG_BAUDDIV_MASK       (0UxFU << 19U)
#define QSPI_CFG_BAUDDIV_POS        19U

/* 15U: Enable DMA Mode */
#define QSPI_CFG_ENDMA_MASK         (1U << 15U)
#define QSPI_CFG_ENDMA_POS          15U

/* 14U: Write Protect */
#define QSPI_CFG_WP_MASK            (1U << 14U)
#define QSPI_CFG_WP_POS             14U

/* 13U:10U Peripheral Chip Select Lines */
#define QSPI_CFG_PERCSLINES_MASK    ((uint32_t) 0xFU << 10U)
#define QSPI_CFG_PERCSLINES_POS     10U

/* 8U: Enable Legacy IP Mode */
#define QSPI_CFG_ENLEGACYIP_MASK    (1U << 8U)
#define QSPI_CFG_ENLEGACYIP_POS     8U

/* 7U: Enable Direct Access Controller */
#define QSPI_CFG_ENDIRACC_MASK      (1U << 7U)
#define QSPI_CFG_ENDIRACC_POS       7U

/* 0U: Enable QSPI */
#define QSPI_CFG_EN_MASK            (1U << 0U)
#define QSPI_CFG_EN_POS             0U

#endif /* __SOCFPGA_QSPI_REG_H__ */
