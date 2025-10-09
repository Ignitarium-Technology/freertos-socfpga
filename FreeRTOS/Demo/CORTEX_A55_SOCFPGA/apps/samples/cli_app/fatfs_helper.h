/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for helper functions for FAT commands
 */

#ifndef __FATFS_HELPER_H__
#define __FATFS_HELPER_H__

typedef enum
{
    DISK_TYPE_SDMMC = 0,
    DISK_TYPE_USB3,
    DISK_TYPE_INVALID,
}disk_type_t;

void FatFsInit( char *FileName );
void ff_mount( const char *MountName, disk_type_t dtype);
void ff_read( const char *FileName, disk_type_t dtype);
void ff_ls( const char *path, disk_type_t dtype);
void ff_mk_dir( const char *dirPath, disk_type_t dtype);
void ff_un_mount( disk_type_t dtype );
void ff_rm_dir( const char *dirPath, disk_type_t dtype);
void ff_write( const char *FileName, const char *buffer, disk_type_t dtype);
void ff_rm( const char *fileName, disk_type_t dtype);

#endif

