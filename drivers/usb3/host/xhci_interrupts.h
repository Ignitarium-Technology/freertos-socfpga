/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for Interrupts sub-module of SoC FPGA USB3.1 XHCI low level driver
 */

#ifndef __XHCI_INTERRUPTS_H__
#define __XHCI_INTERRUPTS_H__

#include <stdbool.h>

/* Function pointer for tinyusb interrupt handler */
typedef void (*tusb_int_ptr)(uint8_t rhport, bool in_isr);

/* descriptor to pass to interrupt handler */
struct xhci_int_desc
{
    tusb_int_ptr int_handler; /* !< pointer to tinyusb interrupt handler */
};

typedef struct xhci_int_desc *xhci_int_ptr_t;
/*
 * @brief  enable xhci interrupts
 */
void enable_xhci_interrupts(void);

/*
 * @brief  disable the xhci interrupts
 */
void disable_xhci_interrupts(void);

/*
 * @brief  register USB3 ISR
 * @param[in] int_handler - pointer to tinyusb interrupt handler
 */
bool register_usb3ISR(xhci_int_ptr_t int_handler);

#endif  /* __XHCI_INTERRUPTS_H__ */
