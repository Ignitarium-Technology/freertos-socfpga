cmake_minimum_required(VERSION 3.5...3.28)

#define these for qspi image generation
set(PFG_PATH "${CMAKE_SOURCE_DIR}/initial_image.pfg" CACHE STRING "PFG path")
set(SOF_PATH "${CMAKE_SOURCE_DIR}/ghrd_a5ed065bb32ae6sr0.sof" CACHE STRING "SOF File path")

include(FetchContent)

set(FREERTOS_FATFS y)
set(FREERTOS_USB y)
set(FREERTOS_TCPIP n)
set(FREERTOS_LIBRSU y)
set(FREERTOS_LIBFCS n)

FetchContent_Declare(
    freertos
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/../../
)

# Get the freertos repo
FetchContent_MakeAvailable(freertos)
FetchContent_GetProperties(freertos)

# project
project(rsu_sample C CXX ASM)

set(LINKER_SCRIPT "${freertos_SOURCE_DIR}/lscript.ld")
include(${freertos_SOURCE_DIR}/tools/target_socfpga.cmake)

# target
add_executable(${PROJECT_NAME}.elf)

#Add image generation
generate_bin_file(${PROJECT_NAME}.elf)
add_sd_image(${PROJECT_NAME}.elf)
add_qspi_image(${PROJECT_NAME}.elf ${PFG_PATH} ${SOF_PATH})


# link to the baremetal library
target_link_libraries(${PROJECT_NAME}.elf
    PRIVATE freertos_socfpga
)

file(GLOB SAMPLE_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# sources
target_sources(${PROJECT_NAME}.elf
    PRIVATE main.c ${SAMPLE_SRCS}
)

# specify linker script
target_link_options(${PROJECT_NAME}.elf PRIVATE
    -T${LINKER_SCRIPT}
)

add_custom_command(
    TARGET qspi-image
    POST_BUILD
    COMMAND ${QUARTUS_PFG_EXECUTABLE} -c ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} app2.rpd -o hps_path=./bl2.hex -o mode=ASX4 -o bitswap=ON
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/qspi_atf_binaries
    COMMENT "Generating app2.rpd for QSPI image"
    BYPRODUCTS ${CMAKE_BINARY_DIR}/qspi_atf_binaries/app2.rpd
    DEPENDS
        get_sof_file
        atf-bl2-bl31-qspi
        ${QUARTUS_PFG_EXECUTABLE}
    )
