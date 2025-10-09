/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file partial reconfiguration sample
 */


#ifndef __FPGA_PR_SAMPLE_H__
#define __FPGA_PR_SAMPLE_H__

#define SYSID_REG    (0x20020000)

#define PERSONA0_SYSID    (0x11111111U)
#define PERSONA1_SYSID    (0x22222222U)
#define PERSONA0_RBF      "/p0.rbf"
#define PERSONA1_RBF      "/p1.rbf"

#define PR_FREEZE_BASE            (0x20020400U)
#define FREEZE_REG_VERSION_OFF    (0x0000000CU)
#define FREEZE_REG_VERSION        (0xAD000003U)

#endif /* __FPGA_PR_SAMPLE_H__ */
