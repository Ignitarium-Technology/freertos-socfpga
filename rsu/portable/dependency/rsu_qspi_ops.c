/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * QSPI HAL layer for RSU
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "hal/RSU_plat_qspi.h"
#include <utils/RSU_logging.h>
#include "RSU_OSAL_types.h"
#include "socfpga_flash.h"
#include "socfpga_cache.h"

flash_handle_t rsu_rtos_qspi_handle = NULL;

static RSU_OSAL_INT plat_qspi_read(RSU_OSAL_OFFSET offset, RSU_OSAL_VOID *data,
        RSU_OSAL_SIZE len)
{
    RSU_OSAL_INT status;

    if (rsu_rtos_qspi_handle == NULL)
    {
        RSU_LOG_ERR("QSPI not intialized!!");
        return -EINVAL;
    }

    cache_force_write_back((void *)data, len);

    status = flash_read_sync(rsu_rtos_qspi_handle, offset, (uint8_t *)data, len);

    cache_force_invalidate(data, len);

    if (status != 0)
    {
        RSU_LOG_ERR("Failed to read data from QSPI");
        return status;
    }
    return 0;
}

static RSU_OSAL_INT plat_qspi_write(RSU_OSAL_OFFSET offset,
        const RSU_OSAL_VOID *data,
        RSU_OSAL_SIZE len)
{
    RSU_OSAL_INT status;

    if (rsu_rtos_qspi_handle == NULL)
    {
        RSU_LOG_ERR("QSPI not intialized!!");
        return -EINVAL;
    }

    cache_force_write_back((void *)data, len);

    status = flash_write_sync(rsu_rtos_qspi_handle, offset, (uint8_t *)data, len);

    if (status != 0)
    {
        RSU_LOG_ERR("Failed to write data to  QSPI");
        return status;
    }
    return 0;
}

static RSU_OSAL_INT plat_qspi_erase(RSU_OSAL_OFFSET offset, RSU_OSAL_SIZE len)
{
    RSU_OSAL_INT status;

    if (rsu_rtos_qspi_handle == NULL)
    {
        RSU_LOG_ERR("QSPI not initialized");
        return -EINVAL;
    }

    status = flash_erase_sectors(rsu_rtos_qspi_handle, offset, len);

    if (status < 0)
    {
        RSU_LOG_ERR("Failed to erase the sectors");
        return status;
    }
    return 0;
}

static RSU_OSAL_INT plat_qspi_terminate(RSU_OSAL_VOID)
{
    if (flash_close(rsu_rtos_qspi_handle) != 0)
    {
        RSU_LOG_ERR("Failed to close QSPI flash handle");
        return -EFAULT;
    }
    return 0;
}

RSU_OSAL_INT plat_qspi_init(struct qspi_ll_intf *qspi_intf,
        RSU_OSAL_CHAR *config_file)
{
    (void) config_file;

    rsu_rtos_qspi_handle = flash_open(QSPI_DEV0);
    if(rsu_rtos_qspi_handle == NULL)
    {
	return -EFAULT;
    }

    qspi_intf->read = plat_qspi_read;
    qspi_intf->write = plat_qspi_write;
    qspi_intf->erase = plat_qspi_erase;
    qspi_intf->terminate = plat_qspi_terminate;

    return 0;

}
