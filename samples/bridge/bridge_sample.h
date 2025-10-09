/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Definitions used in SoC FPGA bridge sample app
 */


#ifndef __BRIDGE_SAMPLE_H__
#define __BRIDGE_SAMPLE_H__

/* lwh2f bridge example memory mapped base addresses */

#define LWH2F_BASE                 (0x20000000UL)
#define LWH2F_512M_SPAN            (0x20000000UL)
#define LWH2F_SYSID_ID_BASE        (0x00010000UL)
#define LWH2F_BUF0                 (0x00020000UL)
#define LWH2F_LED_OFFSET           (0x00010080UL)
#define LWH2F_BUTTON_PIO_OFFSET    (0x00010060UL)

/* h2f bridge example memory mapped base addresses */
#define H2F_1G_BASE         (0x0040000000ULL)
#define H2F_1G_SPAN         (0x0040000000ULL)
#define H2F_15G_BASE        (0x0440000000ULL)
#define H2F_15G_SPAN        (0x03C0000000ULL)
#define H2F_240G_BASE       (0x4400000000ULL)
#define H2F_240G_SPAN       (0x3C00000000ULL)
#define H2F_OCRAM_OFFSET    (0x00000000UL)

int hps2fpga_bridge_sample(void);
int lwhps2fpga_bridge_sample(void);

#endif  /*__BRIDGE_SAMPLE_H__*/
