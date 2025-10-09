/* SPDX-License-Identifier: MIT-0 */
/*
 * Copyright (C) 2025 Altera
 */

/**
 *
 * @file libfcs_logging.h
 * @brief logging API used inside LibFCS
 */

#ifndef LIBFCS_LOGGING_H
#define LIBFCS_LOGGING_H

#include <libfcs_osal.h>
#include "osal_log.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief FCS log levels
 *
 */
enum fcs_loglevel {
	L_LOG_NONE = 0,
	L_LOG_ERROR = 1,
	L_LOG_WARN = 2,
	L_LOG_INFO = 3,
	L_LOG_DEBUG = 4,
};


#undef FCS_LOG_DBG
#define FCS_LOG_DBG(...) DEBUG(__VA_ARGS__)

#undef FCS_LOG_INF
#define FCS_LOG_INF(...) INFO(__VA_ARGS__)

#undef FCS_LOG_WRN
#define FCS_LOG_WRN(...) WARN(__VA_ARGS__)

#undef FCS_LOG_ERR
#define FCS_LOG_ERR(...) ERROR(__VA_ARGS__)

/**
 * @brief set logging level of logger system
 *
 * @param level logging level
 * @return 0 on success, negative number on error.
 */
FCS_OSAL_INT fcs_set_logging(enum fcs_loglevel level);

/**
 * @brief initialize logging
 *
 * @param log_file file to log the messages.
 * @return 0 on success, negative number on error.
 */
FCS_OSAL_INT fcs_logging_init(FCS_OSAL_CHAR *log_file);

/**
 * @brief logging function each platform needs to define
 *
 * @param level logging level
 * @param format string format
 *
 * @return Nil
 */
FCS_OSAL_VOID fcs_logger(enum fcs_loglevel level, const FCS_OSAL_CHAR *format, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIBFCS_LOGGING_H */
