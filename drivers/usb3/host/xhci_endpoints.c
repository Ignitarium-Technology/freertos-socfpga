/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA USB3.1 XHCI controller.
 * Endpoints sub-module.
 */

#include "xhci_doorbell.h"
#include "xhci.h"
#include "xhci_endpoints.h"
#include "xhci_rings.h"
#include "osal_log.h"
#include "socfpga_cache.h"

/**
 * @brief Setup the TRB with the control transfer data. For xHCI, control transfer consists of 3 stages.
 *        ( Data stage is optional). All the 3 stages are populated in this api.
 */
void configure_setup_stage(struct xhci_data *xhci, void *buffer,
        usb_control_request_t *setup_req)
{
    uint32_t end_ctrl_flags = 0U;
    xhci_trb_t *ptr = xhci->ep0.ep_tr_enq_ptr;
    if (ptr == NULL)
    {
        return;
    }
    do
    {
        if (is_link_trb(ptr) == 1)
        {
            ptr = get_next_trb_segment(ptr, &xhci->ep0.pcs_flag);
        }
        /* check for Enqueue pointer location */
        if ((ptr->control & 0x1U) == 1U)
        {
            ptr = ptr + 1;
        }
        else
        {
            break;
        }
    }while(true);

    ptr->buffer = ((uint64_t) setup_req->bmRequestType & 0xffU);
    ptr->buffer |= ((uint64_t) setup_req->bRequest << 8);
    ptr->buffer |= ((uint64_t) setup_req->wValue << 16);
    ptr->buffer |= ((uint64_t)setup_req->wIndex << 32);
    ptr->buffer |= ((uint64_t)setup_req->wLength << 48);

    /* transfer length = 8 for control transfers */
    ptr->status = SETUP_STAGE_TRB_LEN;

    end_ctrl_flags |=  ((uint32_t) SETUP_STAGE_TRB << 10);
    end_ctrl_flags |= ((uint32_t) SETUP_STAGE_DIR_IN << 16);
    end_ctrl_flags |=  (1U << IDT_FLAG);
    end_ctrl_flags |= xhci->ep0.pcs_flag;

    /* PCS FLAG */
    ptr->control = end_ctrl_flags;

    ptr++;

    if (is_link_trb(ptr) == 1)
    {
        ptr = get_next_trb_segment(ptr, &xhci->ep0.pcs_flag);
    }

    if (setup_req->wLength > 0U)
    {
        /* Data Stage TRB */
        ptr->status = (uint32_t)setup_req->wLength;
        ptr->buffer = (uint64_t)buffer;

        end_ctrl_flags = 0U;

        /* TRB TYPE = 3 */
        end_ctrl_flags |= ((uint32_t)  DATA_STAGE_TRB << 10);
        end_ctrl_flags |= ((uint32_t)  DATA_STAGE_DIR_IN << 16);
        end_ctrl_flags |= xhci->ep0.pcs_flag;

        ptr->control = end_ctrl_flags;

        ptr++;

        if (is_link_trb(ptr) == 1)
        {
            ptr = get_next_trb_segment(ptr, &xhci->ep0.pcs_flag);
        }
    }

    /* Status Stage TRB
     * IOC =1
     * PCS flag
     */

    end_ctrl_flags = 0U;
    end_ctrl_flags |= ((uint32_t)  STATUS_STAGE_TRB << 10);
    end_ctrl_flags |= (1U << IOC_FLAG);
    end_ctrl_flags |= ((uint32_t)  STATUS_STAGE_DIR_OUT << 16);
    end_ctrl_flags |= xhci->ep0.pcs_flag;

    ptr->control = end_ctrl_flags;

    cache_force_write_back((void *) xhci->ep0.ep_tr_enq_ptr,
           EP_TRB_SEG_LENGTH * sizeof(xhci_trb_t));
}

/**
 * @brief Get the endpoint DCI from the endpoint address
 */
uint8_t get_ep_dci(uint8_t ep_addr)
{
    uint8_t ep_dir;
    uint8_t ep_num;
    uint8_t ep_dci;

    ep_dir = get_endpoint_dir(ep_addr);
    ep_num = get_endpoint_num(ep_addr);

    if (ep_num == 0U)
    {
        ep_dci = 1U;
    }
    else
    {
        /* EP DCI  is ICI -1 */
        ep_dci = (ep_num * 2U) + ep_dir;
    }

    return ep_dci;
}

/*
 * @brief Get the td_size as per the xHCI spec for the transfer
 */
static uint32_t get_td_size(uint16_t bytes_trasnferred,
        uint16_t trb_transfer_len, uint32_t total_len,
        uint16_t mps, bool is_last_trb)
{
    uint32_t total_pkt_count;
    uint32_t total_pkt_xferred;
    uint32_t td_size;

    if (is_last_trb == true)
    {
        return 0U;
    }

    if (mps == 0U)
    {
        return 0U;
    }
    total_pkt_count = ROUNDUP(total_len, mps);
    total_pkt_xferred = ROUNDDOWN((bytes_trasnferred + trb_transfer_len),
            (uint32_t) mps);

    td_size = total_pkt_count - total_pkt_xferred;

    if (td_size > MAX_TD_SIZE)
    {
        td_size = MAX_TD_SIZE;
    }

    return td_size;
}

/*
 * @brief Populate endpoint transfer rings for bulk transfer
 */
static void fill_endpoint_transfer_ring(struct ep_priv *ep_ctx, void *buffer,
        uint32_t len)
{
    uint32_t ep_pcs_flag;
    uint16_t e_mps = ep_ctx->ep_desc.wMaxPacketSize;

    volatile uint32_t trb_transfer_len;
    volatile uint32_t bytes_xferred;
    volatile uint32_t total_bytes;

    volatile uint32_t status_field;
    volatile uint32_t end_ctrl_flags;
    volatile uint32_t td_size;

    uint32_t bytes_pending;
    uint64_t addr;
    bool last_trb = false;
    volatile uint32_t c_bit;

    xhci_trb_t *ptr = ep_ctx->ep_tr_enq_ptr;
    if (ptr == NULL)
    {
        return;
    }

    while (true)
    {
        if (is_link_trb(ptr) == 1)
        {
            ptr = get_next_trb_segment(ptr, &ep_ctx->pcs_flag);
        }

        c_bit = (ptr->control & 0x00000001U);
        if (c_bit == ep_ctx->pcs_flag)
        {
            ptr = ptr + 1;
        }
        else
        {
            break;
        }
    }

    trb_transfer_len = 0U;
    bytes_xferred = 0U;
    total_bytes = len;
    bytes_pending = len;
    addr = (uint64_t)buffer;

    for (bytes_xferred = 0U; bytes_xferred < total_bytes;
            bytes_xferred += trb_transfer_len)
    {
        ep_pcs_flag = ep_ctx->pcs_flag;
        status_field = 0U;
        end_ctrl_flags = 0U;

        if (bytes_pending > MAX_TRB_LEN)
        {
            trb_transfer_len = 65536;
        }
        else
        {
            trb_transfer_len = bytes_pending;
        }

        if ((bytes_xferred + trb_transfer_len) > total_bytes)
        {
            trb_transfer_len = total_bytes - bytes_xferred;
        }

        if ((bytes_xferred + trb_transfer_len) < total_bytes)
        {
            end_ctrl_flags |= (1U << CH_FLAG);
        }
        /* Last TRB of the TD, Next will be Event TRB */
        if ((bytes_xferred + trb_transfer_len) >= total_bytes)
        {
            end_ctrl_flags |= (1U << ENT_FLAG);
            end_ctrl_flags |= (1U << CH_FLAG);
            last_trb = true;
        }

        td_size = get_td_size(bytes_xferred, trb_transfer_len, total_bytes,
                e_mps, last_trb);

        status_field |= (td_size << 16);
        status_field |= trb_transfer_len;

        end_ctrl_flags |= ((uint32_t)  NORMAL_TRB << TRB_FIELD);
        end_ctrl_flags |= (ep_pcs_flag);

        ptr->buffer = addr;
        ptr->status = status_field;
        ptr->control = end_ctrl_flags;

        addr += (uint64_t)trb_transfer_len;
        bytes_pending -= trb_transfer_len;

        ptr++;

        if (is_link_trb(ptr) == 1)
        {
            ptr = get_next_trb_segment(ptr, &ep_ctx->pcs_flag);
        }
    }

    ptr->buffer = (uint64_t)ep_ctx->ep_tr_enq_ptr;
    ptr->status = 0U;

    end_ctrl_flags = 0U;
    end_ctrl_flags |= (1U << IOC_FLAG);
    end_ctrl_flags |= ((uint32_t) EVENT_DATA_TRB << TRB_FIELD);
    end_ctrl_flags |= (ep_ctx->pcs_flag);

    ptr->control = end_ctrl_flags;
    cache_force_write_back((void *) ep_ctx->ep_tr_enq_ptr,
            EP_TRB_SEG_LENGTH * sizeof(xhci_trb_t));
}

/**
 * @brief Initiate an endpoint transfer on bulk endpoints
 */
bool endpoint_transfer(struct xhci_data *xhci, int ep_num, uint8_t dir,
        void *buffer, uint32_t buflen)
{
    uint8_t ICI;
    ICI = (uint8_t)((uint32_t) ep_num * 2U) + dir + 1U;
    uint8_t db_target = (uint8_t)(ICI - 1U);

    /* Out transfer */
    if (dir == 0U)
    {
        INFO("Endpoint OUT transfer on endpoint - %d with bytes - %d ", ep_num,
                buflen);
        fill_endpoint_transfer_ring(&xhci->msc_eps.ep_out, buffer, buflen);
        ring_xhci_ep_doorbell(&xhci->op_regs, db_target);
    }
    /* In Transfer */
    else if (dir == 1U)
    {
        INFO("Endpoint IN transfer on endpoint - %d with bytes - %d ", ep_num,
                buflen);
        fill_endpoint_transfer_ring(&xhci->msc_eps.ep_in, buffer, buflen);
        ring_xhci_ep_doorbell(&xhci->op_regs, db_target);
    }
    else
    {
        return false;
    }
    return true;
}

int xhci_parse_endpoint_descriptor(struct xhci_data *xhci_ptr,
        usb_endpoint_descriptor_t *desc)
{
    const uint8_t ep_dir = get_endpoint_dir(desc->bEndpointAddress);
    uint8_t max_streams = 0;
    if (ep_dir == USB_EP_DIR_IN)
    {
        xhci_ptr->msc_eps.ep_in.ep_desc.bLength = desc->bLength;
        xhci_ptr->msc_eps.ep_in.ep_desc.bDescriptorType = desc->bDescriptorType;
        xhci_ptr->msc_eps.ep_in.ep_desc.bEndpointAddress =
                desc->bEndpointAddress;
        xhci_ptr->msc_eps.ep_in.ep_desc.bmAttributes = desc->bmAttributes;
        xhci_ptr->msc_eps.ep_in.ep_desc.wMaxPacketSize = desc->wMaxPacketSize;
        xhci_ptr->msc_eps.ep_in.ep_desc.bInterval = desc->bInterval;

        xhci_ptr->msc_eps.ep_in.ep_type = BULK_IN;
        xhci_ptr->msc_eps.ep_in.pcs_flag = 1U;

        /* For xHCI spec, endpoint context index is ep_dci -1 */
        xhci_ptr->msc_eps.ep_in.ep_index = get_ep_dci(desc->bEndpointAddress) -
                0x1U;
        xhci_ptr->msc_eps.ep_in.ep_addr = desc->bEndpointAddress;

        if (max_streams > 0U)
        {
            /* Stream support not enabled */
            return -ENOTSUP;
        }
        else
        {
            xhci_trb_t *enq_ptr;
            enq_ptr = allocate_ring_segment(XHCI_EP_TR_RING_ALIGN,
                    EP_TRB_SEG_LENGTH);
            if (enq_ptr == NULL)
            {
                ERROR("Canot allocate memory!!!");
                return -ENOMEM;
            }

            xhci_ptr->msc_eps.ep_in.ep_tr_enq_ptr = enq_ptr;
        }
    }

    if (ep_dir == USB_EP_DIR_OUT)
    {
        xhci_trb_t *enq_ptr;
        max_streams = 0;

        xhci_ptr->msc_eps.ep_out.ep_desc.bLength = desc->bLength;
        xhci_ptr->msc_eps.ep_out.ep_desc.bDescriptorType =
                desc->bDescriptorType;
        xhci_ptr->msc_eps.ep_out.ep_desc.bEndpointAddress =
                desc->bEndpointAddress;
        xhci_ptr->msc_eps.ep_out.ep_desc.bmAttributes = desc->bmAttributes;
        xhci_ptr->msc_eps.ep_out.ep_desc.wMaxPacketSize = desc->wMaxPacketSize;
        xhci_ptr->msc_eps.ep_out.ep_desc.bInterval = desc->bInterval;

        xhci_ptr->msc_eps.ep_out.ep_type = BULK_OUT;
        xhci_ptr->msc_eps.ep_out.pcs_flag = 1U;

        /* For xHCI spec, endpoint context index is ep_dci -1 */
        xhci_ptr->msc_eps.ep_out.ep_index = get_ep_dci(desc->bEndpointAddress) -
                0x1U;
        xhci_ptr->msc_eps.ep_out.ep_addr = desc->bEndpointAddress;

        if (max_streams > 0U)
        {
            /* Stream support not enabled */
            return -ENOTSUP;
        }
        else
        {
            enq_ptr = allocate_ring_segment(XHCI_EP_TR_RING_ALIGN,
                    EP_TRB_SEG_LENGTH);
            if (enq_ptr == NULL)
            {
                ERROR("Cannot allocate memory!!!");
                return -ENOMEM;
            }
            xhci_ptr->msc_eps.ep_out.ep_tr_enq_ptr = enq_ptr;
        }
    }
    return 0;
}
