// SPDX-License-Identifier: MIT-0
/*
 * Copyright (C) 2025 Altera
 */

#include <libfcs_osal.h>
#include <libfcs_logging.h>
#include <string.h>

static enum fcs_loglevel fcs_curr_loglevel = LIBRARY_LOG_LEVEL;

FCS_OSAL_INT fcs_set_logging(enum fcs_loglevel level)
{
    if (level > L_LOG_DEBUG) {
        FCS_LOG_ERR("wrong log level provided : %d", level);
        return -1;
    }
    fcs_curr_loglevel = level;
    return 0;
}

FCS_OSAL_INT fcs_logging_init(FCS_OSAL_CHAR *loglevel)
{
    if (loglevel == NULL) {
        FCS_LOG_INF("No log level provided, setting to default as LOG_INFO");
        return fcs_set_logging(LOG_INFO);
    }

    if (strcmp(loglevel, "log_off") == 0)
    {
        return fcs_set_logging(L_LOG_NONE);
    }
    else if (strcmp(loglevel, "log_err") == 0)
    {
        return fcs_set_logging(L_LOG_ERROR);
    }
    else if (strcmp(loglevel, "log_wrn") == 0)
    {
        return fcs_set_logging(L_LOG_WARN);
    }
    else if (strcmp(loglevel, "log_inf") == 0)
    {
        return fcs_set_logging(L_LOG_INFO);
    }
    else if (strcmp(loglevel, "log_dbg") == 0)
    {
        return fcs_set_logging(L_LOG_DEBUG);
    }
    else
    {
        /* do nothing */
    }

    return -1;
}
