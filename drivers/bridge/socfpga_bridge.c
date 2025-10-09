/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for fpga bridges
 */

#include "socfpga_bridge.h"
#include "osal_log.h"
#include "socfpga_sip_handler.h"

#define BRIDGE_ENABLE     (3U)
#define BRIDGE_DISABLE    (2U)

/* Mask for respective bridges */
#define SOC2FPGA_MASK      (1 << 0)
#define LWHPS2FPGA_MASK    (1 << 1)
#define FPGA2SOC_MASK      (1 << 2)
#define F2SDRAM_MASK       (1 << 3)

/* Generic command code for Sip set bridges command */
#define SIP_SMC_HPS_SET_BRIDGES    (0xC2000032)

/* SiP status responses */
#define SIP_SMC_STATUS_ERROR    (0x4)
#define SIP_SMC_STATUS_OK       (0x0)

int32_t enable_hps2fpga_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_ENABLE;
    sdm_args[1] = SOC2FPGA_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("hps2fpga bridge enabled successfully");
        return 0;
    }

    ERROR("Failed to enable hps2fpga bridge, sip status response %d", smc_ret);

    return -EIO;
}

int32_t disable_hps2fpga_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_DISABLE;
    sdm_args[1] = SOC2FPGA_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("hps2fpga bridge disabled successfully");
        return 0;
    }

    ERROR("Failed to disable hps2fpga bridge, sip status response %d", smc_ret);

    return -EIO;
}

int32_t enable_lwhps2fpga_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_ENABLE;
    sdm_args[1] = LWHPS2FPGA_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("lwhps2fpga bridge enabled successfully");
        return 0;
    }

    ERROR("Failed to enable lwhps2fpga bridge, sip status response %d",
            smc_ret);

    return -EIO;
}

int32_t disable_lwhps2fpga_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_DISABLE;
    sdm_args[1] = LWHPS2FPGA_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("lwhps2fpga bridge disabled successfully");
        return 0;
    }

    ERROR("Failed to disable lwhps2fpga bridge, sip status response %d",
            smc_ret);

    return -EIO;
}

int32_t enable_fpga2hps_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_ENABLE;
    sdm_args[1] = FPGA2SOC_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("fpga2hps bridge enabled successfully");
        return 0;
    }

    ERROR("Failed to enable fpga2hps bridge, sip status response %d", smc_ret);

    return -EIO;
}

int32_t disable_fpga2hps_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_DISABLE;
    sdm_args[1] = FPGA2SOC_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("fpga2hps bridge disabled successfully");
        return 0;
    }

    ERROR("Failed to disable fpga2hps bridge, sip status response %d", smc_ret);

    return -EIO;
}

int32_t enable_fpga2sdram_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_ENABLE;
    sdm_args[1] = F2SDRAM_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("fpga2sdram bridge enabled successfully");
        return 0;
    }

    ERROR("Failed to enable fpga2sdram bridge, sip status response %d",
            smc_ret);

    return -EIO;
}

int32_t disable_fpga2sdram_bridge(void)
{
    uint64_t sdm_args[2];
    int smc_ret;

    sdm_args[0] = BRIDGE_DISABLE;
    sdm_args[1] = F2SDRAM_MASK;

    smc_ret = smc_call(SIP_SMC_HPS_SET_BRIDGES, sdm_args);

    if (smc_ret == SIP_SMC_STATUS_OK)
    {
        INFO("fpga2sdram bridge disabled successfully");
        return 0;
    }

    ERROR("Failed to disable fpga2sdram bridge, sip status response %d",
            smc_ret);

    return -EIO;
}
