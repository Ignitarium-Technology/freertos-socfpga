/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for I3c
 */

/**
 * @file i3c_sample.c
 * @brief Sample Application for I3C
 */

#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <task.h>
#include <stdbool.h>
#include <string.h>
#include <socfpga_i3c.h>
#include "osal.h"
#include "osal_log.h"

/**
 * @defgroup i3c_sample I3C
 * @ingroup samples
 *
 * Sample Application for I3C
 *
 * @details
 * @section i3c_desc Description
 * This is a sample application to demonstrate the usage of I3C driver.
 * It uses two devices for the data transfer. The first is an I3C temparature sensor.
 * And the second is a legacy I2C EEPROM.
 * The sample uses LPS27HHW temperature sensor as the I3C slave. The application reads
 * temperature from the sensor for 10 iterations.
 * It performs writes and reads to the legacy I2C EEPROM device.
 *
 * @section i3c_pre Prerequisites
 * - A serial EEPROM with I2C interface may be connected to the I3C bus.
 * - If the I2C device is connected, the slave address shall be updated in this file.
 * - A LPS27HHW temperature sensor shall be connected to the I3C bus.
 *
 * @section i3c_param Configurable Parameters
 * - The connected_devices structure shall be initialized with the correct device properties
 * - The memory address to write and read back can be configured in @c EEPROM_START_ADDRESS macro.
 * - The number of bytes to transfer can be configured in @c NUM_TEST_BYTES macro.
 * - The I2C test can be disabled or enabled with macro @c ENABLE_I2C_I3C_TEST .
 *
 * @section i3c_how_to How to Run
 * 1. Follow the common README instructions to build and flash the application.
 * 2. Run the application on the board with the EEPROM connected.
 * 3. Observe the UART terminal for status messages.
 *
 * @section i3c_result Expected Results
 * - The write and read data to EEPROM are verified, and a success message is printed.
 * - Temperature in degree Celsius from the LPS27HHW sensor is printed 10 times.
 */

/* I2C test macro */
#define ENABLE_I2C_I3C_TEST    1

#define I3C_INSTANCE      1
#define DEV_ADDRESS       0
#define NUM_TEST_BYTES    64

/* LPS27HHW register addresses */
#define WHOAMI    0x0F

#define CTRL_1    0x10
#define CTRL_2    0x11
#define CTRL_3    0x12

#define TEMP_OUT_L    0x2B
#define TEMP_OUT_H    0x2C

#define STATUS    0x27

/* LPS27HHW Device ID */
#define LPS27HHW_DEV_ID      0xB3

/* EEPROM I2C Slave address */
#define EEPROM_ADDRESS       0x50
#define EEPROM_START_ADDR    0x00

/* EEPROM write buffer*/
uint8_t wr_buf[NUM_TEST_BYTES + 5];

/* EEPROM read buffer*/
uint8_t rd_buf[NUM_TEST_BYTES + 5];

/* Structure to describe the devices connected to the I3C bus. I3C controller supports both
 * I3C devices and legacy I2C devices. For I3C devices both the static address and
 * preferred dynamic address is set as zero and  device_id is set with the PID of the slave device.
 * For legacy I2C device the PID is set a zero and the static address field is set with the address
 * of the device.
 */
struct i3c_i3c_device connected_devices[] =
{
    {
        .static_address = DEV_ADDRESS,
        .device_id = 0x0000020800B30,    /*LPS27HHTW MEMS pressure sensor PID*/
        .preferred_dynamic_address = 0
    },

    {
        .static_address = EEPROM_ADDRESS,
        .device_id = 0x0,               /*PID as zero for legacy I2C devices*/
        .preferred_dynamic_address = 0
    },
};

/*
 * @brief Fill the buffer with a sequential pattern starting at start_num
 */
static void fill_buffer(uint8_t *buf, uint32_t nbytes, uint8_t start_num)
{
    uint32_t i;
    for (i = 0; i < nbytes; i++)
    {
        *(buf + i) = start_num++;
    }
}

/*
 * @brief verify buffer for the expected pattern
 */
static int verify_buffer(uint8_t *buf, uint32_t nbytes, uint8_t start_num)
{
    int ret = 0;
    uint32_t i;
    for (i = 0; i < nbytes; i++, start_num++)
    {
        if ((*(buf + i)) != start_num)
        {
            ERROR("mismatch at index %d: expected 0x%2.2X got 0x%2.2X", i,
                    start_num, (*(buf + i)));
            ret = -1;
            break;
        }
    }
    return ret;
}

/*
 * @brief Read from legacy I2C EEPROM.
 *
 *    For EEPROM read two transfer requests are to be sent. The first request is
 *    to write the desired offset. The second is the read transfer request.
 *    The first transfer request is a write operation which is indicated to the
 *    driver by setting 'read' flag of the request as false. The second transfer
 *    request is a read operation which is indicated to the driver by setting the
 *    'read' flag as true To indicate that this is a legacy I2C device the
 *    'is_i2c' flag is set.
 */
int eeprom_i3c_i2c_read(uint8_t reg_address, uint8_t *data, uint32_t num_bytes)
{

    int retval = 0;
    struct i3c_xfer_request xfer_request[2];
    uint8_t xfer_cmd[2];
    bool is_i2c = true;

    xfer_cmd[0] = (reg_address >> 8) & 0xFF;
    xfer_cmd[1] = reg_address & 0xFF;

    xfer_request[0].buffer = xfer_cmd;
    xfer_request[0].length = 2;
    xfer_request[0].read = false;

    memset(data, 0, num_bytes);
    xfer_request[1].buffer = data;
    xfer_request[1].length = num_bytes;
    xfer_request[1].read = true;

    /* The I2C transfer function */
    retval = i3c_transfer_sync(I3C_INSTANCE, EEPROM_ADDRESS, xfer_request, 2,
            is_i2c);

    return retval;
}

/*
 * @brief Write to legacy I2C EEPROM.
 *
 *    For EEPROM write one transfer transfer request is sufficient. The first
 *    two bytes of the transfer is used to indicate the offset and the rest
 *    is the data. For write operation the 'read' flag of the transfer is
 *    set as false. To indicate that this is a legacy I2C device 'is_i2c'
 *    flag is set.
 */
int eeprom_i3c_i2c_write(uint8_t reg_address, uint8_t *data, uint8_t num_bytes)
{
    int32_t retval = 0;
    uint8_t xfer_data[num_bytes + 2], i;
    bool is_i2c = true;

    struct i3c_xfer_request xfer_request;

    xfer_data[0] = (reg_address >> 8) & 0xFF;
    xfer_data[1] = reg_address & 0xFF;

    for (i = 0; i < num_bytes; i++)
    {
        xfer_data[2 + i] = data[i];
    }
    xfer_request.buffer = xfer_data;
    xfer_request.length = num_bytes + 2;
    xfer_request.read = false;

    retval = i3c_transfer_sync(I3C_INSTANCE, EEPROM_ADDRESS, &xfer_request, 1,
            is_i2c);
    return retval;
}

/*
 *  @brief Read lps27hhw device register.
 *
 *    The lps27hhw sensor is an I3C slave. The I3C controller communicates with the
 *    sensor using the dynamic address allocated to the device by the I3C controller.
 *    The read operation is carried out using two transfer requests. The first one is
 *    a write request to send the register address. The second request is a read
 *    transaction to get the register value. To indicate that the device is not a
 *    legacy I2C device the 'is_i2c' flag is set as flase.
 */
int lps27hhw_read_register(uint8_t reg_address, uint8_t *data,
        uint8_t num_bytes)
{
    int32_t retval = 0;
    struct i3c_xfer_request xfer_request[2];
    bool is_i2c = false;

    xfer_request[0].buffer = &reg_address;
    xfer_request[0].length = sizeof(reg_address);
    xfer_request[0].read = 0;

    memset(data, 0, num_bytes);
    xfer_request[1].buffer = data;
    xfer_request[1].length = num_bytes;
    xfer_request[1].read = 1;

    retval = i3c_transfer_sync(I3C_INSTANCE,
            connected_devices[0].dynamic_address,
            xfer_request, 2, is_i2c);

    return retval;
}

/*
 * @brief Write to lps27hhw device.
 *
 *    The lps27hhw sensor is an I3C slave. The I3C controller communicates with the
 *    sensor using the dynamic address  allocated to the device by the I3C controller.
 *    The write operation is carried out using one write transfer request. This is a
 *    write request with register address and write data. To indicate that the
 *    device is not a legacy I2C device the 'is_i2c' flag is to be set as false.
 */
int lps27hhw_write_register(uint8_t reg_address, uint8_t *data,
        uint8_t num_bytes)
{
    int32_t retval = 0;
    uint8_t xfer_data[10], i;
    bool is_i2c = false;

    struct i3c_xfer_request xfer_request;

    xfer_data[0] = reg_address;
    for (i = 0; i < num_bytes; i++)
    {
        xfer_data[1 + i] = data[i];
    }

    xfer_request.buffer = xfer_data;
    xfer_request.length = num_bytes + 1; /* for register address */
    xfer_request.read = 0; /* write request */

    retval = i3c_transfer_sync(I3C_INSTANCE,
            connected_devices[0].dynamic_address,
            &xfer_request, 1, is_i2c);

    return retval;
}

void i3c_task(void)
{
    PRINT("Starting I3C sample application.");
    struct i3c_dev_list dev_list =
    {
        .num_devices = 2, .list =
                connected_devices,
    };

    int32_t retval;
    uint8_t reg_address = 0x0F;
    uint8_t whoam_i = 0, data[4];
    uint32_t itr = 0;

    /*
     * Configure and initialize the i3c controller instances
     * Setup the role of the instance(primary/secondary)
     * Initializes the address allotment table
     */

    retval = i3c_open(I3C_INSTANCE);
    if (retval != 0)
    {
        ERROR("i3c instance not intialized");
        return;
    }

    /* Add the devices connected to the bus */
    PRINT("Attaching the devices to the bus ...");
    retval = i3c_ioctl(I3C_INSTANCE, I3C_IOCTL_TARGET_ATTACH, &dev_list);
    if (retval != 0)
    {
        ERROR("I3C Target not attached");
        return;
    }
    PRINT("Done.");

    /* Initialize the i3c bus. Performs dynamic address assignment  */
    PRINT("Initializing the I3C bus ...");
    retval = i3c_ioctl(I3C_INSTANCE, I3C_IOCTL_BUS_INIT, &connected_devices[0]);
    if (retval != 0)
    {
        PRINT("Dynamic address not assigned to devices");
    }
    PRINT("Done.");
#ifdef ENABLE_I2C_I3C_TEST
    PRINT("Starting I2C test.");
    /*Perform Test for the I2C device*/
    PRINT("Checking if I2C device is valid ...");
    retval = i3c_ioctl(I3C_INSTANCE, I2C_IOCTL_ADDRESS_VALID,
            &connected_devices[1]);
    if (retval != 0)
    {
        PRINT("Invalid I2C device address");
    }
    else
    {
        PRINT("Done.");
        fill_buffer(wr_buf, NUM_TEST_BYTES, 0x30);
        PRINT("Write data :");
        for (int i = 0; i < NUM_TEST_BYTES; i++)
        {
            PRINT("0x%02X", wr_buf[i]);
        }
        PRINT("Writing %d bytes to the offset 0x%x in EEPROM ...",
                NUM_TEST_BYTES, EEPROM_START_ADDR);
        retval = eeprom_i3c_i2c_write(EEPROM_START_ADDR, wr_buf,
		        NUM_TEST_BYTES);
        if (retval != 0)
        {
            ERROR("Failed to write data to the EEPROM");
        }
        PRINT("Done.");
        osal_task_delay(100);
        PRINT("Reading %d bytes from the offset 0x%x in EEPROM ...",
                NUM_TEST_BYTES, EEPROM_START_ADDR);
        retval = eeprom_i3c_i2c_read(EEPROM_START_ADDR, rd_buf, NUM_TEST_BYTES);
        PRINT("Read data :");
        for (int i = 0; i < NUM_TEST_BYTES; i++)
        {
            PRINT("0x%02X", rd_buf[i]);
        }
        if (retval != 0)
        {
            PRINT("Failed to read  data from the EEPROM");
        }
        PRINT("Done.");
        retval = verify_buffer(rd_buf, NUM_TEST_BYTES, 0x30);
        if (retval == 0)
        {
            PRINT("EEPROM read and write successful");
        }
        else
        {
            PRINT("EEPROM read and write mismatch");
        }
    }
    PRINT("I2C test compelted.");
#endif
    PRINT("Starting I3C test");
    /*Get the assigned dynamic address of the I3C device*/
    PRINT("Getting I3C slave dynamic address ...");
    retval = i3c_ioctl(I3C_INSTANCE, I3C_IOCTL_GET_DYNADDRESS,
            &connected_devices[0]);
    if (retval != 0)
    {
        PRINT("Dynamic address not assigned");
    }
    else
    {
        PRINT("Done.");
        /* Performs read transfer of the whoam_i register of LPS27HHW device
         * The read is synchronous in nature*/
        reg_address = WHOAMI;
        whoam_i = 0;
        PRINT("Getting device ID ...");
        retval = lps27hhw_read_register(reg_address, &whoam_i, 1);
        if (retval != 0)
        {
            ERROR("Read Transfer not successful");
        }
        else
        {
            PRINT("LPS27HHW Device ID received : 0x%x, Actual= 0x%x", whoam_i,
                    LPS27HHW_DEV_ID);
        }

        /*
         * perform SW reset
         */

        reg_address = CTRL_2;
        memset(data, 0, sizeof(data));
        retval = lps27hhw_read_register(reg_address, &data[0], 1);

        reg_address = CTRL_2;
        data[0] |= 0x4; /* CTRL 2 val */
        retval = lps27hhw_write_register(reg_address, &data[0], 1);

        do
        {
            reg_address = CTRL_2;
            data[0] = 0;
            retval = lps27hhw_read_register(reg_address, &data[0], 1);
        } while (data[0] & 0x4);   /* wait until SW bit is cleared */

        reg_address = CTRL_1;
        data[0] = 0x12; /* SET BDU and ODR */
        retval = lps27hhw_write_register(reg_address, &data[0], 1);

        /* read back ctrl_1 */
        osal_task_delay(10);
        reg_address = CTRL_1;
        data[0] = 0;
        retval = lps27hhw_read_register(reg_address, &data[0], 1);

        PRINT("Reading temperature sensor value for 10 iterations ...");
        /* read temperature continuously for 10 times */
        while (itr < 10)
        {
            /* read the status register to check if new temp data is generated */
            reg_address = STATUS;
            data[0] = 0;
            retval = lps27hhw_read_register(reg_address, &data[0], 1);
            osal_task_delay(100);
            if ((retval == 0) && (data[0] & 0x2))   /* bit 1 indicates new temp data */
            {
                /* read temp reading*/
                reg_address = TEMP_OUT_L;
                data[0] = 0;
                retval = lps27hhw_read_register(reg_address, &data[0], 1);
                osal_task_delay(100);
                if (retval != 0)
                {
                    ERROR("Write Transfer not successful");
                }
                else
                {
                    reg_address = TEMP_OUT_H;
                    data[1] = 0;
                    retval = lps27hhw_read_register(reg_address, &data[1], 1);
                    if (retval != 0)
                    {
                        ERROR("Write Transfer not successful");
                    }
                    else
                    {
                        PRINT("Temperature reading =  %d *C",
                                ((data[1] << 8) | (data[0])) / 100);
                    }
                }
            }
            osal_task_delay(1000);
            itr++;
        }
        PRINT("Done.");
        PRINT("I3C test completed");
    }
    PRINT("I3C sample completed.");
}
