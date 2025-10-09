/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 */

#include <libRSU_OSAL.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


#include "FreeRTOS.h"

RSU_OSAL_MUTEX_DEF xRsuMutexMem;
RSU_OSAL_SEM_DEF xRsuSemMem;

volatile int try_lock_called = 0;
RSU_OSAL_SEM xRsuSem;

RSU_OSAL_VOID *rsu_malloc(RSU_OSAL_SIZE size)
{
    return (RSU_OSAL_VOID *)pvPortMalloc(size);
}

RSU_OSAL_VOID rsu_free(RSU_OSAL_VOID *ptr)
{
    vPortFree(ptr);
}

RSU_OSAL_VOID *rsu_memset(RSU_OSAL_VOID *s, RSU_OSAL_U8 c, RSU_OSAL_SIZE n)
{
    return memset(s, c, n);
}

RSU_OSAL_VOID *rsu_memcpy(RSU_OSAL_VOID *d, RSU_OSAL_VOID *s, RSU_OSAL_SIZE n)
{
    return memcpy(d, s, n);
}

/* Mutex initialization */
RSU_OSAL_INT rsu_mutex_init(RSU_OSAL_MUTEX *mutex)
{
    *mutex = osal_mutex_create(&xRsuMutexMem);
    xRsuSem = osal_semaphore_create(&xRsuSemMem);
    return 0;
}

/* To lock if available else wait based on time */
RSU_OSAL_INT rsu_mutex_timedlock(RSU_OSAL_MUTEX *mutex, RSU_OSAL_U32 const time)
{
    if (mutex == NULL)
    {
        return -EINVAL;

    }
    if (time == RSU_TIME_FOREVER)
    {
        if (osal_mutex_lock(*mutex, RSU_TIME_FOREVER) == pdFALSE)
        {
            return -1;
        }
    }
    else if (time == RSU_TIME_NOWAIT)
    {
        try_lock_called = 1;
        if (osal_semaphore_wait(xRsuSem, 0) == pdFALSE)
        {
            return -1;
        }
    }
    else
    {
        uint64_t wait;
        wait = (time * 1000);
        if (osal_mutex_lock(*mutex, wait) == pdFALSE)
        {
            return -1;
        }
    }
    return 0;
}

/* To release a mutex */
RSU_OSAL_INT rsu_mutex_unlock(RSU_OSAL_MUTEX *mutex)
{
    BaseType_t lRet;
    if (mutex == NULL)
    {
        return -EINVAL;
    }

    if (try_lock_called)
    {
        lRet = osal_semaphore_post(xRsuSem);
        if (lRet == pdFALSE)
        {
            return -1;
        }
    }
    else
    {
        lRet = osal_mutex_unlock(*mutex);
        if (lRet == pdFALSE)
        {
            return -1;
        }
    }
    return 0;
}

/* Using pthread destroy fucntion */
RSU_OSAL_INT rsu_mutex_destroy(RSU_OSAL_MUTEX *mutex)
{
    BaseType_t lRet;
    if (mutex == NULL)
    {
        return -EINVAL;
    }

    lRet = osal_mutex_delete(*mutex);
    if (lRet == pdFALSE)
    {
        return -1;
    }

    lRet = osal_mutex_delete(xRsuSem);
    if (lRet == pdFALSE)
    {
        return -1;
    }

    return 0;
}
