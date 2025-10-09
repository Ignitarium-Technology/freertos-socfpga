/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * This contains the register defintions for SoC FPGA XGMAC
 */

#ifndef __SOCFPGA_XGMAC_REG_H__
#define __SOCFPGA_XGMAC_REG_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Clock Manager Registers */
#define PHERI_PLL_GRP_BASE_ADDRESS    0x10D1007CU
#define ENABLE_EMAC_REG               0x00U

/* Reset Manager Registers */
#define RESET_MNGR_BASE_ADDRESS       0x10D11000U
#define PER0MODRST_REG                0x24U
#define RST_SHIFT_POS                 0

/* System Manager Registers */
#define SYSTEM_MNGR_BASE_ADDRESS      0x10D12000U
#define TSN0_REG                      0x44U
#define TSN1_REG                      0x48U
#define TSN2_REG                      0x4CU
#define FPGA_INTF_EN3_REG             0x70U

#define PHY_INTF_SEL_FIELD_POS        0U
#define SDB_DATA_ENDIAN_POS           30U

#define PHY_INTF_SEL_FIELD_MASK       0x3U

#define SDB_DATA_ENDIAN_MASK          ((uint32_t) 1U << SDB_DATA_ENDIAN_POS)

#define TSN0_FIELD_POS                0U
#define TSN1_FIELD_POS                8U
#define TSN2_FIELD_POS                16U

#define TSN0_FIELD_MASK               (1U << TSN0_FIELD_POS)
#define TSN1_FIELD_MASK               ((uint32_t) 1U << TSN1_FIELD_POS)
#define TSN2_FIELD_MASK               ((uint32_t) 1U << TSN2_FIELD_POS)


/*DMA buffer descriptors */
/* TDES0 Normal Descriptor (Read Format) */
#define TDES0_NORM_RD_BUF1AP_MASK         0xFFFFFFFFU
#define TDES1_NORM_RD_BUF2AP_MASK         0xFFFFFFFFU

/* TDES2 Normal Descriptor (Read Format) */
#define TDES2_NORM_RD_IOC_MASK            0x80000000U
#define TDES2_NORM_RD_TTSE_TMWD_MASK      0x40000000U
#define TDES2_NORM_RD_B2L_MASK            0x3FFF0000U
#define TDES2_NORM_RD_VTIR_MASK           0x0000C000U
#define TDES2_NORM_RD_HL_B1L_MASL         0x00003FFFU

/* TDES3 Normal Descriptor (Read Format) */
#define TDES3_NORM_RD_OWN_MASK            0x80000000U
#define TDES3_NORM_RD_CTXT_MASK           0x40000000U
#define TDES3_NORM_RD_FD_MASK             0x20000000U
#define TDES3_NORM_RD_LD_MASK             0x10000000U
#define TDES3_NORM_RD_CPC_MASK            0x0C000000U
#define TDES3_NORM_RD_SAIC_VNP_MASK       0x03800000U
#define TDES3_NORM_RD_SLOTNUM_THL_MASK    0x00780000U
#define TDES3_NORM_RD_TSE_MASK            0x00040000U
#define TDES3_NORM_RD_CIC_TPL_MASK        0x00030000U
#define TDES3_NORM_RD_TPL_MASK            0x00008000U
#define TDES3_NORM_RD_FL_TPL_MASK         0x00007FFFU

/* TDES3 Normal Descriptor (Write-Back Format) */
#define TDES3_NORM_WR_OWN_MASK            0x80000000U
#define TDES3_NORM_WR_CTXT_MASK           0x40000000U
#define TDES3_NORM_WR_FD_MASK             0x20000000U
#define TDES3_NORM_WR_LD_MASK             0x10000000U
#define TDES3_NORM_WR_DERR_MASK           0x08000000U
#define TDES3_NORM_WR_RSVD_MASK           0x07FFFFFFU

/* RDES0/RDES1/RDES2 Normal Descriptor (Read Format) */
#define RDES0_NORM_RD_BUF1AP_MASK         0xFFFFFFFFU
#define RDES1_NORM_RD_BUF1AP_MASK         0xFFFFFFFFU
#define RDES2_NORM_RD_BUF2AP_MASK         0xFFFFFFFFU

/* RDES3 Normal Descriptor (Read Format) */
#define RDES3_NORM_RD_OWN_MASK            0x80000000U
#define RDES3_NORM_RD_IOC_MASK            0x40000000U
#define RDES3_NORM_RD_BUF2AP_MASK         0x3FFFFFFFU

/* RDES0 Normal Descriptor (Write-Back Format) */
/* For Tunneled Frames (TNP = 0U) */
#define RDES0_NORM_WR_IVT_ELRD_MASK         0xFFFF0000U
#define RDES0_NORM_WR_OVT_ELRD_MASK         0x0000FFFFU
/* For Tunneled Frames (TNP = 1U) */
#define RDES0_NORM_WR_TNP_VNID_VSID_MASK    0xFFFFFF00U
#define RDES0_NORM_WR_TNP_RSVD_MASK         0x000000F8U
#define RDES0_NORM_WR_TNP_OL2L3_MASK        0x00000007U

/* RDES1 Normal Descriptor (Write-Back Format) */
#define RDES1_NORM_WR_RSSH_FRPLI_MASK       0xFFFFFFFFU

/* RDES2 Normal Descriptor (Write-Back Format) */
#define RDES2_NORM_WR_L3L4FM_MASK           0xE0000000U
#define RDES2_NORM_WR_L4FM_MASK             0x10000000U
#define RDES2_NORM_WR_L3FM_MASK             0x08000000U
#define RDES2_NORM_WR_MADRM_MASK            0x07F80000U
#define RDES2_NORM_WR_HFDAF_MASK            0x00060000U
#define RDES2_NORM_WR_DAF_MASK              0x00020000U
#define RDES2_NORM_WR_SAF_MASK              0x00010000U
#define RDES2_NORM_WR_VF_MASK               0x00008000U
#define RDES2_NORM_WR_RPNG_MASK             0x00004000U
#define RDES2_NORM_WR_IOS_MASK              0x00002000U
#define RDES2_NORM_WR_ELD_MASK              0x00001000U
#define RDES2_NORM_WR_TNP_MASK              0x00000800U
#define RDES2_NORM_WR_RSVD_MASK             0x00000400U
#define RDES2_NORM_WR_HL_MASK               0x000003F4U
#define RDES2_NORM_WR_AVTDP_MASK            0x00000002U
#define RDES2_NORM_WR_AVTCP_MASK            0x00000001U

/* RDES3 Normal Descriptor (Write-Back Format) */
#define RDES3_NORM_WR_OWN_MASK              0x80000000U
#define RDES3_NORM_WR_CTXT_MASK             0x40000000U
#define RDES3_NORM_WR_FD_MASK               0x20000000U
#define RDES3_NORM_WR_LD_MASK               0x10000000U
#define RDES3_NORM_WR_CDA_MASK              0x08000000U
#define RDES3_NORM_WR_RSV_MASK              0x04000000U
#define RDES3_NORM_WR_ISP_MASK              0x02000000U
#define RDES3_NORM_WR_ETM_NCP_MASK          0x01000000U
#define RDES3_NORM_WR_L34T_MASK             0x00F00000U
#define RDES3_NORM_WR_ET_LT_MASK            0x000F0000U
#define RDES3_NORM_WR_ES_MASK               0x00008000U
#define RDES3_NORM_WR_RSVD_MASK             0x00004000U
#define RDES3_NORM_WR_PL_MASK               0x00003FFFU


/* EMAC Base Addr Registers */
#define XGMAC_EMAC_BASEADDR                     \
        0X10810000U
#define XGMAC_EMAC0_BASEADDR                    \
        0X10810000U
#define XGMAC_EMAC1_BASEADDR                    \
        0X10820000U
#define XGMAC_EMAC2_BASEADDR                    \
        0X10830000U

/* EMAC Core Addr Registers */
#define XGMAC_EMAC_CORE_BASEADDR                \
        0X10810000U
#define XGMAC_EMAC0_CORE_REGADDR                \
        0X10810000U
#define XGMAC_EMAC1_CORE_REGADDR                \
        0X10820000U
#define XGMAC_EMAC2_CORE_REGADDR                \
        0X10830000U

/* EMAC MTL Addr Registers */
#define XGMAC_EMAC_MTL_BASEADDR                 \
        0X10811000U
#define XGMAC_EMAC0_MTL_REGADDR                 \
        0X10811000U
#define XGMAC_EMAC1_MTL_REGADDR                 \
        0X10821000U
#define XGMAC_EMAC2_MTL_REGADDR                 \
        0X10831000U

/* EMAC DMA Base Addr Registers */
#define XGMAC_EMAC_DMA_BASEADDR                 \
        0X10813000U
#define XGMAC_EMAC0_DMA_REGADDR                 \
        0X10813000U
#define XGMAC_EMAC1_DMA_REGADDR                 \
        0X10823000U
#define XGMAC_EMAC2_DMA_REGADDR                 \
        0X10833000U

/* EMAC DMA Channel Register Offsets */
#define XGMAC_DMA_CHANNEL_BASE              \
        0x0100U
#define XGMAC_DMA_CHANNEL_INC               \
        0x80U

/* DMA_CH_Control */
#define XGMAC_DMA_CH_CONTROL  \
        0x00U
/* DMA_CH_Tx_Control */
#define XGMAC_DMA_CH_TX_CONTROL \
        0x04U
/* DMA_CH_Rx_Control */
#define XGMAC_DMA_CH_RX_CONTROL \
        0x08U
/* DMA_CH_Slot_Function_Control_Status */
#define XGMAC_DMA_CH_SLOT_FUNCTION_CONTROL_STATUS \
        0x0CU
/* DMA_CH_TxDesc_List_HAddress */
#define XGMAC_DMA_CH_TXDESC_LIST_HADDRESS \
        0x10U
/* DMA_CH_TxDesc_List_LAddress */
#define XGMAC_DMA_CH_TXDESC_LIST_LADDRESS \
        0x14U
/* DMA_CH_RxDesc_List_HAddress */
#define XGMAC_DMA_CH_RXDESC_LIST_HADDRESS \
        0x18U
/* DMA_CH_RxDesc_List_LAddress */
#define XGMAC_DMA_CH_RXDESC_LIST_LADDRESS \
        0x1CU
/* DMA_CH_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH_TXDESC_TAIL_LPOINTER \
        0x24U
/* DMA_CH_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH_RXDESC_TAIL_LPOINTER \
        0x2CU
/* DMA_CH_Tx_Control2 */
#define XGMAC_DMA_CH_TX_CONTROL2 \
        0x30U
/* DMA_CH_Rx_Control2 */
#define XGMAC_DMA_CH_RX_CONTROL2 \
        0x34U
/* DMA_CH_Interrupt_Enable */
#define XGMAC_DMA_CH_INTERRUPT_ENABLE \
        0x38U
/* DMA_CH_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH_RX_INTERRUPT_WATCHDOG_TIMER \
        0x3CU
/* DMA_CH_Current_App_TxDesc_L */
#define XGMAC_DMA_CH_CURRENT_APP_TXDESC_L \
        0x44U
/* DMA_CH_Current_App_RxDesc_L */
#define XGMAC_DMA_CH_CURRENT_APP_RXDESC_L \
        0x4CU
/* DMA_CH_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH_CURRENT_APP_TXBUFFER_H \
        0x50U
/* DMA_CH_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH_CURRENT_APP_TXBUFFER_L \
        0x54U
/* DMA_CH_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH_CURRENT_APP_RXBUFFER_H \
        0x58U
/* DMA_CH_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH_CURRENT_APP_RXBUFFER_L \
        0x5CU
/* DMA_CH_Status */
#define XGMAC_DMA_CH_STATUS \
        0x60U
/* DMA_CH_Debug_Status */
#define XGMAC_DMA_CH_DEBUG_STATUS \
        0x64U
/* DMA_CH_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH_DESC_MEM_CACHE_FILL_LEVEL \
        0x68U
/* DMA_CH_Miss_Packet_Cnt */
#define XGMAC_DMA_CH_MISS_PACKET_CNT \
        0x6CU
/* DMA_CH_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH_TX_DATA_XFER_RING_OFFSET \
        0x70U
/* DMA_CH_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH_RX_DATA_XFER_RING_OFFSET \
        0x74U
/* DMA_CH_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH_TX_DESC_WRITE_RING_OFFSET \
        0x78U
/* DMA_CH_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH_RX_DESC_WRITE_RING_OFFSET \
        0x7CU

/* Bit fields of DMA_CH_Control register */
#define XGMAC_DMA_CH_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH_CONTROL_PBLX8_POS \
        16U
#define XGMAC_DMA_CH_CONTROL_MSS_MASK \
        0x00003FFFU
#define XGMAC_DMA_CH_CONTROL_MSS_POS \
        0U

/* Bit fields of DMA_CH_Tx_Control register */
#define XGMAC_DMA_CH_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH_TX_CONTROL_TSE_MASK \
        0x00001000U
#define XGMAC_DMA_CH_TX_CONTROL_TSE_POS \
        12U
#define XGMAC_DMA_CH_TX_CONTROL_RESVOSP_MASK \
        0x00000008U
#define XGMAC_DMA_CH_TX_CONTROL_RESVOSP_POS \
        4U
#define XGMAC_DMA_CH_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH_Rx_Control register */
#define XGMAC_DMA_CH_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH_RX_CONTROL_SR_POS \
        0U

/* MAC Tx Flow Control Register Offsets */
#define XGMAC_TX_FLOW_CONTROL_INC       \
        0x4U

/* EMAC MTL Traffic Class Queue Register Offsets */
#define XGMAC_MTL_TC_BASE               \
        0x0100U
#define XGMAC_MTL_TC_INC                \
        0x80U

/* MTL_TxQ0_Operation_Mode */
#define XGMAC_MTL_TXQ_OPERATION_MODE \
        0x0U
/* MTL_TxQ0_Underflow */
#define XGMAC_MTL_TXQ_UNDERFLOW \
        0x4U
/* MTL_TxQ0_Debug */
#define XGMAC_MTL_TXQ_DEBUG \
        0x8U
/* MTL_TC0_ETS_Control */
#define XGMAC_MTL_TC_ETS_CONTROL \
        0x10U
/* MTL_TC0_ETS_Status */
#define XGMAC_MTL_TC_ETS_STATUS \
        0x14U
/* MTL_TC0_Quantum_Weight */
#define XGMAC_MTL_TC_QUANTUM_WEIGHT \
        0x18U
/* MTL_RxQ0_Operation_Mode */
#define XGMAC_MTL_RXQ_OPERATION_MODE \
        0x40U
/* MTL_RxQ0_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ_MISSED_PKT_OVERFLOW_CNT \
        0x44U
/* MTL_RxQ0_Debug */
#define XGMAC_MTL_RXQ_DEBUG \
        0x48U
/* MTL_RxQ0_Control */
#define XGMAC_MTL_RX_CONTROL \
        0x4CU
/* MTL_RxQ0_Flow_Control */
#define XGMAC_MTL_RXQ_FLOW_CONTROL \
        0x50U
/* MTL_Q0_Interrupt_Enable */
#define XGMAC_MTL_Q_INTERRUPT_ENABLE \
        0x70U
/* MTL_Q0_Interrupt_Status */
#define XGMAC_MTL_Q_INTERRUPT_STATUS \
        0x74U

/* Bit fields of MTL_TxQ_Operation_Mode register */
#define XGMAC_MTL_TXQ_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TC0_Quantum_Weight register */
#define XGMAC_MTL_TC_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ_Operation_Mode register */
#define XGMAC_MTL_RXQ_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ_Control register */
#define XGMAC_MTL_RXQ_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ0_Flow_Control register */
#define XGMAC_MTL_RXQ_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q_Interrupt_Enable register */
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q_Interrupt_Status register */
#define XGMAC_MTL_Q_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* MAC_Tx_Configuration */
#define XGMAC_MAC_TX_CONFIGURATION \
        0x0000U
/* MAC_Rx_Configuration */
#define XGMAC_MAC_RX_CONFIGURATION \
        0x0004U
/* MAC_Packet_Filter */
#define XGMAC_MAC_PACKET_FILTER \
        0x0008U
/* MAC_WD_JB_Timeout */
#define XGMAC_MAC_WD_JB_TIMEOUT \
        0x000CU
/* MAC_Hash_Table_Reg0 */
#define XGMAC_MAC_HASH_TABLE_REG0 \
        0x0010U
/* MAC_Hash_Table_Reg1 */
#define XGMAC_MAC_HASH_TABLE_REG1 \
        0x0014U
/* MAC_VLAN_Tag_Ctrl */
#define XGMAC_MAC_VLAN_TAG_CTRL \
        0x0050U
/* MAC_VLAN_Tag_Data */
#define XGMAC_MAC_VLAN_TAG_DATA \
        0x0054U
/* MAC_VLAN_Tag_Filter0 */
#define XGMAC_MAC_VLAN_TAG_FILTER0 \
        0x0054U
/* MAC_VLAN_Tag_Filter1 */
#define XGMAC_MAC_VLAN_TAG_FILTER1 \
        0x0054U
/* MAC_VLAN_Tag_Filter10 */
#define XGMAC_MAC_VLAN_TAG_FILTER10 \
        0x0054U
/* MAC_VLAN_Tag_Filter11 */
#define XGMAC_MAC_VLAN_TAG_FILTER11 \
        0x0054U
/* MAC_VLAN_Tag_Filter12 */
#define XGMAC_MAC_VLAN_TAG_FILTER12 \
        0x0054U
/* MAC_VLAN_Tag_Filter13 */
#define XGMAC_MAC_VLAN_TAG_FILTER13 \
        0x0054U
/* MAC_VLAN_Tag_Filter14 */
#define XGMAC_MAC_VLAN_TAG_FILTER14 \
        0x0054U
/* MAC_VLAN_Tag_Filter15 */
#define XGMAC_MAC_VLAN_TAG_FILTER15 \
        0x0054U
/* MAC_VLAN_Tag_Filter16 */
#define XGMAC_MAC_VLAN_TAG_FILTER16 \
        0x0054U
/* MAC_VLAN_Tag_Filter17 */
#define XGMAC_MAC_VLAN_TAG_FILTER17 \
        0x0054U
/* MAC_VLAN_Tag_Filter18 */
#define XGMAC_MAC_VLAN_TAG_FILTER18 \
        0x0054U
/* MAC_VLAN_Tag_Filter19 */
#define XGMAC_MAC_VLAN_TAG_FILTER19 \
        0x0054U
/* MAC_VLAN_Tag_Filter2 */
#define XGMAC_MAC_VLAN_TAG_FILTER2 \
        0x0054U
/* MAC_VLAN_Tag_Filter20 */
#define XGMAC_MAC_VLAN_TAG_FILTER20 \
        0x0054U
/* MAC_VLAN_Tag_Filter21 */
#define XGMAC_MAC_VLAN_TAG_FILTER21 \
        0x0054U
/* MAC_VLAN_Tag_Filter22 */
#define XGMAC_MAC_VLAN_TAG_FILTER22 \
        0x0054U
/* MAC_VLAN_Tag_Filter23 */
#define XGMAC_MAC_VLAN_TAG_FILTER23 \
        0x0054U
/* MAC_VLAN_Tag_Filter24 */
#define XGMAC_MAC_VLAN_TAG_FILTER24 \
        0x0054U
/* MAC_VLAN_Tag_Filter25 */
#define XGMAC_MAC_VLAN_TAG_FILTER25 \
        0x0054U
/* MAC_VLAN_Tag_Filter26 */
#define XGMAC_MAC_VLAN_TAG_FILTER26 \
        0x0054U
/* MAC_VLAN_Tag_Filter27 */
#define XGMAC_MAC_VLAN_TAG_FILTER27 \
        0x0054U
/* MAC_VLAN_Tag_Filter28 */
#define XGMAC_MAC_VLAN_TAG_FILTER28 \
        0x0054U
/* MAC_VLAN_Tag_Filter29 */
#define XGMAC_MAC_VLAN_TAG_FILTER29 \
        0x0054U
/* MAC_VLAN_Tag_Filter3 */
#define XGMAC_MAC_VLAN_TAG_FILTER3 \
        0x0054U
/* MAC_VLAN_Tag_Filter30 */
#define XGMAC_MAC_VLAN_TAG_FILTER30 \
        0x0054U
/* MAC_VLAN_Tag_Filter31 */
#define XGMAC_MAC_VLAN_TAG_FILTER31 \
        0x0054U
/* MAC_VLAN_Tag_Filter4 */
#define XGMAC_MAC_VLAN_TAG_FILTER4 \
        0x0054U
/* MAC_VLAN_Tag_Filter5 */
#define XGMAC_MAC_VLAN_TAG_FILTER5 \
        0x0054U
/* MAC_VLAN_Tag_Filter6 */
#define XGMAC_MAC_VLAN_TAG_FILTER6 \
        0x0054U
/* MAC_VLAN_Tag_Filter7 */
#define XGMAC_MAC_VLAN_TAG_FILTER7 \
        0x0054U
/* MAC_VLAN_Tag_Filter8 */
#define XGMAC_MAC_VLAN_TAG_FILTER8 \
        0x0054U
/* MAC_VLAN_Tag_Filter9 */
#define XGMAC_MAC_VLAN_TAG_FILTER9 \
        0x0054U
/* MAC_VLAN_Hash_Table */
#define XGMAC_MAC_VLAN_HASH_TABLE \
        0x0058U
/* MAC_VLAN_Incl */
#define XGMAC_MAC_VLAN_INCL \
        0x0060U
/* MAC_VLAN_Incl0 */
#define XGMAC_MAC_VLAN_INCL0 \
        0x0060U
/* MAC_VLAN_Incl1 */
#define XGMAC_MAC_VLAN_INCL1 \
        0x0060U
/* MAC_VLAN_Incl10 */
#define XGMAC_MAC_VLAN_INCL10 \
        0x0060U
/* MAC_VLAN_Incl11 */
#define XGMAC_MAC_VLAN_INCL11 \
        0x0060U
/* MAC_VLAN_Incl12 */
#define XGMAC_MAC_VLAN_INCL12 \
        0x0060U
/* MAC_VLAN_Incl13 */
#define XGMAC_MAC_VLAN_INCL13 \
        0x0060U
/* MAC_VLAN_Incl14 */
#define XGMAC_MAC_VLAN_INCL14 \
        0x0060U
/* MAC_VLAN_Incl15 */
#define XGMAC_MAC_VLAN_INCL15 \
        0x0060U
/* MAC_VLAN_Incl2 */
#define XGMAC_MAC_VLAN_INCL2 \
        0x0060U
/* MAC_VLAN_Incl3 */
#define XGMAC_MAC_VLAN_INCL3 \
        0x0060U
/* MAC_VLAN_Incl4 */
#define XGMAC_MAC_VLAN_INCL4 \
        0x0060U
/* MAC_VLAN_Incl5 */
#define XGMAC_MAC_VLAN_INCL5 \
        0x0060U
/* MAC_VLAN_Incl6 */
#define XGMAC_MAC_VLAN_INCL6 \
        0x0060U
/* MAC_VLAN_Incl7 */
#define XGMAC_MAC_VLAN_INCL7 \
        0x0060U
/* MAC_VLAN_Incl8 */
#define XGMAC_MAC_VLAN_INCL8 \
        0x0060U
/* MAC_VLAN_Incl9 */
#define XGMAC_MAC_VLAN_INCL9 \
        0x0060U
/* MAC_Inner_VLAN_Incl */
#define XGMAC_MAC_INNER_VLAN_INCL \
        0x0064U
/* MAC_Rx_Eth_Type_Match */
#define XGMAC_MAC_RX_ETH_TYPE_MATCH \
        0x006CU
/* MAC_Q0_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q0_TX_FLOW_CTRL \
        0x0070U
/* MAC_Q1_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q1_TX_FLOW_CTRL \
        0x0074U
/* MAC_Q2_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q2_TX_FLOW_CTRL \
        0x0078U
/* MAC_Q3_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q3_TX_FLOW_CTRL \
        0x007CU
/* MAC_Q4_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q4_TX_FLOW_CTRL \
        0x0080U
/* MAC_Q5_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q5_TX_FLOW_CTRL \
        0x0084U
/* MAC_Q6_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q6_TX_FLOW_CTRL \
        0x0088U
/* MAC_Q7_Tx_Flow_Ctrl */
#define XGMAC_MAC_Q7_TX_FLOW_CTRL \
        0x008CU
/* MAC_Rx_Flow_Ctrl */
#define XGMAC_MAC_RX_FLOW_CTRL \
        0x0090U
/* MAC_RxQ_Ctrl4 */
#define XGMAC_MAC_RXQ_CTRL4 \
        0x0094U
/* MAC_RxQ_Ctrl5 */
#define XGMAC_MAC_RXQ_CTRL5 \
        0x0098U
/* MAC_RxQ_Ctrl0 */
#define XGMAC_MAC_RXQ_CTRL0 \
        0x00A0U
/* MAC_RxQ_Ctrl1 */
#define XGMAC_MAC_RXQ_CTRL1 \
        0x00A4U
/* MAC_RxQ_Ctrl2 */
#define XGMAC_MAC_RXQ_CTRL2 \
        0x00A8U
/* MAC_RxQ_Ctrl3 */
#define XGMAC_MAC_RXQ_CTRL3 \
        0x00ACU
/* MAC_Interrupt_Status */
#define XGMAC_MAC_INTERRUPT_STATUS \
        0x00B0U
/* MAC_Interrupt_Enable */
#define XGMAC_MAC_INTERRUPT_ENABLE \
        0x00B4U
/* MAC_Rx_Tx_Status */
#define XGMAC_MAC_RX_TX_STATUS \
        0x00B8U
/* MAC_Version */
#define XGMAC_MAC_VERSION \
        0x0110U
/* MAC_Debug */
#define XGMAC_MAC_DEBUG \
        0x0114U
/* MAC_HW_Feature0 */
#define XGMAC_MAC_HW_FEATURE0 \
        0x011CU
/* MAC_HW_Feature1 */
#define XGMAC_MAC_HW_FEATURE1 \
        0x0120U
/* MAC_HW_Feature2 */
#define XGMAC_MAC_HW_FEATURE2 \
        0x0124U
/* MAC_HW_Feature3 */
#define XGMAC_MAC_HW_FEATURE3 \
        0x0128U
/* MAC_HW_Feature4 */
#define XGMAC_MAC_HW_FEATURE4 \
        0x012CU
/* MAC_Extended_Configuration */
#define XGMAC_MAC_EXTENDED_CONFIGURATION \
        0x0140U
/* MAC_Ext_Cfg1 */
#define XGMAC_MAC_EXT_CFG1 \
        0x0144U
/* MDIO_Single_Command_Address */
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS \
        0x0200U
/* MDIO_Single_Command_Control_Data */
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA \
        0x0204U
/* MDIO_Continuous_Write_Address */
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS \
        0x0208U
/* MDIO_Continuous_Write_Data */
#define XGMAC_MDIO_CONTINUOUS_WRITE_DATA \
        0x020CU
/* MDIO_Continuous_Scan_Port_Enable */
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE \
        0x0210U
/* MDIO_Interrupt_Status */
#define XGMAC_MDIO_INTERRUPT_STATUS \
        0x0214U
/* MDIO_Interrupt_Enable */
#define XGMAC_MDIO_INTERRUPT_ENABLE \
        0x0218U
/* MDIO_Port_Connect_Disconnect_Status */
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS \
        0x021CU
/* MDIO_Clause_22_Port */
#define XGMAC_MDIO_CLAUSE_22_PORT \
        0x0220U
/* MDIO_Port_Nx4_Indirect_Control */
#define XGMAC_MDIO_PORT_NX4_INDIRECT_CONTROL \
        0x0224U
/* MDIO_PortNx4P0_Device_In_Use */
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE \
        0x0230U
/* MDIO_PortNx4P0_Link_Status */
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS \
        0x0234U
/* MDIO_PortNx4P0_Alive_Status */
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS \
        0x0238U
/* MDIO_PortNx4P1_Device_In_Use */
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE \
        0x0240U
/* MDIO_PortNx4P1_Link_Status */
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS \
        0x0244U
/* MDIO_PortNx4P1_Alive_Status */
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS \
        0x0248U
/* MDIO_PortNx4P2_Device_In_Use */
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE \
        0x0250U
/* MDIO_PortNx4P2_Link_Status */
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS \
        0x0254U
/* MDIO_PortNx4P2_Alive_Status */
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS \
        0x0258U
/* MDIO_PortNx4P3_Device_In_Use */
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE \
        0x0260U
/* MDIO_PortNx4P3_Link_Status */
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS \
        0x0264U
/* MDIO_PortNx4P3_Alive_Status */
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS \
        0x0268U
/* MAC_GPIO_Control */
#define XGMAC_MAC_GPIO_CONTROL \
        0x0278U
/* MAC_GPIO_Status */
#define XGMAC_MAC_GPIO_STATUS \
        0x027CU
/* MAC_FPE_CTRL_STS */
#define XGMAC_MAC_FPE_CTRL_STS \
        0x0280U
/* MAC_CSR_SW_Ctrl */
#define XGMAC_MAC_CSR_SW_CTRL \
        0x0290U
/* MAC_Address0_High */
#define XGMAC_MAC_ADDRESS0_HIGH \
        0x0300U
/* MAC_Address0_Low */
#define XGMAC_MAC_ADDRESS0_LOW \
        0x0304U
/* MAC_Address1_High */
#define XGMAC_MAC_ADDRESS1_HIGH \
        0x0308U
/* MAC_Address1_Low */
#define XGMAC_MAC_ADDRESS1_LOW \
        0x030CU
/* MAC_Address2_High */
#define XGMAC_MAC_ADDRESS2_HIGH \
        0x0310U
/* MAC_Address2_Low */
#define XGMAC_MAC_ADDRESS2_LOW \
        0x0314U
/* MAC_Address3_High */
#define XGMAC_MAC_ADDRESS3_HIGH \
        0x0318U
/* MAC_Address3_Low */
#define XGMAC_MAC_ADDRESS3_LOW \
        0x031CU
/* MAC_Address4_High */
#define XGMAC_MAC_ADDRESS4_HIGH \
        0x0320U
/* MAC_Address4_Low */
#define XGMAC_MAC_ADDRESS4_LOW \
        0x0324U
/* MAC_Address5_High */
#define XGMAC_MAC_ADDRESS5_HIGH \
        0x0328U
/* MAC_Address5_Low */
#define XGMAC_MAC_ADDRESS5_LOW \
        0x032CU
/* MAC_Address6_High */
#define XGMAC_MAC_ADDRESS6_HIGH \
        0x0330U
/* MAC_Address6_Low */
#define XGMAC_MAC_ADDRESS6_LOW \
        0x0334U
/* MAC_Address7_High */
#define XGMAC_MAC_ADDRESS7_HIGH \
        0x0338U
/* MAC_Address7_Low */
#define XGMAC_MAC_ADDRESS7_LOW \
        0x033CU
/* MAC_Address8_High */
#define XGMAC_MAC_ADDRESS8_HIGH \
        0x0340U
/* MAC_Address8_Low */
#define XGMAC_MAC_ADDRESS8_LOW \
        0x0344U
/* MAC_Address9_High */
#define XGMAC_MAC_ADDRESS9_HIGH \
        0x0348U
/* MAC_Address9_Low */
#define XGMAC_MAC_ADDRESS9_LOW \
        0x034CU
/* MAC_Address10_High */
#define XGMAC_MAC_ADDRESS10_HIGH \
        0x0350U
/* MAC_Address10_Low */
#define XGMAC_MAC_ADDRESS10_LOW \
        0x0354U
/* MAC_Address11_High */
#define XGMAC_MAC_ADDRESS11_HIGH \
        0x0358U
/* MAC_Address11_Low */
#define XGMAC_MAC_ADDRESS11_LOW \
        0x035CU
/* MAC_Address12_High */
#define XGMAC_MAC_ADDRESS12_HIGH \
        0x0360U
/* MAC_Address12_Low */
#define XGMAC_MAC_ADDRESS12_LOW \
        0x0364U
/* MAC_Address13_High */
#define XGMAC_MAC_ADDRESS13_HIGH \
        0x0368U
/* MAC_Address13_Low */
#define XGMAC_MAC_ADDRESS13_LOW \
        0x036CU
/* MAC_Address14_High */
#define XGMAC_MAC_ADDRESS14_HIGH \
        0x0370U
/* MAC_Address14_Low */
#define XGMAC_MAC_ADDRESS14_LOW \
        0x0374U
/* MAC_Address15_High */
#define XGMAC_MAC_ADDRESS15_HIGH \
        0x0378U
/* MAC_Address15_Low */
#define XGMAC_MAC_ADDRESS15_LOW \
        0x037CU
/* MAC_Address16_High */
#define XGMAC_MAC_ADDRESS16_HIGH \
        0x0380U
/* MAC_Address16_Low */
#define XGMAC_MAC_ADDRESS16_LOW \
        0x0384U
/* MAC_Address17_High */
#define XGMAC_MAC_ADDRESS17_HIGH \
        0x0388U
/* MAC_Address17_Low */
#define XGMAC_MAC_ADDRESS17_LOW \
        0x038CU
/* MAC_Address18_High */
#define XGMAC_MAC_ADDRESS18_HIGH \
        0x0390U
/* MAC_Address18_Low */
#define XGMAC_MAC_ADDRESS18_LOW \
        0x0394U
/* MAC_Address19_High */
#define XGMAC_MAC_ADDRESS19_HIGH \
        0x0398U
/* MAC_Address19_Low */
#define XGMAC_MAC_ADDRESS19_LOW \
        0x039CU
/* MAC_Address20_High */
#define XGMAC_MAC_ADDRESS20_HIGH \
        0x03A0U
/* MAC_Address20_Low */
#define XGMAC_MAC_ADDRESS20_LOW \
        0x03A4U
/* MAC_Address21_High */
#define XGMAC_MAC_ADDRESS21_HIGH \
        0x03A8U
/* MAC_Address21_Low */
#define XGMAC_MAC_ADDRESS21_LOW \
        0x03ACU
/* MAC_Address22_High */
#define XGMAC_MAC_ADDRESS22_HIGH \
        0x03B0U
/* MAC_Address22_Low */
#define XGMAC_MAC_ADDRESS22_LOW \
        0x03B4U
/* MAC_Address23_High */
#define XGMAC_MAC_ADDRESS23_HIGH \
        0x03B8U
/* MAC_Address23_Low */
#define XGMAC_MAC_ADDRESS23_LOW \
        0x03BCU
/* MAC_Address24_High */
#define XGMAC_MAC_ADDRESS24_HIGH \
        0x03C0U
/* MAC_Address24_Low */
#define XGMAC_MAC_ADDRESS24_LOW \
        0x03C4U
/* MAC_Address25_High */
#define XGMAC_MAC_ADDRESS25_HIGH \
        0x03C8U
/* MAC_Address25_Low */
#define XGMAC_MAC_ADDRESS25_LOW \
        0x03CCU
/* MAC_Address26_High */
#define XGMAC_MAC_ADDRESS26_HIGH \
        0x03D0U
/* MAC_Address26_Low */
#define XGMAC_MAC_ADDRESS26_LOW \
        0x03D4U
/* MAC_Address27_High */
#define XGMAC_MAC_ADDRESS27_HIGH \
        0x03D8U
/* MAC_Address27_Low */
#define XGMAC_MAC_ADDRESS27_LOW \
        0x03DCU
/* MAC_Address28_High */
#define XGMAC_MAC_ADDRESS28_HIGH \
        0x03E0U
/* MAC_Address28_Low */
#define XGMAC_MAC_ADDRESS28_LOW \
        0x03E4U
/* MAC_Address29_High */
#define XGMAC_MAC_ADDRESS29_HIGH \
        0x03E8U
/* MAC_Address29_Low */
#define XGMAC_MAC_ADDRESS29_LOW \
        0x03ECU
/* MAC_Address30_High */
#define XGMAC_MAC_ADDRESS30_HIGH \
        0x03F0U
/* MAC_Address30_Low */
#define XGMAC_MAC_ADDRESS30_LOW \
        0x03F4U
/* MAC_Address31_High */
#define XGMAC_MAC_ADDRESS31_HIGH \
        0x03F8U
/* MAC_Address31_Low */
#define XGMAC_MAC_ADDRESS31_LOW \
        0x03FCU
/* MAC_Indir_Access_Ctrl */
#define XGMAC_MAC_INDIR_ACCESS_CTRL \
        0x0700U
/* MAC_Indir_Access_Data */
#define XGMAC_MAC_INDIR_ACCESS_DATA \
        0x0704U
/* MAC_DChSel_IndReg0 */
#define XGMAC_MAC_DCHSEL_INDREG0 \
        0x0704U
/* MAC_DChSel_IndReg1 */
#define XGMAC_MAC_DCHSEL_INDREG1 \
        0x0704U
/* MAC_DChSel_IndReg10 */
#define XGMAC_MAC_DCHSEL_INDREG10 \
        0x0704U
/* MAC_DChSel_IndReg11 */
#define XGMAC_MAC_DCHSEL_INDREG11 \
        0x0704U
/* MAC_DChSel_IndReg12 */
#define XGMAC_MAC_DCHSEL_INDREG12 \
        0x0704U
/* MAC_DChSel_IndReg13 */
#define XGMAC_MAC_DCHSEL_INDREG13 \
        0x0704U
/* MAC_DChSel_IndReg14 */
#define XGMAC_MAC_DCHSEL_INDREG14 \
        0x0704U
/* MAC_DChSel_IndReg15 */
#define XGMAC_MAC_DCHSEL_INDREG15 \
        0x0704U
/* MAC_DChSel_IndReg16 */
#define XGMAC_MAC_DCHSEL_INDREG16 \
        0x0704U
/* MAC_DChSel_IndReg17 */
#define XGMAC_MAC_DCHSEL_INDREG17 \
        0x0704U
/* MAC_DChSel_IndReg18 */
#define XGMAC_MAC_DCHSEL_INDREG18 \
        0x0704U
/* MAC_DChSel_IndReg19 */
#define XGMAC_MAC_DCHSEL_INDREG19 \
        0x0704U
/* MAC_DChSel_IndReg2 */
#define XGMAC_MAC_DCHSEL_INDREG2 \
        0x0704U
/* MAC_DChSel_IndReg20 */
#define XGMAC_MAC_DCHSEL_INDREG20 \
        0x0704U
/* MAC_DChSel_IndReg21 */
#define XGMAC_MAC_DCHSEL_INDREG21 \
        0x0704U
/* MAC_DChSel_IndReg22 */
#define XGMAC_MAC_DCHSEL_INDREG22 \
        0x0704U
/* MAC_DChSel_IndReg23 */
#define XGMAC_MAC_DCHSEL_INDREG23 \
        0x0704U
/* MAC_DChSel_IndReg24 */
#define XGMAC_MAC_DCHSEL_INDREG24 \
        0x0704U
/* MAC_DChSel_IndReg25 */
#define XGMAC_MAC_DCHSEL_INDREG25 \
        0x0704U
/* MAC_DChSel_IndReg26 */
#define XGMAC_MAC_DCHSEL_INDREG26 \
        0x0704U
/* MAC_DChSel_IndReg27 */
#define XGMAC_MAC_DCHSEL_INDREG27 \
        0x0704U
/* MAC_DChSel_IndReg28 */
#define XGMAC_MAC_DCHSEL_INDREG28 \
        0x0704U
/* MAC_DChSel_IndReg29 */
#define XGMAC_MAC_DCHSEL_INDREG29 \
        0x0704U
/* MAC_DChSel_IndReg3 */
#define XGMAC_MAC_DCHSEL_INDREG3 \
        0x0704U
/* MAC_DChSel_IndReg30 */
#define XGMAC_MAC_DCHSEL_INDREG30 \
        0x0704U
/* MAC_DChSel_IndReg31 */
#define XGMAC_MAC_DCHSEL_INDREG31 \
        0x0704U
/* MAC_DChSel_IndReg4 */
#define XGMAC_MAC_DCHSEL_INDREG4 \
        0x0704U
/* MAC_DChSel_IndReg5 */
#define XGMAC_MAC_DCHSEL_INDREG5 \
        0x0704U
/* MAC_DChSel_IndReg6 */
#define XGMAC_MAC_DCHSEL_INDREG6 \
        0x0704U
/* MAC_DChSel_IndReg7 */
#define XGMAC_MAC_DCHSEL_INDREG7 \
        0x0704U
/* MAC_DChSel_IndReg8 */
#define XGMAC_MAC_DCHSEL_INDREG8 \
        0x0704U
/* MAC_DChSel_IndReg9 */
#define XGMAC_MAC_DCHSEL_INDREG9 \
        0x0704U
/* MMC_Control */
#define XGMAC_MMC_CONTROL \
        0x0800U
/* MMC_Rx_Interrupt */
#define XGMAC_MMC_RX_INTERRUPT \
        0x0804U
/* MMC_Tx_Interrupt */
#define XGMAC_MMC_TX_INTERRUPT \
        0x0808U
/* MMC_Receive_Interrupt_Enable */
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE \
        0x080CU
/* MMC_Transmit_Interrupt_Enable */
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE \
        0x0810U
/* Tx_Octet_Count_Good_Bad_Low */
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_LOW \
        0x0814U
/* Tx_Octet_Count_Good_Bad_High */
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_HIGH \
        0x0818U
/* Tx_Packet_Count_Good_Bad_Low */
#define XGMAC_TX_PACKET_COUNT_GOOD_BAD_LOW \
        0x081CU
/* Tx_Broadcast_Packets_Good_Low */
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_LOW \
        0x0824U
/* Tx_Multicast_Packets_Good_Low */
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_LOW \
        0x082CU
/* Tx_64Octets_Packets_Good_Bad_Low */
#define XGMAC_TX_64OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0834U
/* Tx_65To127Octets_Packets_Good_Bad_Low */
#define XGMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW \
        0x083CU
/* Tx_128To255Octets_Packets_Good_Bad_Low */
#define XGMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0844U
/* Tx_256To511Octets_Packets_Good_Bad_Low */
#define XGMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW \
        0x084CU
/* Tx_512To1023Octets_Packets_Good_Bad_Low */
#define XGMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0854U
/* Tx_1024ToMaxOctets_Packets_Good_Bad_Low */
#define XGMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW \
        0x085CU
/* Tx_Unicast_Packets_Good_Bad_Low */
#define XGMAC_TX_UNICAST_PACKETS_GOOD_BAD_LOW \
        0x0864U
/* Tx_Multicast_Packets_Good_Bad_Low */
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_BAD_LOW \
        0x086CU
/* Tx_Broadcast_Packets_Good_Bad_Low */
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_BAD_LOW \
        0x0874U
/* Tx_Underflow_Error_Packets_Low */
#define XGMAC_TX_UNDERFLOW_ERROR_PACKETS_LOW \
        0x087CU
/* Tx_Octet_Count_Good_Low */
#define XGMAC_TX_OCTET_COUNT_GOOD_LOW \
        0x0884U
/* Tx_Octet_Count_Good_High */
#define XGMAC_TX_OCTET_COUNT_GOOD_HIGH \
        0x0888U
/* Tx_Packet_Count_Good_Low */
#define XGMAC_TX_PACKET_COUNT_GOOD_LOW \
        0x088CU
/* Tx_Pause_Packets_Low */
#define XGMAC_TX_PAUSE_PACKETS_LOW \
        0x0894U
/* Tx_VLAN_Packets_Good_Low */
#define XGMAC_TX_VLAN_PACKETS_GOOD_LOW \
        0x089CU
/* Rx_Packet_Count_Good_Bad_Low */
#define XGMAC_RX_PACKET_COUNT_GOOD_BAD_LOW \
        0x0900U
/* Rx_Octet_Count_Good_Bad_Low */
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_LOW \
        0x0908U
/* Rx_Octet_Count_Good_Bad_High */
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_HIGH \
        0x090CU
/* Rx_Octet_Count_Good_Low */
#define XGMAC_RX_OCTET_COUNT_GOOD_LOW \
        0x0910U
/* Rx_Octet_Count_Good_High */
#define XGMAC_RX_OCTET_COUNT_GOOD_HIGH \
        0x0914U
/* Rx_Broadcast_Packets_Good_Low */
#define XGMAC_RX_BROADCAST_PACKETS_GOOD_LOW \
        0x0918U
/* Rx_Multicast_Packets_Good_Low */
#define XGMAC_RX_MULTICAST_PACKETS_GOOD_LOW \
        0x0920U
/* Rx_CRC_Error_Packets_Low */
#define XGMAC_RX_CRC_ERROR_PACKETS_LOW \
        0x0928U
/* Rx_Runt_Error_Packets */
#define XGMAC_RX_RUNT_ERROR_PACKETS \
        0x0930U
/* Rx_Jabber_Error_Packets */
#define XGMAC_RX_JABBER_ERROR_PACKETS \
        0x0934U
/* Rx_Undersize_Packets_Good */
#define XGMAC_RX_UNDERSIZE_PACKETS_GOOD \
        0x0938U
/* Rx_Oversize_Packets_Good */
#define XGMAC_RX_OVERSIZE_PACKETS_GOOD \
        0x093CU
/* Rx_64Octets_Packets_Good_Bad_Low */
#define XGMAC_RX_64OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0940U
/* Rx_65To127Octets_Packets_Good_Bad_Low */
#define XGMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0948U
/* Rx_128To255Octets_Packets_Good_Bad_Low */
#define XGMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0950U
/* Rx_256To511Octets_Packets_Good_Bad_Low */
#define XGMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0958U
/* Rx_512To1023Octets_Packets_Good_Bad_Low */
#define XGMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW \
        0x0960U
/* Rx_1024ToMaxOctets_Packets_Good_Bad_Low */
#define XGMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW \
        0x0968U
/* Rx_Unicast_Packets_Good_Low */
#define XGMAC_RX_UNICAST_PACKETS_GOOD_LOW \
        0x0970U
/* Rx_Length_Error_Packets_Low */
#define XGMAC_RX_LENGTH_ERROR_PACKETS_LOW \
        0x0978U
/* Rx_OutofRange_Packets_Low */
#define XGMAC_RX_OUTOFRANGE_PACKETS_LOW \
        0x0980U
/* Rx_Pause_Packets_Low */
#define XGMAC_RX_PAUSE_PACKETS_LOW \
        0x0988U
/* Rx_FIFOOverflow_Packets_Low */
#define XGMAC_RX_FIFOOVERFLOW_PACKETS_LOW \
        0x0990U
/* Rx_VLAN_Packets_Good_Bad_Low */
#define XGMAC_RX_VLAN_PACKETS_GOOD_BAD_LOW \
        0x0998U
/* Rx_Watchdog_Error_Packets */
#define XGMAC_RX_WATCHDOG_ERROR_PACKETS \
        0x09A0U
/* Rx_Discard_Packets_Good_Bad_Low */
#define XGMAC_RX_DISCARD_PACKETS_GOOD_BAD_LOW \
        0x09ACU
/* Rx_Discard_Octets_Good_Bad_Low */
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_LOW \
        0x09B4U
/* Rx_Discard_Octets_Good_Bad_High */
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_HIGH \
        0x09B8U
/* Rx_Alignment_Error_Packets */
#define XGMAC_RX_ALIGNMENT_ERROR_PACKETS \
        0x09BCU
/* MMC_FPE_Tx_Interrupt */
#define XGMAC_MMC_FPE_TX_INTERRUPT \
        0x0A00U
/* MMC_FPE_Tx_Interrupt_Mask */
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK \
        0x0A04U
/* MMC_Tx_FPE_Fragment_Cntr */
#define XGMAC_MMC_TX_FPE_FRAGMENT_CNTR \
        0x0A08U
/* MMC_Tx_Hold_Req_Cntr */
#define XGMAC_MMC_TX_HOLD_REQ_CNTR \
        0x0A0CU
/* MMC_Tx_Gate_Orun_Cntr_Low */
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_LOW \
        0x0A10U
/* MMC_Tx_Gate_Orun_Cntr_High */
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_HIGH \
        0x0A14U
/* MMC_FPE_Rx_Interrupt */
#define XGMAC_MMC_FPE_RX_INTERRUPT \
        0x0A20U
/* MMC_FPE_Rx_Interrupt_Mask */
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK \
        0x0A24U
/* MMC_Rx_Packet_Assembly_Err_Cntr */
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR \
        0x0A28U
/* MMC_Rx_Packet_SMD_Err_Cntr */
#define XGMAC_MMC_RX_PACKET_SMD_ERR_CNTR \
        0x0A2CU
/* MMC_Rx_Packet_Assembly_OK_Cntr */
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR \
        0x0A30U
/* MMC_Rx_FPE_Fragment_Cntr */
#define XGMAC_MMC_RX_FPE_FRAGMENT_CNTR \
        0x0A34U
/* Tx_Single_Collision_Good_Packets */
#define XGMAC_TX_SINGLE_COLLISION_GOOD_PACKETS \
        0x0A40U
/* Tx_Multiple_Collision_Good_Packets */
#define XGMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS \
        0x0A44U
/* Tx_Deferred_Packets */
#define XGMAC_TX_DEFERRED_PACKETS \
        0x0A48U
/* Tx_Late_Collision_Packets */
#define XGMAC_TX_LATE_COLLISION_PACKETS \
        0x0A4CU
/* Tx_Excessive_Collision_Packets */
#define XGMAC_TX_EXCESSIVE_COLLISION_PACKETS \
        0x0A50U
/* Tx_Carrier_Error_Packets */
#define XGMAC_TX_CARRIER_ERROR_PACKETS \
        0x0A54U
/* Tx_Excessive_Deferral_Error */
#define XGMAC_TX_EXCESSIVE_DEFERRAL_ERROR \
        0x0A58U
/* MMC_IPC_Rx_Interrupt_Mask */
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK \
        0x0A5CU
/* MMC_IPC_Rx_Interrupt */
#define XGMAC_MMC_IPC_RX_INTERRUPT \
        0x0A60U
/* RxIPv4_Good_Packets_Low */
#define XGMAC_RXIPV4_GOOD_PACKETS_LOW \
        0x0A64U
/* RxIPv4_Header_Error_Packets_Low */
#define XGMAC_RXIPV4_HEADER_ERROR_PACKETS_LOW \
        0x0A6CU
/* RxIPv4_No_Payload_Packets_Low */
#define XGMAC_RXIPV4_NO_PAYLOAD_PACKETS_LOW \
        0x0A74U
/* RxIPv4_Fragmented_Packets_Low */
#define XGMAC_RXIPV4_FRAGMENTED_PACKETS_LOW \
        0x0A7CU
/* RxIPv4_UDP_Checksum_Disabled_Packets_Low */
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_LOW \
        0x0A84U
/* RxIPv6_Good_Packets_Low */
#define XGMAC_RXIPV6_GOOD_PACKETS_LOW \
        0x0A8CU
/* RxIPv6_Header_Error_Packets_Low */
#define XGMAC_RXIPV6_HEADER_ERROR_PACKETS_LOW \
        0x0A94U
/* RxIPv6_No_Payload_Packets_Low */
#define XGMAC_RXIPV6_NO_PAYLOAD_PACKETS_LOW \
        0x0A9CU
/* RxUDP_Good_Packets_Low */
#define XGMAC_RXUDP_GOOD_PACKETS_LOW \
        0x0AA4U
/* RxUDP_Error_Packets_Low */
#define XGMAC_RXUDP_ERROR_PACKETS_LOW \
        0x0AACU
/* RxTCP_Good_Packets_Low */
#define XGMAC_RXTCP_GOOD_PACKETS_LOW \
        0x0AB4U
/* RxTCP_Error_Packets_Low */
#define XGMAC_RXTCP_ERROR_PACKETS_LOW \
        0x0ABCU
/* RxICMP_Good_Packets_Low */
#define XGMAC_RXICMP_GOOD_PACKETS_LOW \
        0x0AC4U
/* RxICMP_Error_Packets_Low */
#define XGMAC_RXICMP_ERROR_PACKETS_LOW \
        0x0ACCU
/* RxIPv4_Good_Octets_Low */
#define XGMAC_RXIPV4_GOOD_OCTETS_LOW \
        0x0AD4U
/* RxIPv4_Header_Error_Octets_Low */
#define XGMAC_RXIPV4_HEADER_ERROR_OCTETS_LOW \
        0x0ADCU
/* RxIPv4_No_Payload_Octets_Low */
#define XGMAC_RXIPV4_NO_PAYLOAD_OCTETS_LOW \
        0x0AE4U
/* RxIPv4_Fragmented_Octets_Low */
#define XGMAC_RXIPV4_FRAGMENTED_OCTETS_LOW \
        0x0AECU
/* RxIPv4_UDP_Checksum_Disable_Octets_Low */
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_LOW \
        0x0AF4U
/* RxIPv6_Good_Octets_Low */
#define XGMAC_RXIPV6_GOOD_OCTETS_LOW \
        0x0AFCU
/* RxIPv6_Header_Error_Octets_Low */
#define XGMAC_RXIPV6_HEADER_ERROR_OCTETS_LOW \
        0x0B04U
/* RxIPv6_No_Payload_Octets_Low */
#define XGMAC_RXIPV6_NO_PAYLOAD_OCTETS_LOW \
        0x0B0CU
/* RxUDP_Good_Octets_Low */
#define XGMAC_RXUDP_GOOD_OCTETS_LOW \
        0x0B14U
/* RxUDP_Error_Octets_Low */
#define XGMAC_RXUDP_ERROR_OCTETS_LOW \
        0x0B1CU
/* RxTCP_Good_Octets_Low */
#define XGMAC_RXTCP_GOOD_OCTETS_LOW \
        0x0B24U
/* RxTCP_Error_Octets_Low */
#define XGMAC_RXTCP_ERROR_OCTETS_LOW \
        0x0B2CU
/* RxICMP_Good_Octets_Low */
#define XGMAC_RXICMP_GOOD_OCTETS_LOW \
        0x0B34U
/* RxICMP_Error_Octets_Low */
#define XGMAC_RXICMP_ERROR_OCTETS_LOW \
        0x0B3CU
/* MAC_L3_L4_Address_Control */
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL \
        0x0C00U
/* MAC_L3_L4_Data */
#define XGMAC_MAC_L3_L4_DATA \
        0x0C04U
/* MAC_L3_L4_Control0 */
#define XGMAC_MAC_L3_L4_CONTROL0 \
        0x0C04U
/* MAC_L3_L4_Control1 */
#define XGMAC_MAC_L3_L4_CONTROL1 \
        0x0C04U
/* MAC_L3_L4_Control10 */
#define XGMAC_MAC_L3_L4_CONTROL10 \
        0x0C04U
/* MAC_L3_L4_Control11 */
#define XGMAC_MAC_L3_L4_CONTROL11 \
        0x0C04U
/* MAC_L3_L4_Control12 */
#define XGMAC_MAC_L3_L4_CONTROL12 \
        0x0C04U
/* MAC_L3_L4_Control13 */
#define XGMAC_MAC_L3_L4_CONTROL13 \
        0x0C04U
/* MAC_L3_L4_Control14 */
#define XGMAC_MAC_L3_L4_CONTROL14 \
        0x0C04U
/* MAC_L3_L4_Control15 */
#define XGMAC_MAC_L3_L4_CONTROL15 \
        0x0C04U
/* MAC_L3_L4_Control2 */
#define XGMAC_MAC_L3_L4_CONTROL2 \
        0x0C04U
/* MAC_L3_L4_Control3 */
#define XGMAC_MAC_L3_L4_CONTROL3 \
        0x0C04U
/* MAC_L3_L4_Control4 */
#define XGMAC_MAC_L3_L4_CONTROL4 \
        0x0C04U
/* MAC_L3_L4_Control5 */
#define XGMAC_MAC_L3_L4_CONTROL5 \
        0x0C04U
/* MAC_L3_L4_Control6 */
#define XGMAC_MAC_L3_L4_CONTROL6 \
        0x0C04U
/* MAC_L3_L4_Control7 */
#define XGMAC_MAC_L3_L4_CONTROL7 \
        0x0C04U
/* MAC_L3_L4_Control8 */
#define XGMAC_MAC_L3_L4_CONTROL8 \
        0x0C04U
/* MAC_L3_L4_Control9 */
#define XGMAC_MAC_L3_L4_CONTROL9 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg0 */
#define XGMAC_MAC_LAYER3_ADDR0_REG0 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg1 */
#define XGMAC_MAC_LAYER3_ADDR0_REG1 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg10 */
#define XGMAC_MAC_LAYER3_ADDR0_REG10 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg11 */
#define XGMAC_MAC_LAYER3_ADDR0_REG11 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg12 */
#define XGMAC_MAC_LAYER3_ADDR0_REG12 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg13 */
#define XGMAC_MAC_LAYER3_ADDR0_REG13 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg14 */
#define XGMAC_MAC_LAYER3_ADDR0_REG14 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg15 */
#define XGMAC_MAC_LAYER3_ADDR0_REG15 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg2 */
#define XGMAC_MAC_LAYER3_ADDR0_REG2 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg3 */
#define XGMAC_MAC_LAYER3_ADDR0_REG3 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg4 */
#define XGMAC_MAC_LAYER3_ADDR0_REG4 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg5 */
#define XGMAC_MAC_LAYER3_ADDR0_REG5 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg6 */
#define XGMAC_MAC_LAYER3_ADDR0_REG6 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg7 */
#define XGMAC_MAC_LAYER3_ADDR0_REG7 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg8 */
#define XGMAC_MAC_LAYER3_ADDR0_REG8 \
        0x0C04U
/* MAC_Layer3_Addr0_Reg9 */
#define XGMAC_MAC_LAYER3_ADDR0_REG9 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg0 */
#define XGMAC_MAC_LAYER3_ADDR1_REG0 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg1 */
#define XGMAC_MAC_LAYER3_ADDR1_REG1 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg10 */
#define XGMAC_MAC_LAYER3_ADDR1_REG10 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg11 */
#define XGMAC_MAC_LAYER3_ADDR1_REG11 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg12 */
#define XGMAC_MAC_LAYER3_ADDR1_REG12 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg13 */
#define XGMAC_MAC_LAYER3_ADDR1_REG13 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg14 */
#define XGMAC_MAC_LAYER3_ADDR1_REG14 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg15 */
#define XGMAC_MAC_LAYER3_ADDR1_REG15 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg2 */
#define XGMAC_MAC_LAYER3_ADDR1_REG2 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg3 */
#define XGMAC_MAC_LAYER3_ADDR1_REG3 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg4 */
#define XGMAC_MAC_LAYER3_ADDR1_REG4 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg5 */
#define XGMAC_MAC_LAYER3_ADDR1_REG5 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg6 */
#define XGMAC_MAC_LAYER3_ADDR1_REG6 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg7 */
#define XGMAC_MAC_LAYER3_ADDR1_REG7 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg8 */
#define XGMAC_MAC_LAYER3_ADDR1_REG8 \
        0x0C04U
/* MAC_Layer3_Addr1_Reg9 */
#define XGMAC_MAC_LAYER3_ADDR1_REG9 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg0 */
#define XGMAC_MAC_LAYER3_ADDR2_REG0 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg1 */
#define XGMAC_MAC_LAYER3_ADDR2_REG1 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg10 */
#define XGMAC_MAC_LAYER3_ADDR2_REG10 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg11 */
#define XGMAC_MAC_LAYER3_ADDR2_REG11 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg12 */
#define XGMAC_MAC_LAYER3_ADDR2_REG12 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg13 */
#define XGMAC_MAC_LAYER3_ADDR2_REG13 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg14 */
#define XGMAC_MAC_LAYER3_ADDR2_REG14 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg15 */
#define XGMAC_MAC_LAYER3_ADDR2_REG15 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg2 */
#define XGMAC_MAC_LAYER3_ADDR2_REG2 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg3 */
#define XGMAC_MAC_LAYER3_ADDR2_REG3 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg4 */
#define XGMAC_MAC_LAYER3_ADDR2_REG4 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg5 */
#define XGMAC_MAC_LAYER3_ADDR2_REG5 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg6 */
#define XGMAC_MAC_LAYER3_ADDR2_REG6 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg7 */
#define XGMAC_MAC_LAYER3_ADDR2_REG7 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg8 */
#define XGMAC_MAC_LAYER3_ADDR2_REG8 \
        0x0C04U
/* MAC_Layer3_Addr2_Reg9 */
#define XGMAC_MAC_LAYER3_ADDR2_REG9 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg0 */
#define XGMAC_MAC_LAYER3_ADDR3_REG0 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg1 */
#define XGMAC_MAC_LAYER3_ADDR3_REG1 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg10 */
#define XGMAC_MAC_LAYER3_ADDR3_REG10 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg11 */
#define XGMAC_MAC_LAYER3_ADDR3_REG11 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg12 */
#define XGMAC_MAC_LAYER3_ADDR3_REG12 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg13 */
#define XGMAC_MAC_LAYER3_ADDR3_REG13 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg14 */
#define XGMAC_MAC_LAYER3_ADDR3_REG14 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg15 */
#define XGMAC_MAC_LAYER3_ADDR3_REG15 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg2 */
#define XGMAC_MAC_LAYER3_ADDR3_REG2 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg3 */
#define XGMAC_MAC_LAYER3_ADDR3_REG3 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg4 */
#define XGMAC_MAC_LAYER3_ADDR3_REG4 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg5 */
#define XGMAC_MAC_LAYER3_ADDR3_REG5 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg6 */
#define XGMAC_MAC_LAYER3_ADDR3_REG6 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg7 */
#define XGMAC_MAC_LAYER3_ADDR3_REG7 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg8 */
#define XGMAC_MAC_LAYER3_ADDR3_REG8 \
        0x0C04U
/* MAC_Layer3_Addr3_Reg9 */
#define XGMAC_MAC_LAYER3_ADDR3_REG9 \
        0x0C04U
/* MAC_Layer4_Address0 */
#define XGMAC_MAC_LAYER4_ADDRESS0 \
        0x0C04U
/* MAC_Layer4_Address1 */
#define XGMAC_MAC_LAYER4_ADDRESS1 \
        0x0C04U
/* MAC_Layer4_Address10 */
#define XGMAC_MAC_LAYER4_ADDRESS10 \
        0x0C04U
/* MAC_Layer4_Address11 */
#define XGMAC_MAC_LAYER4_ADDRESS11 \
        0x0C04U
/* MAC_Layer4_Address12 */
#define XGMAC_MAC_LAYER4_ADDRESS12 \
        0x0C04U
/* MAC_Layer4_Address13 */
#define XGMAC_MAC_LAYER4_ADDRESS13 \
        0x0C04U
/* MAC_Layer4_Address14 */
#define XGMAC_MAC_LAYER4_ADDRESS14 \
        0x0C04U
/* MAC_Layer4_Address15 */
#define XGMAC_MAC_LAYER4_ADDRESS15 \
        0x0C04U
/* MAC_Layer4_Address2 */
#define XGMAC_MAC_LAYER4_ADDRESS2 \
        0x0C04U
/* MAC_Layer4_Address3 */
#define XGMAC_MAC_LAYER4_ADDRESS3 \
        0x0C04U
/* MAC_Layer4_Address4 */
#define XGMAC_MAC_LAYER4_ADDRESS4 \
        0x0C04U
/* MAC_Layer4_Address5 */
#define XGMAC_MAC_LAYER4_ADDRESS5 \
        0x0C04U
/* MAC_Layer4_Address6 */
#define XGMAC_MAC_LAYER4_ADDRESS6 \
        0x0C04U
/* MAC_Layer4_Address7 */
#define XGMAC_MAC_LAYER4_ADDRESS7 \
        0x0C04U
/* MAC_Layer4_Address8 */
#define XGMAC_MAC_LAYER4_ADDRESS8 \
        0x0C04U
/* MAC_Layer4_Address9 */
#define XGMAC_MAC_LAYER4_ADDRESS9 \
        0x0C04U
/* MAC_ARP_Address */
#define XGMAC_MAC_ARP_ADDRESS \
        0x0C10U
/* MAC_Timestamp_Control */
#define XGMAC_MAC_TIMESTAMP_CONTROL \
        0x0D00U
/* MAC_Sub_Second_Increment */
#define XGMAC_MAC_SUB_SECOND_INCREMENT \
        0x0D04U
/* MAC_System_Time_Seconds */
#define XGMAC_MAC_SYSTEM_TIME_SECONDS \
        0x0D08U
/* MAC_System_Time_Nanoseconds */
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS \
        0x0D0CU
/* MAC_System_Time_Seconds_Update */
#define XGMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE \
        0x0D10U
/* MAC_System_Time_Nanoseconds_Update */
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE \
        0x0D14U
/* MAC_Timestamp_Addend */
#define XGMAC_MAC_TIMESTAMP_ADDEND \
        0x0D18U
/* MAC_System_Time_Higher_Word_Seconds */
#define XGMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS \
        0x0D1CU
/* MAC_Timestamp_Status */
#define XGMAC_MAC_TIMESTAMP_STATUS \
        0x0D20U
/* MAC_Tx_Timestamp_Status_Nanoseconds */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS \
        0x0D30U
/* MAC_Tx_Timestamp_Status_Seconds */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS \
        0x0D34U
/* MAC_Tx_Timestamp_Status_PktID */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_PKTID \
        0x0D38U
/* MAC_Auxiliary_Control */
#define XGMAC_MAC_AUXILIARY_CONTROL \
        0x0D40U
/* MAC_Auxiliary_Timestamp_Nanoseconds */
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_NANOSECONDS \
        0x0D48U
/* MAC_Auxiliary_Timestamp_Seconds */
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_SECONDS \
        0x0D4CU
/* MAC_Timestamp_Ingress_Asym_Corr */
#define XGMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR \
        0x0D50U
/* MAC_Timestamp_Egress_Asym_Corr */
#define XGMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR \
        0x0D54U
/* MAC_Timestamp_Ingress_Corr_Nanosecond */
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND \
        0x0D58U
/* MAC_Timestamp_Ingress_Corr_Subnanosecond */
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSECOND \
        0x0D5CU
/* MAC_Timestamp_Egress_Corr_Nanosecond */
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND \
        0x0D60U
/* MAC_Timestamp_Egress_Corr_Subnanosecond */
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSECOND \
        0x0D64U
/* MAC_PPS_Control */
#define XGMAC_MAC_PPS_CONTROL \
        0x0D70U
/* MAC_PPS0_Target_Time_Seconds */
#define XGMAC_MAC_PPS0_TARGET_TIME_SECONDS \
        0x0D80U
/* MAC_PPS0_Target_Time_Nanoseconds */
#define XGMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS \
        0x0D84U
/* MAC_PPS0_Interval */
#define XGMAC_MAC_PPS0_INTERVAL \
        0x0D88U
/* MAC_PPS0_Width */
#define XGMAC_MAC_PPS0_WIDTH \
        0x0D8CU
/* MAC_PPS1_Target_Time_Seconds */
#define XGMAC_MAC_PPS1_TARGET_TIME_SECONDS \
        0x0D90U
/* MAC_PPS1_Target_Time_Nanoseconds */
#define XGMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS \
        0x0D94U
/* MAC_PPS1_Interval */
#define XGMAC_MAC_PPS1_INTERVAL \
        0x0D98U
/* MAC_PPS1_Width */
#define XGMAC_MAC_PPS1_WIDTH \
        0x0D9CU
/* MAC_PTO_Control */
#define XGMAC_MAC_PTO_CONTROL \
        0x0DC0U
/* MAC_Source_Port_Identity0 */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY0 \
        0x0DC4U
/* MAC_Source_Port_Identity1 */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY1 \
        0x0DC8U
/* MAC_Source_Port_Identity2 */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY2 \
        0x0DCCU
/* MAC_Log_Message_Interval */
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL \
        0x0DD0U
/* MTL_Operation_Mode */
#define XGMAC_MTL_OPERATION_MODE \
        0x1000U
/* MTL_Debug_Control */
#define XGMAC_MTL_DEBUG_CONTROL \
        0x1008U
/* MTL_Debug_Status */
#define XGMAC_MTL_DEBUG_STATUS \
        0x100CU
/* MTL_FIFO_Debug_Data */
#define XGMAC_MTL_FIFO_DEBUG_DATA \
        0x1010U
/* MTL_Interrupt_Status */
#define XGMAC_MTL_INTERRUPT_STATUS \
        0x1020U
/* MTL_RxQ_DMA_Map0 */
#define XGMAC_MTL_RXQ_DMA_MAP0 \
        0x1030U
/* MTL_RxQ_DMA_Map1 */
#define XGMAC_MTL_RXQ_DMA_MAP1 \
        0x1034U
/* MTL_TC_Prty_Map0 */
#define XGMAC_MTL_TC_PRTY_MAP0 \
        0x1040U
/* MTL_TC_Prty_Map1 */
#define XGMAC_MTL_TC_PRTY_MAP1 \
        0x1044U
/* MTL_TBS_CTRL */
#define XGMAC_MTL_TBS_CTRL \
        0x1048U
/* MTL_TBS_STATS */
#define XGMAC_MTL_TBS_STATS \
        0x104CU
/* MTL_EST_Control */
#define XGMAC_MTL_EST_CONTROL \
        0x1050U
/* MTL_EST_Overhead */
#define XGMAC_MTL_EST_OVERHEAD \
        0x1054U
/* MTL_EST_Status */
#define XGMAC_MTL_EST_STATUS \
        0x1058U
/* MTL_EST_Sch_Error */
#define XGMAC_MTL_EST_SCH_ERROR \
        0x1060U
/* MTL_EST_Frm_Size_Error */
#define XGMAC_MTL_EST_FRM_SIZE_ERROR \
        0x1064U
/* MTL_EST_Frm_Size_Capture */
#define XGMAC_MTL_EST_FRM_SIZE_CAPTURE \
        0x1068U
/* MTL_EST_Intr_Enable */
#define XGMAC_MTL_EST_INTR_ENABLE \
        0x1070U
/* MTL_GCL_Control */
#define XGMAC_MTL_GCL_CONTROL \
        0x1080U
/* MTL_GCL_Data */
#define XGMAC_MTL_GCL_DATA \
        0x1084U
/* MTL_FPE_CTRL_STS */
#define XGMAC_MTL_FPE_CTRL_STS \
        0x1090U
/* MTL_FPE_Advance */
#define XGMAC_MTL_FPE_ADVANCE \
        0x1094U
/* MTL_TxQ0_Operation_Mode */
#define XGMAC_MTL_TXQ0_OPERATION_MODE \
        0x1100U
/* MTL_TxQ0_Underflow */
#define XGMAC_MTL_TXQ0_UNDERFLOW \
        0x1104U
/* MTL_TxQ0_Debug */
#define XGMAC_MTL_TXQ0_DEBUG \
        0x1108U
/* MTL_TC0_ETS_Control */
#define XGMAC_MTL_TC0_ETS_CONTROL \
        0x1110U
/* MTL_TC0_ETS_Status */
#define XGMAC_MTL_TC0_ETS_STATUS \
        0x1114U
/* MTL_TC0_Quantum_Weight */
#define XGMAC_MTL_TC0_QUANTUM_WEIGHT \
        0x1118U
/* MTL_RxQ0_Operation_Mode */
#define XGMAC_MTL_RXQ0_OPERATION_MODE \
        0x1140U
/* MTL_RxQ0_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT \
        0x1144U
/* MTL_RxQ0_Debug */
#define XGMAC_MTL_RXQ0_DEBUG \
        0x1148U
/* MTL_RxQ0_Control */
#define XGMAC_MTL_RXQ0_CONTROL \
        0x114CU
/* MTL_RxQ0_Flow_Control */
#define XGMAC_MTL_RXQ0_FLOW_CONTROL \
        0x1150U
/* MTL_Q0_Interrupt_Enable */
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE \
        0x1170U
/* MTL_Q0_Interrupt_Status */
#define XGMAC_MTL_Q0_INTERRUPT_STATUS \
        0x1174U
/* MTL_TxQ1_Operation_Mode */
#define XGMAC_MTL_TXQ1_OPERATION_MODE \
        0x1180U
/* MTL_TxQ1_Underflow */
#define XGMAC_MTL_TXQ1_UNDERFLOW \
        0x1184U
/* MTL_TxQ1_Debug */
#define XGMAC_MTL_TXQ1_DEBUG \
        0x1188U
/* MTL_TC1_ETS_Control */
#define XGMAC_MTL_TC1_ETS_CONTROL \
        0x1190U
/* MTL_TC1_ETS_Status */
#define XGMAC_MTL_TC1_ETS_STATUS \
        0x1194U
/* MTL_TC1_Quantum_Weight */
#define XGMAC_MTL_TC1_QUANTUM_WEIGHT \
        0x1198U
/* MTL_RxQ1_Operation_Mode */
#define XGMAC_MTL_RXQ1_OPERATION_MODE \
        0x11C0U
/* MTL_RxQ1_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT \
        0x11C4U
/* MTL_RxQ1_Debug */
#define XGMAC_MTL_RXQ1_DEBUG \
        0x11C8U
/* MTL_RxQ1_Control */
#define XGMAC_MTL_RXQ1_CONTROL \
        0x11CCU
/* MTL_RxQ1_Flow_Control */
#define XGMAC_MTL_RXQ1_FLOW_CONTROL \
        0x11D0U
/* MTL_Q1_Interrupt_Enable */
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE \
        0x11F0U
/* MTL_Q1_Interrupt_Status */
#define XGMAC_MTL_Q1_INTERRUPT_STATUS \
        0x11F4U
/* MTL_TxQ2_Operation_Mode */
#define XGMAC_MTL_TXQ2_OPERATION_MODE \
        0x1200U
/* MTL_TxQ2_Underflow */
#define XGMAC_MTL_TXQ2_UNDERFLOW \
        0x1204U
/* MTL_TxQ2_Debug */
#define XGMAC_MTL_TXQ2_DEBUG \
        0x1208U
/* MTL_TC2_ETS_Control */
#define XGMAC_MTL_TC2_ETS_CONTROL \
        0x1210U
/* MTL_TC2_ETS_Status */
#define XGMAC_MTL_TC2_ETS_STATUS \
        0x1214U
/* MTL_TC2_Quantum_Weight */
#define XGMAC_MTL_TC2_QUANTUM_WEIGHT \
        0x1218U
/* MTL_RxQ2_Operation_Mode */
#define XGMAC_MTL_RXQ2_OPERATION_MODE \
        0x1240U
/* MTL_RxQ2_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT \
        0x1244U
/* MTL_RxQ2_Debug */
#define XGMAC_MTL_RXQ2_DEBUG \
        0x1248U
/* MTL_RxQ2_Control */
#define XGMAC_MTL_RXQ2_CONTROL \
        0x124CU
/* MTL_RxQ2_Flow_Control */
#define XGMAC_MTL_RXQ2_FLOW_CONTROL \
        0x1250U
/* MTL_Q2_Interrupt_Enable */
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE \
        0x1270U
/* MTL_Q2_Interrupt_Status */
#define XGMAC_MTL_Q2_INTERRUPT_STATUS \
        0x1274U
/* MTL_TxQ3_Operation_Mode */
#define XGMAC_MTL_TXQ3_OPERATION_MODE \
        0x1280U
/* MTL_TxQ3_Underflow */
#define XGMAC_MTL_TXQ3_UNDERFLOW \
        0x1284U
/* MTL_TxQ3_Debug */
#define XGMAC_MTL_TXQ3_DEBUG \
        0x1288U
/* MTL_TC3_ETS_Control */
#define XGMAC_MTL_TC3_ETS_CONTROL \
        0x1290U
/* MTL_TC3_ETS_Status */
#define XGMAC_MTL_TC3_ETS_STATUS \
        0x1294U
/* MTL_TC3_Quantum_Weight */
#define XGMAC_MTL_TC3_QUANTUM_WEIGHT \
        0x1298U
/* MTL_RxQ3_Operation_Mode */
#define XGMAC_MTL_RXQ3_OPERATION_MODE \
        0x12C0U
/* MTL_RxQ3_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT \
        0x12C4U
/* MTL_RxQ3_Debug */
#define XGMAC_MTL_RXQ3_DEBUG \
        0x12C8U
/* MTL_RxQ3_Control */
#define XGMAC_MTL_RXQ3_CONTROL \
        0x12CCU
/* MTL_RxQ3_Flow_Control */
#define XGMAC_MTL_RXQ3_FLOW_CONTROL \
        0x12D0U
/* MTL_Q3_Interrupt_Enable */
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE \
        0x12F0U
/* MTL_Q3_Interrupt_Status */
#define XGMAC_MTL_Q3_INTERRUPT_STATUS \
        0x12F4U
/* MTL_TxQ4_Operation_Mode */
#define XGMAC_MTL_TXQ4_OPERATION_MODE \
        0x1300U
/* MTL_TxQ4_Underflow */
#define XGMAC_MTL_TXQ4_UNDERFLOW \
        0x1304U
/* MTL_TxQ4_Debug */
#define XGMAC_MTL_TXQ4_DEBUG \
        0x1308U
/* MTL_TC4_ETS_Control */
#define XGMAC_MTL_TC4_ETS_CONTROL \
        0x1310U
/* MTL_TC4_ETS_Status */
#define XGMAC_MTL_TC4_ETS_STATUS \
        0x1314U
/* MTL_TC4_Quantum_Weight */
#define XGMAC_MTL_TC4_QUANTUM_WEIGHT \
        0x1318U
/* MTL_RxQ4_Operation_Mode */
#define XGMAC_MTL_RXQ4_OPERATION_MODE \
        0x1340U
/* MTL_RxQ4_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT \
        0x1344U
/* MTL_RxQ4_Debug */
#define XGMAC_MTL_RXQ4_DEBUG \
        0x1348U
/* MTL_RxQ4_Control */
#define XGMAC_MTL_RXQ4_CONTROL \
        0x134CU
/* MTL_RxQ4_Flow_Control */
#define XGMAC_MTL_RXQ4_FLOW_CONTROL \
        0x1350U
/* MTL_Q4_Interrupt_Enable */
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE \
        0x1370U
/* MTL_Q4_Interrupt_Status */
#define XGMAC_MTL_Q4_INTERRUPT_STATUS \
        0x1374U
/* MTL_TxQ5_Operation_Mode */
#define XGMAC_MTL_TXQ5_OPERATION_MODE \
        0x1380U
/* MTL_TxQ5_Underflow */
#define XGMAC_MTL_TXQ5_UNDERFLOW \
        0x1384U
/* MTL_TxQ5_Debug */
#define XGMAC_MTL_TXQ5_DEBUG \
        0x1388U
/* MTL_TC5_ETS_Control */
#define XGMAC_MTL_TC5_ETS_CONTROL \
        0x1390U
/* MTL_TC5_ETS_Status */
#define XGMAC_MTL_TC5_ETS_STATUS \
        0x1394U
/* MTL_TC5_Quantum_Weight */
#define XGMAC_MTL_TC5_QUANTUM_WEIGHT \
        0x1398U
/* MTL_RxQ5_Operation_Mode */
#define XGMAC_MTL_RXQ5_OPERATION_MODE \
        0x13C0U
/* MTL_RxQ5_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT \
        0x13C4U
/* MTL_RxQ5_Debug */
#define XGMAC_MTL_RXQ5_DEBUG \
        0x13C8U
/* MTL_RxQ5_Control */
#define XGMAC_MTL_RXQ5_CONTROL \
        0x13CCU
/* MTL_RxQ5_Flow_Control */
#define XGMAC_MTL_RXQ5_FLOW_CONTROL \
        0x13D0U
/* MTL_Q5_Interrupt_Enable */
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE \
        0x13F0U
/* MTL_Q5_Interrupt_Status */
#define XGMAC_MTL_Q5_INTERRUPT_STATUS \
        0x13F4U
/* MTL_TxQ6_Operation_Mode */
#define XGMAC_MTL_TXQ6_OPERATION_MODE \
        0x1400U
/* MTL_TxQ6_Underflow */
#define XGMAC_MTL_TXQ6_UNDERFLOW \
        0x1404U
/* MTL_TxQ6_Debug */
#define XGMAC_MTL_TXQ6_DEBUG \
        0x1408U
/* MTL_TC6_ETS_Control */
#define XGMAC_MTL_TC6_ETS_CONTROL \
        0x1410U
/* MTL_TC6_ETS_Status */
#define XGMAC_MTL_TC6_ETS_STATUS \
        0x1414U
/* MTL_TC6_Quantum_Weight */
#define XGMAC_MTL_TC6_QUANTUM_WEIGHT \
        0x1418U
/* MTL_RxQ6_Operation_Mode */
#define XGMAC_MTL_RXQ6_OPERATION_MODE \
        0x1440U
/* MTL_RxQ6_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT \
        0x1444U
/* MTL_RxQ6_Debug */
#define XGMAC_MTL_RXQ6_DEBUG \
        0x1448U
/* MTL_RxQ6_Control */
#define XGMAC_MTL_RXQ6_CONTROL \
        0x144CU
/* MTL_RxQ6_Flow_Control */
#define XGMAC_MTL_RXQ6_FLOW_CONTROL \
        0x1450U
/* MTL_Q6_Interrupt_Enable */
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE \
        0x1470U
/* MTL_Q6_Interrupt_Status */
#define XGMAC_MTL_Q6_INTERRUPT_STATUS \
        0x1474U
/* MTL_TxQ7_Operation_Mode */
#define XGMAC_MTL_TXQ7_OPERATION_MODE \
        0x1480U
/* MTL_TxQ7_Underflow */
#define XGMAC_MTL_TXQ7_UNDERFLOW \
        0x1484U
/* MTL_TxQ7_Debug */
#define XGMAC_MTL_TXQ7_DEBUG \
        0x1488U
/* MTL_TC7_ETS_Control */
#define XGMAC_MTL_TC7_ETS_CONTROL \
        0x1490U
/* MTL_TC7_ETS_Status */
#define XGMAC_MTL_TC7_ETS_STATUS \
        0x1494U
/* MTL_TC7_Quantum_Weight */
#define XGMAC_MTL_TC7_QUANTUM_WEIGHT \
        0x1498U
/* MTL_TC7_SendSlopeCredit */
#define XGMAC_MTL_TC7_SENDSLOPECREDIT \
        0x149CU
/* MTL_TC7_HiCredit */
#define XGMAC_MTL_TC7_HICREDIT \
        0x14A0U
/* MTL_TC7_LoCredit */
#define XGMAC_MTL_TC7_LOCREDIT \
        0x14A4U
/* MTL_RxQ7_Operation_Mode */
#define XGMAC_MTL_RXQ7_OPERATION_MODE \
        0x14C0U
/* MTL_RxQ7_Missed_Pkt_Overflow_Cnt */
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT \
        0x14C4U
/* MTL_RxQ7_Debug */
#define XGMAC_MTL_RXQ7_DEBUG \
        0x14C8U
/* MTL_RxQ7_Control */
#define XGMAC_MTL_RXQ7_CONTROL \
        0x14CCU
/* MTL_RxQ7_Flow_Control */
#define XGMAC_MTL_RXQ7_FLOW_CONTROL \
        0x14D0U
/* MTL_Q7_Interrupt_Enable */
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE \
        0x14F0U
/* MTL_Q7_Interrupt_Status */
#define XGMAC_MTL_Q7_INTERRUPT_STATUS \
        0x14F4U
/* DMA_Mode */
#define XGMAC_DMA_MODE \
        0x3000U
/* DMA_SysBus_Mode */
#define XGMAC_DMA_SYSBUS_MODE \
        0x3004U
/* DMA_Interrupt_Status */
#define XGMAC_DMA_INTERRUPT_STATUS \
        0x3008U
/* AXI_Tx_AR_ACE_Control */
#define XGMAC_AXI_TX_AR_ACE_CONTROL \
        0x3010U
/* AXI_Rx_AW_ACE_Control */
#define XGMAC_AXI_RX_AW_ACE_CONTROL \
        0x3018U
/* AXI_TxRx_AWAR_ACE_Control */
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL \
        0x301CU
/* DMA_Debug_Status0 */
#define XGMAC_DMA_DEBUG_STATUS0 \
        0x3020U
/* DMA_Debug_Status1 */
#define XGMAC_DMA_DEBUG_STATUS1 \
        0x3024U
/* DMA_Debug_Status3 */
#define XGMAC_DMA_DEBUG_STATUS3 \
        0x302CU
/* DMA_Tx_EDMA_Control */
#define XGMAC_DMA_TX_EDMA_CONTROL \
        0x3040U
/* DMA_Rx_EDMA_Control */
#define XGMAC_DMA_RX_EDMA_CONTROL \
        0x3044U
/* AXI_LPI_Entry_Interval */
#define XGMAC_AXI_LPI_ENTRY_INTERVAL \
        0x3050U
/* DMA_TBS_CTRL0 */
#define XGMAC_DMA_TBS_CTRL0 \
        0x3054U
/* DMA_TBS_CTRL1 */
#define XGMAC_DMA_TBS_CTRL1 \
        0x3058U
/* DMA_TBS_CTRL2 */
#define XGMAC_DMA_TBS_CTRL2 \
        0x305CU
/* DMA_TBS_CTRL3 */
#define XGMAC_DMA_TBS_CTRL3 \
        0x3060U
/* DMA_CH_Ind_Ctrl */
#define XGMAC_DMA_CH_IND_CTRL \
        0x3080U
/* DMA_CH_Ind_Data */
#define XGMAC_DMA_CH_IND_DATA \
        0x3084U
/* DMA_CH0_TxExtCfg */
#define XGMAC_DMA_CH0_TXEXTCFG \
        0x3084U
/* DMA_CH1_TxExtCfg */
#define XGMAC_DMA_CH1_TXEXTCFG \
        0x3084U
/* DMA_CH2_TxExtCfg */
#define XGMAC_DMA_CH2_TXEXTCFG \
        0x3084U
/* DMA_CH3_TxExtCfg */
#define XGMAC_DMA_CH3_TXEXTCFG \
        0x3084U
/* DMA_CH4_TxExtCfg */
#define XGMAC_DMA_CH4_TXEXTCFG \
        0x3084U
/* DMA_CH5_TxExtCfg */
#define XGMAC_DMA_CH5_TXEXTCFG \
        0x3084U
/* DMA_CH6_TxExtCfg */
#define XGMAC_DMA_CH6_TXEXTCFG \
        0x3084U
/* DMA_CH7_TxExtCfg */
#define XGMAC_DMA_CH7_TXEXTCFG \
        0x3084U
/* DMA_CH0_Control */
#define XGMAC_DMA_CH0_CONTROL \
        0x3100U
/* DMA_CH0_Tx_Control */
#define XGMAC_DMA_CH0_TX_CONTROL \
        0x3104U
/* DMA_CH0_Rx_Control */
#define XGMAC_DMA_CH0_RX_CONTROL \
        0x3108U
/* DMA_CH0_Slot_Function_Control_Status */
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS \
        0x310CU
/* DMA_CH0_TxDesc_List_HAddress */
#define XGMAC_DMA_CH0_TXDESC_LIST_HADDRESS \
        0x3110U
/* DMA_CH0_TxDesc_List_LAddress */
#define XGMAC_DMA_CH0_TXDESC_LIST_LADDRESS \
        0x3114U
/* DMA_CH0_RxDesc_List_HAddress */
#define XGMAC_DMA_CH0_RXDESC_LIST_HADDRESS \
        0x3118U
/* DMA_CH0_RxDesc_List_LAddress */
#define XGMAC_DMA_CH0_RXDESC_LIST_LADDRESS \
        0x311CU
/* DMA_CH0_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH0_TXDESC_TAIL_LPOINTER \
        0x3124U
/* DMA_CH0_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH0_RXDESC_TAIL_LPOINTER \
        0x312CU
/* DMA_CH0_Tx_Control2 */
#define XGMAC_DMA_CH0_TX_CONTROL2 \
        0x3130U
/* DMA_CH0_Rx_Control2 */
#define XGMAC_DMA_CH0_RX_CONTROL2 \
        0x3134U
/* DMA_CH0_Interrupt_Enable */
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE \
        0x3138U
/* DMA_CH0_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER \
        0x313CU
/* DMA_CH0_Current_App_TxDesc_L */
#define XGMAC_DMA_CH0_CURRENT_APP_TXDESC_L \
        0x3144U
/* DMA_CH0_Current_App_RxDesc_L */
#define XGMAC_DMA_CH0_CURRENT_APP_RXDESC_L \
        0x314CU
/* DMA_CH0_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_H \
        0x3150U
/* DMA_CH0_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_L \
        0x3154U
/* DMA_CH0_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_H \
        0x3158U
/* DMA_CH0_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_L \
        0x315CU
/* DMA_CH0_Status */
#define XGMAC_DMA_CH0_STATUS \
        0x3160U
/* DMA_CH0_Debug_Status */
#define XGMAC_DMA_CH0_DEBUG_STATUS \
        0x3164U
/* DMA_CH0_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH0_DESC_MEM_CACHE_FILL_LEVEL \
        0x3168U
/* DMA_CH0_Miss_Packet_Cnt */
#define XGMAC_DMA_CH0_MISS_PACKET_CNT \
        0x316CU
/* DMA_CH0_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH0_TX_DATA_XFER_RING_OFFSET \
        0x3170U
/* DMA_CH0_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH0_RX_DATA_XFER_RING_OFFSET \
        0x3174U
/* DMA_CH0_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH0_TX_DESC_WRITE_RING_OFFSET \
        0x3178U
/* DMA_CH0_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH0_RX_DESC_WRITE_RING_OFFSET \
        0x317CU
/* DMA_CH1_Control */
#define XGMAC_DMA_CH1_CONTROL \
        0x3180U
/* DMA_CH1_Tx_Control */
#define XGMAC_DMA_CH1_TX_CONTROL \
        0x3184U
/* DMA_CH1_Rx_Control */
#define XGMAC_DMA_CH1_RX_CONTROL \
        0x3188U
/* DMA_CH1_Slot_Function_Control_Status */
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS \
        0x318CU
/* DMA_CH1_TxDesc_List_HAddress */
#define XGMAC_DMA_CH1_TXDESC_LIST_HADDRESS \
        0x3190U
/* DMA_CH1_TxDesc_List_LAddress */
#define XGMAC_DMA_CH1_TXDESC_LIST_LADDRESS \
        0x3194U
/* DMA_CH1_RxDesc_List_HAddress */
#define XGMAC_DMA_CH1_RXDESC_LIST_HADDRESS \
        0x3198U
/* DMA_CH1_RxDesc_List_LAddress */
#define XGMAC_DMA_CH1_RXDESC_LIST_LADDRESS \
        0x319CU
/* DMA_CH1_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH1_TXDESC_TAIL_LPOINTER \
        0x31A4U
/* DMA_CH1_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH1_RXDESC_TAIL_LPOINTER \
        0x31ACU
/* DMA_CH1_Tx_Control2 */
#define XGMAC_DMA_CH1_TX_CONTROL2 \
        0x31B0U
/* DMA_CH1_Rx_Control2 */
#define XGMAC_DMA_CH1_RX_CONTROL2 \
        0x31B4U
/* DMA_CH1_Interrupt_Enable */
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE \
        0x31B8U
/* DMA_CH1_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER \
        0x31BCU
/* DMA_CH1_Current_App_TxDesc_L */
#define XGMAC_DMA_CH1_CURRENT_APP_TXDESC_L \
        0x31C4U
/* DMA_CH1_Current_App_RxDesc_L */
#define XGMAC_DMA_CH1_CURRENT_APP_RXDESC_L \
        0x31CCU
/* DMA_CH1_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_H \
        0x31D0U
/* DMA_CH1_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_L \
        0x31D4U
/* DMA_CH1_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_H \
        0x31D8U
/* DMA_CH1_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_L \
        0x31DCU
/* DMA_CH1_Status */
#define XGMAC_DMA_CH1_STATUS \
        0x31E0U
/* DMA_CH1_Debug_Status */
#define XGMAC_DMA_CH1_DEBUG_STATUS \
        0x31E4U
/* DMA_CH1_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH1_DESC_MEM_CACHE_FILL_LEVEL \
        0x31E8U
/* DMA_CH1_Miss_Packet_Cnt */
#define XGMAC_DMA_CH1_MISS_PACKET_CNT \
        0x31ECU
/* DMA_CH1_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH1_TX_DATA_XFER_RING_OFFSET \
        0x31F0U
/* DMA_CH1_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH1_RX_DATA_XFER_RING_OFFSET \
        0x31F4U
/* DMA_CH1_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH1_TX_DESC_WRITE_RING_OFFSET \
        0x31F8U
/* DMA_CH1_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH1_RX_DESC_WRITE_RING_OFFSET \
        0x31FCU
/* DMA_CH2_Control */
#define XGMAC_DMA_CH2_CONTROL \
        0x3200U
/* DMA_CH2_Tx_Control */
#define XGMAC_DMA_CH2_TX_CONTROL \
        0x3204U
/* DMA_CH2_Rx_Control */
#define XGMAC_DMA_CH2_RX_CONTROL \
        0x3208U
/* DMA_CH2_Slot_Function_Control_Status */
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS \
        0x320CU
/* DMA_CH2_TxDesc_List_HAddress */
#define XGMAC_DMA_CH2_TXDESC_LIST_HADDRESS \
        0x3210U
/* DMA_CH2_TxDesc_List_LAddress */
#define XGMAC_DMA_CH2_TXDESC_LIST_LADDRESS \
        0x3214U
/* DMA_CH2_RxDesc_List_HAddress */
#define XGMAC_DMA_CH2_RXDESC_LIST_HADDRESS \
        0x3218U
/* DMA_CH2_RxDesc_List_LAddress */
#define XGMAC_DMA_CH2_RXDESC_LIST_LADDRESS \
        0x321CU
/* DMA_CH2_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH2_TXDESC_TAIL_LPOINTER \
        0x3224U
/* DMA_CH2_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH2_RXDESC_TAIL_LPOINTER \
        0x322CU
/* DMA_CH2_Tx_Control2 */
#define XGMAC_DMA_CH2_TX_CONTROL2 \
        0x3230U
/* DMA_CH2_Rx_Control2 */
#define XGMAC_DMA_CH2_RX_CONTROL2 \
        0x3234U
/* DMA_CH2_Interrupt_Enable */
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE \
        0x3238U
/* DMA_CH2_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER \
        0x323CU
/* DMA_CH2_Current_App_TxDesc_L */
#define XGMAC_DMA_CH2_CURRENT_APP_TXDESC_L \
        0x3244U
/* DMA_CH2_Current_App_RxDesc_L */
#define XGMAC_DMA_CH2_CURRENT_APP_RXDESC_L \
        0x324CU
/* DMA_CH2_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_H \
        0x3250U
/* DMA_CH2_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_L \
        0x3254U
/* DMA_CH2_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_H \
        0x3258U
/* DMA_CH2_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_L \
        0x325CU
/* DMA_CH2_Status */
#define XGMAC_DMA_CH2_STATUS \
        0x3260U
/* DMA_CH2_Debug_Status */
#define XGMAC_DMA_CH2_DEBUG_STATUS \
        0x3264U
/* DMA_CH2_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH2_DESC_MEM_CACHE_FILL_LEVEL \
        0x3268U
/* DMA_CH2_Miss_Packet_Cnt */
#define XGMAC_DMA_CH2_MISS_PACKET_CNT \
        0x326CU
/* DMA_CH2_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH2_TX_DATA_XFER_RING_OFFSET \
        0x3270U
/* DMA_CH2_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH2_RX_DATA_XFER_RING_OFFSET \
        0x3274U
/* DMA_CH2_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH2_TX_DESC_WRITE_RING_OFFSET \
        0x3278U
/* DMA_CH2_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH2_RX_DESC_WRITE_RING_OFFSET \
        0x327CU
/* DMA_CH3_Control */
#define XGMAC_DMA_CH3_CONTROL \
        0x3280U
/* DMA_CH3_Tx_Control */
#define XGMAC_DMA_CH3_TX_CONTROL \
        0x3284U
/* DMA_CH3_Rx_Control */
#define XGMAC_DMA_CH3_RX_CONTROL \
        0x3288U
/* DMA_CH3_Slot_Function_Control_Status */
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS \
        0x328CU
/* DMA_CH3_TxDesc_List_HAddress */
#define XGMAC_DMA_CH3_TXDESC_LIST_HADDRESS \
        0x3290U
/* DMA_CH3_TxDesc_List_LAddress */
#define XGMAC_DMA_CH3_TXDESC_LIST_LADDRESS \
        0x3294U
/* DMA_CH3_RxDesc_List_HAddress */
#define XGMAC_DMA_CH3_RXDESC_LIST_HADDRESS \
        0x3298U
/* DMA_CH3_RxDesc_List_LAddress */
#define XGMAC_DMA_CH3_RXDESC_LIST_LADDRESS \
        0x329CU
/* DMA_CH3_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH3_TXDESC_TAIL_LPOINTER \
        0x32A4U
/* DMA_CH3_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH3_RXDESC_TAIL_LPOINTER \
        0x32ACU
/* DMA_CH3_Tx_Control2 */
#define XGMAC_DMA_CH3_TX_CONTROL2 \
        0x32B0U
/* DMA_CH3_Rx_Control2 */
#define XGMAC_DMA_CH3_RX_CONTROL2 \
        0x32B4U
/* DMA_CH3_Interrupt_Enable */
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE \
        0x32B8U
/* DMA_CH3_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER \
        0x32BCU
/* DMA_CH3_Current_App_TxDesc_L */
#define XGMAC_DMA_CH3_CURRENT_APP_TXDESC_L \
        0x32C4U
/* DMA_CH3_Current_App_RxDesc_L */
#define XGMAC_DMA_CH3_CURRENT_APP_RXDESC_L \
        0x32CCU
/* DMA_CH3_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_H \
        0x32D0U
/* DMA_CH3_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_L \
        0x32D4U
/* DMA_CH3_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_H \
        0x32D8U
/* DMA_CH3_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_L \
        0x32DCU
/* DMA_CH3_Status */
#define XGMAC_DMA_CH3_STATUS \
        0x32E0U
/* DMA_CH3_Debug_Status */
#define XGMAC_DMA_CH3_DEBUG_STATUS \
        0x32E4U
/* DMA_CH3_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH3_DESC_MEM_CACHE_FILL_LEVEL \
        0x32E8U
/* DMA_CH3_Miss_Packet_Cnt */
#define XGMAC_DMA_CH3_MISS_PACKET_CNT \
        0x32ECU
/* DMA_CH3_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH3_TX_DATA_XFER_RING_OFFSET \
        0x32F0U
/* DMA_CH3_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH3_RX_DATA_XFER_RING_OFFSET \
        0x32F4U
/* DMA_CH3_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH3_TX_DESC_WRITE_RING_OFFSET \
        0x32F8U
/* DMA_CH3_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH3_RX_DESC_WRITE_RING_OFFSET \
        0x32FCU
/* DMA_CH4_Control */
#define XGMAC_DMA_CH4_CONTROL \
        0x3300U
/* DMA_CH4_Tx_Control */
#define XGMAC_DMA_CH4_TX_CONTROL \
        0x3304U
/* DMA_CH4_Rx_Control */
#define XGMAC_DMA_CH4_RX_CONTROL \
        0x3308U
/* DMA_CH4_Slot_Function_Control_Status */
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS \
        0x330CU
/* DMA_CH4_TxDesc_List_HAddress */
#define XGMAC_DMA_CH4_TXDESC_LIST_HADDRESS \
        0x3310U
/* DMA_CH4_TxDesc_List_LAddress */
#define XGMAC_DMA_CH4_TXDESC_LIST_LADDRESS \
        0x3314U
/* DMA_CH4_RxDesc_List_HAddress */
#define XGMAC_DMA_CH4_RXDESC_LIST_HADDRESS \
        0x3318U
/* DMA_CH4_RxDesc_List_LAddress */
#define XGMAC_DMA_CH4_RXDESC_LIST_LADDRESS \
        0x331CU
/* DMA_CH4_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH4_TXDESC_TAIL_LPOINTER \
        0x3324U
/* DMA_CH4_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH4_RXDESC_TAIL_LPOINTER \
        0x332CU
/* DMA_CH4_Tx_Control2 */
#define XGMAC_DMA_CH4_TX_CONTROL2 \
        0x3330U
/* DMA_CH4_Rx_Control2 */
#define XGMAC_DMA_CH4_RX_CONTROL2 \
        0x3334U
/* DMA_CH4_Interrupt_Enable */
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE \
        0x3338U
/* DMA_CH4_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER \
        0x333CU
/* DMA_CH4_Current_App_TxDesc_L */
#define XGMAC_DMA_CH4_CURRENT_APP_TXDESC_L \
        0x3344U
/* DMA_CH4_Current_App_RxDesc_L */
#define XGMAC_DMA_CH4_CURRENT_APP_RXDESC_L \
        0x334CU
/* DMA_CH4_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_H \
        0x3350U
/* DMA_CH4_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_L \
        0x3354U
/* DMA_CH4_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_H \
        0x3358U
/* DMA_CH4_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_L \
        0x335CU
/* DMA_CH4_Status */
#define XGMAC_DMA_CH4_STATUS \
        0x3360U
/* DMA_CH4_Debug_Status */
#define XGMAC_DMA_CH4_DEBUG_STATUS \
        0x3364U
/* DMA_CH4_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH4_DESC_MEM_CACHE_FILL_LEVEL \
        0x3368U
/* DMA_CH4_Miss_Packet_Cnt */
#define XGMAC_DMA_CH4_MISS_PACKET_CNT \
        0x336CU
/* DMA_CH4_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH4_TX_DATA_XFER_RING_OFFSET \
        0x3370U
/* DMA_CH4_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH4_RX_DATA_XFER_RING_OFFSET \
        0x3374U
/* DMA_CH4_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH4_TX_DESC_WRITE_RING_OFFSET \
        0x3378U
/* DMA_CH4_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH4_RX_DESC_WRITE_RING_OFFSET \
        0x337CU
/* DMA_CH5_Control */
#define XGMAC_DMA_CH5_CONTROL \
        0x3380U
/* DMA_CH5_Tx_Control */
#define XGMAC_DMA_CH5_TX_CONTROL \
        0x3384U
/* DMA_CH5_Rx_Control */
#define XGMAC_DMA_CH5_RX_CONTROL \
        0x3388U
/* DMA_CH5_Slot_Function_Control_Status */
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS \
        0x338CU
/* DMA_CH5_TxDesc_List_HAddress */
#define XGMAC_DMA_CH5_TXDESC_LIST_HADDRESS \
        0x3390U
/* DMA_CH5_TxDesc_List_LAddress */
#define XGMAC_DMA_CH5_TXDESC_LIST_LADDRESS \
        0x3394U
/* DMA_CH5_RxDesc_List_HAddress */
#define XGMAC_DMA_CH5_RXDESC_LIST_HADDRESS \
        0x3398U
/* DMA_CH5_RxDesc_List_LAddress */
#define XGMAC_DMA_CH5_RXDESC_LIST_LADDRESS \
        0x339CU
/* DMA_CH5_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH5_TXDESC_TAIL_LPOINTER \
        0x33A4U
/* DMA_CH5_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH5_RXDESC_TAIL_LPOINTER \
        0x33ACU
/* DMA_CH5_Tx_Control2 */
#define XGMAC_DMA_CH5_TX_CONTROL2 \
        0x33B0U
/* DMA_CH5_Rx_Control2 */
#define XGMAC_DMA_CH5_RX_CONTROL2 \
        0x33B4U
/* DMA_CH5_Interrupt_Enable */
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE \
        0x33B8U
/* DMA_CH5_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER \
        0x33BCU
/* DMA_CH5_Current_App_TxDesc_L */
#define XGMAC_DMA_CH5_CURRENT_APP_TXDESC_L \
        0x33C4U
/* DMA_CH5_Current_App_RxDesc_L */
#define XGMAC_DMA_CH5_CURRENT_APP_RXDESC_L \
        0x33CCU
/* DMA_CH5_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_H \
        0x33D0U
/* DMA_CH5_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_L \
        0x33D4U
/* DMA_CH5_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_H \
        0x33D8U
/* DMA_CH5_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_L \
        0x33DCU
/* DMA_CH5_Status */
#define XGMAC_DMA_CH5_STATUS \
        0x33E0U
/* DMA_CH5_Debug_Status */
#define XGMAC_DMA_CH5_DEBUG_STATUS \
        0x33E4U
/* DMA_CH5_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH5_DESC_MEM_CACHE_FILL_LEVEL \
        0x33E8U
/* DMA_CH5_Miss_Packet_Cnt */
#define XGMAC_DMA_CH5_MISS_PACKET_CNT \
        0x33ECU
/* DMA_CH5_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH5_TX_DATA_XFER_RING_OFFSET \
        0x33F0U
/* DMA_CH5_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH5_RX_DATA_XFER_RING_OFFSET \
        0x33F4U
/* DMA_CH5_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH5_TX_DESC_WRITE_RING_OFFSET \
        0x33F8U
/* DMA_CH5_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH5_RX_DESC_WRITE_RING_OFFSET \
        0x33FCU
/* DMA_CH6_Control */
#define XGMAC_DMA_CH6_CONTROL \
        0x3400U
/* DMA_CH6_Tx_Control */
#define XGMAC_DMA_CH6_TX_CONTROL \
        0x3404U
/* DMA_CH6_Rx_Control */
#define XGMAC_DMA_CH6_RX_CONTROL \
        0x3408U
/* DMA_CH6_Slot_Function_Control_Status */
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS \
        0x340CU
/* DMA_CH6_TxDesc_List_HAddress */
#define XGMAC_DMA_CH6_TXDESC_LIST_HADDRESS \
        0x3410U
/* DMA_CH6_TxDesc_List_LAddress */
#define XGMAC_DMA_CH6_TXDESC_LIST_LADDRESS \
        0x3414U
/* DMA_CH6_RxDesc_List_HAddress */
#define XGMAC_DMA_CH6_RXDESC_LIST_HADDRESS \
        0x3418U
/* DMA_CH6_RxDesc_List_LAddress */
#define XGMAC_DMA_CH6_RXDESC_LIST_LADDRESS \
        0x341CU
/* DMA_CH6_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH6_TXDESC_TAIL_LPOINTER \
        0x3424U
/* DMA_CH6_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH6_RXDESC_TAIL_LPOINTER \
        0x342CU
/* DMA_CH6_Tx_Control2 */
#define XGMAC_DMA_CH6_TX_CONTROL2 \
        0x3430U
/* DMA_CH6_Rx_Control2 */
#define XGMAC_DMA_CH6_RX_CONTROL2 \
        0x3434U
/* DMA_CH6_Interrupt_Enable */
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE \
        0x3438U
/* DMA_CH6_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER \
        0x343CU
/* DMA_CH6_Current_App_TxDesc_L */
#define XGMAC_DMA_CH6_CURRENT_APP_TXDESC_L \
        0x3444U
/* DMA_CH6_Current_App_RxDesc_L */
#define XGMAC_DMA_CH6_CURRENT_APP_RXDESC_L \
        0x344CU
/* DMA_CH6_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_H \
        0x3450U
/* DMA_CH6_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_L \
        0x3454U
/* DMA_CH6_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_H \
        0x3458U
/* DMA_CH6_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_L \
        0x345CU
/* DMA_CH6_Status */
#define XGMAC_DMA_CH6_STATUS \
        0x3460U
/* DMA_CH6_Debug_Status */
#define XGMAC_DMA_CH6_DEBUG_STATUS \
        0x3464U
/* DMA_CH6_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH6_DESC_MEM_CACHE_FILL_LEVEL \
        0x3468U
/* DMA_CH6_Miss_Packet_Cnt */
#define XGMAC_DMA_CH6_MISS_PACKET_CNT \
        0x346CU
/* DMA_CH6_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH6_TX_DATA_XFER_RING_OFFSET \
        0x3470U
/* DMA_CH6_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH6_RX_DATA_XFER_RING_OFFSET \
        0x3474U
/* DMA_CH6_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH6_TX_DESC_WRITE_RING_OFFSET \
        0x3478U
/* DMA_CH6_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH6_RX_DESC_WRITE_RING_OFFSET \
        0x347CU
/* DMA_CH7_Control */
#define XGMAC_DMA_CH7_CONTROL \
        0x3480U
/* DMA_CH7_Tx_Control */
#define XGMAC_DMA_CH7_TX_CONTROL \
        0x3484U
/* DMA_CH7_Rx_Control */
#define XGMAC_DMA_CH7_RX_CONTROL \
        0x3488U
/* DMA_CH7_Slot_Function_Control_Status */
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS \
        0x348CU
/* DMA_CH7_TxDesc_List_HAddress */
#define XGMAC_DMA_CH7_TXDESC_LIST_HADDRESS \
        0x3490U
/* DMA_CH7_TxDesc_List_LAddress */
#define XGMAC_DMA_CH7_TXDESC_LIST_LADDRESS \
        0x3494U
/* DMA_CH7_RxDesc_List_HAddress */
#define XGMAC_DMA_CH7_RXDESC_LIST_HADDRESS \
        0x3498U
/* DMA_CH7_RxDesc_List_LAddress */
#define XGMAC_DMA_CH7_RXDESC_LIST_LADDRESS \
        0x349CU
/* DMA_CH7_TxDesc_Tail_LPointer */
#define XGMAC_DMA_CH7_TXDESC_TAIL_LPOINTER \
        0x34A4U
/* DMA_CH7_RxDesc_Tail_LPointer */
#define XGMAC_DMA_CH7_RXDESC_TAIL_LPOINTER \
        0x34ACU
/* DMA_CH7_Tx_Control2 */
#define XGMAC_DMA_CH7_TX_CONTROL2 \
        0x34B0U
/* DMA_CH7_Rx_Control2 */
#define XGMAC_DMA_CH7_RX_CONTROL2 \
        0x34B4U
/* DMA_CH7_Interrupt_Enable */
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE \
        0x34B8U
/* DMA_CH7_Rx_Interrupt_Watchdog_Timer */
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER \
        0x34BCU
/* DMA_CH7_Current_App_TxDesc_L */
#define XGMAC_DMA_CH7_CURRENT_APP_TXDESC_L \
        0x34C4U
/* DMA_CH7_Current_App_RxDesc_L */
#define XGMAC_DMA_CH7_CURRENT_APP_RXDESC_L \
        0x34CCU
/* DMA_CH7_Current_App_TxBuffer_H */
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_H \
        0x34D0U
/* DMA_CH7_Current_App_TxBuffer_L */
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_L \
        0x34D4U
/* DMA_CH7_Current_App_RxBuffer_H */
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_H \
        0x34D8U
/* DMA_CH7_Current_App_RxBuffer_L */
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_L \
        0x34DCU
/* DMA_CH7_Status */
#define XGMAC_DMA_CH7_STATUS \
        0x34E0U
/* DMA_CH7_Debug_Status */
#define XGMAC_DMA_CH7_DEBUG_STATUS \
        0x34E4U
/* DMA_CH7_Desc_Mem_Cache_Fill_Level */
#define XGMAC_DMA_CH7_DESC_MEM_CACHE_FILL_LEVEL \
        0x34E8U
/* DMA_CH7_Miss_Packet_Cnt */
#define XGMAC_DMA_CH7_MISS_PACKET_CNT \
        0x34ECU
/* DMA_CH7_Tx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH7_TX_DATA_XFER_RING_OFFSET \
        0x34F0U
/* DMA_CH7_Rx_Data_Xfer_Ring_Offset */
#define XGMAC_DMA_CH7_RX_DATA_XFER_RING_OFFSET \
        0x34F4U
/* DMA_CH7_Tx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH7_TX_DESC_WRITE_RING_OFFSET \
        0x34F8U
/* DMA_CH7_Rx_Desc_Write_Ring_Offset */
#define XGMAC_DMA_CH7_RX_DESC_WRITE_RING_OFFSET \
        0x34FCU

/* Bit fields of MAC_Tx_Configuration register */
#define XGMAC_MAC_TX_CONFIGURATION_SS_MASK \
        0xE0000000U
#define XGMAC_MAC_TX_CONFIGURATION_SS_POS \
        29U
#define XGMAC_MAC_TX_CONFIGURATION_SARC_MASK \
        0x00700000U
#define XGMAC_MAC_TX_CONFIGURATION_SARC_POS \
        20U
#define XGMAC_MAC_TX_CONFIGURATION_JD_MASK \
        0x00010000U
#define XGMAC_MAC_TX_CONFIGURATION_JD_POS \
        16U
#define XGMAC_MAC_TX_CONFIGURATION_LUD_MASK \
        0x00002000U
#define XGMAC_MAC_TX_CONFIGURATION_LUD_POS \
        13U
#define XGMAC_MAC_TX_CONFIGURATION_TC_MASK \
        0x00001000U
#define XGMAC_MAC_TX_CONFIGURATION_TC_POS \
        12U
#define XGMAC_MAC_TX_CONFIGURATION_IFP_MASK \
        0x00000800U
#define XGMAC_MAC_TX_CONFIGURATION_IFP_POS \
        11U
#define XGMAC_MAC_TX_CONFIGURATION_IPG_MASK \
        0x00000700U
#define XGMAC_MAC_TX_CONFIGURATION_IPG_POS \
        8U
#define XGMAC_MAC_TX_CONFIGURATION_ISR_MASK \
        0x000000F0U
#define XGMAC_MAC_TX_CONFIGURATION_ISR_POS \
        4U
#define XGMAC_MAC_TX_CONFIGURATION_ISM_MASK \
        0x00000008U
#define XGMAC_MAC_TX_CONFIGURATION_ISM_POS \
        3U
#define XGMAC_MAC_TX_CONFIGURATION_DDIC_MASK \
        0x00000002U
#define XGMAC_MAC_TX_CONFIGURATION_DDIC_POS \
        1U
#define XGMAC_MAC_TX_CONFIGURATION_TE_MASK \
        0x00000001U
#define XGMAC_MAC_TX_CONFIGURATION_TE_POS \
        0U

/* Bit fields of MAC_Rx_Configuration register */
#define XGMAC_MAC_RX_CONFIGURATION_ARPEN_MASK \
        0x80000000U
#define XGMAC_MAC_RX_CONFIGURATION_ARPEN_POS \
        31U
#define XGMAC_MAC_RX_CONFIGURATION_GPSL_MASK \
        0x3FFF0000U
#define XGMAC_MAC_RX_CONFIGURATION_GPSL_POS \
        16U
#define XGMAC_MAC_RX_CONFIGURATION_HDSMS_MASK \
        0x00007000U
#define XGMAC_MAC_RX_CONFIGURATION_HDSMS_POS \
        12U
#define XGMAC_MAC_RX_CONFIGURATION_S2KP_MASK \
        0x00000800U
#define XGMAC_MAC_RX_CONFIGURATION_S2KP_POS \
        11U
#define XGMAC_MAC_RX_CONFIGURATION_LM_MASK \
        0x00000400U
#define XGMAC_MAC_RX_CONFIGURATION_LM_POS \
        10U
#define XGMAC_MAC_RX_CONFIGURATION_IPC_MASK \
        0x00000200U
#define XGMAC_MAC_RX_CONFIGURATION_IPC_POS \
        9U
#define XGMAC_MAC_RX_CONFIGURATION_JE_MASK \
        0x00000100U
#define XGMAC_MAC_RX_CONFIGURATION_JE_POS \
        8U
#define XGMAC_MAC_RX_CONFIGURATION_WD_MASK \
        0x00000080U
#define XGMAC_MAC_RX_CONFIGURATION_WD_POS \
        7U
#define XGMAC_MAC_RX_CONFIGURATION_GPSLCE_MASK \
        0x00000040U
#define XGMAC_MAC_RX_CONFIGURATION_GPSLCE_POS \
        6U
#define XGMAC_MAC_RX_CONFIGURATION_USP_MASK \
        0x00000020U
#define XGMAC_MAC_RX_CONFIGURATION_USP_POS \
        5U
#define XGMAC_MAC_RX_CONFIGURATION_SPEN_MASK \
        0x00000010U
#define XGMAC_MAC_RX_CONFIGURATION_SPEN_POS \
        4U
#define XGMAC_MAC_RX_CONFIGURATION_DCRCC_MASK \
        0x00000008U
#define XGMAC_MAC_RX_CONFIGURATION_DCRCC_POS \
        3U
#define XGMAC_MAC_RX_CONFIGURATION_CST_MASK \
        0x00000004U
#define XGMAC_MAC_RX_CONFIGURATION_CST_POS \
        2U
#define XGMAC_MAC_RX_CONFIGURATION_ACS_MASK \
        0x00000002U
#define XGMAC_MAC_RX_CONFIGURATION_ACS_POS \
        1U
#define XGMAC_MAC_RX_CONFIGURATION_RE_MASK \
        0x00000001U
#define XGMAC_MAC_RX_CONFIGURATION_RE_POS \
        0U

/* Bit fields of MAC_Packet_Filter register */
#define XGMAC_MAC_PACKET_FILTER_RA_MASK \
        0x80000000U
#define XGMAC_MAC_PACKET_FILTER_RA_POS \
        31U
#define XGMAC_MAC_PACKET_FILTER_DNTU_MASK \
        0x00200000U
#define XGMAC_MAC_PACKET_FILTER_DNTU_POS \
        21U
#define XGMAC_MAC_PACKET_FILTER_IPFE_MASK \
        0x00100000U
#define XGMAC_MAC_PACKET_FILTER_IPFE_POS \
        20U
#define XGMAC_MAC_PACKET_FILTER_VTFE_MASK \
        0x00010000U
#define XGMAC_MAC_PACKET_FILTER_VTFE_POS \
        16U
#define XGMAC_MAC_PACKET_FILTER_DHLFRS_MASK \
        0x00001800U
#define XGMAC_MAC_PACKET_FILTER_DHLFRS_POS \
        11U
#define XGMAC_MAC_PACKET_FILTER_HPF_MASK \
        0x00000400U
#define XGMAC_MAC_PACKET_FILTER_HPF_POS \
        10U
#define XGMAC_MAC_PACKET_FILTER_SAF_MASK \
        0x00000200U
#define XGMAC_MAC_PACKET_FILTER_SAF_POS \
        9U
#define XGMAC_MAC_PACKET_FILTER_SAIF_MASK \
        0x00000100U
#define XGMAC_MAC_PACKET_FILTER_SAIF_POS \
        8U
#define XGMAC_MAC_PACKET_FILTER_PCF_MASK \
        0x000000C0U
#define XGMAC_MAC_PACKET_FILTER_PCF_POS \
        6U
#define XGMAC_MAC_PACKET_FILTER_DBF_MASK \
        0x00000020U
#define XGMAC_MAC_PACKET_FILTER_DBF_POS \
        5U
#define XGMAC_MAC_PACKET_FILTER_PM_MASK \
        0x00000010U
#define XGMAC_MAC_PACKET_FILTER_PM_POS \
        4U
#define XGMAC_MAC_PACKET_FILTER_DAIF_MASK \
        0x00000008U
#define XGMAC_MAC_PACKET_FILTER_DAIF_POS \
        3U
#define XGMAC_MAC_PACKET_FILTER_HMC_MASK \
        0x00000004U
#define XGMAC_MAC_PACKET_FILTER_HMC_POS \
        2U
#define XGMAC_MAC_PACKET_FILTER_HUC_MASK \
        0x00000002U
#define XGMAC_MAC_PACKET_FILTER_HUC_POS \
        1U
#define XGMAC_MAC_PACKET_FILTER_PR_MASK \
        0x00000001U
#define XGMAC_MAC_PACKET_FILTER_PR_POS \
        0U

/* Bit fields of MAC_WD_JB_Timeout register */
#define XGMAC_MAC_WD_JB_TIMEOUT_PJE_MASK \
        0x01000000U
#define XGMAC_MAC_WD_JB_TIMEOUT_PJE_POS \
        24U
#define XGMAC_MAC_WD_JB_TIMEOUT_JTO_MASK \
        0x000F0000U
#define XGMAC_MAC_WD_JB_TIMEOUT_JTO_POS \
        16U
#define XGMAC_MAC_WD_JB_TIMEOUT_PWE_MASK \
        0x00000100U
#define XGMAC_MAC_WD_JB_TIMEOUT_PWE_POS \
        8U
#define XGMAC_MAC_WD_JB_TIMEOUT_WTO_MASK \
        0x0000000FU
#define XGMAC_MAC_WD_JB_TIMEOUT_WTO_POS \
        0U

/* Bit fields of MAC_Hash_Table_Reg0 register */
#define XGMAC_MAC_HASH_TABLE_REG0_HT31T0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_HASH_TABLE_REG0_HT31T0_POS \
        0U

/* Bit fields of MAC_Hash_Table_Reg1 register */
#define XGMAC_MAC_HASH_TABLE_REG1_HT31T0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_HASH_TABLE_REG1_HT31T0_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Ctrl register */
#define XGMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK \
        0x80000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_POS \
        31U
#define XGMAC_MAC_VLAN_TAG_CTRL_EIVLS_MASK \
        0x30000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_EIVLS_POS \
        28U
#define XGMAC_MAC_VLAN_TAG_CTRL_ERIVLT_MASK \
        0x08000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_ERIVLT_POS \
        27U
#define XGMAC_MAC_VLAN_TAG_CTRL_EDVLP_MASK \
        0x04000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_EDVLP_POS \
        26U
#define XGMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK \
        0x02000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_VTHM_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_CTRL_EVLRXS_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_CTRL_EVLRXS_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_CTRL_EVLS_MASK \
        0x00600000U
#define XGMAC_MAC_VLAN_TAG_CTRL_EVLS_POS \
        21U
#define XGMAC_MAC_VLAN_TAG_CTRL_DOVLTC_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_CTRL_DOVLTC_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_CTRL_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_CTRL_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_CTRL_ESVL_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_CTRL_ESVL_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_CTRL_VTIM_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_CTRL_ETV_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_CTRL_ETV_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_CTRL_OFS_MASK \
        0x0000007CU
#define XGMAC_MAC_VLAN_TAG_CTRL_OFS_POS \
        2U
#define XGMAC_MAC_VLAN_TAG_CTRL_CT_MASK \
        0x00000002U
#define XGMAC_MAC_VLAN_TAG_CTRL_CT_POS \
        1U
#define XGMAC_MAC_VLAN_TAG_CTRL_OB_MASK \
        0x00000001U
#define XGMAC_MAC_VLAN_TAG_CTRL_OB_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Data register */
#define XGMAC_MAC_VLAN_TAG_DATA_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_DATA_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_DATA_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_DATA_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_DATA_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_DATA_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_DATA_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_DATA_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_DATA_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_DATA_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_DATA_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_DATA_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_DATA_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter0 register */
#define XGMAC_MAC_VLAN_TAG_FILTER0_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER0_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER0_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER0_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER0_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter1 register */
#define XGMAC_MAC_VLAN_TAG_FILTER1_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER1_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER1_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER1_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER1_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter10 register */
#define XGMAC_MAC_VLAN_TAG_FILTER10_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER10_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER10_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER10_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER10_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter11 register */
#define XGMAC_MAC_VLAN_TAG_FILTER11_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER11_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER11_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER11_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER11_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter12 register */
#define XGMAC_MAC_VLAN_TAG_FILTER12_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER12_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER12_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER12_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER12_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter13 register */
#define XGMAC_MAC_VLAN_TAG_FILTER13_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER13_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER13_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER13_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER13_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter14 register */
#define XGMAC_MAC_VLAN_TAG_FILTER14_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER14_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER14_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER14_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER14_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter15 register */
#define XGMAC_MAC_VLAN_TAG_FILTER15_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER15_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER15_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER15_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER15_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter16 register */
#define XGMAC_MAC_VLAN_TAG_FILTER16_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER16_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER16_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER16_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER16_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter17 register */
#define XGMAC_MAC_VLAN_TAG_FILTER17_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER17_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER17_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER17_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER17_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter18 register */
#define XGMAC_MAC_VLAN_TAG_FILTER18_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER18_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER18_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER18_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER18_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter19 register */
#define XGMAC_MAC_VLAN_TAG_FILTER19_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER19_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER19_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER19_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER19_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter2 register */
#define XGMAC_MAC_VLAN_TAG_FILTER2_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER2_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER2_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER2_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER2_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter20 register */
#define XGMAC_MAC_VLAN_TAG_FILTER20_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER20_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER20_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER20_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER20_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter21 register */
#define XGMAC_MAC_VLAN_TAG_FILTER21_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER21_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER21_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER21_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER21_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter22 register */
#define XGMAC_MAC_VLAN_TAG_FILTER22_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER22_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER22_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER22_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER22_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter23 register */
#define XGMAC_MAC_VLAN_TAG_FILTER23_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER23_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER23_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER23_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER23_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter24 register */
#define XGMAC_MAC_VLAN_TAG_FILTER24_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER24_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER24_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER24_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER24_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter25 register */
#define XGMAC_MAC_VLAN_TAG_FILTER25_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER25_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER25_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER25_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER25_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter26 register */
#define XGMAC_MAC_VLAN_TAG_FILTER26_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER26_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER26_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER26_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER26_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter27 register */
#define XGMAC_MAC_VLAN_TAG_FILTER27_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER27_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER27_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER27_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER27_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter28 register */
#define XGMAC_MAC_VLAN_TAG_FILTER28_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER28_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER28_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER28_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER28_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter29 register */
#define XGMAC_MAC_VLAN_TAG_FILTER29_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER29_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER29_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER29_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER29_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter3 register */
#define XGMAC_MAC_VLAN_TAG_FILTER3_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER3_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER3_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER3_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER3_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter30 register */
#define XGMAC_MAC_VLAN_TAG_FILTER30_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER30_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER30_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER30_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER30_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter31 register */
#define XGMAC_MAC_VLAN_TAG_FILTER31_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER31_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER31_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER31_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER31_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter4 register */
#define XGMAC_MAC_VLAN_TAG_FILTER4_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER4_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER4_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER4_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER4_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter5 register */
#define XGMAC_MAC_VLAN_TAG_FILTER5_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER5_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER5_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER5_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER5_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter6 register */
#define XGMAC_MAC_VLAN_TAG_FILTER6_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER6_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER6_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER6_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER6_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter7 register */
#define XGMAC_MAC_VLAN_TAG_FILTER7_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER7_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER7_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER7_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER7_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter8 register */
#define XGMAC_MAC_VLAN_TAG_FILTER8_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER8_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER8_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER8_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER8_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Tag_Filter9 register */
#define XGMAC_MAC_VLAN_TAG_FILTER9_DMACHN_MASK \
        0x0E000000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_DMACHN_POS \
        25U
#define XGMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_MASK \
        0x01000000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_POS \
        24U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_POS \
        20U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_POS \
        19U
#define XGMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_POS \
        18U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ETV_MASK \
        0x00020000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_ETV_POS \
        17U
#define XGMAC_MAC_VLAN_TAG_FILTER9_VEN_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_TAG_FILTER9_VEN_POS \
        16U
#define XGMAC_MAC_VLAN_TAG_FILTER9_VID_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_TAG_FILTER9_VID_POS \
        0U

/* Bit fields of MAC_VLAN_Hash_Table register */
#define XGMAC_MAC_VLAN_HASH_TABLE_VLHT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_HASH_TABLE_VLHT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl register */
#define XGMAC_MAC_VLAN_INCL_BUSY_MASK \
        0x80000000U
#define XGMAC_MAC_VLAN_INCL_BUSY_POS \
        31U
#define XGMAC_MAC_VLAN_INCL_RDWR_MASK \
        0x40000000U
#define XGMAC_MAC_VLAN_INCL_RDWR_POS \
        30U
#define XGMAC_MAC_VLAN_INCL_ADDR_MASK \
        0x07000000U
#define XGMAC_MAC_VLAN_INCL_ADDR_POS \
        24U
#define XGMAC_MAC_VLAN_INCL_CBTI_MASK \
        0x00200000U
#define XGMAC_MAC_VLAN_INCL_CBTI_POS \
        21U
#define XGMAC_MAC_VLAN_INCL_VLTI_MASK \
        0x00100000U
#define XGMAC_MAC_VLAN_INCL_VLTI_POS \
        20U
#define XGMAC_MAC_VLAN_INCL_CSVL_MASK \
        0x00080000U
#define XGMAC_MAC_VLAN_INCL_CSVL_POS \
        19U
#define XGMAC_MAC_VLAN_INCL_VLP_MASK \
        0x00040000U
#define XGMAC_MAC_VLAN_INCL_VLP_POS \
        18U
#define XGMAC_MAC_VLAN_INCL_VLC_MASK \
        0x00030000U
#define XGMAC_MAC_VLAN_INCL_VLC_POS \
        16U
#define XGMAC_MAC_VLAN_INCL_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl0 register */
#define XGMAC_MAC_VLAN_INCL0_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL0_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL0_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL0_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl1 register */
#define XGMAC_MAC_VLAN_INCL1_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL1_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL1_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL1_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl10 register */
#define XGMAC_MAC_VLAN_INCL10_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL10_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL10_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL10_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl11 register */
#define XGMAC_MAC_VLAN_INCL11_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL11_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL11_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL11_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl12 register */
#define XGMAC_MAC_VLAN_INCL12_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL12_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL12_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL12_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl13 register */
#define XGMAC_MAC_VLAN_INCL13_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL13_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL13_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL13_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl14 register */
#define XGMAC_MAC_VLAN_INCL14_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL14_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL14_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL14_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl15 register */
#define XGMAC_MAC_VLAN_INCL15_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL15_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL15_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL15_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl2 register */
#define XGMAC_MAC_VLAN_INCL2_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL2_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL2_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL2_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl3 register */
#define XGMAC_MAC_VLAN_INCL3_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL3_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL3_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL3_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl4 register */
#define XGMAC_MAC_VLAN_INCL4_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL4_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL4_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL4_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl5 register */
#define XGMAC_MAC_VLAN_INCL5_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL5_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL5_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL5_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl6 register */
#define XGMAC_MAC_VLAN_INCL6_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL6_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL6_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL6_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl7 register */
#define XGMAC_MAC_VLAN_INCL7_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL7_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL7_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL7_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl8 register */
#define XGMAC_MAC_VLAN_INCL8_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL8_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL8_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL8_VLT_POS \
        0U

/* Bit fields of MAC_VLAN_Incl9 register */
#define XGMAC_MAC_VLAN_INCL9_CSVL_MASK \
        0x00010000U
#define XGMAC_MAC_VLAN_INCL9_CSVL_POS \
        16U
#define XGMAC_MAC_VLAN_INCL9_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_VLAN_INCL9_VLT_POS \
        0U

/* Bit fields of MAC_Inner_VLAN_Incl register */
#define XGMAC_MAC_INNER_VLAN_INCL_VLTI_MASK \
        0x00100000U
#define XGMAC_MAC_INNER_VLAN_INCL_VLTI_POS \
        20U
#define XGMAC_MAC_INNER_VLAN_INCL_CSVL_MASK \
        0x00080000U
#define XGMAC_MAC_INNER_VLAN_INCL_CSVL_POS \
        19U
#define XGMAC_MAC_INNER_VLAN_INCL_VLP_MASK \
        0x00040000U
#define XGMAC_MAC_INNER_VLAN_INCL_VLP_POS \
        18U
#define XGMAC_MAC_INNER_VLAN_INCL_VLC_MASK \
        0x00030000U
#define XGMAC_MAC_INNER_VLAN_INCL_VLC_POS \
        16U
#define XGMAC_MAC_INNER_VLAN_INCL_VLT_MASK \
        0x0000FFFFU
#define XGMAC_MAC_INNER_VLAN_INCL_VLT_POS \
        0U

/* Bit fields of MAC_Rx_Eth_Type_Match register */
#define XGMAC_MAC_RX_ETH_TYPE_MATCH_ET_MASK \
        0x0000FFFFU
#define XGMAC_MAC_RX_ETH_TYPE_MATCH_ET_POS \
        0U

/* Bit fields of MAC_Q0_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q0_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q1_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q1_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q2_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q2_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q3_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q3_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q4_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q4_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q5_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q5_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q6_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q6_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Q7_Tx_Flow_Ctrl register */
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_PT_MASK \
        0xFFFF0000U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_PT_POS \
        16U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_DZPQ_MASK \
        0x00000080U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_DZPQ_POS \
        7U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_PLT_MASK \
        0x00000070U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_PLT_POS \
        4U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_TFE_MASK \
        0x00000002U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_TFE_POS \
        1U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_FCB_MASK \
        0x00000001U
#define XGMAC_MAC_Q7_TX_FLOW_CTRL_FCB_POS \
        0U

/* Bit fields of MAC_Rx_Flow_Ctrl register */
#define XGMAC_MAC_RX_FLOW_CTRL_PFCE_MASK \
        0x00000100U
#define XGMAC_MAC_RX_FLOW_CTRL_PFCE_POS \
        8U
#define XGMAC_MAC_RX_FLOW_CTRL_UP_MASK \
        0x00000002U
#define XGMAC_MAC_RX_FLOW_CTRL_UP_POS \
        1U
#define XGMAC_MAC_RX_FLOW_CTRL_RFE_MASK \
        0x00000001U
#define XGMAC_MAC_RX_FLOW_CTRL_RFE_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl4 register */
#define XGMAC_MAC_RXQ_CTRL4_PMCBCQ_MASK \
        0x07000000U
#define XGMAC_MAC_RXQ_CTRL4_PMCBCQ_POS \
        24U
#define XGMAC_MAC_RXQ_CTRL4_VFFQ_MASK \
        0x000E0000U
#define XGMAC_MAC_RXQ_CTRL4_VFFQ_POS \
        17U
#define XGMAC_MAC_RXQ_CTRL4_VFFQE_MASK \
        0x00010000U
#define XGMAC_MAC_RXQ_CTRL4_VFFQE_POS \
        16U
#define XGMAC_MAC_RXQ_CTRL4_MFFQ_MASK \
        0x00000E00U
#define XGMAC_MAC_RXQ_CTRL4_MFFQ_POS \
        9U
#define XGMAC_MAC_RXQ_CTRL4_MFFQE_MASK \
        0x00000100U
#define XGMAC_MAC_RXQ_CTRL4_MFFQE_POS \
        8U
#define XGMAC_MAC_RXQ_CTRL4_UFFQ_MASK \
        0x0000000EU
#define XGMAC_MAC_RXQ_CTRL4_UFFQ_POS \
        1U
#define XGMAC_MAC_RXQ_CTRL4_UFFQE_MASK \
        0x00000001U
#define XGMAC_MAC_RXQ_CTRL4_UFFQE_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl5 register */
#define XGMAC_MAC_RXQ_CTRL5_PRQSO_MASK \
        0x0000000FU
#define XGMAC_MAC_RXQ_CTRL5_PRQSO_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl0 register */
#define XGMAC_MAC_RXQ_CTRL0_RXQ7EN_MASK \
        0x0000C000U
#define XGMAC_MAC_RXQ_CTRL0_RXQ7EN_POS \
        14U
#define XGMAC_MAC_RXQ_CTRL0_RXQ6EN_MASK \
        0x00003000U
#define XGMAC_MAC_RXQ_CTRL0_RXQ6EN_POS \
        12U
#define XGMAC_MAC_RXQ_CTRL0_RXQ5EN_MASK \
        0x00000C00U
#define XGMAC_MAC_RXQ_CTRL0_RXQ5EN_POS \
        10U
#define XGMAC_MAC_RXQ_CTRL0_RXQ4EN_MASK \
        0x00000300U
#define XGMAC_MAC_RXQ_CTRL0_RXQ4EN_POS \
        8U
#define XGMAC_MAC_RXQ_CTRL0_RXQ3EN_MASK \
        0x000000C0U
#define XGMAC_MAC_RXQ_CTRL0_RXQ3EN_POS \
        6U
#define XGMAC_MAC_RXQ_CTRL0_RXQ2EN_MASK \
        0x00000030U
#define XGMAC_MAC_RXQ_CTRL0_RXQ2EN_POS \
        4U
#define XGMAC_MAC_RXQ_CTRL0_RXQ1EN_MASK \
        0x0000000CU
#define XGMAC_MAC_RXQ_CTRL0_RXQ1EN_POS \
        2U
#define XGMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK \
        0x00000003U
#define XGMAC_MAC_RXQ_CTRL0_RXQ0EN_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl1 register */
#define XGMAC_MAC_RXQ_CTRL1_AVCPQ_MASK \
        0xF0000000U
#define XGMAC_MAC_RXQ_CTRL1_AVCPQ_POS \
        28U
#define XGMAC_MAC_RXQ_CTRL1_PTPQ_MASK \
        0x0F000000U
#define XGMAC_MAC_RXQ_CTRL1_PTPQ_POS \
        24U
#define XGMAC_MAC_RXQ_CTRL1_TACPQE_MASK \
        0x00800000U
#define XGMAC_MAC_RXQ_CTRL1_TACPQE_POS \
        23U
#define XGMAC_MAC_RXQ_CTRL1_TPQC_MASK \
        0x00600000U
#define XGMAC_MAC_RXQ_CTRL1_TPQC_POS \
        21U
#define XGMAC_MAC_RXQ_CTRL1_OMCBCQ_MASK \
        0x00100000U
#define XGMAC_MAC_RXQ_CTRL1_OMCBCQ_POS \
        20U
#define XGMAC_MAC_RXQ_CTRL1_DCBCPQ_MASK \
        0x000F0000U
#define XGMAC_MAC_RXQ_CTRL1_DCBCPQ_POS \
        16U
#define XGMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK \
        0x00008000U
#define XGMAC_MAC_RXQ_CTRL1_MCBCQEN_POS \
        15U
#define XGMAC_MAC_RXQ_CTRL1_MCBCQ_MASK \
        0x00000F00U
#define XGMAC_MAC_RXQ_CTRL1_MCBCQ_POS \
        8U
#define XGMAC_MAC_RXQ_CTRL1_RQ_MASK \
        0x000000F0U
#define XGMAC_MAC_RXQ_CTRL1_RQ_POS \
        4U
#define XGMAC_MAC_RXQ_CTRL1_UPQ_MASK \
        0x0000000FU
#define XGMAC_MAC_RXQ_CTRL1_UPQ_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl2 register */
#define XGMAC_MAC_RXQ_CTRL2_PSRQ3_MASK \
        0xFF000000U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ3_POS \
        24U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ2_MASK \
        0x00FF0000U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ2_POS \
        16U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ1_MASK \
        0x0000FF00U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ1_POS \
        8U
#define XGMAC_MAC_RXQ_CTRL2_PSRQ0_MASK \
        0x000000FFU
#define XGMAC_MAC_RXQ_CTRL2_PSRQ0_POS \
        0U

/* Bit fields of MAC_RxQ_Ctrl3 register */
#define XGMAC_MAC_RXQ_CTRL3_PSRQ7_MASK \
        0xFF000000U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ7_POS \
        24U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ6_MASK \
        0x00FF0000U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ6_POS \
        16U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ5_MASK \
        0x0000FF00U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ5_POS \
        8U
#define XGMAC_MAC_RXQ_CTRL3_PSRQ4_MASK \
        0x000000FFU
#define XGMAC_MAC_RXQ_CTRL3_PSRQ4_POS \
        0U

/* Bit fields of MAC_Interrupt_Status register */
#define XGMAC_MAC_INTERRUPT_STATUS_LS_MASK \
        0x03000000U
#define XGMAC_MAC_INTERRUPT_STATUS_LS_POS \
        24U
#define XGMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK \
        0x00040000U
#define XGMAC_MAC_INTERRUPT_STATUS_MFRIS_POS \
        18U
#define XGMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK \
        0x00020000U
#define XGMAC_MAC_INTERRUPT_STATUS_MFTIS_POS \
        17U
#define XGMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK \
        0x00010000U
#define XGMAC_MAC_INTERRUPT_STATUS_FPEIS_POS \
        16U
#define XGMAC_MAC_INTERRUPT_STATUS_GPIIS_MASK \
        0x00008000U
#define XGMAC_MAC_INTERRUPT_STATUS_GPIIS_POS \
        15U
#define XGMAC_MAC_INTERRUPT_STATUS_RXESIS_MASK \
        0x00004000U
#define XGMAC_MAC_INTERRUPT_STATUS_RXESIS_POS \
        14U
#define XGMAC_MAC_INTERRUPT_STATUS_TXESIS_MASK \
        0x00002000U
#define XGMAC_MAC_INTERRUPT_STATUS_TXESIS_POS \
        13U
#define XGMAC_MAC_INTERRUPT_STATUS_TSIS_MASK \
        0x00001000U
#define XGMAC_MAC_INTERRUPT_STATUS_TSIS_POS \
        12U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCRXIPIS_MASK \
        0x00000800U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCRXIPIS_POS \
        11U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK \
        0x00000400U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCTXIS_POS \
        10U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK \
        0x00000200U
#define XGMAC_MAC_INTERRUPT_STATUS_MMCRXIS_POS \
        9U
#define XGMAC_MAC_INTERRUPT_STATUS_SMI_MASK \
        0x00000002U
#define XGMAC_MAC_INTERRUPT_STATUS_SMI_POS \
        1U
#define XGMAC_MAC_INTERRUPT_STATUS_LSI_MASK \
        0x00000001U
#define XGMAC_MAC_INTERRUPT_STATUS_LSI_POS \
        0U

/* Bit fields of MAC_Interrupt_Enable register */
#define XGMAC_MAC_INTERRUPT_ENABLE_FPEIE_MASK \
        0x00008000U
#define XGMAC_MAC_INTERRUPT_ENABLE_FPEIE_POS \
        15U
#define XGMAC_MAC_INTERRUPT_ENABLE_RXESIE_MASK \
        0x00004000U
#define XGMAC_MAC_INTERRUPT_ENABLE_RXESIE_POS \
        14U
#define XGMAC_MAC_INTERRUPT_ENABLE_TXESIE_MASK \
        0x00002000U
#define XGMAC_MAC_INTERRUPT_ENABLE_TXESIE_POS \
        13U
#define XGMAC_MAC_INTERRUPT_ENABLE_TSIE_MASK \
        0x00001000U
#define XGMAC_MAC_INTERRUPT_ENABLE_TSIE_POS \
        12U
#define XGMAC_MAC_INTERRUPT_ENABLE_LSIE_MASK \
        0x00000001U
#define XGMAC_MAC_INTERRUPT_ENABLE_LSIE_POS \
        0U

/* Bit fields of MAC_Rx_Tx_Status register */
#define XGMAC_MAC_RX_TX_STATUS_PCE_MASK \
        0x00002000U
#define XGMAC_MAC_RX_TX_STATUS_PCE_POS \
        13U
#define XGMAC_MAC_RX_TX_STATUS_IHE_MASK \
        0x00001000U
#define XGMAC_MAC_RX_TX_STATUS_IHE_POS \
        12U
#define XGMAC_MAC_RX_TX_STATUS_RWT_MASK \
        0x00000100U
#define XGMAC_MAC_RX_TX_STATUS_RWT_POS \
        8U
#define XGMAC_MAC_RX_TX_STATUS_EXCOL_MASK \
        0x00000020U
#define XGMAC_MAC_RX_TX_STATUS_EXCOL_POS \
        5U
#define XGMAC_MAC_RX_TX_STATUS_LCOL_MASK \
        0x00000010U
#define XGMAC_MAC_RX_TX_STATUS_LCOL_POS \
        4U
#define XGMAC_MAC_RX_TX_STATUS_EXDEF_MASK \
        0x00000008U
#define XGMAC_MAC_RX_TX_STATUS_EXDEF_POS \
        3U
#define XGMAC_MAC_RX_TX_STATUS_LCARR_MASK \
        0x00000004U
#define XGMAC_MAC_RX_TX_STATUS_LCARR_POS \
        2U
#define XGMAC_MAC_RX_TX_STATUS_NCARR_MASK \
        0x00000002U
#define XGMAC_MAC_RX_TX_STATUS_NCARR_POS \
        1U
#define XGMAC_MAC_RX_TX_STATUS_TJT_MASK \
        0x00000001U
#define XGMAC_MAC_RX_TX_STATUS_TJT_POS \
        0U

/* Bit fields of MAC_Version register */
#define XGMAC_MAC_VERSION_USERVER_MASK \
        0x00FF0000U
#define XGMAC_MAC_VERSION_USERVER_POS \
        16U
#define XGMAC_MAC_VERSION_DEVID_MASK \
        0x0000FF00U
#define XGMAC_MAC_VERSION_DEVID_POS \
        8U
#define XGMAC_MAC_VERSION_SNPSVER_MASK \
        0x000000FFU
#define XGMAC_MAC_VERSION_SNPSVER_POS \
        0U

/* Bit fields of MAC_Debug register */
#define XGMAC_MAC_DEBUG_TFCSTS_MASK \
        0x00060000U
#define XGMAC_MAC_DEBUG_TFCSTS_POS \
        17U
#define XGMAC_MAC_DEBUG_TPESTS_MASK \
        0x00010000U
#define XGMAC_MAC_DEBUG_TPESTS_POS \
        16U
#define XGMAC_MAC_DEBUG_RFCFCSTS_MASK \
        0x00000006U
#define XGMAC_MAC_DEBUG_RFCFCSTS_POS \
        1U
#define XGMAC_MAC_DEBUG_RPESTS_MASK \
        0x00000001U
#define XGMAC_MAC_DEBUG_RPESTS_POS \
        0U

/* Bit fields of MAC_HW_Feature0 register */
#define XGMAC_MAC_HW_FEATURE0_EDMA_MASK \
        0x80000000U
#define XGMAC_MAC_HW_FEATURE0_EDMA_POS \
        31U
#define XGMAC_MAC_HW_FEATURE0_EDIFFC_MASK \
        0x40000000U
#define XGMAC_MAC_HW_FEATURE0_EDIFFC_POS \
        30U
#define XGMAC_MAC_HW_FEATURE0_VXN_MASK \
        0x20000000U
#define XGMAC_MAC_HW_FEATURE0_VXN_POS \
        29U
#define XGMAC_MAC_HW_FEATURE0_SAVLANINS_MASK \
        0x08000000U
#define XGMAC_MAC_HW_FEATURE0_SAVLANINS_POS \
        27U
#define XGMAC_MAC_HW_FEATURE0_TSSTSSEL_MASK \
        0x06000000U
#define XGMAC_MAC_HW_FEATURE0_TSSTSSEL_POS \
        25U
#define XGMAC_MAC_HW_FEATURE0_PHYSEL_MASK \
        0x01800000U
#define XGMAC_MAC_HW_FEATURE0_PHYSEL_POS \
        23U
#define XGMAC_MAC_HW_FEATURE0_ADDMACADRSEL_MASK \
        0x007C0000U
#define XGMAC_MAC_HW_FEATURE0_ADDMACADRSEL_POS \
        18U
#define XGMAC_MAC_HW_FEATURE0_RXCOESEL_MASK \
        0x00010000U
#define XGMAC_MAC_HW_FEATURE0_RXCOESEL_POS \
        16U
#define XGMAC_MAC_HW_FEATURE0_TXCOESEL_MASK \
        0x00004000U
#define XGMAC_MAC_HW_FEATURE0_TXCOESEL_POS \
        14U
#define XGMAC_MAC_HW_FEATURE0_EEESEL_MASK \
        0x00002000U
#define XGMAC_MAC_HW_FEATURE0_EEESEL_POS \
        13U
#define XGMAC_MAC_HW_FEATURE0_TSSEL_MASK \
        0x00001000U
#define XGMAC_MAC_HW_FEATURE0_TSSEL_POS \
        12U
#define XGMAC_MAC_HW_FEATURE0_AVSEL_MASK \
        0x00000800U
#define XGMAC_MAC_HW_FEATURE0_AVSEL_POS \
        11U
#define XGMAC_MAC_HW_FEATURE0_RAVSEL_MASK \
        0x00000400U
#define XGMAC_MAC_HW_FEATURE0_RAVSEL_POS \
        10U
#define XGMAC_MAC_HW_FEATURE0_ARPOFFSEL_MASK \
        0x00000200U
#define XGMAC_MAC_HW_FEATURE0_ARPOFFSEL_POS \
        9U
#define XGMAC_MAC_HW_FEATURE0_MMCSEL_MASK \
        0x00000100U
#define XGMAC_MAC_HW_FEATURE0_MMCSEL_POS \
        8U
#define XGMAC_MAC_HW_FEATURE0_MGKSEL_MASK \
        0x00000080U
#define XGMAC_MAC_HW_FEATURE0_MGKSEL_POS \
        7U
#define XGMAC_MAC_HW_FEATURE0_RWKSEL_MASK \
        0x00000040U
#define XGMAC_MAC_HW_FEATURE0_RWKSEL_POS \
        6U
#define XGMAC_MAC_HW_FEATURE0_SMASEL_MASK \
        0x00000020U
#define XGMAC_MAC_HW_FEATURE0_SMASEL_POS \
        5U
#define XGMAC_MAC_HW_FEATURE0_VLHASH_MASK \
        0x00000010U
#define XGMAC_MAC_HW_FEATURE0_VLHASH_POS \
        4U
#define XGMAC_MAC_HW_FEATURE0_HDSEL_MASK \
        0x00000008U
#define XGMAC_MAC_HW_FEATURE0_HDSEL_POS \
        3U
#define XGMAC_MAC_HW_FEATURE0_RMIISEL_MASK \
        0x00000004U
#define XGMAC_MAC_HW_FEATURE0_RMIISEL_POS \
        2U
#define XGMAC_MAC_HW_FEATURE0_GMIISEL_MASK \
        0x00000002U
#define XGMAC_MAC_HW_FEATURE0_GMIISEL_POS \
        1U
#define XGMAC_MAC_HW_FEATURE0_RGMIISEL_MASK \
        0x00000001U
#define XGMAC_MAC_HW_FEATURE0_RGMIISEL_POS \
        0U

/* Bit fields of MAC_HW_Feature1 register */
#define XGMAC_MAC_HW_FEATURE1_L3L4FNUM_MASK \
        0x78000000U
#define XGMAC_MAC_HW_FEATURE1_L3L4FNUM_POS \
        27U
#define XGMAC_MAC_HW_FEATURE1_HASHTBLSZ_MASK \
        0x07000000U
#define XGMAC_MAC_HW_FEATURE1_HASHTBLSZ_POS \
        24U
#define XGMAC_MAC_HW_FEATURE1_NUMTC_MASK \
        0x00E00000U
#define XGMAC_MAC_HW_FEATURE1_NUMTC_POS \
        21U
#define XGMAC_MAC_HW_FEATURE1_RSSEN_MASK \
        0x00100000U
#define XGMAC_MAC_HW_FEATURE1_RSSEN_POS \
        20U
#define XGMAC_MAC_HW_FEATURE1_DBGMEMA_MASK \
        0x00080000U
#define XGMAC_MAC_HW_FEATURE1_DBGMEMA_POS \
        19U
#define XGMAC_MAC_HW_FEATURE1_TSOEN_MASK \
        0x00040000U
#define XGMAC_MAC_HW_FEATURE1_TSOEN_POS \
        18U
#define XGMAC_MAC_HW_FEATURE1_SPHEN_MASK \
        0x00020000U
#define XGMAC_MAC_HW_FEATURE1_SPHEN_POS \
        17U
#define XGMAC_MAC_HW_FEATURE1_DCBEN_MASK \
        0x00010000U
#define XGMAC_MAC_HW_FEATURE1_DCBEN_POS \
        16U
#define XGMAC_MAC_HW_FEATURE1_ADDR64_MASK \
        0x0000C000U
#define XGMAC_MAC_HW_FEATURE1_ADDR64_POS \
        14U
#define XGMAC_MAC_HW_FEATURE1_ADVTHWORD_MASK \
        0x00002000U
#define XGMAC_MAC_HW_FEATURE1_ADVTHWORD_POS \
        13U
#define XGMAC_MAC_HW_FEATURE1_PTOEN_MASK \
        0x00001000U
#define XGMAC_MAC_HW_FEATURE1_PTOEN_POS \
        12U
#define XGMAC_MAC_HW_FEATURE1_OSTEN_MASK \
        0x00000800U
#define XGMAC_MAC_HW_FEATURE1_OSTEN_POS \
        11U
#define XGMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK \
        0x000007C0U
#define XGMAC_MAC_HW_FEATURE1_TXFIFOSIZE_POS \
        6U
#define XGMAC_MAC_HW_FEATURE1_PFCEN_MASK \
        0x00000020U
#define XGMAC_MAC_HW_FEATURE1_PFCEN_POS \
        5U
#define XGMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK \
        0x0000001FU
#define XGMAC_MAC_HW_FEATURE1_RXFIFOSIZE_POS \
        0U

/* Bit fields of MAC_HW_Feature2 register */
#define XGMAC_MAC_HW_FEATURE2_AUXSNAPNUM_MASK \
        0x70000000U
#define XGMAC_MAC_HW_FEATURE2_AUXSNAPNUM_POS \
        28U
#define XGMAC_MAC_HW_FEATURE2_PPSOUTNUM_MASK \
        0x07000000U
#define XGMAC_MAC_HW_FEATURE2_PPSOUTNUM_POS \
        24U
#define XGMAC_MAC_HW_FEATURE2_TXCHCNT_MASK \
        0x003C0000U
#define XGMAC_MAC_HW_FEATURE2_TXCHCNT_POS \
        18U
#define XGMAC_MAC_HW_FEATURE2_RXCHCNT_MASK \
        0x0000F000U
#define XGMAC_MAC_HW_FEATURE2_RXCHCNT_POS \
        12U
#define XGMAC_MAC_HW_FEATURE2_TXQCNT_MASK \
        0x000003C0U
#define XGMAC_MAC_HW_FEATURE2_TXQCNT_POS \
        6U
#define XGMAC_MAC_HW_FEATURE2_RXQCNT_MASK \
        0x0000000FU
#define XGMAC_MAC_HW_FEATURE2_RXQCNT_POS \
        0U

/* Bit fields of MAC_HW_Feature3 register */
#define XGMAC_MAC_HW_FEATURE3_TBS_CH_MASK \
        0xF0000000U
#define XGMAC_MAC_HW_FEATURE3_TBS_CH_POS \
        28U
#define XGMAC_MAC_HW_FEATURE3_TBSSEL_MASK \
        0x08000000U
#define XGMAC_MAC_HW_FEATURE3_TBSSEL_POS \
        27U
#define XGMAC_MAC_HW_FEATURE3_FPESEL_MASK \
        0x04000000U
#define XGMAC_MAC_HW_FEATURE3_FPESEL_POS \
        26U
#define XGMAC_MAC_HW_FEATURE3_SGFSEL_MASK \
        0x02000000U
#define XGMAC_MAC_HW_FEATURE3_SGFSEL_POS \
        25U
#define XGMAC_MAC_HW_FEATURE3_GCLWID_MASK \
        0x01800000U
#define XGMAC_MAC_HW_FEATURE3_GCLWID_POS \
        23U
#define XGMAC_MAC_HW_FEATURE3_GCLDEP_MASK \
        0x00700000U
#define XGMAC_MAC_HW_FEATURE3_GCLDEP_POS \
        20U
#define XGMAC_MAC_HW_FEATURE3_ESTSEL_MASK \
        0x00080000U
#define XGMAC_MAC_HW_FEATURE3_ESTSEL_POS \
        19U
#define XGMAC_MAC_HW_FEATURE3_TTSFD_MASK \
        0x00070000U
#define XGMAC_MAC_HW_FEATURE3_TTSFD_POS \
        16U
#define XGMAC_MAC_HW_FEATURE3_ASP_MASK \
        0x0000C000U
#define XGMAC_MAC_HW_FEATURE3_ASP_POS \
        14U
#define XGMAC_MAC_HW_FEATURE3_DVLAN_MASK \
        0x00002000U
#define XGMAC_MAC_HW_FEATURE3_DVLAN_POS \
        13U
#define XGMAC_MAC_HW_FEATURE3_FRPES_MASK \
        0x00001800U
#define XGMAC_MAC_HW_FEATURE3_FRPES_POS \
        11U
#define XGMAC_MAC_HW_FEATURE3_FRPPB_MASK \
        0x00000600U
#define XGMAC_MAC_HW_FEATURE3_FRPPB_POS \
        9U
#define XGMAC_MAC_HW_FEATURE3_POUOST_MASK \
        0x00000100U
#define XGMAC_MAC_HW_FEATURE3_POUOST_POS \
        8U
#define XGMAC_MAC_HW_FEATURE3_FRPPIPE_MASK \
        0x000000E0U
#define XGMAC_MAC_HW_FEATURE3_FRPPIPE_POS \
        5U
#define XGMAC_MAC_HW_FEATURE3_CBTISEL_MASK \
        0x00000010U
#define XGMAC_MAC_HW_FEATURE3_CBTISEL_POS \
        4U
#define XGMAC_MAC_HW_FEATURE3_FRPSEL_MASK \
        0x00000008U
#define XGMAC_MAC_HW_FEATURE3_FRPSEL_POS \
        3U
#define XGMAC_MAC_HW_FEATURE3_NRVF_MASK \
        0x00000007U
#define XGMAC_MAC_HW_FEATURE3_NRVF_POS \
        0U

/* Bit fields of MAC_HW_Feature4 register */
#define XGMAC_MAC_HW_FEATURE4_PCSEL_MASK \
        0x00000003U
#define XGMAC_MAC_HW_FEATURE4_PCSEL_POS \
        0U

/* Bit fields of MAC_Extended_Configuration register */
#define XGMAC_MAC_EXTENDED_CONFIGURATION_HD_MASK \
        0x01000000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_HD_POS \
        24U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_ECRSFD_MASK \
        0x00800000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_ECRSFD_POS \
        23U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DO_MASK \
        0x00400000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DO_POS \
        22U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DCRS_MASK \
        0x00200000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DCRS_POS \
        21U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DR_MASK \
        0x00100000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DR_POS \
        20U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_BL_MASK \
        0x000C0000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_BL_POS \
        18U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DC_MASK \
        0x00020000U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DC_POS \
        17U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_TPRE_MASK \
        0x00000200U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_TPRE_POS \
        9U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DDS_MASK \
        0x00000080U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_DDS_POS \
        7U
#define XGMAC_MAC_EXTENDED_CONFIGURATION_EIPG_MASK \
        0x0000007FU
#define XGMAC_MAC_EXTENDED_CONFIGURATION_EIPG_POS \
        0U

/* Bit fields of MAC_Ext_Cfg1 register */
#define XGMAC_MAC_EXT_CFG1_SAVE_MASK \
        0x01000000U
#define XGMAC_MAC_EXT_CFG1_SAVE_POS \
        24U
#define XGMAC_MAC_EXT_CFG1_SAVO_MASK \
        0x007F0000U
#define XGMAC_MAC_EXT_CFG1_SAVO_POS \
        16U
#define XGMAC_MAC_EXT_CFG1_SPLM_MASK \
        0x00000300U
#define XGMAC_MAC_EXT_CFG1_SPLM_POS \
        8U
#define XGMAC_MAC_EXT_CFG1_SPLOFST_MASK \
        0x0000007FU
#define XGMAC_MAC_EXT_CFG1_SPLOFST_POS \
        0U

/* Bit fields of MDIO_Single_Command_Address register */
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_DA_MASK \
        0x03E00000U
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_DA_POS \
        21U
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_PA_MASK \
        0x001F0000U
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_PA_POS \
        16U
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_RA_MASK \
        0x0000FFFFU
#define XGMAC_MDIO_SINGLE_COMMAND_ADDRESS_RA_POS \
        0U

/* Bit fields of MDIO_Single_Command_Control_Data register */
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CRS_MASK \
        0x80000000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CRS_POS \
        31U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_PSE_MASK \
        0x40000000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_PSE_POS \
        30U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SBUSY_MASK \
        0x00400000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SBUSY_POS \
        22U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CR_MASK \
        0x00380000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CR_POS \
        19U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SAADR_MASK \
        0x00040000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SAADR_POS \
        18U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CMD_MASK \
        0x00030000U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_CMD_POS \
        16U
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SDATA_MASK \
        0x0000FFFFU
#define XGMAC_MDIO_SINGLE_COMMAND_CONTROL_DATA_SDATA_POS \
        0U

/* Bit fields of MDIO_Continuous_Write_Address register */
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CBUSY_MASK \
        0x00400000U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CBUSY_POS \
        22U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CPRT_MASK \
        0x00200000U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CPRT_POS \
        21U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CADDR_MASK \
        0x001F0000U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CADDR_POS \
        16U
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CREGADDR_MASK \
        0x0000FFFFU
#define XGMAC_MDIO_CONTINUOUS_WRITE_ADDRESS_CREGADDR_POS \
        0U

/* Bit fields of MDIO_Continuous_Write_Data register */
#define XGMAC_MDIO_CONTINUOUS_WRITE_DATA_CDATA_MASK \
        0x0000FFFFU
#define XGMAC_MDIO_CONTINUOUS_WRITE_DATA_CDATA_POS \
        0U

/* Bit fields of MDIO_Continuous_Scan_Port_Enable register */
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT31SCE_MASK \
        0x80000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT31SCE_POS \
        31U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT30SCE_MASK \
        0x40000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT30SCE_POS \
        30U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT29SCE_MASK \
        0x20000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT29SCE_POS \
        29U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT28SCE_MASK \
        0x10000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT28SCE_POS \
        28U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT27SCE_MASK \
        0x08000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT27SCE_POS \
        27U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT26SCE_MASK \
        0x04000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT26SCE_POS \
        26U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT25SCE_MASK \
        0x02000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT25SCE_POS \
        25U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT24SCE_MASK \
        0x01000000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT24SCE_POS \
        24U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT23SCE_MASK \
        0x00800000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT23SCE_POS \
        23U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT22SCE_MASK \
        0x00400000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT22SCE_POS \
        22U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT21SCE_MASK \
        0x00200000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT21SCE_POS \
        21U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT20SCE_MASK \
        0x00100000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT20SCE_POS \
        20U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT19SCE_MASK \
        0x00080000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT19SCE_POS \
        19U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT18SCE_MASK \
        0x00040000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT18SCE_POS \
        18U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT17SCE_MASK \
        0x00020000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT17SCE_POS \
        17U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT16SCE_MASK \
        0x00010000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT16SCE_POS \
        16U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT15SCE_MASK \
        0x00008000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT15SCE_POS \
        15U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT14SCE_MASK \
        0x00004000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT14SCE_POS \
        14U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT13SCE_MASK \
        0x00002000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT13SCE_POS \
        13U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT12SCE_MASK \
        0x00001000U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT12SCE_POS \
        12U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT11SCE_MASK \
        0x00000800U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT11SCE_POS \
        11U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT10SCE_MASK \
        0x00000400U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT10SCE_POS \
        10U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT9SCE_MASK \
        0x00000200U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT9SCE_POS \
        9U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT8SCE_MASK \
        0x00000100U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT8SCE_POS \
        8U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT7SCE_MASK \
        0x00000080U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT7SCE_POS \
        7U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT6SCE_MASK \
        0x00000040U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT6SCE_POS \
        6U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT5SCE_MASK \
        0x00000020U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT5SCE_POS \
        5U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT4SCE_MASK \
        0x00000010U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT4SCE_POS \
        4U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT3SCE_MASK \
        0x00000008U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT3SCE_POS \
        3U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT2SCE_MASK \
        0x00000004U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT2SCE_POS \
        2U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT1SCE_MASK \
        0x00000002U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT1SCE_POS \
        1U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT0SCE_MASK \
        0x00000001U
#define XGMAC_MDIO_CONTINUOUS_SCAN_PORT_ENABLE_PORT0SCE_POS \
        0U

/* Bit fields of MDIO_Interrupt_Status register */
#define XGMAC_MDIO_INTERRUPT_STATUS_CWCOMPINT_MASK \
        0x00002000U
#define XGMAC_MDIO_INTERRUPT_STATUS_CWCOMPINT_POS \
        13U
#define XGMAC_MDIO_INTERRUPT_STATUS_SNGLCOMPINT_MASK \
        0x00001000U
#define XGMAC_MDIO_INTERRUPT_STATUS_SNGLCOMPINT_POS \
        12U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3ALINT_MASK \
        0x00000800U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3ALINT_POS \
        11U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2ALINT_MASK \
        0x00000400U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2ALINT_POS \
        10U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1ALINT_MASK \
        0x00000200U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1ALINT_POS \
        9U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0ALINT_MASK \
        0x00000100U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0ALINT_POS \
        8U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3LSINT_MASK \
        0x00000080U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3LSINT_POS \
        7U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2LSINT_MASK \
        0x00000040U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2LSINT_POS \
        6U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1LSINT_MASK \
        0x00000020U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1LSINT_POS \
        5U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0LSINT_MASK \
        0x00000010U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0LSINT_POS \
        4U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3CONINT_MASK \
        0x00000008U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P3CONINT_POS \
        3U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2CONINT_MASK \
        0x00000004U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P2CONINT_POS \
        2U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1CONINT_MASK \
        0x00000002U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P1CONINT_POS \
        1U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0CONINT_MASK \
        0x00000001U
#define XGMAC_MDIO_INTERRUPT_STATUS_PORTNX4P0CONINT_POS \
        0U

/* Bit fields of MDIO_Interrupt_Enable register */
#define XGMAC_MDIO_INTERRUPT_ENABLE_CWCOMPIE_MASK \
        0x00002000U
#define XGMAC_MDIO_INTERRUPT_ENABLE_CWCOMPIE_POS \
        13U
#define XGMAC_MDIO_INTERRUPT_ENABLE_SNGLCOMPIE_MASK \
        0x00001000U
#define XGMAC_MDIO_INTERRUPT_ENABLE_SNGLCOMPIE_POS \
        12U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3ALIE_MASK \
        0x00000800U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3ALIE_POS \
        11U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2ALIE_MASK \
        0x00000400U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2ALIE_POS \
        10U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1ALIE_MASK \
        0x00000200U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1ALIE_POS \
        9U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0ALIE_MASK \
        0x00000100U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0ALIE_POS \
        8U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3LSIE_MASK \
        0x00000080U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3LSIE_POS \
        7U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2LSIE_MASK \
        0x00000040U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2LSIE_POS \
        6U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1LSIE_MASK \
        0x00000020U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1LSIE_POS \
        5U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0LSIE_MASK \
        0x00000010U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0LSIE_POS \
        4U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3CONIE_MASK \
        0x00000008U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P3CONIE_POS \
        3U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2CONIE_MASK \
        0x00000004U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P2CONIE_POS \
        2U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1CONIE_MASK \
        0x00000002U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P1CONIE_POS \
        1U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0CONIE_MASK \
        0x00000001U
#define XGMAC_MDIO_INTERRUPT_ENABLE_PTRNX4P0CONIE_POS \
        0U

/* Bit fields of MDIO_Port_Connect_Disconnect_Status register */
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT31CON_MASK \
        0x80000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT31CON_POS \
        31U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT30CON_MASK \
        0x40000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT30CON_POS \
        30U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT29CON_MASK \
        0x20000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT29CON_POS \
        29U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT28CON_MASK \
        0x10000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT28CON_POS \
        28U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT27CON_MASK \
        0x08000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT27CON_POS \
        27U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT26CON_MASK \
        0x04000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT26CON_POS \
        26U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT25CON_MASK \
        0x02000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT25CON_POS \
        25U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT24CON_MASK \
        0x01000000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT24CON_POS \
        24U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT23CON_MASK \
        0x00800000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT23CON_POS \
        23U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT22CON_MASK \
        0x00400000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT22CON_POS \
        22U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT21CON_MASK \
        0x00200000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT21CON_POS \
        21U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT20CON_MASK \
        0x00100000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT20CON_POS \
        20U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT19CON_MASK \
        0x00080000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT19CON_POS \
        19U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT18CON_MASK \
        0x00040000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT18CON_POS \
        18U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT17CON_MASK \
        0x00020000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT17CON_POS \
        17U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT16CON_MASK \
        0x00010000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT16CON_POS \
        16U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT15CON_MASK \
        0x00008000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT15CON_POS \
        15U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT14CON_MASK \
        0x00004000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT14CON_POS \
        14U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT13CON_MASK \
        0x00002000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT13CON_POS \
        13U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT12CON_MASK \
        0x00001000U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT12CON_POS \
        12U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT11CON_MASK \
        0x00000800U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT11CON_POS \
        11U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT10CON_MASK \
        0x00000400U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT10CON_POS \
        10U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT9CON_MASK \
        0x00000200U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT9CON_POS \
        9U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT8CON_MASK \
        0x00000100U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT8CON_POS \
        8U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT7CON_MASK \
        0x00000080U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT7CON_POS \
        7U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT6CON_MASK \
        0x00000040U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT6CON_POS \
        6U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT5CON_MASK \
        0x00000020U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT5CON_POS \
        5U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT4CON_MASK \
        0x00000010U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT4CON_POS \
        4U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT3CON_MASK \
        0x00000008U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT3CON_POS \
        3U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT2CON_MASK \
        0x00000004U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT2CON_POS \
        2U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT1CON_MASK \
        0x00000002U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT1CON_POS \
        1U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT0CON_MASK \
        0x00000001U
#define XGMAC_MDIO_PORT_CONNECT_DISCONNECT_STATUS_PORT0CON_POS \
        0U

/* Bit fields of MDIO_Clause_22_Port register */
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR31CL22_MASK \
        0x80000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR31CL22_POS \
        31U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR30CL22_MASK \
        0x40000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR30CL22_POS \
        30U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR29CL22_MASK \
        0x20000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR29CL22_POS \
        29U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR28CL22_MASK \
        0x10000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR28CL22_POS \
        28U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR27CL22_MASK \
        0x08000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR27CL22_POS \
        27U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR26CL22_MASK \
        0x04000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR26CL22_POS \
        26U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR25CL22_MASK \
        0x02000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR25CL22_POS \
        25U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR24CL22_MASK \
        0x01000000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR24CL22_POS \
        24U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR23CL22_MASK \
        0x00800000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR23CL22_POS \
        23U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR22CL22_MASK \
        0x00400000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR22CL22_POS \
        22U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR21CL22_MASK \
        0x00200000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR21CL22_POS \
        21U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR20CL22_MASK \
        0x00100000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR20CL22_POS \
        20U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR19CL22_MASK \
        0x00080000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR19CL22_POS \
        19U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR18CL22_MASK \
        0x00040000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR18CL22_POS \
        18U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR17CL22_MASK \
        0x00020000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR17CL22_POS \
        17U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR16CL22_MASK \
        0x00010000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR16CL22_POS \
        16U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR15CL22_MASK \
        0x00008000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR15CL22_POS \
        15U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR14CL22_MASK \
        0x00004000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR14CL22_POS \
        14U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR13CL22_MASK \
        0x00002000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR13CL22_POS \
        13U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR12CL22_MASK \
        0x00001000U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR12CL22_POS \
        12U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR11CL22_MASK \
        0x00000800U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR11CL22_POS \
        11U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR10CL22_MASK \
        0x00000400U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR10CL22_POS \
        10U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR9CL22_MASK \
        0x00000200U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR9CL22_POS \
        9U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR8CL22_MASK \
        0x00000100U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR8CL22_POS \
        8U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR7CL22_MASK \
        0x00000080U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR7CL22_POS \
        7U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR6CL22_MASK \
        0x00000040U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR6CL22_POS \
        6U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR5CL22_MASK \
        0x00000020U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR5CL22_POS \
        5U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR4CL22_MASK \
        0x00000010U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR4CL22_POS \
        4U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR3CL22_MASK \
        0x00000008U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR3CL22_POS \
        3U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR2CL22_MASK \
        0x00000004U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR2CL22_POS \
        2U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR1CL22_MASK \
        0x00000002U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR1CL22_POS \
        1U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR0CL22_MASK \
        0x00000001U
#define XGMAC_MDIO_CLAUSE_22_PORT_PTR0CL22_POS \
        0U

/* Bit fields of MDIO_Port_Nx4_Indirect_Control register */
#define XGMAC_MDIO_PORT_NX4_INDIRECT_CONTROL_PRS_MASK \
        0x00000007U
#define XGMAC_MDIO_PORT_NX4_INDIRECT_CONTROL_PRS_POS \
        0U

/* Bit fields of MDIO_PortNx4P0_Device_In_Use register */
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0VSD2_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0VSD2_POS \
        31U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0VSD1_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0VSD1_POS \
        30U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0TC_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0TC_POS \
        6U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0DTEXS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0DTEXS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PHYXS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PHYXS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PCS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PCS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0WIS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0WIS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PMDPMA_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P0_DEVICE_IN_USE_NX4P0PMDPMA_POS \
        1U

/* Bit fields of MDIO_PortNx4P0_Link_Status register */
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P0_LINK_STATUS_NX4P0PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P0_Alive_Status register */
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P0_ALIVE_STATUS_NX4P0PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P1_Device_In_Use register */
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1VSD2_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1VSD2_POS \
        31U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1VSD1_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1VSD1_POS \
        30U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1TC_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1TC_POS \
        6U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1DTEXS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1DTEXS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PHYXS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PHYXS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PCS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PCS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1WIS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1WIS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PMDPMA_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P1_DEVICE_IN_USE_NX4P1PMDPMA_POS \
        1U

/* Bit fields of MDIO_PortNx4P1_Link_Status register */
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P1_LINK_STATUS_NX4P1PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P1_Alive_Status register */
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P1_ALIVE_STATUS_NX4P1PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P2_Device_In_Use register */
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2VSD2_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2VSD2_POS \
        31U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2VSD1_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2VSD1_POS \
        30U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2TC_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2TC_POS \
        6U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2DTEXS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2DTEXS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PHYXS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PHYXS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PCS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PCS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2WIS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2WIS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PMDPMA_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P2_DEVICE_IN_USE_NX4P2PMDPMA_POS \
        1U

/* Bit fields of MDIO_PortNx4P2_Link_Status register */
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P2_LINK_STATUS_NX4P2PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P2_Alive_Status register */
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P2_ALIVE_STATUS_NX4P2PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P3_Device_In_Use register */
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3VSD2_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3VSD2_POS \
        31U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3VSD1_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3VSD1_POS \
        30U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3TC_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3TC_POS \
        6U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3DTEXS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3DTEXS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PHYXS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PHYXS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PCS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PCS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3WIS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3WIS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PMDPMA_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P3_DEVICE_IN_USE_NX4P3PMDPMA_POS \
        1U

/* Bit fields of MDIO_PortNx4P3_Link_Status register */
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P3_LINK_STATUS_NX4P3PMDPMALS_POS \
        1U

/* Bit fields of MDIO_PortNx4P3_Alive_Status register */
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3VSD2LS_MASK \
        0x80000000U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3VSD2LS_POS \
        31U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3VSD1LS_MASK \
        0x40000000U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3VSD1LS_POS \
        30U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3TCLS_MASK \
        0x00000040U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3TCLS_POS \
        6U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3DTEXSLS_MASK \
        0x00000020U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3DTEXSLS_POS \
        5U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PHYXSLS_MASK \
        0x00000010U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PHYXSLS_POS \
        4U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PCSLS_MASK \
        0x00000008U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PCSLS_POS \
        3U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3WISLS_MASK \
        0x00000004U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3WISLS_POS \
        2U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PMDPMALS_MASK \
        0x00000002U
#define XGMAC_MDIO_PORTNX4P3_ALIVE_STATUS_NX4P3PMDPMALS_POS \
        1U

/* Bit fields of MAC_GPIO_Control register */
#define XGMAC_MAC_GPIO_CONTROL_GPIT_MASK \
        0x00FF0000U
#define XGMAC_MAC_GPIO_CONTROL_GPIT_POS \
        16U
#define XGMAC_MAC_GPIO_CONTROL_GPIE_MASK \
        0x0000000FU
#define XGMAC_MAC_GPIO_CONTROL_GPIE_POS \
        0U

/* Bit fields of MAC_GPIO_Status register */
#define XGMAC_MAC_GPIO_STATUS_GPO_MASK \
        0x00FF0000U
#define XGMAC_MAC_GPIO_STATUS_GPO_POS \
        16U
#define XGMAC_MAC_GPIO_STATUS_GPIS_MASK \
        0x000000FFU
#define XGMAC_MAC_GPIO_STATUS_GPIS_POS \
        0U

/* Bit fields of MAC_FPE_CTRL_STS register */
#define XGMAC_MAC_FPE_CTRL_STS_TRSP_MASK \
        0x00080000U
#define XGMAC_MAC_FPE_CTRL_STS_TRSP_POS \
        19U
#define XGMAC_MAC_FPE_CTRL_STS_TVER_MASK \
        0x00040000U
#define XGMAC_MAC_FPE_CTRL_STS_TVER_POS \
        18U
#define XGMAC_MAC_FPE_CTRL_STS_RRSP_MASK \
        0x00020000U
#define XGMAC_MAC_FPE_CTRL_STS_RRSP_POS \
        17U
#define XGMAC_MAC_FPE_CTRL_STS_RVER_MASK \
        0x00010000U
#define XGMAC_MAC_FPE_CTRL_STS_RVER_POS \
        16U
#define XGMAC_MAC_FPE_CTRL_STS_ARV_MASK \
        0x00000008U
#define XGMAC_MAC_FPE_CTRL_STS_ARV_POS \
        3U
#define XGMAC_MAC_FPE_CTRL_STS_SRSP_MASK \
        0x00000004U
#define XGMAC_MAC_FPE_CTRL_STS_SRSP_POS \
        2U
#define XGMAC_MAC_FPE_CTRL_STS_SVER_MASK \
        0x00000002U
#define XGMAC_MAC_FPE_CTRL_STS_SVER_POS \
        1U
#define XGMAC_MAC_FPE_CTRL_STS_EFPE_MASK \
        0x00000001U
#define XGMAC_MAC_FPE_CTRL_STS_EFPE_POS \
        0U

/* Bit fields of MAC_CSR_SW_Ctrl register */
#define XGMAC_MAC_CSR_SW_CTRL_SEEN_MASK \
        0x00000100U
#define XGMAC_MAC_CSR_SW_CTRL_SEEN_POS \
        8U
#define XGMAC_MAC_CSR_SW_CTRL_RCWE_MASK \
        0x00000001U
#define XGMAC_MAC_CSR_SW_CTRL_RCWE_POS \
        0U

/* Bit fields of MAC_Address0_High register */
#define XGMAC_MAC_ADDRESS0_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS0_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS0_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS0_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS0_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address0_Low register */
#define XGMAC_MAC_ADDRESS0_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS0_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address1_High register */
#define XGMAC_MAC_ADDRESS1_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS1_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS1_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS1_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS1_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS1_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS1_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS1_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS1_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS1_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address1_Low register */
#define XGMAC_MAC_ADDRESS1_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS1_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address2_High register */
#define XGMAC_MAC_ADDRESS2_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS2_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS2_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS2_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS2_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS2_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS2_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS2_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS2_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS2_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address2_Low register */
#define XGMAC_MAC_ADDRESS2_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS2_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address3_High register */
#define XGMAC_MAC_ADDRESS3_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS3_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS3_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS3_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS3_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS3_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS3_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS3_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS3_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS3_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address3_Low register */
#define XGMAC_MAC_ADDRESS3_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS3_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address4_High register */
#define XGMAC_MAC_ADDRESS4_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS4_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS4_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS4_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS4_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS4_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS4_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS4_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS4_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS4_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address4_Low register */
#define XGMAC_MAC_ADDRESS4_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS4_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address5_High register */
#define XGMAC_MAC_ADDRESS5_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS5_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS5_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS5_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS5_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS5_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS5_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS5_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS5_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS5_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address5_Low register */
#define XGMAC_MAC_ADDRESS5_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS5_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address6_High register */
#define XGMAC_MAC_ADDRESS6_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS6_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS6_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS6_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS6_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS6_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS6_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS6_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS6_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS6_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address6_Low register */
#define XGMAC_MAC_ADDRESS6_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS6_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address7_High register */
#define XGMAC_MAC_ADDRESS7_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS7_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS7_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS7_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS7_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS7_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS7_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS7_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS7_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS7_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address7_Low register */
#define XGMAC_MAC_ADDRESS7_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS7_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address8_High register */
#define XGMAC_MAC_ADDRESS8_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS8_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS8_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS8_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS8_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS8_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS8_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS8_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS8_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS8_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address8_Low register */
#define XGMAC_MAC_ADDRESS8_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS8_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address9_High register */
#define XGMAC_MAC_ADDRESS9_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS9_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS9_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS9_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS9_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS9_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS9_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS9_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS9_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS9_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address9_Low register */
#define XGMAC_MAC_ADDRESS9_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS9_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address10_High register */
#define XGMAC_MAC_ADDRESS10_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS10_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS10_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS10_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS10_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS10_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS10_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS10_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS10_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS10_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address10_Low register */
#define XGMAC_MAC_ADDRESS10_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS10_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address11_High register */
#define XGMAC_MAC_ADDRESS11_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS11_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS11_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS11_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS11_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS11_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS11_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS11_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS11_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS11_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address11_Low register */
#define XGMAC_MAC_ADDRESS11_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS11_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address12_High register */
#define XGMAC_MAC_ADDRESS12_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS12_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS12_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS12_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS12_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS12_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS12_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS12_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS12_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS12_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address12_Low register */
#define XGMAC_MAC_ADDRESS12_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS12_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address13_High register */
#define XGMAC_MAC_ADDRESS13_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS13_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS13_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS13_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS13_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS13_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS13_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS13_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS13_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS13_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address13_Low register */
#define XGMAC_MAC_ADDRESS13_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS13_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address14_High register */
#define XGMAC_MAC_ADDRESS14_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS14_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS14_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS14_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS14_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS14_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS14_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS14_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS14_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS14_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address14_Low register */
#define XGMAC_MAC_ADDRESS14_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS14_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address15_High register */
#define XGMAC_MAC_ADDRESS15_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS15_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS15_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS15_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS15_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS15_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS15_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS15_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS15_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS15_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address15_Low register */
#define XGMAC_MAC_ADDRESS15_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS15_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address16_High register */
#define XGMAC_MAC_ADDRESS16_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS16_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS16_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS16_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS16_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS16_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS16_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS16_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS16_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS16_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address16_Low register */
#define XGMAC_MAC_ADDRESS16_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS16_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address17_High register */
#define XGMAC_MAC_ADDRESS17_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS17_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS17_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS17_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS17_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS17_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS17_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS17_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS17_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS17_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address17_Low register */
#define XGMAC_MAC_ADDRESS17_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS17_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address18_High register */
#define XGMAC_MAC_ADDRESS18_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS18_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS18_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS18_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS18_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS18_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS18_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS18_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS18_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS18_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address18_Low register */
#define XGMAC_MAC_ADDRESS18_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS18_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address19_High register */
#define XGMAC_MAC_ADDRESS19_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS19_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS19_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS19_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS19_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS19_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS19_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS19_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS19_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS19_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address19_Low register */
#define XGMAC_MAC_ADDRESS19_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS19_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address20_High register */
#define XGMAC_MAC_ADDRESS20_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS20_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS20_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS20_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS20_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS20_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS20_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS20_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS20_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS20_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address20_Low register */
#define XGMAC_MAC_ADDRESS20_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS20_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address21_High register */
#define XGMAC_MAC_ADDRESS21_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS21_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS21_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS21_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS21_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS21_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS21_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS21_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS21_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS21_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address21_Low register */
#define XGMAC_MAC_ADDRESS21_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS21_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address22_High register */
#define XGMAC_MAC_ADDRESS22_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS22_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS22_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS22_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS22_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS22_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS22_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS22_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS22_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS22_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address22_Low register */
#define XGMAC_MAC_ADDRESS22_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS22_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address23_High register */
#define XGMAC_MAC_ADDRESS23_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS23_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS23_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS23_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS23_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS23_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS23_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS23_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS23_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS23_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address23_Low register */
#define XGMAC_MAC_ADDRESS23_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS23_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address24_High register */
#define XGMAC_MAC_ADDRESS24_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS24_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS24_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS24_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS24_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS24_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS24_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS24_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS24_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS24_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address24_Low register */
#define XGMAC_MAC_ADDRESS24_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS24_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address25_High register */
#define XGMAC_MAC_ADDRESS25_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS25_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS25_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS25_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS25_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS25_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS25_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS25_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS25_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS25_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address25_Low register */
#define XGMAC_MAC_ADDRESS25_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS25_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address26_High register */
#define XGMAC_MAC_ADDRESS26_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS26_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS26_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS26_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS26_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS26_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS26_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS26_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS26_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS26_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address26_Low register */
#define XGMAC_MAC_ADDRESS26_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS26_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address27_High register */
#define XGMAC_MAC_ADDRESS27_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS27_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS27_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS27_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS27_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS27_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS27_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS27_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS27_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS27_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address27_Low register */
#define XGMAC_MAC_ADDRESS27_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS27_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address28_High register */
#define XGMAC_MAC_ADDRESS28_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS28_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS28_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS28_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS28_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS28_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS28_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS28_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS28_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS28_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address28_Low register */
#define XGMAC_MAC_ADDRESS28_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS28_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address29_High register */
#define XGMAC_MAC_ADDRESS29_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS29_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS29_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS29_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS29_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS29_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS29_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS29_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS29_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS29_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address29_Low register */
#define XGMAC_MAC_ADDRESS29_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS29_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address30_High register */
#define XGMAC_MAC_ADDRESS30_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS30_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS30_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS30_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS30_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS30_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS30_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS30_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS30_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS30_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address30_Low register */
#define XGMAC_MAC_ADDRESS30_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS30_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Address31_High register */
#define XGMAC_MAC_ADDRESS31_HIGH_AE_MASK \
        0x80000000U
#define XGMAC_MAC_ADDRESS31_HIGH_AE_POS \
        31U
#define XGMAC_MAC_ADDRESS31_HIGH_SA_MASK \
        0x40000000U
#define XGMAC_MAC_ADDRESS31_HIGH_SA_POS \
        30U
#define XGMAC_MAC_ADDRESS31_HIGH_MBC_MASK \
        0x3F000000U
#define XGMAC_MAC_ADDRESS31_HIGH_MBC_POS \
        24U
#define XGMAC_MAC_ADDRESS31_HIGH_DCS_MASK \
        0x00070000U
#define XGMAC_MAC_ADDRESS31_HIGH_DCS_POS \
        16U
#define XGMAC_MAC_ADDRESS31_HIGH_ADDRHI_MASK \
        0x0000FFFFU
#define XGMAC_MAC_ADDRESS31_HIGH_ADDRHI_POS \
        0U

/* Bit fields of MAC_Address31_Low register */
#define XGMAC_MAC_ADDRESS31_LOW_ADDRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ADDRESS31_LOW_ADDRLO_POS \
        0U

/* Bit fields of MAC_Indir_Access_Ctrl register */
#define XGMAC_MAC_INDIR_ACCESS_CTRL_SNPS_R_MASK \
        0x80000000U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_SNPS_R_POS \
        31U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_MSEL_MASK \
        0x3C000000U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_MSEL_POS \
        26U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_AOFF_MASK \
        0x0000FF00U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_AOFF_POS \
        8U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_AUTO_MASK \
        0x00000020U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_AUTO_POS \
        5U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_COM_MASK \
        0x00000002U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_COM_POS \
        1U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_OB_MASK \
        0x00000001U
#define XGMAC_MAC_INDIR_ACCESS_CTRL_OB_POS \
        0U

/* Bit fields of MAC_Indir_Access_Data register */
#define XGMAC_MAC_INDIR_ACCESS_DATA_DATA_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_INDIR_ACCESS_DATA_DATA_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg0 register */
#define XGMAC_MAC_DCHSEL_INDREG0_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG0_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg1 register */
#define XGMAC_MAC_DCHSEL_INDREG1_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG1_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg10 register */
#define XGMAC_MAC_DCHSEL_INDREG10_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG10_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg11 register */
#define XGMAC_MAC_DCHSEL_INDREG11_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG11_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg12 register */
#define XGMAC_MAC_DCHSEL_INDREG12_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG12_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg13 register */
#define XGMAC_MAC_DCHSEL_INDREG13_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG13_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg14 register */
#define XGMAC_MAC_DCHSEL_INDREG14_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG14_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg15 register */
#define XGMAC_MAC_DCHSEL_INDREG15_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG15_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg16 register */
#define XGMAC_MAC_DCHSEL_INDREG16_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG16_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg17 register */
#define XGMAC_MAC_DCHSEL_INDREG17_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG17_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg18 register */
#define XGMAC_MAC_DCHSEL_INDREG18_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG18_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg19 register */
#define XGMAC_MAC_DCHSEL_INDREG19_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG19_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg2 register */
#define XGMAC_MAC_DCHSEL_INDREG2_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG2_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg20 register */
#define XGMAC_MAC_DCHSEL_INDREG20_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG20_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg21 register */
#define XGMAC_MAC_DCHSEL_INDREG21_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG21_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg22 register */
#define XGMAC_MAC_DCHSEL_INDREG22_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG22_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg23 register */
#define XGMAC_MAC_DCHSEL_INDREG23_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG23_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg24 register */
#define XGMAC_MAC_DCHSEL_INDREG24_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG24_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg25 register */
#define XGMAC_MAC_DCHSEL_INDREG25_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG25_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg26 register */
#define XGMAC_MAC_DCHSEL_INDREG26_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG26_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg27 register */
#define XGMAC_MAC_DCHSEL_INDREG27_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG27_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg28 register */
#define XGMAC_MAC_DCHSEL_INDREG28_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG28_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg29 register */
#define XGMAC_MAC_DCHSEL_INDREG29_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG29_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg3 register */
#define XGMAC_MAC_DCHSEL_INDREG3_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG3_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg30 register */
#define XGMAC_MAC_DCHSEL_INDREG30_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG30_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg31 register */
#define XGMAC_MAC_DCHSEL_INDREG31_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG31_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg4 register */
#define XGMAC_MAC_DCHSEL_INDREG4_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG4_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg5 register */
#define XGMAC_MAC_DCHSEL_INDREG5_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG5_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg6 register */
#define XGMAC_MAC_DCHSEL_INDREG6_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG6_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg7 register */
#define XGMAC_MAC_DCHSEL_INDREG7_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG7_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg8 register */
#define XGMAC_MAC_DCHSEL_INDREG8_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG8_XDCS_POS \
        0U

/* Bit fields of MAC_DChSel_IndReg9 register */
#define XGMAC_MAC_DCHSEL_INDREG9_XDCS_MASK \
        0x000000FFU
#define XGMAC_MAC_DCHSEL_INDREG9_XDCS_POS \
        0U

/* Bit fields of MMC_Control register */
#define XGMAC_MMC_CONTROL_CNTPRST_MASK \
        0x00000080U
#define XGMAC_MMC_CONTROL_CNTPRST_POS \
        7U
#define XGMAC_MMC_CONTROL_MCT_MASK \
        0x00000030U
#define XGMAC_MMC_CONTROL_MCT_POS \
        4U
#define XGMAC_MMC_CONTROL_MCF_MASK \
        0x00000008U
#define XGMAC_MMC_CONTROL_MCF_POS \
        3U
#define XGMAC_MMC_CONTROL_RSTONRD_MASK \
        0x00000004U
#define XGMAC_MMC_CONTROL_RSTONRD_POS \
        2U
#define XGMAC_MMC_CONTROL_CNTSTOPRO_MASK \
        0x00000002U
#define XGMAC_MMC_CONTROL_CNTSTOPRO_POS \
        1U
#define XGMAC_MMC_CONTROL_CNTRST_MASK \
        0x00000001U
#define XGMAC_MMC_CONTROL_CNTRST_POS \
        0U

/* Bit fields of MMC_Rx_Interrupt register */
#define XGMAC_MMC_RX_INTERRUPT_RXPRMMCIS_MASK \
        0x80000000U
#define XGMAC_MMC_RX_INTERRUPT_RXPRMMCIS_POS \
        31U
#define XGMAC_MMC_RX_INTERRUPT_SGFPIS_MASK \
        0x20000000U
#define XGMAC_MMC_RX_INTERRUPT_SGFPIS_POS \
        29U
#define XGMAC_MMC_RX_INTERRUPT_SGPPIS_MASK \
        0x10000000U
#define XGMAC_MMC_RX_INTERRUPT_SGPPIS_POS \
        28U
#define XGMAC_MMC_RX_INTERRUPT_RXALEPIS_MASK \
        0x08000000U
#define XGMAC_MMC_RX_INTERRUPT_RXALEPIS_POS \
        27U
#define XGMAC_MMC_RX_INTERRUPT_RXLPITRCIS_MASK \
        0x04000000U
#define XGMAC_MMC_RX_INTERRUPT_RXLPITRCIS_POS \
        26U
#define XGMAC_MMC_RX_INTERRUPT_RXLPIUSCIS_MASK \
        0x02000000U
#define XGMAC_MMC_RX_INTERRUPT_RXLPIUSCIS_POS \
        25U
#define XGMAC_MMC_RX_INTERRUPT_RXDISOCGBIS_MASK \
        0x01000000U
#define XGMAC_MMC_RX_INTERRUPT_RXDISOCGBIS_POS \
        24U
#define XGMAC_MMC_RX_INTERRUPT_RXDISPCGBIS_MASK \
        0x00800000U
#define XGMAC_MMC_RX_INTERRUPT_RXDISPCGBIS_POS \
        23U
#define XGMAC_MMC_RX_INTERRUPT_RXWDOGPIS_MASK \
        0x00400000U
#define XGMAC_MMC_RX_INTERRUPT_RXWDOGPIS_POS \
        22U
#define XGMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK \
        0x00200000U
#define XGMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_POS \
        21U
#define XGMAC_MMC_RX_INTERRUPT_RXFOVPIS_MASK \
        0x00100000U
#define XGMAC_MMC_RX_INTERRUPT_RXFOVPIS_POS \
        20U
#define XGMAC_MMC_RX_INTERRUPT_RXPAUSPIS_MASK \
        0x00080000U
#define XGMAC_MMC_RX_INTERRUPT_RXPAUSPIS_POS \
        19U
#define XGMAC_MMC_RX_INTERRUPT_RXORANGEPIS_MASK \
        0x00040000U
#define XGMAC_MMC_RX_INTERRUPT_RXORANGEPIS_POS \
        18U
#define XGMAC_MMC_RX_INTERRUPT_RXLENERPIS_MASK \
        0x00020000U
#define XGMAC_MMC_RX_INTERRUPT_RXLENERPIS_POS \
        17U
#define XGMAC_MMC_RX_INTERRUPT_RXUCGPIS_MASK \
        0x00010000U
#define XGMAC_MMC_RX_INTERRUPT_RXUCGPIS_POS \
        16U
#define XGMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK \
        0x00008000U
#define XGMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_POS \
        15U
#define XGMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK \
        0x00004000U
#define XGMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_POS \
        14U
#define XGMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK \
        0x00002000U
#define XGMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_POS \
        13U
#define XGMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK \
        0x00001000U
#define XGMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_POS \
        12U
#define XGMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK \
        0x00000800U
#define XGMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_POS \
        11U
#define XGMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK \
        0x00000400U
#define XGMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_POS \
        10U
#define XGMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK \
        0x00000200U
#define XGMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_POS \
        9U
#define XGMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK \
        0x00000100U
#define XGMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_POS \
        8U
#define XGMAC_MMC_RX_INTERRUPT_RXJABERPIS_MASK \
        0x00000080U
#define XGMAC_MMC_RX_INTERRUPT_RXJABERPIS_POS \
        7U
#define XGMAC_MMC_RX_INTERRUPT_RXRUNTPIS_MASK \
        0x00000040U
#define XGMAC_MMC_RX_INTERRUPT_RXRUNTPIS_POS \
        6U
#define XGMAC_MMC_RX_INTERRUPT_RXCRCERPIS_MASK \
        0x00000020U
#define XGMAC_MMC_RX_INTERRUPT_RXCRCERPIS_POS \
        5U
#define XGMAC_MMC_RX_INTERRUPT_RXMCGPIS_MASK \
        0x00000010U
#define XGMAC_MMC_RX_INTERRUPT_RXMCGPIS_POS \
        4U
#define XGMAC_MMC_RX_INTERRUPT_RXBCGPIS_MASK \
        0x00000008U
#define XGMAC_MMC_RX_INTERRUPT_RXBCGPIS_POS \
        3U
#define XGMAC_MMC_RX_INTERRUPT_RXGOCTIS_MASK \
        0x00000004U
#define XGMAC_MMC_RX_INTERRUPT_RXGOCTIS_POS \
        2U
#define XGMAC_MMC_RX_INTERRUPT_RXGBOCTIS_MASK \
        0x00000002U
#define XGMAC_MMC_RX_INTERRUPT_RXGBOCTIS_POS \
        1U
#define XGMAC_MMC_RX_INTERRUPT_RXGBPKTIS_MASK \
        0x00000001U
#define XGMAC_MMC_RX_INTERRUPT_RXGBPKTIS_POS \
        0U

/* Bit fields of MMC_Tx_Interrupt register */
#define XGMAC_MMC_TX_INTERRUPT_TXPRMMCIS_MASK \
        0x80000000U
#define XGMAC_MMC_TX_INTERRUPT_TXPRMMCIS_POS \
        31U
#define XGMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK \
        0x04000000U
#define XGMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_POS \
        26U
#define XGMAC_MMC_TX_INTERRUPT_TXCARERPIS_MASK \
        0x02000000U
#define XGMAC_MMC_TX_INTERRUPT_TXCARERPIS_POS \
        25U
#define XGMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK \
        0x01000000U
#define XGMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_POS \
        24U
#define XGMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK \
        0x00800000U
#define XGMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_POS \
        23U
#define XGMAC_MMC_TX_INTERRUPT_TXDEFPIS_MASK \
        0x00400000U
#define XGMAC_MMC_TX_INTERRUPT_TXDEFPIS_POS \
        22U
#define XGMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK \
        0x00200000U
#define XGMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_POS \
        21U
#define XGMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK \
        0x00100000U
#define XGMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_POS \
        20U
#define XGMAC_MMC_TX_INTERRUPT_TXLPITRCIS_MASK \
        0x00080000U
#define XGMAC_MMC_TX_INTERRUPT_TXLPITRCIS_POS \
        19U
#define XGMAC_MMC_TX_INTERRUPT_TXLPIUSCIS_MASK \
        0x00040000U
#define XGMAC_MMC_TX_INTERRUPT_TXLPIUSCIS_POS \
        18U
#define XGMAC_MMC_TX_INTERRUPT_TXVLANGPIS_MASK \
        0x00020000U
#define XGMAC_MMC_TX_INTERRUPT_TXVLANGPIS_POS \
        17U
#define XGMAC_MMC_TX_INTERRUPT_TXPAUSPIS_MASK \
        0x00010000U
#define XGMAC_MMC_TX_INTERRUPT_TXPAUSPIS_POS \
        16U
#define XGMAC_MMC_TX_INTERRUPT_TXGPKTIS_MASK \
        0x00008000U
#define XGMAC_MMC_TX_INTERRUPT_TXGPKTIS_POS \
        15U
#define XGMAC_MMC_TX_INTERRUPT_TXGOCTIS_MASK \
        0x00004000U
#define XGMAC_MMC_TX_INTERRUPT_TXGOCTIS_POS \
        14U
#define XGMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK \
        0x00002000U
#define XGMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_POS \
        13U
#define XGMAC_MMC_TX_INTERRUPT_TXBCGBPIS_MASK \
        0x00001000U
#define XGMAC_MMC_TX_INTERRUPT_TXBCGBPIS_POS \
        12U
#define XGMAC_MMC_TX_INTERRUPT_TXMCGBPIS_MASK \
        0x00000800U
#define XGMAC_MMC_TX_INTERRUPT_TXMCGBPIS_POS \
        11U
#define XGMAC_MMC_TX_INTERRUPT_TXUCGBPIS_MASK \
        0x00000400U
#define XGMAC_MMC_TX_INTERRUPT_TXUCGBPIS_POS \
        10U
#define XGMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK \
        0x00000200U
#define XGMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_POS \
        9U
#define XGMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK \
        0x00000100U
#define XGMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_POS \
        8U
#define XGMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK \
        0x00000080U
#define XGMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_POS \
        7U
#define XGMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK \
        0x00000040U
#define XGMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_POS \
        6U
#define XGMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK \
        0x00000020U
#define XGMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_POS \
        5U
#define XGMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK \
        0x00000010U
#define XGMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_POS \
        4U
#define XGMAC_MMC_TX_INTERRUPT_TXMCGPIS_MASK \
        0x00000008U
#define XGMAC_MMC_TX_INTERRUPT_TXMCGPIS_POS \
        3U
#define XGMAC_MMC_TX_INTERRUPT_TXBCGPIS_MASK \
        0x00000004U
#define XGMAC_MMC_TX_INTERRUPT_TXBCGPIS_POS \
        2U
#define XGMAC_MMC_TX_INTERRUPT_TXGBPKTIS_MASK \
        0x00000002U
#define XGMAC_MMC_TX_INTERRUPT_TXGBPKTIS_POS \
        1U
#define XGMAC_MMC_TX_INTERRUPT_TXGBOCTIS_MASK \
        0x00000001U
#define XGMAC_MMC_TX_INTERRUPT_TXGBOCTIS_POS \
        0U

/* Bit fields of MMC_Receive_Interrupt_Enable register */
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXALEPIE_MASK \
        0x08000000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXALEPIE_POS \
        27U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXDISOCGBIE_MASK \
        0x01000000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXDISOCGBIE_POS \
        24U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXDISPCGBIE_MASK \
        0x00800000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXDISPCGBIE_POS \
        23U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXWDOGPIE_MASK \
        0x00400000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXWDOGPIE_POS \
        22U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXVLANGBPIE_MASK \
        0x00200000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXVLANGBPIE_POS \
        21U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXFOVPIE_MASK \
        0x00100000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXFOVPIE_POS \
        20U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXPAUSPIE_MASK \
        0x00080000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXPAUSPIE_POS \
        19U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXORANGEPIE_MASK \
        0x00040000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXORANGEPIE_POS \
        18U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXLENERPIE_MASK \
        0x00020000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXLENERPIE_POS \
        17U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXUCGPIE_MASK \
        0x00010000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXUCGPIE_POS \
        16U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX1024TMAXOCTGBPIE_MASK \
        0x00008000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX1024TMAXOCTGBPIE_POS \
        15U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX512T1023OCTGBPIE_MASK \
        0x00004000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX512T1023OCTGBPIE_POS \
        14U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX256T511OCTGBPIE_MASK \
        0x00002000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX256T511OCTGBPIE_POS \
        13U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX128T255OCTGBPIE_MASK \
        0x00001000U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX128T255OCTGBPIE_POS \
        12U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX65T127OCTGBPIE_MASK \
        0x00000800U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX65T127OCTGBPIE_POS \
        11U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX64OCTGBPIE_MASK \
        0x00000400U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RX64OCTGBPIE_POS \
        10U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXOSIZEGPIE_MASK \
        0x00000200U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXOSIZEGPIE_POS \
        9U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXUSIZEGPIE_MASK \
        0x00000100U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXUSIZEGPIE_POS \
        8U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXJABERPIE_MASK \
        0x00000080U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXJABERPIE_POS \
        7U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXRUNTPIE_MASK \
        0x00000040U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXRUNTPIE_POS \
        6U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXCRCERPIE_MASK \
        0x00000020U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXCRCERPIE_POS \
        5U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXMCGPIE_MASK \
        0x00000010U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXMCGPIE_POS \
        4U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXBCGPIE_MASK \
        0x00000008U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXBCGPIE_POS \
        3U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGOCTIE_MASK \
        0x00000004U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGOCTIE_POS \
        2U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGBOCTIE_MASK \
        0x00000002U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGBOCTIE_POS \
        1U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGBPKTIE_MASK \
        0x00000001U
#define XGMAC_MMC_RECEIVE_INTERRUPT_ENABLE_RXGBPKTIE_POS \
        0U

/* Bit fields of MMC_Transmit_Interrupt_Enable register */
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXEXDEFPIE_MASK \
        0x04000000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXEXDEFPIE_POS \
        26U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXCARERPIE_MASK \
        0x02000000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXCARERPIE_POS \
        25U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXEXCOLPIE_MASK \
        0x01000000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXEXCOLPIE_POS \
        24U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXLATCOLPIE_MASK \
        0x00800000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXLATCOLPIE_POS \
        23U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXDEFPIE_MASK \
        0x00400000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXDEFPIE_POS \
        22U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCOLGPIE_MASK \
        0x00200000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCOLGPIE_POS \
        21U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXSCOLGPIE_MASK \
        0x00100000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXSCOLGPIE_POS \
        20U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXVLANGPIE_MASK \
        0x00020000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXVLANGPIE_POS \
        17U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXPAUSPIE_MASK \
        0x00010000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXPAUSPIE_POS \
        16U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGPKTIE_MASK \
        0x00008000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGPKTIE_POS \
        15U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGOCTIE_MASK \
        0x00004000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGOCTIE_POS \
        14U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXUFLOWERPIE_MASK \
        0x00002000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXUFLOWERPIE_POS \
        13U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXBCGBPIE_MASK \
        0x00001000U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXBCGBPIE_POS \
        12U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCGBPIE_MASK \
        0x00000800U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCGBPIE_POS \
        11U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXUCGBPIE_MASK \
        0x00000400U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXUCGBPIE_POS \
        10U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX1024TMAXOCTGBPIE_MASK \
        0x00000200U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX1024TMAXOCTGBPIE_POS \
        9U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX512T1023OCTGBPIE_MASK \
        0x00000100U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX512T1023OCTGBPIE_POS \
        8U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX256T511OCTGBPIE_MASK \
        0x00000080U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX256T511OCTGBPIE_POS \
        7U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX128T255OCTGBPIE_MASK \
        0x00000040U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX128T255OCTGBPIE_POS \
        6U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX65T127OCTGBPIE_MASK \
        0x00000020U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX65T127OCTGBPIE_POS \
        5U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX64OCTGBPIE_MASK \
        0x00000010U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TX64OCTGBPIE_POS \
        4U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCGPIE_MASK \
        0x00000008U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXMCGPIE_POS \
        3U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXBCGPIE_MASK \
        0x00000004U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXBCGPIE_POS \
        2U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGBPKTIE_MASK \
        0x00000002U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGBPKTIE_POS \
        1U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGBOCTIE_MASK \
        0x00000001U
#define XGMAC_MMC_TRANSMIT_INTERRUPT_ENABLE_TXGBOCTIE_POS \
        0U

/* Bit fields of Tx_Octet_Count_Good_Bad_Low register */
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_LOW_TXOCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_LOW_TXOCTGBLO_POS \
        0U

/* Bit fields of Tx_Octet_Count_Good_Bad_High register */
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_HIGH_TXOCTGBHI_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_OCTET_COUNT_GOOD_BAD_HIGH_TXOCTGBHI_POS \
        0U

/* Bit fields of Tx_Packet_Count_Good_Bad_Low register */
#define XGMAC_TX_PACKET_COUNT_GOOD_BAD_LOW_TXPKTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_PACKET_COUNT_GOOD_BAD_LOW_TXPKTGBLO_POS \
        0U

/* Bit fields of Tx_Broadcast_Packets_Good_Low register */
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_LOW_TXBCASTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_LOW_TXBCASTGLO_POS \
        0U

/* Bit fields of Tx_Multicast_Packets_Good_Low register */
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_LOW_TXMCASTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_LOW_TXMCASTGLO_POS \
        0U

/* Bit fields of Tx_64Octets_Packets_Good_Bad_Low register */
#define XGMAC_TX_64OCTETS_PACKETS_GOOD_BAD_LOW_TX64OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_64OCTETS_PACKETS_GOOD_BAD_LOW_TX64OCTGBLO_POS \
        0U

/* Bit fields of Tx_65To127Octets_Packets_Good_Bad_Low register */
#define XGMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW_TX65_127OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW_TX65_127OCTGBLO_POS \
        0U

/* Bit fields of Tx_128To255Octets_Packets_Good_Bad_Low register */
#define XGMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW_TX128_255OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW_TX128_255OCTGBLO_POS \
        0U

/* Bit fields of Tx_256To511Octets_Packets_Good_Bad_Low register */
#define XGMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW_TX256_511OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW_TX256_511OCTGBLO_POS \
        0U

/* Bit fields of Tx_512To1023Octets_Packets_Good_Bad_Low register */
#define XGMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW_TX512_1023OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW_TX512_1023OCTGBLO_POS \
        0U

/* Bit fields of Tx_1024ToMaxOctets_Packets_Good_Bad_Low register */
#define XGMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW_TX1024_MAXOCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW_TX1024_MAXOCTGBLO_POS \
        0U

/* Bit fields of Tx_Unicast_Packets_Good_Bad_Low register */
#define XGMAC_TX_UNICAST_PACKETS_GOOD_BAD_LOW_TXUCASTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_UNICAST_PACKETS_GOOD_BAD_LOW_TXUCASTGBLO_POS \
        0U

/* Bit fields of Tx_Multicast_Packets_Good_Bad_Low register */
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_BAD_LOW_TXMCASTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_MULTICAST_PACKETS_GOOD_BAD_LOW_TXMCASTGBLO_POS \
        0U

/* Bit fields of Tx_Broadcast_Packets_Good_Bad_Low register */
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_BAD_LOW_TXBCASTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_BROADCAST_PACKETS_GOOD_BAD_LOW_TXBCASTGBLO_POS \
        0U

/* Bit fields of Tx_Underflow_Error_Packets_Low register */
#define XGMAC_TX_UNDERFLOW_ERROR_PACKETS_LOW_TXUNDRFLWLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_UNDERFLOW_ERROR_PACKETS_LOW_TXUNDRFLWLO_POS \
        0U

/* Bit fields of Tx_Octet_Count_Good_Low register */
#define XGMAC_TX_OCTET_COUNT_GOOD_LOW_TXOCTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_OCTET_COUNT_GOOD_LOW_TXOCTGLO_POS \
        0U

/* Bit fields of Tx_Octet_Count_Good_High register */
#define XGMAC_TX_OCTET_COUNT_GOOD_HIGH_TXOCTGHI_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_OCTET_COUNT_GOOD_HIGH_TXOCTGHI_POS \
        0U

/* Bit fields of Tx_Packet_Count_Good_Low register */
#define XGMAC_TX_PACKET_COUNT_GOOD_LOW_TXPKTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_PACKET_COUNT_GOOD_LOW_TXPKTGLO_POS \
        0U

/* Bit fields of Tx_Pause_Packets_Low register */
#define XGMAC_TX_PAUSE_PACKETS_LOW_TXPAUSEGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_PAUSE_PACKETS_LOW_TXPAUSEGLO_POS \
        0U

/* Bit fields of Tx_VLAN_Packets_Good_Low register */
#define XGMAC_TX_VLAN_PACKETS_GOOD_LOW_TXVLANGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_VLAN_PACKETS_GOOD_LOW_TXVLANGLO_POS \
        0U

/* Bit fields of Rx_Packet_Count_Good_Bad_Low register */
#define XGMAC_RX_PACKET_COUNT_GOOD_BAD_LOW_RXPKTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_PACKET_COUNT_GOOD_BAD_LOW_RXPKTGBLO_POS \
        0U

/* Bit fields of Rx_Octet_Count_Good_Bad_Low register */
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_LOW_RXOCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_LOW_RXOCTGBLO_POS \
        0U

/* Bit fields of Rx_Octet_Count_Good_Bad_High register */
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_HIGH_RXOCTGBHI_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OCTET_COUNT_GOOD_BAD_HIGH_RXOCTGBHI_POS \
        0U

/* Bit fields of Rx_Octet_Count_Good_Low register */
#define XGMAC_RX_OCTET_COUNT_GOOD_LOW_RXOCTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OCTET_COUNT_GOOD_LOW_RXOCTGLO_POS \
        0U

/* Bit fields of Rx_Octet_Count_Good_High register */
#define XGMAC_RX_OCTET_COUNT_GOOD_HIGH_RXOCTGHI_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OCTET_COUNT_GOOD_HIGH_RXOCTGHI_POS \
        0U

/* Bit fields of Rx_Broadcast_Packets_Good_Low register */
#define XGMAC_RX_BROADCAST_PACKETS_GOOD_LOW_RXBCASTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_BROADCAST_PACKETS_GOOD_LOW_RXBCASTGLO_POS \
        0U

/* Bit fields of Rx_Multicast_Packets_Good_Low register */
#define XGMAC_RX_MULTICAST_PACKETS_GOOD_LOW_RXMCASTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_MULTICAST_PACKETS_GOOD_LOW_RXMCASTGLO_POS \
        0U

/* Bit fields of Rx_CRC_Error_Packets_Low register */
#define XGMAC_RX_CRC_ERROR_PACKETS_LOW_RXCRCERLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_CRC_ERROR_PACKETS_LOW_RXCRCERLO_POS \
        0U

/* Bit fields of Rx_Runt_Error_Packets register */
#define XGMAC_RX_RUNT_ERROR_PACKETS_RXRUNTER_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_RUNT_ERROR_PACKETS_RXRUNTER_POS \
        0U

/* Bit fields of Rx_Jabber_Error_Packets register */
#define XGMAC_RX_JABBER_ERROR_PACKETS_RXJABERER_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_JABBER_ERROR_PACKETS_RXJABERER_POS \
        0U

/* Bit fields of Rx_Undersize_Packets_Good register */
#define XGMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUSIZEG_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUSIZEG_POS \
        0U

/* Bit fields of Rx_Oversize_Packets_Good register */
#define XGMAC_RX_OVERSIZE_PACKETS_GOOD_RXOSIZEG_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OVERSIZE_PACKETS_GOOD_RXOSIZEG_POS \
        0U

/* Bit fields of Rx_64Octets_Packets_Good_Bad_Low register */
#define XGMAC_RX_64OCTETS_PACKETS_GOOD_BAD_LOW_RX64OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_64OCTETS_PACKETS_GOOD_BAD_LOW_RX64OCTGBLO_POS \
        0U

/* Bit fields of Rx_65To127Octets_Packets_Good_Bad_Low register */
#define XGMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW_RX65_127OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_LOW_RX65_127OCTGBLO_POS \
        0U

/* Bit fields of Rx_128To255Octets_Packets_Good_Bad_Low register */
#define XGMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW_RX128_255OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_LOW_RX128_255OCTGBLO_POS \
        0U

/* Bit fields of Rx_256To511Octets_Packets_Good_Bad_Low register */
#define XGMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW_RX256_511OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_LOW_RX256_511OCTGBLO_POS \
        0U

/* Bit fields of Rx_512To1023Octets_Packets_Good_Bad_Low register */
#define XGMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW_RX512_1023OCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_LOW_RX512_1023OCTGBLO_POS \
        0U

/* Bit fields of Rx_1024ToMaxOctets_Packets_Good_Bad_Low register */
#define XGMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW_RX1024_MAXOCTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_LOW_RX1024_MAXOCTGBLO_POS \
        0U

/* Bit fields of Rx_Unicast_Packets_Good_Low register */
#define XGMAC_RX_UNICAST_PACKETS_GOOD_LOW_RXUCASTGLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_UNICAST_PACKETS_GOOD_LOW_RXUCASTGLO_POS \
        0U

/* Bit fields of Rx_Length_Error_Packets_Low register */
#define XGMAC_RX_LENGTH_ERROR_PACKETS_LOW_RXLENERRLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_LENGTH_ERROR_PACKETS_LOW_RXLENERRLO_POS \
        0U

/* Bit fields of Rx_OutofRange_Packets_Low register */
#define XGMAC_RX_OUTOFRANGE_PACKETS_LOW_RXORANGELO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_OUTOFRANGE_PACKETS_LOW_RXORANGELO_POS \
        0U

/* Bit fields of Rx_Pause_Packets_Low register */
#define XGMAC_RX_PAUSE_PACKETS_LOW_RXPAUSELO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_PAUSE_PACKETS_LOW_RXPAUSELO_POS \
        0U

/* Bit fields of Rx_FIFOOverflow_Packets_Low register */
#define XGMAC_RX_FIFOOVERFLOW_PACKETS_LOW_RXFOVFLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_FIFOOVERFLOW_PACKETS_LOW_RXFOVFLO_POS \
        0U

/* Bit fields of Rx_VLAN_Packets_Good_Bad_Low register */
#define XGMAC_RX_VLAN_PACKETS_GOOD_BAD_LOW_RXVLANGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_VLAN_PACKETS_GOOD_BAD_LOW_RXVLANGBLO_POS \
        0U

/* Bit fields of Rx_Watchdog_Error_Packets register */
#define XGMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDOGERR_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDOGERR_POS \
        0U

/* Bit fields of Rx_Discard_Packets_Good_Bad_Low register */
#define XGMAC_RX_DISCARD_PACKETS_GOOD_BAD_LOW_RXDPCNTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_DISCARD_PACKETS_GOOD_BAD_LOW_RXDPCNTGBLO_POS \
        0U

/* Bit fields of Rx_Discard_Octets_Good_Bad_Low register */
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_LOW_RXDOCNTGBLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_LOW_RXDOCNTGBLO_POS \
        0U

/* Bit fields of Rx_Discard_Octets_Good_Bad_High register */
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_HIGH_RXDOCNTGBHI_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_DISCARD_OCTETS_GOOD_BAD_HIGH_RXDOCNTGBHI_POS \
        0U

/* Bit fields of Rx_Alignment_Error_Packets register */
#define XGMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALIGNERR_MASK \
        0xFFFFFFFFU
#define XGMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALIGNERR_POS \
        0U

/* Bit fields of MMC_FPE_Tx_Interrupt register */
#define XGMAC_MMC_FPE_TX_INTERRUPT_GOCIS_MASK \
        0x00000004U
#define XGMAC_MMC_FPE_TX_INTERRUPT_GOCIS_POS \
        2U
#define XGMAC_MMC_FPE_TX_INTERRUPT_HRCIS_MASK \
        0x00000002U
#define XGMAC_MMC_FPE_TX_INTERRUPT_HRCIS_POS \
        1U
#define XGMAC_MMC_FPE_TX_INTERRUPT_FCIS_MASK \
        0x00000001U
#define XGMAC_MMC_FPE_TX_INTERRUPT_FCIS_POS \
        0U

/* Bit fields of MMC_FPE_Tx_Interrupt_Mask register */
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_GOCIM_MASK \
        0x00000004U
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_GOCIM_POS \
        2U
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK \
        0x00000002U
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_POS \
        1U
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK \
        0x00000001U
#define XGMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_POS \
        0U

/* Bit fields of MMC_Tx_FPE_Fragment_Cntr register */
#define XGMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_POS \
        0U

/* Bit fields of MMC_Tx_Hold_Req_Cntr register */
#define XGMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_POS \
        0U

/* Bit fields of MMC_Tx_Gate_Orun_Cntr_Low register */
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_LOW_TXGOCL_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_LOW_TXGOCL_POS \
        0U

/* Bit fields of MMC_Tx_Gate_Orun_Cntr_High register */
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_HIGH_TXGOCH_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_TX_GATE_ORUN_CNTR_HIGH_TXGOCH_POS \
        0U

/* Bit fields of MMC_FPE_Rx_Interrupt register */
#define XGMAC_MMC_FPE_RX_INTERRUPT_FCIS_MASK \
        0x00000008U
#define XGMAC_MMC_FPE_RX_INTERRUPT_FCIS_POS \
        3U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK \
        0x00000004U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_POS \
        2U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PSECIS_MASK \
        0x00000002U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PSECIS_POS \
        1U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PAECIS_MASK \
        0x00000001U
#define XGMAC_MMC_FPE_RX_INTERRUPT_PAECIS_POS \
        0U

/* Bit fields of MMC_FPE_Rx_Interrupt_Mask register */
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK \
        0x00000008U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_POS \
        3U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK \
        0x00000004U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_POS \
        2U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK \
        0x00000002U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_POS \
        1U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK \
        0x00000001U
#define XGMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_POS \
        0U

/* Bit fields of MMC_Rx_Packet_Assembly_Err_Cntr register */
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_POS \
        0U

/* Bit fields of MMC_Rx_Packet_SMD_Err_Cntr register */
#define XGMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_POS \
        0U

/* Bit fields of MMC_Rx_Packet_Assembly_OK_Cntr register */
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_POS \
        0U

/* Bit fields of MMC_Rx_FPE_Fragment_Cntr register */
#define XGMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK \
        0xFFFFFFFFU
#define XGMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_POS \
        0U

/* Bit fields of Tx_Single_Collision_Good_Packets register */
#define XGMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_POS \
        0U

/* Bit fields of Tx_Multiple_Collision_Good_Packets register */
#define XGMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_POS \
        0U

/* Bit fields of Tx_Deferred_Packets register */
#define XGMAC_TX_DEFERRED_PACKETS_TXDEFRD_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_DEFERRED_PACKETS_TXDEFRD_POS \
        0U

/* Bit fields of Tx_Late_Collision_Packets register */
#define XGMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_POS \
        0U

/* Bit fields of Tx_Excessive_Collision_Packets register */
#define XGMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_POS \
        0U

/* Bit fields of Tx_Carrier_Error_Packets register */
#define XGMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_POS \
        0U

/* Bit fields of Tx_Excessive_Deferral_Error register */
#define XGMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK \
        0xFFFFFFFFU
#define XGMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_POS \
        0U

/* Bit fields of MMC_IPC_Rx_Interrupt_Mask register */
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPEROIM_MASK \
        0x20000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPEROIM_POS \
        29U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPGOIM_MASK \
        0x10000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPGOIM_POS \
        28U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPEROIM_MASK \
        0x08000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPEROIM_POS \
        27U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPGOIM_MASK \
        0x04000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPGOIM_POS \
        26U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPEROIM_MASK \
        0x02000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPEROIM_POS \
        25U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPGOIM_MASK \
        0x01000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPGOIM_POS \
        24U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6NOPAYOIM_MASK \
        0x00800000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6NOPAYOIM_POS \
        23U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6HEROIM_MASK \
        0x00400000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6HEROIM_POS \
        22U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6GOIM_MASK \
        0x00200000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6GOIM_POS \
        21U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4UDSBLOIM_MASK \
        0x00100000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4UDSBLOIM_POS \
        20U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4FRAGOIM_MASK \
        0x00080000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4FRAGOIM_POS \
        19U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4NOPAYOIM_MASK \
        0x00040000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4NOPAYOIM_POS \
        18U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4HEROIM_MASK \
        0x00020000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4HEROIM_POS \
        17U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4GOIM_MASK \
        0x00010000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4GOIM_POS \
        16U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPERPIM_MASK \
        0x00002000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPERPIM_POS \
        13U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPGPIM_MASK \
        0x00001000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXICMPGPIM_POS \
        12U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPERPIM_MASK \
        0x00000800U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPERPIM_POS \
        11U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPGPIM_MASK \
        0x00000400U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXTCPGPIM_POS \
        10U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPERPIM_MASK \
        0x00000200U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPERPIM_POS \
        9U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPGPIM_MASK \
        0x00000100U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXUDPGPIM_POS \
        8U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6NOPAYPIM_MASK \
        0x00000080U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6NOPAYPIM_POS \
        7U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6HERPIM_MASK \
        0x00000040U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6HERPIM_POS \
        6U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6GPIM_MASK \
        0x00000020U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV6GPIM_POS \
        5U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4UDSBLPIM_MASK \
        0x00000010U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4UDSBLPIM_POS \
        4U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4FRAGPIM_MASK \
        0x00000008U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4FRAGPIM_POS \
        3U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4NOPAYPIM_MASK \
        0x00000004U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4NOPAYPIM_POS \
        2U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4HERPIM_MASK \
        0x00000002U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4HERPIM_POS \
        1U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4GPIM_MASK \
        0x00000001U
#define XGMAC_MMC_IPC_RX_INTERRUPT_MASK_RXIPV4GPIM_POS \
        0U

/* Bit fields of MMC_IPC_Rx_Interrupt register */
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPEROIS_MASK \
        0x20000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPEROIS_POS \
        29U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPGOIS_MASK \
        0x10000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPGOIS_POS \
        28U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPEROIS_MASK \
        0x08000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPEROIS_POS \
        27U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPGOIS_MASK \
        0x04000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPGOIS_POS \
        26U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPEROIS_MASK \
        0x02000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPEROIS_POS \
        25U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPGOIS_MASK \
        0x01000000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPGOIS_POS \
        24U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6NOPAYOIS_MASK \
        0x00800000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6NOPAYOIS_POS \
        23U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6HEROIS_MASK \
        0x00400000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6HEROIS_POS \
        22U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6GOIS_MASK \
        0x00200000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6GOIS_POS \
        21U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4UDSBLOIS_MASK \
        0x00100000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4UDSBLOIS_POS \
        20U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4FRAGOIS_MASK \
        0x00080000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4FRAGOIS_POS \
        19U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4NOPAYOIS_MASK \
        0x00040000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4NOPAYOIS_POS \
        18U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4HEROIS_MASK \
        0x00020000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4HEROIS_POS \
        17U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4GOIS_MASK \
        0x00010000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4GOIS_POS \
        16U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPERPIS_MASK \
        0x00002000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPERPIS_POS \
        13U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPGPIS_MASK \
        0x00001000U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXICMPGPIS_POS \
        12U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPERPIS_MASK \
        0x00000800U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPERPIS_POS \
        11U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPGPIS_MASK \
        0x00000400U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXTCPGPIS_POS \
        10U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPERPIS_MASK \
        0x00000200U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPERPIS_POS \
        9U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPGPIS_MASK \
        0x00000100U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXUDPGPIS_POS \
        8U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6NOPAYPIS_MASK \
        0x00000080U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6NOPAYPIS_POS \
        7U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6HERPIS_MASK \
        0x00000040U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6HERPIS_POS \
        6U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6GPIS_MASK \
        0x00000020U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV6GPIS_POS \
        5U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4UDSBLPIS_MASK \
        0x00000010U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4UDSBLPIS_POS \
        4U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4FRAGPIS_MASK \
        0x00000008U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4FRAGPIS_POS \
        3U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4NOPAYPIS_MASK \
        0x00000004U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4NOPAYPIS_POS \
        2U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4HERPIS_MASK \
        0x00000002U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4HERPIS_POS \
        1U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4GPIS_MASK \
        0x00000001U
#define XGMAC_MMC_IPC_RX_INTERRUPT_RXIPV4GPIS_POS \
        0U

/* Bit fields of RxIPv4_Good_Packets_Low register */
#define XGMAC_RXIPV4_GOOD_PACKETS_LOW_RXIPV4GDPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_GOOD_PACKETS_LOW_RXIPV4GDPKTLO_POS \
        0U

/* Bit fields of RxIPv4_Header_Error_Packets_Low register */
#define XGMAC_RXIPV4_HEADER_ERROR_PACKETS_LOW_RXIPV4HDRERRPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_HEADER_ERROR_PACKETS_LOW_RXIPV4HDRERRPKTLO_POS \
        0U

/* Bit fields of RxIPv4_No_Payload_Packets_Low register */
#define XGMAC_RXIPV4_NO_PAYLOAD_PACKETS_LOW_RXIPV4NOPAYPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_NO_PAYLOAD_PACKETS_LOW_RXIPV4NOPAYPKTLO_POS \
        0U

/* Bit fields of RxIPv4_Fragmented_Packets_Low register */
#define XGMAC_RXIPV4_FRAGMENTED_PACKETS_LOW_RXIPV4FRAGPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_FRAGMENTED_PACKETS_LOW_RXIPV4FRAGPKTLO_POS \
        0U

/* Bit fields of RxIPv4_UDP_Checksum_Disabled_Packets_Low register */
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_LOW_RXIPV4UDSBLPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_LOW_RXIPV4UDSBLPKTLO_POS \
        0U

/* Bit fields of RxIPv6_Good_Packets_Low register */
#define XGMAC_RXIPV6_GOOD_PACKETS_LOW_RXIPV6GDPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_GOOD_PACKETS_LOW_RXIPV6GDPKTLO_POS \
        0U

/* Bit fields of RxIPv6_Header_Error_Packets_Low register */
#define XGMAC_RXIPV6_HEADER_ERROR_PACKETS_LOW_RXIPV6HDRERRPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_HEADER_ERROR_PACKETS_LOW_RXIPV6HDRERRPKTLO_POS \
        0U

/* Bit fields of RxIPv6_No_Payload_Packets_Low register */
#define XGMAC_RXIPV6_NO_PAYLOAD_PACKETS_LOW_RXIPV6NOPAYPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_NO_PAYLOAD_PACKETS_LOW_RXIPV6NOPAYPKTLO_POS \
        0U

/* Bit fields of RxUDP_Good_Packets_Low register */
#define XGMAC_RXUDP_GOOD_PACKETS_LOW_RXUDPGDPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXUDP_GOOD_PACKETS_LOW_RXUDPGDPKTLO_POS \
        0U

/* Bit fields of RxUDP_Error_Packets_Low register */
#define XGMAC_RXUDP_ERROR_PACKETS_LOW_RXUDPERRPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXUDP_ERROR_PACKETS_LOW_RXUDPERRPKTLO_POS \
        0U

/* Bit fields of RxTCP_Good_Packets_Low register */
#define XGMAC_RXTCP_GOOD_PACKETS_LOW_RXTCPGDPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXTCP_GOOD_PACKETS_LOW_RXTCPGDPKTLO_POS \
        0U

/* Bit fields of RxTCP_Error_Packets_Low register */
#define XGMAC_RXTCP_ERROR_PACKETS_LOW_RXTCPERRPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXTCP_ERROR_PACKETS_LOW_RXTCPERRPKTLO_POS \
        0U

/* Bit fields of RxICMP_Good_Packets_Low register */
#define XGMAC_RXICMP_GOOD_PACKETS_LOW_RXICMPGDPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXICMP_GOOD_PACKETS_LOW_RXICMPGDPKTLO_POS \
        0U

/* Bit fields of RxICMP_Error_Packets_Low register */
#define XGMAC_RXICMP_ERROR_PACKETS_LOW_RXICMPERRPKTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXICMP_ERROR_PACKETS_LOW_RXICMPERRPKTLO_POS \
        0U

/* Bit fields of RxIPv4_Good_Octets_Low register */
#define XGMAC_RXIPV4_GOOD_OCTETS_LOW_RXIPV4GDOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_GOOD_OCTETS_LOW_RXIPV4GDOCTLO_POS \
        0U

/* Bit fields of RxIPv4_Header_Error_Octets_Low register */
#define XGMAC_RXIPV4_HEADER_ERROR_OCTETS_LOW_RXIPV4HDRERROCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_HEADER_ERROR_OCTETS_LOW_RXIPV4HDRERROCTLO_POS \
        0U

/* Bit fields of RxIPv4_No_Payload_Octets_Low register */
#define XGMAC_RXIPV4_NO_PAYLOAD_OCTETS_LOW_RXIPV4NOPAYOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_NO_PAYLOAD_OCTETS_LOW_RXIPV4NOPAYOCTLO_POS \
        0U

/* Bit fields of RxIPv4_Fragmented_Octets_Low register */
#define XGMAC_RXIPV4_FRAGMENTED_OCTETS_LOW_RXIPV4FRAGOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_FRAGMENTED_OCTETS_LOW_RXIPV4FRAGOCTLO_POS \
        0U

/* Bit fields of RxIPv4_UDP_Checksum_Disable_Octets_Low register */
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_LOW_RXIPV4UDSBLOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_LOW_RXIPV4UDSBLOCTLO_POS \
        0U

/* Bit fields of RxIPv6_Good_Octets_Low register */
#define XGMAC_RXIPV6_GOOD_OCTETS_LOW_RXIPV6GDOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_GOOD_OCTETS_LOW_RXIPV6GDOCTLO_POS \
        0U

/* Bit fields of RxIPv6_Header_Error_Octets_Low register */
#define XGMAC_RXIPV6_HEADER_ERROR_OCTETS_LOW_RXIPV6HDRERROCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_HEADER_ERROR_OCTETS_LOW_RXIPV6HDRERROCTLO_POS \
        0U

/* Bit fields of RxIPv6_No_Payload_Octets_Low register */
#define XGMAC_RXIPV6_NO_PAYLOAD_OCTETS_LOW_RXIPV6NOPAYOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXIPV6_NO_PAYLOAD_OCTETS_LOW_RXIPV6NOPAYOCTLO_POS \
        0U

/* Bit fields of RxUDP_Good_Octets_Low register */
#define XGMAC_RXUDP_GOOD_OCTETS_LOW_RXUDPGDOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXUDP_GOOD_OCTETS_LOW_RXUDPGDOCTLO_POS \
        0U

/* Bit fields of RxUDP_Error_Octets_Low register */
#define XGMAC_RXUDP_ERROR_OCTETS_LOW_RXUDPERROCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXUDP_ERROR_OCTETS_LOW_RXUDPERROCTLO_POS \
        0U

/* Bit fields of RxTCP_Good_Octets_Low register */
#define XGMAC_RXTCP_GOOD_OCTETS_LOW_RXTCPGDOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXTCP_GOOD_OCTETS_LOW_RXTCPGDOCTLO_POS \
        0U

/* Bit fields of RxTCP_Error_Octets_Low register */
#define XGMAC_RXTCP_ERROR_OCTETS_LOW_RXTCPERROCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXTCP_ERROR_OCTETS_LOW_RXTCPERROCTLO_POS \
        0U

/* Bit fields of RxICMP_Good_Octets_Low register */
#define XGMAC_RXICMP_GOOD_OCTETS_LOW_RXICMPGDOCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXICMP_GOOD_OCTETS_LOW_RXICMPGDOCTLO_POS \
        0U

/* Bit fields of RxICMP_Error_Octets_Low register */
#define XGMAC_RXICMP_ERROR_OCTETS_LOW_RXICMPERROCTLO_MASK \
        0xFFFFFFFFU
#define XGMAC_RXICMP_ERROR_OCTETS_LOW_RXICMPERROCTLO_POS \
        0U

/* Bit fields of MAC_L3_L4_Address_Control register */
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_IDDR_MASK \
        0x0000FF00U
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_IDDR_POS \
        8U
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_TT_MASK \
        0x00000002U
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_TT_POS \
        1U
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_XB_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_ADDRESS_CONTROL_XB_POS \
        0U

/* Bit fields of MAC_L3_L4_Data register */
#define XGMAC_MAC_L3_L4_DATA_IDATA_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_L3_L4_DATA_IDATA_POS \
        0U

/* Bit fields of MAC_L3_L4_Control0 register */
#define XGMAC_MAC_L3_L4_CONTROL0_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL0_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL0_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL0_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL0_L4DPIM0_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL0_L4DPIM0_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL0_L4DPM0_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL0_L4DPM0_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL0_L4SPIM0_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL0_L4SPIM0_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL0_L4SPM0_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL0_L4SPM0_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL0_L4PEN0_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL0_L4PEN0_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL0_L3HDBM0_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL0_L3HDBM0_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL0_L3HSBM0_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL0_L3HSBM0_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL0_L3DAIM0_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL0_L3DAIM0_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL0_L3DAM0_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL0_L3DAM0_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL0_L3SAIM0_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL0_L3SAIM0_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL0_L3SAM0_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL0_L3SAM0_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL0_L3PEN0_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL0_L3PEN0_POS \
        0U

/* Bit fields of MAC_L3_L4_Control1 register */
#define XGMAC_MAC_L3_L4_CONTROL1_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL1_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL1_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL1_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL1_L4DPIM1_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL1_L4DPIM1_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL1_L4DPM1_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL1_L4DPM1_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL1_L4SPIM1_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL1_L4SPIM1_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL1_L4SPM1_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL1_L4SPM1_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL1_L4PEN1_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL1_L4PEN1_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL1_L3HDBM1_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL1_L3HDBM1_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL1_L3HSBM1_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL1_L3HSBM1_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL1_L3DAIM1_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL1_L3DAIM1_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL1_L3DAM1_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL1_L3DAM1_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL1_L3SAIM1_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL1_L3SAIM1_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL1_L3SAM1_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL1_L3SAM1_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL1_L3PEN1_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL1_L3PEN1_POS \
        0U

/* Bit fields of MAC_L3_L4_Control10 register */
#define XGMAC_MAC_L3_L4_CONTROL10_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL10_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL10_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL10_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL10_L4DPIM10_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL10_L4DPIM10_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL10_L4DPM10_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL10_L4DPM10_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL10_L4SPIM10_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL10_L4SPIM10_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL10_L4SPM10_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL10_L4SPM10_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL10_L4PEN10_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL10_L4PEN10_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL10_L3HDBM10_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL10_L3HDBM10_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL10_L3HSBM10_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL10_L3HSBM10_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL10_L3DAIM10_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL10_L3DAIM10_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL10_L3DAM10_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL10_L3DAM10_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL10_L3SAIM10_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL10_L3SAIM10_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL10_L3SAM10_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL10_L3SAM10_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL10_L3PEN10_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL10_L3PEN10_POS \
        0U

/* Bit fields of MAC_L3_L4_Control11 register */
#define XGMAC_MAC_L3_L4_CONTROL11_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL11_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL11_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL11_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL11_L4DPIM11_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL11_L4DPIM11_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL11_L4DPM11_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL11_L4DPM11_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL11_L4SPIM11_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL11_L4SPIM11_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL11_L4SPM11_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL11_L4SPM11_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL11_L4PEN11_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL11_L4PEN11_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL11_L3HDBM11_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL11_L3HDBM11_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL11_L3HSBM11_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL11_L3HSBM11_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL11_L3DAIM11_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL11_L3DAIM11_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL11_L3DAM11_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL11_L3DAM11_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL11_L3SAIM11_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL11_L3SAIM11_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL11_L3SAM11_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL11_L3SAM11_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL11_L3PEN11_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL11_L3PEN11_POS \
        0U

/* Bit fields of MAC_L3_L4_Control12 register */
#define XGMAC_MAC_L3_L4_CONTROL12_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL12_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL12_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL12_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL12_L4DPIM12_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL12_L4DPIM12_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL12_L4DPM12_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL12_L4DPM12_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL12_L4SPIM12_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL12_L4SPIM12_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL12_L4SPM12_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL12_L4SPM12_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL12_L4PEN12_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL12_L4PEN12_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL12_L3HDBM12_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL12_L3HDBM12_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL12_L3HSBM12_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL12_L3HSBM12_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL12_L3DAIM12_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL12_L3DAIM12_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL12_L3DAM12_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL12_L3DAM12_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL12_L3SAIM12_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL12_L3SAIM12_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL12_L3SAM12_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL12_L3SAM12_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL12_L3PEN12_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL12_L3PEN12_POS \
        0U

/* Bit fields of MAC_L3_L4_Control13 register */
#define XGMAC_MAC_L3_L4_CONTROL13_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL13_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL13_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL13_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL13_L4DPIM13_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL13_L4DPIM13_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL13_L4DPM13_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL13_L4DPM13_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL13_L4SPIM13_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL13_L4SPIM13_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL13_L4SPM13_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL13_L4SPM13_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL13_L4PEN13_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL13_L4PEN13_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL13_L3HDBM13_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL13_L3HDBM13_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL13_L3HSBM13_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL13_L3HSBM13_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL13_L3DAIM13_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL13_L3DAIM13_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL13_L3DAM13_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL13_L3DAM13_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL13_L3SAIM13_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL13_L3SAIM13_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL13_L3SAM13_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL13_L3SAM13_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL13_L3PEN13_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL13_L3PEN13_POS \
        0U

/* Bit fields of MAC_L3_L4_Control14 register */
#define XGMAC_MAC_L3_L4_CONTROL14_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL14_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL14_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL14_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL14_L4DPIM14_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL14_L4DPIM14_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL14_L4DPM14_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL14_L4DPM14_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL14_L4SPIM14_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL14_L4SPIM14_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL14_L4SPM14_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL14_L4SPM14_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL14_L4PEN14_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL14_L4PEN14_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL14_L3HDBM14_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL14_L3HDBM14_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL14_L3HSBM14_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL14_L3HSBM14_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL14_L3DAIM14_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL14_L3DAIM14_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL14_L3DAM14_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL14_L3DAM14_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL14_L3SAIM14_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL14_L3SAIM14_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL14_L3SAM14_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL14_L3SAM14_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL14_L3PEN14_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL14_L3PEN14_POS \
        0U

/* Bit fields of MAC_L3_L4_Control15 register */
#define XGMAC_MAC_L3_L4_CONTROL15_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL15_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL15_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL15_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL15_L4DPIM15_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL15_L4DPIM15_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL15_L4DPM15_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL15_L4DPM15_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL15_L4SPIM15_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL15_L4SPIM15_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL15_L4SPM15_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL15_L4SPM15_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL15_L4PEN15_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL15_L4PEN15_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL15_L3HDBM15_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL15_L3HDBM15_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL15_L3HSBM15_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL15_L3HSBM15_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL15_L3DAIM15_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL15_L3DAIM15_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL15_L3DAM15_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL15_L3DAM15_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL15_L3SAIM15_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL15_L3SAIM15_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL15_L3SAM15_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL15_L3SAM15_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL15_L3PEN15_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL15_L3PEN15_POS \
        0U

/* Bit fields of MAC_L3_L4_Control2 register */
#define XGMAC_MAC_L3_L4_CONTROL2_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL2_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL2_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL2_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL2_L4DPIM2_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL2_L4DPIM2_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL2_L4DPM2_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL2_L4DPM2_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL2_L4SPIM2_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL2_L4SPIM2_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL2_L4SPM2_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL2_L4SPM2_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL2_L4PEN2_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL2_L4PEN2_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL2_L3HDBM2_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL2_L3HDBM2_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL2_L3HSBM2_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL2_L3HSBM2_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL2_L3DAIM2_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL2_L3DAIM2_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL2_L3DAM2_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL2_L3DAM2_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL2_L3SAIM2_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL2_L3SAIM2_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL2_L3SAM2_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL2_L3SAM2_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL2_L3PEN2_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL2_L3PEN2_POS \
        0U

/* Bit fields of MAC_L3_L4_Control3 register */
#define XGMAC_MAC_L3_L4_CONTROL3_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL3_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL3_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL3_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL3_L4DPIM3_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL3_L4DPIM3_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL3_L4DPM3_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL3_L4DPM3_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL3_L4SPIM3_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL3_L4SPIM3_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL3_L4SPM3_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL3_L4SPM3_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL3_L4PEN3_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL3_L4PEN3_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL3_L3HDBM3_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL3_L3HDBM3_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL3_L3HSBM3_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL3_L3HSBM3_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL3_L3DAIM3_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL3_L3DAIM3_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL3_L3DAM3_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL3_L3DAM3_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL3_L3SAIM3_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL3_L3SAIM3_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL3_L3SAM3_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL3_L3SAM3_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL3_L3PEN3_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL3_L3PEN3_POS \
        0U

/* Bit fields of MAC_L3_L4_Control4 register */
#define XGMAC_MAC_L3_L4_CONTROL4_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL4_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL4_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL4_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL4_L4DPIM4_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL4_L4DPIM4_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL4_L4DPM4_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL4_L4DPM4_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL4_L4SPIM4_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL4_L4SPIM4_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL4_L4SPM4_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL4_L4SPM4_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL4_L4PEN4_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL4_L4PEN4_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL4_L3HDBM4_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL4_L3HDBM4_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL4_L3HSBM4_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL4_L3HSBM4_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL4_L3DAIM4_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL4_L3DAIM4_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL4_L3DAM4_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL4_L3DAM4_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL4_L3SAIM4_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL4_L3SAIM4_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL4_L3SAM4_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL4_L3SAM4_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL4_L3PEN4_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL4_L3PEN4_POS \
        0U

/* Bit fields of MAC_L3_L4_Control5 register */
#define XGMAC_MAC_L3_L4_CONTROL5_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL5_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL5_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL5_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL5_L4DPIM5_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL5_L4DPIM5_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL5_L4DPM5_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL5_L4DPM5_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL5_L4SPIM5_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL5_L4SPIM5_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL5_L4SPM5_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL5_L4SPM5_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL5_L4PEN5_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL5_L4PEN5_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL5_L3HDBM5_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL5_L3HDBM5_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL5_L3HSBM5_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL5_L3HSBM5_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL5_L3DAIM5_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL5_L3DAIM5_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL5_L3DAM5_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL5_L3DAM5_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL5_L3SAIM5_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL5_L3SAIM5_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL5_L3SAM5_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL5_L3SAM5_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL5_L3PEN5_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL5_L3PEN5_POS \
        0U

/* Bit fields of MAC_L3_L4_Control6 register */
#define XGMAC_MAC_L3_L4_CONTROL6_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL6_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL6_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL6_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL6_L4DPIM6_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL6_L4DPIM6_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL6_L4DPM6_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL6_L4DPM6_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL6_L4SPIM6_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL6_L4SPIM6_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL6_L4SPM6_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL6_L4SPM6_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL6_L4PEN6_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL6_L4PEN6_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL6_L3HDBM6_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL6_L3HDBM6_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL6_L3HSBM6_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL6_L3HSBM6_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL6_L3DAIM6_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL6_L3DAIM6_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL6_L3DAM6_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL6_L3DAM6_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL6_L3SAIM6_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL6_L3SAIM6_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL6_L3SAM6_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL6_L3SAM6_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL6_L3PEN6_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL6_L3PEN6_POS \
        0U

/* Bit fields of MAC_L3_L4_Control7 register */
#define XGMAC_MAC_L3_L4_CONTROL7_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL7_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL7_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL7_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL7_L4DPIM7_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL7_L4DPIM7_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL7_L4DPM7_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL7_L4DPM7_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL7_L4SPIM7_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL7_L4SPIM7_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL7_L4SPM7_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL7_L4SPM7_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL7_L4PEN7_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL7_L4PEN7_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL7_L3HDBM7_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL7_L3HDBM7_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL7_L3HSBM7_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL7_L3HSBM7_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL7_L3DAIM7_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL7_L3DAIM7_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL7_L3DAM7_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL7_L3DAM7_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL7_L3SAIM7_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL7_L3SAIM7_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL7_L3SAM7_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL7_L3SAM7_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL7_L3PEN7_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL7_L3PEN7_POS \
        0U

/* Bit fields of MAC_L3_L4_Control8 register */
#define XGMAC_MAC_L3_L4_CONTROL8_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL8_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL8_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL8_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL8_L4DPIM8_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL8_L4DPIM8_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL8_L4DPM8_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL8_L4DPM8_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL8_L4SPIM8_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL8_L4SPIM8_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL8_L4SPM8_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL8_L4SPM8_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL8_L4PEN8_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL8_L4PEN8_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL8_L3HDBM8_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL8_L3HDBM8_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL8_L3HSBM8_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL8_L3HSBM8_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL8_L3DAIM8_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL8_L3DAIM8_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL8_L3DAM8_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL8_L3DAM8_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL8_L3SAIM8_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL8_L3SAIM8_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL8_L3SAM8_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL8_L3SAM8_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL8_L3PEN8_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL8_L3PEN8_POS \
        0U

/* Bit fields of MAC_L3_L4_Control9 register */
#define XGMAC_MAC_L3_L4_CONTROL9_DMCHEN_MASK \
        0x80000000U
#define XGMAC_MAC_L3_L4_CONTROL9_DMCHEN_POS \
        31U
#define XGMAC_MAC_L3_L4_CONTROL9_DMCHN_MASK \
        0x07000000U
#define XGMAC_MAC_L3_L4_CONTROL9_DMCHN_POS \
        24U
#define XGMAC_MAC_L3_L4_CONTROL9_L4DPIM9_MASK \
        0x00200000U
#define XGMAC_MAC_L3_L4_CONTROL9_L4DPIM9_POS \
        21U
#define XGMAC_MAC_L3_L4_CONTROL9_L4DPM9_MASK \
        0x00100000U
#define XGMAC_MAC_L3_L4_CONTROL9_L4DPM9_POS \
        20U
#define XGMAC_MAC_L3_L4_CONTROL9_L4SPIM9_MASK \
        0x00080000U
#define XGMAC_MAC_L3_L4_CONTROL9_L4SPIM9_POS \
        19U
#define XGMAC_MAC_L3_L4_CONTROL9_L4SPM9_MASK \
        0x00040000U
#define XGMAC_MAC_L3_L4_CONTROL9_L4SPM9_POS \
        18U
#define XGMAC_MAC_L3_L4_CONTROL9_L4PEN9_MASK \
        0x00010000U
#define XGMAC_MAC_L3_L4_CONTROL9_L4PEN9_POS \
        16U
#define XGMAC_MAC_L3_L4_CONTROL9_L3HDBM9_MASK \
        0x0000F800U
#define XGMAC_MAC_L3_L4_CONTROL9_L3HDBM9_POS \
        11U
#define XGMAC_MAC_L3_L4_CONTROL9_L3HSBM9_MASK \
        0x000007C0U
#define XGMAC_MAC_L3_L4_CONTROL9_L3HSBM9_POS \
        6U
#define XGMAC_MAC_L3_L4_CONTROL9_L3DAIM9_MASK \
        0x00000020U
#define XGMAC_MAC_L3_L4_CONTROL9_L3DAIM9_POS \
        5U
#define XGMAC_MAC_L3_L4_CONTROL9_L3DAM9_MASK \
        0x00000010U
#define XGMAC_MAC_L3_L4_CONTROL9_L3DAM9_POS \
        4U
#define XGMAC_MAC_L3_L4_CONTROL9_L3SAIM9_MASK \
        0x00000008U
#define XGMAC_MAC_L3_L4_CONTROL9_L3SAIM9_POS \
        3U
#define XGMAC_MAC_L3_L4_CONTROL9_L3SAM9_MASK \
        0x00000004U
#define XGMAC_MAC_L3_L4_CONTROL9_L3SAM9_POS \
        2U
#define XGMAC_MAC_L3_L4_CONTROL9_L3PEN9_MASK \
        0x00000001U
#define XGMAC_MAC_L3_L4_CONTROL9_L3PEN9_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg0 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG0_L3A00_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG0_L3A00_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg1 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG1_L3A01_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG1_L3A01_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg10 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG10_L3A010_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG10_L3A010_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg11 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG11_L3A011_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG11_L3A011_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg12 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG12_L3A012_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG12_L3A012_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg13 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG13_L3A013_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG13_L3A013_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg14 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG14_L3A014_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG14_L3A014_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg15 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG15_L3A015_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG15_L3A015_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg2 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG2_L3A02_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG2_L3A02_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg3 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG3_L3A03_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG3_L3A03_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg4 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG4_L3A04_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG4_L3A04_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg5 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG5_L3A05_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG5_L3A05_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg6 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG6_L3A06_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG6_L3A06_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg7 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG7_L3A07_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG7_L3A07_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg8 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG8_L3A08_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG8_L3A08_POS \
        0U

/* Bit fields of MAC_Layer3_Addr0_Reg9 register */
#define XGMAC_MAC_LAYER3_ADDR0_REG9_L3A09_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR0_REG9_L3A09_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg0 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG0_L3A10_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG0_L3A10_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg1 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG1_L3A11_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG1_L3A11_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg10 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG10_L3A110_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG10_L3A110_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg11 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG11_L3A111_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG11_L3A111_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg12 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG12_L3A112_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG12_L3A112_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg13 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG13_L3A113_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG13_L3A113_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg14 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG14_L3A114_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG14_L3A114_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg15 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG15_L3A115_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG15_L3A115_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg2 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG2_L3A12_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG2_L3A12_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg3 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG3_L3A13_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG3_L3A13_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg4 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG4_L3A14_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG4_L3A14_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg5 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG5_L3A15_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG5_L3A15_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg6 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG6_L3A16_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG6_L3A16_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg7 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG7_L3A17_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG7_L3A17_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg8 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG8_L3A18_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG8_L3A18_POS \
        0U

/* Bit fields of MAC_Layer3_Addr1_Reg9 register */
#define XGMAC_MAC_LAYER3_ADDR1_REG9_L3A19_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR1_REG9_L3A19_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg0 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG0_L3A20_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG0_L3A20_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg1 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG1_L3A21_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG1_L3A21_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg10 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG10_L3A210_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG10_L3A210_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg11 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG11_L3A211_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG11_L3A211_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg12 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG12_L3A212_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG12_L3A212_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg13 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG13_L3A213_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG13_L3A213_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg14 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG14_L3A214_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG14_L3A214_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg15 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG15_L3A215_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG15_L3A215_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg2 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG2_L3A22_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG2_L3A22_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg3 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG3_L3A23_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG3_L3A23_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg4 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG4_L3A24_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG4_L3A24_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg5 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG5_L3A25_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG5_L3A25_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg6 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG6_L3A26_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG6_L3A26_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg7 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG7_L3A27_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG7_L3A27_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg8 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG8_L3A28_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG8_L3A28_POS \
        0U

/* Bit fields of MAC_Layer3_Addr2_Reg9 register */
#define XGMAC_MAC_LAYER3_ADDR2_REG9_L3A29_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR2_REG9_L3A29_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg0 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG0_L3A30_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG0_L3A30_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg1 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG1_L3A31_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG1_L3A31_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg10 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG10_L3A310_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG10_L3A310_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg11 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG11_L3A311_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG11_L3A311_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg12 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG12_L3A312_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG12_L3A312_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg13 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG13_L3A313_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG13_L3A313_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg14 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG14_L3A314_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG14_L3A314_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg15 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG15_L3A315_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG15_L3A315_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg2 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG2_L3A32_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG2_L3A32_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg3 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG3_L3A33_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG3_L3A33_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg4 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG4_L3A34_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG4_L3A34_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg5 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG5_L3A35_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG5_L3A35_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg6 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG6_L3A36_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG6_L3A36_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg7 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG7_L3A37_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG7_L3A37_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg8 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG8_L3A38_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG8_L3A38_POS \
        0U

/* Bit fields of MAC_Layer3_Addr3_Reg9 register */
#define XGMAC_MAC_LAYER3_ADDR3_REG9_L3A39_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_LAYER3_ADDR3_REG9_L3A39_POS \
        0U

/* Bit fields of MAC_Layer4_Address0 register */
#define XGMAC_MAC_LAYER4_ADDRESS0_L4DP0_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS0_L4DP0_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS0_L4SP0_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS0_L4SP0_POS \
        0U

/* Bit fields of MAC_Layer4_Address1 register */
#define XGMAC_MAC_LAYER4_ADDRESS1_L4DP1_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS1_L4DP1_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS1_L4SP1_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS1_L4SP1_POS \
        0U

/* Bit fields of MAC_Layer4_Address10 register */
#define XGMAC_MAC_LAYER4_ADDRESS10_L4DP10_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS10_L4DP10_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS10_L4SP10_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS10_L4SP10_POS \
        0U

/* Bit fields of MAC_Layer4_Address11 register */
#define XGMAC_MAC_LAYER4_ADDRESS11_L4DP11_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS11_L4DP11_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS11_L4SP11_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS11_L4SP11_POS \
        0U

/* Bit fields of MAC_Layer4_Address12 register */
#define XGMAC_MAC_LAYER4_ADDRESS12_L4DP12_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS12_L4DP12_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS12_L4SP12_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS12_L4SP12_POS \
        0U

/* Bit fields of MAC_Layer4_Address13 register */
#define XGMAC_MAC_LAYER4_ADDRESS13_L4DP13_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS13_L4DP13_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS13_L4SP13_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS13_L4SP13_POS \
        0U

/* Bit fields of MAC_Layer4_Address14 register */
#define XGMAC_MAC_LAYER4_ADDRESS14_L4DP14_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS14_L4DP14_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS14_L4SP14_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS14_L4SP14_POS \
        0U

/* Bit fields of MAC_Layer4_Address15 register */
#define XGMAC_MAC_LAYER4_ADDRESS15_L4DP15_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS15_L4DP15_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS15_L4SP15_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS15_L4SP15_POS \
        0U

/* Bit fields of MAC_Layer4_Address2 register */
#define XGMAC_MAC_LAYER4_ADDRESS2_L4DP2_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS2_L4DP2_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS2_L4SP2_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS2_L4SP2_POS \
        0U

/* Bit fields of MAC_Layer4_Address3 register */
#define XGMAC_MAC_LAYER4_ADDRESS3_L4DP3_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS3_L4DP3_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS3_L4SP3_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS3_L4SP3_POS \
        0U

/* Bit fields of MAC_Layer4_Address4 register */
#define XGMAC_MAC_LAYER4_ADDRESS4_L4DP4_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS4_L4DP4_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS4_L4SP4_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS4_L4SP4_POS \
        0U

/* Bit fields of MAC_Layer4_Address5 register */
#define XGMAC_MAC_LAYER4_ADDRESS5_L4DP5_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS5_L4DP5_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS5_L4SP5_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS5_L4SP5_POS \
        0U

/* Bit fields of MAC_Layer4_Address6 register */
#define XGMAC_MAC_LAYER4_ADDRESS6_L4DP6_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS6_L4DP6_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS6_L4SP6_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS6_L4SP6_POS \
        0U

/* Bit fields of MAC_Layer4_Address7 register */
#define XGMAC_MAC_LAYER4_ADDRESS7_L4DP7_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS7_L4DP7_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS7_L4SP7_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS7_L4SP7_POS \
        0U

/* Bit fields of MAC_Layer4_Address8 register */
#define XGMAC_MAC_LAYER4_ADDRESS8_L4DP8_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS8_L4DP8_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS8_L4SP8_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS8_L4SP8_POS \
        0U

/* Bit fields of MAC_Layer4_Address9 register */
#define XGMAC_MAC_LAYER4_ADDRESS9_L4DP9_MASK \
        0xFFFF0000U
#define XGMAC_MAC_LAYER4_ADDRESS9_L4DP9_POS \
        16U
#define XGMAC_MAC_LAYER4_ADDRESS9_L4SP9_MASK \
        0x0000FFFFU
#define XGMAC_MAC_LAYER4_ADDRESS9_L4SP9_POS \
        0U

/* Bit fields of MAC_ARP_Address register */
#define XGMAC_MAC_ARP_ADDRESS_ARPPA_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_ARP_ADDRESS_ARPPA_POS \
        0U

/* Bit fields of MAC_Timestamp_Control register */
#define XGMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK \
        0x10000000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_POS \
        28U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK \
        0x01000000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_POS \
        24U
#define XGMAC_MAC_TIMESTAMP_CONTROL_CSC_MASK \
        0x00080000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_CSC_POS \
        19U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK \
        0x00040000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_POS \
        18U
#define XGMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK \
        0x00030000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_POS \
        16U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK \
        0x00008000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_POS \
        15U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK \
        0x00004000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_POS \
        14U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK \
        0x00002000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_POS \
        13U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK \
        0x00001000U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_POS \
        12U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK \
        0x00000800U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_POS \
        11U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK \
        0x00000400U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_POS \
        10U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK \
        0x00000200U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_POS \
        9U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK \
        0x00000100U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENALL_POS \
        8U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK \
        0x00000020U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_POS \
        5U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK \
        0x00000008U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_POS \
        3U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK \
        0x00000004U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSINIT_POS \
        2U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK \
        0x00000002U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_POS \
        1U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK \
        0x00000001U
#define XGMAC_MAC_TIMESTAMP_CONTROL_TSENA_POS \
        0U

/* Bit fields of MAC_Sub_Second_Increment register */
#define XGMAC_MAC_SUB_SECOND_INCREMENT_SSINC_MASK \
        0x00FF0000U
#define XGMAC_MAC_SUB_SECOND_INCREMENT_SSINC_POS \
        16U
#define XGMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK \
        0x0000FF00U
#define XGMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_POS \
        8U

/* Bit fields of MAC_System_Time_Seconds register */
#define XGMAC_MAC_SYSTEM_TIME_SECONDS_TSS_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_SYSTEM_TIME_SECONDS_TSS_POS \
        0U

/* Bit fields of MAC_System_Time_Nanoseconds register */
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_POS \
        0U

/* Bit fields of MAC_System_Time_Seconds_Update register */
#define XGMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_POS \
        0U

/* Bit fields of MAC_System_Time_Nanoseconds_Update register */
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK \
        0x80000000U
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_POS \
        31U
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_POS \
        0U

/* Bit fields of MAC_Timestamp_Addend register */
#define XGMAC_MAC_TIMESTAMP_ADDEND_TSAR_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TIMESTAMP_ADDEND_TSAR_POS \
        0U

/* Bit fields of MAC_System_Time_Higher_Word_Seconds register */
#define XGMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK \
        0x0000FFFFU
#define XGMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_POS \
        0U

/* Bit fields of MAC_Timestamp_Status register */
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSNS_MASK \
        0x3E000000U
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSNS_POS \
        25U
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSSTM_MASK \
        0x01000000U
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSSTM_POS \
        24U
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSSTN_MASK \
        0x000F0000U
#define XGMAC_MAC_TIMESTAMP_STATUS_ATSSTN_POS \
        16U
#define XGMAC_MAC_TIMESTAMP_STATUS_TXTSC_MASK \
        0x00008000U
#define XGMAC_MAC_TIMESTAMP_STATUS_TXTSC_POS \
        15U
#define XGMAC_MAC_TIMESTAMP_STATUS_TTSNS_MASK \
        0x00007C00U
#define XGMAC_MAC_TIMESTAMP_STATUS_TTSNS_POS \
        10U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK \
        0x00000200U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_POS \
        9U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK \
        0x00000100U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_POS \
        8U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK \
        0x00000080U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_POS \
        7U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK \
        0x00000040U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_POS \
        6U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK \
        0x00000020U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_POS \
        5U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK \
        0x00000010U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_POS \
        4U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK \
        0x00000008U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_POS \
        3U
#define XGMAC_MAC_TIMESTAMP_STATUS_AUXTSTRIG_MASK \
        0x00000004U
#define XGMAC_MAC_TIMESTAMP_STATUS_AUXTSTRIG_POS \
        2U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK \
        0x00000002U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_POS \
        1U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSSOVF_MASK \
        0x00000001U
#define XGMAC_MAC_TIMESTAMP_STATUS_TSSOVF_POS \
        0U

/* Bit fields of MAC_Tx_Timestamp_Status_Nanoseconds register */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK \
        0x80000000U
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_POS \
        31U
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_POS \
        0U

/* Bit fields of MAC_Tx_Timestamp_Status_Seconds register */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_POS \
        0U

/* Bit fields of MAC_Tx_Timestamp_Status_PktID register */
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_PKTID_PKTID_MASK \
        0x000003FFU
#define XGMAC_MAC_TX_TIMESTAMP_STATUS_PKTID_PKTID_POS \
        0U

/* Bit fields of MAC_Auxiliary_Control register */
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSEN1_MASK \
        0x00000020U
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSEN1_POS \
        5U
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSEN0_MASK \
        0x00000010U
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSEN0_POS \
        4U
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSFC_MASK \
        0x00000001U
#define XGMAC_MAC_AUXILIARY_CONTROL_ATSFC_POS \
        0U

/* Bit fields of MAC_Auxiliary_Timestamp_Nanoseconds register */
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_NANOSECONDS_AUXTSLO_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_NANOSECONDS_AUXTSLO_POS \
        0U

/* Bit fields of MAC_Auxiliary_Timestamp_Seconds register */
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_SECONDS_AUXTSHI_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_AUXILIARY_TIMESTAMP_SECONDS_AUXTSHI_POS \
        0U

/* Bit fields of MAC_Timestamp_Ingress_Asym_Corr register */
#define XGMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_POS \
        0U

/* Bit fields of MAC_Timestamp_Egress_Asym_Corr register */
#define XGMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_POS \
        0U

/* Bit fields of MAC_Timestamp_Ingress_Corr_Nanosecond register */
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_POS \
        0U

/* Bit fields of MAC_Timestamp_Ingress_Corr_Subnanosecond register */
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSECOND_TSICSNS_MASK \
        0x0000FF00U
#define XGMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSECOND_TSICSNS_POS \
        8U

/* Bit fields of MAC_Timestamp_Egress_Corr_Nanosecond register */
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_POS \
        0U

/* Bit fields of MAC_Timestamp_Egress_Corr_Subnanosecond register */
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSECOND_TSECSNS_MASK \
        0x0000FF00U
#define XGMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSECOND_TSECSNS_POS \
        8U

/* Bit fields of MAC_PPS_Control register */
#define XGMAC_MAC_PPS_CONTROL_TRGTMODSEL1_MASK \
        0x00006000U
#define XGMAC_MAC_PPS_CONTROL_TRGTMODSEL1_POS \
        13U
#define XGMAC_MAC_PPS_CONTROL_PPSCMD1_MASK \
        0x00000700U
#define XGMAC_MAC_PPS_CONTROL_PPSCMD1_POS \
        8U
#define XGMAC_MAC_PPS_CONTROL_TRGTMODSEL0_MASK \
        0x00000060U
#define XGMAC_MAC_PPS_CONTROL_TRGTMODSEL0_POS \
        5U
#define XGMAC_MAC_PPS_CONTROL_PPSEN0_MASK \
        0x00000010U
#define XGMAC_MAC_PPS_CONTROL_PPSEN0_POS \
        4U
#define XGMAC_MAC_PPS_CONTROL_PPSCTRL0_PPSCMD0_MASK \
        0x0000000FU
#define XGMAC_MAC_PPS_CONTROL_PPSCTRL0_PPSCMD0_POS \
        0U

/* Bit fields of MAC_PPS0_Target_Time_Seconds register */
#define XGMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_POS \
        0U

/* Bit fields of MAC_PPS0_Target_Time_Nanoseconds register */
#define XGMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK \
        0x80000000U
#define XGMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_POS \
        31U
#define XGMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_POS \
        0U

/* Bit fields of MAC_PPS0_Interval register */
#define XGMAC_MAC_PPS0_INTERVAL_PPSINT0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS0_INTERVAL_PPSINT0_POS \
        0U

/* Bit fields of MAC_PPS0_Width register */
#define XGMAC_MAC_PPS0_WIDTH_PPSWIDTH0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS0_WIDTH_PPSWIDTH0_POS \
        0U

/* Bit fields of MAC_PPS1_Target_Time_Seconds register */
#define XGMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_POS \
        0U

/* Bit fields of MAC_PPS1_Target_Time_Nanoseconds register */
#define XGMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_MASK \
        0x80000000U
#define XGMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_POS \
        31U
#define XGMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_MASK \
        0x7FFFFFFFU
#define XGMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_POS \
        0U

/* Bit fields of MAC_PPS1_Interval register */
#define XGMAC_MAC_PPS1_INTERVAL_PPSINT1_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS1_INTERVAL_PPSINT1_POS \
        0U

/* Bit fields of MAC_PPS1_Width register */
#define XGMAC_MAC_PPS1_WIDTH_PPSWIDTH1_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_PPS1_WIDTH_PPSWIDTH1_POS \
        0U

/* Bit fields of MAC_PTO_Control register */
#define XGMAC_MAC_PTO_CONTROL_DN_MASK \
        0x0000FF00U
#define XGMAC_MAC_PTO_CONTROL_DN_POS \
        8U
#define XGMAC_MAC_PTO_CONTROL_PDRDIS_MASK \
        0x00000080U
#define XGMAC_MAC_PTO_CONTROL_PDRDIS_POS \
        7U
#define XGMAC_MAC_PTO_CONTROL_DRRDIS_MASK \
        0x00000040U
#define XGMAC_MAC_PTO_CONTROL_DRRDIS_POS \
        6U
#define XGMAC_MAC_PTO_CONTROL_APDREQTRIG_MASK \
        0x00000020U
#define XGMAC_MAC_PTO_CONTROL_APDREQTRIG_POS \
        5U
#define XGMAC_MAC_PTO_CONTROL_ASYNCTRIG_MASK \
        0x00000010U
#define XGMAC_MAC_PTO_CONTROL_ASYNCTRIG_POS \
        4U
#define XGMAC_MAC_PTO_CONTROL_APDREQEN_MASK \
        0x00000004U
#define XGMAC_MAC_PTO_CONTROL_APDREQEN_POS \
        2U
#define XGMAC_MAC_PTO_CONTROL_ASYNCEN_MASK \
        0x00000002U
#define XGMAC_MAC_PTO_CONTROL_ASYNCEN_POS \
        1U
#define XGMAC_MAC_PTO_CONTROL_PTOEN_MASK \
        0x00000001U
#define XGMAC_MAC_PTO_CONTROL_PTOEN_POS \
        0U

/* Bit fields of MAC_Source_Port_Identity0 register */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY0_SPI0_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_SOURCE_PORT_IDENTITY0_SPI0_POS \
        0U

/* Bit fields of MAC_Source_Port_Identity1 register */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY1_SPI1_MASK \
        0xFFFFFFFFU
#define XGMAC_MAC_SOURCE_PORT_IDENTITY1_SPI1_POS \
        0U

/* Bit fields of MAC_Source_Port_Identity2 register */
#define XGMAC_MAC_SOURCE_PORT_IDENTITY2_SPI2_MASK \
        0x0000FFFFU
#define XGMAC_MAC_SOURCE_PORT_IDENTITY2_SPI2_POS \
        0U

/* Bit fields of MAC_Log_Message_Interval register */
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_MASK \
        0xFF000000U
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_POS \
        24U
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_MASK \
        0x00000700U
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_POS \
        8U
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_LSI_MASK \
        0x000000FFU
#define XGMAC_MAC_LOG_MESSAGE_INTERVAL_LSI_POS \
        0U

/* Bit fields of MTL_Operation_Mode register */
#define XGMAC_MTL_OPERATION_MODE_ETSALG_MASK \
        0x00000060U
#define XGMAC_MTL_OPERATION_MODE_ETSALG_POS \
        5U
#define XGMAC_MTL_OPERATION_MODE_RAA_MASK \
        0x00000004U
#define XGMAC_MTL_OPERATION_MODE_RAA_POS \
        2U

/* Bit fields of MTL_Debug_Control register */
#define XGMAC_MTL_DEBUG_CONTROL_PKTIE_MASK \
        0x00004000U
#define XGMAC_MTL_DEBUG_CONTROL_PKTIE_POS \
        14U
#define XGMAC_MTL_DEBUG_CONTROL_FIFOSEL_MASK \
        0x00003000U
#define XGMAC_MTL_DEBUG_CONTROL_FIFOSEL_POS \
        12U
#define XGMAC_MTL_DEBUG_CONTROL_FIFOWREN_MASK \
        0x00000800U
#define XGMAC_MTL_DEBUG_CONTROL_FIFOWREN_POS \
        11U
#define XGMAC_MTL_DEBUG_CONTROL_FIFORDEN_MASK \
        0x00000400U
#define XGMAC_MTL_DEBUG_CONTROL_FIFORDEN_POS \
        10U
#define XGMAC_MTL_DEBUG_CONTROL_RSTSEL_MASK \
        0x00000200U
#define XGMAC_MTL_DEBUG_CONTROL_RSTSEL_POS \
        9U
#define XGMAC_MTL_DEBUG_CONTROL_RSTALL_MASK \
        0x00000100U
#define XGMAC_MTL_DEBUG_CONTROL_RSTALL_POS \
        8U
#define XGMAC_MTL_DEBUG_CONTROL_PKTSTATE_MASK \
        0x00000060U
#define XGMAC_MTL_DEBUG_CONTROL_PKTSTATE_POS \
        5U
#define XGMAC_MTL_DEBUG_CONTROL_BYTEEN_MASK \
        0x0000000CU
#define XGMAC_MTL_DEBUG_CONTROL_BYTEEN_POS \
        2U
#define XGMAC_MTL_DEBUG_CONTROL_DBGMOD_MASK \
        0x00000002U
#define XGMAC_MTL_DEBUG_CONTROL_DBGMOD_POS \
        1U
#define XGMAC_MTL_DEBUG_CONTROL_FDBGEN_MASK \
        0x00000001U
#define XGMAC_MTL_DEBUG_CONTROL_FDBGEN_POS \
        0U

/* Bit fields of MTL_Debug_Status register */
#define XGMAC_MTL_DEBUG_STATUS_LOCR_MASK \
        0xFFFF0000U
#define XGMAC_MTL_DEBUG_STATUS_LOCR_POS \
        16U
#define XGMAC_MTL_DEBUG_STATUS_PKTI_MASK \
        0x00000100U
#define XGMAC_MTL_DEBUG_STATUS_PKTI_POS \
        8U
#define XGMAC_MTL_DEBUG_STATUS_BYTEEN_MASK \
        0x00000018U
#define XGMAC_MTL_DEBUG_STATUS_BYTEEN_POS \
        3U
#define XGMAC_MTL_DEBUG_STATUS_PKTSTATE_MASK \
        0x00000006U
#define XGMAC_MTL_DEBUG_STATUS_PKTSTATE_POS \
        1U
#define XGMAC_MTL_DEBUG_STATUS_FIFOBUSY_MASK \
        0x00000001U
#define XGMAC_MTL_DEBUG_STATUS_FIFOBUSY_POS \
        0U

/* Bit fields of MTL_FIFO_Debug_Data register */
#define XGMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK \
        0xFFFFFFFFU
#define XGMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_POS \
        0U

/* Bit fields of MTL_Interrupt_Status register */
#define XGMAC_MTL_INTERRUPT_STATUS_TINS_MASK \
        0x00080000U
#define XGMAC_MTL_INTERRUPT_STATUS_TINS_POS \
        19U
#define XGMAC_MTL_INTERRUPT_STATUS_ESTIS_MASK \
        0x00040000U
#define XGMAC_MTL_INTERRUPT_STATUS_ESTIS_POS \
        18U
#define XGMAC_MTL_INTERRUPT_STATUS_DBGIS_MASK \
        0x00020000U
#define XGMAC_MTL_INTERRUPT_STATUS_DBGIS_POS \
        17U
#define XGMAC_MTL_INTERRUPT_STATUS_MACIS_MASK \
        0x00010000U
#define XGMAC_MTL_INTERRUPT_STATUS_MACIS_POS \
        16U
#define XGMAC_MTL_INTERRUPT_STATUS_Q15IS_MASK \
        0x00008000U
#define XGMAC_MTL_INTERRUPT_STATUS_Q15IS_POS \
        15U
#define XGMAC_MTL_INTERRUPT_STATUS_Q14IS_MASK \
        0x00004000U
#define XGMAC_MTL_INTERRUPT_STATUS_Q14IS_POS \
        14U
#define XGMAC_MTL_INTERRUPT_STATUS_Q13IS_MASK \
        0x00002000U
#define XGMAC_MTL_INTERRUPT_STATUS_Q13IS_POS \
        13U
#define XGMAC_MTL_INTERRUPT_STATUS_Q12IS_MASK \
        0x00001000U
#define XGMAC_MTL_INTERRUPT_STATUS_Q12IS_POS \
        12U
#define XGMAC_MTL_INTERRUPT_STATUS_Q11IS_MASK \
        0x00000800U
#define XGMAC_MTL_INTERRUPT_STATUS_Q11IS_POS \
        11U
#define XGMAC_MTL_INTERRUPT_STATUS_Q10IS_MASK \
        0x00000400U
#define XGMAC_MTL_INTERRUPT_STATUS_Q10IS_POS \
        10U
#define XGMAC_MTL_INTERRUPT_STATUS_Q9IS_MASK \
        0x00000200U
#define XGMAC_MTL_INTERRUPT_STATUS_Q9IS_POS \
        9U
#define XGMAC_MTL_INTERRUPT_STATUS_Q8IS_MASK \
        0x00000100U
#define XGMAC_MTL_INTERRUPT_STATUS_Q8IS_POS \
        8U
#define XGMAC_MTL_INTERRUPT_STATUS_Q7IS_MASK \
        0x00000080U
#define XGMAC_MTL_INTERRUPT_STATUS_Q7IS_POS \
        7U
#define XGMAC_MTL_INTERRUPT_STATUS_Q6IS_MASK \
        0x00000040U
#define XGMAC_MTL_INTERRUPT_STATUS_Q6IS_POS \
        6U
#define XGMAC_MTL_INTERRUPT_STATUS_Q5IS_MASK \
        0x00000020U
#define XGMAC_MTL_INTERRUPT_STATUS_Q5IS_POS \
        5U
#define XGMAC_MTL_INTERRUPT_STATUS_Q4IS_MASK \
        0x00000010U
#define XGMAC_MTL_INTERRUPT_STATUS_Q4IS_POS \
        4U
#define XGMAC_MTL_INTERRUPT_STATUS_Q3IS_MASK \
        0x00000008U
#define XGMAC_MTL_INTERRUPT_STATUS_Q3IS_POS \
        3U
#define XGMAC_MTL_INTERRUPT_STATUS_Q2IS_MASK \
        0x00000004U
#define XGMAC_MTL_INTERRUPT_STATUS_Q2IS_POS \
        2U
#define XGMAC_MTL_INTERRUPT_STATUS_Q1IS_MASK \
        0x00000002U
#define XGMAC_MTL_INTERRUPT_STATUS_Q1IS_POS \
        1U
#define XGMAC_MTL_INTERRUPT_STATUS_Q0IS_MASK \
        0x00000001U
#define XGMAC_MTL_INTERRUPT_STATUS_Q0IS_POS \
        0U

/* Bit fields of MTL_RxQ_DMA_Map0 register */
#define XGMAC_MTL_RXQ_DMA_MAP0_Q3DDMACH_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q3DDMACH_POS \
        31U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q3MDMACH_MASK \
        0x07000000U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q3MDMACH_POS \
        24U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_MASK \
        0x00800000U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_POS \
        23U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_MASK \
        0x00070000U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_POS \
        16U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_POS \
        15U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK \
        0x00000700U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_POS \
        8U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_POS \
        7U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_POS \
        0U

/* Bit fields of MTL_RxQ_DMA_Map1 register */
#define XGMAC_MTL_RXQ_DMA_MAP1_Q7DDMACH_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q7DDMACH_POS \
        31U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q7MDMACH_MASK \
        0x07000000U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q7MDMACH_POS \
        24U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q6DDMACH_MASK \
        0x00800000U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q6DDMACH_POS \
        23U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q6MDMACH_MASK \
        0x00070000U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q6MDMACH_POS \
        16U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q5DDMACH_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q5DDMACH_POS \
        15U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q5MDMACH_MASK \
        0x00000700U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q5MDMACH_POS \
        8U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q4DDMACH_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q4DDMACH_POS \
        7U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q4MDMACH_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ_DMA_MAP1_Q4MDMACH_POS \
        0U

/* Bit fields of MTL_TC_Prty_Map0 register */
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC3_MASK \
        0xFF000000U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC3_POS \
        24U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC2_MASK \
        0x00FF0000U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC2_POS \
        16U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC1_MASK \
        0x0000FF00U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC1_POS \
        8U
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC0_MASK \
        0x000000FFU
#define XGMAC_MTL_TC_PRTY_MAP0_PSTC0_POS \
        0U

/* Bit fields of MTL_TC_Prty_Map1 register */
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC7_MASK \
        0xFF000000U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC7_POS \
        24U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC6_MASK \
        0x00FF0000U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC6_POS \
        16U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC5_MASK \
        0x0000FF00U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC5_POS \
        8U
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC4_MASK \
        0x000000FFU
#define XGMAC_MTL_TC_PRTY_MAP1_PSTC4_POS \
        0U

/* Bit fields of MTL_TBS_CTRL register */
#define XGMAC_MTL_TBS_CTRL_LEOS_MASK \
        0xFFFFFF00U
#define XGMAC_MTL_TBS_CTRL_LEOS_POS \
        8U
#define XGMAC_MTL_TBS_CTRL_LEGOS_MASK \
        0x00000070U
#define XGMAC_MTL_TBS_CTRL_LEGOS_POS \
        4U
#define XGMAC_MTL_TBS_CTRL_TIEN_MASK \
        0x00000004U
#define XGMAC_MTL_TBS_CTRL_TIEN_POS \
        2U
#define XGMAC_MTL_TBS_CTRL_LEOV_MASK \
        0x00000002U
#define XGMAC_MTL_TBS_CTRL_LEOV_POS \
        1U
#define XGMAC_MTL_TBS_CTRL_ESTM_MASK \
        0x00000001U
#define XGMAC_MTL_TBS_CTRL_ESTM_POS \
        0U

/* Bit fields of MTL_TBS_STATS register */
#define XGMAC_MTL_TBS_STATS_EDQN_MASK \
        0x000000FFU
#define XGMAC_MTL_TBS_STATS_EDQN_POS \
        0U

/* Bit fields of MTL_EST_Control register */
#define XGMAC_MTL_EST_CONTROL_PTOV_MASK \
        0xFF800000U
#define XGMAC_MTL_EST_CONTROL_PTOV_POS \
        23U
#define XGMAC_MTL_EST_CONTROL_CTOV_MASK \
        0x007FF800U
#define XGMAC_MTL_EST_CONTROL_CTOV_POS \
        11U
#define XGMAC_MTL_EST_CONTROL_TILS_MASK \
        0x00000700U
#define XGMAC_MTL_EST_CONTROL_TILS_POS \
        8U
#define XGMAC_MTL_EST_CONTROL_LCSE_MASK \
        0x000000C0U
#define XGMAC_MTL_EST_CONTROL_LCSE_POS \
        6U
#define XGMAC_MTL_EST_CONTROL_DFBS_MASK \
        0x00000020U
#define XGMAC_MTL_EST_CONTROL_DFBS_POS \
        5U
#define XGMAC_MTL_EST_CONTROL_DDBF_MASK \
        0x00000010U
#define XGMAC_MTL_EST_CONTROL_DDBF_POS \
        4U
#define XGMAC_MTL_EST_CONTROL_QHLBF_MASK \
        0x00000008U
#define XGMAC_MTL_EST_CONTROL_QHLBF_POS \
        3U
#define XGMAC_MTL_EST_CONTROL_SSWL_MASK \
        0x00000002U
#define XGMAC_MTL_EST_CONTROL_SSWL_POS \
        1U
#define XGMAC_MTL_EST_CONTROL_EEST_MASK \
        0x00000001U
#define XGMAC_MTL_EST_CONTROL_EEST_POS \
        0U

/* Bit fields of MTL_EST_Overhead register */
#define XGMAC_MTL_EST_OVERHEAD_OVHD_MASK \
        0x000000FFU
#define XGMAC_MTL_EST_OVERHEAD_OVHD_POS \
        0U

/* Bit fields of MTL_EST_Status register */
#define XGMAC_MTL_EST_STATUS_CGSN_MASK \
        0x000F0000U
#define XGMAC_MTL_EST_STATUS_CGSN_POS \
        16U
#define XGMAC_MTL_EST_STATUS_BTRL_MASK \
        0x0000FF00U
#define XGMAC_MTL_EST_STATUS_BTRL_POS \
        8U
#define XGMAC_MTL_EST_STATUS_SWOL_MASK \
        0x00000080U
#define XGMAC_MTL_EST_STATUS_SWOL_POS \
        7U
#define XGMAC_MTL_EST_STATUS_CGCE_MASK \
        0x00000010U
#define XGMAC_MTL_EST_STATUS_CGCE_POS \
        4U
#define XGMAC_MTL_EST_STATUS_HLBS_MASK \
        0x00000008U
#define XGMAC_MTL_EST_STATUS_HLBS_POS \
        3U
#define XGMAC_MTL_EST_STATUS_HLBF_MASK \
        0x00000004U
#define XGMAC_MTL_EST_STATUS_HLBF_POS \
        2U
#define XGMAC_MTL_EST_STATUS_BTRE_MASK \
        0x00000002U
#define XGMAC_MTL_EST_STATUS_BTRE_POS \
        1U
#define XGMAC_MTL_EST_STATUS_SWLC_MASK \
        0x00000001U
#define XGMAC_MTL_EST_STATUS_SWLC_POS \
        0U

/* Bit fields of MTL_EST_Sch_Error register */
#define XGMAC_MTL_EST_SCH_ERROR_SETN_MASK \
        0x000000FFU
#define XGMAC_MTL_EST_SCH_ERROR_SETN_POS \
        0U

/* Bit fields of MTL_EST_Frm_Size_Error register */
#define XGMAC_MTL_EST_FRM_SIZE_ERROR_FETN_MASK \
        0x000000FFU
#define XGMAC_MTL_EST_FRM_SIZE_ERROR_FETN_POS \
        0U

/* Bit fields of MTL_EST_Frm_Size_Capture register */
#define XGMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK \
        0x00070000U
#define XGMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_POS \
        16U
#define XGMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK \
        0x00007FFFU
#define XGMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_POS \
        0U

/* Bit fields of MTL_EST_Intr_Enable register */
#define XGMAC_MTL_EST_INTR_ENABLE_CGCE_MASK \
        0x00000010U
#define XGMAC_MTL_EST_INTR_ENABLE_CGCE_POS \
        4U
#define XGMAC_MTL_EST_INTR_ENABLE_IEHS_MASK \
        0x00000008U
#define XGMAC_MTL_EST_INTR_ENABLE_IEHS_POS \
        3U
#define XGMAC_MTL_EST_INTR_ENABLE_IEHF_MASK \
        0x00000004U
#define XGMAC_MTL_EST_INTR_ENABLE_IEHF_POS \
        2U
#define XGMAC_MTL_EST_INTR_ENABLE_IEBE_MASK \
        0x00000002U
#define XGMAC_MTL_EST_INTR_ENABLE_IEBE_POS \
        1U
#define XGMAC_MTL_EST_INTR_ENABLE_IECC_MASK \
        0x00000001U
#define XGMAC_MTL_EST_INTR_ENABLE_IECC_POS \
        0U

/* Bit fields of MTL_GCL_Control register */
#define XGMAC_MTL_GCL_CONTROL_GCLEIEC_MASK \
        0x00800000U
#define XGMAC_MTL_GCL_CONTROL_GCLEIEC_POS \
        23U
#define XGMAC_MTL_GCL_CONTROL_GCLEIAEE_MASK \
        0x00400000U
#define XGMAC_MTL_GCL_CONTROL_GCLEIAEE_POS \
        22U
#define XGMAC_MTL_GCL_CONTROL_GCLEIEE_MASK \
        0x00200000U
#define XGMAC_MTL_GCL_CONTROL_GCLEIEE_POS \
        21U
#define XGMAC_MTL_GCL_CONTROL_ADDR_MASK \
        0x0000FF00U
#define XGMAC_MTL_GCL_CONTROL_ADDR_POS \
        8U
#define XGMAC_MTL_GCL_CONTROL_DBGB_MASK \
        0x00000020U
#define XGMAC_MTL_GCL_CONTROL_DBGB_POS \
        5U
#define XGMAC_MTL_GCL_CONTROL_DBGM_MASK \
        0x00000010U
#define XGMAC_MTL_GCL_CONTROL_DBGM_POS \
        4U
#define XGMAC_MTL_GCL_CONTROL_GCRR_MASK \
        0x00000004U
#define XGMAC_MTL_GCL_CONTROL_GCRR_POS \
        2U
#define XGMAC_MTL_GCL_CONTROL_R1W0_MASK \
        0x00000002U
#define XGMAC_MTL_GCL_CONTROL_R1W0_POS \
        1U
#define XGMAC_MTL_GCL_CONTROL_SRWO_MASK \
        0x00000001U
#define XGMAC_MTL_GCL_CONTROL_SRWO_POS \
        0U

/* Bit fields of MTL_GCL_Data register */
#define XGMAC_MTL_GCL_DATA_GCD_MASK \
        0xFFFFFFFFU
#define XGMAC_MTL_GCL_DATA_GCD_POS \
        0U

/* Bit fields of MTL_FPE_CTRL_STS register */
#define XGMAC_MTL_FPE_CTRL_STS_HRS_MASK \
        0x10000000U
#define XGMAC_MTL_FPE_CTRL_STS_HRS_POS \
        28U
#define XGMAC_MTL_FPE_CTRL_STS_PHRSC_MASK \
        0x00010000U
#define XGMAC_MTL_FPE_CTRL_STS_PHRSC_POS \
        16U
#define XGMAC_MTL_FPE_CTRL_STS_PEC_MASK \
        0x0000FF00U
#define XGMAC_MTL_FPE_CTRL_STS_PEC_POS \
        8U
#define XGMAC_MTL_FPE_CTRL_STS_LBHT_MASK \
        0x00000080U
#define XGMAC_MTL_FPE_CTRL_STS_LBHT_POS \
        7U
#define XGMAC_MTL_FPE_CTRL_STS_AFSZ_MASK \
        0x00000003U
#define XGMAC_MTL_FPE_CTRL_STS_AFSZ_POS \
        0U

/* Bit fields of MTL_FPE_Advance register */
#define XGMAC_MTL_FPE_ADVANCE_RADV_MASK \
        0xFFFF0000U
#define XGMAC_MTL_FPE_ADVANCE_RADV_POS \
        16U
#define XGMAC_MTL_FPE_ADVANCE_HADV_MASK \
        0x0000FFFFU
#define XGMAC_MTL_FPE_ADVANCE_HADV_POS \
        0U

/* Bit fields of MTL_TxQ0_Operation_Mode register */
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ0_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ0_Underflow register */
#define XGMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ0_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ0_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ0_Debug register */
#define XGMAC_MTL_TXQ0_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ0_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ0_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ0_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ0_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ0_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ0_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ0_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ0_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC0_ETS_Control register */
#define XGMAC_MTL_TC0_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC0_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC0_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC0_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC0_ETS_Status register */
#define XGMAC_MTL_TC0_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC0_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC0_Quantum_Weight register */
#define XGMAC_MTL_TC0_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC0_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ0_Operation_Mode register */
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ0_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ0_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ0_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ0_Debug register */
#define XGMAC_MTL_RXQ0_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ0_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ0_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ0_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ0_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ0_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ0_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ0_Control register */
#define XGMAC_MTL_RXQ0_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ0_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ0_Flow_Control register */
#define XGMAC_MTL_RXQ0_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ0_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ0_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ0_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q0_Interrupt_Enable register */
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q0_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q0_Interrupt_Status register */
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q0_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ1_Operation_Mode register */
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ1_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ1_Underflow register */
#define XGMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ1_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ1_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ1_Debug register */
#define XGMAC_MTL_TXQ1_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ1_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ1_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ1_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ1_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ1_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ1_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ1_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ1_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ1_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC1_ETS_Control register */
#define XGMAC_MTL_TC1_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC1_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC1_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC1_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC1_ETS_Status register */
#define XGMAC_MTL_TC1_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC1_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC1_Quantum_Weight register */
#define XGMAC_MTL_TC1_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC1_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ1_Operation_Mode register */
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ1_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ1_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ1_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ1_Debug register */
#define XGMAC_MTL_RXQ1_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ1_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ1_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ1_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ1_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ1_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ1_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ1_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ1_Control register */
#define XGMAC_MTL_RXQ1_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ1_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ1_Flow_Control register */
#define XGMAC_MTL_RXQ1_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ1_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ1_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ1_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q1_Interrupt_Enable register */
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q1_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q1_Interrupt_Status register */
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q1_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ2_Operation_Mode register */
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ2_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ2_Underflow register */
#define XGMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ2_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ2_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ2_Debug register */
#define XGMAC_MTL_TXQ2_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ2_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ2_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ2_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ2_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ2_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ2_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ2_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ2_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ2_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC2_ETS_Control register */
#define XGMAC_MTL_TC2_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC2_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC2_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC2_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC2_ETS_Status register */
#define XGMAC_MTL_TC2_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC2_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC2_Quantum_Weight register */
#define XGMAC_MTL_TC2_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC2_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ2_Operation_Mode register */
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ2_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ2_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ2_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ2_Debug register */
#define XGMAC_MTL_RXQ2_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ2_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ2_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ2_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ2_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ2_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ2_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ2_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ2_Control register */
#define XGMAC_MTL_RXQ2_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ2_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ2_Flow_Control register */
#define XGMAC_MTL_RXQ2_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ2_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ2_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ2_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q2_Interrupt_Enable register */
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q2_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q2_Interrupt_Status register */
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q2_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ3_Operation_Mode register */
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ3_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ3_Underflow register */
#define XGMAC_MTL_TXQ3_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ3_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ3_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ3_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ3_Debug register */
#define XGMAC_MTL_TXQ3_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ3_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ3_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ3_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ3_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ3_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ3_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ3_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ3_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ3_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC3_ETS_Control register */
#define XGMAC_MTL_TC3_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC3_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC3_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC3_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC3_ETS_Status register */
#define XGMAC_MTL_TC3_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC3_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC3_Quantum_Weight register */
#define XGMAC_MTL_TC3_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC3_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ3_Operation_Mode register */
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ3_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ3_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ3_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ3_Debug register */
#define XGMAC_MTL_RXQ3_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ3_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ3_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ3_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ3_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ3_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ3_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ3_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ3_Control register */
#define XGMAC_MTL_RXQ3_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ3_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ3_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ3_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ3_Flow_Control register */
#define XGMAC_MTL_RXQ3_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ3_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ3_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ3_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q3_Interrupt_Enable register */
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q3_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q3_Interrupt_Status register */
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q3_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ4_Operation_Mode register */
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ4_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ4_Underflow register */
#define XGMAC_MTL_TXQ4_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ4_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ4_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ4_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ4_Debug register */
#define XGMAC_MTL_TXQ4_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ4_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ4_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ4_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ4_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ4_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ4_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ4_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ4_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ4_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC4_ETS_Control register */
#define XGMAC_MTL_TC4_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC4_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC4_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC4_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC4_ETS_Status register */
#define XGMAC_MTL_TC4_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC4_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC4_Quantum_Weight register */
#define XGMAC_MTL_TC4_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC4_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ4_Operation_Mode register */
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ4_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ4_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ4_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ4_Debug register */
#define XGMAC_MTL_RXQ4_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ4_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ4_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ4_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ4_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ4_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ4_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ4_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ4_Control register */
#define XGMAC_MTL_RXQ4_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ4_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ4_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ4_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ4_Flow_Control register */
#define XGMAC_MTL_RXQ4_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ4_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ4_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ4_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q4_Interrupt_Enable register */
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q4_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q4_Interrupt_Status register */
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q4_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ5_Operation_Mode register */
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ5_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ5_Underflow register */
#define XGMAC_MTL_TXQ5_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ5_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ5_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ5_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ5_Debug register */
#define XGMAC_MTL_TXQ5_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ5_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ5_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ5_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ5_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ5_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ5_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ5_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ5_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ5_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC5_ETS_Control register */
#define XGMAC_MTL_TC5_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC5_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC5_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC5_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC5_ETS_Status register */
#define XGMAC_MTL_TC5_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC5_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC5_Quantum_Weight register */
#define XGMAC_MTL_TC5_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC5_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ5_Operation_Mode register */
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ5_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ5_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ5_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ5_Debug register */
#define XGMAC_MTL_RXQ5_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ5_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ5_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ5_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ5_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ5_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ5_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ5_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ5_Control register */
#define XGMAC_MTL_RXQ5_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ5_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ5_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ5_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ5_Flow_Control register */
#define XGMAC_MTL_RXQ5_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ5_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ5_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ5_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q5_Interrupt_Enable register */
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q5_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q5_Interrupt_Status register */
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q5_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ6_Operation_Mode register */
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ6_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ6_Underflow register */
#define XGMAC_MTL_TXQ6_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ6_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ6_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ6_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ6_Debug register */
#define XGMAC_MTL_TXQ6_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ6_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ6_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ6_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ6_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ6_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ6_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ6_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ6_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ6_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC6_ETS_Control register */
#define XGMAC_MTL_TC6_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC6_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC6_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC6_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC6_ETS_Status register */
#define XGMAC_MTL_TC6_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC6_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC6_Quantum_Weight register */
#define XGMAC_MTL_TC6_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC6_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_RxQ6_Operation_Mode register */
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ6_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ6_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ6_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ6_Debug register */
#define XGMAC_MTL_RXQ6_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ6_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ6_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ6_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ6_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ6_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ6_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ6_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ6_Control register */
#define XGMAC_MTL_RXQ6_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ6_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ6_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ6_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ6_Flow_Control register */
#define XGMAC_MTL_RXQ6_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ6_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ6_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ6_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q6_Interrupt_Enable register */
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q6_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q6_Interrupt_Status register */
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q6_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of MTL_TxQ7_Operation_Mode register */
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TQS_MASK \
        0x007F0000U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TQS_POS \
        16U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_Q2TCMAP_MASK \
        0x00000700U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_Q2TCMAP_POS \
        8U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TTC_MASK \
        0x00000070U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TTC_POS \
        4U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TXQEN_MASK \
        0x0000000CU
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TXQEN_POS \
        2U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TSF_MASK \
        0x00000002U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_TSF_POS \
        1U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_FTQ_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ7_OPERATION_MODE_FTQ_POS \
        0U

/* Bit fields of MTL_TxQ7_Underflow register */
#define XGMAC_MTL_TXQ7_UNDERFLOW_UFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_TXQ7_UNDERFLOW_UFCNTOVF_POS \
        15U
#define XGMAC_MTL_TXQ7_UNDERFLOW_UFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_TXQ7_UNDERFLOW_UFPKTCNT_POS \
        0U

/* Bit fields of MTL_TxQ7_Debug register */
#define XGMAC_MTL_TXQ7_DEBUG_TRCPSTS_MASK \
        0x00000020U
#define XGMAC_MTL_TXQ7_DEBUG_TRCPSTS_POS \
        5U
#define XGMAC_MTL_TXQ7_DEBUG_TXQSTS_MASK \
        0x00000010U
#define XGMAC_MTL_TXQ7_DEBUG_TXQSTS_POS \
        4U
#define XGMAC_MTL_TXQ7_DEBUG_TWCSTS_MASK \
        0x00000008U
#define XGMAC_MTL_TXQ7_DEBUG_TWCSTS_POS \
        3U
#define XGMAC_MTL_TXQ7_DEBUG_TRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_TXQ7_DEBUG_TRCSTS_POS \
        1U
#define XGMAC_MTL_TXQ7_DEBUG_TCPAUSED_MASK \
        0x00000001U
#define XGMAC_MTL_TXQ7_DEBUG_TCPAUSED_POS \
        0U

/* Bit fields of MTL_TC7_ETS_Control register */
#define XGMAC_MTL_TC7_ETS_CONTROL_SLC_MASK \
        0x00000070U
#define XGMAC_MTL_TC7_ETS_CONTROL_SLC_POS \
        4U
#define XGMAC_MTL_TC7_ETS_CONTROL_CC_MASK \
        0x00000008U
#define XGMAC_MTL_TC7_ETS_CONTROL_CC_POS \
        3U
#define XGMAC_MTL_TC7_ETS_CONTROL_CBSEN_MASK \
        0x00000004U
#define XGMAC_MTL_TC7_ETS_CONTROL_CBSEN_POS \
        2U
#define XGMAC_MTL_TC7_ETS_CONTROL_TSA_MASK \
        0x00000003U
#define XGMAC_MTL_TC7_ETS_CONTROL_TSA_POS \
        0U

/* Bit fields of MTL_TC7_ETS_Status register */
#define XGMAC_MTL_TC7_ETS_STATUS_ABS_MASK \
        0x00FFFFFFU
#define XGMAC_MTL_TC7_ETS_STATUS_ABS_POS \
        0U

/* Bit fields of MTL_TC7_Quantum_Weight register */
#define XGMAC_MTL_TC7_QUANTUM_WEIGHT_QW_MASK \
        0x001FFFFFU
#define XGMAC_MTL_TC7_QUANTUM_WEIGHT_QW_POS \
        0U

/* Bit fields of MTL_TC7_SendSlopeCredit register */
#define XGMAC_MTL_TC7_SENDSLOPECREDIT_SSC_MASK \
        0x0000FFFFU
#define XGMAC_MTL_TC7_SENDSLOPECREDIT_SSC_POS \
        0U

/* Bit fields of MTL_TC7_HiCredit register */
#define XGMAC_MTL_TC7_HICREDIT_HC_MASK \
        0x1FFFFFFFU
#define XGMAC_MTL_TC7_HICREDIT_HC_POS \
        0U

/* Bit fields of MTL_TC7_LoCredit register */
#define XGMAC_MTL_TC7_LOCREDIT_LC_MASK \
        0x1FFFFFFFU
#define XGMAC_MTL_TC7_LOCREDIT_LC_POS \
        0U

/* Bit fields of MTL_RxQ7_Operation_Mode register */
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RQS_MASK \
        0x003F0000U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RQS_POS \
        16U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_EHFC_MASK \
        0x00000080U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_EHFC_POS \
        7U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_DIS_TCP_EF_MASK \
        0x00000040U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_DIS_TCP_EF_POS \
        6U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RSF_MASK \
        0x00000020U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RSF_POS \
        5U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_FEF_MASK \
        0x00000010U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_FEF_POS \
        4U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_FUF_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_FUF_POS \
        3U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RTC_MASK \
        0x00000003U
#define XGMAC_MTL_RXQ7_OPERATION_MODE_RTC_POS \
        0U

/* Bit fields of MTL_RxQ7_Missed_Pkt_Overflow_Cnt register */
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_MASK \
        0x80000000U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_MISCNTOVF_POS \
        31U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_MASK \
        0x07FF0000U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_MISPKTCNT_POS \
        16U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_MASK \
        0x00008000U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_OVFCNTOVF_POS \
        15U
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_MASK \
        0x000007FFU
#define XGMAC_MTL_RXQ7_MISSED_PKT_OVERFLOW_CNT_OVFPKTCNT_POS \
        0U

/* Bit fields of MTL_RxQ7_Debug register */
#define XGMAC_MTL_RXQ7_DEBUG_PRXQ_MASK \
        0x3FFF0000U
#define XGMAC_MTL_RXQ7_DEBUG_PRXQ_POS \
        16U
#define XGMAC_MTL_RXQ7_DEBUG_RXQSTS_MASK \
        0x00000030U
#define XGMAC_MTL_RXQ7_DEBUG_RXQSTS_POS \
        4U
#define XGMAC_MTL_RXQ7_DEBUG_RRCSTS_MASK \
        0x00000006U
#define XGMAC_MTL_RXQ7_DEBUG_RRCSTS_POS \
        1U
#define XGMAC_MTL_RXQ7_DEBUG_RWCSTS_MASK \
        0x00000001U
#define XGMAC_MTL_RXQ7_DEBUG_RWCSTS_POS \
        0U

/* Bit fields of MTL_RxQ7_Control register */
#define XGMAC_MTL_RXQ7_CONTROL_RXQ_PKT_ARBIT_MASK \
        0x00000008U
#define XGMAC_MTL_RXQ7_CONTROL_RXQ_PKT_ARBIT_POS \
        3U
#define XGMAC_MTL_RXQ7_CONTROL_RXQ_WEGT_MASK \
        0x00000007U
#define XGMAC_MTL_RXQ7_CONTROL_RXQ_WEGT_POS \
        0U

/* Bit fields of MTL_RxQ7_Flow_Control register */
#define XGMAC_MTL_RXQ7_FLOW_CONTROL_RFD_MASK \
        0x003E0000U
#define XGMAC_MTL_RXQ7_FLOW_CONTROL_RFD_POS \
        17U
#define XGMAC_MTL_RXQ7_FLOW_CONTROL_RFA_MASK \
        0x0000003EU
#define XGMAC_MTL_RXQ7_FLOW_CONTROL_RFA_POS \
        1U

/* Bit fields of MTL_Q7_Interrupt_Enable register */
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_RXOIE_MASK \
        0x00010000U
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_RXOIE_POS \
        16U
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_ABPSIE_MASK \
        0x00000002U
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_ABPSIE_POS \
        1U
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_TXUIE_MASK \
        0x00000001U
#define XGMAC_MTL_Q7_INTERRUPT_ENABLE_TXUIE_POS \
        0U

/* Bit fields of MTL_Q7_Interrupt_Status register */
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_RXOVFIS_MASK \
        0x00010000U
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_RXOVFIS_POS \
        16U
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_ABPSIS_MASK \
        0x00000002U
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_ABPSIS_POS \
        1U
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_TXUNFIS_MASK \
        0x00000001U
#define XGMAC_MTL_Q7_INTERRUPT_STATUS_TXUNFIS_POS \
        0U

/* Bit fields of DMA_Mode register */
#define XGMAC_DMA_MODE_INTM_MASK \
        0x00003000U
#define XGMAC_DMA_MODE_INTM_POS \
        12U
#define XGMAC_DMA_MODE_DSPW_MASK \
        0x00000100U
#define XGMAC_DMA_MODE_DSPW_POS \
        8U
#define XGMAC_DMA_MODE_TDRP_MASK \
        0x00000010U
#define XGMAC_DMA_MODE_TDRP_POS \
        4U
#define XGMAC_DMA_MODE_SWR_MASK \
        0x00000001U
#define XGMAC_DMA_MODE_SWR_POS \
        0U

/* Bit fields of DMA_SysBus_Mode register */
#define XGMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_MASK \
        0x1F000000U
#define XGMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_POS \
        24U
#define XGMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_MASK \
        0x001F0000U
#define XGMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_POS \
        16U
#define XGMAC_DMA_SYSBUS_MODE_EN_LPI_MASK \
        0x00008000U
#define XGMAC_DMA_SYSBUS_MODE_EN_LPI_POS \
        15U
#define XGMAC_DMA_SYSBUS_MODE_LPI_XIT_PKT_MASK \
        0x00004000U
#define XGMAC_DMA_SYSBUS_MODE_LPI_XIT_PKT_POS \
        14U
#define XGMAC_DMA_SYSBUS_MODE_ONEKBBE_MASK \
        0x00002000U
#define XGMAC_DMA_SYSBUS_MODE_ONEKBBE_POS \
        13U
#define XGMAC_DMA_SYSBUS_MODE_AAL_MASK \
        0x00001000U
#define XGMAC_DMA_SYSBUS_MODE_AAL_POS \
        12U
#define XGMAC_DMA_SYSBUS_MODE_EAME_MASK \
        0x00000800U
#define XGMAC_DMA_SYSBUS_MODE_EAME_POS \
        11U
#define XGMAC_DMA_SYSBUS_MODE_AALE_MASK \
        0x00000400U
#define XGMAC_DMA_SYSBUS_MODE_AALE_POS \
        10U
#define XGMAC_DMA_SYSBUS_MODE_BLEN256_MASK \
        0x00000080U
#define XGMAC_DMA_SYSBUS_MODE_BLEN256_POS \
        7U
#define XGMAC_DMA_SYSBUS_MODE_BLEN128_MASK \
        0x00000040U
#define XGMAC_DMA_SYSBUS_MODE_BLEN128_POS \
        6U
#define XGMAC_DMA_SYSBUS_MODE_BLEN64_MASK \
        0x00000020U
#define XGMAC_DMA_SYSBUS_MODE_BLEN64_POS \
        5U
#define XGMAC_DMA_SYSBUS_MODE_BLEN32_MASK \
        0x00000010U
#define XGMAC_DMA_SYSBUS_MODE_BLEN32_POS \
        4U
#define XGMAC_DMA_SYSBUS_MODE_BLEN16_MASK \
        0x00000008U
#define XGMAC_DMA_SYSBUS_MODE_BLEN16_POS \
        3U
#define XGMAC_DMA_SYSBUS_MODE_BLEN8_MASK \
        0x00000004U
#define XGMAC_DMA_SYSBUS_MODE_BLEN8_POS \
        2U
#define XGMAC_DMA_SYSBUS_MODE_BLEN4_MASK \
        0x00000002U
#define XGMAC_DMA_SYSBUS_MODE_BLEN4_POS \
        1U
#define XGMAC_DMA_SYSBUS_MODE_UBL_MASK \
        0x00000001U
#define XGMAC_DMA_SYSBUS_MODE_UBL_POS \
        0U

/* Bit fields of DMA_Interrupt_Status register */
#define XGMAC_DMA_INTERRUPT_STATUS_MACIS_MASK \
        0x00020000U
#define XGMAC_DMA_INTERRUPT_STATUS_MACIS_POS \
        17U
#define XGMAC_DMA_INTERRUPT_STATUS_MTLIS_MASK \
        0x00010000U
#define XGMAC_DMA_INTERRUPT_STATUS_MTLIS_POS \
        16U
#define XGMAC_DMA_INTERRUPT_STATUS_DC15TC8IS_MASK \
        0x0000FF00U
#define XGMAC_DMA_INTERRUPT_STATUS_DC15TC8IS_POS \
        8U
#define XGMAC_DMA_INTERRUPT_STATUS_DC7IS_MASK \
        0x00000080U
#define XGMAC_DMA_INTERRUPT_STATUS_DC7IS_POS \
        7U
#define XGMAC_DMA_INTERRUPT_STATUS_DC6IS_MASK \
        0x00000040U
#define XGMAC_DMA_INTERRUPT_STATUS_DC6IS_POS \
        6U
#define XGMAC_DMA_INTERRUPT_STATUS_DC5IS_MASK \
        0x00000020U
#define XGMAC_DMA_INTERRUPT_STATUS_DC5IS_POS \
        5U
#define XGMAC_DMA_INTERRUPT_STATUS_DC4IS_MASK \
        0x00000010U
#define XGMAC_DMA_INTERRUPT_STATUS_DC4IS_POS \
        4U
#define XGMAC_DMA_INTERRUPT_STATUS_DC3IS_MASK \
        0x00000008U
#define XGMAC_DMA_INTERRUPT_STATUS_DC3IS_POS \
        3U
#define XGMAC_DMA_INTERRUPT_STATUS_DC2IS_MASK \
        0x00000004U
#define XGMAC_DMA_INTERRUPT_STATUS_DC2IS_POS \
        2U
#define XGMAC_DMA_INTERRUPT_STATUS_DC1IS_MASK \
        0x00000002U
#define XGMAC_DMA_INTERRUPT_STATUS_DC1IS_POS \
        1U
#define XGMAC_DMA_INTERRUPT_STATUS_DC0IS_MASK \
        0x00000001U
#define XGMAC_DMA_INTERRUPT_STATUS_DC0IS_POS \
        0U

/* Bit fields of AXI_Tx_AR_ACE_Control register */
#define XGMAC_AXI_TX_AR_ACE_CONTROL_THD_MASK \
        0x00300000U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_THD_POS \
        20U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_THC_MASK \
        0x000F0000U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_THC_POS \
        16U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TED_MASK \
        0x00003000U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TED_POS \
        12U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TEC_MASK \
        0x00000F00U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TEC_POS \
        8U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TDRD_MASK \
        0x00000030U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TDRD_POS \
        4U
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TDRC_MASK \
        0x0000000FU
#define XGMAC_AXI_TX_AR_ACE_CONTROL_TDRC_POS \
        0U

/* Bit fields of AXI_Rx_AW_ACE_Control register */
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDD_MASK \
        0x30000000U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDD_POS \
        28U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDC_MASK \
        0x0F000000U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDC_POS \
        24U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RHD_MASK \
        0x00300000U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RHD_POS \
        20U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RHC_MASK \
        0x000F0000U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RHC_POS \
        16U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RPD_MASK \
        0x00003000U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RPD_POS \
        12U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RPC_MASK \
        0x00000F00U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RPC_POS \
        8U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDWD_MASK \
        0x00000030U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDWD_POS \
        4U
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDWC_MASK \
        0x0000000FU
#define XGMAC_AXI_RX_AW_ACE_CONTROL_RDWC_POS \
        0U

/* Bit fields of AXI_TxRx_AWAR_ACE_Control register */
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_WRP_MASK \
        0x00700000U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_WRP_POS \
        20U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDP_MASK \
        0x00070000U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDP_POS \
        16U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDRD_MASK \
        0x00003000U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDRD_POS \
        12U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDRC_MASK \
        0x00000F00U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_RDRC_POS \
        8U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_TDWD_MASK \
        0x00000030U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_TDWD_POS \
        4U
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_TDWC_MASK \
        0x0000000FU
#define XGMAC_AXI_TXRX_AWAR_ACE_CONTROL_TDWC_POS \
        0U

/* Bit fields of DMA_Debug_Status0 register */
#define XGMAC_DMA_DEBUG_STATUS0_TPS2_MASK \
        0xF0000000U
#define XGMAC_DMA_DEBUG_STATUS0_TPS2_POS \
        28U
#define XGMAC_DMA_DEBUG_STATUS0_RPS2_MASK \
        0x0F000000U
#define XGMAC_DMA_DEBUG_STATUS0_RPS2_POS \
        24U
#define XGMAC_DMA_DEBUG_STATUS0_TPS1_MASK \
        0x00F00000U
#define XGMAC_DMA_DEBUG_STATUS0_TPS1_POS \
        20U
#define XGMAC_DMA_DEBUG_STATUS0_RPS1_MASK \
        0x000F0000U
#define XGMAC_DMA_DEBUG_STATUS0_RPS1_POS \
        16U
#define XGMAC_DMA_DEBUG_STATUS0_TPS0_MASK \
        0x0000F000U
#define XGMAC_DMA_DEBUG_STATUS0_TPS0_POS \
        12U
#define XGMAC_DMA_DEBUG_STATUS0_RPS0_MASK \
        0x00000F00U
#define XGMAC_DMA_DEBUG_STATUS0_RPS0_POS \
        8U
#define XGMAC_DMA_DEBUG_STATUS0_AXRHSTS_MASK \
        0x00000002U
#define XGMAC_DMA_DEBUG_STATUS0_AXRHSTS_POS \
        1U
#define XGMAC_DMA_DEBUG_STATUS0_AXWHSTS_MASK \
        0x00000001U
#define XGMAC_DMA_DEBUG_STATUS0_AXWHSTS_POS \
        0U

/* Bit fields of DMA_Debug_Status1 register */
#define XGMAC_DMA_DEBUG_STATUS1_TDAS_MASK \
        0x000000FFU
#define XGMAC_DMA_DEBUG_STATUS1_TDAS_POS \
        0U

/* Bit fields of DMA_Debug_Status3 register */
#define XGMAC_DMA_DEBUG_STATUS3_RDAS_MASK \
        0x000000FFU
#define XGMAC_DMA_DEBUG_STATUS3_RDAS_POS \
        0U

/* Bit fields of DMA_Tx_EDMA_Control register */
#define XGMAC_DMA_TX_EDMA_CONTROL_TEDM_MASK \
        0xC0000000U
#define XGMAC_DMA_TX_EDMA_CONTROL_TEDM_POS \
        30U
#define XGMAC_DMA_TX_EDMA_CONTROL_TDPS_MASK \
        0x00000003U
#define XGMAC_DMA_TX_EDMA_CONTROL_TDPS_POS \
        0U

/* Bit fields of DMA_Rx_EDMA_Control register */
#define XGMAC_DMA_RX_EDMA_CONTROL_REDM_MASK \
        0xC0000000U
#define XGMAC_DMA_RX_EDMA_CONTROL_REDM_POS \
        30U
#define XGMAC_DMA_RX_EDMA_CONTROL_RDPS_MASK \
        0x00000003U
#define XGMAC_DMA_RX_EDMA_CONTROL_RDPS_POS \
        0U

/* Bit fields of AXI_LPI_Entry_Interval register */
#define XGMAC_AXI_LPI_ENTRY_INTERVAL_LPIEI_MASK \
        0x0000000FU
#define XGMAC_AXI_LPI_ENTRY_INTERVAL_LPIEI_POS \
        0U

/* Bit fields of DMA_TBS_CTRL0 register */
#define XGMAC_DMA_TBS_CTRL0_FTOS_MASK \
        0xFFFFFF00U
#define XGMAC_DMA_TBS_CTRL0_FTOS_POS \
        8U
#define XGMAC_DMA_TBS_CTRL0_FGOS_MASK \
        0x00000070U
#define XGMAC_DMA_TBS_CTRL0_FGOS_POS \
        4U
#define XGMAC_DMA_TBS_CTRL0_FTOV_MASK \
        0x00000001U
#define XGMAC_DMA_TBS_CTRL0_FTOV_POS \
        0U

/* Bit fields of DMA_TBS_CTRL1 register */
#define XGMAC_DMA_TBS_CTRL1_FTOS_MASK \
        0xFFFFFF00U
#define XGMAC_DMA_TBS_CTRL1_FTOS_POS \
        8U
#define XGMAC_DMA_TBS_CTRL1_FGOS_MASK \
        0x00000070U
#define XGMAC_DMA_TBS_CTRL1_FGOS_POS \
        4U
#define XGMAC_DMA_TBS_CTRL1_FTOV_MASK \
        0x00000001U
#define XGMAC_DMA_TBS_CTRL1_FTOV_POS \
        0U

/* Bit fields of DMA_TBS_CTRL2 register */
#define XGMAC_DMA_TBS_CTRL2_FTOS_MASK \
        0xFFFFFF00U
#define XGMAC_DMA_TBS_CTRL2_FTOS_POS \
        8U
#define XGMAC_DMA_TBS_CTRL2_FGOS_MASK \
        0x00000070U
#define XGMAC_DMA_TBS_CTRL2_FGOS_POS \
        4U
#define XGMAC_DMA_TBS_CTRL2_FTOV_MASK \
        0x00000001U
#define XGMAC_DMA_TBS_CTRL2_FTOV_POS \
        0U

/* Bit fields of DMA_TBS_CTRL3 register */
#define XGMAC_DMA_TBS_CTRL3_FTOS_MASK \
        0xFFFFFF00U
#define XGMAC_DMA_TBS_CTRL3_FTOS_POS \
        8U
#define XGMAC_DMA_TBS_CTRL3_FGOS_MASK \
        0x00000070U
#define XGMAC_DMA_TBS_CTRL3_FGOS_POS \
        4U
#define XGMAC_DMA_TBS_CTRL3_FTOV_MASK \
        0x00000001U
#define XGMAC_DMA_TBS_CTRL3_FTOV_POS \
        0U

/* Bit fields of DMA_CH_Ind_Ctrl register */
#define XGMAC_DMA_CH_IND_CTRL_MSEL_MASK \
        0x000F0000U
#define XGMAC_DMA_CH_IND_CTRL_MSEL_POS \
        16U
#define XGMAC_DMA_CH_IND_CTRL_AOFF_MASK \
        0x00000F00U
#define XGMAC_DMA_CH_IND_CTRL_AOFF_POS \
        8U
#define XGMAC_DMA_CH_IND_CTRL_AUTO_MASK \
        0x00000030U
#define XGMAC_DMA_CH_IND_CTRL_AUTO_POS \
        4U
#define XGMAC_DMA_CH_IND_CTRL_CT_MASK \
        0x00000002U
#define XGMAC_DMA_CH_IND_CTRL_CT_POS \
        1U
#define XGMAC_DMA_CH_IND_CTRL_OB_MASK \
        0x00000001U
#define XGMAC_DMA_CH_IND_CTRL_OB_POS \
        0U

/* Bit fields of DMA_CH_Ind_Data register */
#define XGMAC_DMA_CH_IND_DATA_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH_IND_DATA_WT_POS \
        0U

/* Bit fields of DMA_CH0_TxExtCfg register */
#define XGMAC_DMA_CH0_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH0_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH1_TxExtCfg register */
#define XGMAC_DMA_CH1_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH1_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH2_TxExtCfg register */
#define XGMAC_DMA_CH2_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH2_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH3_TxExtCfg register */
#define XGMAC_DMA_CH3_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH3_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH4_TxExtCfg register */
#define XGMAC_DMA_CH4_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH4_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH5_TxExtCfg register */
#define XGMAC_DMA_CH5_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH5_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH6_TxExtCfg register */
#define XGMAC_DMA_CH6_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH6_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH7_TxExtCfg register */
#define XGMAC_DMA_CH7_TXEXTCFG_WT_MASK \
        0x0000007FU
#define XGMAC_DMA_CH7_TXEXTCFG_WT_POS \
        0U

/* Bit fields of DMA_CH0_Control register */
#define XGMAC_DMA_CH0_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH0_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH0_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH0_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH0_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH0_CONTROL_PBLX8_POS \
        16U
#define XGMAC_DMA_CH0_CONTROL_MSS_MASK \
        0x00003FFFU
#define XGMAC_DMA_CH0_CONTROL_MSS_POS \
        0U

/* Bit fields of DMA_CH0_Tx_Control register */
#define XGMAC_DMA_CH0_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH0_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH0_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH0_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH0_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH0_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH0_TX_CONTROL_TSE_MASK \
        0x00001000U
#define XGMAC_DMA_CH0_TX_CONTROL_TSE_POS \
        12U
#define XGMAC_DMA_CH0_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH0_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH0_Rx_Control register */
#define XGMAC_DMA_CH0_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH0_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH0_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH0_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH0_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH0_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH0_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH0_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH0_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH0_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH0_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH0_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH0_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH0_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH0_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH0_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH0_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH0_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH0_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH0_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH0_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH0_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH0_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH0_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH0_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH0_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH0_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH0_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH0_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH0_Tx_Control2 register */
#define XGMAC_DMA_CH0_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH0_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH0_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH0_Rx_Control2 register */
#define XGMAC_DMA_CH0_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH0_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH0_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH0_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH0_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH0_Interrupt_Enable register */
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH0_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH0_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH0_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH0_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH0_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH0_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH0_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH0_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH0_Status register */
#define XGMAC_DMA_CH0_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH0_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH0_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH0_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH0_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH0_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH0_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH0_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH0_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH0_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH0_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH0_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH0_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH0_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH0_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH0_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH0_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH0_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH0_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH0_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH0_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH0_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH0_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH0_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH0_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH0_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH0_Debug_Status register */
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH0_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH0_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH0_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH0_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH0_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH0_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH0_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH0_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH0_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH0_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH0_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH0_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH0_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH0_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH0_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH0_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH0_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH0_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH0_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH0_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH0_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH1_Control register */
#define XGMAC_DMA_CH1_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH1_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH1_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH1_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH1_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH1_CONTROL_PBLX8_POS \
        16U
#define XGMAC_DMA_CH1_CONTROL_MSS_MASK \
        0x00003FFFU
#define XGMAC_DMA_CH1_CONTROL_MSS_POS \
        0U

/* Bit fields of DMA_CH1_Tx_Control register */
#define XGMAC_DMA_CH1_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH1_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH1_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH1_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH1_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH1_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH1_TX_CONTROL_TSE_MASK \
        0x00001000U
#define XGMAC_DMA_CH1_TX_CONTROL_TSE_POS \
        12U
#define XGMAC_DMA_CH1_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH1_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH1_Rx_Control register */
#define XGMAC_DMA_CH1_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH1_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH1_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH1_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH1_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH1_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH1_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH1_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH1_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH1_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH1_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH1_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH1_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH1_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH1_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH1_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH1_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH1_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH1_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH1_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH1_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH1_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH1_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH1_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH1_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH1_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH1_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH1_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH1_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH1_Tx_Control2 register */
#define XGMAC_DMA_CH1_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH1_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH1_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH1_Rx_Control2 register */
#define XGMAC_DMA_CH1_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH1_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH1_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH1_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH1_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH1_Interrupt_Enable register */
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH1_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH1_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH1_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH1_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH1_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH1_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH1_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH1_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH1_Status register */
#define XGMAC_DMA_CH1_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH1_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH1_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH1_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH1_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH1_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH1_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH1_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH1_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH1_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH1_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH1_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH1_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH1_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH1_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH1_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH1_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH1_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH1_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH1_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH1_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH1_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH1_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH1_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH1_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH1_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH1_Debug_Status register */
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH1_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH1_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH1_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH1_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH1_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH1_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH1_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH1_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH1_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH1_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH1_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH1_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH1_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH1_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH1_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH1_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH1_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH1_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH1_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH1_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH1_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH2_Control register */
#define XGMAC_DMA_CH2_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH2_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH2_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH2_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH2_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH2_CONTROL_PBLX8_POS \
        16U
#define XGMAC_DMA_CH2_CONTROL_MSS_MASK \
        0x00003FFFU
#define XGMAC_DMA_CH2_CONTROL_MSS_POS \
        0U

/* Bit fields of DMA_CH2_Tx_Control register */
#define XGMAC_DMA_CH2_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH2_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH2_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH2_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH2_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH2_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH2_TX_CONTROL_TSE_MASK \
        0x00001000U
#define XGMAC_DMA_CH2_TX_CONTROL_TSE_POS \
        12U
#define XGMAC_DMA_CH2_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH2_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH2_Rx_Control register */
#define XGMAC_DMA_CH2_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH2_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH2_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH2_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH2_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH2_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH2_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH2_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH2_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH2_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH2_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH2_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH2_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH2_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH2_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH2_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH2_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH2_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH2_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH2_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH2_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH2_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH2_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH2_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH2_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH2_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH2_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH2_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH2_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH2_Tx_Control2 register */
#define XGMAC_DMA_CH2_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH2_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH2_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH2_Rx_Control2 register */
#define XGMAC_DMA_CH2_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH2_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH2_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH2_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH2_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH2_Interrupt_Enable register */
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH2_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH2_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH2_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH2_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH2_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH2_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH2_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH2_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH2_Status register */
#define XGMAC_DMA_CH2_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH2_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH2_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH2_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH2_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH2_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH2_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH2_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH2_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH2_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH2_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH2_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH2_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH2_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH2_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH2_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH2_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH2_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH2_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH2_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH2_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH2_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH2_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH2_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH2_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH2_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH2_Debug_Status register */
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH2_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH2_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH2_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH2_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH2_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH2_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH2_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH2_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH2_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH2_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH2_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH2_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH2_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH2_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH2_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH2_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH2_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH2_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH2_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH2_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH2_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH3_Control register */
#define XGMAC_DMA_CH3_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH3_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH3_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH3_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH3_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH3_CONTROL_PBLX8_POS \
        16U
#define XGMAC_DMA_CH3_CONTROL_MSS_MASK \
        0x00003FFFU
#define XGMAC_DMA_CH3_CONTROL_MSS_POS \
        0U

/* Bit fields of DMA_CH3_Tx_Control register */
#define XGMAC_DMA_CH3_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH3_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH3_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH3_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH3_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH3_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH3_TX_CONTROL_TSE_MASK \
        0x00001000U
#define XGMAC_DMA_CH3_TX_CONTROL_TSE_POS \
        12U
#define XGMAC_DMA_CH3_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH3_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH3_Rx_Control register */
#define XGMAC_DMA_CH3_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH3_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH3_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH3_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH3_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH3_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH3_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH3_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH3_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH3_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH3_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH3_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH3_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH3_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH3_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH3_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH3_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH3_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH3_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH3_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH3_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH3_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH3_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH3_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH3_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH3_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH3_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH3_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH3_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH3_Tx_Control2 register */
#define XGMAC_DMA_CH3_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH3_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH3_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH3_Rx_Control2 register */
#define XGMAC_DMA_CH3_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH3_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH3_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH3_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH3_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH3_Interrupt_Enable register */
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH3_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH3_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH3_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH3_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH3_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH3_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH3_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH3_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH3_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH3_Status register */
#define XGMAC_DMA_CH3_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH3_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH3_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH3_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH3_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH3_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH3_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH3_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH3_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH3_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH3_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH3_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH3_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH3_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH3_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH3_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH3_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH3_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH3_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH3_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH3_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH3_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH3_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH3_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH3_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH3_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH3_Debug_Status register */
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH3_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH3_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH3_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH3_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH3_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH3_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH3_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH3_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH3_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH3_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH3_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH3_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH3_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH3_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH3_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH3_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH3_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH3_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH3_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH3_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH3_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH4_Control register */
#define XGMAC_DMA_CH4_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH4_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH4_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH4_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH4_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH4_CONTROL_PBLX8_POS \
        16U

/* Bit fields of DMA_CH4_Tx_Control register */
#define XGMAC_DMA_CH4_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH4_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH4_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH4_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH4_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH4_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH4_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH4_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH4_Rx_Control register */
#define XGMAC_DMA_CH4_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH4_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH4_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH4_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH4_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH4_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH4_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH4_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH4_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH4_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH4_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH4_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH4_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH4_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH4_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH4_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH4_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH4_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH4_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH4_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH4_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH4_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH4_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH4_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH4_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH4_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH4_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH4_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH4_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH4_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH4_Tx_Control2 register */
#define XGMAC_DMA_CH4_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH4_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH4_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH4_Rx_Control2 register */
#define XGMAC_DMA_CH4_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH4_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH4_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH4_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH4_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH4_Interrupt_Enable register */
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH4_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH4_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH4_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH4_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH4_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH4_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH4_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH4_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH4_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH4_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH4_Status register */
#define XGMAC_DMA_CH4_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH4_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH4_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH4_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH4_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH4_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH4_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH4_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH4_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH4_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH4_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH4_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH4_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH4_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH4_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH4_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH4_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH4_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH4_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH4_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH4_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH4_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH4_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH4_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH4_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH4_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH4_Debug_Status register */
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH4_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH4_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH4_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH4_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH4_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH4_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH4_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH4_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH4_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH4_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH4_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH4_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH4_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH4_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH4_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH4_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH4_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH4_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH4_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH4_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH4_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH5_Control register */
#define XGMAC_DMA_CH5_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH5_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH5_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH5_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH5_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH5_CONTROL_PBLX8_POS \
        16U

/* Bit fields of DMA_CH5_Tx_Control register */
#define XGMAC_DMA_CH5_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH5_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH5_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH5_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH5_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH5_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH5_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH5_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH5_Rx_Control register */
#define XGMAC_DMA_CH5_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH5_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH5_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH5_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH5_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH5_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH5_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH5_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH5_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH5_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH5_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH5_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH5_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH5_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH5_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH5_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH5_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH5_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH5_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH5_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH5_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH5_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH5_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH5_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH5_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH5_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH5_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH5_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH5_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH5_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH5_Tx_Control2 register */
#define XGMAC_DMA_CH5_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH5_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH5_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH5_Rx_Control2 register */
#define XGMAC_DMA_CH5_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH5_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH5_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH5_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH5_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH5_Interrupt_Enable register */
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH5_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH5_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH5_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH5_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH5_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH5_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH5_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH5_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH5_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH5_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH5_Status register */
#define XGMAC_DMA_CH5_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH5_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH5_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH5_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH5_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH5_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH5_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH5_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH5_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH5_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH5_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH5_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH5_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH5_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH5_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH5_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH5_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH5_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH5_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH5_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH5_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH5_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH5_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH5_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH5_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH5_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH5_Debug_Status register */
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH5_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH5_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH5_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH5_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH5_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH5_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH5_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH5_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH5_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH5_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH5_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH5_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH5_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH5_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH5_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH5_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH5_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH5_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH5_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH5_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH5_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH6_Control register */
#define XGMAC_DMA_CH6_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH6_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH6_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH6_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH6_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH6_CONTROL_PBLX8_POS \
        16U

/* Bit fields of DMA_CH6_Tx_Control register */
#define XGMAC_DMA_CH6_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH6_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH6_TX_CONTROL_EDSE_MASK \
        0x10000000U
#define XGMAC_DMA_CH6_TX_CONTROL_EDSE_POS \
        28U
#define XGMAC_DMA_CH6_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH6_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH6_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH6_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH6_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH6_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH6_Rx_Control register */
#define XGMAC_DMA_CH6_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH6_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH6_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH6_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH6_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH6_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH6_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH6_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH6_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH6_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH6_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH6_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH6_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH6_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH6_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH6_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH6_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH6_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH6_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH6_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH6_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH6_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH6_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH6_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH6_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH6_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH6_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH6_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH6_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH6_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH6_Tx_Control2 register */
#define XGMAC_DMA_CH6_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH6_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH6_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH6_Rx_Control2 register */
#define XGMAC_DMA_CH6_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH6_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH6_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH6_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH6_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH6_Interrupt_Enable register */
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH6_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH6_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH6_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH6_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH6_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH6_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH6_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH6_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH6_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH6_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH6_Status register */
#define XGMAC_DMA_CH6_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH6_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH6_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH6_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH6_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH6_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH6_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH6_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH6_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH6_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH6_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH6_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH6_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH6_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH6_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH6_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH6_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH6_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH6_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH6_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH6_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH6_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH6_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH6_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH6_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH6_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH6_Debug_Status register */
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH6_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH6_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH6_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH6_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH6_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH6_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH6_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH6_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH6_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH6_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH6_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH6_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH6_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH6_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH6_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH6_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH6_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH6_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH6_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH6_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH6_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH7_Control register */
#define XGMAC_DMA_CH7_CONTROL_SPH_MASK \
        0x01000000U
#define XGMAC_DMA_CH7_CONTROL_SPH_POS \
        24U
#define XGMAC_DMA_CH7_CONTROL_DSL_MASK \
        0x001C0000U
#define XGMAC_DMA_CH7_CONTROL_DSL_POS \
        18U
#define XGMAC_DMA_CH7_CONTROL_PBLX8_MASK \
        0x00010000U
#define XGMAC_DMA_CH7_CONTROL_PBLX8_POS \
        16U

/* Bit fields of DMA_CH7_Tx_Control register */
#define XGMAC_DMA_CH7_TX_CONTROL_TFSEL_MASK \
        0x60000000U
#define XGMAC_DMA_CH7_TX_CONTROL_TFSEL_POS \
        29U
#define XGMAC_DMA_CH7_TX_CONTROL_EDSE_MASK \
        0x10000000U
#define XGMAC_DMA_CH7_TX_CONTROL_EDSE_POS \
        28U
#define XGMAC_DMA_CH7_TX_CONTROL_TQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH7_TX_CONTROL_TQOS_POS \
        24U
#define XGMAC_DMA_CH7_TX_CONTROL_TXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH7_TX_CONTROL_TXPBL_POS \
        16U
#define XGMAC_DMA_CH7_TX_CONTROL_ST_MASK \
        0x00000001U
#define XGMAC_DMA_CH7_TX_CONTROL_ST_POS \
        0U

/* Bit fields of DMA_CH7_Rx_Control register */
#define XGMAC_DMA_CH7_RX_CONTROL_RPF_MASK \
        0x80000000U
#define XGMAC_DMA_CH7_RX_CONTROL_RPF_POS \
        31U
#define XGMAC_DMA_CH7_RX_CONTROL_RQOS_MASK \
        0x0F000000U
#define XGMAC_DMA_CH7_RX_CONTROL_RQOS_POS \
        24U
#define XGMAC_DMA_CH7_RX_CONTROL_RXPBL_MASK \
        0x003F0000U
#define XGMAC_DMA_CH7_RX_CONTROL_RXPBL_POS \
        16U
#define XGMAC_DMA_CH7_RX_CONTROL_RBSZ_MASK \
        0x00007FF0U
#define XGMAC_DMA_CH7_RX_CONTROL_RBSZ_POS \
        4U
#define XGMAC_DMA_CH7_RX_CONTROL_SR_MASK \
        0x00000001U
#define XGMAC_DMA_CH7_RX_CONTROL_SR_POS \
        0U

/* Bit fields of DMA_CH7_Slot_Function_Control_Status register */
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK \
        0x000F0000U
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_RSN_POS \
        16U
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK \
        0x00000002U
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_ASC_POS \
        1U
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK \
        0x00000001U
#define XGMAC_DMA_CH7_SLOT_FUNCTION_CONTROL_STATUS_ESC_POS \
        0U

/* Bit fields of DMA_CH7_TxDesc_List_HAddress register */
#define XGMAC_DMA_CH7_TXDESC_LIST_HADDRESS_TDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH7_TXDESC_LIST_HADDRESS_TDESHA_POS \
        0U

/* Bit fields of DMA_CH7_TxDesc_List_LAddress register */
#define XGMAC_DMA_CH7_TXDESC_LIST_LADDRESS_TDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH7_TXDESC_LIST_LADDRESS_TDESLA_POS \
        3U

/* Bit fields of DMA_CH7_RxDesc_List_HAddress register */
#define XGMAC_DMA_CH7_RXDESC_LIST_HADDRESS_RDESHA_MASK \
        0x000000FFU
#define XGMAC_DMA_CH7_RXDESC_LIST_HADDRESS_RDESHA_POS \
        0U

/* Bit fields of DMA_CH7_RxDesc_List_LAddress register */
#define XGMAC_DMA_CH7_RXDESC_LIST_LADDRESS_RDESLA_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH7_RXDESC_LIST_LADDRESS_RDESLA_POS \
        3U

/* Bit fields of DMA_CH7_TxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH7_TXDESC_TAIL_LPOINTER_TDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH7_TXDESC_TAIL_LPOINTER_TDT_POS \
        3U

/* Bit fields of DMA_CH7_RxDesc_Tail_LPointer register */
#define XGMAC_DMA_CH7_RXDESC_TAIL_LPOINTER_RDT_MASK \
        0xFFFFFFF8U
#define XGMAC_DMA_CH7_RXDESC_TAIL_LPOINTER_RDT_POS \
        3U

/* Bit fields of DMA_CH7_Tx_Control2 register */
#define XGMAC_DMA_CH7_TX_CONTROL2_ORRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH7_TX_CONTROL2_ORRQ_POS \
        24U
#define XGMAC_DMA_CH7_TX_CONTROL2_TDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_TX_CONTROL2_TDRL_POS \
        0U

/* Bit fields of DMA_CH7_Rx_Control2 register */
#define XGMAC_DMA_CH7_RX_CONTROL2_OWRQ_MASK \
        0x03000000U
#define XGMAC_DMA_CH7_RX_CONTROL2_OWRQ_POS \
        24U
#define XGMAC_DMA_CH7_RX_CONTROL2_ARBS_MASK \
        0x00FE0000U
#define XGMAC_DMA_CH7_RX_CONTROL2_ARBS_POS \
        17U
#define XGMAC_DMA_CH7_RX_CONTROL2_RDRL_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_RX_CONTROL2_RDRL_POS \
        0U

/* Bit fields of DMA_CH7_Interrupt_Enable register */
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_NIE_MASK \
        0x00008000U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_NIE_POS \
        15U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_AIE_MASK \
        0x00004000U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_AIE_POS \
        14U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_CDEE_MASK \
        0x00002000U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_CDEE_POS \
        13U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_FBEE_MASK \
        0x00001000U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_FBEE_POS \
        12U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_DDEE_MASK \
        0x00000200U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_DDEE_POS \
        9U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RSE_MASK \
        0x00000100U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RSE_POS \
        8U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RBUE_MASK \
        0x00000080U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RBUE_POS \
        7U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RIE_MASK \
        0x00000040U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_RIE_POS \
        6U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TBUE_MASK \
        0x00000004U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TBUE_POS \
        2U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TXSE_MASK \
        0x00000002U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TXSE_POS \
        1U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TIE_MASK \
        0x00000001U
#define XGMAC_DMA_CH7_INTERRUPT_ENABLE_TIE_POS \
        0U

/* Bit fields of DMA_CH7_Rx_Interrupt_Watchdog_Timer register */
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_MASK \
        0x80000000U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_PSEL_POS \
        31U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_MASK \
        0x03FF0000U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RBCT_POS \
        16U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK \
        0x00003000U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_POS \
        12U
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK \
        0x000000FFU
#define XGMAC_DMA_CH7_RX_INTERRUPT_WATCHDOG_TIMER_RWT_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_TxDesc_L register */
#define XGMAC_DMA_CH7_CURRENT_APP_TXDESC_L_CURTDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH7_CURRENT_APP_TXDESC_L_CURTDESAPTR_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_RxDesc_L register */
#define XGMAC_DMA_CH7_CURRENT_APP_RXDESC_L_CURRDESAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH7_CURRENT_APP_RXDESC_L_CURRDESAPTR_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_TxBuffer_H register */
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_H_CURTBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_TxBuffer_L register */
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH7_CURRENT_APP_TXBUFFER_L_CURTBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_RxBuffer_H register */
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_MASK \
        0x000000FFU
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_H_CURRBUFAPTRH_POS \
        0U

/* Bit fields of DMA_CH7_Current_App_RxBuffer_L register */
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_MASK \
        0xFFFFFFFFU
#define XGMAC_DMA_CH7_CURRENT_APP_RXBUFFER_L_CURRBUFAPTR_POS \
        0U

/* Bit fields of DMA_CH7_Status register */
#define XGMAC_DMA_CH7_STATUS_REB_MASK \
        0x00380000U
#define XGMAC_DMA_CH7_STATUS_REB_POS \
        19U
#define XGMAC_DMA_CH7_STATUS_TEB_MASK \
        0x00070000U
#define XGMAC_DMA_CH7_STATUS_TEB_POS \
        16U
#define XGMAC_DMA_CH7_STATUS_NIS_MASK \
        0x00008000U
#define XGMAC_DMA_CH7_STATUS_NIS_POS \
        15U
#define XGMAC_DMA_CH7_STATUS_AIS_MASK \
        0x00004000U
#define XGMAC_DMA_CH7_STATUS_AIS_POS \
        14U
#define XGMAC_DMA_CH7_STATUS_CDE_MASK \
        0x00002000U
#define XGMAC_DMA_CH7_STATUS_CDE_POS \
        13U
#define XGMAC_DMA_CH7_STATUS_FBE_MASK \
        0x00001000U
#define XGMAC_DMA_CH7_STATUS_FBE_POS \
        12U
#define XGMAC_DMA_CH7_STATUS_DDE_MASK \
        0x00000200U
#define XGMAC_DMA_CH7_STATUS_DDE_POS \
        9U
#define XGMAC_DMA_CH7_STATUS_RPS_MASK \
        0x00000100U
#define XGMAC_DMA_CH7_STATUS_RPS_POS \
        8U
#define XGMAC_DMA_CH7_STATUS_RBU_MASK \
        0x00000080U
#define XGMAC_DMA_CH7_STATUS_RBU_POS \
        7U
#define XGMAC_DMA_CH7_STATUS_RI_MASK \
        0x00000040U
#define XGMAC_DMA_CH7_STATUS_RI_POS \
        6U
#define XGMAC_DMA_CH7_STATUS_TBU_MASK \
        0x00000004U
#define XGMAC_DMA_CH7_STATUS_TBU_POS \
        2U
#define XGMAC_DMA_CH7_STATUS_TPS_MASK \
        0x00000002U
#define XGMAC_DMA_CH7_STATUS_TPS_POS \
        1U
#define XGMAC_DMA_CH7_STATUS_TI_MASK \
        0x00000001U
#define XGMAC_DMA_CH7_STATUS_TI_POS \
        0U

/* Bit fields of DMA_CH7_Debug_Status register */
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDWS_MASK \
        0x70000000U
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDWS_POS \
        28U
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDTS_MASK \
        0x0FF80000U
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDTS_POS \
        19U
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDFS_MASK \
        0x00070000U
#define XGMAC_DMA_CH7_DEBUG_STATUS_RDFS_POS \
        16U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDWS_MASK \
        0x00007000U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDWS_POS \
        12U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDTS_MASK \
        0x00000F00U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDTS_POS \
        8U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDRS_MASK \
        0x000000C0U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDRS_POS \
        6U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDXS_MASK \
        0x00000038U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDXS_POS \
        3U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDFS_MASK \
        0x00000007U
#define XGMAC_DMA_CH7_DEBUG_STATUS_TDFS_POS \
        0U

/* Bit fields of DMA_CH7_Desc_Mem_Cache_Fill_Level register */
#define XGMAC_DMA_CH7_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_MASK \
        0x007F0000U
#define XGMAC_DMA_CH7_DESC_MEM_CACHE_FILL_LEVEL_RX_FILL_LVL_POS \
        16U
#define XGMAC_DMA_CH7_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_MASK \
        0x0000007FU
#define XGMAC_DMA_CH7_DESC_MEM_CACHE_FILL_LEVEL_TX_FILL_LVL_POS \
        0U

/* Bit fields of DMA_CH7_Miss_Packet_Cnt register */
#define XGMAC_DMA_CH7_MISS_PACKET_CNT_MFCO_MASK \
        0x00008000U
#define XGMAC_DMA_CH7_MISS_PACKET_CNT_MFCO_POS \
        15U
#define XGMAC_DMA_CH7_MISS_PACKET_CNT_MFC_MASK \
        0x000007FFU
#define XGMAC_DMA_CH7_MISS_PACKET_CNT_MFC_POS \
        0U

/* Bit fields of DMA_CH7_Tx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH7_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_TX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH7_Rx_Data_Xfer_Ring_Offset register */
#define XGMAC_DMA_CH7_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_RX_DATA_XFER_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH7_Tx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH7_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_TX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

/* Bit fields of DMA_CH7_Rx_Desc_Write_Ring_Offset register */
#define XGMAC_DMA_CH7_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_MASK \
        0x0000FFFFU
#define XGMAC_DMA_CH7_RX_DESC_WRITE_RING_OFFSET_DESC_OFFSET_POS \
        0U

#ifdef __cplusplus
}
#endif

#endif /* ifndef __SOCFPGA_XGMAC_REG_H__ */
