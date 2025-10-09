/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL driver implementation for USB3
 */

#include "xhci.h"
#include "socfpga_usb.h"
#include "tusb_types.h"
#include "osal_log.h"
#include "xhci_endpoints.h"

void xhci_parse_interface_descriptor(usb_interface_descriptor_t *xhci_intf_desc,
        usb_interface_descriptor_t *desc)
{

    xhci_intf_desc->bLength = desc->bLength;
    xhci_intf_desc->bDescriptorType = desc->bDescriptorType;
    xhci_intf_desc->bInterfaceNumber = desc->bInterfaceNumber;
    xhci_intf_desc->bAlternateSetting = desc->bAlternateSetting;
    xhci_intf_desc->bNumEndpoints = desc->bNumEndpoints;
    xhci_intf_desc->bInterfaceClass = desc->bInterfaceClass;
    xhci_intf_desc->bInterfaceSubClass = desc->bInterfaceSubClass;
    xhci_intf_desc->bInterfaceProtocol = desc->bInterfaceProtocol;
    xhci_intf_desc->iInterface = desc->iInterface;
}

void xhci_parse_device_descriptor(usb_device_descriptor_t *xhci_dev_desc,
        usb_device_descriptor_t *desc)
{
    xhci_dev_desc->bLength = desc->bLength;
    xhci_dev_desc->bDescriptorType = desc->bDescriptorType;
    xhci_dev_desc->bcdUSB = desc->bcdUSB;
    xhci_dev_desc->bDeviceClass = desc->bDeviceClass;
    xhci_dev_desc->bDeviceSubClass = desc->bDeviceSubClass;
    xhci_dev_desc->bDeviceProtocol = desc->bDeviceProtocol;
    xhci_dev_desc->bMaxPacketSize0 = desc->bMaxPacketSize0;
    xhci_dev_desc->idVendor = desc->idVendor;
    xhci_dev_desc->idProduct = desc->idProduct;
    xhci_dev_desc->bcdDevice = desc->bcdDevice;
    xhci_dev_desc->iManufacturer = desc->iManufacturer;
    xhci_dev_desc->iProduct = desc->iProduct;
    xhci_dev_desc->iSerialNumber = desc->iSerialNumber;
    xhci_dev_desc->bNumConfigurations = desc->bNumConfigurations;
}

void xhci_parse_conf_descriptor(usb_conf_descriptor_t *xhci_conf_desc,
        usb_conf_descriptor_t *desc)
{
    xhci_conf_desc->bLength = desc->bLength;
    xhci_conf_desc->bDescriptorType = desc->bDescriptorType;
    xhci_conf_desc->wTotalLength = desc->wTotalLength;
    xhci_conf_desc->bNumInterfaces = desc->bNumInterfaces;
    xhci_conf_desc->bConfigurationValue = desc->bConfigurationValue;
    xhci_conf_desc->iConfiguration = desc->iConfiguration;
    xhci_conf_desc->bmAttributes = desc->bmAttributes;
    xhci_conf_desc->bMaxPower = desc->bMaxPower;
}

void xhci_parse_ss_endpoint_comp_desc(usb3_ss_ep_comp_desc_t *ss_ep_desc,
        usb3_ss_ep_comp_desc_t *desc)
{
    ss_ep_desc->bLength = desc->bLength;
    ss_ep_desc->bDescriptorType = desc->bDescriptorType;
    ss_ep_desc->bMaxBurst = desc->bMaxBurst;
    ss_ep_desc->bmAttributes = desc->bmAttributes;
    ss_ep_desc->wBytesPerInterval = desc->wBytesPerInterval;
}

int xhci_parse_endpoint_descriptor(struct xhci_data *xhci_ptr,
        usb_endpoint_descriptor_t *desc)
{
    const tusb_dir_t ep_dir = tu_edpt_dir(desc->bEndpointAddress);
    uint8_t max_streams = 0;
    if (ep_dir == TUSB_DIR_IN)
    {
        xhci_ptr->msc_eps.ep_in.ep_desc.bLength = desc->bLength;
        xhci_ptr->msc_eps.ep_in.ep_desc.bDescriptorType = desc->bDescriptorType;
        xhci_ptr->msc_eps.ep_in.ep_desc.bEndpointAddress =
                desc->bEndpointAddress;
        xhci_ptr->msc_eps.ep_in.ep_desc.bmAttributes = desc->bmAttributes;
        xhci_ptr->msc_eps.ep_in.ep_desc.wMaxPacketSize = desc->wMaxPacketSize;
        xhci_ptr->msc_eps.ep_in.ep_desc.bInterval = desc->bInterval;

        xhci_ptr->msc_eps.ep_in.ep_type = BULK_IN;
        xhci_ptr->msc_eps.ep_in.pcs_flag = 1U;

        /* For xHCI spec, endpoint context index is ep_dci -1 */
        xhci_ptr->msc_eps.ep_in.ep_index = get_ep_dci(desc->bEndpointAddress) -
                0x1U;
        xhci_ptr->msc_eps.ep_in.ep_addr = desc->bEndpointAddress;

        if (max_streams > 0U)
        {
            /* Stream support not enabled */
            return -ENOTSUP;
        }
        else
        {
            xhci_trb_t *enq_ptr;
            enq_ptr = allocate_ring_segment(XHCI_EP_TR_RING_ALIGN,
                    EP_TRB_SEG_LENGTH);
            if (enq_ptr == NULL)
            {
                ERROR("Canot allocate memory!!!");
                return -ENOMEM;
            }

            xhci_ptr->msc_eps.ep_in.ep_tr_enq_ptr = enq_ptr;
        }
    }

    if (ep_dir == TUSB_DIR_OUT)
    {
        xhci_trb_t *enq_ptr;
        max_streams = 0;

        xhci_ptr->msc_eps.ep_out.ep_desc.bLength = desc->bLength;
        xhci_ptr->msc_eps.ep_out.ep_desc.bDescriptorType =
                desc->bDescriptorType;
        xhci_ptr->msc_eps.ep_out.ep_desc.bEndpointAddress =
                desc->bEndpointAddress;
        xhci_ptr->msc_eps.ep_out.ep_desc.bmAttributes = desc->bmAttributes;
        xhci_ptr->msc_eps.ep_out.ep_desc.wMaxPacketSize = desc->wMaxPacketSize;
        xhci_ptr->msc_eps.ep_out.ep_desc.bInterval = desc->bInterval;

        xhci_ptr->msc_eps.ep_out.ep_type = BULK_OUT;
        xhci_ptr->msc_eps.ep_out.pcs_flag = 1U;

        /* For xHCI spec, endpoint context index is ep_dci -1 */
        xhci_ptr->msc_eps.ep_out.ep_index = get_ep_dci(desc->bEndpointAddress) -
                0x1U;
        xhci_ptr->msc_eps.ep_out.ep_addr = desc->bEndpointAddress;

        if (max_streams > 0U)
        {
            /* Stream support not enabled */
            return -ENOTSUP;
        }
        else
        {
            enq_ptr = allocate_ring_segment(XHCI_EP_TR_RING_ALIGN,
                    EP_TRB_SEG_LENGTH);
            if (enq_ptr == NULL)
            {
                ERROR("Cannot allocate memory!!!");
                return -ENOMEM;
            }
            xhci_ptr->msc_eps.ep_out.ep_tr_enq_ptr = enq_ptr;
        }
    }
    return 0;
}

void xhci_parse_bos_descriptor(struct usb_bos_root_desc *root_bos_desc,
        uint8_t *desc)
{
    usb_bos_descriptor_t *bos_desc = (usb_bos_descriptor_t *)(uintptr_t)desc;

    if (bos_desc == NULL)
    {
        return;
    }
    const uint16_t total_len = bos_desc->wTotalLength;
    uint8_t const *desc_end = ((uint8_t const *)desc) + total_len;
    uint8_t *desc_next = desc + desc[0];

    root_bos_desc->bos_desc.bLength = bos_desc->bLength;
    root_bos_desc->bos_desc.bDescriptorType = bos_desc->bDescriptorType;
    root_bos_desc->bos_desc.wTotalLength = bos_desc->wTotalLength;
    root_bos_desc->bos_desc.bNumDeviceCaps = bos_desc->bNumDeviceCaps;

    while (desc_next < desc_end)
    {
        uint8_t desc_len;
        uint8_t bdesc_type;
        uint8_t *next_dev_cap = desc_next;

        desc_len = desc_next[DESC_OFFSET_LEN];

        bdesc_type = desc_next[2];

        switch (bdesc_type)
        {
            /* USB2.0 extension capability descriptor */
            case 2:
                {
                    usb_20_ext_desc_t *cap_desc;
                    cap_desc = (usb_20_ext_desc_t *)(uintptr_t)next_dev_cap;
                    if (cap_desc == NULL)
                    {
                        break;
                    }

                    root_bos_desc->usb20_ext_desc.bLength = cap_desc->bLength;
                    root_bos_desc->usb20_ext_desc.bDescriptorType =
                            cap_desc->bDescriptorType;
                    root_bos_desc->usb20_ext_desc.bDevCapabilityType =
                            cap_desc->bDevCapabilityType;
                    root_bos_desc->usb20_ext_desc.bmAttributes =
                            cap_desc->bmAttributes;

                    break;
                }
            /* USB SS Device Capability descriptor */
            case 3:
                {
                    usb_ss_dev_cap_desc_t *ss_desc;
                    ss_desc = (usb_ss_dev_cap_desc_t *)(uintptr_t)next_dev_cap;
                    if (ss_desc == NULL)
                    {
                        break;
                    }

                    root_bos_desc->ss_dev_desc.bLength = ss_desc->bLength;
                    root_bos_desc->ss_dev_desc.bDescriptorType =
                            ss_desc->bDescriptorType;
                    root_bos_desc->ss_dev_desc.bDevCapabilityType =
                            ss_desc->bDevCapabilityType;
                    root_bos_desc->ss_dev_desc.wSpeedsSupported =
                            ss_desc->wSpeedsSupported;
                    root_bos_desc->ss_dev_desc.bFunctionalitySupport =
                            ss_desc->bFunctionalitySupport;
                    root_bos_desc->ss_dev_desc.bU1DevExitLat =
                            ss_desc->bU1DevExitLat;
                    root_bos_desc->ss_dev_desc.wU2DevExitLat =
                            ss_desc->wU2DevExitLat;

                    break;
                }
            default:
                /* do nothing */
                break;
        }
        desc_next += desc_len;
    }
}

void display_usb_descriptor(struct xhci_data *xhci_ptr)
{
    DEBUG(
            "******************* USB DEVICE DESCRIPTOR ***************************");

    DEBUG(" DEVICE DESCRIPTORS");

    DEBUG(" bLength : %x", xhci_ptr->usb_desc.dev_desc.bLength);
    DEBUG(" bDescriptorType : %x", xhci_ptr->usb_desc.dev_desc.bDescriptorType);
    DEBUG(" bcdUSB : %x", xhci_ptr->usb_desc.dev_desc.bcdUSB);
    DEBUG(" bDeviceClass : %x ", xhci_ptr->usb_desc.dev_desc.bDeviceClass);
    DEBUG(" bDeviceSubClass : %x ",
            xhci_ptr->usb_desc.dev_desc.bDeviceSubClass);
    DEBUG(" bDeviceProtocol : %x ",
            xhci_ptr->usb_desc.dev_desc.bDeviceProtocol);
    DEBUG(" bMaxPacketSize0 : %x", xhci_ptr->usb_desc.dev_desc.bMaxPacketSize0);
    DEBUG(" idVendor : %x ", xhci_ptr->usb_desc.dev_desc.idVendor);
    DEBUG(" idProduct : %x", xhci_ptr->usb_desc.dev_desc.idProduct);
    DEBUG(" bcdDevice: %x ", xhci_ptr->usb_desc.dev_desc.bcdDevice);
    DEBUG(" iManufacturer : %x  -- %s",
            xhci_ptr->usb_desc.dev_desc.iManufacturer,
            xhci_ptr->usb_desc.m_string);
    DEBUG(" iProduct : %x -- %s ", xhci_ptr->usb_desc.dev_desc.iProduct,
            xhci_ptr->usb_desc.p_string);
    DEBUG(" iSerialNumber : %x -- %s ",
            xhci_ptr->usb_desc.dev_desc.iSerialNumber,
            xhci_ptr->usb_desc.s_string);
    DEBUG(" bNumConfigurations : %x ",
            xhci_ptr->usb_desc.dev_desc.bNumConfigurations);

    DEBUG(" ");
    DEBUG(" CONFIGURATION DESCRIPTOR ");

    DEBUG(" bLength : %x ", xhci_ptr->usb_desc.dev_conf_desc.bLength);
    DEBUG(" bDescriptorType : %x ",
            xhci_ptr->usb_desc.dev_conf_desc.bDescriptorType);
    DEBUG(" wTotalLength : %x ", xhci_ptr->usb_desc.dev_conf_desc.wTotalLength);
    DEBUG(" bNumInterfaces : %x ",
            xhci_ptr->usb_desc.dev_conf_desc.bNumInterfaces);
    DEBUG(" bConfigurationValue : %x ",
            xhci_ptr->usb_desc.dev_conf_desc.bConfigurationValue);
    DEBUG(" iConfiguration : %x ",
            xhci_ptr->usb_desc.dev_conf_desc.iConfiguration);
    DEBUG(" bmAttributes: %x ", xhci_ptr->usb_desc.dev_conf_desc.bmAttributes);
    DEBUG(" bMaxPower : %x ", xhci_ptr->usb_desc.dev_conf_desc.bMaxPower);

    usb_endpoint_descriptor_t *ep_desc = &xhci_ptr->msc_eps.ep_out.ep_desc;

    DEBUG(" ");
    DEBUG(" \tINTERFACE DESCRIPTORS ");
    DEBUG(" \tbLength : %x ", xhci_ptr->usb_desc.dev_intf_desc.bLength);
    DEBUG(" \tbDescriptorType : %x ",
            xhci_ptr->usb_desc.dev_intf_desc.bDescriptorType);
    DEBUG(" \tbInterfaceNumber : %x",
            xhci_ptr->usb_desc.dev_intf_desc.bInterfaceNumber);
    DEBUG(" \tbAlternateSetting : %x",
            xhci_ptr->usb_desc.dev_intf_desc.bAlternateSetting);
    DEBUG(" \tbNumEndpoints : %x ",
            xhci_ptr->usb_desc.dev_intf_desc.bNumEndpoints);
    DEBUG(" \tbInterfaceClass : %x ",
            xhci_ptr->usb_desc.dev_intf_desc.bInterfaceClass);
    DEBUG(" \tbInterfaceSubClass : %x ",
            xhci_ptr->usb_desc.dev_intf_desc.bInterfaceSubClass);
    DEBUG(" \tbInterfaceProtocol : %x ",
            xhci_ptr->usb_desc.dev_intf_desc.bInterfaceProtocol);
    DEBUG(" \tiInterface : %x ", xhci_ptr->usb_desc.dev_intf_desc.iInterface);

    DEBUG(" ");
    DEBUG("\t\tENDPOINT DESCRIPTORS");
    DEBUG(" \t\tLength : %x", ep_desc->bLength);
    DEBUG(" \t\tbDescriptorType: %x", ep_desc->bDescriptorType);
    DEBUG(" \t\tbEndpointAddress : %x", ep_desc->bEndpointAddress);
    DEBUG(" \t\tbmAttributes: %x", ep_desc->bmAttributes);
    DEBUG(" \t\twMaxPacketSize: %x", ep_desc->wMaxPacketSize);
    DEBUG(" \t\tbInterval: %x", ep_desc->bInterval);

    ep_desc = &xhci_ptr->msc_eps.ep_in.ep_desc;

    DEBUG("\t\tLength : %x", ep_desc->bLength);
    DEBUG("\t\tbDescriptorType: %x", ep_desc->bDescriptorType);
    DEBUG("\t\tbEndpointAddress : %x", ep_desc->bEndpointAddress);
    DEBUG("\t\tbmAttributes: %x", ep_desc->bmAttributes);
    DEBUG("\t\twMaxPacketSize: %x", ep_desc->wMaxPacketSize);
    DEBUG("\t\tbInterval: %x", ep_desc->bInterval);

    struct usb_bos_root_desc *bos_desc = &xhci_ptr->usb_desc.root_bos_desc;

    DEBUG(" ");
    DEBUG(" BOS DESCRIPTORS");
    DEBUG("\tLength : %x", bos_desc->bos_desc.bLength);
    DEBUG("\tbDescriptorType: %x", bos_desc->bos_desc.bDescriptorType);
    DEBUG("\twTotalLength : %x", bos_desc->bos_desc.wTotalLength);
    DEBUG("\tbNumDeviceCaps : %x", bos_desc->bos_desc.bNumDeviceCaps);

    DEBUG(" ");
    DEBUG("\tUSB2.0 EXTENSION DESCRIPTOR");
    DEBUG("\t\tLength : %x ", bos_desc->usb20_ext_desc.bLength);
    DEBUG("\t\tbDescriptorType: %x", bos_desc->usb20_ext_desc.bDescriptorType);
    DEBUG("\t\tbDevCapabilityType : %x ",
            bos_desc->usb20_ext_desc.bDevCapabilityType);
    DEBUG("\t\tbmAttributes : %x ", bos_desc->usb20_ext_desc.bmAttributes);

    DEBUG("\tSS DEVICE CAPABILITY DESCRIPTOR ");
    DEBUG("\t\tLength : %x ", bos_desc->ss_dev_desc.bLength);
    DEBUG("\t\tbDescriptorType: %x ", bos_desc->ss_dev_desc.bDescriptorType);
    DEBUG("\t\tbDevCapabilityType : %x ",
            bos_desc->ss_dev_desc.bDevCapabilityType);
    DEBUG("\t\tbmAttributes : %x ", bos_desc->ss_dev_desc.bmAttributes);
    DEBUG("\t\twSpeedsSupported : %x ", bos_desc->ss_dev_desc.wSpeedsSupported);
    DEBUG("\t\tbFunctionalitySupport : %x ",
            bos_desc->ss_dev_desc.bFunctionalitySupport);
    DEBUG("\t\tbU1DevExitLat : %x ", bos_desc->ss_dev_desc.bU1DevExitLat);
    DEBUG("\t\twU2DevExitLat : %x ", bos_desc->ss_dev_desc.wU2DevExitLat);
}
