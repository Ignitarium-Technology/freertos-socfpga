/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL layer for RSU CRC functionalities
 */

#include "RSU_OSAL_types.h"
#include "RSU_crc32_def.h"

RSU_OSAL_U32 rsu_crc32(RSU_OSAL_U32 crc, const RSU_OSAL_U8 *data,
        RSU_OSAL_SIZE len)
{
    return calculate_crc32(crc,(void *) data, len);
}
