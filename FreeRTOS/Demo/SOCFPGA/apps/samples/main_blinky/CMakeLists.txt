cmake_minimum_required(VERSION 3.5...3.28)

#define these for qspi image generation

include(${CMAKE_CURRENT_SOURCE_DIR}/../../download_dep.cmake)

include(FetchContent)

set(FREERTOS_FATFS n)
set(FREERTOS_USB n)
set(FREERTOS_TCPIP n)
set(FREERTOS_LIBRSU n)
set(FREERTOS_LIBFCS n)

FetchContent_Declare(
    freertos
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/../../../../../..
)

# Get the freertos repo
FetchContent_MakeAvailable(freertos)

# project
project(freertos_main_blinky C CXX ASM)

set(LINKER_SCRIPT "${freertos_SOURCE_DIR}/lscript.ld")
include(${freertos_SOURCE_DIR}/tools/target_socfpga.cmake)

# targets to be built
add_executable(${PROJECT_NAME}.elf)
generate_bin_file(${PROJECT_NAME}.elf)
add_sd_image(${PROJECT_NAME}.elf)
add_qspi_image(${PROJECT_NAME}.elf)

target_include_directories(${PROJECT_NAME}.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common/include
    ${CMAKE_CURRENT_SOURCE_DIR}/
    )

# link to the baremetal library
target_link_libraries(${PROJECT_NAME}.elf
    PRIVATE freertos_socfpga
)

target_sources(${PROJECT_NAME}.elf
    PRIVATE
    main.c
    main_blinky.c
)

# specify linker script
target_link_options(${PROJECT_NAME}.elf PRIVATE
    -T ${LINKER_SCRIPT}
)
