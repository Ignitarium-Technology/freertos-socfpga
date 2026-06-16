/**
 * SPDX-FileCopyrightText: Copyright (C) 2025-2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for I3C HAL driver
 */

#ifndef __SOCFPGA_I3C_H__
#define __SOCFPGA_I3C_H__

/**
 * @file socfpga_i3c.h
 * @brief I3C HAL driver header file.
 *
 */

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @defgroup i3c I3C
 * @ingroup drivers
 * @brief APIs for Soc FPGA I3C driver.
 * @details
 *
 * This driver provides methods to perform operations with an I3C
 * or an I2C device connected to the SoC FPGA I3C bus.
 *
 * The driver supports DAA and DASA and can communicate with both I2C and I3C
 * devices connected to the bus in interrupt mode. For I3C devices the
 * I3C controller will assign an address if needed whereas for an I2C device its
 * static address is used to communicate with the controller.
 *
 * A typical usage flow is as follows:
 *
 * 1. Initialize the driver using the `i3c_open` API.
 * 2. Prepare an array of type `struct i3c_device`. Each entry in the array should be
 *    filled with the properties of the I3C or I2C device present on the bus.
 * 3. Use the `I3C_IOCTL_TARGET_ATTACH` IOCTL to attach the devices. Use the above
 *    array as the parameter to this IOCTL.
 * 4. Use the `I3C_IOCTL_BUS_INIT` IOCTL to trigger dynamic address assignment.
 * 5. For I3C devices, use the `I3C_IOCTL_GET_DYNADDRESS` IOCTL to get the dynamic address.
 * 6. For I2C devices, use the `I2C_IOCTL_ADDRESS_VALID` IOCTL to verify that the slave address is valid.
 * 7. Perform read/write operations as desired using the `i3c_transfer_sync` API.
 *
 * To see example usage, see @ref i3c_sample "I3C sample application"
 * @{
 */

/**
 * @defgroup i3c_fns Functions
 * @ingroup i3c
 * I3C HAL APIs
 */

/**
 * @defgroup i3c_structs Structures
 * @ingroup i3c
 * I3C Specific Structures
 */

/**
 * @defgroup i3c_enums Enumerations
 * @ingroup i3c
 * I3C Specific Enumerations
 */

/**
 * @defgroup i3c_macros Macros
 * @ingroup i3c
 * I3C Specific Macros
 */

/**
 * @addtogroup i3c_macros
 * @{
 */
/**
 * @brief I3C controller instance specification.
 */
#define I3C_INSTANCE1        0x0U
#define I3C_INSTANCE2        0x1U
#define I3C_NUM_INSTANCES    0x2U
/**
 * @}
 */

/**
 * @brief Specifies the different IOCTL requests allowed by the I3C controller driver.
 * @ingroup i3c_enums
 */
enum i3c_ioctl_request
{
    I3C_IOCTL_TARGET_ATTACH,
    I3C_IOCTL_BUS_INIT,
    I3C_IOCTL_DO_DAA,
    I3C_IOCTL_GET_DYNADDRESS,
    I2C_IOCTL_ADDRESS_VALID,
    I3C_IOCTL_CONFIG_IBI
};

/**
 * @addtogroup i3c_structs
 * @{
 */

/**
 * @brief Structure used to describe an I3C device that is connected to the I3C controller instance.
 */
struct i3c_device
{
    /* 48-bit provisioned device ID in lower bits. Set to zero for I2C devices. */
    uint64_t device_id;

    /**
     * Static target address.
     *
     * Set to 0 to use dynamic address assignment through DAA.
     */
    uint8_t static_address;

    /**
     * Preferred dynamic address for the target.
     *
     * The final assigned value is reflected in dynamic_address.
     */
    uint8_t preferred_dynamic_address;

    /* Final target address assigned under the controller. */
    uint8_t dynamic_address;

    /* Bus characteristics register value. */
    uint8_t bcr;
};


/**
 * @brief Structure used to pass the information of all the I3C devices that are connected to the I3C controller instance.
 */
struct i3c_dev_list
{
    /* Number of device objects in list. */
    uint16_t num_devices;

    /* List of targets connected to this controller. */
    struct i3c_device *list;
};

/**
 * @brief Structure used to configure IBI enable/disable for a device.
 */
struct i3c_ibi_config
{
    /* Target device object. */
    struct i3c_device *dev;

    /* Set true to enable IBI, false to disable IBI. */
    bool enable;
};

struct i3c_descriptor;
typedef struct i3c_descriptor *i3c_handle_t;

/**
 * @brief Callback function for i3c operations
 * @param[in] stat I3C instance
 * @param[in] param function param
 */
typedef void (*i3c_callback_t)(int stat,
        void *param);

/**
 * @brief Callback function for IBI events.
 * @param[in] ibi_id IBI ID received in IBI queue status.
 * @param[in] status IBI status field.
 * @param[in] payload Pointer to payload bytes if present.
 * @param[in] payload_len Number of payload bytes.
 * @param[in] param user context.
 */
typedef void (*i3c_ibi_callback_t)(uint8_t ibi_id, uint8_t status,
        const uint8_t *payload, uint8_t payload_len, void *param);

/**
 * @brief Structure used by the user layer to make read/write from/to a connected device (after I3C_IOCTL_TARGET_ATTACH and I3C_IOCTL_BUS_INIT).
 */
struct i3c_xfer_request
{
    /**
     * Data buffer.
     *
     * For write, points to source bytes.
     * For read, points to destination bytes.
     */
    uint8_t *buffer;

    /* Transfer size in bytes. */
    uint16_t length;

    /* Set true for read transfer, false for write transfer. */
    bool read;
};
/**
 * @}
 */

/**
 * @addtogroup i3c_fns
 * @{
 */
/**
 * @brief Initialize and open an I3C controller instance.
 *
 * @param[in] instance  Instance of the I3C controller.
 * @return
 * - valid `i3c_handle_t` on success.
 * - `NULL` on failure.
 */
extern i3c_handle_t i3c_open(uint8_t instance);

/**
 * @brief Close an open I3C controller handle.
 *
 * @param[in] hi3c Handle returned by i3c_open().
 * @return
 * - 0 on success.
 * - -EINVAL if handle is NULL or not open.
 */
extern int32_t i3c_close(i3c_handle_t hi3c);

/**
 * @brief Send a CCC command to a target.
 * @param[in] hi3c I3C controller handle.
 * @param[in] cmd_id CCC command ID.
 * @param[in] target_address Target address (0 for broadcast).
 * @param[in] data Pointer to payload data buffer.
 * @param[in] data_length Payload length.
 * @param[in] read Read command if true.
 * @return 0 on success, negative error code on failure.
 */
extern int32_t i3c_send_ccc(i3c_handle_t hi3c, uint8_t cmd_id,
        uint8_t target_address, uint8_t *data, uint16_t data_length, bool read);

/**
 * @brief Enable IBI for a target device.
 * @param[in] hi3c I3C controller handle.
 * @param[in] dev Target device descriptor.
 * @return 0 on success, negative error code on failure.
 */
extern int32_t i3c_enable_ibi(i3c_handle_t hi3c, struct i3c_device *dev);

/**
 * @brief Disable IBI for a target device.
 * @param[in] hi3c I3C controller handle.
 * @param[in] dev Target device descriptor.
 * @return 0 on success, negative error code on failure.
 */
extern int32_t i3c_disable_ibi(i3c_handle_t hi3c, struct i3c_device *dev);

/**
 * @brief Register IBI callback for an I3C handle.
 * @param[in] hi3c I3C controller handle.
 * @param[in] callback Callback function.
 * @param[in] param user context.
 * @note Callback runs in ISR context and must be non-blocking.
 */
extern void i3c_set_ibi_callback(i3c_handle_t hi3c, i3c_ibi_callback_t callback,
        void *param);

/**
 * @brief Configure I3C controller instance with user configuration.
 *
 * @note I3C_IOCTL_TARGET_ATTACH: Request for adding the devices connected to the controller.
 * Uses struct i3c_dev_list to pass the number of devices and their properties to the controller.
 *
 * @note I3C_IOCTL_BUS_INIT: Used for enumerating the I3C bus. The I3C_IOCTL_TARGET_ATTACH should
 * be called before calling this request. This ioctl will try to assign dynamic addresses to all the
 * connected devices. Once this is completed, read/write transactions can be performed with the devices.
 *
 * @note I3C_IOCTL_DO_DAA: Perform the dynamic address assignment to the connected devices
 * which do not have static addresses.
 *
 * @note I3C_IOCTL_CONFIG_IBI: Enable/disable the slave in-bound interrupt.
 *
 * @param[in] hi3c     I3C controller handle.
 * @param[in] ioctl    IOCTL request.
 * @param[in] pargs    Pointer to the arguments for the IOCTL request.
 *
 * @return
 * - 0 on success.
 * - -EINVAL for invalid args/handle.
 * - negative errno on failure.
 */
extern int32_t i3c_ioctl(i3c_handle_t hi3c, enum i3c_ioctl_request ioctl,
        void *pargs);

/**
 * @brief set I3C callback
 * @param[in] hi3c      I3C controller handle.
 * @param[in] callback  The callback to be registered.
 * @param[in] param    Parameters that are to be passed to the callback.
 * @return    NIL
 */
extern void i3c_set_callback(i3c_handle_t hi3c,
        i3c_callback_t callback, void *param);

/**
 * @brief Perform a data transfer between the controller and the target device.
 *
 * @param[in] hi3c          I3C controller handle.
 * @param[in] address       Dynamic address of the target to which the transfer is requested.
 * @param[in] pxfer_request Pointer to the transfer request list.
 * @param[in] num_xfers     Number of transfers requested.
 * @param[in] is_i2c        Indicates if the transfer is for an I2C device.
 *
 * @return
 * - 0 on success.
 * - -EINVAL if arguments are invalid.
 * - -EBUSY if transfer is already in progress.
 * - negative errno on failure.
 */
extern int32_t i3c_transfer_sync(i3c_handle_t hi3c, uint8_t address, struct
        i3c_xfer_request *pxfer_request, uint8_t num_xfers, bool is_i2c);

/**
 * @brief Perform a data transfer between the controller and the target device.
 *
 * @param[in] hi3c          I3C controller handle.
 * @param[in] address       Dynamic address of the target to which the transfer is requested.
 * @param[in] pxfer_request Pointer to the transfer request list.
 * @param[in] num_xfers     Number of transfers requested.
 * @param[in] is_i2c        Indicates if the transfer is for an I2C device.
 *
 * @return
 * - 0 on success.
 * - -EINVAL if arguments are invalid.
 * - -EBUSY if transfer is already in progress.
 * - negative errno on failure.
 */
extern int32_t i3c_transfer_async(i3c_handle_t hi3c, uint8_t address, struct
        i3c_xfer_request *pxfer_request, uint8_t num_xfers, bool is_i2c);

/**
 * @}
 */
/**
 * @}
 */

#endif
