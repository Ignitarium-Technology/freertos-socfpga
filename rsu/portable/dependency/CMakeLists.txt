# SPDX-License-Identifier: MIT-0
# Copyright (C) 2023-2024 Intel Corporation
cmake_minimum_required(VERSION 3.24)

include(FetchContent)

add_subdirectory(freeRTOS)
target_sources(uniLibRSU PRIVATE "rsu_crc32.c")
target_sources(uniLibRSU PRIVATE "rsu_crc32_def.c")
target_sources(uniLibRSU PRIVATE "rsu_mailbox_ops.c")
target_sources(uniLibRSU PRIVATE "rsu_qspi_ops.c")
target_sources(uniLibRSU PRIVATE "rsu_file_ops.c")
target_sources(uniLibRSU PRIVATE "rsu_misc_ops.c")
target_sources(uniLibRSU PRIVATE
    ${MAIN_SOURCE_SRCS}
    $<TARGET_OBJECTS:socfpga_drivers>
    )
