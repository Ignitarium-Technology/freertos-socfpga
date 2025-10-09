target_sources(socfpga_drivers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_i2c_ll.c
    )

target_include_directories(socfpga_drivers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
