/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for FAT FS operation with SD card storage
 */

/**
 * @file fatfs_sample.c
 * @brief Sample Application for fatfs operations.
 */

/**
 * @defgroup fatfs_sample FAT-FS
 * @ingroup samples
 *
 * Sample Application for fatfs opertaions.
 *
 * @details
 * @section fat_desc Description
 * This is a sample application to demonstrate the fatfs operations on SD card.
 * The sample performs the following operations sequentially on the first available fat partition.
 * The partition number can be configred using FAT_PARTITION macro.
 * It does the following operations.
 * - Identify all the fatfs partition in the sdcard.
 * - Mount the first fat partition.
 * - Write data to a text file.
 * - Create a directory in the partition.
 * - Delete the directry.
 * - Read and display data from the text file.
 * - Delete the file.
 * - Unmount the fat partition.
 *
 * @section fat_pre Prerequisites
 * The SD card should be partitioned as FAT partition. In Linux based systems, you may use the below commands:
 *  - Use fdisk to partition the SD card.
 *        - Use mkfs tool to format the sd card partition into FAT.
 *            - sudo mkfs.fat /dev/&lt;partition&gt;
 *
 * @section fat_howto How to Run
 * 1. Follow the common README for build and flashing instructions.
 * 2. Insert the partitioned SD card into the device, and run the sample.
 *
 * @section fat_res Expected Results
 * - The result of fat operations are displayed in the console.
 * @{
 */
/** @} */

#include "ff_sddisk.h"
#include "FreeRTOS.h"
#include "ff_sys.h"
#include "ff_stdio.h"
#include "fatfs_sample.h"
#include <string.h>
#include "osal_log.h"

#define MOUNT_POINT      "/sdcard"
#define FAT_PARTITION    (0)

void fatfs_task(void)
{
    FF_Disk_t *pdisk;
    FF_FILE *file;
    FF_Error_t error;
    FF_SPartFound_t parts_found;
    parts_found.iCount = 0;
    const char *file_name = "/sample.txt";
    char *pdata_to_write =
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor";
    const char *psample_dir = "/Test1";
    uint8_t read_buffer[128];
    size_t bytes_written, bytes_read;

    pdisk = FF_SDDiskInit(MOUNT_POINT, -1);
    if (pdisk == NULL)
    {
        ERROR("Failed to initialize disk");
        return;
    }

    /* Get the Fatfs partition count */
    int fat_pcount = FF_PartitionSearch(pdisk->pxIOManager, &parts_found);

    PRINT("Fatfs partitions available : %d", fat_pcount);

    if (fat_pcount == 0)
    {
        ERROR("SD card does not contain any fat partition!!!");
        ERROR("Exiting fatfs sample application");
        return;
    }

    PRINT("Running fat operations on first partition");

    error = FF_Mount(pdisk, FAT_PARTITION);
    if (error != FF_ERR_NONE)
    {
        ERROR("Failed to mount filesystem");
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    PRINT("File system mounted successfully");

    file = FF_Open(pdisk->pxIOManager, file_name,
            FF_MODE_WRITE | FF_MODE_CREATE, &error);
    if ((file == NULL) || (error != FF_ERR_NONE))
    {
        ERROR("Failed to open file for writing");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    bytes_written = FF_Write(file, 1, strlen((char *)pdata_to_write),
            (uint8_t *)pdata_to_write);
    if ((bytes_written != strlen((char *)pdata_to_write)) || (error !=
            FF_ERR_NONE))
    {
        ERROR("Failed to write data to file");
        FF_Close(file);
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    FF_Close(file);
    PRINT("Data written to file successfully");

    error = FF_MkDir(pdisk->pxIOManager, psample_dir);
    if (error != FF_ERR_NONE)
    {
        ERROR("Failed to create directory");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    PRINT("Directory created successfully");

    error = FF_RmDir(pdisk->pxIOManager, psample_dir);
    if (error != FF_ERR_NONE)
    {
        ERROR("Failed to remove directory");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    PRINT("Directory removed successfully");

    file = FF_Open(pdisk->pxIOManager, file_name, FF_MODE_READ, &error);
    if ((file == NULL) || (error != FF_ERR_NONE))
    {
        ERROR("Failed to open file for reading");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    bytes_read = FF_Read(file, 1U, sizeof(read_buffer) - 1U, read_buffer);
    if ((bytes_read <= 0) || (error != FF_ERR_NONE))
    {
        ERROR("Failed to read data from file");
        FF_Close(file);
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    read_buffer[bytes_read] = '\0';
    FF_Close(file);
    PRINT("Data read from file: %s", read_buffer);

    error = FF_RmFile(pdisk->pxIOManager, file_name);
    if (error != FF_ERR_NONE)
    {
        ERROR("Failed to delete file");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    PRINT("File deleted successfully");

    error = FF_Unmount(pdisk);
    if (error != FF_ERR_NONE)
    {
        ERROR("Failed to unmount filesystem");
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting fatfs sample application");
        return;
    }
    PRINT("Filesystem unmounted successfully");

    FF_SDDiskDelete(pdisk);
    PRINT("Disk deleted successfully");
    PRINT("FATFS sample application completed");
}
