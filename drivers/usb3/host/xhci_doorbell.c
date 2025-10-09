/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for SoC FPGA USB3.1 XHCI controller.
 * Doorbell submodule.
 */

#include "xhci_doorbell.h"
#include "socfpga_defines.h"

void ring_xhci_host_db(void)
{
    xhci_oper_reg_params_t op_regs;

    op_regs = get_xhci_op_registers();
    WR_REG32((op_regs.xhci_db_base + USB3_DB), XHCI_COMMAND_DOORBELL);
}
void ring_xhci_ep0_db(xhci_oper_reg_params_t *op_regs)
{
    uint64_t db_reg;
    uint32_t slot_id = 1U;

    db_reg = (op_regs->xhci_db_base + USB3_DB) +
            (XHCI_DB_REG_SIZE * (uint64_t) slot_id);

    WR_REG32((uint32_t) db_reg, XHCI_DB_EP0_TARGET);
}

void ring_xhci_ep_doorbell(xhci_oper_reg_params_t *op_regs, uint8_t db_target)
{
    uint64_t db_reg;
    uint32_t slot_id = 1U;

    db_reg = (op_regs->xhci_db_base + USB3_DB) +
            (XHCI_DB_REG_SIZE * (uint64_t) slot_id);

    WR_REG32((uint32_t) db_reg, db_target);
}
