target_sources(socfpga_drivers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_flash.h
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_flash_adapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_flash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_qspi_ll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_qspi.c
    )
target_include_directories(socfpga_drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
