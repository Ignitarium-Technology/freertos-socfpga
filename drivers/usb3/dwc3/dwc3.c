/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL driver implementation for DWC3 driver
 */

#include "dwc3.h"
#include "dwc3_ll.h"
#include "osal_log.h"

int dwc3_init(void)
{
    uint32_t phy_info;
    int ret;

    dwc3_ghwparams_t *dwc3_hwparams = NULL;

    dwc3_hwparams = get_dwc3_ghwparams();
    if (dwc3_hwparams == NULL)
    {
        ERROR("Unable to get DWC3 hardware parameters");
        return -ENODEV;
    }

    phy_info = get_usb3_phy_info(dwc3_hwparams->ghwparams3);
    switch (phy_info)
    {
        case DWC3_SS_PHY_3_0:
            INFO("Device supportes USB 3.0 Only");
            break;

        case DWC3_SS_PHY_3_1:
            INFO("Device supportes USB 3.1 Gen1");
            break;

        default:
            INFO("Device does not support USB3.1");
            break;
    }

    usb2_phy_setup(dwc3_hwparams->ghwparams3);

    setup_dwc3_gctl(dwc3_hwparams->ghwparams1);

    ret = dwc3_set_usb_host_mode(dwc3_hwparams->ghwparams0);
    if (ret != 0)
    {
        ERROR("Unable to setup DWC3 in host mode");
        return ret;
    }

    return 0;
}
