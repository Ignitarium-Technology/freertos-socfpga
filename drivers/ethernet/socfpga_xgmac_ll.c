/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA XGMAC
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "socfpga_defines.h"
#include "socfpga_xgmac_ll.h"
#include "socfpga_xgmac_reg.h"
#include "socfpga_xgmac_phy_ll.h"

#define XGMAC_CLEAR_SPEED_MASK     0x1FFFFFFFU

void xgmac_set_macaddress(uint32_t base_address, void *address_ptr, uint8_t
        index_val)
{
    uint32_t mac_addr;
    uint8_t *aptr = (uint8_t *)(void *)address_ptr;
    uint32_t addr_offset;

    /* Hardware MAc Address index ranges from 1 to 32,and index will start from 0 to 31 */
    index_val--;
    addr_offset = ((uint32_t)index_val * 8U);

    /* Set the MAC bits [31:0] in MAC_Addressx_Low register*/
    mac_addr = *(aptr);
    mac_addr |= ((uint32_t)(*(aptr + 1U)) << 8U);
    mac_addr |= ((uint32_t)(*(aptr + 2U)) << 16U);
    mac_addr |= ((uint32_t)(*(aptr + 3U)) << 24U);

    WR_REG32(base_address +
            ((uint32_t)XGMAC_MAC_ADDRESS0_LOW + (uint32_t)addr_offset), mac_addr);

    /* Read the MAC_Addressx_High register and clear address bits */
    mac_addr = RD_REG32(base_address +
            ((uint32_t)XGMAC_MAC_ADDRESS0_HIGH + (uint32_t)addr_offset));

    /* Clear the lower 16 bits of the MAC_Addressx_High register */
    mac_addr &= (uint32_t)(~XGMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK);


    /* Set MAC bits [47:32] from MAC_Addressx_High[15:0]  */
    mac_addr |= (uint32_t)(*(aptr + 4U));
    mac_addr |= ((uint32_t)(*(aptr + 5U)) << 8U);

    WR_REG32(base_address +
            ((uint32_t)XGMAC_MAC_ADDRESS0_HIGH + (uint32_t)addr_offset), mac_addr);
}

void  xgmac_setduplex(uint32_t base_address, uint8_t duplex)
{
    /* Full Duplex */
    if (duplex == ETH_FULL_DUPLEX)
    {
        DISABLE_BIT(base_address + XGMAC_MAC_EXTENDED_CONFIGURATION, XGMAC_MAC_EXT_CONF_HD);
    }
    /* Half Duplex */
    else
    {
        ENABLE_BIT(base_address + XGMAC_MAC_EXTENDED_CONFIGURATION, XGMAC_MAC_EXT_CONF_HD);
    }
}
void xgmac_setspeed(uint32_t base_address, uint32_t speed)
{
    uint32_t reg_data = 0;

    reg_data = RD_REG32(base_address + XGMAC_MAC_TX_CONFIGURATION);
    reg_data &= (XGMAC_CLEAR_SPEED_MASK);
    /* 1Gbps */
    if (speed == ETH_SPEED_1000_MBPS)
    {
        reg_data |= ((uint32_t)XGMAC_MAC_CONF_SS_1G_GMII << XGMAC_MAC_TX_CONFIGURATION_SS_POS);
    }
    /* 100Mbps */
    else if (speed == ETH_SPEED_100_MBPS)
    {
        reg_data |= ((uint32_t)XGMAC_MAC_CONF_SS_100M_MII << XGMAC_MAC_TX_CONFIGURATION_SS_POS);
    }
    /* 10Mbps */
    else
    {
        reg_data |= ((uint32_t)XGMAC_MAC_CONF_SS_10M_MII << XGMAC_MAC_TX_CONFIGURATION_SS_POS);
    }

    WR_REG32(base_address + XGMAC_MAC_TX_CONFIGURATION, reg_data);
}

int32_t xgmac_dma_software_reset(uint32_t base_address)
{
    ENABLE_BIT(base_address + XGMAC_DMA_MODE, XGMAC_DMA_MODE_SWR_MASK);

    return XGMAC_LL_RETVAL_SUCCESS;
}

bool xgmac_is_dma_reset_done(uint32_t base_address)
{
    uint32_t reg_data;

    /* Check if the DMA Software Reset bit is cleared */
    reg_data = RD_REG32(base_address + XGMAC_DMA_MODE);
    return ((reg_data & XGMAC_DMA_MODE_SWR_MASK) == 0U);
}

void xgmac_dma_init(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig)
{
    xgmac_config_dma_sysbus_mode(base_address, (const xgmacdma_config_t *)
            xgmacdevconfig->dma_config);
}


void xgmac_start_dma(uint32_t base_address, uint8_t dmachindx, uint8_t txrxflag)
{
    uint32_t val;

    if (txrxflag == XGMAC_DMA_TRANSMIT_START)
    {
        val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TX_CONTROL);
        val |= (1U << XGMAC_DMA_CH_TX_CONTROL_ST_POS);
        WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TX_CONTROL, val);
    }

    if (txrxflag == XGMAC_DMA_RECEIVE_START)
    {
        val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL);
        val |= (1U << XGMAC_DMA_CH_RX_CONTROL_SR_POS);
        WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL, val);
    }
}

void xgmac_config_dma_sysbus_mode(uint32_t base_address, const
        xgmacdma_config_t *dmaconfig)
{
    uint32_t setmask = 0, clrmask = 0;

    /* Set/Clear mask bits for Undefined Burst Length */
    if (dmaconfig->ubl == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_UBL_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_UBL_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 4 */
    if (dmaconfig->blen4 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN4_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN4_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 8 */
    if (dmaconfig->blen8 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN8_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN8_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 16 */
    if (dmaconfig->blen16 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN16_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN16_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 32 */
    if (dmaconfig->blen32 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN32_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN32_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 64 */
    if (dmaconfig->blen64 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN64_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN64_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 128 */
    if (dmaconfig->blen128 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN128_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN128_MASK;
    }
    /* Set/Clear mask bits for AXI Burst Length 256 */
    if (dmaconfig->blen256 == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_BLEN256_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_BLEN256_MASK;
    }
    /* Set/Clear mask bits for Enhanced Address Mode Enable */
    if (dmaconfig->eame == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_EAME_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_EAME_MASK;
    }
    /* Set/Clear mask bits for Address-Aligned Beats */
    if (dmaconfig->aal == 1)
    {
        setmask |= XGMAC_DMA_SYSBUS_MODE_AAL_MASK;
    }
    else
    {
        clrmask |= XGMAC_DMA_SYSBUS_MODE_AAL_MASK;
    }

    /* Configure Maximum Read Outstanding Request Limit */
    setmask |= XGMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_MASK;

    /* Configure Maximum Write Outstanding Request Limit */
    setmask |= XGMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_MASK;

    /* Set DMA Sysbus Mode setmask bits */
    ENABLE_BIT(base_address + XGMAC_DMA_SYSBUS_MODE, setmask);

    /* Clear DMA Sysbus Mode clrmask bits */
    DISABLE_BIT(base_address + XGMAC_DMA_SYSBUS_MODE, clrmask);
}

void xgmac_init_dma_channel_desc_reg(uint32_t base_address, uint8_t dmachindx,
        xgmac_dma_desc_addr_t *dmadescparams)
{
    uint32_t val;

    /* Program the transmit ring length registers */
    val = dmadescparams->tx_ring_len & XGMAC_DMA_CH0_TX_CONTROL2_TDRL_MASK;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TX_CONTROL2, val);

    /* Program the receive ring length registers */
    val = dmadescparams->rx_ring_len & XGMAC_DMA_CH0_RX_CONTROL2_RDRL_MASK;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL2, val);

    /* Program Tx List Address Registers with Base Address of Ring Descriptor */
    val = dmadescparams->tx_desc_high_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TXDESC_LIST_HADDRESS, val);
    val = dmadescparams->tx_desc_low_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TXDESC_LIST_LADDRESS, val);

    /* Program Rx List Address Registers with Base Address of Ring Descriptor */
    val = dmadescparams->rx_desc_high_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RXDESC_LIST_HADDRESS, val);
    val = dmadescparams->rx_desc_low_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RXDESC_LIST_LADDRESS, val);

    /* Program the  Tx Tail Pointer Register */
    val = dmadescparams->tx_last_desc_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TXDESC_TAIL_LPOINTER, val);

    /* Program the  Rx Tail Pointer Register */
    val = dmadescparams->rx_last_desc_addr;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RXDESC_TAIL_LPOINTER, val);
}

void xgmac_config_dma_channel_control(uint32_t base_address, uint8_t dmachindx,
        const xgmacdma_chanl_config_t *dmachnlconfig)
{
    uint32_t val;

    if (base_address == 0U)
    {
        return;
    }
    /* Program  DMA Control Settings - PBLx8 Enable*/
    if (dmachnlconfig->pblx8 == TRUE)
    {
        ENABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_CONTROL, dmachindx,
                XGMAC_DMA_CH0_CONTROL_PBLX8_MASK);
    }
    else
    {
        DISABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_CONTROL, dmachindx,
                XGMAC_DMA_CH0_CONTROL_PBLX8_MASK);
    }

    /* Program  DMA Control Settings - SPH Enable*/
    if (dmachnlconfig->sph == TRUE)
    {
        ENABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_CONTROL, dmachindx,
                XGMAC_DMA_CH0_CONTROL_SPH_MASK);
    }
    else
    {
        DISABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_CONTROL, dmachindx,
                XGMAC_DMA_CH0_CONTROL_SPH_MASK);
    }

    /* Program  DMA Control Settings - DSL Descriptor Skip Length */
    val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_CONTROL);
    val |= (uint32_t)dmachnlconfig->dsl << XGMAC_DMA_CH_CONTROL_DSL_POS;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_CONTROL, val);

    /* Program  DMA Tx Control Settings - TSE Enable*/
    if (dmachnlconfig->tse == TRUE)
    {
        ENABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_TX_CONTROL, dmachindx,
                XGMAC_DMA_CH0_TX_CONTROL_TSE_MASK);
    }
    else
    {
        DISABLE_DMA_CHNL_REGBIT(base_address + XGMAC_DMA_CH_TX_CONTROL, dmachindx,
                XGMAC_DMA_CH0_TX_CONTROL_TSE_MASK);
    }

    /* Program  DMA Tx Control Settings - Write Txpbl */
    val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TX_CONTROL);
    val |= (uint32_t)dmachnlconfig->txpbl << XGMAC_DMA_CH_TX_CONTROL_TXPBL_POS;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_TX_CONTROL, val);

    /* Program  DMA Rx Control Settings - Write Rxpbl */
    val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL);
    val |= (uint32_t)dmachnlconfig->rxpbl << XGMAC_DMA_CH_RX_CONTROL_RXPBL_POS;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL, val);

    /* Program  DMA Rx Control Settings - RBSZ Receive Buffer Size*/
    val = RD_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL);
    val |= (uint32_t)dmachnlconfig->rbsz << XGMAC_DMA_CH_RX_CONTROL_RBSZ_POS;
    WR_DMA_CHNL_REG32(base_address, dmachindx, XGMAC_DMA_CH_RX_CONTROL, val);

}
int32_t xgmac_enable_dma_interrupt(uint32_t base_address, uint8_t chindx,
        xgmac_dma_interrupt_id_t id)
{
    uint32_t val;
    uint32_t intrmask;

    /* Clear the DMA channel status register bits if set. Its a sticky bit hence write back to clear */
    val = RD_DMA_CHNL_REG32(base_address, chindx, XGMAC_DMA_CH_STATUS);
    WR_DMA_CHNL_REG32(base_address, chindx, XGMAC_DMA_CH_STATUS, val);

    switch (id)
    {
        case INTERRUPT_NIS:
            intrmask = XGMAC_DMA_INTR_MASK_TI | XGMAC_DMA_INTR_MASK_RI |
                    XGMAC_DMA_INTR_MASK_NIS;
            break;

        case INTERRUPT_AIS:
            intrmask = XGMAC_DMA_INTR_MASK_FBE | XGMAC_DMA_INTR_MASK_TXS |
                    XGMAC_DMA_INTR_MASK_RBU | XGMAC_DMA_INTR_MASK_RS |
                    XGMAC_DMA_INTR_MASK_DDE | XGMAC_DMA_INTR_MASK_AIS;
            break;

        default:
            intrmask = 0U;
            break;
    }
    if (intrmask == 0U)
    {
        return XGMAC_LL_RETVAL_FAIL;
    }

    val = RD_DMA_CHNL_REG32(base_address, chindx, XGMAC_DMA_CH_INTERRUPT_ENABLE);
    val |= intrmask;
    WR_DMA_CHNL_REG32(base_address, chindx, XGMAC_DMA_CH_INTERRUPT_ENABLE, val);

    return XGMAC_LL_RETVAL_SUCCESS;
}

void xgmac_mac_init(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig)
{
    uint8_t num_queues;
    const xgmac_dev_config_t *macdevconfig = (const
            xgmac_dev_config_t *)(xgmacdevconfig->mac_dev_config);

    if ((base_address == 0U) || (xgmacdevconfig == NULL))
    {
        return;
    }
    /* Configure  MAC Rx Queue Control Register */
    xgmac_config_macrxqctrl_regs(base_address, (const
            xgmacmac_rx_q_ctrl_config_t *)
            xgmacdevconfig->mac_rx_q_ctrl_config);

    /* Program MAC Frame Filter Register  for Promiscuous mode and Receive all */
    xgmac_config_mac_frame_filter(base_address, (const
            xgmacmac_pkt_filter_config_t *)
            xgmacdevconfig->mac_pkt_filter_config);

    /* Program MAC Transmit Flow Control Register */
    num_queues = macdevconfig->noftxqueues;
    for (uint8_t qindex = 0; qindex < num_queues; qindex++)
    {
        xgmac_enable_tx_flow_control(base_address, qindex, (const
                xgmacmac_tx_flow_ctrl_config_t *)
                xgmacdevconfig->mac_tx_flow_ctrl_config);
    }

    /* Program MAC Receive Flow Control Register */
    xgmac_enable_rx_flow_control(base_address, (const
            xgmacmac_rx_flow_ctrl_config_t *)
            xgmacdevconfig->mac_rx_flow_ctrl_config);

    /* Program MAC Tx Configuration Registers */
    xgmac_config_mac_tx(base_address, (const xgmacmac_tx_config_t *)
            xgmacdevconfig->mac_tx_config);


    /* Set Checksum Offload to COE for IPv4 Header & TCP, UDP, ICMP Payload  Rx packets */
    xgmac_config_mac_rx(base_address, (const xgmacmac_rx_config_t *)
            xgmacdevconfig->mac_rx_config);

    /* MAC Management counter config */
    xgmac_mmc_setup(base_address);
}

void xgmac_start_stop_mac_tx(uint32_t base_address, bool stflag)
{
    if (stflag == true)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_TX_CONFIGURATION, XGMAC_MAC_TX_CONFIGURATION_TE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_TX_CONFIGURATION, XGMAC_MAC_TX_CONFIGURATION_TE_MASK);
    }
}

void xgmac_start_stop_mac_rx(uint32_t base_address, bool stflag)
{
    if (stflag == true)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_RX_CONFIGURATION, XGMAC_MAC_RX_CONFIGURATION_RE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_RX_CONFIGURATION, XGMAC_MAC_RX_CONFIGURATION_RE_MASK);
    }
}

void xgmac_config_macrxqctrl_regs(uint32_t base_address, const
        xgmacmac_rx_q_ctrl_config_t *macrxqctrlconfig)
{
    /* Clear and set the Receive Queue 0 */
    DISABLE_BIT(base_address + XGMAC_MAC_RXQ_CTRL0, XGMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK);

    /* Enable for data Center Bridging/Generic */
    ENABLE_BIT(base_address + XGMAC_MAC_RXQ_CTRL0,
            macrxqctrlconfig->rxq0en << XGMAC_MAC_RXQ_CTRL0_RXQ0EN_POS);

    /* Enable/Disable Multicast and Broadcast Queue Enable */
    if (macrxqctrlconfig->mcbcqen == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_RXQ_CTRL1, XGMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_RXQ_CTRL1, XGMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK);
    }
}

void xgmac_config_mac_frame_filter(uint32_t base_address, const
        xgmacmac_pkt_filter_config_t *macpktfilterconfig)
{
    uint8_t val;

    if (base_address == 0U)
    {
        return;
    }
    /* Program Promiscuous Mode */
    if (macpktfilterconfig->pr == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_PR_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_PR_MASK);
    }
    /* Program Hash Unicast */
    if (macpktfilterconfig->huc == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HUC_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HUC_MASK);
    }
    /* Program Hash Multicast */
    if (macpktfilterconfig->hmc == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HMC_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HMC_MASK);
    }

    /* Program DA Inverse Filtering */
    if (macpktfilterconfig->daif == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DAIF_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DAIF_MASK);
    }
    /* Program Pass All Multicast */
    if (macpktfilterconfig->pm == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_PM_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_PM_MASK);
    }
    /* Program Disable Broadcast Packets  */
    if (macpktfilterconfig->dbf == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DBF_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DBF_MASK);
    }

    /* Program Pass Control Packets  */
    val = (uint8_t)RD_REG32(base_address + XGMAC_MAC_PACKET_FILTER);
    val |= macpktfilterconfig->pcf << XGMAC_MAC_PACKET_FILTER_PCF_POS;
    WR_REG32(base_address + XGMAC_MAC_PACKET_FILTER, val);

    /* Program SA Inverse Filtering */
    if (macpktfilterconfig->saif == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_SAIF_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_SAIF_MASK);
    }
    /* Program Source Address Filter Enable */
    if (macpktfilterconfig->saf == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_SAF_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_SAF_MASK);
    }
    /* Program Hash or Perfect Filter */
    if (macpktfilterconfig->hpf == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HPF_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_HPF_MASK);
    }

    /* Program DA Hash Index or L3/L4 Filter Number in Receive  Filter */
    val = (uint8_t)RD_REG32(base_address + XGMAC_MAC_PACKET_FILTER);
    val |= (uint8_t)((uint32_t)macpktfilterconfig->dhlfrs << XGMAC_MAC_PACKET_FILTER_DHLFRS_POS);
    WR_REG32(base_address + XGMAC_MAC_PACKET_FILTER, val);

    /* Program VLAN Tag Filter Enable */
    if (macpktfilterconfig->vtfe == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_VTFE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_VTFE_MASK);
    }
    /* Program Layer 3 and Layer 4 Filter Enable */
    if (macpktfilterconfig->ipfe == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_IPFE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_IPFE_MASK);
    }
    /* Program Drop Non-TCP/UDP over IP Packets */
    if (macpktfilterconfig->dntu == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DNTU_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_DNTU_MASK);
    }
    /* Program Receive All */
    if (macpktfilterconfig->ra == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_RA_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_PACKET_FILTER, XGMAC_MAC_PACKET_FILTER_RA_MASK);
    }
}

void xgmac_config_mac_tx(uint32_t base_address, const
        xgmacmac_tx_config_t *mactxconfig)
{
    /* Program JD MAC configuration to disable Jumbo frames in Tx */
    if (mactxconfig->jd == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_TX_CONFIGURATION, XGMAC_MAC_TX_CONFIGURATION_JD_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_TX_CONFIGURATION, XGMAC_MAC_TX_CONFIGURATION_JD_MASK);
    }
}

void xgmac_config_mac_rx(uint32_t base_address, const
        xgmacmac_rx_config_t *macrxconfig)
{
    uint32_t setmask = 0, clrmask = 0;
    uint16_t val;

    /* Set/Clear mask bits for Automatic Pad or CRC Stripping */
    if (macrxconfig->acs == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_ACS_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_ACS_MASK;
    }

    /* Set/Clear mask bits for CRC stripping for Type packets */
    if (macrxconfig->cst == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_CST_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_CST_MASK;
    }

    /* Set/Clear mask bits for Disable CRC Checking for Received Packets */
    if (macrxconfig->dcrcc == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_DCRCC_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_DCRCC_MASK;
    }

    /* Set/Clear mask bits for Slow Protocol Detection Enable */
    if (macrxconfig->spen == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_SPEN_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_SPEN_MASK;
    }

    /* Set/Clear mask bits for Unicast Slow Protocol Packet Detect */
    if (macrxconfig->usp == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_USP_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_USP_MASK;
    }

    /* Set/Clear mask bits for Giant Packet Size Limit Control Enable */
    if (macrxconfig->gpslce == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_GPSLCE_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_GPSLCE_MASK;
    }

    /* Set/Clear mask bits for Watchdog Disable Enable */
    if (macrxconfig->wd == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_WD_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_WD_MASK;
    }

    /* Set/Clear mask bits for Jumbo Packet Enable */
    if (macrxconfig->je == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_JE_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_JE_MASK;
    }

    /* Set/Clear mask bits for Checksum Offload Enable */
    if (macrxconfig->ipc == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_IPC_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_IPC_MASK;
    }

    /* Set/Clear mask bits for ARP enable */
    if (macrxconfig->arpen == 1)
    {
        setmask |= XGMAC_MAC_RX_CONFIGURATION_ARPEN_MASK;
    }
    else
    {
        clrmask |= XGMAC_MAC_RX_CONFIGURATION_ARPEN_MASK;
    }

    ENABLE_BIT(base_address + XGMAC_MAC_RX_CONFIGURATION, setmask);

    DISABLE_BIT(base_address + XGMAC_MAC_RX_CONFIGURATION, clrmask);

    /* Program Giant Packet Size Limit */
    val = (uint16_t)RD_REG32(base_address + XGMAC_MAC_RX_CONFIGURATION);
    val |= (uint16_t)((uint32_t)macrxconfig->gpsl << XGMAC_MAC_RX_CONFIGURATION_GPSL_POS);
    WR_REG32(base_address + XGMAC_MAC_RX_CONFIGURATION, val);
}

void xgmac_enable_tx_flow_control(uint32_t base_address, uint8_t qindx, const
        xgmacmac_tx_flow_ctrl_config_t *mactxflowctrlconfig)
{
    if ((base_address == 0U) || (mactxflowctrlconfig == NULL))
    {
        return;
    }
    /* Set Pause frame */
    ENABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
            mactxflowctrlconfig->pt << XGMAC_MAC_Q6_TX_FLOW_CTRL_PT_POS);

    /* Set Pause Low Threshold */
    ENABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
            mactxflowctrlconfig->plt << XGMAC_MAC_Q0_TX_FLOW_CTRL_PLT_POS);

    /* Enable Transmit Flow control */
    if (mactxflowctrlconfig->tfe == 1)
    {
        ENABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK);
    }
    else
    {
        DISABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK);
    }

    /* Enable Flow Control Busy */
    if (mactxflowctrlconfig->fcb == 1)
    {
        ENABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_FCB_MASK);
    }
    else
    {
        DISABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_FCB_MASK);
    }

    /* Disable Zero-Quanta Pause */
    if (mactxflowctrlconfig->dzpq == 1)
    {
        ENABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK);
    }
    else
    {
        DISABLE_MAC_FLOW_CNTL_REGBIT(base_address + XGMAC_MAC_Q0_TX_FLOW_CTRL, qindx,
                XGMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK);
    }
}

void xgmac_enable_rx_flow_control(uint32_t base_address, const
        xgmacmac_rx_flow_ctrl_config_t *macrxflowctrlconfig)
{
    /* Program Rx Flow Control */
    if (macrxflowctrlconfig->rfe == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_RFE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_RFE_MASK);
    }
    /* Program Unicast Pause Packet Detect */
    if (macrxflowctrlconfig->up == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_UP_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_UP_MASK);
    }
    /* Program Priority Based Flow Control Enable */
    if (macrxflowctrlconfig->pfce == 1)
    {
        ENABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_PFCE_MASK);
    }
    else
    {
        DISABLE_BIT(base_address + XGMAC_MAC_RX_FLOW_CTRL, XGMAC_MAC_RX_FLOW_CTRL_PFCE_MASK);
    }
}

void xgmac_mtl_init (uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig)
{
    uint8_t qindex;
    uint8_t num_queues;
    const xgmac_dev_config_t *macdevconfig = (const
            xgmac_dev_config_t *)(xgmacdevconfig->mac_dev_config);

    /* Program MTL configuration registers for Tx */
    num_queues = macdevconfig->noftxqueues;
    for (qindex = 0; qindex < num_queues; qindex++)
    {
        xgmac_set_mtl_tx_regs(base_address, qindex, (const
                xgmacmtl_tx_queue_config_t *)
                xgmacdevconfig->mtl_tx_q_config);
    }

    /* Program MTL configuration registers for Rx */
    num_queues = macdevconfig->nofrxqueues;
    for (qindex = 0; qindex < num_queues; qindex++)
    {
        if ((base_address == 0U) || (xgmacdevconfig == NULL))
        {
            return;
        }
        xgmac_set_mtl_rx_regs(base_address, qindex, (const
                xgmacmtl_rx_queue_config_t *)
                xgmacdevconfig->mtl_rx_q_config);
    }
}

/* XGMAC Device start */
void xgmac_dev_start(uint32_t base_address)
{
    /* Start the MAC Transmitter */
    xgmac_start_stop_mac_tx(base_address, true);

    /* Start the MAC Receiver  */
    xgmac_start_stop_mac_rx(base_address, true);
}

void xgmac_set_mtl_tx_regs(uint32_t base_address, uint8_t qindx, const
        xgmacmtl_tx_queue_config_t *mtltxqcfgparams)
{
    uint32_t val;
    uint32_t reg_val;
    uint32_t tqs;

    /* Compute Tqs */
    reg_val = RD_REG32(base_address + XGMAC_MAC_HW_FEATURE1);
    tqs = XGMAC_MTL_TX_FIFO_BLK_CNT(reg_val);

    /* Enable Transmit Queue Store and Forward */
    if (mtltxqcfgparams->tsf == 1)
    {
        ENABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_TXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK);
    }

    /* Disable Transmit Queue Store and Forward */
    else
    {
        DISABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_TXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK);
    }

    /* Enable Tx Queue */
    ENABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_TXQ_OPERATION_MODE, qindx,
            mtltxqcfgparams->txqen << XGMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_POS);

    /* Program Transmit Queue Size */
    val = RD_MTL_QX_REG32(base_address, qindx, XGMAC_MTL_TXQ_OPERATION_MODE);
    val |= tqs << XGMAC_MTL_TXQ0_OPERATION_MODE_TQS_POS;
    WR_MTL_QX_REG32(base_address, qindx, XGMAC_MTL_TXQ_OPERATION_MODE, val);
}

void xgmac_set_mtl_rx_regs(uint32_t base_address, uint8_t qindx, const
        xgmacmtl_rx_queue_config_t *mtlrxqcfgparams)
{
    uint32_t val;
    uint32_t reg_val;
    uint32_t rqs;

    /* Compute Rqs */
    reg_val = RD_REG32(base_address + XGMAC_MAC_HW_FEATURE1);
    rqs = XGMAC_MTL_RX_FIFO_BLK_CNT(reg_val);

    /* Enable Receive Queue Store and Forward */
    if (mtlrxqcfgparams->rsf == 1)
    {
        ENABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_RXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_RXQ_OPERATION_MODE_RSF_MASK);
    }

    /* Disable Receive Queue Store and Forward */
    else
    {
        DISABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_RXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_RXQ_OPERATION_MODE_RSF_MASK);
    }

    /* Enable Hardware Flow Control */
    if (mtlrxqcfgparams->ehfc == 1)
    {
        ENABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_RXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_RXQ_OPERATION_MODE_EHFC_MASK);
    }

    /* Disable Hardware Flow Control */
    else
    {
        DISABLE_MTL_QX_REGBIT(base_address + XGMAC_MTL_RXQ_OPERATION_MODE, qindx,
                XGMAC_MTL_RXQ_OPERATION_MODE_EHFC_MASK);
    }

    /* Program Receive Queue Size */
    val = RD_MTL_QX_REG32(base_address, qindx, XGMAC_MTL_RXQ_OPERATION_MODE);
    val |= rqs << XGMAC_MTL_RXQ_OPERATION_MODE_RQS_POS;
    WR_MTL_QX_REG32(base_address, qindx, XGMAC_MTL_RXQ_OPERATION_MODE, val);
}

void xgmac_disable_interrupt(uint32_t base_address)
{
    /* Read the XGMAC interrupt status register */
    uint32_t mac_intr_status = RD_REG32(
            base_address + XGMAC_MAC_INTERRUPT_STATUS);

    /* Check for any active interrupt */
    mac_intr_status &= ~XGMAC_MAC_INTERRUPT_STATUS_LSI_MASK;

    /* Clear the interrupt */
    WR_REG32(base_address + XGMAC_MAC_INTERRUPT_STATUS, mac_intr_status);
}

void xgmac_start_dma_dev(uint32_t base_address, const
        xgmac_dev_config_str_t *xgmacdevconfig)
{
    uint8_t dma_chnl_index;
    uint8_t dma_num_chnls;

    dma_num_chnls = xgmacdevconfig->mac_dev_config->nofdmachannels;

    for (dma_chnl_index = 0; dma_chnl_index < dma_num_chnls; dma_chnl_index++)
    {
        /* Start Receive and Transmit DMA */
        xgmac_start_dma(base_address, dma_chnl_index, XGMAC_DMA_TRANSMIT_START);

        xgmac_start_dma(base_address, dma_chnl_index, XGMAC_DMA_RECEIVE_START);
    }
}

xgmac_dma_interrupt_id_t check_and_clear_xgmac_interrupt_status(uint32_t
        base_address)
{
    uint32_t val;
    xgmac_dma_interrupt_id_t res;

    /* Read the status */
    val = RD_REG32(base_address + XGMAC_DMA_CH_STATUS);

    /* Clear the status */
    WR_REG32(base_address + XGMAC_DMA_CH_STATUS, val);

    if ((val & XGMAC_DMA_INTR_MASK_TI) != 0U)
    {
        res = INTERRUPT_TI;
    }
    else if ((val & XGMAC_DMA_INTR_MASK_RI) != 0U)
    {
        res = INTERRUPT_RI;
    }
    else if ((val & XGMAC_DMA_INTR_MASK_FBE) != 0U)
    {
        res = INTERRUPT_FBE;
    }
    else if ((val & XGMAC_DMA_INTR_MASK_TXS) != 0U)
    {
        res = INTERRUPT_TXS;
    }
    else if ((val & XGMAC_DMA_INTR_MASK_RBU) != 0U)
    {
        res = INTERRUPT_RBU;
    }
    else if ((val & XGMAC_DMA_INTR_MASK_RS) != 0U)
    {
        res = INTERRUPT_RS;
    }
    else
    {
        res = INTERRUPT_UNHANDLED;
    }

    return res;
}
void check_and_clear_link_interrupt_status(uint32_t base_address)
{
    uint32_t val;
    /*register reads ,clears the interrupts*/
    val = RD_REG32(base_address + XGMAC_MAC_RX_TX_STATUS);
    val = RD_REG32(base_address + XGMAC_MAC_INTERRUPT_STATUS);
    (void)val;
}

void xgmac_flush_buffer(void *buf, size_t size)
{
    cache_force_write_back(buf, size);
}

void xgmac_invalidate_buffer(void *buf, size_t size)
{
    cache_force_invalidate(buf, size);
}

void xgmac_mmc_setup(uint32_t base_address)
{
    /*
     * Disable all the Receive IPC statistics counter,
     * in the management counter
     *
     * MMC block is unused, the interrupt masking is done to avoid some
     * unwanted interrupts
     * */
    DISABLE_BIT(base_address + XGMAC_MMC_IPC_RX_INTERRUPT_MASK, XGMAC_MMC_IPC_RX_INTR_MASK_ALL);
}
