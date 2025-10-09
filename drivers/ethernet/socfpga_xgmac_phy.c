/*
 * FreeRTOS+TCP V3.1.0
 * Copyright (C) 2022 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * HAL driver implementation for PHY. Modified for SoC FPGA
 */


#include "socfpga_xgmac_phy.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Driver includes */
#include "socfpga_xgmac.h"
#include "socfpga_xgmac_reg.h"
#include "socfpga_xgmac_phy_ll.h"
#include "socfpga_xgmac_ll.h"
#include <osal_log.h>

#define PHY_RECONFIG_TIMEOUT    5000

static Basetype_t phy_set_parameters(uint32_t base_address, xgmac_phy_config_t *pphy_config);
static Basetype_t phy_link_status(uint32_t base_address, xgmac_phy_config_t *pphy_config);
static Basetype_t phy_set_adv_cap(uint32_t base_address, xgmac_phy_config_t *pphy_config);
static Basetype_t phy_reset(uint32_t base_address, xgmac_phy_config_t *pphy_config);

/* Function to check the validity of the PHY ID */
static bool is_phy_id_valid(uint32_t ulreg_val)
{
    if ((ulreg_val != (uint16_t) ~0U) && (ulreg_val != (uint16_t)0U))
    {
        return true;
    }
    return false;
}

/* PHY Detect function */
int32_t xgmac_phy_discover(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config)
{
    uint16_t aul_phy_reg[2] =
    {
        0
    };
    uint32_t phy_address = PHY_MIN_ADDRESS;

    xgmac_base_addr_t xgmac_base_addr = xgmac_get_inst_base_addr(hxgmac);

    /* Iterate over possible PHY addresses */
    while (phy_address <= PHY_MAX_ADDRESS)
    {
        /* Read both PHY identifier registers */
        aul_phy_reg[0] = read_phy_reg(xgmac_base_addr, phy_address, PHYID1_REG);
        if (is_phy_id_valid(aul_phy_reg[0]))
        {
            aul_phy_reg[1] = read_phy_reg(xgmac_base_addr, phy_address, PHYID2_REG);

            /* Update structure members */
            pphy_config->phy_identifier = ((uint32_t)aul_phy_reg[1] << 16) |
                    aul_phy_reg[0];
            pphy_config->phy_address = phy_address;

            INFO("PHY at address %d with PHY Identifier2: 0x%04X and PHY identifier3 : 0x%04X.",
                    pphy_config->phy_address, aul_phy_reg[0], aul_phy_reg[1]);

            INFO("Detected PHY at address %d with ID 0x%08X.", pphy_config->phy_address,
                    pphy_config->phy_identifier);

            return 0;
        }
        phy_address++;
    }
    ERROR("No PHY detected.");
    return -EIO;
}

int32_t xgmac_phy_initialize(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config)
{
    Basetype_t ret_val;

    /* Retrieve the base address of the XGMAC instance */
    xgmac_base_addr_t xgmac_base_addr = xgmac_get_inst_base_addr(hxgmac);

    /* Configure PHY parameters */
    ret_val = phy_set_parameters(xgmac_base_addr, pphy_config);
    if (ret_val != true)
    {
        ERROR("XGMAC PHY: Set PHY parameter failed.");
        return -EINVAL;
    }

    /* Check PHY link status */
    ret_val = phy_link_status(xgmac_base_addr, pphy_config);
    if (ret_val == true)
    {
        INFO("PHY link is up.");
    }
    else
    {
        INFO("PHY link is down.");
        return -EIO;
    }
    return 0;
}


int32_t xgmac_cfg_speed_mode(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config)
{
    uint32_t val;
    xgmac_base_addr_t xgmac_base_addr = xgmac_get_inst_base_addr(hxgmac);
    if (xgmac_base_addr == 0U)
    {
        return -EINVAL;
    }


    /* Read 1G status register */
    val = (uint32_t)read_phy_reg(xgmac_base_addr, pphy_config->phy_address, STATUS_1GBASE_T_REG);
    if ((val & STATUS_1GBASE_TX_ALLDPLX_MASK) != 0U)
    {
        pphy_config->speed_mbps = ETH_SPEED_1000_MBPS;

        if ((val & STATUS_1GBASE_TX_HALFDPLX_MASK) != 0U)
        {
            pphy_config->duplex = PHY_HALF_DUPLEX;
        }
        else
        {
            pphy_config->duplex = PHY_FULL_DUPLEX;
        }
    }
    else
    {
        /* Read copper status register for speed 100/10 */
        val = (uint32_t)read_phy_reg(xgmac_base_addr, pphy_config->phy_address, COPPER_STATUS_REG);
        if ((val & COPPER_STATUS_100BASE_TX_ALLDPLX_MASK) != 0U)
        {
            pphy_config->speed_mbps = ETH_SPEED_100_MBPS;
            if ((val & ((uint32_t)1 << FULL_DUPLEX_100M)) == ((uint32_t)1 << FULL_DUPLEX_100M))
            {
                pphy_config->duplex = PHY_FULL_DUPLEX;
            }
            else if ((val & ((uint32_t)1 << HALF_DUPLEX_100M)) ==
                    ((uint32_t)1 << HALF_DUPLEX_100M))
            {
                pphy_config->duplex = PHY_HALF_DUPLEX;
            }
            else
            {
                ERROR("Unsupported Mode.");
                return -EIO;
            }
        }
        else if ((val & COPPER_STATUS_10BASE_TX_ALLDPLX_MASK) != 0U)
        {
            pphy_config->speed_mbps = ETH_SPEED_10_MBPS;
            if ((val & COPPER_STATUS_10BASE_TX_HALFDPLC_MASK) != 0U)
            {
                pphy_config->duplex = PHY_HALF_DUPLEX;
            }
            else
            {
                pphy_config->duplex = PHY_FULL_DUPLEX;
            }
        }
        else
        {
            /*do nothing*/
        }
    }

    if ((pphy_config->speed_mbps != ETH_SPEED_10_MBPS) &&
            (pphy_config->speed_mbps != ETH_SPEED_100_MBPS) &&
            (pphy_config->speed_mbps != ETH_SPEED_1000_MBPS))
    {
        ERROR("Unsupported speed %u Mbps.", pphy_config->speed_mbps);

        return -EIO;
    }

    /* Configure speed on XGMAC side */
    xgmac_setspeed(xgmac_base_addr, pphy_config->speed_mbps);

    if ((pphy_config->duplex != PHY_FULL_DUPLEX) && (pphy_config->duplex !=
            PHY_HALF_DUPLEX))
    {
        ERROR("Invalid mode specified.");

        return -EINVAL;
    }

    /* Configure mode on XGMAC side */
    xgmac_setduplex(xgmac_base_addr, pphy_config->duplex);

    /* Successful configuration */
    INFO("Successfully configured XGMAC: Speed = %u Mbps, Mode = %s.", pphy_config->speed_mbps,
            (pphy_config->duplex == PHY_FULL_DUPLEX)? "Full Duplex": "Half Duplex.");

    return 0;
}
int32_t xgmac_update_xgmac_speed_mode(xgmac_handle_t hxgmac, xgmac_phy_config_t *pphy_config)
{
    xgmac_base_addr_t xgmac_base_addr = xgmac_get_inst_base_addr(hxgmac);

    /* Set PHY parameters */
    if (phy_set_parameters(xgmac_base_addr, pphy_config) != true)
    {
        ERROR("Failed to do PHY Re-Configuration");
        return -EIO;
    }
    /* Check PHY link status after PHY Reset */
    if (phy_link_status(xgmac_base_addr, pphy_config) != true)
    {
        ERROR("PHY link is down.");
        return -EIO;
    }
    /* Configure updated parameters on XGMAC side */
    if (xgmac_cfg_speed_mode(hxgmac, pphy_config) != 0)
    {
        ERROR("Failed to Re-Configure XGMAC Speed and Mode.");
        return -EIO;
    }
    return 0;
}

static Basetype_t phy_set_parameters(uint32_t base_address, xgmac_phy_config_t *pphy_config)
{
    uint32_t data;
    Basetype_t ret_val;
    volatile uint8_t max_count = 0U;
    uint16_t cont_reg2;
    int task_timeout = 0;
    bool status = true;

    /* Check the selected PHY interface */
    if ((pphy_config->phy_interface & PHY_IF_SELECT_RGMII) != 0U)
    {
        /* Select page from page address register */
        data = (uint32_t)write_phy_reg(base_address, pphy_config->phy_address,
                PAGE_ADDRESS_SELECT_REG, SELECT_PAGE_EIGHTEEN);

        /*Set Interface mode in General control register and changes
         * to this mode bit should be needed to reset the General PHY
         */
        data =
                (uint32_t)read_phy_reg(base_address, pphy_config->phy_address,
                GENERAL_CONTROL_REG_1);
        data &= ~GENERAL_CONTROL_RGMII_COPPER_SELECT_MASK;
        if (write_phy_reg(base_address, pphy_config->phy_address, GENERAL_CONTROL_REG_1,
                (uint16_t)data) != 0)
        {
            return false;
        }

        data &= ~GENERAL_CONTROL_RESET_MASK;
        if (write_phy_reg(base_address, pphy_config->phy_address, GENERAL_CONTROL_REG_1,
                (uint16_t)data) != 0)
        {
            return false;
        }

        if (write_phy_reg(base_address, pphy_config->phy_address, PAGE_ADDRESS_SELECT_REG,
                SELECT_PAGE_TWO) != 0)
        {
            return false;
        }

        cont_reg2 =
                read_phy_reg(base_address, pphy_config->phy_address, MAC_SPECIFIC_CONTROL_REG_2);
        cont_reg2 &= ~((uint16_t)(3U << 4));
        if (write_phy_reg(base_address, pphy_config->phy_address, MAC_SPECIFIC_CONTROL_REG_2,
                cont_reg2) != 0)
        {
            return false;
        }

        /* Poll the reset bit to complete. */
        while (((data & GENERAL_CONTROL_RESET_MASK) != 0U) && (max_count <
                MAX_GEN_TIMER_COUNT))
        {
            data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address,
                    GENERAL_CONTROL_REG_1);
            max_count++;
        }
        if (max_count == MAX_GEN_TIMER_COUNT)
        {
            ERROR("General PHY reset address timed out:%0d.", max_count);
            return -EIO;
        }
    }
    else
    {
        ERROR("Unsupported interface type selected.");
        return -EINVAL;
    }

    /* Select the speed -> If auto-negotiation not enable set the speed
     * manually in copper control register
     * bits [6][13] -> 00 -> 10MBPS
     *		[6][13] -> 01 -> 100MBPS
     *		[6][13] -> 10 -> 1000MBPS
     *		[6][13] -> 11 -> Reserved
     */
    if (write_phy_reg(base_address, pphy_config->phy_address, PAGE_ADDRESS_SELECT_REG,
            SELECT_PAGE_ZERO) != 0)
    {
        return false;
    }

    /* Auto-negotiation disabled */
    if (pphy_config->enable_autonegotiation != ENABLE_AUTONEG)
    {
        /* Make sure auto-negotiation disabled for setting speed and mode manually
         */
        data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG);

        data &= ~COPPER_CONTROL_AUTONEG_ENABLE_MASK;

        if (write_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG,
                (uint16_t)data) != 0)
        {
            return false;
        }

        data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG);
        switch (pphy_config->speed_mbps)
        {
            /* Select 10Mbps */
            case ETH_SPEED_1000_MBPS:
                data |= COPPER_SPEED_SELECT_1000MBPS_MASK;
                break;
            /* Select 100Mbps */
            case ETH_SPEED_100_MBPS:
                data |= COPPER_SPEED_SELECT_100MBPS_MASK;
                break;
            /* Select 10Mbps */
            case ETH_SPEED_10_MBPS:
                data |= COPPER_SPEED_SELECT_10MBPS_MASK;
                break;
            default:
                WARN("Unsupported speed configuration selected.");
                status = false;
                break;
        }
        if (status == false)
        {
            return -EIO;
        }

        if (pphy_config->duplex == PHY_HALF_DUPLEX)
        {
            data |= COPPER_CONTROL_FULLDPLX_MASK;
        }
        else
        {
            data &= ~COPPER_CONTROL_FULLDPLX_MASK;
        }

        /* Write Mode and Speed to Copper Control Register */
        if (write_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG,
                (uint16_t)data) != 0)
        {
            return false;
        }

        /* Resetting the PHY to effect the changes made for speed and mode */
        ret_val = phy_reset(base_address, pphy_config);
        if (ret_val != true)
        {
            ERROR("Failed to reset the PHY to set speed and mode.");
            return false;
        }
    }
    /* Auto-negotiation is enabled, configure advertised features */
    else
    {
        if (phy_set_adv_cap(base_address, pphy_config) != true)
        {
            ERROR("Speed Advertisement failed.");
            return false;
        }
        data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG);

        data |= (COPPER_CONTROL_AUTONEG_ENABLE_MASK |
                COPPER_CONTROL_AUTONEG_RESET_MASK);
        data &= ~COPPER_CONTROL_ISOLATE_MASK;

        if (write_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG,
                (uint16_t)data) != 0)
        {
            return false;
        }

        /* Resetting the PHY to effect the changes made for speed and mode */
        ret_val = phy_reset(base_address, pphy_config);
        if (ret_val != true)
        {
            ERROR("Failed to reset the PHY to reset the auto-negotiation in CCR.");
        }

        do
        {
            data =
                    (uint32_t)read_phy_reg(base_address, pphy_config->phy_address,
                    COPPER_STATUS_REG);
            if (task_timeout >= PHY_RECONFIG_TIMEOUT)
            {
                return false;
            }
            task_timeout++;
        } while((data & COPPER_STATUS_AUTONEG_COMPLETE_MASK) == 0U);

        INFO("Auto negotiation process completed.");
    }
    return true;
}
static Basetype_t phy_set_adv_cap(uint32_t base_address, xgmac_phy_config_t *pphy_config)
{
    uint32_t adv;

    /* Advertise all speed and mode */
    if (pphy_config->advertise == ADVERTISE_ALL)
    {
        /*Enable 100/10 Full/Half duplex Advertisement*/
        adv = AUTONEG_ADV_100_10_TX_ALLDPLX_MASK;
        if (write_phy_reg(base_address, pphy_config->phy_address, COPPER_AUTONEG_ADV_REG,
                (uint16_t)adv) != 0)
        {
            return false;
        }

        /* Enable 1G Full/Half duplex Advertisement */
        adv = AUTONEG_ADV_1GBASE_TX_ALLDPLX_MASK;
        if (write_phy_reg(base_address, pphy_config->phy_address, PHY_1GBASE_T_CONTROL_REG,
                (uint16_t)adv) != 0)
        {
            return false;
        }
    }
    else
    {
        /* Unsupported configuration */
        INFO("Unsupported advertisement.");
        return false;
    }
    if ((pphy_config->pause == ENABLE_ASYNC_PAUSE) || (pphy_config->pause ==
            ENABLE_MAC_PAUSE))
    {
        /* Pause Frames unsupported */
        return false;
    }
    return true;
}
static Basetype_t phy_reset(uint32_t base_address, xgmac_phy_config_t *pphy_config)
{
    uint32_t data;
    uint8_t cnt = 0;

    /* Read the copper control register */
    if (write_phy_reg(base_address, pphy_config->phy_address, PAGE_ADDRESS_SELECT_REG,
            SELECT_PAGE_ZERO) != 0)
    {
        return false;
    }
    data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG);

    data |= COPPER_CONTROL_PHY_RESET_MASK;
    if (write_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG,
            (uint16_t)data) != 0)
    {
        return false;
    }

    /* Wait for PHY reset to complete */
    do
    {
        data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, COPPER_CONTROL_REG);

        cnt++;
        if (cnt >= MAX_GEN_TIMER_COUNT)
        {
            ERROR("PHY reset timeout reached.");
            return false;
        }
    } while((data & COPPER_CONTROL_PHY_RESET_MASK) != 0U); /* Check if the reset bit is still set */

    return true;
}

static Basetype_t phy_link_status(uint32_t base_address, xgmac_phy_config_t *pphy_config)
{
    uint8_t reg;
    uint16_t mask;
    uint32_t data;
#if (REAL_TIME_LINK_STATUS == 1)
    reg = COPPER_SPECIFIC_STATUS_REG_1;
    mask = COPPER_REAL_TIME_LINK_STATUS_MASK;
#else
    reg = COPPER_STATUS_REG;
    mask = COPPER_LINK_STATUS_MASK;
#endif

    /* Read the copper status register */
    data = (uint32_t)read_phy_reg(base_address, pphy_config->phy_address, reg);

    if ((data & mask) != 0U)
    {
        pphy_config->link_status = LINK_UP;
        return true;
    }
    else
    {
        pphy_config->link_status = LINK_DOWN;
        return false;
    }
}
