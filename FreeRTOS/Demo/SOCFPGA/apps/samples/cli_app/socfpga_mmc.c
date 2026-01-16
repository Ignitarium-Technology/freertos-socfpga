/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Helper functions to read files from storage
 */

#include "osal_log.h"
#include "ff_sddisk.h"
#include "socfpga_mmc.h"

uint8_t* mmc_read_file(media_source_t media_src, const char *pcFileName, uint32_t *file_size)
{
    const char *mmc_dev[4] = {"sdmmc", "usb3", "usb2", "invalid"};
    FF_Disk_t *pxDisk;
    FF_FILE *pxFile;
    FF_Error_t xError;

    uint8_t *rbf_ptr;
    size_t xBytesRead;
    int ret_val;
    int mount_drive_num;

    if(media_src == SOURCE_SDMMC)
    {
        mount_drive_num = DRIVE_NUM_SDMMC;
    }
    else if(media_src == SOURCE_USB3)
    {
        mount_drive_num = DRIVE_NUM_USB3;
    }
    else if(media_src == SOURCE_USB2)
    {
        /*need to define the value after USB2.0 is done*/
        ERROR("Invalid media source specified !!!");
        return NULL;
    }
    else
    {
        /*Invalid media source */
        ERROR("Invalid media source specified !!!");
        return NULL;
    }

    pxDisk = FF_SDDiskInit(MOUNT_POINT, mount_drive_num);
    if (pxDisk == NULL)
    {
        PRINT("Failed to initialize disk\n");
        return NULL;
    }

    xError = FF_Mount(pxDisk, 0);
    if (xError != FF_ERR_NONE)
    {
        PRINT("Failed to mount filesystem\n");
        FF_SDDiskDelete(pxDisk);
        return NULL;
    }

    pxFile = FF_Open(pxDisk->pxIOManager, pcFileName, FF_MODE_READ, &xError);
    if ((pxFile == NULL) || (xError != FF_ERR_NONE))
    {
        PRINT("Failed to open file for reading\r\n");
        FF_Unmount(pxDisk);
        FF_SDDiskDelete(pxDisk);
        return NULL;
    }

    ret_val = FF_GetFileSize(pxFile, file_size);
    if( ret_val != 0 )
    {
        ERROR("Error getting file size ");
        return NULL;
    }

    rbf_ptr = (uint8_t *)pvPortMalloc(*file_size);
    if( rbf_ptr == NULL )
    {
        ERROR("Cannot allocate memory ");
        return NULL;
    }

    xBytesRead = FF_Read(pxFile, 1, *file_size, rbf_ptr);
    if ((xBytesRead <= 0) || (xError != FF_ERR_NONE))
    {
        PRINT("Failed to read data from file\n");
        vPortFree(rbf_ptr);
        FF_Close(pxFile);
        FF_Unmount(pxDisk);
        FF_SDDiskDelete(pxDisk);
        return NULL;
    }
    FF_Close(pxFile);

    xError = FF_Unmount(pxDisk);
    if (xError != FF_ERR_NONE)
    {
        PRINT("Failed to unmount filesystem\n");
        vPortFree(rbf_ptr);
        FF_SDDiskDelete(pxDisk);
        return NULL;
    }
    FF_SDDiskDelete(pxDisk);

    PRINT("Read %x bytes from %s drive successfully", *file_size, mmc_dev[media_src]);

    return rbf_ptr;
}
