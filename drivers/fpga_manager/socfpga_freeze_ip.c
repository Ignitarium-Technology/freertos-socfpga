/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * HAL Implementation for freeze IP
 */

/*
 * This is the driver implementation for freeze ip. It is used to freeze/unfreeze  a
 * particular PR region during partial reconfiguration.
 *
 * Below diagram shows the partial reconfiguration process using freeze IP.
 *
 *       +------------------------+
 *       |  freeze the PR region  |
 *       +------------------------+
 *                  |
 *    ------------->| Yes
 *    |             v
 *    |   +------------------------+
 *    |   |  freeze complete?      |
 *    |   +------------------------+
 *    |    No       |
 *    --------------| Yes
 *                  v
 *       +------------------------+
 *       |     assert PR reset    |
 *       +------------------------+
 *                  |
 *                  v
 *       +------------------------+
 *       |  perform PR via SDM    |
 *       +------------------------+
 *                  |
 *                  v
 *      +----------------------------+
 *      |  Request unfreezing of the |
 *      |        PR region           |
 *      +----------------------------+
 *                  |
 *    ------------->| Yes
 *    |             v
 *    |   +------------------------+
 *    |   |   unfreeze complete?   |
 *    |   +------------------------+
 *    |   No        |
 *    --------------| Yes
 *                  v
 *     +----------------------------+
 *     | Partial Reconfiguration    |
 *     |         completed          |
 *     +----------------------------+
 *
 */

#include "socfpga_defines.h"
#include "socfpga_freeze_ip.h"
#include "socfpga_freeze_ip_ll.h"
#include "osal_log.h"

int do_freeze_pr_region(void)
{
    int ret;

    ret = freeze_pr_region();

    if (ret != 0)
    {
        ERROR("freeze bridge error %d", ret);
        return ret;
    }

    INFO("Freeze operation sucessful");
    return 0;
}

int do_unfreeze_pr_region(void)
{
    int ret;

    ret = unfreeze_pr_region();

    if (ret != 0)
    {
        ERROR("freeze bridge error %d", ret);
        return ret;
    }

    INFO("Unfreeze operation sucessful");
    return 0;
}
