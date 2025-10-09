set(PLATFORM freertos)
set(CROSS_COMPILE aarch64-none-elf)
set(FREERTOS_TOOLCHAIN TOOLCHAIN)

add_subdirectory(libfcs)
add_subdirectory(portable)
target_link_libraries(FCS PUBLIC freertos_kernel socfpga_drivers)

