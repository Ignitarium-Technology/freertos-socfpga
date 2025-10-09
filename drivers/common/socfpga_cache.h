/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for cache management APIs
 */


#ifndef __SOCFPGA_CACHE_H__
#define __SOCFPGA_CACHE_H__
#include <stddef.h>

/**
 * @brief Force write-back of a specified cache region to main memory.
 *
 * This function ensures that any modified data in the specified cache
 * region is written back to main memory. It is useful in situations where
 * data coherence with other components, such as DMA devices, is required.
 *
 * @param[in] addr Starting address of the memory region.
 * @param[in] sz Size of the memory region, in bytes.
 */
void cache_force_write_back(void *addr, size_t sz);

/**
 * @brief Invalidate a specified cache region.
 *
 * This function invalidates a specified region of the cache, ensuring that
 * any subsequent access to this region will retrieve fresh data from main
 * memory. This is useful for preventing the use of stale data, particularly
 * after memory has been modified by an external device.
 *
 * @param[in] addr Starting address of the memory region.
 * @param[in] sz Size of the memory region, in bytes.
 */
void cache_force_invalidate(void *addr, size_t sz);

/**
 * @brief Flush a specified cache region by performing both write-back and invalidate.
 *
 * This function ensures that modified data in the specified region is written
 * back to main memory and then invalidates the cache. It guarantees data coherence
 * by making sure main memory holds the latest data and that future accesses reload
 * data from memory.
 *
 * @param[in] addr Starting address of the memory region.
 * @param[in] sz Size of the memory region, in bytes.
 */
void cache_flush(void *addr, size_t sz);

#endif
