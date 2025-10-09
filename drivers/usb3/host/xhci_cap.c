/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA USB3.1 XHCI controller.
 * Capabilities sub-module
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "xhci.h"
#include "osal_log.h"

/*
 * @brief read the host controller capability registers
 */
int get_xhc_cap_params(struct xhci_data *xhci)
{
    xhci->xhc_cap_ptr = (xhci_cap_reg_t *)USBBASE;

    DEBUG("CAPLENGTH : %x", xhci->xhc_cap_ptr->caplength);
    DEBUG("HCSPARAMS1 : %x", xhci->xhc_cap_ptr->hcsparams1);
    DEBUG("HCSPARAMS2 : %x", xhci->xhc_cap_ptr->hcsparams2);
    DEBUG("HCSPARAMS3 : %x", xhci->xhc_cap_ptr->hcsparams3);
    DEBUG("HCCPARAMS1 : %x", xhci->xhc_cap_ptr->hccparams1);
    DEBUG("DBOFF : %x", xhci->xhc_cap_ptr->dboff_params.db_array_offset);
    DEBUG("RTOFF : %x", xhci->xhc_cap_ptr->rtsoff_params.rts_offset);
    DEBUG("HCCPARAMS2 : %x", xhci->xhc_cap_ptr->hccparams2);

    xhci->op_regs.xhci_op_base = (USBBASE +
            (uint64_t) xhci->xhc_cap_ptr->caplength);
    xhci->op_regs.xhci_runtime_base = (USBBASE +
            (uint64_t) xhci->xhc_cap_ptr->rtsoff_params.rts_offset);
    xhci->op_regs.xhci_db_base = (USBBASE +
            (uint64_t) xhci->xhc_cap_ptr->dboff_params.db_array_offset);

    DEBUG("Operational base : %lx ", xhci->op_regs.xhci_op_base);
    DEBUG("Runtime  base : %lx ", xhci->op_regs.xhci_runtime_base);
    DEBUG("Doorbell base : %lx ", xhci->op_regs.xhci_db_base);

    return 0;
}

xhci_oper_reg_params_t get_xhci_op_registers(void)
{
    const xhci_cap_reg_t *xhc_cap_ptr;
    xhci_oper_reg_params_t op_reg = { 0 };

    xhc_cap_ptr = (xhci_cap_reg_t *)USBBASE;

    op_reg.xhci_op_base = (USBBASE + (uint64_t) xhc_cap_ptr->caplength);
    op_reg.xhci_runtime_base = (USBBASE +
            (uint64_t) xhc_cap_ptr->rtsoff_params.rts_offset);
    op_reg.xhci_db_base = (USBBASE +
            (uint64_t) xhc_cap_ptr->dboff_params.db_array_offset);

    return op_reg;
}


