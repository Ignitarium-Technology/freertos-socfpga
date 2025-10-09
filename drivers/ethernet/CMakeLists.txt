target_sources(socfpga_drivers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_xgmac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_xgmac_phy_ll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_xgmac_ll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/socfpga_xgmac_phy.c
    )

target_include_directories(socfpga_drivers PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
