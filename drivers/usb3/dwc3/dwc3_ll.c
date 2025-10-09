/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for DWC3 driver
 */

#include "dwc3_ll.h"
#include "socfpga_usb3_reg.h"
#include "socfpga_defines.h"
#include <errno.h>

/*
 * @brief Configures the DWC3 to operate in host mode
 */
int dwc3_set_usb_host_mode(uint32_t ghwparams0)
{
    uint32_t reg_val;
    uint8_t usb_mode = (uint8_t) (ghwparams0 &
            USB3_GHWPARAMS0_GHWPARAMS0_2_0_MASK);

    if (usb_mode == DWC3_GHWPARAMS0_MODE_DRD)
    {
        /* Suspend both USB3 & USB2 PHYs before setting HOST mode */
        reg_val = RD_REG32((USBBASE + USB3_GUSB3PIPECTL));
        reg_val &= ~(USB3_GUSB3PIPECTL_SUSPENDENABLE_MASK);
        WR_REG32((USBBASE + USB3_GUSB3PIPECTL), reg_val);

        reg_val = RD_REG32((USBBASE + USB3_GUSB2PHYCFG));
        reg_val &= ~(USB3_GUSB2PHYCFG_SUSPENDUSB20_MASK);
        WR_REG32((USBBASE + USB3_GUSB2PHYCFG), reg_val);

        /* Clear 12, 13 bit of GCTL register before setting to host mode */
        reg_val = RD_REG32((USBBASE + USB3_GCTL));
        reg_val &= ~(USB3_GCTL_PRTCAPDIR_MASK);
        reg_val |= (USB_MODE_HOST << USB3_GCTL_PRTCAPDIR_POS);
        WR_REG32((USBBASE + USB3_GCTL), reg_val);

        reg_val = RD_REG32((USBBASE + USB3_GCTL));
        reg_val |= (USB3_GCTL_CORESOFTRESET_MASK);
        WR_REG32((USBBASE + USB3_GCTL), reg_val);

        osal_task_delay(100);

        reg_val = RD_REG32((USBBASE + USB3_GCTL));
        reg_val &= ~(USB3_GCTL_CORESOFTRESET_MASK);
        WR_REG32((USBBASE + USB3_GCTL), reg_val);

        reg_val = RD_REG32((USBBASE + USB3_GUSB2PHYCFG));
        reg_val |= (USB3_GUSB2PHYCFG_SUSPENDUSB20_MASK);
        WR_REG32((USBBASE + USB3_GUSB2PHYCFG), reg_val);

        reg_val = RD_REG32((USBBASE + USB3_GUSB3PIPECTL));
        reg_val |= ((uint32_t) 1U << 17);
        WR_REG32((USBBASE + USB3_GUSB3PIPECTL), reg_val);

    }
    else if (usb_mode == DWC3_GHWPARAMS0_MODE_HOST)
    {
        /* Do nothing as usb mode is host by default */
    }
    else
    {
        /* Host mode not supported by controller*/
        return -EOPNOTSUPP;
    }

    return 0;
}

/*
 * @brief Configures the USB2 phy
 */
void usb2_phy_setup(uint32_t ghwparams3)
{
    uint32_t reg_val;
    uint8_t hs_phy;

    /* Select HS phy interface */
    hs_phy = (uint8_t) ((ghwparams3 & USB3_GHWPARAMS3_GHWPARAMS3_3_2_MASK) >>
            USB3_GHWPARAMS3_GHWPARAMS3_3_2_POS);

    switch (hs_phy)
    {
        case DWC3_HS_PHY_UTMI:     break;

        case DWC3_HS_PHY_ULPI:
            break;

        case DWC3_HS_PHY_UTMI_ULPI:
            /* select ULPI phy */
            reg_val = RD_REG32(USBBASE + USB3_GUSB2PHYCFG);
            reg_val |= USB3_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK;
            WR_REG32((USBBASE + USB3_GUSB2PHYCFG), reg_val);
            break;
        default:
            /*do nothing*/
            break;
    }
}

/*
 * @brief Get the USB3 phy info
 */
uint32_t get_usb3_phy_info(uint32_t ghwparams3)
{
    uint8_t ss_phy;

    /* SS phy interface */
    ss_phy = (uint8_t) ((ghwparams3 & USB3_GHWPARAMS3_GHWPARAMS3_1_0_MASK) >>
            USB3_GHWPARAMS3_GHWPARAMS3_1_0_POS);

    if (ss_phy == DWC3_SS_PHY_DIS)
    {
        /* SS PHY is disabled */
        return DWC3_SS_PHY_DIS;
    }
    else if (ss_phy == DWC3_SS_PHY_3_0)
    {
        /* Controller supports USB3.0 only */
        return DWC3_SS_PHY_3_0;
    }
    else if (ss_phy == DWC3_SS_PHY_3_1)
    {
        /* Controller supports USB3.1 */
        return DWC3_SS_PHY_3_1;
    }
    else
    {
        /* Invalid SS PHY info */
    }

    return DWC3_SS_PHY_DIS;

}

/*
 * @brief Configure the DWC3 GCTL register
 */
void setup_dwc3_gctl(uint32_t ghwparams1)
{
    uint32_t reg_val;
    uint8_t power_opt_mode;

    reg_val = RD_REG32(USBBASE + USB3_GCTL);
    reg_val &= ~USB3_GCTL_SCALEDOWN_MASK;

    power_opt_mode = (uint8_t) ((ghwparams1 &
            USB3_GHWPARAMS1_GHWPARAMS1_25_24_MASK) >>
            USB3_GHWPARAMS1_GHWPARAMS1_25_24_POS);

    switch (power_opt_mode)
    {

        case 1:  /* clock gating only supported */
            /* Enable clock gating in GCTL reg */
            reg_val &= ~USB3_GCTL_DSBLCLKGTNG_MASK;
            break;
        case 2:
            /* enable hibernation */
            reg_val |= USB3_GCTL_GBLHIBERNATIONEN_MASK;

        default:  /*do nothing */
            break;
    }

    WR_REG32((USBBASE + USB3_GCTL), reg_val);
}
