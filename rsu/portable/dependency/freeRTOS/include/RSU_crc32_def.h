/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 */

/**
 *
 * @file RSU_crc32_def.h
 * @brief contains macros and functions used for CRC calculation
 */
#ifndef RSU_PLAT_CRC32_DEF_H
#define RSU_PLAT_CRC32_DEF_H

#include <stdint.h>
#include <stdio.h>

#define CRC_BATCH_SZ                     3990
#define CRC_BATCH_ZEROES                 0xa10d3d0c
#define CRC_BATCH_MIN_SZ                 800
#define CRC_POLY                         0xedb88320


/**
 * @brief calculate crc32.
 *
 * @param[in] initial CRC value.
 * @param[in] pointer to the data buffer.
 * @param[in] size of the data to calculate CRC
 * @return crc value.
 */
unsigned long calculate_crc32(unsigned long int ulCrc, void *vData,
        unsigned long int ulDataSize);
#endif
