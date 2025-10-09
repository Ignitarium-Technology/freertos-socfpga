/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for context sub-module of SoC FPGA USB3.1 XHCI low level driver
 */

#ifndef __XCHI_CONTEXT_H__
#define __XCHI_CONTEXT_H__

#include "socfpga_usb3_reg.h"
#include "socfpga_defines.h"

/* MASK and POS for Input control context */
#define DCI_SLOT_CONTEXT            (1UL) /* !< Select slot context in Input control context */
#define SLOT_CONTEXT_POS            (0) /* !< Slot context Index position in Input control context */
#define SLOT_CONTEXT_ENTRIES_MSK    (0xffffffff07ffffffUL) /* !< Context entries bit mask in slot context data structure */
#define SLOT_CONTEXT_ENTRIES_POS    (27)                /* !< Bit position for contrxt entries in slot context structure */
#define EP0_DCI                     (1UL)               /* !< Endpoint 0 Device context index */
#define EP0_DCI_POS                 (1)                 /* !< Endpoint 0 bitfield position in device context */
#define EP0_CCS_FLAG                (1U)                /* !< EP0 Cycle bit */

/*
 * endpoint context bit mask and position
 */
#define EP_CTX_MAX_PKT_SIZE_POS     (48) /* !< Endpoint 0 packet size configuration location in endpoint context structure */
#define EP_CTX_MAX_PKT_SIZE_MSK     (0x0000ffffffffffffUL) /* !< Endpoint 0 packet size configuration bitmask in endpoint context structure */

/*
 * Endpoint 0 max packet sizes
 */
#define EP0_MAX_PKT_SIZE_SS         (512UL) /* !< Max. packet size for SS device */
#define EP0_MAX_PKT_SIZE_HS         (64UL) /* !< Max. packet size for HS device */
#define EP0_MAX_PKT_SIZE_FS         (8UL) /* !< Max. packet size for FS device */
#define EP0_MAX_PKT_SIZE_LS         (8UL) /* !< Max. packet size for LS device */

#define EP_DEFAULT_TRB_LEN          (8U) /* !< xhci default trb len */

/*
 * @struct : slot xhci_slot_context_t
 * @brief  : slot context data structure
 * @note   : Refer page 444 of xhci Document
 */
typedef struct __attribute__ ((packed)){
    uint64_t xsc_info1;
    uint64_t xsc_info2;
    uint64_t xsc_reserved[6];
} xhci_slot_context_t;

/*
 * @struct : xhci_endpoint_context_t
 * @brief  : endpoint context data structure
 */
typedef struct __attribute__ ((packed)){
    uint64_t xec_info;
    uint64_t xec_dequeue;
    uint64_t xec_info2;
    uint64_t xec_reserved[5];
} xhci_endpoint_context_t;

/*
 * @struct : xhci_input_control_context_t
 * @brief  : input control context data structure
 */
typedef struct __attribute__ ((packed)){
    uint64_t xic_context_flags;     /* drop/add flags for contexts */
    uint64_t xic_reserved[7];
} xhci_input_control_context_t;

/*
 * @struct : xhci_ip_device_context_t
 * @brief  : Input Device Context data structure
 */
typedef struct __attribute__ ((packed))
{
    xhci_input_control_context_t xi_context;
    xhci_slot_context_t xs_context;
    xhci_endpoint_context_t xe_context[31];
} xhci_ip_device_context_t;

/*
 * @struct : xhci_op_device_context_t
 * @brief  : Output Device Context Data Structure
 */
typedef struct __attribute__ ((packed))
{
    xhci_slot_context_t slot_context;    /* slot context followed by endpoint context */
    xhci_endpoint_context_t EP_0;        /* EP 0 context */
    xhci_endpoint_context_t EP[30];      /* EP 1 - 30 contexts */
} xhci_op_device_context_t;

/* Device Context Base Address Array */
/*
 * @struct : xhci_device_context_array
 * @brief  : device context base address array structure
 */
struct xhci_device_context_array {
    uint64_t dev_context_ptrs[256];
};

/*
 * @func  : update_endpoint_packetsize
 * @brief : update the endpoint context with max packet size
 * @param[in] ip_ctx reference to input context data structure
 * @param[in] max_pkt_size max packet size
 */
void update_endpoint_packetsize(xhci_ip_device_context_t *ip_ctx,
        uint16_t max_pkt_size);

/*
 * @func  : display_op_context
 * @brief : Display the output context data structure
 * @param[in] op_ctx reference to output context data structure
 */
void display_op_context(xhci_op_device_context_t *op_ctx);

/*
 * @func  : display_ip_context
 * @brief : Display the input context data structure
 * @param[in] ip_ctx reference to input context data structure
 */
void display_ip_context(xhci_ip_device_context_t *ip_ctx);

#endif  /* __XCHI_CONTEXT_H__ */
