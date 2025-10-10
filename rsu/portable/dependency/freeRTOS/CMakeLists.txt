# SPDX-License-Identifier: MIT-0
# Copyright (C) 2025 Altera Corporation

cmake_minimum_required(VERSION 3.24)

target_include_directories(uniLibRSU PUBLIC "include")
target_sources(uniLibRSU PRIVATE "RSU_osal_freeRTOS.c")
target_sources(uniLibRSU PRIVATE "RSU_logging_freeRTOS.c")

set_target_properties(uniLibRSU PROPERTIES PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/RSU_OSAL_types.h")
