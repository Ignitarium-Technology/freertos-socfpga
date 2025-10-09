/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Helper functions to support CLI commands for FAT file system
 */

#include "ff_sddisk.h"
#include "FreeRTOS.h"
#include "ff_sys.h"
#include <stdio.h>
#include "fatfs_helper.h"

#define MOUNTED        1
#define UNMOUNTED      0

#define APPEND_MODE    0x08
#define WRITE_MODE     0x02
#define CREATE_MODE    0x04
#define READ_MODE      0x01

FF_Disk_t *sdmmcObj = NULL;
FF_Disk_t *usb3Obj = NULL;

uint8_t sdmmc_mount_status = UNMOUNTED;
uint8_t usb3_mount_status = UNMOUNTED;

void ff_mount( const char *MountName, disk_type_t dtype)
{
    if (MountName != NULL)
    {
        if ((dtype == DISK_TYPE_SDMMC) && (sdmmc_mount_status == UNMOUNTED))
        {
            sdmmcObj = FF_SDDiskInit(MountName, -1);
            if (sdmmcObj != NULL)
            {
                printf("\r\n sdmmc mounted successfully at /sd/");
                sdmmc_mount_status = MOUNTED;
            }
            else
            {
                printf("\r Mounting Failed \n");
            }
        }
        else if((dtype == DISK_TYPE_USB3) && (usb3_mount_status == UNMOUNTED))
        {
            usb3Obj = FF_SDDiskInit(MountName, 0);
            if( usb3Obj != NULL )
            {
                printf("\r\n usb3 mounted successfully at /usb3/");
                usb3_mount_status = MOUNTED;
            }
            else
            {
                printf("\r Mounting Failed \n");
            }

        }
        else
        {
            printf("\r Mount already exists \n");
        }
    }
    else
    {
        printf("\r Invalid Mount Name \n");
    }
}

void ff_read( const char *FileName, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_Error_t xError;
    uint8_t buffer[256];
    uint32_t bytesRead = 0;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        FF_FILE *pxFile = FF_Open(DiskObj->pxIOManager, FileName, READ_MODE,
                &xError);
        if (pxFile == NULL)
        {
            printf("\r file not opened \n");
        }
        else
        {
            do
            {
                bytesRead = FF_Read(pxFile, 1, sizeof(buffer), buffer);

                if (bytesRead > 0)
                {
                    for (uint32_t i = 0; i < bytesRead; i++)
                    {
                        putchar(buffer[ i ]);
                    }
                }

            } while (bytesRead == sizeof(buffer));

            FF_Close(pxFile);
        }
    }
}

void ff_ls( const char *path, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_DirEnt_t xDirEntry;
    FF_Error_t xError;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        xError = FF_FindFirst(DiskObj->pxIOManager, &xDirEntry, path);
        if (xError != FF_ERR_NONE)
        {
            printf("\r No files found in directory: %s\n", path);
        }
        else
        {
            do
            {
                if (xDirEntry.ucAttrib & FF_FAT_ATTR_DIR)
                {
                    printf("\r DIR:  %s\n", xDirEntry.pcFileName);
                }
                else
                {
                    printf("\r FILE: %s\n", xDirEntry.pcFileName);
                }
            } while (FF_FindNext(DiskObj->pxIOManager, &xDirEntry)
                    == FF_ERR_NONE);
        }
    }
}

void ff_mk_dir( const char *dirPath, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_Error_t xError;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        xError = FF_MkDir(DiskObj->pxIOManager, dirPath);
        if (xError == FF_ERR_NONE)
        {
            printf("\rDirectory '%s' created successfully.\n", dirPath);
        }
        else
        {
            printf("\rFailed to create directory '%s' \n", dirPath);
        }
    }
}

void ff_un_mount( disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj != NULL)
    {
        FF_Unmount(DiskObj);
        FF_SDDiskDelete(DiskObj);
        printf("\r Unmounting Successful \n");
        if( dtype == DISK_TYPE_SDMMC)
        {
            sdmmcObj = NULL;
            sdmmc_mount_status = UNMOUNTED;
        }
        else
        {
            usb3Obj = NULL;
            usb3_mount_status = UNMOUNTED;
        }
    }
    else
    {
        printf("\r No disk mounted to unmount \n");
    }
}

void ff_rm_dir( const char *dirName, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_Error_t xError;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        xError = FF_RmDir(DiskObj->pxIOManager, dirName);
        if (xError == FF_ERR_NONE)
        {
            printf("\r Directory %s removed successfully\n", dirName);
        }
        else
        {
            printf("\r Could not remove directory %s\n", dirName);
        }
    }
}

void ff_write( const char *FileName, const char *buffer, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_FILE *pxFile;
    size_t bytesWritten;
    FF_Error_t xError;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        if (buffer != NULL)
        {
            pxFile = FF_Open(DiskObj->pxIOManager, FileName,
                    (APPEND_MODE | CREATE_MODE | WRITE_MODE), &xError);
        }
        else
        {
            pxFile = FF_Open(DiskObj->pxIOManager, FileName,
                    (APPEND_MODE | CREATE_MODE | WRITE_MODE), &xError);
            buffer = " ";
        }

        if (pxFile == NULL)
        {
            printf("Failed to open the file\n");
            return;
        }

        bytesWritten = FF_Write(pxFile, 1U, (strlen(buffer) + 1),
                (uint8_t*) buffer);

        if (bytesWritten < (strlen(buffer) + 1))
        {
            printf("Failed to write to the file \n");
        }
        else
        {
            printf("written to file successfully.\n");
        }

        FF_Close(pxFile);
    }
}

void ff_rm( const char *fileName, disk_type_t dtype)
{
    FF_Disk_t *DiskObj = NULL;
    FF_Error_t xError;

    if( dtype == DISK_TYPE_SDMMC )
    {
        DiskObj = sdmmcObj;
    }
    else if(dtype == DISK_TYPE_USB3)
    {
        DiskObj = usb3Obj;
    }
    else
    {
        DiskObj = NULL;
    }

    if (DiskObj == NULL)
    {
        printf("\r No disk mounted \n");
    }
    else
    {
        xError = FF_RmFile(DiskObj->pxIOManager, fileName);
        if (xError == FF_ERR_NONE)
        {
            printf("\r File %s removed \n", fileName);
        }
        else
        {
            printf("\r Error: Could not remove file %s\n", fileName);
        }
    }
}
