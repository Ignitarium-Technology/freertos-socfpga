
if(NOT ATF_SOURCE)
    set(ATF_SOURCE ${FREERTOS_TOP_DIR}/tools/ATF CACHE STRING "Path to ATF git repository")
endif()

set(ATF_BUILD_COPY_DIR "${CMAKE_BINARY_DIR}/atf_copy" CACHE STRING "Path to ATF build copy directory")
set(TOOL_DIR "${FREERTOS_TOP_DIR}/tools" CACHE STRING "Path to tools directory")

set(SD_ARTIFACTS_DIR "${CMAKE_BINARY_DIR}/sd_atf_binaries" CACHE STRING "Path to SD artifacts directory")
set(EMMC_ARTIFACTS_DIR "${CMAKE_BINARY_DIR}/emmc_atf_binaries" CACHE STRING "Path to eMMC artifacts directory")
set(QSPI_ARTIFACTS_DIR "${CMAKE_BINARY_DIR}/qspi_atf_binaries" CACHE STRING "Path to QSPI artifacts directory")

add_custom_command(
    OUTPUT ${ATF_BUILD_COPY_DIR}/atf.copy_done
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ATF_BUILD_COPY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ATF_SOURCE} ${ATF_BUILD_COPY_DIR}
    COMMAND ${CMAKE_COMMAND} -E touch ${ATF_BUILD_COPY_DIR}/atf.copy_done
    COMMENT "Copying ATF to build directory"
)

add_custom_target(copy_atf
    DEPENDS ${ATF_BUILD_COPY_DIR}/atf.copy_done
)

if(NOT DEFINED ATF_LOG_LEVEL)
    set(ATF_LOG_LEVEL "25")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ATF_DEBUG_FLAG "1")
    set(ATF_BUILD_DIR "${ATF_BUILD_COPY_DIR}/build/agilex5/debug/")
else()
    set(ATF_DEBUG_FLAG "0")
    set(ATF_BUILD_DIR "${ATF_BUILD_COPY_DIR}/build/agilex5/release/")
endif()

message(STATUS "ATF Log Level : ${ATF_LOG_LEVEL}")

# Add custom target to build ATF
add_custom_target(
    atf-bl2-bl31-qspi
    COMMAND make -C ${ATF_BUILD_COPY_DIR} PLAT=agilex5 clean
    COMMAND make -C ${ATF_BUILD_COPY_DIR} CROSS_COMPILE=${CC_PREFIX} PLAT=agilex5 SOCFPGA_BOOT_SOURCE_QSPI=1 bl2 bl31 PRELOADED_BL33_BASE=0x82000000 LOG_LEVEL=${ATF_LOG_LEVEL} DEBUG=${ATF_DEBUG_FLAG} -j${CMAKE_BUILD_PARALLEL_LEVEL}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${QSPI_ARTIFACTS_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl31.bin ${QSPI_ARTIFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl2.bin ${QSPI_ARTIFACTS_DIR}
    BYPRODUCTS ${QSPI_ARTIFACTS_DIR}/bl31.bin
    BYPRODUCTS ${QSPI_ARTIFACTS_DIR}/bl2.bin
    DEPENDS copy_atf
)

add_custom_target(
    atf-bl2-bl31-sd
    COMMAND sed -i 's/MMC_DEVICE_TYPE[ \t]*0/MMC_DEVICE_TYPE 1/'  ${ATF_BUILD_COPY_DIR}/plat/intel/soc/agilex5/include/socfpga_plat_def.h
    COMMAND make -C ${ATF_BUILD_COPY_DIR} PLAT=agilex5 clean
    COMMAND make -C ${ATF_BUILD_COPY_DIR} CROSS_COMPILE=${CC_PREFIX} PLAT=agilex5 bl2 bl31 PRELOADED_BL33_BASE=0x82000000 LOG_LEVEL=${ATF_LOG_LEVEL} DEBUG=${ATF_DEBUG_FLAG} -j${CMAKE_BUILD_PARALLEL_LEVEL}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${SD_ARTIFACTS_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl31.bin ${SD_ARTIFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl2.bin ${SD_ARTIFACTS_DIR}
    BYPRODUCTS ${SD_ARTIFACTS_DIR}/bl31.bin
    BYPRODUCTS ${SD_ARTIFACTS_DIR}/bl2.bin
    DEPENDS copy_atf
)

add_custom_target(
    atf-bl2-bl31-emmc
    COMMAND sed -i 's/MMC_DEVICE_TYPE[ \t]*1/MMC_DEVICE_TYPE 0/'  ${ATF_BUILD_COPY_DIR}/plat/intel/soc/agilex5/include/socfpga_plat_def.h
    COMMAND make -C ${ATF_BUILD_COPY_DIR} PLAT=agilex5 clean
    COMMAND make -C ${ATF_BUILD_COPY_DIR} CROSS_COMPILE=${CC_PREFIX} PLAT=agilex5 bl2 bl31 PRELOADED_BL33_BASE=0x82000000 LOG_LEVEL=${ATF_LOG_LEVEL} DEBUG=${ATF_DEBUG_FLAG} -j${CMAKE_BUILD_PARALLEL_LEVEL}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${EMMC_ARTIFACTS_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl31.bin ${EMMC_ARTIFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_DIR}/bl2.bin ${EMMC_ARTIFACTS_DIR}
    BYPRODUCTS ${EMMC_ARTIFACTS_DIR}/bl31.bin
    BYPRODUCTS ${EMMC_ARTIFACTS_DIR}/bl2.bin
    DEPENDS copy_atf
)

add_custom_command(
    COMMAND make -C ${ATF_BUILD_COPY_DIR} fiptool
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ATF_BUILD_COPY_DIR}/tools/fiptool/fiptool ${CMAKE_BINARY_DIR}/fiptool
    OUTPUT ${CMAKE_BINARY_DIR}/fiptool
    VERBATIM
    )

add_custom_target(
    atf-fiptool
    DEPENDS ${CMAKE_BINARY_DIR}/fiptool
    DEPENDS copy_atf
)

function(generate_bin_file target_name)
    if(target_name MATCHES "\\.elf$")
        string(REGEX REPLACE "\\.elf$" ".bin" BIN_FILE "${target_name}")
    else()
        set(BIN_FILE "${target_name}.bin")
    endif()
    string(REGEX REPLACE ".bin" ".asm" ASM_FILE ${BIN_FILE})
    add_custom_command(
        TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O binary ${target_name} ${BIN_FILE}
        COMMAND ${CMAKE_OBJDUMP} -D ${target_name} >  ${ASM_FILE}
        COMMENT "Generating ${BIN_FILE} and ${ASM_FILE} from ${target_name}"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/
    )
    add_custom_target(${BIN_FILE} DEPENDS ${target_name})
endfunction()

find_program(QUARTUS_PFG_EXECUTABLE
    NAMES quartus_pfg
    HINTS $ENV{QUARTUS_ROOTDIR}/bin
)

if(QUARTUS_PFG_EXECUTABLE)
    message(STATUS "Found quartus_pfg: ${QUARTUS_PFG_EXECUTABLE}")
    execute_process(
        COMMAND "${QUARTUS_PFG_EXECUTABLE}" --version
        RESULT_VARIABLE PFG_RESULT
        OUTPUT_VARIABLE PFG_VERSION
        ERROR_VARIABLE PFG_ERROR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_STRIP_TRAILING_WHITESPACE
    )
    if(PFG_RESULT EQUAL 0)
        string(REGEX MATCH "Version ([0-9]+\\.[0-9]+\\.[0-9]+)" _match "${PFG_VERSION}")
        set(PFG_VERSION_NUMBER "${CMAKE_MATCH_1}")
        message(STATUS "quartus_pfg version: ${PFG_VERSION_NUMBER}")
    endif()
endif()

set(SOCFPGA_SOF_FILE "ghrd_a5ed065bb32ae6sr0.sof" CACHE STRING "Name of the SOF file to be used for the FPGA")
set(SOCFPGA_PFG_FILE "qspi_flash_image_agilex5_boot.pfg" CACHE STRING "Name of the PFG file to be used for the FPGA")

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE}
    COMMAND /bin/sh -c "if [ ! -f '${SOF_PATH}' ]; then echo '${SOF_PATH} does not exist';exit 1; else echo '${SOF_PATH} exists, copying to build directory'; cp '${SOF_PATH}' ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE}; fi"
    VERBATIM
)

add_custom_target(get_sof_file
    DEPENDS ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE}
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/${SOCFPGA_PFG_FILE}
    COMMAND /bin/sh -c "if [ ! -f '${PFG_PATH}' ]; then echo '${PFG_PATH} does not exist. Use the default pfg file.';cp '${TOOL_DIR}/${SOCFPGA_PFG_FILE}' ${CMAKE_BINARY_DIR}/; else echo '${PFG_PATH} exists, skipping download'; cp '${PFG_PATH}' ${CMAKE_BINARY_DIR}/${SOCFPGA_PFG_FILE}; fi"
    VERBATIM
)

add_custom_target(get_pfg_file
        DEPENDS ${CMAKE_BINARY_DIR}/${SOCFPGA_PFG_FILE}
    )

function(add_sd_image executable_name)
    if(executable_name MATCHES "\\.elf$")
        string(REGEX REPLACE "\\.elf$" ".bin" BIN_FILE "${executable_name}")
    else()
        set(BIN_FILE "${executable_name}.bin")
    endif()
    string(REGEX REPLACE ".bin" "" TARG_NAME ${BIN_FILE})
    set(FIP_FILE "fip.bin")
    set(FIPTOOL_BIN ${CMAKE_BINARY_DIR}/fiptool)
    set(SD_BL31_BIN ${SD_ARTIFACTS_DIR}/bl31.bin)
    set(SD_BL2_BIN ${SD_ARTIFACTS_DIR}/bl2.bin)

    set(EMMC_BL31_BIN ${EMMC_ARTIFACTS_DIR}/bl31.bin)
    set(EMMC_BL2_BIN ${EMMC_ARTIFACTS_DIR}/bl2.bin)

    add_custom_target(
        sd-image
        COMMAND ${FIPTOOL_BIN} create --soc-fw ${SD_BL31_BIN} --nt-fw ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} ${SD_ARTIFACTS_DIR}/${FIP_FILE}
        COMMAND rm -f sd.img
        COMMAND ${CMAKE_OBJCOPY} -v -I binary -O ihex --change-addresses 0x0 ${SD_BL2_BIN} bl2.hex
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} ${SOCFPGA_SOF_FILE}
        COMMENT "Generating core.rbf from sof"
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c -o hps_path=bl2.hex ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} fsbl.sof
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c fsbl.sof ghrd.rbf -o hps=ON -o hps_path=bl2.hex
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/fatfs"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SD_ARTIFACTS_DIR}/ghrd.core.rbf ${CMAKE_BINARY_DIR}/fatfs/core.rbf
        COMMAND sudo python3 ${TOOL_DIR}/make_sdimage_p3.py -f -P fip.bin,num=2,format=raw,size=64M,type=a2 -P ${CMAKE_BINARY_DIR}/fatfs/*,num=1,format=fat,size=64M -s 128M -n sd.img
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TOOL_DIR}/qspi_flash_image_agilex5_boot_sdmmc.pfg ${SD_ARTIFACTS_DIR}
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c ${SD_ARTIFACTS_DIR}/qspi_flash_image_agilex5_boot_sdmmc.pfg
        WORKING_DIRECTORY ${SD_ARTIFACTS_DIR}
        DEPENDS ${executable_name}
                ${BIN_FILE}
                get_sof_file
                atf-bl2-bl31-sd
                atf-fiptool
                ${QUARTUS_PFG_EXECUTABLE}
        BYPRODUCTS sd.img fsbl.sof
    )

    add_custom_target(
        emmc-image
        COMMAND ${FIPTOOL_BIN} create --soc-fw ${EMMC_BL31_BIN} --nt-fw ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} ${EMMC_ARTIFACTS_DIR}/${FIP_FILE}
        COMMAND rm -f sd_emmc.img
        COMMAND ${CMAKE_OBJCOPY} -v -I binary -O ihex --change-addresses 0x0 ${EMMC_BL2_BIN} bl2.hex
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} ${SOCFPGA_SOF_FILE}
        COMMENT "Generating core.rbf from sof"
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c -o hps_path=bl2.hex ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} fsbl.sof
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c fsbl.sof ghrd.rbf -o hps=ON -o hps_path=bl2.hex
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/fatfs"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${EMMC_ARTIFACTS_DIR}/ghrd.core.rbf ${CMAKE_BINARY_DIR}/fatfs/core.rbf
        COMMAND sudo python3 ${TOOL_DIR}/make_sdimage_p3.py -f -P fip.bin,num=2,format=raw,size=64M,type=a2 -P ${CMAKE_BINARY_DIR}/fatfs/*,num=1,format=fat,size=64M -s 128M -n sd_emmc.img
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TOOL_DIR}/qspi_flash_image_agilex5_boot_sdmmc.pfg ${EMMC_ARTIFACTS_DIR}
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c ${EMMC_ARTIFACTS_DIR}/qspi_flash_image_agilex5_boot_sdmmc.pfg
        WORKING_DIRECTORY ${EMMC_ARTIFACTS_DIR}
        DEPENDS ${executable_name}
                ${BIN_FILE}
                get_sof_file
                atf-bl2-bl31-emmc
                atf-fiptool
                ${QUARTUS_PFG_EXECUTABLE}
        BYPRODUCTS sd_emmc.img
    )
endfunction()

function(add_qspi_image executable_name pfg_file sof_file)
    if(executable_name MATCHES "\\.elf$")
        string(REGEX REPLACE "\\.elf$" ".bin" BIN_FILE "${executable_name}")
    else()
        set(BIN_FILE "${executable_name}.bin")
    endif()
    string(REGEX REPLACE ".bin" "" TARG_NAME ${BIN_FILE})
    set(FIP_FILE "fip.bin")
    set(FIPTOOL_BIN ${CMAKE_BINARY_DIR}/fiptool)
    set(BL31_BIN ${QSPI_ARTIFACTS_DIR}/bl31.bin)
    set(BL2_BIN ${QSPI_ARTIFACTS_DIR}/bl2.bin)

    add_custom_target(
        qspi-image
        COMMAND ${CMAKE_COMMAND} -E echo "${Yellow}Using pfg file : ${CMAKE_BINARY_DIR}/${SOCFPGA_PFG_FILE} ${ColourReset}"
        COMMAND ${CMAKE_COMMAND} -E echo "${Yellow}Using sof file : ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} ${ColourReset}"
        COMMAND ${FIPTOOL_BIN} create --soc-fw ${BL31_BIN} --nt-fw ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} ${QSPI_ARTIFACTS_DIR}/${FIP_FILE}
        COMMAND ${CMAKE_OBJCOPY} -I binary -O ihex --change-addresses 0x0 ${BL2_BIN} bl2.hex
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} ${QSPI_ARTIFACTS_DIR}/${SOCFPGA_SOF_FILE}
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c ${CMAKE_BINARY_DIR}/${SOCFPGA_PFG_FILE}
        COMMENT "Generating core.rbf from sof"
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c -o hps_path=bl2.hex ${CMAKE_BINARY_DIR}/${SOCFPGA_SOF_FILE} fsbl.sof
        COMMAND ${QUARTUS_PFG_EXECUTABLE} -c fsbl.sof ghrd.rbf -o hps=ON -o hps_path=bl2.hex
        WORKING_DIRECTORY ${QSPI_ARTIFACTS_DIR}
        DEPENDS ${executable_name}
                ${BIN_FILE}
                get_sof_file
                get_pfg_file
                atf-bl2-bl31-qspi
                atf-fiptool
                ${QUARTUS_PFG_EXECUTABLE}
        BYPRODUCTS qspi_image.jic
    )
endfunction()
