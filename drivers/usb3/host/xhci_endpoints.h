/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for Endpoints sub-module of SoC FPGA USB3.1 XHCI low level driver
 */

#ifndef __XHCI_ENDPOINTS_H__
#define __XHCI_ENDPOINTS_H__

#include <stdint.h>
#include <stdbool.h>
#include "xhci.h"

#define USB_EP_DIR_IN_MSK       (0x80U) /* !< Endpoint direction mask for xhci */
#define USB_EP_DIR_OUT          (0U) /* !< OUT endpoint */
#define USB_EP_DIR_IN           (1U) /* !< IN endpoint */

#define SETUP_STAGE_TRB         (2U) /* !< trb id of setup stage */
#define DATA_STAGE_TRB          (3U) /* !< trb id of data stage  */
#define STATUS_STAGE_TRB        (4U) /* !< trb id of status stage*/
#define NORMAL_TRB              (1U) /* !< trb id of normal trb*/
#define EVENT_DATA_TRB          (7U) /* !< trb id of event data trb*/

#define ENT_FLAG                (1) /* !< Bit position for Evaluate Next TRB field */
#define CH_FLAG                 (4) /* !< Bit position for CHAIN bit field */
#define IOC_FLAG                (5) /* !< Bit position for IOC field */
#define IDT_FLAG                (6) /* !< Bit position for IDT field */

#define SETUP_STAGE_TRB_LEN     (8U) /* !< xhci setup stage TRB len */

#define STATUS_STAGE_DIR_OUT    (0U) /* !< xhci status stage direction is OUT */
#define STATUS_STAGE_DIR_IN     (1U) /* !< xhci status stage direction is IN  */

#define DATA_STAGE_DIR_IN       (1U) /* !< xhci data stage direction is IN */
#define SETUP_STAGE_DIR_IN      (3U) /* !< xhci setup stage direction is IN*/

#define ROUNDUP(x, y)      (((x) + (y) - 1U) / (y))
#define ROUNDDOWN(x, y)    (((x) + (y)) / (y))
#define MIN(x, y)          (((x) < (y)) ? (x): (y))
#define MAX_TD_SIZE    (31U)

#define MAX_TRB_LEN    (65536U)

/*
 * @brief   get the endpoint direction
 * @param[in] ep_addr : endpoint address
 * @return  endpoint direction
 */
static inline uint8_t get_endpoint_dir(uint8_t ep_addr)
{
    return (uint8_t)(((ep_addr &
           USB_EP_DIR_IN_MSK) != 0U) ? USB_EP_DIR_IN : USB_EP_DIR_OUT);
}

/*
 * @brief   get the endpoint number
 * @param[in] ep_addr endpoint address
 * @return  endpoint number
 */
static inline uint8_t get_endpoint_num(uint8_t ep_addr)
{
    return (uint8_t)(ep_addr & 0x3U);
}

/*
 * @brief   find the xhci device context index from the endpoint number
 * @param[in]  xhci_ptr -  endpoint address
 * @return  device context index
 */
uint8_t get_ep_dci(uint8_t ep_addr);

/**
 * @brief  initialize the endpoint0 transfer ring for control transfers
 * @param[in]  xhci reference to xhci hcd structure
 * @param[in]  buffer reference to buffer to hold the control transfer data
 * @param[in]  setup_req reference to the USB control request
 */
void configure_setup_stage(struct xhci_data *xhci, void *buffer,
        usb_control_request_t *setup_req);

/**
 * @brief  handle the bulk endpoint transfer
 * @param[in]  xhci reference to xhci hcd structure
 * @param[in]  ep_num endpoint number to initiate the transfer
 * @param[in]  dir endpoint direction
 * @param[in]  buffer reference to buffer to hold the control transfer data
 * @param[in]  buflen  number of bytes of data to transfer out/in
 * @return
 *  true  , on successful transfer
 *  false , on failure
 */
bool endpoint_transfer(struct xhci_data *xhci, int ep_num, uint8_t dir,
        void *buffer, uint32_t buflen);

#endif  /*__XHCI_ENDPOINTS_H__ */
