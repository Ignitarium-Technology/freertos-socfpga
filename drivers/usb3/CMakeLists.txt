FILE(GLOB USB_HOST_SRCS host/*.c)

target_sources(socfpga_drivers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dwc3/dwc3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dwc3/dwc3_ll.c
    ${USB_HOST_SRCS}
    )

target_include_directories(socfpga_drivers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/host
    ${CMAKE_CURRENT_SOURCE_DIR}/dwc3
    ${FREERTOS_TOP_DIR}/tinyusb/src/common
    )
