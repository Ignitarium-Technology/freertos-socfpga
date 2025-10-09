/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for QSPI
 */

/**
 * @file spi_sample.c
 * @brief Sample Application for SPI
 */

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include <stdio.h>
#include <string.h>
#include "socfpga_flash.h"
#include "socfpga_cache.h"
#include "osal_log.h"

/**
 * @defgroup qspi_sample QSPI Flash
 * @ingroup samples
 *
 * Sample Application for QSPI Flash
 *
 * @details
 * @section qspi_desc Description
 * This is a sample application to demonstrate the usage of QSPI flash driver.
 * It writes data to an flash using QSPI, reads it back and then verifies it.

 * This sample app was  tested with Micron MT25QU02GCBB Serial NOR Flash Memory.
 *
 * @section qspi_pre Prerequisites
 * - A QSPI flash device shall be present in the QSPI bus
 *
 * @section qspi_param Configurable Parameters
 * - The memory address to write and read back can be configured in @c START_ADDRESS macro.
 * - The number of bytes to transfer can be configured in @c TEST_DATA_SIZE macro.
 *
 * @section qspi_how_to How to Run
 * 1. Follow the common README instructions to build and flash the application.
 * 2. Run the application on the board.
 * 3. Observe the UART terminal for status messages.
 *
 * @section qspi_result Expected Results
 * - The read and written data are compared, and a success message is printed on match.
 */

/* The size of the data to be written and verified*/
#define TEST_DATA_SIZE    ((4 * 1024 * 1024))

/*The QSPI flash starting offset used in the sample*/
#define START_ADDRESS    0x05000000
#define FLASH_OK         0

/*Buffer to hold the write values*/
uint8_t w_buf[TEST_DATA_SIZE];

/*Buffer to hold the read values*/
uint8_t r_buf[TEST_DATA_SIZE];

/*
 * @brief Initialize test data
 */
void init_test_data() {
    for (int i = 0; i < TEST_DATA_SIZE; i++)
    {
        w_buf[i] = i % 256;
    }
}

int qspi_task(void) {
    PRINT("QSPI flash driver example.");
    PRINT("Estimated Time for Completion: 50 Seconds.");
    int status;
    flash_handle_t flash_handle;

    /*Populate the write data*/
    init_test_data();
    cache_force_write_back((void *)w_buf, sizeof(w_buf));

    /*Initialise the flash driver*/
    flash_handle = flash_open(QSPI_DEV0);

    PRINT("Erase in progess...");
    status = flash_erase_sectors(flash_handle, START_ADDRESS, TEST_DATA_SIZE);
    if (status < FLASH_OK)
    {
        ERROR("Erase failed with error code %d", status);
        return -1;
    }
    PRINT("Erased %d sectors from start address : 0x%x", status, START_ADDRESS);

    PRINT("Done.");

    PRINT("Writing 4MB of data to the offset  0x%x...", START_ADDRESS);
    status =
            flash_write_sync(flash_handle, START_ADDRESS, w_buf,
            TEST_DATA_SIZE);
    if (status != FLASH_OK)
    {
        ERROR("Write failed with error code %d\r\n", status);
        return -1;
    }
    PRINT("Done.");

    for (int i = 0; i < TEST_DATA_SIZE; i++)
    {
        r_buf[i] = 0x00;
    }
    cache_force_write_back((void *)r_buf, sizeof(r_buf));

    PRINT("Reading 4MB of data from the offset 0x%x...", START_ADDRESS);
    status =
            flash_read_sync(flash_handle, START_ADDRESS, r_buf, TEST_DATA_SIZE);
    if (status != FLASH_OK)
    {
        ERROR("Read failed with error code %d", status);
        return -1;
    }
    PRINT("Done.");
    cache_force_invalidate((void *)r_buf, sizeof(r_buf));

    PRINT("Validating read values...");
    if (memcmp(r_buf, w_buf, TEST_DATA_SIZE) == 0)
    {
        PRINT("Done.");
    }
    else
    {
        ERROR("Data Mismatch.");
    }
    flash_close(flash_handle);

    PRINT("QSPI Flash driver example completed");

    return 0;
}
