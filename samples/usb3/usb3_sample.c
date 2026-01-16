/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample fatfs application for agilex5 USB3.1
 */

/**
 * @file usb3_sample.c
 * @brief Sample Application for usb3.1 driver.
 */

/**
 * @defgroup usb3_sample USB3.1
 * @ingroup samples
 *
 * Sample Application for USB3.1 operations
 *
 * @details
 * @section usb_desc Description
 * This is a sample application to demonstrate the fatfs operations on USB3.1 disk. The sample performs the following operations sequentially on the first fat partitions:
 * - Identify the total fatfs partition in the disk.
 * - Mount the first fat partition.
 * - Write data to a text file.
 * - Create a directory in the partition.
 * - Delete the directry.
 * - Read and display data from the text file.
 * - Delete the file.
 * - Unmount the fat partition.
 *
 * @note The sample supports both USB2 and USB3 devices.
 * @note If the device boots in HPS first configuration, then the core.rbf bitstream needs to be loaded before starting the sample.
 *
 * @section usb_pre Prerequisites
 * The USB disk should be partitioned as FAT partition. For Linux based systems, you may use the below commands :
 *  - Use fdisk to partition the USB mass storage device.
 *        - Use mkfs tool to format the USB disk partition into FAT.
 *            - sudo mkfs.fat /dev/&lt;partition&gt;
 *
 * @section usb_howto How to Run
 * 1. Follow the common README for build and flashing instructions.
 * 2. Insert the partitioned USB device into the device, and run the sample..
 *
 * @section usb_res Expected Results
 * The result of fat operations are displayed in the console.
 *
 * @note File names used in application should conform to the 8.3 format (maximum 8 characters for the name.
 * @{
 */
/** @} */


#include "ff_sddisk.h"
#include "ff_sys.h"
#include "usb_main.h"
#include "osal_log.h"

#define TASK_PRIORITY    (configMAX_PRIORITIES - 2)

#define USB_MOUNT_POINT    "/usb"
#define USB_MOUNT_ADDR     0
#define FAT_PARTITION      0
#define USB3_TIMEOUT       (10)

void run_usb_fatfs(void);

void usb3_sample_task(void)
{
    BaseType_t xReturn;

    xReturn = xTaskCreate(usb_task, "usb3_sample",
            configMINIMAL_STACK_SIZE * 20, NULL,
            TASK_PRIORITY - 1, NULL);
    if (xReturn != 1)
    {
        /* can not create task */
        while (1);
    }

    run_usb_fatfs();
}

void run_usb_fatfs(void)
{
    const char *file_name = "/b.txt";
    const char *pcSampleDir = "/Test1";
    char *write_data1 =
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor";
    uint8_t pcReadBuffer[512] = {0};
    size_t bytes_written, bytes_read;
    int ret;

    FF_Disk_t *pdisk;
    FF_FILE *file;
    FF_Error_t err;
    FF_SPartFound_t parts_found;
    parts_found.iCount = 0;

    PRINT("Waiting for the USB3 disk to be mounted...");

    /* wait for the usb3 disk to be mounted */
    ret = usb_wait_to_mount(USB3_TIMEOUT);
    if (ret != 0)
    {
        ERROR("Usb timeout occured... No device mounted");
        ERROR("Exiting sample application");
        return;
    }

    PRINT("USB mass storaged device mounted successfully");
    /***********************************************************************************/
    /*                          USB Disk Init                                          */
    /***********************************************************************************/
    PRINT("Initializing the disk...");
    pdisk = FF_SDDiskInit(USB_MOUNT_POINT, USB_MOUNT_ADDR);
    if (pdisk == NULL)
    {
        ERROR("Failed to initialize disk");
        return;
    }
    PRINT("Disk initilization done");

    /* Get the Fatfs partition count */
    int fat_pcount = FF_PartitionSearch(pdisk->pxIOManager, &parts_found);

    PRINT("Fatfs partitions available : %d", fat_pcount);

    if (fat_pcount == 0)
    {
        ERROR("USB disk does not contain any fat partition!!!");
        return;
    }

    PRINT("Running fat operations on first partition");

    /***********************************************************************************/
    /*                          Mount the USB                                          */
    /***********************************************************************************/
    PRINT("Mounting the FAT partition...");
    err = FF_Mount(pdisk, FAT_PARTITION);
    if (err != FF_ERR_NONE)
    {
        ERROR("Failed to mount filesystem");
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("FAT partition mounted successfully");

    /***********************************************************************************/
    /*                          create a directory                                     */
    /***********************************************************************************/
    PRINT("Creating directory...");
    err = FF_MkDir(pdisk->pxIOManager, pcSampleDir);
    if (err != FF_ERR_NONE)
    {
        ERROR("Failed to create directory");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("Directory created successfully");

    /***********************************************************************************/
    /*                         delete the directory                                    */
    /***********************************************************************************/
    PRINT("Deleting the directory...");
    err = FF_RmDir(pdisk->pxIOManager, pcSampleDir);
    if (err != FF_ERR_NONE)
    {
        ERROR("Failed to remove directory");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("Directory deleted successfully");

    /***********************************************************************************/
    /*                         write to a file                                         */
    /***********************************************************************************/
    PRINT("Writing data to a file...");
    PRINT("Opening file...");
    file = FF_Open(pdisk->pxIOManager, file_name,
            FF_MODE_WRITE | FF_MODE_CREATE, &err);
    if ((file == NULL) || (err != FF_ERR_NONE))
    {
        ERROR("Failed to open file for writing");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("File opened successfully");
    bytes_written = FF_Write(file, 1, strlen(
            (char *)write_data1), (uint8_t *)write_data1);
    if ((bytes_written != strlen((char *)write_data1)) || (err != FF_ERR_NONE))
    {
        ERROR("Failed to write data to file");
        FF_Close(file);
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    FF_Close(file);
    PRINT("File closed");
    PRINT("Data written to file successfully");

    /***********************************************************************************/
    /*                         read from a file                                        */
    /***********************************************************************************/
    PRINT("Reading data from the file...");
    PRINT("Opening file...");
    file = FF_Open(pdisk->pxIOManager, file_name, FF_MODE_READ, &err);
    if ((file == NULL) || (err != FF_ERR_NONE))
    {
        ERROR("Failed to open file for reading");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }

    PRINT("File opened successfully");
    bytes_read = FF_Read(file, 1, sizeof(pcReadBuffer) - 1, pcReadBuffer);
    if (bytes_read <= 0)
    {
        ERROR("Failed to read data from file");
        FF_Close(file);
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    pcReadBuffer[bytes_read] = '\0';
    FF_Close(file);
    PRINT("File closed");
    PRINT("Data read from file: %s", pcReadBuffer);

    /***********************************************************************************/
    /*                         delete a file                                           */
    /***********************************************************************************/
    PRINT("Deleting a file...");
    err = FF_RmFile(pdisk->pxIOManager, file_name);
    if (err != FF_ERR_NONE)
    {
        ERROR("Failed to delete file");
        FF_Unmount(pdisk);
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("File deleted successfully");

    /***********************************************************************************/
    /*                         unmount the usb drive                                   */
    /***********************************************************************************/
    PRINT("Unmounting the FAT partition...");
    err = FF_Unmount(pdisk);
    if (err != FF_ERR_NONE)
    {
        ERROR("Failed to unmount filesystem");
        FF_SDDiskDelete(pdisk);
        ERROR("Exiting from sample application");
        return;
    }
    PRINT("FAT partition unmounted successfully");

    FF_SDDiskDelete(pdisk);
    PRINT("Disk deleted successfully");
}
