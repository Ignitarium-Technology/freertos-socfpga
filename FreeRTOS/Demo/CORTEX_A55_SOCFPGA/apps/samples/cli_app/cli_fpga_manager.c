/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for FPGA configuration manager
 */

/**
 * @defgroup cli_fpga_manager FPGA Manager
 * @ingroup cli
 *
 * Perform FPGA operations
 *
 * @details
 * It supports the following subcommands:
 * - fpga load &lt;bitstream_file&gt; [file_source]
 * - fpga pr   &lt;bitstream_file&gt; [file_source]
 * - fpga read &lt;address&gt;
 * - fpga help
 *
 * Typical usage:
 * - Use 'fpga load' command to load the FPGA bitstream.
 * - Use 'fpga pr'   command to perform partial reconfiguration of an FPGA PR region.
 * - Use 'fpga read' command to read data from the FPGA memory region.
 *
 * @section fpga_commands Commands
 * @subsection fpga_load fpga load
 * Load FPGA bitstream  <br>
 *
 * Usage:  <br>
 *   fpga load &lt;bitstream_file&gt; [file_source]  <br>
 *
 * It requires the following arguments:
 * - bitstream_file - The bitstream file name (rbf).  <br>
 * - file_source    - The RBF file source location [default: sdmmc]. Other valid options are:  <br>
 *   - 0 - SDMMC  <br>
 *   - 1 - USB3 disk  <br>
 *
 * @subsection fpga_pr fpga pr
 * Perform partial reconfiguration  <br>
 *
 * Usage:  <br>
 *   fpga pr &lt;bitstream_file&gt; [file_source]  <br>
 *
 * It requires the following arguments:
 * - bitstream_file - The bitstream file name (rbf).  <br>
 * - file_source    - The RBF file source location [default: sdmmc]. Other valid options are:  <br>
 *   - 0 - SDMMC  <br>
 *   - 1 - USB3 disk  <br>
 *   - 2 - USB2 disk  <br>
 *
 * @subsection fpga_read fpga read
 * Read data from FPGA memory region  <br>
 *
 * Usage:  <br>
 *   fpga read &lt;address&gt;  <br>
 *
 * It requires the following arguments:
 * - address - The memory address in the FPGA region.  <br>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "socfpga_fpga_manager.h"
#include "socfpga_mmc.h"
#include "osal.h"
#include "osal_log.h"
#include "socfpga_freeze_ip.h"
#include "socfpga_defines.h"

BaseType_t cmd_fpga_manager( char *write_buffer, size_t write_buffer_len,
        const char *command_string );

/*
 * @func  : cmd_fpga_manager
 * @brief : fpga manager CLI
 */
BaseType_t cmd_fpga_manager( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    BaseType_t parameter1_str_len, parameter2_str_len,
            parameter3_str_len;
    const char *parameter1, *parameter2, *parameter3;
    char *space_pos;

    (void) write_buffer;
    (void) write_buffer_len;

    int media_src;
    char rbf_file[32] = "/";
    uint8_t *rbf_ptr;
    uint32_t file_size;
    media_source_t rbf_media_src;

    parameter1 = FreeRTOS_CLIGetParameter(
            command_string,
            1,
            &parameter1_str_len);

    parameter2 = FreeRTOS_CLIGetParameter(
            command_string,
            2,
            &parameter2_str_len);

    parameter3 = FreeRTOS_CLIGetParameter(
            command_string,
            3,
            &parameter3_str_len);

    space_pos = strchr(parameter1, ' ');
    if (space_pos != NULL)
    {
        *space_pos = '\0';
    }

    space_pos = strchr(parameter2, ' ');
    if (space_pos != NULL)
    {
        *space_pos = '\0';
    }

    if (strncmp(parameter1, "help", 4) == 0)
    {
        printf("\r\nPerform fpga configuration operations"
                "\r\n\nIt supports the following sub commands:"
                "\r\n  fpga load <rbf_file> <file_src>"
                "\r\n  fpga pr <rbf_file> <file_src>"
                "\r\n  fpga read <address>"
                "\r\n  fpga help"
                "\r\n\nTypical usage:"
                "\r\n- Use load command to load the fpga bitstream."
                "\r\n- Use pr command to do partial reconfiguration of fpga pr region."
                "\r\n- Use read command to read data from the fpga memory region."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  fpga <command> help\r\n"
                );

        return pdFALSE;
    }

    if (strncmp(parameter1, "load", 4) == 0)
    {
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nLoad fpga configuration bitstream"
                    "\r\n\nUsage:"
                    "\r\n  fpga load <bitstream_file> [file_source]"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  bitstream_file    The bitstream file name (rbf)"
                    "\r\n  file_source       The rbf file source location [default: sdmmc]. Other valid options are:"
                    "\r\n                     0 - SDMMC"
                    "\r\n                     1 - USB3 disk"
                    );

            return pdFALSE;
        }

        PRINT("bitstream provided : %s", parameter2);
        strcat(rbf_file, parameter2);
        media_src = atoi(parameter3); /* empty arguments are also treated as 0 */
        switch (media_src)
        {
        case 0: rbf_media_src = SOURCE_SDMMC;
            PRINT("bistream file source : SDMMC");
            break;

        case 1: rbf_media_src = SOURCE_USB3;
            PRINT("bistream file source : USB3");
            break;

        case 2: rbf_media_src = SOURCE_USB2;
            PRINT("bistream file source : USB2");
            PRINT("USB2 is currently not supported");
            return pdFALSE;

        default:
            rbf_media_src = SOURCE_INVALID;
            ERROR("Invalid bitstream source provieded");
            return pdFALSE;
        }
        rbf_ptr = NULL;
        rbf_ptr = mmc_read_file(rbf_media_src, rbf_file, &file_size);
        if (rbf_ptr == NULL)
        {
            ERROR("Unable to read bitstream from memory");
            return pdFALSE;
        }

        if (load_fpga_bitstream(rbf_ptr, file_size) != 0)
        {
            ERROR("Failed to load bitstream");
            vPortFree(rbf_ptr);
            return pdFALSE;
        }

        vPortFree(rbf_ptr);
        PRINT("bitstream configuration successful");
    }
    else if (strncmp(parameter1, "pr", 2) == 0)
    {
        /* Do partial reconfiguration */
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nPerform fpga partial reconfiguration"
                    "\r\n\nUsage:"
                    "\r\n  fpga pr <bitstream_file> [file_source]"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  bitstream_file    The bitstream file name (rbf)"
                    "\r\n  file_source       The rbf file source location [default: sdmmc]. Other valid options are:"
                    "\r\n                    0 - SDMMC"
                    "\r\n                    1 - USB3 disk"
                    );

            return pdFALSE;
        }
        PRINT("bitstream provided : %s", parameter2);
        strcat(rbf_file, parameter2);

        media_src = atoi(parameter3); /* empty arguments are also treated as 0 */
        switch (media_src)
        {
        case 0: rbf_media_src = SOURCE_SDMMC;
            PRINT("bistream file source : SDMMC");
            break;

        case 1: rbf_media_src = SOURCE_USB3;
            PRINT("bistream file source : USB3");
            break;

        case 2: rbf_media_src = SOURCE_USB2;
            PRINT("bistream file source : USB2");
            PRINT("USB2 is currently not supported");
            break;

        default:
            rbf_media_src = SOURCE_INVALID;
            ERROR("Invalid bitstream source provieded");
            return pdFALSE;
            break;
        }

        rbf_ptr = NULL;
        rbf_ptr = mmc_read_file(rbf_media_src, rbf_file, &file_size);
        if (rbf_ptr == NULL)
        {
            ERROR("Unable to read bitstream from memory");
            return pdFALSE;
        }

        if (do_freeze_pr_region() != 0)
        {
            return pdFALSE;
        }

        if (load_fpga_bitstream(rbf_ptr, file_size) != 0)
        {
            ERROR("Failed to load bitstream");
            vPortFree(rbf_ptr);
            return pdFALSE;
        }

        osal_delay_ms(100);

        if (do_unfreeze_pr_region() != 0)
        {
            return pdFALSE;
        }

        vPortFree(rbf_ptr);
        PRINT("Partial Reconfiguration completed");
    }
    else if (strncmp(parameter1, "read", 4) == 0)
    {
        uint64_t mem_reg;

        /* Read data from fpga memory */
        if (strncmp( parameter2, "help", 4 ) == 0)
        {
            printf("\r\nRead data from fpga memory region"
                    "\r\n\nUsage:"
                    "\r\n  fpga read <address>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n  address    The memory address in the fpga region."
                    );

            return pdFALSE;
        }

        mem_reg = (uint64_t)strtol(parameter2, NULL, 16);
        if ((mem_reg < 0x20000000) || (mem_reg > 0x40000000))
        {
            ERROR("Incorrect memory address provided");
            return pdFALSE;
        }

        PRINT("Value at %lx is : 0x%x", mem_reg, RD_REG32(mem_reg));
    }
    else
    {
        printf("Invalid fpga Command\r\n");
        printf("Enter 'help' to view a list of available commands.\r\n");
    }

    return pdFALSE;

}
