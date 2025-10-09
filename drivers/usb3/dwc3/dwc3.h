/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for DWC3 driver
 */

#ifndef __SOCFPGA_DWC3_H__
#define __SOCFPGA_DWC3_H__

#include <errno.h>
#include "socfpga_usb3_reg.h"
#include "socfpga_defines.h"

/*
 * @func  : dwc3_init
 * @brief : initialize the dwc3 controller
 *          initializes the usb2, usb3 phy and sets the usb mode to host
 * @return
 *  0 - on success
 *  errno    - on failure
 */
int dwc3_init(void);

#endif /* _SOCFPGA_DWC3_H_ */
