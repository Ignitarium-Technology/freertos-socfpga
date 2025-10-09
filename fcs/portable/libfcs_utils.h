#ifndef LIBFCS_UTILS_H
#define LIBFCS_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "libfcs_osal.h"

/**
 * @brief Gets the file size
 *
 * @param[in] file  Name of the file. It shall contain the source device
 *                  also.(eg: /usb/file)
 */
uint32_t fat_get_size( const char *file );
/**
 * @brief Reads contents of the file
 *
 * @param[in]       file    Name of the file. It shall contain the source device
 *                          also.(eg: /usb/file)
 * @param[in, out]  buffer  Buffer to store contents
 */

uint32_t fat_read( const char *FileName, void *buffer );

#ifdef __cplusplus
}
#endif /* __cplusplus */

// #endif
#endif
