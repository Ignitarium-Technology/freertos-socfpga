add_library(freertos_plus_tcp_network_if STATIC)

target_sources(freertos_plus_tcp_network_if
  PRIVATE
  NetworkInterface.c
  )

target_include_directories(freertos_plus_tcp_network_if
   PUBLIC
   .
   ${PROJECT_SOURCE_DIR}/drivers/ethernet/
   ${PROJECT_SOURCE_DIR}/drivers/common/
   ${PROJECT_SOURCE_DIR}/osal/freertos/
   ${PROJECT_SOURCE_DIR}/FreeRTOS/FreeRTOS-Plus/Source/Utilities/logging/
   ${PROJECT_SOURCE_DIR}/FreeRTOS/FreeRTOS-Plus/Source/FreeRTOS-Plus-TCP/source/include/
   )

target_link_libraries(freertos_plus_tcp_network_if
    PUBLIC
    freertos_plus_tcp_port
    freertos_plus_tcp_network_if_common
    PRIVATE
    freertos_kernel
    freertos_plus_tcp
    socfpga_drivers
    )
