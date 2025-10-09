/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for helper functions to read from storage
 */

#ifndef __SOCFPGA_MMC_H__
#define __SOCFPGA_MMC_H__

#include <stdint.h>

#define MMC_NO_ERROR ( 1)
#define MMC_ERROR    (-1)

#define DRIVE_NUM_SDMMC ( -1)
#define DRIVE_NUM_USB3  (  0)

#define MOUNT_POINT    "/drive"

/*
 * @enum  : media_source
 * @brief : enum to specify the various storage mediums to load bitstream
 */
typedef enum media_source
{
    SOURCE_SDMMC = 0,
    SOURCE_USB3,
    SOURCE_USB2,
    SOURCE_INVALID,
}media_source_t;

/*
 * @func  : get_bitstream
 * @brief : function to get the bitstream reference and file size
 * @param[in] media_src bitstream file source
 * @param[in] rbf_name name of the bitstream
 * @param[in] file_size reference to length of the bitstream file
 * @param[out] file_size returns the length of the bitstream file
 * @return
 *  reference to bitstream pointer
 */
uint8_t* mmc_read_file(media_source_t media_src, const char *pcFileName, uint32_t *file_size);

#endif
