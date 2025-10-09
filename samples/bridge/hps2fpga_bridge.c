/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of HPS2FPGA bridge sample application
 */

#include "bridge_sample.h"
#include "osal_log.h"

int hps2fpga_bridge_sample(void)
{
    uint64_t *first_word_ptr;
    uint64_t *last_word_ptr;
    uint64_t first_word_write_value;
    uint64_t last_word_write_value;
    uint64_t first_word_read_value;
    uint64_t last_word_read_value;

    /* initialize pointers to first and last word of spans */
    first_word_ptr = (uint64_t *)(H2F_1G_BASE);
    last_word_ptr = (uint64_t *)(H2F_1G_BASE + H2F_1G_SPAN - sizeof(uint64_t));

    /* initialize write data patterns */
    first_word_write_value = 0x1111111111111111;
    last_word_write_value = 0x2222222222222222;

    PRINT("Write data");
    PRINT("buffer 1 : %lx", first_word_write_value);
    PRINT("buffer 2 : %lx", last_word_write_value);

    /* write values to first and last word of each span and read back */
    PRINT("Writing data to memory %p", first_word_ptr);
    *first_word_ptr = first_word_write_value;

    PRINT("Writing data to memory %p", last_word_ptr);
    *last_word_ptr = last_word_write_value;


    /* read from first word */
    PRINT("Reading data from memory %p", first_word_ptr);
    first_word_read_value = *first_word_ptr;

    PRINT("Reading data from memory %p", last_word_ptr);
    last_word_read_value = *last_word_ptr;

    PRINT("Read data");
    PRINT("buffer 1 : %lx", first_word_read_value);
    PRINT("buffer 2 : %lx", last_word_read_value);

    PRINT("Validating the buffers");

    /* Compare read and write buffers */
    if ((first_word_read_value != first_word_write_value) ||
            (last_word_read_value != last_word_write_value))
    {
        ERROR("Buffer Comparison failed");
        return -1;
    }
    PRINT("Buffer validation successful");

    return 0;
}

