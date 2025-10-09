/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for FAT file system
 */

/**
 * @defgroup cli_fat FAT
 * @ingroup cli
 *
 * Perform file operations on USB and SD/MMC devices
 *
 * @details
 * It supports the following subcommands:
 * - fat mount &lt;partition&gt;
 * - fat unmount &lt;partition&gt;
 * - fat ls &lt;dir_name&gt;
 * - fat rm &lt;file_name&gt;
 * - fat cat &lt;file_name&gt;
 * - fat write &lt;file_name&gt; &lt;string&gt;
 * - fat mkdir &lt;dir_name&gt;
 * - fat rmdir &lt;dir_name&gt;
 * - fat help
 *
 * Typical usage:
 * - Use 'fat mount' to mount the FAT partition.
 * - Use 'fat ls' to list files and directories.
 * - Use 'fat cat' to display file contents.
 * - Use 'fat write' to write data to a file.
 * - Use 'fat mkdir' to create a directory.
 * - Use 'fat rmdir' to delete a directory.
 * - Use 'fat rm' to delete a file.
 * - Use 'fat unmount' to unmount the partition.
 *
 * @section fat_commands Commands
 * @subsection fat_mount fat mount
 * Mount FAT partition  <br>
 *
 * Usage:  <br>
 *   fat mount &lt;partition&gt;  <br>
 *
 * It requires the following arguments:
 * - partition -     The name of the partition to be mounted. Partition name should follow a forward slash (e.g., `/sd/` for SD/MMC or `/usb3/` for USB3 drive).  <br>
 *
 * @subsection fat_unmount fat unmount
 * Unmount FAT partition  <br>
 *
 * Usage:  <br>
 *   fat unmount &lt;partition&gt;  <br>
 *
 * It requires the following arguments:
 * - partition -     The name of the partition to be unmounted. Partition name should follow a forward slash (e.g., `/sd/` for SD/MMC or `/usb3/` for USB3 drive).  <br>
 *
 * @subsection fat_ls fat ls
 * List files and sub-directories  <br>
 *
 * Usage:  <br>
 *   fat ls &lt;dir_name&gt;  <br>
 *
 * It requires the following arguments:
 * - dir_name -     The directory name. Maximum length (excluding mount point) is 8 characters.  <br>
 *
 * @subsection fat_cat fat cat
 * Display the contents of a file  <br>
 *
 * Usage:  <br>
 *   fat cat &lt;file_name&gt;  <br>
 *
 * It requires the following arguments:
 * - file_name -     The full path to the file (including mount point). Maximum length (excluding mount point) is 8 characters.  <br>
 *
 * @subsection fat_write fat write
 * Write data to a file  <br>
 *
 * Usage:  <br>
 *   fat write &lt;file_name&gt; &lt;data&gt;  <br>
 *
 * It requires the following arguments:
 * - file_name -     The full path to the file (including mount point). Maximum length (excluding mount point) is 8 characters.  <br>
 * - data -          The string to write. Can contain spaces and special characters. If the file does not exist, it will be created; otherwise data is appended.  <br>
 *
 * @subsection fat_mkdir fat mkdir
 * Create directory  <br>
 *
 * Usage:  <br>
 *   fat mkdir &lt;dir_name&gt;  <br>
 *
 * It requires the following arguments:
 * - dir_name -     The full path to the new directory (including mount point). Maximum length (excluding mount point) is 8 characters.  <br>
 *
 * @subsection fat_rmdir fat rmdir
 * Delete directory  <br>
 *
 * Usage:  <br>
 *   fat rmdir &lt;dir_name&gt;  <br>
 *
 * It requires the following arguments:
 * - dir_name -     The full path to the directory (including mount point). Maximum length (excluding mount point) is 8 characters.  <br>
 *
 * @subsection fat_rm fat rm
 * Delete file in partition  <br>
 *
 * Usage:  <br>
 *   fat rm &lt;file_name&gt;  <br>
 *
 * It requires the following arguments:
 * - file_name -     The full path to the file (including mount point). Maximum length (excluding mount point) is 8 characters.  <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <socfpga_uart.h>
#include "FreeRTOS_CLI.h"
#include "fatfs_helper.h"
#include "cli_app.h"
#include "cli_utils.h"
#include "semphr.h"

const char sdmmc_mount[] = "/sd/";
const char usb_mount[] = "/usb3/";

static disk_type_t get_disk_type(const char *mptr)
{
    if (strncmp(mptr, sdmmc_mount, 4) == 0)
    {
        return DISK_TYPE_SDMMC;
    }
    else if (strncmp(mptr, usb_mount, 6) == 0)
    {
        return DISK_TYPE_USB3;
    }
    else
    {
        return DISK_TYPE_INVALID;
    }

    return DISK_TYPE_INVALID;
}

BaseType_t fat_ops( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    (void)write_buffer;
    (void)write_buffer_len;
    int ret;

    const char *parameter1, *parameter2, *parameter3;
    BaseType_t param1_str_len,param2_str_len, param3_str_len;

    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1, &param1_str_len);

    if (strncmp(parameter1, "help", 4) == 0)
    {
        printf("\r\nPerform file operations on USB and SD/MMC devices"
                "\r\n\nIt supports the following subcommands:"
                "\r\n  fat mount <partition>"
                "\r\n  fat unmount <partition>"
                "\r\n  fat ls <dir_name>"
                "\r\n  fat rm <file_name>"
                "\r\n  fat cat <file_name>"
                "\r\n  fat write <file_name> <string>"
                "\r\n  fat mkdir <dir_name>"
                "\r\n  fat rmdir <dir_name>"
                "\r\n  fat help"
                "\r\n\nTypical usage:"
                "\r\n- Use mount command to mount the fat partition"
                "\r\n- Use other fat commands to perform fat operations."
                "\r\n- Use unmount command to unmoun the partition."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  fat <command> help\r\n"
                "\r\n\nNote : USB/SD MMC devices must contain a valid fat partition.\r\n"
                );

        return pdFALSE;
    }

    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2, &param2_str_len); /* Second argument of fat command */

    /* Fat mount operation */
    if (strncmp(parameter1, "mount", 5) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nMount fat partition"
                    "\r\n\nUsage:"
                    "\r\n  fat mount </partition>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  partition     The name of the partition to be mounted. Partition name should follow a forward slash. Eg. (fat mount /sd/)"
                    "\r\n                Use /sd/ for sdmmc & /usb3/ for usb3 drive."
                    "\r\n                Note: Only the first fat partition will be considered."
                    );

            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            ff_mount(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            ff_mount(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "unmount", 7) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nUnmount fat partition"
                    "\r\n\nUsage:"
                    "\r\n  fat unmount </partition>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  partition     The name of the partition to be mounted. Partition name should follow a forward slash. Eg. (fat unmount /sd/)"
                    "\r\n                Use /sd/ for sdmmc & /usb3/ for usb3 drive "
                    );

            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            ff_un_mount(DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            ff_un_mount(DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "ls", 2) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nList the files and sub-drectories in the folder/sub-directories"
                    "\r\n\nUsage:"
                    "\r\n  fat ls <dir_name>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  dir_name     The directory name. The maximum string length of the directory (excluding mount point) should be 8."
                    );
            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret = cli_get_dir_name(parameter2, "fat ls");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_ls(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_dir_name(parameter2, "fat ls");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_ls(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "cat", 3) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nDisplays the contents of a file"
                    "\r\n\nUsage:"
                    "\r\n  fat cat <file_name>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  file_name     The name of the file to be displayed. The file name should contain the complete path including mount point."
                    "\r\n                The maximum string length of the file (excluding mount point) should be 8."
                    );

            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret =  cli_get_file_name(parameter2, "fat cat");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_read(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_file_name(parameter2, "fat cat");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_read(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "write", 5) == 0)
    {
        char *space_pos;
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nWrite data to a file"
                    "\r\n\nUsage:"
                    "\r\n  fat write <file_name> <data>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  file_name   The name of the file to be displayed. The file name should contain the complete path including mount point. Eg. /sd/a.txt"
                    "\r\n              The maximum string length of the file ( excluding mount point) should be 8."
                    "\r\n  data        The string to be wriiten to the file. The string starts after the space following the file name and can contain spaces and other special characters."
                    "\r\n              If the file is not present, it create a new file and writes data to it. If the file is already present, it appends data to the existing file."
                    );

            return pdFALSE;
        }

        parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                &param3_str_len);                                                     /* write string for write command */

        space_pos = strchr(parameter2, ' ');
        if (space_pos != NULL)
        {
            *space_pos = '\0';
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret = cli_get_file_name(parameter2, "fat write");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_write(parameter2, parameter3, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_file_name(parameter2, "fat write");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_write(parameter2, parameter3, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "mkdir", 5) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nCreate directory"
                    "\r\n\nUsage:"
                    "\r\n  fat mkdir <dir_name>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  dir_name    The name of the directory. The file name should contain the complete path including mount point. The directory name should not end with a '/'"
                    "\r\n              The maximum string length of the file ( excluding mount point) should be 8."
                    );
            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret = cli_get_dir_name(parameter2, "fat mkdir");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_mk_dir(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_dir_name(parameter2, "fat mkdir");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_mk_dir(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "rmdir", 5) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nDelete directory"
                    "\r\n\nUsage:"
                    "\r\n  fat rmdir <dir_name>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  dir_name    The name of the directory. The file name should contain the complete path including mount point."
                    "\r\n              The maximum string length of the file ( excluding mount point) should be 8."
                    );
            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret = cli_get_dir_name(parameter2, "fat rmdir");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_rm_dir(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_dir_name(parameter2, "fat rmdir");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_rm_dir(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else if (strncmp(parameter1, "rm", 2) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nDelete the file in the partition"
                    "\r\n\nUsage:"
                    "\r\n  fat rm <file_name>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  file_name    The name of the file to be deleted. The file name should contain the complete path including mount point."
                    "\r\n               The maximum string length of the file ( excluding mount point) should be 8."
                    );

            return pdFALSE;
        }

        if (get_disk_type(parameter2) == DISK_TYPE_SDMMC)
        {
            parameter2 += 3;
            ret = cli_get_file_name(parameter2, "fat rm");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_rm(parameter2, DISK_TYPE_SDMMC);
        }
        else if (get_disk_type(parameter2) == DISK_TYPE_USB3)
        {
            parameter2 += 5;
            ret = cli_get_file_name(parameter2, "fat rm");
            if (ret != 0)
            {
                return pdFAIL;
            }
            ff_rm(parameter2, DISK_TYPE_USB3);
        }
        else
        {
            printf("Invalid mount point specified");
        }
    }
    else
    {
        printf("\r\n Incorrect Command \r\n");
    }

    return pdFALSE;
}
