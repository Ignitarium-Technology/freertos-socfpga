/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * SoC FPGA UART register definitions
 */

#ifndef __SOCFPGA_UART_REG_H__
#define __SOCFPGA_UART_REG_H__

#define GET_UART_BASE_ADDRESS(instance)    ((uint32_t)(0x10C02000U + \
    (instance * 0x100U)))

#define CLK_PERPLL                               0x10D1007CU
#define CLK_PERPLL_EN                            (0x0U + CLK_PERPLL)
#define CLK_EN_SHIFT                             20U

#define RST_MGR                                  0x10D11000U
#define RST_PERMOD                               (0x28U + RST_MGR)
#define RST_SHIFT                                16U

/* Receive Buffer Register */
#define UART_RBR                                 0x0000U
/* Divisor Latch (Low) */
#define UART_DLL                                 0x0000U
/* Transmit Holding Register */
#define UART_THR                                 0x0000U
/* Interrupt Enable Register */
#define UART_IER                                 0x0004U
/* Divisor Latch High */
#define UART_DLH                                 0x0004U
/* Interrupt Identification Register */
#define UART_IIR                                 0x0008U
/* FIFO Control Register */
#define UART_FCR                                 0x0008U
/* Line Control Register */
#define UART_LCR                                 0x000CU
/* Modem Control Register */
#define UART_MCR                                 0x0010U
/* Line Status Register */
#define UART_LSR                                 0x0014U
/* Modem Status Register */
#define UART_MSR                                 0x0018U
/* Scratchpad Register */
#define UART_SCR                                 0x001CU
/* Shadow Receive Buffer Register */
#define UART_SRBR0                               0x0030U
/* Shadow Transmit Holding Register */
#define UART_STHR0                               0x0030U
/* Shadow Receive Buffer Register 1 */
#define UART_SRBR1                               0x0034U
/* Shadow Transmit Holding Register 1 */
#define UART_STHR1                               0x0034U
/* Shadow Receive Buffer Register 2 */
#define UART_SRBR2                               0x0038U
/* Shadow Transmit Holding Register 2 */
#define UART_STHR2                               0x0038U
/* Shadow Receive Buffer Register 3 */
#define UART_SRBR3                               0x003CU
/* Shadow Transmit Holding Register 3 */
#define UART_STHR3                               0x003CU
/* Shadow Receive Buffer Register 4 */
#define UART_SRBR4                               0x0040U
/* Shadow Transmit Holding Register 4 */
#define UART_STHR4                               0x0040U
/* Shadow Receive Buffer Register 5 */
#define UART_SRBR5                               0x0044U
/* Shadow Transmit Holding Register 5 */
#define UART_STHR5                               0x0044U
/* Shadow Receive Buffer Register 6 */
#define UART_SRBR6                               0x0048U
/* Shadow Transmit Holding Register 6 */
#define UART_STHR6                               0x0048U
/* Shadow Receive Buffer Register 7 */
#define UART_SRBR7                               0x004CU
/* Shadow Transmit Holding Register 7 */
#define UART_STHR7                               0x004CU
/* Shadow Receive Buffer Register 8 */
#define UART_SRBR8                               0x0050U
/* Shadow Transmit Holding Register 8 */
#define UART_STHR8                               0x0050U
/* Shadow Receive Buffer Register 9 */
#define UART_SRBR9                               0x0054U
/* Shadow Transmit Holding Register 9 */
#define UART_STHR9                               0x0054U
/* Shadow Receive Buffer Register 10 */
#define UART_SRBR10                              0x0058U
/* Shadow Transmit Holding Register 10 */
#define UART_STHR10                              0x0058U
/* Shadow Receive Buffer Register 11 */
#define UART_SRBR11                              0x005CU
/* Shadow Transmit Holding Register 11 */
#define UART_STHR11                              0x005CU
/* Shadow Receive Buffer Register 12 */
#define UART_SRBR12                              0x0060U
/* Shadow Transmit Holding Register 12 */
#define UART_STHR12                              0x0060U
/* Shadow Receive Buffer Register 13 */
#define UART_SRBR13                              0x0064U
/* Shadow Transmit Holding Register 13 */
#define UART_STHR13                              0x0064U
/* Shadow Receive Buffer Register 14 */
#define UART_SRBR14                              0x0068U
/* Shadow Transmit Holding Register 14 */
#define UART_STHR14                              0x0068U
/* Shadow Receive Buffer Register 15 */
#define UART_SRBR15                              0x006CU
/* Shadow Transmit Holding Register 15 */
#define UART_STHR15                              0x006CU
/* FIFO Access Register */
#define UART_FAR                                 0x0070U
/* Transmit FIFO Read */
#define UART_TFR                                 0x0074U
/* Receive FIFO Write */
#define UART_RFW                                 0x0078U
/* UART Status register */
#define UART_USR                                 0x007CU
/* Transmit FIFO Level */
#define UART_TFL                                 0x0080U
/* Receive FIFO Level */
#define UART_RFL                                 0x0084U
/* Software Reset Register */
#define UART_SRR                                 0x0088U
/* Shadow Request to Send */
#define UART_SRTS                                0x008CU
/* Shadow Break Control Register */
#define UART_SBCR                                0x0090U
/* Shadow DMA Mode */
#define UART_SDMAM                               0x0094U
/* Shadow FIFO Enable */
#define UART_SFE                                 0x0098U
/* Shadow RCVR Trigger */
#define UART_SRT                                 0x009CU
/* Shadow TX Empty Trigger */
#define UART_STET                                0x00A0U
/* Halt TX */
#define UART_HTX                                 0x00A4U
/* DMA Software Acknowledge */
#define UART_DMASA                               0x00A8U
/* Component Parameter Register */
#define UART_CPR                                 0x00F4U
/* Component Version */
#define UART_UCV                                 0x00F8U
/* Component Type Register */
#define UART_CTR                                 0x00FCU

/* Bit fields of RBR register */
#define UART_RBR_RBR_MASK                        0x000000FFU
#define UART_RBR_RBR_POS                         0U

/* Bit fields of DLL register */
#define UART_DLL_DLL_MASK                        0x000000FFU
#define UART_DLL_DLL_POS                         0U

/* Bit fields of THR register */
#define UART_THR_THR_MASK                        0x000000FFU
#define UART_THR_THR_POS                         0U

/* Bit fields of IER register */
#define UART_IER_PTIME_MASK                      0x00000080U
#define UART_IER_PTIME_POS                       7U
#define UART_IER_EDSSI_MASK                      0x00000008U
#define UART_IER_EDSSI_POS                       3U
#define UART_IER_ELSI_MASK                       0x00000004U
#define UART_IER_ELSI_POS                        2U
#define UART_IER_ETBEI_MASK                      0x00000002U
#define UART_IER_ETBEI_POS                       1U
#define UART_IER_ERBFI_MASK                      0x00000001U
#define UART_IER_ERBFI_POS                       0U

/* Bit fields of DLH register */
#define UART_DLH_DLH_MASK                        0x000000FFU
#define UART_DLH_DLH_POS                         0U

/* Bit fields of IIR register */
#define UART_IIR_FIFOSE_MASK                     0x000000C0U
#define UART_IIR_FIFOSE_POS                      6U
#define UART_IIR_IID_MASK                        0x0000000FU
#define UART_IIR_IID_POS                         0U

/* Bit fields of FCR register */
#define UART_FCR_RT_MASK                         0x000000C0U
#define UART_FCR_RT_POS                          6U
#define UART_FCR_TET_MASK                        0x00000030U
#define UART_FCR_TET_POS                         4U
#define UART_FCR_DMAM_MASK                       0x00000008U
#define UART_FCR_DMAM_POS                        3U
#define UART_FCR_XFIFOR_MASK                     0x00000004U
#define UART_FCR_XFIFOR_POS                      2U
#define UART_FCR_RFIFOR_MASK                     0x00000002U
#define UART_FCR_RFIFOR_POS                      1U
#define UART_FCR_FIFOE_MASK                      0x00000001U
#define UART_FCR_FIFOE_POS                       0U

/* Bit fields of LCR register */
#define UART_LCR_DLAB_MASK                       0x00000080U
#define UART_LCR_DLAB_POS                        7U
#define UART_LCR_BREAK_MASK                      0x00000040U
#define UART_LCR_BREAK_POS                       6U
#define UART_LCR_SP_MASK                         0x00000020U
#define UART_LCR_SP_POS                          5U
#define UART_LCR_EPS_MASK                        0x00000010U
#define UART_LCR_EPS_POS                         4U
#define UART_LCR_PEN_MASK                        0x00000008U
#define UART_LCR_PEN_POS                         3U
#define UART_LCR_STOP_MASK                       0x00000004U
#define UART_LCR_STOP_POS                        2U
#define UART_LCR_DLS_MASK                        0x00000003U
#define UART_LCR_DLS_POS                         0U

/* Bit fields of MCR register */
#define UART_MCR_SIRE_MASK                       0x00000040U
#define UART_MCR_SIRE_POS                        6U
#define UART_MCR_AFCE_MASK                       0x00000020U
#define UART_MCR_AFCE_POS                        5U
#define UART_MCR_LOOPBACK_MASK                   0x00000010U
#define UART_MCR_LOOPBACK_POS                    4U
#define UART_MCR_OUT2_MASK                       0x00000008U
#define UART_MCR_OUT2_POS                        3U
#define UART_MCR_OUT1_MASK                       0x00000004U
#define UART_MCR_OUT1_POS                        2U
#define UART_MCR_RTS_MASK                        0x00000002U
#define UART_MCR_RTS_POS                         1U
#define UART_MCR_DTR_MASK                        0x00000001U
#define UART_MCR_DTR_POS                         0U

/* Bit fields of LSR register */
#define UART_LSR_RFE_MASK                        0x00000080U
#define UART_LSR_RFE_POS                         7U
#define UART_LSR_TEMT_MASK                       0x00000040U
#define UART_LSR_TEMT_POS                        6U
#define UART_LSR_THRE_MASK                       0x00000020U
#define UART_LSR_THRE_POS                        5U
#define UART_LSR_BI_MASK                         0x00000010U
#define UART_LSR_BI_POS                          4U
#define UART_LSR_FE_MASK                         0x00000008U
#define UART_LSR_FE_POS                          3U
#define UART_LSR_PE_MASK                         0x00000004U
#define UART_LSR_PE_POS                          2U
#define UART_LSR_OE_MASK                         0x00000002U
#define UART_LSR_OE_POS                          1U
#define UART_LSR_DR_MASK                         0x00000001U
#define UART_LSR_DR_POS                          0U

/* Bit fields of MSR register */
#define UART_MSR_DCD_MASK                        0x00000080U
#define UART_MSR_DCD_POS                         7U
#define UART_MSR_RI_MASK                         0x00000040U
#define UART_MSR_RI_POS                          6U
#define UART_MSR_DSR_MASK                        0x00000020U
#define UART_MSR_DSR_POS                         5U
#define UART_MSR_CTS_MASK                        0x00000010U
#define UART_MSR_CTS_POS                         4U
#define UART_MSR_DDCD_MASK                       0x00000008U
#define UART_MSR_DDCD_POS                        3U
#define UART_MSR_TERI_MASK                       0x00000004U
#define UART_MSR_TERI_POS                        2U
#define UART_MSR_DDSR_MASK                       0x00000002U
#define UART_MSR_DDSR_POS                        1U
#define UART_MSR_DCTS_MASK                       0x00000001U
#define UART_MSR_DCTS_POS                        0U

/* Bit fields of SCR register */
#define UART_SCR_SCR_MASK                        0x000000FFU
#define UART_SCR_SCR_POS                         0U

/* Bit fields of SRBR0 register */
#define UART_SRBR0_SRBR0_MASK                    0x000000FFU
#define UART_SRBR0_SRBR0_POS                     0U

/* Bit fields of STHR0 register */
#define UART_STHR0_STHR0_MASK                    0x000000FFU
#define UART_STHR0_STHR0_POS                     0U

/* Bit fields of SRBR1 register */
#define UART_SRBR1_SRBR1_MASK                    0x000000FFU
#define UART_SRBR1_SRBR1_POS                     0U

/* Bit fields of STHR1 register */
#define UART_STHR1_STHR1_MASK                    0x000000FFU
#define UART_STHR1_STHR1_POS                     0U

/* Bit fields of SRBR2 register */
#define UART_SRBR2_SRBR2_MASK                    0x000000FFU
#define UART_SRBR2_SRBR2_POS                     0U

/* Bit fields of STHR2 register */
#define UART_STHR2_STHR2_MASK                    0x000000FFU
#define UART_STHR2_STHR2_POS                     0U

/* Bit fields of SRBR3 register */
#define UART_SRBR3_SRBR3_MASK                    0x000000FFU
#define UART_SRBR3_SRBR3_POS                     0U

/* Bit fields of STHR3 register */
#define UART_STHR3_STHR3_MASK                    0x000000FFU
#define UART_STHR3_STHR3_POS                     0U

/* Bit fields of SRBR4 register */
#define UART_SRBR4_SRBR4_MASK                    0x000000FFU
#define UART_SRBR4_SRBR4_POS                     0U

/* Bit fields of STHR4 register */
#define UART_STHR4_STHR4_MASK                    0x000000FFU
#define UART_STHR4_STHR4_POS                     0U

/* Bit fields of SRBR5 register */
#define UART_SRBR5_SRBR5_MASK                    0x000000FFU
#define UART_SRBR5_SRBR5_POS                     0U

/* Bit fields of STHR5 register */
#define UART_STHR5_STHR5_MASK                    0x000000FFU
#define UART_STHR5_STHR5_POS                     0

/* Bit fields of SRBR6 register */
#define UART_SRBR6_SRBR6_MASK                    0x000000FFU
#define UART_SRBR6_SRBR6_POS                     0U

/* Bit fields of STHR6 register */
#define UART_STHR6_STHR6_MASK                    0x000000FFU
#define UART_STHR6_STHR6_POS                     0U

/* Bit fields of SRBR7 register */
#define UART_SRBR7_SRBR7_MASK                    0x000000FFU
#define UART_SRBR7_SRBR7_POS                     0U

/* Bit fields of STHR7 register */
#define UART_STHR7_STHR7_MASK                    0x000000FFU
#define UART_STHR7_STHR7_POS                     0U

/* Bit fields of SRBR8 register */
#define UART_SRBR8_SRBR8_MASK                    0x000000FFU
#define UART_SRBR8_SRBR8_POS                     0U

/* Bit fields of STHR8 register */
#define UART_STHR8_STHR8_MASK                    0x000000FFU
#define UART_STHR8_STHR8_POS                     0U

/* Bit fields of SRBR9 register */
#define UART_SRBR9_SRBR9_MASK                    0x000000FFU
#define UART_SRBR9_SRBR9_POS                     0U

/* Bit fields of STHR9 register */
#define UART_STHR9_STHR9_MASK                    0x000000FFU
#define UART_STHR9_STHR9_POS                     0U

/* Bit fields of SRBR10 register */
#define UART_SRBR10_SRBR10_MASK                  0x000000FFU
#define UART_SRBR10_SRBR10_POS                   0U

/* Bit fields of STHR10 register */
#define UART_STHR10_STHR10_MASK                  0x000000FFU
#define UART_STHR10_STHR10_POS                   0U

/* Bit fields of SRBR11 register */
#define UART_SRBR11_SRBR11_MASK                  0x000000FFU
#define UART_SRBR11_SRBR11_POS                   0U

/* Bit fields of STHR11 register */
#define UART_STHR11_STHR11_MASK                  0x000000FFU
#define UART_STHR11_STHR11_POS                   0U

/* Bit fields of SRBR12 register */
#define UART_SRBR12_SRBR12_MASK                  0x000000FFU
#define UART_SRBR12_SRBR12_POS                   0U

/* Bit fields of STHR12 register */
#define UART_STHR12_STHR12_MASK                  0x000000FFU
#define UART_STHR12_STHR12_POS                   0U

/* Bit fields of SRBR13 register */
#define UART_SRBR13_SRBR13_MASK                  0x000000FFU
#define UART_SRBR13_SRBR13_POS                   0U

/* Bit fields of STHR13 register */
#define UART_STHR13_STHR13_MASK                  0x000000FFU
#define UART_STHR13_STHR13_POS                   0U

/* Bit fields of SRBR14 register */
#define UART_SRBR14_SRBR14_MASK                  0x000000FFU
#define UART_SRBR14_SRBR14_POS                   0U

/* Bit fields of STHR14 register */
#define UART_STHR14_STHR14_MASK                  0x000000FFU
#define UART_STHR14_STHR14_POS                   0U

/* Bit fields of SRBR15 register */
#define UART_SRBR15_SRBR15_MASK                  0x000000FFU
#define UART_SRBR15_SRBR15_POS                   0U

/* Bit fields of STHR15 register */
#define UART_STHR15_STHR15_MASK                  0x000000FFU
#define UART_STHR15_STHR15_POS                   0U

/* Bit fields of FAR register */
#define UART_FAR_FAR_MASK                        0x00000001U
#define UART_FAR_FAR_POS                         0U

/* Bit fields of TFR register */
#define UART_TFR_TFR_MASK                        0x000000FFU
#define UART_TFR_TFR_POS                         0U

/* Bit fields of RFW register */
#define UART_RFW_RFFE_MASK                       0x00000200U
#define UART_RFW_RFFE_POS                        9U
#define UART_RFW_RFPE_MASK                       0x00000100U
#define UART_RFW_RFPE_POS                        8U
#define UART_RFW_RFWD_MASK                       0x000000FFU
#define UART_RFW_RFWD_POS                        0U

/* Bit fields of USR register */
#define UART_USR_RFF_MASK                        0x00000010U
#define UART_USR_RFF_POS                         4U
#define UART_USR_RFNE_MASK                       0x00000008U
#define UART_USR_RFNE_POS                        3U
#define UART_USR_TFE_MASK                        0x00000004U
#define UART_USR_TFE_POS                         2U
#define UART_USR_TFNF_MASK                       0x00000002U
#define UART_USR_TFNF_POS                        1U

/* Bit fields of TFL register */
#define UART_TFL_TFL_MASK                        0x000000FFU
#define UART_TFL_TFL_POS                         0U

/* Bit fields of RFL register */
#define UART_RFL_RFL_MASK                        0x000000FFU
#define UART_RFL_RFL_POS                         0U

/* Bit fields of SRR register */
#define UART_SRR_XFR_MASK                        0x00000004U
#define UART_SRR_XFR_POS                         2U
#define UART_SRR_RFR_MASK                        0x00000002U
#define UART_SRR_RFR_POS                         1U
#define UART_SRR_UR_MASK                         0x00000001U
#define UART_SRR_UR_POS                          0U

/* Bit fields of SRTS register */
#define UART_SRTS_SRTS_MASK                      0x00000001U
#define UART_SRTS_SRTS_POS                       0U

/* Bit fields of SBCR register */
#define UART_SBCR_SBCB_MASK                      0x00000001U
#define UART_SBCR_SBCB_POS                       0U

/* Bit fields of SDMAM register */
#define UART_SDMAM_SDMAM_MASK                    0x00000001U
#define UART_SDMAM_SDMAM_POS                     0U

/* Bit fields of SFE register */
#define UART_SFE_SFE_MASK                        0x00000001U
#define UART_SFE_SFE_POS                         0U

/* Bit fields of SRT register */
#define UART_SRT_SRT_MASK                        0x00000003U
#define UART_SRT_SRT_POS                         0U

/* Bit fields of STET register */
#define UART_STET_STET_MASK                      0x00000003U
#define UART_STET_STET_POS                       0U

/* Bit fields of HTX register */
#define UART_HTX_HTX_MASK                        0x00000001U
#define UART_HTX_HTX_POS                         0U

/* Bit fields of DMASA register */
#define UART_DMASA_DMASA_MASK                    0x00000001U
#define UART_DMASA_DMASA_POS                     0U

/* Bit fields of CPR register */
#define UART_CPR_FIFO_MODE_MASK                  0x00FF0000U
#define UART_CPR_FIFO_MODE_POS                   16U
#define UART_CPR_DMA_EXTRA_MASK                  0x00002000U
#define UART_CPR_DMA_EXTRA_POS                   13U
#define UART_CPR_UART_ADD_ENCODED_PARAMS_MASK    0x00001000U
#define UART_CPR_UART_ADD_ENCODED_PARAMS_POS     12U
#define UART_CPR_SHADOW_MASK                     0x00000800U
#define UART_CPR_SHADOW_POS                      11U
#define UART_CPR_FIFO_STAT_MASK                  0x00000400U
#define UART_CPR_FIFO_STAT_POS                   10U
#define UART_CPR_FIFO_ACCESS_MASK                0x00000200U
#define UART_CPR_FIFO_ACCESS_POS                 9U
#define UART_CPR_ADDITIONAL_FEAT_MASK            0x00000100U
#define UART_CPR_ADDITIONAL_FEAT_POS             8U
#define UART_CPR_SIR_LP_MODE_MASK                0x00000080U
#define UART_CPR_SIR_LP_MODE_POS                 7U
#define UART_CPR_SIR_MODE_MASK                   0x00000040U
#define UART_CPR_SIR_MODE_POS                    6U
#define UART_CPR_THRE_MODE_MASK                  0x00000020U
#define UART_CPR_THRE_MODE_POS                   5U
#define UART_CPR_AFCE_MODE_MASK                  0x00000010U
#define UART_CPR_AFCE_MODE_POS                   4U
#define UART_CPR_APB_DATA_WIDTH_MASK             0x00000003U
#define UART_CPR_APB_DATA_WIDTH_POS              0U

/* Bit fields of UCV register */
#define UART_UCV_UART_COMPONENT_VERSION_MASK     0xFFFFFFFFU
#define UART_UCV_UART_COMPONENT_VERSION_POS      0U

/* Bit fields of CTR register */
#define UART_CTR_PERIPHERAL_ID_MASK              0xFFFFFFFFU
#define UART_CTR_PERIPHERAL_ID_POS               0U

#endif /* __SOCFPGA_UART_REG_H__ */
