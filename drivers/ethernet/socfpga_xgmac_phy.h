/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * Header file for PHY HAL driver
 */

#ifndef __SOCFPGA_XGMAC_PHY_H__
#define __SOCFPGA_XGMAC_PHY_H__

#include "socfpga_xgmac.h"
#ifdef __cplusplus
extern "C"
{
#endif

/* Modes and speed */
#define ETH_FULL_DUPLEX 1U
#define ETH_HALF_DUPLEX 2U
#define ETH_SPEED_1000_MBPS 1000U
#define ETH_SPEED_100_MBPS 100U
#define ETH_SPEED_10_MBPS 10U
#define ETH_PHY_IF_RGMII 1U
#define ETH_PHY_IF_SGMII 2U
#define ETH_ENABLE_AUTONEG 1U
#define ETH_DISABLE_AUTONEG 0U
#define ETH_ADVERTISE_ALL 1U
#define ETH_ADVERTISE_ALL_TX_FULLDPLX 2U
#define ETH_ADVERTISE_ALL_TX_HALFDPLX 4U

/*
 * @brief  Configuration structure for XGMAC PHY Parameters
 */
typedef struct
{
    uint32_t phy_address;
    uint32_t phy_identifier;
    uint8_t phy_interface;
    bool enable_autonegotiation;
    uint32_t speed_mbps;
    uint8_t duplex;
    uint8_t advertise;
    bool link_status;
    bool async_pause;
    bool pause;
} xgmac_phy_config_t;

/**
 * @brief Detects presence of phy. This function is called during network interface init.
 *
 * @param[in] hxgmac The handle of initialized xgmac.
 * @param[out] pphy_config The configuration structure which gets populated once the phy is
 *             discovered.
 *
 * @return
 * - SOCFPGA_HAL_XGMAC_SUCCESS, when phy is detected
 * - SOCFPGA_HAL_XGMAC_ERROR, when phy is not detected
 */
int32_t xgmac_phy_discover(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config);

/**
 * @brief Initialize the phy . This function is called after the phy discovery.
 *
 * @param[in] hxgmac The handle of initialized xgmac.
 * @param[in] pphy_config The configuration structure which will be used to configure the phy
 *            and check phy link status.
 *
 * @return
 * - SOCFPGA_HAL_XGMAC_SUCCESS, when phy is initialized
 * - SOCFPGA_HAL_XGMAC_ERROR, when phy is not configured or the link is down.
 */
int32_t xgmac_phy_initialize(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config);

/**
 * @brief Configure the speed and duplex on xgmac side. This function takes values from phy
 * registers and update the xgmac configuration according to it.
 *
 * @param[in] hxgmac The handle of initialized xgmac.
 * @param[out] pphy_config The configuration structure which will be populated according to the configured values.
 *
 * @return
 * - SOCFPGA_HAL_XGMAC_SUCCESS, when xgmac is configured succesfully
 * - SOCFPGA_HAL_XGMAC_FAILURE, when xgmac is not configured due to usupported speed or mode.
 */
int32_t xgmac_cfg_speed_mode(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config);

/**
 * @brief Reconfigures the phy as well as xgmac . This function updates the configuration of phy followed by
 *        checking the link status after phy reconfiguration and update the configuration on xgmac side.
 *
 * @param[in] hxgmac The handle of initialized xgmac.
 * @param[in] pphy_config The configuration structure which will be used to reconfigure the phy as well as
 *            speed and mode on xgmac side.
 *
 * @return
 * - SOCFPGA_HAL_XGMAC_SUCCESS, when phy is initialized
 * - SOCFPGA_HAL_XGMAC_ERROR, when phy or xgmac is failed to reconfigure or the link is down after phy reconfig.
 */
int32_t xgmac_update_xgmac_speed_mode(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config);

/**
 * @brief Return the current link status of the phy.
 *
 * @param[in] base_address The base address of the XGMAC registers.
 * @param[in] pphy_config The handle containing PHY configuration.
 *
 * @return
 * - true, when phy link is up
 * - false, when phy link is down
 */
BaseType_t phy_get_link_status(uint32_t base_address, xgmac_phy_config_t *pphy_config);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __SOCFPGA_XGMAC_PHY_H__ */
