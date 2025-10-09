/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for freeze bridge ip low level driver
 */

#ifndef __SOCFPGA_FREEZE_LL_H__
#define __SOCFPGA_FREEZE_LL_H__

#include <errno.h>
#include "fpga_mmio.h"

#ifdef FPGA_FREEZE_IP_BASE_ADDR
    #define PR_FREEZE_BASE    (FPGA_FREEZE_IP_BASE_ADDR)
#else
    #define PR_FREEZE_BASE    (0x20020400U)
#endif

#define FREEZE_CSR_STATUS         (0x00000000U)
#define FREEZE_CSR_CTRL           (0x00000004U)
#define FREEZE_REG_VERSION_OFF    (0x0000000CU)

#define FREEZE_CSR_STATUS_FREEZE_STATUS_MASK      (0x00000001U)
#define FREEZE_CSR_STATUS_UNFREEZE_STATUS_MASK    (0x00000002U)

#define FREEZE_CSR_CTRL_FREEZE_REQ      (0x00000001U)
#define FREEZE_CSR_CTRL_RESET_REQ       (0x00000002U)
#define FREEZE_CSR_CTRL_UNFREEZE_REQ    (0x00000004U)

int freeze_pr_region(void);
int unfreeze_pr_region(void);

#endif /* __SOCFPGA_FREEZE_LL_H__ */
