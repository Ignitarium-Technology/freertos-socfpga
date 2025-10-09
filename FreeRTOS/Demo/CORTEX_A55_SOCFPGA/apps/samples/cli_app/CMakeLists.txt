cmake_minimum_required(VERSION 3.5...3.28)

#define these for qspi image generation
set(PFG_PATH "null" CACHE STRING "PFG path")
set(SOF_PATH "${CMAKE_SOURCE_DIR}/ghrd_a5ed065bb32ae6sr0.sof" CACHE STRING "SOF File path")

include(FetchContent)

set(FREERTOS_CLI y)
set(FREERTOS_FATFS y)
set(FREERTOS_USB y)
set(FREERTOS_TCPIP y)
set(FREERTOS_LIBRSU y)
set(FREERTOS_LIBFCS y)

FetchContent_Declare(
    freertos
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/../../../../../..
)

# Get the freertos repo
FetchContent_MakeAvailable(freertos)
FetchContent_GetProperties(freertos)

# project
project(cli_app C CXX ASM)

set(LINKER_SCRIPT "${freertos_SOURCE_DIR}/lscript.ld")
include(${freertos_SOURCE_DIR}/tools/target_socfpga.cmake)

# target
add_executable(${PROJECT_NAME}.elf)
generate_bin_file(${PROJECT_NAME}.elf)

add_sd_image(${PROJECT_NAME}.elf)
add_qspi_image(${PROJECT_NAME}.elf ${PFG_PATH} ${SOF_PATH})

file(GLOB CLI_APP_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

target_include_directories(${PROJECT_NAME}.elf
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

set(MAIN_SOURCE_SRCS_CLI
    ${CLI_APP_SRCS}
    )

target_link_libraries(${PROJECT_NAME}.elf
    PRIVATE freertos_socfpga
)

# sources
target_sources(${PROJECT_NAME}.elf
    PRIVATE main.c
    ${MAIN_SOURCE_SRCS_CLI}
)

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -T${LINKER_SCRIPT}
)
