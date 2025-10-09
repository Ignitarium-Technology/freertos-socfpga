/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for SoC FPGA XGMAC low level driver
 */

#ifndef __SOCFPGA_XGMAC_LL_H__
#define __SOCFPGA_XGMAC_LL_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "socfpga_xgmac_reg.h"
#include "socfpga_cache.h"

#define BIT(nr)    (1UL << (nr))
#define TRUE                          (1)
#define FALSE                         (-1)
#define XGMAC_MAC_CONF_SS_1G_GMII     3U
#define XGMAC_MAC_CONF_SS_100M_MII    4U
#define XGMAC_MAC_CONF_SS_10M_MII     7U

#define EQOS_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_DCB    2
#define EQOS_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_AV     1

#define XGMAC_DMA_CH0_TX_CONTROL_OSP    BIT(4)
#define XGMAC_MAC_EXT_CONF_HD           BIT(24)

#define MAC_ADRRESS_INDEX1    1

#define XGMAC_RESET_ASSERT         (1)
#define XGMAC_RESET_DEASSERT       (0)
#define XGMAC_LL_RETVAL_SUCCESS    (0x1)
#define XGMAC_LL_RETVAL_FAIL       (0xFF)

#define XGMAC_PHY_TYPE_GMII          0U
#define XGMAC_PHY_TYPE_RMII          2U
#define XGMAC_PHY_TYPE_SGMII         3U
#define XGMAC_PHY_TYPE_SGMII_PLUS    4U

#define XGMAC_DMA_TRANSMIT_START    1U
#define XGMAC_DMA_RECEIVE_START     2U
#define XGMAC_DMA_TRANSMIT_STOP     3U
#define XGMAC_DMA_RECEIVE_STOP      4U

#define XGMAC_GET_BASE_ADDRESS(instance)         ((uint32_t)(XGMAC_EMAC_BASEADDR + \
    ((uint32_t)(instance) * 0x10000U)))
#define XGMAC_GET_CORE_BASE_ADDRESS(instance)    ((uint32_t)(XGMAC_EMAC_CORE_BASEADDR + \
    ((instance) * 0x10000)))
#define XGMAC_GET_DMA_BASE_ADDRESS(instance)     ((uint32_t)(XGMAC_EMAC_DMA_BASEADDR + \
    ((uint32_t)(instance) * 0x10000U)))
#define XGMAC_GET_MTL_BASE_ADDRESS(instance)     ((uint32_t)(XGMAC_EMAC_MTL_BASEADDR + \
    ((uint32_t)(instance) * 0x10000U)))

#define XGMAC_DMA_INTR_POS_TI      0U
#define XGMAC_DMA_INTR_MASK_TI     0x00000001U
#define XGMAC_DMA_INTR_POS_TXS     1U
#define XGMAC_DMA_INTR_MASK_TXS    0x00000002U
#define XGMAC_DMA_INTR_POS_TBU     2U
#define XGMAC_DMA_INTR_MASK_TBU    0x00000004U

#define XGMAC_DMA_INTR_POS_RI      6U
#define XGMAC_DMA_INTR_MASK_RI     0x00000040U
#define XGMAC_DMA_INTR_POS_RBU     7U
#define XGMAC_DMA_INTR_MASK_RBU    0x00000080U
#define XGMAC_DMA_INTR_POS_RS      8U
#define XGMAC_DMA_INTR_MASK_RS     0x00000100U
#define XGMAC_DMA_INTR_POS_DDE     9U
#define XGMAC_DMA_INTR_MASK_DDE    0x00000200U

#define XGMAC_DMA_INTR_POS_FBE     12U
#define XGMAC_DMA_INTR_MASK_FBE    0x00001000U
#define XGMAC_DMA_INTR_POS_CDE     13U
#define XGMAC_DMA_INTR_MASK_CDE    0x00002000U
#define XGMAC_DMA_INTR_POS_AIS     14U
#define XGMAC_DMA_INTR_MASK_AIS    0x00004000U
#define XGMAC_DMA_INTR_POS_NIS     15U
#define XGMAC_DMA_INTR_MASK_NIS    0x00008000U

#define XGMAC_MMC_IPC_RX_INTR_MASK_ALL    0xFFFFFFFFU
/* Get the fifo size in bytes from Feature1 register
 * */
#define XGMAC_MTL_RX_FIFOSZ_BYTES(feature1_val)    (128U << (((feature1_val) & \
    XGMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK) >> XGMAC_MAC_HW_FEATURE1_RXFIFOSIZE_POS))

#define XGMAC_MTL_TX_FIFOSZ_BYTES(feature1_val)    (128U << (((feature1_val) & \
    XGMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK) >> XGMAC_MAC_HW_FEATURE1_TXFIFOSIZE_POS))

/* calculate block count from fifo size in bytes (256 bytes per block, value 0 means 256 bytes)
 * */
#define XGMAC_MTL_RX_FIFO_BLK_CNT(feature1_val)    ((XGMAC_MTL_RX_FIFOSZ_BYTES(feature1_val) >> 8) - \
    1U)
#define XGMAC_MTL_TX_FIFO_BLK_CNT(feature1_val)    ((XGMAC_MTL_TX_FIFOSZ_BYTES(feature1_val) >> 8) - \
    1U)

/* Common register bit set/clear macros */
#define ENABLE_BIT(address, bit)     (*(uint32_t volatile *)((uintptr_t)(address)) |= (bit))
#define DISABLE_BIT(address, bit)    (*(uint32_t volatile *)((uintptr_t)(address)) &= ~(bit))

/* MAC register bit enable/disable macros */
#define ENABLE_MAC_FLOW_CNTL_REGBIT(addr, queueindx, bit)     (*(uint32_t \
    volatile *)((uintptr_t)(addr) + ((queueindx) * XGMAC_TX_FLOW_CONTROL_INC)) |= (bit))
#define DISABLE_MAC_FLOW_CNTL_REGBIT(addr, queueindx, bit)    (*(uint32_t \
    volatile *)((uintptr_t)(addr) + ((queueindx) * XGMAC_TX_FLOW_CONTROL_INC)) &= ~(bit))

/* MTL register bit enable/disable macros */
#define ENABLE_MTL_QX_REGBIT(addr, queueindx, bit)     (*(uint32_t volatile *)((uintptr_t)(addr) + \
    XGMAC_MTL_TC_BASE + ((queueindx) * XGMAC_MTL_TC_INC)) |= (bit))
#define DISABLE_MTL_QX_REGBIT(addr, queueindx, bit)    (*(uint32_t volatile *)((uintptr_t)(addr) + \
    XGMAC_MTL_TC_BASE + ((queueindx) * XGMAC_MTL_TC_INC)) &= ~(bit))

/* MTL register read/write macros */
#define RD_MTL_QX_REG32(base_address, queue_indx, reg_offset)          *(uint32_t \
    volatile *)((uintptr_t)(base_address) + XGMAC_MTL_TC_BASE + ((queue_indx) *   \
    XGMAC_MTL_TC_INC) + (reg_offset))
#define WR_MTL_QX_REG32(base_address, queue_indx, reg_offset, data)    (*(uint32_t \
    volatile *)((uintptr_t)(base_address) + XGMAC_MTL_TC_BASE + ((queue_indx) *    \
    XGMAC_MTL_TC_INC) + (reg_offset)) = (data))

/* DMA register bit enable/disable macros */
#define ENABLE_DMA_CHNL_REGBIT(addr, channel, bit)     (*(uint32_t volatile *)((uintptr_t)(addr) + \
    XGMAC_DMA_CHANNEL_BASE + ((channel) * XGMAC_DMA_CHANNEL_INC)) |= (bit))
#define DISABLE_DMA_CHNL_REGBIT(addr, channel, bit)    (*(uint32_t volatile *)((uintptr_t)(addr) + \
    XGMAC_DMA_CHANNEL_BASE + ((channel) * XGMAC_DMA_CHANNEL_INC)) &= ~(bit))

/* DMA register read/write macros */
#define RD_DMA_CHNL_REG32(base_address, channel, reg_offset)          *(uint32_t  \
    volatile *)((uintptr_t)(base_address) + XGMAC_DMA_CHANNEL_BASE + ((channel) * \
    XGMAC_DMA_CHANNEL_INC) + (reg_offset))
#define WR_DMA_CHNL_REG32(base_address, channel, reg_offset, data)    (*(uint32_t \
    volatile *)((uintptr_t)(base_address) + XGMAC_DMA_CHANNEL_BASE + ((channel) * \
    XGMAC_DMA_CHANNEL_INC) + (reg_offset)) = (data))

typedef enum
{
    INTERRUPT_TI,       /* Transmit Interrupt .*/
    INTERRUPT_TXS,      /* Transmit Stopped. */
    INTERRUPT_TBU,      /*Transmit Buffer Unavailable.*/
    INTERRUPT_RI,       /* Receive Interrupt */
    INTERRUPT_RBU,      /* Receive Buffer Unavailable */
    INTERRUPT_RS,       /* Receive Stopped */
    INTERRUPT_DDE,      /* Descriptor Definition Error  */
    INTERRUPT_FBE,      /* Fatal Bus Error  */
    INTERRUPT_CDE,      /* Context Descriptor Error  */
    INTERRUPT_AIS,      /* Abnormal Interrupt Summary */
    INTERRUPT_NIS,      /* Normal Interrupt Summary */
    INTERRUPT_UNHANDLED      /* Unhandled Interrupt  */
} xgmac_dma_interrupt_id_t;

typedef bool Basetype_t;

typedef struct
{
    uint32_t tx_ring_len;
    uint32_t rx_ring_len;
    uint32_t tx_desc_high_addr;
    uint32_t tx_desc_low_addr;
    uint32_t rx_desc_high_addr;
    uint32_t rx_desc_low_addr;
    uint32_t tx_last_desc_addr;
    uint32_t rx_last_desc_addr;
} xgmac_dma_desc_addr_t;

/*
 * @brief  Configuration structure for XGMAC DMA Parameters
 */
typedef struct
{
    bool ubl;
    bool blen4;
    bool blen8;
    bool blen16;
    bool blen32;
    bool blen64;
    bool blen128;
    bool blen256;
    bool aal;
    bool eame;
    uint8_t rd_osr_lmt;
    uint8_t wr_osr_lmt;
} xgmacdma_config_t;


/*
 * @brief  Configuration structure for XGMAC DMA Channel Parameters
 */
typedef struct
{
    /* DMA channel Control register fields */
    bool pblx8;
    bool sph;
    uint8_t dsl;

    /* DMA channel Tx Control register fields */
    bool tse;
    uint8_t txpbl;
    uint8_t tqos;

    /* DMA channel Rx Control register fields */
    uint8_t rxpbl;
    uint8_t rqos;
    uint16_t rbsz;
} xgmacdma_chanl_config_t;


/*
 * @brief  Configuration structure for XGMAC MAC Rx parameters
 */
typedef struct
{
    /* MAC RxQ control0 register fields */
    uint8_t rxq0en;
    uint8_t rxq1en;
    uint8_t rxq2en;
    uint8_t rxq3en;
    uint8_t rxq4en;
    uint8_t rxq5en;
    uint8_t rxq6en;
    uint8_t rxq7en;

    /* MAC RxQ control1 register fields */
    bool mcbcqen;
} xgmacmac_rx_q_ctrl_config_t;


/*
 * @brief   Configuration structure for XGMAC MTL Tx Queue parameters
 */
typedef struct
{
    bool tsf;
    uint8_t txqen;
    uint8_t tqs;
} xgmacmtl_tx_queue_config_t;


/*
 * @brief   Configuration structure for XGMAC MTL Rx Queue parameters
 */
typedef struct
{
    bool rsf;
    bool ehfc;
    uint8_t rqs;
} xgmacmtl_rx_queue_config_t;


/*
 * @brief  Configuration structure for XGMAC MAC Tx Flow Control parameters
 */
typedef struct
{
    bool fcb;
    bool tfe;
    uint8_t plt;
    bool dzpq;
    uint32_t pt;
} xgmacmac_tx_flow_ctrl_config_t;

/*
 * @brief  Configuration structure for XGMAC MAC Rx Flow Control parameters
 */
typedef struct
{
    bool rfe;
    bool up;
    bool pfce;
} xgmacmac_rx_flow_ctrl_config_t;


/*
 * @brief  Configuration structure for XGMAC MAC Tx parameters
 */
typedef struct
{
    bool jd;
} xgmacmac_tx_config_t;


/*
 * @brief  Configuration structure for XGMAC MAC Rx parameters
 */
typedef struct
{
    bool acs;
    bool cst;
    bool dcrcc;
    bool spen;
    bool usp;
    bool gpslce;
    bool wd;
    bool je;
    bool ipc;
    uint16_t gpsl;
    bool arpen;
} xgmacmac_rx_config_t;

/*
 * @brief  Configuration structure for XGMAC MAC Packet Filter parameters
 */
typedef struct
{
    bool pr;
    bool huc;
    bool hmc;
    bool daif;
    bool pm;
    bool dbf;
    uint8_t pcf;
    bool saif;
    bool saf;
    bool hpf;
    uint8_t dhlfrs;
    bool vtfe;
    bool ipfe;
    bool dntu;
    bool ra;
} xgmacmac_pkt_filter_config_t;

/*
 * @brief  Configuration structure for XGMAC Device Parameters
 */
typedef struct
{
    uint8_t nofdmachannels;
    uint8_t noftxqueues;
    uint8_t nofrxqueues;
} xgmac_dev_config_t;

/*
 * @brief  Configuration structure for XGMAC DMA, MTL and MAC Parameters
 */
typedef struct
{
    const xgmac_dev_config_t *mac_dev_config;
    const xgmacdma_config_t *dma_config;
    const xgmacdma_chanl_config_t *dma_channel_config;
    const xgmacmtl_tx_queue_config_t *mtl_tx_q_config;
    const xgmacmtl_rx_queue_config_t *mtl_rx_q_config;
    const xgmacmac_rx_q_ctrl_config_t *mac_rx_q_ctrl_config;
    const xgmacmac_tx_flow_ctrl_config_t *mac_tx_flow_ctrl_config;
    const xgmacmac_rx_flow_ctrl_config_t *mac_rx_flow_ctrl_config;
    const xgmacmac_tx_config_t *mac_tx_config;
    const xgmacmac_rx_config_t *mac_rx_config;
    const xgmacmac_pkt_filter_config_t *mac_pkt_filter_config;

} xgmac_dev_config_str_t;

/* MAC Function prototypes */
void xgmac_set_macaddress(uint32_t base_address, void *address_ptr, uint8_t
        index_val);
void xgmac_setduplex(uint32_t base_address, uint8_t duplex);
void xgmac_setspeed(uint32_t base_address, uint32_t speed);

void xgmac_deassert_reset(int32_t emacindex);

void xgmac_start_stop_mac_rx(uint32_t base_address, bool stflag);
void xgmac_start_stop_mac_tx(uint32_t base_address, bool stflag);

void xgmac_config_macrxqctrl_regs(uint32_t base_address, const
        xgmacmac_rx_q_ctrl_config_t *macrxqctrlconfig);
void xgmac_config_mac_frame_filter(uint32_t base_address, const
        xgmacmac_pkt_filter_config_t *macpktfilterconfig);
void xgmac_config_mac_tx(uint32_t base_address, const
        xgmacmac_tx_config_t *mactxconfig);
void xgmac_config_mac_rx(uint32_t base_address, const
        xgmacmac_rx_config_t *macrxconfig);
void xgmac_enable_tx_flow_control(uint32_t base_address, uint8_t qindx, const
        xgmacmac_tx_flow_ctrl_config_t *mactxflowctrlconfig);
void xgmac_enable_rx_flow_control(uint32_t base_address, const
        xgmacmac_rx_flow_ctrl_config_t *macrxflowctrlconfig);

void xgmac_set_mtl_tx_regs(uint32_t base_address, uint8_t qindx, const
        xgmacmtl_tx_queue_config_t *mtltxqcfgparams);
void xgmac_set_mtl_rx_regs(uint32_t base_address, uint8_t qindx, const
        xgmacmtl_rx_queue_config_t *mtlrxqcfgparams);

/* DMA Function prototypes */
void xgmac_dma_init(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig);
void xgmac_start_dma(uint32_t base_address, uint8_t dmachindx, uint8_t
        txrxflag);
void xgmac_stop_dma(uint32_t base_address, uint8_t dmachindx, uint8_t txrxflag);
void xgmac_config_dma_sysbus_mode(uint32_t base_address, const
        xgmacdma_config_t *dmaconfig);
void xgmac_init_dma_channel_desc_reg(uint32_t base_address, uint8_t dmachindx,
        xgmac_dma_desc_addr_t *dmadescparams);
void xgmac_config_dma_channel_control(uint32_t base_address, uint8_t dmachindx, const
        xgmacdma_chanl_config_t *dmachnlconfig);

int32_t xgmac_dma_software_reset(uint32_t base_address);
bool xgmac_is_dma_reset_done(uint32_t base_address);
int32_t xgmac_enable_dma_interrupt(uint32_t base_address, uint8_t chindx, xgmac_dma_interrupt_id_t
        id);
int32_t xgmac_disable_dma_interrupt(uint32_t base_address, uint8_t chindx, xgmac_dma_interrupt_id_t
        id);
void xgmac_start_dma_dev(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig);
void xgmac_stop_dma_dev(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig);

void xgmac_mtl_init (uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig);
void xgmac_mac_init(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig);
void xgmac_dev_start(uint32_t base_address);
void xgmac_dev_stop(uint32_t base_address);

void xgmac_disable_interrupt(uint32_t base_address);
xgmac_dma_interrupt_id_t check_and_clear_xgmac_interrupt_status(
    uint32_t base_address);
void check_and_clear_link_interrupt_status(uint32_t base_address);

void xgmac_invalidate_buffer(void *buf, size_t size);
void xgmac_flush_buffer(void *buf, size_t size);

void xgmac_mmc_setup(uint32_t base_address);

#endif
