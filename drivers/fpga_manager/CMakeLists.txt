target_sources(socfpga_drivers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_fpga_manager.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_freeze_ip.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_freeze_ip_ll.c
    )

target_include_directories(socfpga_drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
