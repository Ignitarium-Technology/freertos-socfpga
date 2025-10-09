/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL layer for RSU file operations
 */
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "RSU_OSAL_types.h"
#include "hal/RSU_plat_file.h"
#include <utils/RSU_logging.h>

#include "ff_sddisk.h"
#include "FreeRTOS.h"
#include "ff_sys.h"
#include "ff_stdio.h"
#include "ff_headers.h"

#define MOUNT_POINT         "/sdcard"
#define RSU_MOUNT_DEV_SD    -1
FF_Disk_t *rsu_disk;
FF_FILE *rsu_file;

static RSU_OSAL_FILE *plat_filesys_open(RSU_OSAL_CHAR *filename,
        RSU_filesys_flags_t flag)
{
    FF_Error_t err;

    if (!filename)
    {
        RSU_LOG_ERR("invalid argument");
        return NULL;
    }
    if (flag == RSU_FILE_READ)
    {
        rsu_file = FF_Open(rsu_disk->pxIOManager,
                filename, FF_MODE_READ,
                &err);
    }
    else if (flag == RSU_FILE_WRITE)
    {
        rsu_file = FF_Open(rsu_disk->pxIOManager,
                filename, FF_MODE_CREATE | FF_MODE_WRITE | FF_MODE_TRUNCATE,
                &err);
    }
    else if (flag == RSU_FILE_APPEND)
    {
        rsu_file = FF_Open(rsu_disk->pxIOManager,
                filename, FF_MODE_APPEND | FF_MODE_CREATE | FF_MODE_WRITE,
                &err);
    }
    else
    {
        RSU_LOG_ERR("invalid argument in flag");
        return NULL;
    }

    if (err != FF_ERR_NONE)
    {
        RSU_LOG_ERR("opening the file failed");
        return NULL;
    }

    return rsu_file;
}

static RSU_OSAL_INT plat_filesys_close(RSU_OSAL_FILE *file)
{
    FF_Error_t err;
    if (!file)
    {
        return -EINVAL;
    }

    err = FF_Close(file);
    if (err != FF_ERR_NONE)
    {
        RSU_LOG_ERR("error in closing the file");
        return -EFAULT;
    }
    return 0;
}

static RSU_OSAL_INT plat_filesys_write(RSU_OSAL_VOID *buf, RSU_OSAL_SIZE len,
        RSU_OSAL_FILE *file)
{
    if (!buf || (len <= 0) || !file)
    {
        return -EINVAL;
    }

    int32_t bytesWritten = FF_Write(file, 1, len, buf);
    if (bytesWritten < 0)
    {
        RSU_LOG_ERR("error in writing to file");
        return -EFAULT;
    }
    return bytesWritten;
}

static RSU_OSAL_INT plat_filesys_read(RSU_OSAL_VOID *buf, RSU_OSAL_SIZE len,
        RSU_OSAL_FILE *file)
{

    if (!buf || (len <= 0) || !file)
    {
        return -EINVAL;
    }

    int32_t bytes_read = FF_Read(file, 1, len, buf);
    if (bytes_read < 0)
    {
        RSU_LOG_ERR("error in reading the file ");
        return -EFAULT;
    }
    return bytes_read;
}

static RSU_OSAL_INT plat_filesys_fgets(RSU_OSAL_CHAR *str, RSU_OSAL_SIZE len,
        RSU_OSAL_FILE *file)
{
    if ((str == NULL) || (len == 0) || (file == NULL))
    {
        return -EINVAL;
    }

    int32_t ret;
    ret = FF_GetLine(file, str, (uint32_t)len);

    if ((ret == 0) && (str == NULL))
    {
        return -EFAULT;
    }
    else if (ret != 0)
    {
        return ret;
    }
    else
    {
        return 0;
    }
}

static RSU_OSAL_INT plat_filesys_fseek(RSU_OSAL_OFFSET offset,
        RSU_filesys_whence_t whence,
        RSU_OSAL_FILE *file)
{
    if (!file)
    {
        return -EINVAL;
    }

    FF_Error_t err;

    if (whence == RSU_SEEK_SET)
    {
        err = FF_Seek(file, offset, FF_SEEK_SET);
    }
    else if (whence == RSU_SEEK_CUR)
    {
        err = FF_Seek(file, offset, FF_SEEK_CUR);
    }
    else if (whence == RSU_SEEK_END)
    {
        err = FF_Seek(file, offset, FF_SEEK_END);
    }
    else
    {
        RSU_LOG_ERR("invalid whence %u\n", whence);
        return -EINVAL;
    }

    if (err != FF_ERR_NONE)
    {
        return -EFAULT;
    }
    return 0;
}

static RSU_OSAL_INT plat_filesys_ftruncate(RSU_OSAL_OFFSET length,
        RSU_OSAL_FILE *file)
{
    if (!file)
    {
        return -EINVAL;
    }
    FF_Error_t xError;

    xError = FF_Seek(file, length, FF_SEEK_SET);
    if(xError != FF_ERR_NONE)
    {
	return -EFAULT;
    }
    xError = FF_SetEof(file);
    if(xError != FF_ERR_NONE)
    {
	return -EFAULT;
    }
    return 0;
}

static RSU_OSAL_INT plat_filesys_terminate(RSU_OSAL_VOID)
{
    FF_Error_t err = FF_Unmount(rsu_disk);
    if (err != FF_ERR_NONE)
    {
        RSU_LOG_ERR("Failed to unmount filesystem");
        (void) FF_SDDiskDelete(rsu_disk);
        return -EFAULT;
    }

    FF_SDDiskDelete(rsu_disk);
    return 0;
}

RSU_OSAL_INT plat_filesys_init(struct filesys_ll_intf *filesys_intf)
{
    FF_Error_t err;
    if (!filesys_intf)
    {
        return -EINVAL;
    }

    rsu_disk = FF_SDDiskInit(MOUNT_POINT, RSU_MOUNT_DEV_SD);
    if (rsu_disk == NULL)
    {
        RSU_LOG_ERR("Failed to initialize disk");
        return -EFAULT;
    }

    err = FF_Mount(rsu_disk, 0);
    if (err != FF_ERR_NONE)
    {
        RSU_LOG_ERR("Failed to mount filesystem");
        (void) FF_SDDiskDelete(rsu_disk);
        return -EFAULT;
    }

    filesys_intf->open = plat_filesys_open;
    filesys_intf->read = plat_filesys_read;
    filesys_intf->fgets = plat_filesys_fgets;
    filesys_intf->write = plat_filesys_write;
    filesys_intf->fseek = plat_filesys_fseek;
    filesys_intf->ftruncate = plat_filesys_ftruncate;
    filesys_intf->close = plat_filesys_close;
    filesys_intf->terminate = plat_filesys_terminate;
    return 0;
}

