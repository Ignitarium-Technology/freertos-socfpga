/**
 * SPDX-FileCopyrightText: Copyright (C) 2025-2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver implementation for I3C
 */

#include <errno.h>
#include <stddef.h>
#include <string.h>
#include "socfpga_defines.h"
#include "socfpga_i3c_regs.h"
#include "socfpga_i3c.h"
#include "socfpga_i3c_ll.h"

#define MHZ         (1000000U)
#define NANO_SEC    (1000000000U)

#define I3C_CCC_TRANSFER_CMD          0x0U
#define I3C_CCC_TRANSFER_ARG          0x1U
#define I3C_CCC_SHORT_DATA_ARG        0x2U
#define I3C_CCC_ADDRESS_ASSIGN_CMD    0x3U

static bool i3c_dat_slot_in_use[I3C_NUM_INSTANCES][I3C_MAX_DEVICES] =
{ false };

struct i3c_cmd_obj
{
    uint32_t cmd_word;
    uint32_t arg_word;
    uint8_t *data;
    uint16_t rx_length;
    uint16_t tx_length;
    uint16_t write_bytes_left;
    uint8_t *write_buffer;
    uint16_t read_bytes_left;
    uint8_t *read_buffer;
    int32_t status;
    bool is_read;
};

static struct i3c_cmd_obj i3c_cmd_store[I3C_NUM_INSTANCES][I3C_MAX_XFER];

/* Static prototypes: command word builders. */
static int32_t i3c_ll_build_xfer_word(struct i3c_cmd_obj *cmd_obj, uint8_t tid,
        uint8_t dev_index, struct i3c_cmd_payload *payload, bool is_i2c,
        bool is_last);
static int32_t i3c_ll_build_addr_assign_word(struct i3c_cmd_obj *cmd_obj,
        uint8_t tid, uint8_t cmd_id, uint8_t dev_index, uint8_t dev_count);

typedef struct
{
    uint8_t dat_index;
    uint8_t requested_dynamic_addr;
} i3c_ll_dasa_req_t;

typedef struct
{
    uint8_t start_dat_index;
    uint8_t device_count;
    uint8_t *assigned_dynamic_addrs;
    uint8_t assigned_buf_len;
} i3c_ll_daa_req_t;

/* Static prototypes: DAT and timing helpers. */
static int32_t i3c_ll_alloc_dat_slot(uint8_t instance, uint32_t *dat_index);
static void i3c_ll_configure_scl(uint32_t base_addr);
static struct i3c_cmd_obj *i3c_ll_get_cmd_obj(uint8_t instance);

/* Static prototypes: command queue and response helpers. */
static uint8_t i3c_ll_get_response_count(uint32_t base_addr);
static uint32_t i3c_ll_get_response(uint32_t base_addr);
static void i3c_ll_set_response_threshold(uint32_t base_addr, uint8_t threshold);
static void i3c_ll_queue_xfer_cmd(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj, uint8_t num_cmds);

/* Static prototypes: interrupt and IBI helpers. */
static uint8_t get_ibi_reject_bit_index(uint8_t ibi_id);
static uint32_t i3c_ll_intr_status_mask_from_ids(uint32_t mask);
static uint32_t i3c_ll_intr_signal_mask_from_ids(uint32_t mask);
static uint32_t i3c_ll_get_ibi_data(uint32_t base_addr);
static void i3c_ll_set_data_thresholds(uint32_t base_addr, uint32_t rx_thld,
        uint32_t tx_thld);

/* Static prototypes: transfer and address-assign helpers. */
static int32_t i3c_ll_prepare_xfer_cmd(struct i3c_cmd_obj *cmd_obj, uint8_t tid,
        uint8_t dev_index, const struct i3c_cmd_payload *payload, bool is_i2c,
        bool is_last);
static int32_t i3c_ll_prepare_addr_assign_cmd(struct i3c_cmd_obj *cmd_obj,
        uint8_t tid, uint8_t cmd_id, uint8_t dev_index, uint8_t dev_count);
static void i3c_ll_submit_cmds(uint32_t base_addr, struct i3c_cmd_obj *cmd_obj,
        uint8_t num_cmds, bool is_addr_cmd);
static int32_t i3c_ll_execute_setdasa(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj,
        const i3c_ll_dasa_req_t *req);
static int32_t i3c_ll_execute_entdaa(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj,
        const i3c_ll_daa_req_t *req);

/**
 * @brief Allocate a free DAT slot for a controller instance.
 *
 * @param[in] instance I3C controller instance.
 * @param[out] dat_index Allocated DAT index.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_alloc_dat_slot(uint8_t instance, uint32_t *dat_index)
{
    uint32_t i;

    if ((instance >= I3C_NUM_INSTANCES) || (dat_index == NULL))
    {
        return -EINVAL;
    }

    for (i = 0U; i < I3C_MAX_DEVICES; i++)
    {
        if (i3c_dat_slot_in_use[instance][i] == false)
        {
            i3c_dat_slot_in_use[instance][i] = true;
            *dat_index = i;
            return 0;
        }
    }

    return -ENOMEM;
}

/**
 * @brief Get transfer command storage for an instance.
 *
 * @param[in] instance I3C controller instance.
 * @return Command object storage pointer, or NULL on invalid instance.
 */
static struct i3c_cmd_obj *i3c_ll_get_cmd_obj(uint8_t instance)
{
    if (instance >= I3C_NUM_INSTANCES)
    {
        return NULL;
    }

    return &i3c_cmd_store[instance][0];
}

/* HAL-accessible DAT management APIs. */


void i3c_ll_reset_dat_slots(uint8_t instance)
{
    if (instance < I3C_NUM_INSTANCES)
    {
        (void)memset(i3c_dat_slot_in_use[instance], 0,
                sizeof(i3c_dat_slot_in_use[instance]));
    }
}


/**
 *
 * @brief Configure SCL timing registers for I3C and I2C bus modes.
 *
 * @param[in] base_addr I3C controller register base address.
 *
 */
static void i3c_ll_configure_scl(uint32_t base_addr)
{
    uint32_t core_clk, core_period;
    uint32_t hcnt, lcnt;
    uint32_t value;

    core_clk = I3C_CORE_CLOCK;
    if (core_clk == 0U)
    {
        return;
    }

    core_period = ((NANO_SEC + (core_clk - 1U)) / core_clk);
    if (core_period == 0U)
    {
        return;
    }

    hcnt = (I3C_BUS_THIGH_MAX_NS + (core_period - 1U)) / core_period;
    hcnt -= 1U;
    if (hcnt < SCL_I3C_TIMING_CNT_MIN)
    {
        hcnt = SCL_I3C_TIMING_CNT_MIN;
    }

    lcnt = (core_clk + (I3C_BUS_TYP_I3C_SCL_RATE - 1U)) /
            I3C_BUS_TYP_I3C_SCL_RATE;
    lcnt -= hcnt;
    if (lcnt < SCL_I3C_TIMING_CNT_MIN)
    {
        lcnt = SCL_I3C_TIMING_CNT_MIN;
    }

    value = RD_REG32(base_addr + I3C_SCL_I3C_PP_TIMING);
    value &= ~(I3C_SCL_I3C_PP_TIMING_I3C_PP_LCNT_MASK |
            I3C_SCL_I3C_PP_TIMING_I3C_PP_HCNT_MASK);
    value |= ((lcnt << I3C_SCL_I3C_PP_TIMING_I3C_PP_LCNT_POS) &
            I3C_SCL_I3C_PP_TIMING_I3C_PP_LCNT_MASK);
    value |= ((hcnt << I3C_SCL_I3C_PP_TIMING_I3C_PP_HCNT_POS) &
            I3C_SCL_I3C_PP_TIMING_I3C_PP_HCNT_MASK);
    WR_REG32(base_addr + I3C_SCL_I3C_PP_TIMING, value);

    WR_REG32((base_addr + I3C_BUS_FREE_AVAIL_TIMING), lcnt);

    lcnt = (I3C_BUS_TLOW_OD_MIN_NS + (core_period - 1U)) / core_period;
    value = RD_REG32(base_addr + I3C_SCL_I3C_OD_TIMING);
    value &= ~(I3C_SCL_I3C_OD_TIMING_I3C_OD_LCNT_MASK |
            I3C_SCL_I3C_OD_TIMING_I3C_OD_HCNT_MASK);
    value |= ((lcnt << I3C_SCL_I3C_OD_TIMING_I3C_OD_LCNT_POS) &
            I3C_SCL_I3C_OD_TIMING_I3C_OD_LCNT_MASK);
    value |= ((hcnt << I3C_SCL_I3C_OD_TIMING_I3C_OD_HCNT_POS) &
            I3C_SCL_I3C_OD_TIMING_I3C_OD_HCNT_MASK);
    WR_REG32(base_addr + I3C_SCL_I3C_OD_TIMING, value);

    lcnt = ((core_clk + (I3C_BUS_SDR1_SCL_RATE - 1U)) /
            I3C_BUS_SDR1_SCL_RATE) - hcnt;
    value = RD_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING);
    value &= ~I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_1_MASK;
    value |= ((lcnt << I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_1_POS) &
            I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_1_MASK);
    WR_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING, value);

    lcnt = ((core_clk + (I3C_BUS_SDR2_SCL_RATE - 1U)) /
            I3C_BUS_SDR2_SCL_RATE) - hcnt;
    value = RD_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING);
    value &= ~I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_2_MASK;
    value |= ((lcnt << I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_2_POS) &
            I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_2_MASK);
    WR_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING, value);

    lcnt = ((core_clk + (I3C_BUS_SDR3_SCL_RATE - 1U)) /
            I3C_BUS_SDR3_SCL_RATE) - hcnt;
    value = RD_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING);
    value &= ~I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_3_MASK;
    value |= ((lcnt << I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_3_POS) &
            I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_3_MASK);
    WR_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING, value);

    lcnt = ((core_clk + (I3C_BUS_SDR4_SCL_RATE - 1U)) /
            I3C_BUS_SDR4_SCL_RATE) - hcnt;
    value = RD_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING);
    value &= ~I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_4_MASK;
    value |= ((lcnt << I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_4_POS) &
            I3C_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_4_MASK);
    WR_REG32(base_addr + I3C_SCL_EXT_LCNT_TIMING, value);

    lcnt = (I3C_BUS_I2C_FM_TLOW_MIN_NS + (core_period - 1U)) / core_period;
    hcnt = ((core_clk + (I3C_BUS_I2C_FM_SCL_RATE - 1U)) /
            I3C_BUS_I2C_FM_SCL_RATE) - lcnt;
    value = RD_REG32(base_addr + I3C_SCL_I2C_FM_TIMING);
    value &= ~(I3C_SCL_I2C_FM_TIMING_I2C_FM_LCNT_MASK |
            I3C_SCL_I2C_FM_TIMING_I2C_FM_HCNT_MASK);
    value |= ((lcnt << I3C_SCL_I2C_FM_TIMING_I2C_FM_LCNT_POS) &
            I3C_SCL_I2C_FM_TIMING_I2C_FM_LCNT_MASK);
    value |= ((hcnt << I3C_SCL_I2C_FM_TIMING_I2C_FM_HCNT_POS) &
            I3C_SCL_I2C_FM_TIMING_I2C_FM_HCNT_MASK);
    WR_REG32(base_addr + I3C_SCL_I2C_FM_TIMING, value);

    lcnt = (I3C_BUS_I2C_FMP_TLOW_MIN_NS + (core_period - 1U)) / core_period;
    hcnt = ((core_clk + (I3C_BUS_I2C_FM_PLUS_SCL_RATE - 1U)) /
            I3C_BUS_I2C_FM_PLUS_SCL_RATE) - lcnt;
    value = RD_REG32(base_addr + I3C_SCL_I2C_FMP_TIMING);
    value &= ~(I3C_SCL_I2C_FMP_TIMING_I2C_FMP_LCNT_MASK |
            I3C_SCL_I2C_FMP_TIMING_I2C_FMP_HCNT_MASK);
    value |= ((lcnt << I3C_SCL_I2C_FMP_TIMING_I2C_FMP_LCNT_POS) &
            I3C_SCL_I2C_FMP_TIMING_I2C_FMP_LCNT_MASK);
    value |= ((hcnt << I3C_SCL_I2C_FMP_TIMING_I2C_FMP_HCNT_POS) &
            I3C_SCL_I2C_FMP_TIMING_I2C_FMP_HCNT_MASK);
    WR_REG32(base_addr + I3C_SCL_I2C_FMP_TIMING, value);
}

/* HAL-accessible controller lifecycle APIs. */

int32_t i3c_ll_init(uint8_t instance, uint8_t own_da, uint32_t *base_addr,
        uint32_t *dat_base, uint32_t *dct_base, uint32_t *cmd_fifo_depth,
        uint32_t *data_fifo_depth, bool *is_primary)
{
    uint32_t role;
    uint32_t value;
    uint8_t bitpos;
    uint32_t mask;
    uint32_t timeout;

    if ((instance >= I3C_NUM_INSTANCES) ||
            (base_addr == NULL) || (dat_base == NULL) || (dct_base == NULL) ||
            (cmd_fifo_depth == NULL) || (data_fifo_depth == NULL) ||
            (is_primary == NULL))
    {
        return -EINVAL;
    }

    bitpos = PER1MODRST_I3C0_POS + instance;
    mask = (1U << (uint32_t)bitpos);
    value = RD_REG32(PER1MODRST);
    value &= ~mask;
    WR_REG32(PER1MODRST, value);

    timeout = 1000000U;
    while (timeout > 0U)
    {
        value = RD_REG32(PER1MODRST);
        if ((value & mask) == 0U)
        {
            break;
        }
        timeout--;
    }
    if (timeout == 0U)
    {
        return -ETIMEDOUT;
    }

    *base_addr = I3C_CONTROLLER_REGISTER_BASE(instance);
    i3c_ll_configure_scl(*base_addr);

    value = RD_REG32(*base_addr + I3C_HW_CAPABILITY);
    role = (value & I3C_HW_CAPABILITY_DEVICE_ROLE_CONFIG_MASK) >>
            I3C_HW_CAPABILITY_DEVICE_ROLE_CONFIG_POS;
    *is_primary = (role == I3C_CONTROLLER_MASTER);

    value = RD_REG32(*base_addr + I3C_DEVICE_ADDR_TABLE_POINTER);
    *dat_base = (value & I3C_DEVICE_ADDR_TABLE_POINTER_P_DEV_ADDR_TABLE_START_ADDR_MASK) >>
            I3C_DEVICE_ADDR_TABLE_POINTER_P_DEV_ADDR_TABLE_START_ADDR_POS;
    value = RD_REG32(*base_addr + I3C_DEV_CHAR_TABLE_POINTER);
    *dct_base = (value & I3C_DEV_CHAR_TABLE_POINTER_P_DEV_CHAR_TABLE_START_ADDR_MASK) >>
            I3C_DEV_CHAR_TABLE_POINTER_P_DEV_CHAR_TABLE_START_ADDR_POS;

    value = RD_REG32(*base_addr + I3C_DEVICE_ADDR);
    value &= ~(I3C_DEVICE_ADDR_DYNAMIC_ADDR_VALID_MASK | I3C_DEVICE_ADDR_DYNAMIC_ADDR_MASK);
    value |= ((uint32_t)1U << I3C_DEVICE_ADDR_DYNAMIC_ADDR_VALID_POS) & I3C_DEVICE_ADDR_DYNAMIC_ADDR_VALID_MASK;
    value |= ((uint32_t)own_da << I3C_DEVICE_ADDR_DYNAMIC_ADDR_POS) & I3C_DEVICE_ADDR_DYNAMIC_ADDR_MASK;
    WR_REG32(*base_addr + I3C_DEVICE_ADDR, value);

    value = RD_REG32(*base_addr + I3C_QUEUE_STATUS_LEVEL);
    *cmd_fifo_depth = (value & I3C_QUEUE_STATUS_LEVEL_CMD_QUEUE_EMPTY_LOC_MASK) >>
            I3C_QUEUE_STATUS_LEVEL_CMD_QUEUE_EMPTY_LOC_POS;
    value = RD_REG32(*base_addr + I3C_DATA_BUFFER_STATUS_LEVEL);
    *data_fifo_depth = (value & I3C_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_MASK) >>
            I3C_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_POS;

    value = RD_REG32(*base_addr + I3C_DEVICE_CTRL);
    value &= ~I3C_DEVICE_CTRL_ENABLE_MASK;
    value |= ((uint32_t)1U << I3C_DEVICE_CTRL_ENABLE_POS) & I3C_DEVICE_CTRL_ENABLE_MASK;
    WR_REG32(*base_addr + I3C_DEVICE_CTRL, value);

    return 0;
}

/* HAL-accessible FIFO APIs. */

uint16_t i3c_ll_push_tx_fifo(uint32_t base_addr, uint8_t *data,
        uint16_t length)
{
    uint32_t tx_empty_loc, write_len;
    uint16_t bytes_written = 0U;
    uint16_t num_words;
    uint16_t num_bytes;
    uint32_t word, i;
    uint8_t *buf = data;

    if (buf == NULL)
    {
        return 0U;
    }

    tx_empty_loc = RD_REG32((base_addr + I3C_DATA_BUFFER_STATUS_LEVEL));
    tx_empty_loc = (tx_empty_loc &
            I3C_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_MASK) >>
            I3C_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_POS;
    tx_empty_loc *= RX_TX_DATA_PORT_SIZE;

    write_len = (uint32_t)length < tx_empty_loc ? (uint32_t)length : tx_empty_loc;
    num_words = (uint16_t)(write_len / RX_TX_DATA_PORT_SIZE);
    num_bytes = (uint16_t)(write_len & (RX_TX_DATA_PORT_SIZE - 1U));

    for (i = 0; i < num_words; i++)
    {
        word = ((uint32_t)buf[0]) | ((uint32_t)buf[1] << 8U) |
                ((uint32_t)buf [2] << 16U) | ((uint32_t)buf[3] << 24U);
        WR_REG32((base_addr + I3C_TX_DATA_PORT), word);
        buf += RX_TX_DATA_PORT_SIZE;
    }

    bytes_written = num_words * 4U;
    if (num_bytes != 0U)
    {
        word = 0U;
        for (i = 0; i < num_bytes; i++)
        {
            word |= (uint32_t)(*buf) << (8U * i);
            buf++;
            bytes_written++;
        }
        WR_REG32((base_addr + I3C_TX_DATA_PORT), word);
    }

    return bytes_written;
}

uint16_t i3c_ll_read_rx_fifo(uint32_t base_addr, uint8_t *data,
        uint16_t length)
{
    uint16_t num_words;
    uint16_t num_bytes, i, j;
    uint32_t word;
    uint8_t *buf = data;
    uint16_t bytes_read = 0U;
    uint32_t rx_fill_level, read_len;

    if (buf == NULL)
    {
        return 0U;
    }

    rx_fill_level = RD_REG32((base_addr + I3C_DATA_BUFFER_STATUS_LEVEL));
    rx_fill_level = ((rx_fill_level &
            I3C_DATA_BUFFER_STATUS_LEVEL_RX_BUF_BLR_MASK) >>
            I3C_DATA_BUFFER_STATUS_LEVEL_RX_BUF_BLR_POS);
    rx_fill_level = rx_fill_level * 4U;

    read_len = (uint32_t)length < rx_fill_level ? (uint32_t)length : rx_fill_level;
    num_words = (uint16_t)(read_len / RX_TX_DATA_PORT_SIZE);
    num_bytes = (uint16_t)(read_len & (RX_TX_DATA_PORT_SIZE - 1U));

    for (i = 0U; i < num_words; i++)
    {
        word = RD_REG32((base_addr + I3C_RX_DATA_PORT));
        for (j = 0U; j < RX_TX_DATA_PORT_SIZE; j++)
        {
            buf[j] = (uint8_t)(word & 0xFFU);
            word >>= 8U;
        }
        buf += RX_TX_DATA_PORT_SIZE;
    }

    bytes_read = num_words * 4U;
    if (num_bytes > 0U)
    {
        word = RD_REG32((base_addr + I3C_RX_DATA_PORT));
        for (j = 0U; j < num_bytes; j++)
        {
            buf[j] = (uint8_t)(word & 0xFFU);
            word >>= 8U;
            bytes_read++;
        }
    }

    return bytes_read;
}

void i3c_ll_service_transfer_thresholds(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds, uint32_t intr_status)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;
    uint16_t bytes;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (num_cmds == 0U))
    {
        return;
    }

    if ((intr_status & I3C_TX_THLD_STS_INTR) != 0U)
    {
        for (i = 0U; i < num_cmds; i++)
        {
            if (cmd_obj[i].write_bytes_left > 0U)
            {
                bytes = i3c_ll_push_tx_fifo(base_addr, cmd_obj[i].write_buffer,
                        cmd_obj[i].write_bytes_left);
                cmd_obj[i].write_bytes_left -= bytes;
                cmd_obj[i].write_buffer += bytes;
            }
        }
    }

    if ((intr_status & I3C_RX_THLD_STS_INTR) != 0U)
    {
        for (i = 0U; i < num_cmds; i++)
        {
            if (cmd_obj[i].read_bytes_left > 0U)
            {
                bytes = i3c_ll_read_rx_fifo(base_addr, cmd_obj[i].read_buffer,
                        cmd_obj[i].read_bytes_left);
                cmd_obj[i].read_bytes_left -= bytes;
                cmd_obj[i].read_buffer += bytes;
            }
        }
    }
}

void i3c_ll_complete_read_transfers(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;
    uint16_t bytes;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (num_cmds == 0U))
    {
        return;
    }

    for (i = 0U; i < num_cmds; i++)
    {
        if ((cmd_obj[i].rx_length > 0U) &&
                (cmd_obj[i].status == I3C_RESPONSE_OK) &&
                (cmd_obj[i].read_bytes_left > 0U))
        {
            bytes = i3c_ll_read_rx_fifo(base_addr, cmd_obj[i].read_buffer,
                    cmd_obj[i].read_bytes_left);
            cmd_obj[i].read_bytes_left -= bytes;
            cmd_obj[i].read_buffer += bytes;
        }
    }
}

/**
 * @brief Get number of available response entries.
 *
 * @param[in] base_addr I3C controller register base address.
 * @return Response queue entry count.
 */
static uint8_t i3c_ll_get_response_count(uint32_t base_addr)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_QUEUE_STATUS_LEVEL);
    return (uint8_t)((value & I3C_QUEUE_STATUS_LEVEL_RESP_BUF_BLR_MASK) >>
            I3C_QUEUE_STATUS_LEVEL_RESP_BUF_BLR_POS);
}

/**
 * @brief Read one response entry from response queue.
 *
 * @param[in] base_addr I3C controller register base address.
 * @return Response queue word.
 */
static uint32_t i3c_ll_get_response(uint32_t base_addr)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_RESPONSE_QUEUE_PORT);
    return value;
}

/**
 * @brief Configure response threshold for response-ready interrupt.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in] threshold Response queue threshold.
 */
static void i3c_ll_set_response_threshold(uint32_t base_addr, uint8_t threshold)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_QUEUE_THLD_CTRL);
    value &= ~I3C_QUEUE_THLD_CTRL_RESP_BUF_THLD_MASK;
    value |= ((uint32_t)threshold << I3C_QUEUE_THLD_CTRL_RESP_BUF_THLD_POS) &
            I3C_QUEUE_THLD_CTRL_RESP_BUF_THLD_MASK;
    WR_REG32(base_addr + I3C_QUEUE_THLD_CTRL, value);
}

/**
 * @brief Submit command objects to command queue.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in] cmd_obj Command object array.
 * @param[in] num_cmds Number of commands.
 */
static void i3c_ll_queue_xfer_cmd(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj, uint8_t num_cmds)
{
    uint8_t i;

    for (i = 0U; i < num_cmds; i++)
    {
        WR_REG32((base_addr + I3C_COMMAND_QUEUE_PORT), cmd_obj[i].arg_word);
        WR_REG32((base_addr + I3C_COMMAND_QUEUE_PORT), cmd_obj[i].cmd_word);
    }
}

/* HAL-accessible DAT attach/detach APIs. */


int32_t i3c_ll_attach_dat_i2c(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint8_t addr, uint32_t *dat_index)
{
    uint32_t addr_entry;
    uint32_t addr_entry_val;
    int32_t ret;

    ret = i3c_ll_alloc_dat_slot(instance, dat_index);
    if (ret != 0)
    {
        return ret;
    }

    addr_entry = dat_base + ((*dat_index) * sizeof(uint32_t));
    addr_entry_val = ((uint32_t)1U << I3C_DAT_DEVICE_BIT_POS);
    addr_entry_val |= (((uint32_t)addr <<
            I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_POS) &
            (I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_MASK));

    WR_REG32((base_addr + addr_entry), addr_entry_val);
    return 0;
}

int32_t i3c_ll_attach_dat_i3c(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint8_t addr, uint32_t *dat_index)
{
    uint32_t addr_entry;
    uint32_t addr_entry_val;
    uint8_t dynamic_addr;
    uint8_t temp_addr, p;
    int32_t ret;

    ret = i3c_ll_alloc_dat_slot(instance, dat_index);
    if (ret != 0)
    {
        return ret;
    }

    dynamic_addr = (uint8_t)(addr & I3C_MAX_ADDR);
    addr_entry = dat_base + ((*dat_index) * sizeof(uint32_t));
    p = (dynamic_addr ^ (dynamic_addr >> 4U)) & 0xFU;
    p = ((uint8_t)(0x9669U >> p)) & 0x1U;
    temp_addr = (uint8_t)(dynamic_addr | (uint8_t)(p << 7U));

    addr_entry_val = ((uint32_t)dynamic_addr <<
            I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_POS) &
            I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_MASK;
    addr_entry_val |= ((uint32_t)temp_addr <<
            I3C_DEV_ADDR_TABLE1_LOC1_DEV_DYNAMIC_ADDR_POS) &
            I3C_DEV_ADDR_TABLE1_LOC1_DEV_DYNAMIC_ADDR_MASK;

    WR_REG32((base_addr + addr_entry), addr_entry_val);

    return 0;
}

int32_t i3c_ll_detach_dat(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint32_t dat_index, uint8_t addr)
{
    bool is_i2c;
    uint8_t cur_addr;
    uint32_t addr_entry;
    uint32_t value;

    if ((instance >= I3C_NUM_INSTANCES) || (dat_index >= I3C_MAX_DEVICES))
    {
        return -EINVAL;
    }

    addr_entry = dat_base + (dat_index * sizeof(uint32_t));
    value = RD_REG32(base_addr + addr_entry);
    is_i2c = ((value & I3C_DEV_ADDR_TABLE1_LOC1_DEVICE_MASK) != 0U);
    if (is_i2c)
    {
        cur_addr = (uint8_t)((value & I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_MASK) >>
                I3C_DEV_ADDR_TABLE1_LOC1_STATIC_ADDRESS_POS);
    }
    else
    {
        cur_addr = (uint8_t)((value & I3C_DEV_ADDR_TABLE1_LOC1_DEV_DYNAMIC_ADDR_MASK) >>
                I3C_DEV_ADDR_TABLE1_LOC1_DEV_DYNAMIC_ADDR_POS);
    }
    cur_addr &= I3C_MAX_ADDR;

    if (cur_addr != (addr & I3C_MAX_ADDR))
    {
        return -EINVAL;
    }

    WR_REG32(base_addr + addr_entry, 0U);
    i3c_dat_slot_in_use[instance][dat_index] = false;
    return 0;
}

/**
 *
 * @brief Compute bit index for IBI reject register from IBI identifier.
 *
 * @param[in] ibi_id IBI identifier.
 * @return Reject register bit index.
 *
 */
static uint8_t get_ibi_reject_bit_index(uint8_t ibi_id)
{
    uint8_t sum = (uint8_t)((ibi_id & 0x1FU) + ((ibi_id >> 5U) & 0x3U));
    return (uint8_t)(sum & 0x1FU);
}

/* HAL-accessible IBI configuration APIs. */

int32_t i3c_ll_configure_ibi(uint32_t base_addr, uint32_t dat_base,
        uint32_t dat_index, uint8_t dynamic_addr, bool enable,
        bool ibi_with_data)
{
    uint8_t bit = get_ibi_reject_bit_index(dynamic_addr);
    uint32_t sir_reject;
    uint32_t addr_entry;
    uint32_t reg;

    sir_reject = RD_REG32(base_addr + I3C_IBI_SIR_REQ_REJECT);
    if (enable)
    {
        sir_reject &= ~(1U << bit);
    }
    else
    {
        sir_reject |= (1U << bit);
    }
    WR_REG32(base_addr + I3C_IBI_SIR_REQ_REJECT, sir_reject);

    addr_entry = dat_base + ((dat_index * sizeof(uint32_t)));
    reg = RD_REG32(base_addr + addr_entry);

    if (enable)
    {
        reg &= ~I3C_DEV_ADDR_TABLE1_LOC1_SIR_REJECT_MASK;
    }
    else
    {
        reg |= I3C_DEV_ADDR_TABLE1_LOC1_SIR_REJECT_MASK;
    }

    reg |= I3C_DEV_ADDR_TABLE1_LOC1_MR_REJECT_MASK;
    if (enable && ibi_with_data)
    {
        reg |= I3C_DEV_ADDR_TABLE1_LOC1_IBI_WITH_DATA_MASK;
    }
    else
    {
        reg &= ~I3C_DEV_ADDR_TABLE1_LOC1_IBI_WITH_DATA_MASK;
    }

    reg &= ~I3C_DEV_ADDR_TABLE1_LOC1_IBI_PEC_EN_MASK;
    WR_REG32((base_addr + addr_entry), reg);
    return 0;
}

/* HAL-accessible interrupt control APIs. */

uint32_t i3c_ll_get_intr_status(uint32_t base_addr)
{
    uint32_t value;
    uint32_t status;

    value = RD_REG32(base_addr + I3C_INTR_STATUS);
    status = 0U;

    if ((value & I3C_INTR_STATUS_TX_THLD_STS_MASK) != 0U)
    {
        status |= I3C_TX_THLD_STS_INTR;
    }
    if ((value & I3C_INTR_STATUS_RX_THLD_STS_MASK) != 0U)
    {
        status |= I3C_RX_THLD_STS_INTR;
    }
    if ((value & I3C_INTR_STATUS_RESP_READY_STS_MASK) != 0U)
    {
        status |= I3C_RESP_READY_STS_INTR;
    }
    if ((value & I3C_INTR_STATUS_TRANSFER_ERR_STS_MASK) != 0U)
    {
        status |= I3C_TRANSFER_ERR_STS_INTR;
    }
    if ((value & I3C_INTR_STATUS_IBI_THLD_STS_MASK) != 0U)
    {
        status |= I3C_IBI_THLD_STS_INTR;
    }

    return status;
}

/**
 * @brief Convert HAL interrupt IDs to hardware status register bits.
 *
 * @param[in] mask HAL interrupt ID mask.
 * @return Hardware status-mask bits.
 */
static uint32_t i3c_ll_intr_status_mask_from_ids(uint32_t mask)
{
    uint32_t value = 0U;

    if ((mask & I3C_TX_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_STATUS_TX_THLD_STS_MASK;
    }
    if ((mask & I3C_RX_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_STATUS_RX_THLD_STS_MASK;
    }
    if ((mask & I3C_RESP_READY_STS_INTR) != 0U)
    {
        value |= I3C_INTR_STATUS_RESP_READY_STS_MASK;
    }
    if ((mask & I3C_TRANSFER_ERR_STS_INTR) != 0U)
    {
        value |= I3C_INTR_STATUS_TRANSFER_ERR_STS_MASK;
    }
    if ((mask & I3C_IBI_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_STATUS_IBI_THLD_STS_MASK;
    }

    return value;
}

/**
 * @brief Convert HAL interrupt IDs to hardware signal-enable bits.
 *
 * @param[in] mask HAL interrupt ID mask.
 * @return Hardware signal-enable bits.
 */
static uint32_t i3c_ll_intr_signal_mask_from_ids(uint32_t mask)
{
    uint32_t value = 0U;

    if ((mask & I3C_TX_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_SIGNAL_EN_TX_THLD_SIGNAL_EN_MASK;
    }
    if ((mask & I3C_RX_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_SIGNAL_EN_RX_THLD_SIGNAL_EN_MASK;
    }
    if ((mask & I3C_RESP_READY_STS_INTR) != 0U)
    {
        value |= I3C_INTR_SIGNAL_EN_RESP_READY_SIGNAL_EN_MASK;
    }
    if ((mask & I3C_TRANSFER_ERR_STS_INTR) != 0U)
    {
        value |= I3C_INTR_SIGNAL_EN_TRANSFER_ERR_SIGNAL_EN_MASK;
    }
    if ((mask & I3C_IBI_THLD_STS_INTR) != 0U)
    {
        value |= I3C_INTR_SIGNAL_EN_IBI_THLD_SIGNAL_EN_MASK;
    }

    return value;
}

void i3c_ll_clear_intr_status(uint32_t base_addr, uint32_t mask)
{
    WR_REG32(base_addr + I3C_INTR_STATUS,
            i3c_ll_intr_status_mask_from_ids(mask));
}

void i3c_ll_enable_interrupt(uint32_t base_addr, uint32_t mask)
{
    uint32_t status_value;
    uint32_t signal_value;
    uint32_t status_mask;
    uint32_t signal_mask;

    status_mask = i3c_ll_intr_status_mask_from_ids(mask);
    signal_mask = i3c_ll_intr_signal_mask_from_ids(mask);

    status_value = RD_REG32(base_addr + I3C_INTR_STATUS_EN);
    signal_value = RD_REG32(base_addr + I3C_INTR_SIGNAL_EN);

    status_value |= status_mask;
    signal_value |= signal_mask;

    WR_REG32(base_addr + I3C_INTR_STATUS_EN, status_value);
    WR_REG32(base_addr + I3C_INTR_SIGNAL_EN, signal_value);
}

void i3c_ll_disable_interrupt(uint32_t base_addr, uint32_t mask)
{
    uint32_t status_value;
    uint32_t signal_value;
    uint32_t status_mask;
    uint32_t signal_mask;

    status_mask = i3c_ll_intr_status_mask_from_ids(mask);
    signal_mask = i3c_ll_intr_signal_mask_from_ids(mask);

    status_value = RD_REG32(base_addr + I3C_INTR_STATUS_EN);
    signal_value = RD_REG32(base_addr + I3C_INTR_SIGNAL_EN);

    status_value &= ~status_mask;
    signal_value &= ~signal_mask;

    WR_REG32(base_addr + I3C_INTR_STATUS_EN, status_value);
    WR_REG32(base_addr + I3C_INTR_SIGNAL_EN, signal_value);
}

/* HAL-accessible queue recovery APIs. */

void i3c_ll_reset_queues(uint32_t base_addr)
{
    WR_REG32((base_addr + I3C_RESET_CTRL),
            (I3C_RESET_CTRL_RX_FIFO_RST_MASK |
            I3C_RESET_CTRL_TX_FIFO_RST_MASK |
            I3C_RESET_CTRL_RESP_QUEUE_RST_MASK |
            I3C_RESET_CTRL_CMD_QUEUE_RST_MASK));
}

void i3c_ll_resume(uint32_t base_addr)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_DEVICE_CTRL);
    value &= ~I3C_DEVICE_CTRL_RESUME_MASK;
    value |= ((uint32_t)1U << I3C_DEVICE_CTRL_RESUME_POS) & I3C_DEVICE_CTRL_RESUME_MASK;
    WR_REG32(base_addr + I3C_DEVICE_CTRL, value);
}

/* HAL-accessible IBI queue APIs. */


uint32_t i3c_ll_get_ibi_status(uint32_t base_addr)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_IBI_QUEUE_STATUS);
    return value;
}

/**
 * @brief Read one IBI payload word from IBI queue.
 *
 * @param[in] base_addr I3C controller register base address.
 * @return IBI queue data word.
 */
static uint32_t i3c_ll_get_ibi_data(uint32_t base_addr)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_IBI_QUEUE_DATA);
    return value;
}

uint32_t i3c_ll_get_ibi_count(uint32_t base_addr)
{
    uint32_t queue_level;
    uint32_t count;

    queue_level = RD_REG32(base_addr + I3C_QUEUE_STATUS_LEVEL);
    count = (queue_level & I3C_QUEUE_STATUS_LEVEL_IBI_BUF_BLR_MASK) >>
            I3C_QUEUE_STATUS_LEVEL_IBI_BUF_BLR_POS;
    return count;
}

void i3c_ll_get_ibi_fields(uint32_t value, uint8_t *ibi_sts,
        uint8_t *ibi_id, uint8_t *data_len)
{
    if ((ibi_sts == NULL) || (ibi_id == NULL) || (data_len == NULL))
    {
        return;
    }

    *ibi_sts = (uint8_t)((value & I3C_IBI_QUEUE_STATUS_IBI_STS_MASK) >>
            I3C_IBI_QUEUE_STATUS_IBI_STS_POS);
    *ibi_id = (uint8_t)((value & I3C_IBI_QUEUE_STATUS_IBI_ID_MASK) >>
            I3C_IBI_QUEUE_STATUS_IBI_ID_POS);
    *data_len = (uint8_t)((value & I3C_IBI_QUEUE_STATUS_DATA_LENGTH_MASK) >>
            I3C_IBI_QUEUE_STATUS_DATA_LENGTH_POS);
}

uint8_t i3c_ll_read_ibi_payload(uint32_t base_addr, uint8_t *payload,
        uint8_t data_len, uint8_t payload_size)
{
    uint8_t read_len;
    uint8_t remaining;
    uint32_t word;
    uint8_t byte_idx;

    read_len = 0U;
    remaining = data_len;

    while (remaining > 0U)
    {
        word = i3c_ll_get_ibi_data(base_addr);
        for (byte_idx = 0U; (byte_idx < 4U) && (remaining > 0U); byte_idx++)
        {
            if ((payload != NULL) && (read_len < payload_size))
            {
                payload[read_len] = (uint8_t)(word & 0xFFU);
            }
            read_len++;
            word >>= 8U;
            remaining--;
        }
    }

    if (read_len > payload_size)
    {
        read_len = payload_size;
    }
    return read_len;
}

/**
 * @brief Program RX/TX threshold values.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in] rx_thld RX threshold.
 * @param[in] tx_thld TX threshold.
 */
static void i3c_ll_set_data_thresholds(uint32_t base_addr, uint32_t rx_thld,
        uint32_t tx_thld)
{
    uint32_t value;

    value = RD_REG32(base_addr + I3C_DATA_BUFFER_THLD_CTRL);
    value &= ~I3C_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD_MASK;
    value |= ((rx_thld << I3C_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD_POS) &
            I3C_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD_MASK);
    value &= ~I3C_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD_MASK;
    value |= ((tx_thld << I3C_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD_POS) &
            I3C_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD_MASK);
    WR_REG32(base_addr + I3C_DATA_BUFFER_THLD_CTRL, value);
}

void i3c_ll_set_default_data_thresholds(uint32_t base_addr)
{
    i3c_ll_set_data_thresholds(base_addr, I3C_DATA_BUFFER_THLD_CTRL_LVL16,
            I3C_DATA_BUFFER_THLD_CTRL_LVL16);
}

void i3c_ll_set_ibi_defaults(uint32_t base_addr)
{
    WR_REG32((base_addr + I3C_IBI_SIR_REQ_REJECT), SIR_REQ_REJECT_MASK);
    WR_REG32((base_addr + I3C_IBI_MR_REQ_REJECT), MR_REQ_REJECT_MASK);
    WR_REG32((base_addr + I3C_IBI_QUEUE_CTRL),
            (I3C_IBI_QUEUE_CTRL_NOTIFY_SIR_REJECTED_MASK |
            I3C_IBI_QUEUE_CTRL_NOTIFY_MR_REJECTED_MASK |
            I3C_IBI_QUEUE_CTRL_NOTIFY_HJ_REJECTED_MASK));
}

/* HAL-accessible transfer command APIs. */

/**
 * @brief Build one transfer command object from payload data.
 *
 * @param[in,out] cmd_obj Command object output.
 * @param[in] tid Transfer ID.
 * @param[in] dev_index DAT index.
 * @param[in] payload Transfer payload.
 * @param[in] is_i2c True for I2C transfer formatting.
 * @param[in] is_last True for final command in batch.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_prepare_xfer_cmd(struct i3c_cmd_obj *cmd_obj, uint8_t tid,
        uint8_t dev_index, const struct i3c_cmd_payload *payload, bool is_i2c,
        bool is_last)
{
    struct i3c_cmd_payload local_payload;

    if ((cmd_obj == NULL) || (payload == NULL))
    {
        return -EINVAL;
    }

    local_payload = *payload;
    return i3c_ll_build_xfer_word(cmd_obj, tid, dev_index, &local_payload,
            is_i2c, is_last);
}

/**
 * @brief Build one address-assignment command object.
 *
 * @param[in,out] cmd_obj Command object output.
 * @param[in] tid Transfer ID.
 * @param[in] cmd_id CCC command ID.
 * @param[in] dev_index DAT index.
 * @param[in] dev_count Device count.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_prepare_addr_assign_cmd(struct i3c_cmd_obj *cmd_obj,
        uint8_t tid, uint8_t cmd_id, uint8_t dev_index, uint8_t dev_count)
{
    return i3c_ll_build_addr_assign_word(cmd_obj, tid, cmd_id, dev_index,
            dev_count);
}

/**
 * @brief Submit prepared command objects to hardware.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in] cmd_obj Command object array.
 * @param[in] num_cmds Number of commands.
 * @param[in] is_addr_cmd True for address-assignment flow.
 */
static void i3c_ll_submit_cmds(uint32_t base_addr, struct i3c_cmd_obj *cmd_obj,
        uint8_t num_cmds, bool is_addr_cmd)
{
    if ((cmd_obj == NULL) || (num_cmds == 0U) || (num_cmds > I3C_MAX_XFER))
    {
        return;
    }

    (void)is_addr_cmd;
    i3c_ll_set_response_threshold(base_addr, (uint8_t)(num_cmds - 1U));
    i3c_ll_queue_xfer_cmd(base_addr, cmd_obj, num_cmds);
}

uint8_t i3c_ll_read_cmd_responses(uint8_t instance, uint32_t base_addr,
        i3c_ll_cmd_response_t *responses, uint8_t max_responses)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;
    uint8_t count;
    uint8_t tid;
    uint32_t response_word;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (responses == NULL) || (max_responses == 0U))
    {
        return 0U;
    }

    count = i3c_ll_get_response_count(base_addr);
    if (count > max_responses)
    {
        count = max_responses;
    }

    for (i = 0U; i < count; i++)
    {
        response_word = i3c_ll_get_response(base_addr);
        responses[i].data_len = (uint16_t)(response_word & 0xFFFFU);
        tid = (uint8_t)((response_word >> 24U) & 0xFU);
        responses[i].tid = tid;
        responses[i].status = (int32_t)((response_word >> 28U) & 0xFU);

        if (tid < I3C_MAX_XFER)
        {
            cmd_obj[tid].rx_length = responses[i].data_len;
            cmd_obj[tid].status = responses[i].status;
        }
    }

    return count;
}

int32_t i3c_ll_prepare_transfer_batch(uint8_t instance,
        const struct i3c_cmd_payload *payloads,
        const uint8_t *dat_indices, uint8_t num_cmds, bool is_i2c)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;
    int32_t ret;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (payloads == NULL) || (dat_indices == NULL) ||
            (num_cmds == 0U) || (num_cmds > I3C_MAX_XFER))
    {
        return -EINVAL;
    }

    for (i = 0U; i < num_cmds; i++)
    {
        (void)memset(&cmd_obj[i], 0, sizeof(cmd_obj[i]));
        ret = i3c_ll_prepare_xfer_cmd(&cmd_obj[i], i, dat_indices[i],
                &payloads[i], is_i2c, (bool)(i == (num_cmds - 1U)));
        if (ret != 0)
        {
            return ret;
        }

        cmd_obj[i].data = payloads[i].data;
        if (payloads[i].read)
        {
            cmd_obj[i].rx_length = payloads[i].data_length;
            cmd_obj[i].read_bytes_left = payloads[i].data_length;
            cmd_obj[i].read_buffer = payloads[i].data;
        }
        else
        {
            cmd_obj[i].tx_length = payloads[i].data_length;
            cmd_obj[i].write_bytes_left = payloads[i].data_length;
            cmd_obj[i].write_buffer = payloads[i].data;
        }
    }

    return 0;
}

void i3c_ll_start_transfer_batch(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;
    uint16_t bytes;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (num_cmds == 0U) || (num_cmds > I3C_MAX_XFER))
    {
        return;
    }

    for (i = 0U; i < num_cmds; i++)
    {
        bytes = i3c_ll_push_tx_fifo(base_addr, cmd_obj[i].data,
                cmd_obj[i].tx_length);
        if (cmd_obj[i].is_read == false)
        {
            cmd_obj[i].write_bytes_left -= bytes;
            if (cmd_obj[i].write_bytes_left > 0U)
            {
                cmd_obj[i].write_buffer += bytes;
                i3c_ll_enable_interrupt(base_addr, I3C_TX_THLD_STS_INTR);
            }
        }
    }

    i3c_ll_submit_cmds(base_addr, cmd_obj, num_cmds, false);
}

uint16_t i3c_ll_get_transfer_rx_length(uint8_t instance, uint8_t tid)
{
    struct i3c_cmd_obj *cmd_obj;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (tid >= I3C_MAX_XFER))
    {
        return 0U;
    }

    return cmd_obj[tid].rx_length;
}

/**
 * @brief Execute SETDASA command using request descriptor.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in,out] cmd_obj Command object output.
 * @param[in] req SETDASA request data.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_execute_setdasa(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj,
        const i3c_ll_dasa_req_t *req)
{
    uint8_t dynamic_addr;
    uint8_t temp_addr;
    uint8_t p;

    if ((cmd_obj == NULL) || (req == NULL))
    {
        return -EINVAL;
    }

    dynamic_addr = (uint8_t)((req->requested_dynamic_addr >> 1U) & I3C_MAX_ADDR);
    p = (dynamic_addr ^ (dynamic_addr >> 4U)) & 0xFU;
    p = ((uint8_t)(0x9669U >> p)) & 0x1U;
    temp_addr = (uint8_t)(dynamic_addr | (uint8_t)(p << 7U));

    (void)memset(cmd_obj, 0, sizeof(*cmd_obj));
    cmd_obj->data = (uint8_t *)&req->requested_dynamic_addr;

    if (i3c_ll_prepare_addr_assign_cmd(cmd_obj, 0U, I3C_CCC_SETDASA_CMD,
            req->dat_index,
            1U) != 0)
    {
        return -EINVAL;
    }

    cmd_obj->arg_word = ((uint32_t)I3C_CCC_SHORT_DATA_ARG & 0x7U) |
            ((uint32_t)temp_addr << 8U);

    i3c_ll_submit_cmds(base_addr, cmd_obj, 1U, true);
    return 0;
}

/**
 * @brief Execute ENTDAA command using request descriptor.
 *
 * @param[in] base_addr I3C controller register base address.
 * @param[in,out] cmd_obj Command object output.
 * @param[in] req ENTDAA request data.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_execute_entdaa(uint32_t base_addr,
        struct i3c_cmd_obj *cmd_obj,
        const i3c_ll_daa_req_t *req)
{
    if ((cmd_obj == NULL) || (req == NULL) ||
            (req->device_count == 0U) ||
            (req->assigned_dynamic_addrs == NULL) ||
            (req->assigned_buf_len < req->device_count))
    {
        return -EINVAL;
    }

    (void)memset(cmd_obj, 0, sizeof(*cmd_obj));
    cmd_obj->data = req->assigned_dynamic_addrs;

    if (i3c_ll_prepare_addr_assign_cmd(cmd_obj, 0U, I3C_CCC_ENTDAA_CMD,
            req->start_dat_index, req->device_count) != 0)
    {
        return -EINVAL;
    }

    i3c_ll_submit_cmds(base_addr, cmd_obj, 1U, true);
    return 0;
}

/* HAL-accessible address-assignment APIs. */

int32_t i3c_ll_submit_addr_assign(uint32_t base_addr,
        uint8_t instance, const i3c_ll_addr_assign_req_t *req)
{
    struct i3c_cmd_obj *cmd_obj;
    i3c_ll_dasa_req_t dasa_req;
    i3c_ll_daa_req_t daa_req;
    int32_t ret;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (req == NULL))
    {
        return -EINVAL;
    }

    if (req->cmd_id == I3C_CCC_SETDASA_CMD)
    {
        if ((req->data == NULL) || (req->data_len != 1U))
        {
            return -EINVAL;
        }

        dasa_req.dat_index = req->start_dat_index;
        dasa_req.requested_dynamic_addr = req->data[0];
        return i3c_ll_execute_setdasa(base_addr, cmd_obj, &dasa_req);
    }

    if (req->cmd_id == I3C_CCC_ENTDAA_CMD)
    {
        if ((req->data == NULL) || (req->data_len == 0U))
        {
            return -EINVAL;
        }

        daa_req.start_dat_index = req->start_dat_index;
        daa_req.device_count = req->data_len;
        daa_req.assigned_dynamic_addrs = req->data;
        daa_req.assigned_buf_len = req->data_len;
        return i3c_ll_execute_entdaa(base_addr, cmd_obj, &daa_req);
    }

    (void)memset(cmd_obj, 0, sizeof(*cmd_obj));
    cmd_obj->data = req->data;
    ret = i3c_ll_prepare_addr_assign_cmd(cmd_obj, 0U, req->cmd_id,
            req->start_dat_index, req->data_len);
    if (ret != 0)
    {
        return ret;
    }

    i3c_ll_submit_cmds(base_addr, cmd_obj, 1U, true);
    return 0;
}

int32_t i3c_ll_complete_addr_assign(uint32_t base_addr,
        uint8_t instance, uint8_t num_cmds)
{
    struct i3c_cmd_obj *cmd_obj;
    uint8_t i;

    cmd_obj = i3c_ll_get_cmd_obj(instance);
    if ((cmd_obj == NULL) || (num_cmds == 0U) || (num_cmds > I3C_MAX_XFER))
    {
        return -EINVAL;
    }

    for (i = 0U; i < num_cmds; i++)
    {
        if (cmd_obj[i].status != I3C_RESPONSE_OK)
        {
            return -EIO;
        }

        if (cmd_obj[i].rx_length > 0U)
        {
            if (cmd_obj[i].data == NULL)
            {
                return -EINVAL;
            }

            if (i3c_ll_read_rx_fifo(base_addr, cmd_obj[i].data,
                    cmd_obj[i].rx_length) == 0U)
            {
                return -EIO;
            }
        }
    }

    return 0;
}

/* Static command-word builder helpers. */


/**
 * @brief Build command and argument words for transfer command.
 *
 * @param[in,out] cmd_obj Command object output.
 * @param[in] tid Transfer ID.
 * @param[in] dev_index DAT index.
 * @param[in,out] payload Transfer payload.
 * @param[in] is_i2c True for I2C transfer formatting.
 * @param[in] is_last True for final command in batch.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_build_xfer_word(struct i3c_cmd_obj *cmd_obj, uint8_t tid,
        uint8_t dev_index, struct i3c_cmd_payload *payload, bool is_i2c,
        bool is_last)
{
    uint32_t cmd_word;
    uint32_t arg_word;

    if ((cmd_obj == NULL) || (payload == NULL))
    {
        return -EINVAL;
    }

    arg_word = 0U;
    arg_word |= ((uint32_t)I3C_CCC_TRANSFER_ARG & 0x7U);
    arg_word |= ((uint32_t)payload->data_length << 16U);

    cmd_word = 0U;
    cmd_word |= ((uint32_t)I3C_CCC_TRANSFER_CMD & 0x7U);
    cmd_word |= ((uint32_t)tid & 0xFU) << 3U;
    cmd_word |= ((uint32_t)payload->cmd_id & 0xFFU) << 7U;
    if (payload->cmd_id != 0U)
    {
        cmd_word |= (1U << 15U);
    }
    cmd_word |= ((uint32_t)dev_index & 0x1FU) << 16U;
    if (is_i2c)
    {
        cmd_word |= (1U << 21U);
    }
    cmd_word |= (1U << 26U);
    cmd_word |= ((payload->read ? 1U : 0U) << 28U);
    cmd_word |= ((is_last ? 1U : 0U) << 30U);

    cmd_obj->arg_word = arg_word;
    cmd_obj->cmd_word = cmd_word;
    cmd_obj->is_read = payload->read;
    return 0;
}

/**
 * @brief Build command and argument words for address-assignment command.
 *
 * @param[in,out] cmd_obj Command object output.
 * @param[in] tid Transfer ID.
 * @param[in] cmd_id CCC command ID.
 * @param[in] dev_index DAT index.
 * @param[in] dev_count Device count.
 * @return 0 on success, negative errno on failure.
 */
static int32_t i3c_ll_build_addr_assign_word(struct i3c_cmd_obj *cmd_obj,
        uint8_t tid, uint8_t cmd_id, uint8_t dev_index, uint8_t dev_count)
{
    uint32_t cmd_word;
    uint32_t arg_word;

    if (cmd_obj == NULL)
    {
        return -EINVAL;
    }

    arg_word = 0U;
    arg_word |= ((uint32_t)I3C_CCC_TRANSFER_ARG & 0x7U);

    cmd_word = 0U;
    cmd_word |= ((uint32_t)I3C_CCC_ADDRESS_ASSIGN_CMD & 0x7U);
    cmd_word |= ((uint32_t)tid & 0xFU) << 3U;
    cmd_word |= ((uint32_t)cmd_id & 0xFFU) << 7U;
    cmd_word |= ((uint32_t)dev_index & 0x1FU) << 16U;
    cmd_word |= ((uint32_t)dev_count & 0x1FU) << 21U;
    cmd_word |= (1U << 26U);
    cmd_word |= (1U << 30U);

    cmd_obj->arg_word = arg_word;
    cmd_obj->cmd_word = cmd_word;
    cmd_obj->is_read = false;
    return 0;
}

/* HAL-accessible controller teardown API. */

int32_t i3c_ll_deinit(uint8_t instance, uint32_t base_addr)
{
    uint32_t value;
    uint32_t mask;
    uint8_t bitpos;

    if (instance >= I3C_NUM_INSTANCES)
    {
        return -EINVAL;
    }

    value = RD_REG32(base_addr + I3C_DEVICE_CTRL);
    value &= ~I3C_DEVICE_CTRL_ENABLE_MASK;
    WR_REG32(base_addr + I3C_DEVICE_CTRL, value);

    bitpos = (uint8_t)(PER1MODRST_I3C0_POS + instance);
    mask = (1U << (uint32_t)bitpos);
    value = RD_REG32(PER1MODRST);
    value |= mask;
    WR_REG32(PER1MODRST, value);

    return 0;
}
