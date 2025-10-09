/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for USB HAL driver
 */

#ifndef __SOCFPGA_USB_H__
#define __SOCFPGA_USB_H__

/**
 * @file socfpga_usb.h
 * @brief USB3 HAL driver header file
 */

#include <stdio.h>
#include <errno.h>

/**
 * @defgroup usb3 USB3
 * @ingroup drivers
 * @brief APIs for SoC FPGA USB3 driver.
 * @details This is the USB3 driver implementation for SoC FPGA.
 * It provides APIs for USB3 device enumeration, configuration,
 * and data transfer. For example usage, refer to
 * @ref usb3_sample "USB3.1 sample application".
 * @{
 */

/**
 * @defgroup usb3_fns Functions
 * @ingroup usb3
 * USB3 HAL APIs
 */

/**
 * @defgroup usb3_structs Structures
 * @ingroup usb3
 * USB3 Specific Structures
 */

/**
 * @addtogroup usb3_structs
 * @{
 */

/**
 * @brief USB Device Descriptor.
 *
 * Describes general information about a USB device, including USB version,
 * vendor and product IDs, class information, and supported configurations.
 */
typedef struct
{
    uint8_t bLength;           /*!< Length of this descriptor in bytes */
    uint8_t bDescriptorType;   /*!< Descriptor type (DEVICE descriptor = 1) */
    uint16_t bcdUSB;           /*!< USB Specification Release Number in BCD (e.g., 0x0200 for USB 2.0) */
    uint8_t bDeviceClass;      /*!< Class code assigned by USB-IF */
    uint8_t bDeviceSubClass;   /*!< Subclass code assigned by USB-IF */
    uint8_t bDeviceProtocol;   /*!< Protocol code assigned by USB-IF */
    uint8_t bMaxPacketSize0;   /*!< Maximum packet size for endpoint zero (valid: 8, 16, 32, or 64) */
    uint16_t idVendor;         /*!< Vendor ID assigned by USB-IF */
    uint16_t idProduct;        /*!< Product ID assigned by the manufacturer */
    uint16_t bcdDevice;        /*!< Device release number in BCD */
    uint8_t iManufacturer;     /*!< Index of string descriptor describing manufacturer */
    uint8_t iProduct;          /*!< Index of string descriptor describing product */
    uint8_t iSerialNumber;     /*!< Index of string descriptor describing the device's serial number */
    uint8_t bNumConfigurations;/*!< Number of possible configurations */
}
/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_device_descriptor_t;

/**
 * @brief USB Configuration Descriptor.
 *
 * Describes a device configuration, including the number of interfaces,
 * power requirements, and configuration characteristics.
 */
typedef struct
{
    uint8_t bLength;              /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;      /*!< CONFIGURATION descriptor type (0x02) */
    uint16_t wTotalLength;        /*!< Total length of data returned for this configuration, including all descriptors */
    uint8_t bNumInterfaces;       /*!< Number of interfaces supported by this configuration */
    uint8_t bConfigurationValue;  /*!< Value to use as an argument to select this configuration */
    uint8_t iConfiguration;       /*!< Index of string descriptor describing this configuration */
    uint8_t bmAttributes;         /*!< Configuration characteristics (e.g., self-powered, remote wakeup) */
    uint8_t bMaxPower;            /*!< Maximum power consumption of the USB device from the bus in this configuration (in 2 mA units) */
}
/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_conf_descriptor_t;

/**
 * @brief USB String Descriptor.
 *
 * Provides a Unicode string used by USB devices to describe manufacturer,
 * product, serial number, or other human-readable information.
 *
 * The string is encoded as UTF-16LE and follows the USB specification format.
 */
typedef struct
{
    uint8_t bLength;           /*!< Size of this descriptor in bytes, including bLength, bDescriptorType, and the string */
    uint8_t bDescriptorType;   /*!< STRING descriptor type (0x03) */
    uint8_t unicode_string[];  /*!< UTF-16LE encoded Unicode string (variable length) */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */
usb_string_descriptor_t;

/**
 * @brief USB Standard Interface Descriptor.
 *
 * Describes a specific interface within a USB configuration, including class,
 * subclass, protocol, and the number of endpoints used.
 */
typedef struct
{
    uint8_t bLength;             /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;     /*!< INTERFACE descriptor type (0x04) */
    uint8_t bInterfaceNumber;    /*!< Number of this interface (zero-based index) */
    uint8_t bAlternateSetting;   /*!< Value used to select this alternate setting for the interface */
    uint8_t bNumEndpoints;       /*!< Number of endpoints used by this interface (excluding endpoint zero) */
    uint8_t bInterfaceClass;     /*!< Class code (assigned by the USB-IF) */
    uint8_t bInterfaceSubClass;  /*!< Subclass code (assigned by the USB-IF) */
    uint8_t bInterfaceProtocol;  /*!< Protocol code (assigned by the USB-IF) */
    uint8_t iInterface;          /*!< Index of string descriptor describing this interface */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_interface_descriptor_t;

/**
 * @brief USB Standard Endpoint Descriptor.
 *
 * Describes an endpoint’s characteristics such as type, address, maximum packet size,
 * and polling interval. It is used during USB enumeration to inform the host of
 * endpoint capabilities.
 */
typedef struct
{
    uint8_t bLength;            /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;    /*!< ENDPOINT descriptor type (0x05) */
    uint8_t bEndpointAddress;   /*!< The address of the endpoint on the USB device (bit 7 indicates direction: 0 = OUT, 1 = IN) */
    uint8_t bmAttributes;       /*!< Endpoint attributes: transfer type (bits 0–1), synchronization type (bits 2–3), usage type (bits 4–5) */
    uint16_t wMaxPacketSize;    /*!< Maximum packet size this endpoint is capable of sending or receiving */
    uint8_t bInterval;          /*!< Interval for polling endpoint for data transfers (in frames or microframes, depending on transfer type) */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_endpoint_descriptor_t;

/**
 * @brief USB BOS (Binary Object Store) Descriptor.
 *
 * The BOS descriptor is a container for one or more device capability descriptors.
 * It allows a USB device to advertise its capabilities, such as USB 2.0 extensions,
 * SuperSpeed capabilities, and more.
 */
typedef struct
{
    uint8_t bLength;            /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;    /*!< BOS descriptor type (0x0F) */
    uint16_t wTotalLength;      /*!< Total length of the BOS descriptor and all of its device capability descriptors */
    uint8_t bNumDeviceCaps;     /*!< Number of separate device capability descriptors that follow the BOS descriptor */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_bos_descriptor_t;

/**
 * @brief USB 2.0 Extension Descriptor for BOS (Binary Object Store).
 *
 * Describes USB 2.0-specific capabilities, including Link Power Management (LPM).
 * Part of the BOS descriptor set introduced in USB 2.0+.
 */
typedef struct
{
    uint8_t bLength;              /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;      /*!< DEVICE CAPABILITY descriptor type (0x10) */
    uint8_t bDevCapabilityType;   /*!< USB 2.0 Extension capability type (0x02) */

    union
    {
        uint32_t bmAttributes;    /*!< Attributes bitmap as a 32-bit value */

        struct bos_usb20_attr
        {
            uint32_t rsvd0 : 1;   /*!< Reserved bit (must be 0) */
            uint32_t lpm   : 1;   /*!< Supports Link Power Management (LPM) if set */
            uint32_t rsvd1 : 30;  /*!< Reserved bits (must be 0) */
        } bos_battr;              /*!< Bitfield representation of bmAttributes */
    };
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_20_ext_desc_t;

/**
 * @brief USB SuperSpeed Device Capability Descriptor (USB 3.0).
 *
 * Describes SuperSpeed USB device capabilities, including supported speeds,
 * power management features (like LPM), and exit latencies.
 */
typedef struct
{
    uint8_t bLength;                /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;        /*!< DEVICE CAPABILITY descriptor type (0x10) */
    uint8_t bDevCapabilityType;     /*!< SUPERSPEED USB Device Capability type (0x03) */

    union
    {
        uint8_t bmAttributes;       /*!< Attributes bitmap as an 8-bit value */

        struct bos_ss_attr
        {
            uint8_t rsvd0 : 1;      /*!< Reserved bit (must be 0) */
            uint8_t lpm   : 1;      /*!< Supports LPM if set */
            uint8_t rsvd1 : 6;      /*!< Reserved bits (must be 0) */
        } bos_battr;                /*!< Bitfield representation of bmAttributes */
    };

    uint16_t wSpeedsSupported;      /*!< Bitmap of supported speeds (e.g., Full, High, SuperSpeed) */
    uint8_t bFunctionalitySupport;  /*!< Lowest speed at which all functionality is supported */
    uint8_t bU1DevExitLat;          /*!< U1 device exit latency (in microseconds) */
    uint8_t wU2DevExitLat;          /*!< U2 device exit latency (in microseconds) */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_ss_dev_cap_desc_t;

/**
 * @brief Root structure representing the USB BOS (Binary Object Store) descriptor set.
 *
 * The BOS descriptor provides a way for USB devices to describe their capabilities,
 * such as USB 2.0 extensions and SuperSpeed capabilities. This structure aggregates
 * all related BOS capability descriptors as required by the USB specification.
 */
struct usb_bos_root_desc
{
    usb_bos_descriptor_t bos_desc;         /*!< BOS descriptor header containing the total length and number of device capabilities */
    usb_20_ext_desc_t usb20_ext_desc;      /*!< USB 2.0 Extension descriptor indicating features like LPM support */
    usb_ss_dev_cap_desc_t ss_dev_desc;     /*!< SuperSpeed USB Device Capability descriptor indicating speed support and exit latencies */
};

/**
 * @brief Represents a standard USB control transfer setup packet.
 *
 * This structure defines the setup packet used in USB control transfers.
 * It corresponds to the standard USB setup packet format defined by the USB specification.
 */
typedef struct
{
    uint8_t bmRequestType;   /*!< Characteristics of the request:
                                 - Direction (bit 7)
                                 - Type (bits 5..6)
                                 - Recipient (bits 0..4) */
    uint8_t bRequest;        /*!< Specific request code */
    uint16_t wValue;         /*!< Word-sized field that varies according to request */
    uint16_t wIndex;         /*!< Typically used to pass an index or offset (e.g., interface or endpoint) */
    uint16_t wLength;        /*!< Number of bytes to transfer if there is a data stage */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb_control_request_t;

/**
 * @brief SuperSpeed Endpoint Companion Descriptor (USB 3.0).
 *
 * This descriptor provides additional information for endpoints when operating
 * at SuperSpeed. It extends the standard endpoint descriptor with extra fields
 * needed for USB 3.0 capabilities like burst transactions and streams.
 */
typedef struct
{
    uint8_t bLength;             /*!< Size of this descriptor in bytes */
    uint8_t bDescriptorType;     /*!< SuperSpeed Endpoint Companion descriptor type (0x30) */
    uint8_t bMaxBurst;           /*!< Maximum number of bursts the endpoint can send or receive */

    union
    {
        struct
        {
            uint8_t max_streams : 5; /*!< Maximum number of streams supported (0 means no streams) */
            uint8_t rsvd       : 3;  /*!< Reserved bits (must be zero) */
        } bulk_ep_attributes;         /*!< Bitfield for bulk endpoint attributes */

        uint8_t bmAttributes;         /*!< Raw attributes byte */
    };

    uint8_t wBytesPerInterval;   /*!< Bytes per service interval (for interrupt and isochronous endpoints) */
}/*! \cond */
__attribute__ ((packed))
/*! \endcond */ usb3_ss_ep_comp_desc_t;

/**
 * @brief Represents the USB descriptors used for device configuration.
 *
 * This structure holds various USB descriptor types needed to describe a USB device,
 * including device, configuration, interface, endpoint, and BOS descriptors.
 * It also includes manufacturer, product, and serial string descriptors.
 */
struct usb_descriptors
{
    usb_device_descriptor_t dev_desc;                 /*!< Pointer to the Device Descriptor */
    usb_conf_descriptor_t dev_conf_desc;              /*!< Pointer to the Configuration Descriptor */
    usb_interface_descriptor_t dev_intf_desc;         /*!< Pointer to the Interface Descriptor */
    usb_endpoint_descriptor_t dev_ep_desc;            /*!< Pointer to the Endpoint Descriptor */
    struct usb_bos_root_desc root_bos_desc;           /*!< Pointer to the BOS descriptor set */
    usb3_ss_ep_comp_desc_t ss_ep_comp_desc;           /*!< Pointer to the SuperSpeed Endpoint Companion Descriptor */

    char m_string[128];                                  /*!< Manufacturer string (UTF-8 or ASCII) */
    char p_string[128];                                  /*!< Product string (UTF-8 or ASCII) */
    char s_string[128];                                  /*!< Serial number string (UTF-8 or ASCII) */
};

/**
 * @}
 */
/* end of group usb3_structs */

/**
 * @addtogroup usb3_fns
 * @{
 */
/**
 * @brief Parse usb device descriptor
 *
 * @param[in] xhci_dev_desc xhci device descriptor pointer
 * @param[in] desc          tinyusb stack device descriptor pointer
 */
void xhci_parse_device_descriptor(usb_device_descriptor_t *xhci_dev_desc,
        usb_device_descriptor_t *desc);

/**
 * @brief Parse usb configuration descriptor
 *
 * @param[in] xhci_dev_desc xhci configuration  descriptor pointer
 * @param[in] desc          tinyusb stack configuration descriptor pointer
 */
void xhci_parse_conf_descriptor(usb_conf_descriptor_t *xhci_conf_desc,
        usb_conf_descriptor_t *desc);

/**
 * @brief parse usb3 SS EP companion descriptor
 *
 * @param[in] ss_ep_desc reference to ss ep comp. descriptor
 * @param[in] desc       reference to the descriptor to be parsed
 */
void xhci_parse_ss_endpoint_comp_desc(usb3_ss_ep_comp_desc_t *ss_ep_desc,
        usb3_ss_ep_comp_desc_t *desc);

/**
 * @brief parse usb interface descriptor
 *
 * @param[in] xhci_dev_desc xhci interface descriptor pointer
 * @param[in] desc          tinyusb stack interface descriptor pointer
 */
void xhci_parse_interface_descriptor(usb_interface_descriptor_t *xhci_intf_desc,
        usb_interface_descriptor_t *desc);

/**
 * @brief parse usb root bos descriptor
 *
 * @param[in] root_bos_desc referance to xhci bos descriptor structure
 * @param[in] desc          referance to bos descriptor pointer from the stack
 */
void xhci_parse_bos_descriptor(struct usb_bos_root_desc *root_bos_desc,
        uint8_t *desc);

/**
 * @}
 */
/* end of group usb3_fns */

/**
 * @}
 */
/* end of group usb3 */

#endif /* __SOCFPGA_USB_H__ */
