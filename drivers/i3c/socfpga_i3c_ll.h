/**
 * SPDX-FileCopyrightText: Copyright (C) 2025-2026 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Header file for I3C low level driver
 */
#ifndef __SOCFPGA_I3C_LL_H__
#define __SOCFPGA_I3C_LL_H__

#include <stdint.h>
#include <stdbool.h>
#include "socfpga_i3c.h"

/**
 * @brief I3C core clock source frequency.
 */
#define I3C_CORE_CLOCK    (200U * MHZ)

#define I3C_MAX_DEVICES    (8U)
#define I3C_MAX_XFER       (16U)

#define I3C_CONTROLLER_REGISTER_BASE(inst)    (((inst) == I3C_INSTANCE1) \
    ? 0x10DA0000   \
    : 0x10DA1000)

#define GET_I3C_INTERRUPT_ID(instance)    (((instance) == I3C_INSTANCE1) \
    ? I3C0IRQ : I3C1IRQ)

#define I3C_IBI_MR_REQ_REJECT     (0x2CU)
#define I3C_IBI_SIR_REQ_REJECT    (0x30U)

/* IBI MR Req reject register*/
#define MR_REQ_REJECT_POS     (0U)
#define MR_REQ_REJECT_LEN     (32U)
#define MR_REQ_REJECT_MASK    (0xFFFFFFFFUL)

/* IBI SIR Req reject register*/
#define SIR_REQ_REJECT_POS     (0U)
#define SIR_REQ_REJECT_LEN     (32U)
#define SIR_REQ_REJECT_MASK    (0xFFFFFFFFUL)

/* HAL-facing interrupt status flags */
#define I3C_TX_THLD_STS_INTR      (1U << 0)
#define I3C_RX_THLD_STS_INTR      (1U << 1)
#define I3C_RESP_READY_STS_INTR   (1U << 2)
#define I3C_TRANSFER_ERR_STS_INTR (1U << 3)
#define I3C_IBI_THLD_STS_INTR     (1U << 4)
#define I3C_ALL_STS_INTR          (I3C_TX_THLD_STS_INTR | I3C_RX_THLD_STS_INTR | \
                                   I3C_RESP_READY_STS_INTR | I3C_TRANSFER_ERR_STS_INTR | \
                                   I3C_IBI_THLD_STS_INTR)

/* Number of bytes in RX/TX data port entry. */
#define RX_TX_DATA_PORT_SIZE    (4U)

/*Reset manager peripheral reset register*/
#define PER1MODRST              (0x10D11028U)
#define PER1MODRST_I3C0_POS     (13U)
#define PER1MODRST_I3C0_MASK    ((0x1U << PER1MODRST_I3C0_POS))

#define PER1MODRST_I3C1_POS     (14U)
#define PER1MODRST_I3C1_MASK    ((0x1U << PER1MODRST_I3C1_POS))
#define I3C_DAT_DEVICE_BIT_POS  (31U)
#define I3C_MAX_ADDR          (0x7FU)
#define I3C_BROADCAST_ADDR    (0x7EU)

#define I3C_CCC_SETDASA_CMD   (0x87U)
#define I3C_CCC_ENTDAA_CMD    (0x07U)

#define NUM_BITS_PER_TABLE_ENTRY    ((sizeof(uint32_t) * 8U))

#define SCL_I3C_TIMING_CNT_MIN    (5U)

/* I3c Bus timing rates*/
#define I3C_BUS_SDR1_SCL_RATE          (8000000U)
#define I3C_BUS_SDR2_SCL_RATE          (6000000U)
#define I3C_BUS_SDR3_SCL_RATE          (4000000U)
#define I3C_BUS_SDR4_SCL_RATE          (2000000U)
#define I3C_BUS_I2C_FM_TLOW_MIN_NS     (1300U)
#define I3C_BUS_I2C_FMP_TLOW_MIN_NS    (500U)
#define I3C_BUS_THIGH_MAX_NS           (41U)

#define I3C_BUS_TYP_I3C_SCL_RATE        (12500000U)
#define I3C_BUS_I2C_FM_PLUS_SCL_RATE    (1000000U)
#define I3C_BUS_I2C_FM_SCL_RATE         (400000U)
#define I3C_BUS_TLOW_OD_MIN_NS          (200U)

/* values specifying the entries in the Address allotment table*/
#define ADDRESS_ENTRY_STATUS_FREE    0U
#define ADDRESS_ENTRY_STATUS_I3C     1U
#define ADDRESS_ENTRY_STATUS_I2C     2U
#define ADDRESS_ENTRY_STATUS_RSVD    3U
#define ADDRESS_ENTRY_STATUS_MAX     3U

#define I3C_CONTROLLER_MASTER                      1U

/*Internal error codes*/
#define I3C_OK          0
#define I3C_DENIED      1
#define I3C_TIMEDOUT    2
#define I3C_IO          3
#define I3C_NOMEM       4
#define I3C_BUSY        5
#define I3C_INVALID     6
#define I3C_PARAM       7

/* I3C command response values*/
#define I3C_RESPONSE_OK                  0
#define I3C_RESPONSE_CRC_ERROR           1
#define I3C_RESPONSE_PARITY_ERROR        2
#define I3C_RESPONSE_FRAME_ERROR         3
#define I3C_RESPONSE_BRAODCAST_NAK       4
#define I3C_RESPONSE_ADDRESS_NAK         5
#define I3C_RESPONSE_BUF_OVERFLOW        6
#define I3C_RESPONSE_RESERVED_7          7
#define I3C_RESPONSE_XFER_ABORT          8
#define I3C_RESPONSE_SLAVE_WRITE_NACK    9
#define I3C_RESPONSE_RESERVED_10         10
#define I3C_RESPONSE_RESERVED_11         11
#define I3C_RESPONSE_PEC_ERROR           12
#define I3C_RESPONSE_RESERVED_13         13
#define I3C_RESPONSE_RESERVED_14         14
#define I3C_RESPONSE_RESERVED_15         15

/**
 * @brief Command payload structure.
 *
 * The I3C driver uses this structure to pass CCC command information
 * to the underlying low-level driver API.
 */
struct i3c_cmd_payload
{
    /* CCC command code. */
    uint8_t cmd_id;

    /* Set true for read command, false for write command. */
    bool read;

    /* Pointer to transfer payload data. */
    uint8_t *data;

    /* Number of payload bytes in data. */
    uint16_t data_length;

    /* Target address. Set to 0 for broadcast command. */
    uint8_t target_addr;
};

/*
 * HAL/LL boundary (Phase 1):
 * - HAL owns transfer orchestration and ISR decision logic.
 * - LL owns register encoding/decoding details.
 * - HAL should not directly parse raw response words.
 */
typedef struct
{
    uint8_t tid;
    uint16_t data_len;
    int32_t status;
} i3c_ll_cmd_response_t;

uint8_t i3c_ll_read_cmd_responses(uint8_t instance, uint32_t base_addr,
        i3c_ll_cmd_response_t *responses, uint8_t max_responses);

int32_t i3c_ll_prepare_transfer_batch(uint8_t instance,
        const struct i3c_cmd_payload *payloads,
        const uint8_t *dat_indices, uint8_t num_cmds, bool is_i2c);

void i3c_ll_start_transfer_batch(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds);

uint16_t i3c_ll_get_transfer_rx_length(uint8_t instance, uint8_t tid);

typedef struct
{
    uint8_t cmd_id;
    uint8_t start_dat_index;
    uint8_t *data;
    uint8_t data_len;
} i3c_ll_addr_assign_req_t;

int32_t i3c_ll_submit_addr_assign(uint32_t base_addr,
        uint8_t instance, const i3c_ll_addr_assign_req_t *req);

int32_t i3c_ll_complete_addr_assign(uint32_t base_addr,
        uint8_t instance, uint8_t num_cmds);

/**
 * @brief I3C controller context data.
 *
 * Holds attached device information, configuration parameters,
 * controller role, and bookkeeping data.
 */
struct i3c_device_desc
{

    struct i3c_device device;

    uint32_t dat_index;

    /* Bus characteristics register value. */
    uint8_t BCR;

    /* Device characteristics register value. */
    uint8_t DCR;

    struct
    {
        /* Maximum read speed. */
        uint8_t max_read;

        /* Maximum write speed. */
        uint8_t max_write;

        /* Maximum turnaround time for read. */
        uint32_t max_read_turnaround;
    } data_speed;

    struct
    {
        /* Maximum read length. */
        uint16_t mrl;

        /* Maximum write length. */
        uint16_t mwl;

        /* Maximum IBI payload size. Valid only if BCR[2] is set. */
        uint8_t max_ibi;
    } data_length;
};

int32_t i3c_ll_init(uint8_t instance, uint8_t own_da, uint32_t *base_addr,
        uint32_t *dat_base, uint32_t *dct_base, uint32_t *cmd_fifo_depth,
        uint32_t *data_fifo_depth, bool *is_primary);

uint16_t i3c_ll_push_tx_fifo(uint32_t base_addr, uint8_t *data,
        uint16_t length);

uint16_t i3c_ll_read_rx_fifo(uint32_t base_addr, uint8_t *data,
        uint16_t length);

void i3c_ll_service_transfer_thresholds(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds, uint32_t intr_status);

void i3c_ll_complete_read_transfers(uint8_t instance, uint32_t base_addr,
        uint8_t num_cmds);

int32_t i3c_ll_attach_dat_i2c(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint8_t addr, uint32_t *dat_index);

int32_t i3c_ll_attach_dat_i3c(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint8_t addr, uint32_t *dat_index);

int32_t i3c_ll_detach_dat(uint8_t instance, uint32_t base_addr,
        uint32_t dat_base, uint32_t dat_index, uint8_t addr);

void i3c_ll_reset_dat_slots(uint8_t instance);

int32_t i3c_ll_configure_ibi(uint32_t base_addr, uint32_t dat_base,
        uint32_t dat_index, uint8_t dynamic_addr, bool enable,
        bool ibi_with_data);

uint32_t i3c_ll_get_intr_status(uint32_t base_addr);

void i3c_ll_clear_intr_status(uint32_t base_addr, uint32_t mask);

void i3c_ll_enable_interrupt(uint32_t base_addr, uint32_t mask);

void i3c_ll_disable_interrupt(uint32_t base_addr, uint32_t mask);

void i3c_ll_reset_queues(uint32_t base_addr);

void i3c_ll_resume(uint32_t base_addr);

uint32_t i3c_ll_get_ibi_status(uint32_t base_addr);

uint32_t i3c_ll_get_ibi_count(uint32_t base_addr);

void i3c_ll_get_ibi_fields(uint32_t value, uint8_t *ibi_sts,
        uint8_t *ibi_id, uint8_t *data_len);

uint8_t i3c_ll_read_ibi_payload(uint32_t base_addr, uint8_t *payload,
        uint8_t data_len, uint8_t payload_size);

void i3c_ll_set_default_data_thresholds(uint32_t base_addr);

void i3c_ll_set_ibi_defaults(uint32_t base_addr);

int32_t i3c_ll_deinit(uint8_t instance, uint32_t base_addr);

#endif
