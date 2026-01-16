/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of the command line application
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <socfpga_uart.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include "semphr.h"
#include "usb_main.h"
#include "libfcs.h"
#include "socfpga_mmc.h"
#include "socfpga_fpga_manager.h"
#include "osal_log.h"

#define RBF_FILENAME         "/core.rbf"
#define KEY_NULL             0x0
#define KEY_ETX              0x3
#define KEY_ESCAPE           0x1B
#define KEY_ARROW_MID        0x5B
#define KEY_ARROW_UP         0x41
#define KEY_ARROW_DOWN       0x42
#define KEY_ARROW_RIGHT      0x43
#define KEY_ARROW_LEFT       0x44
#define KEY_BACKSPACE        0x08
#define KEY_TAB              0x09

#define MAX_HISTORY_ITEMS    20
#define MAX_INPUT_LENGTH     256
#define MAX_OUTPUT_LENGTH    256
SemaphoreHandle_t print_semaphore;

static BaseType_t cmd_add( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );
static BaseType_t cmd_echo( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString );

char output_data[ MAX_INPUT_LENGTH ];
char input_line[ MAX_INPUT_LENGTH ];    //input command to be executed

int latest_index = 0;
char history[ MAX_HISTORY_ITEMS ][ MAX_INPUT_LENGTH ];

static void load_bitstream();

/*
 * @brief Load core.rbf to configure the FPGA
 */
static void load_bitstream()
{
    uint32_t file_size;
    uint8_t *rbf_ptr;

    rbf_ptr = mmc_read_file(SOURCE_SDMMC, RBF_FILENAME, &file_size);
    if( rbf_ptr == NULL )
    {
        return;
    }

    if( load_fpga_bitstream(rbf_ptr, file_size) != 0 )
    {
        vPortFree(rbf_ptr);
        return;
    }

    vPortFree(rbf_ptr);
}

void vApplicationTickHook( void )
{
    /*
     * This is called from RTOS tick handler
     * Not used in this demo, But defined to keep the configuration sharing
     * simple
     * */
}

/**
 *  Structure to include the list of commands to be registered
 */
const CLI_Command_Definition_t xCommandList[] =
{
    {
        .pcCommand = "add", /* The command string to type. */
        .pcHelpString = "add     perform add operation on two numbers\r\n",
        .pxCommandInterpreter = cmd_add, /* The function to run. */
        .cExpectedNumberOfParameters = -1 /* 2 parameters are expected. */
    },
    {
        .pcCommand = "echo",
        .pcHelpString = "echo    echo the input back to console\r\n",
        .pxCommandInterpreter = cmd_echo,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "i2c", .pcHelpString =
                "i2c     perform i2c bus operations\r\n",
        .pxCommandInterpreter = cmd_i2c,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "spi", .pcHelpString =
                "spi     perform operations on SPI bus\r\n",
        .pxCommandInterpreter = cmd_spi,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "eth", .pcHelpString =
                "eth     perform ethernet operations\r\n",
        .pxCommandInterpreter = cmd_eth,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "fat",
        .pcHelpString = "fat     perform fat operations\r\n",
        .pxCommandInterpreter = fat_ops,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "i3c",
        .pcHelpString =
                "i3c     perform operations on i3c bus \r\n",
        .pxCommandInterpreter = cmd_i3c,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "fcs",
        .pcHelpString = "fcs     perform crptographic commands.\r\n",
        .pxCommandInterpreter = cmd_fcs,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "rsu",
        .pcHelpString =
                "rsu     perform rsu operations(NOTE: needs RSU sopported image for this)\r\n",
        .pxCommandInterpreter = cmd_rsu,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "ros",
        .pcHelpString =
                "ros     perform ros operations(NOTE: needs RSU sopported image for this)\r\n",
        .pxCommandInterpreter = cmd_ros,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "wdog",
        .pcHelpString =
                "wdog    perform watchdog timer operations\r\n",
        .pxCommandInterpreter = cmd_wdt,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "gpio", /* The command string to type. */
        .pcHelpString =
                "gpio    perform gpio operations\r\n",
        .pxCommandInterpreter = cmd_gpio, /* The function to run. */
        .cExpectedNumberOfParameters = -1
    },
    { .pcCommand = "qspi",
      .pcHelpString =
              "qspi    perform qspi operations\r\n",
      .pxCommandInterpreter = cmd_qspi,
      .cExpectedNumberOfParameters = -1},
    { .pcCommand = "fpga",
      .pcHelpString =
              "fpga    perform fpga configuration \r\n",
      .pxCommandInterpreter = cmd_fpga_manager,
      .cExpectedNumberOfParameters = -1},
    {
        .pcCommand = "timer", .pcHelpString =
                "timer   perform operations on timer\r\n",
        .pxCommandInterpreter = cmd_timer,
        .cExpectedNumberOfParameters = -1
    },
    {
        .pcCommand = "reboot", .pcHelpString =
                "reboot  perform reboot operation (warm/cold)\r\n",
        .pxCommandInterpreter = cmd_reboot,
        .cExpectedNumberOfParameters = -1
    },
    { .pcCommand = "bridge",
      .pcHelpString =
              "bridge  perform bridge operations\r\n",
      .pxCommandInterpreter = cmd_bridge,
      .cExpectedNumberOfParameters = -1}
};


/**
 * @func : cmd_add
 * @brief : callback function to add two numbers when user inputs data in the format add a b
 */

static BaseType_t cmd_add( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString )
{
    const char *pcParameter1, *pcParameter2;
    BaseType_t xParameter1StringLength, xParameter2StringLength;

    /* Obtain the name of the source file, and the length of its name, from
       the command string. The name of the source file is the first parameter. */
    pcParameter1 = FreeRTOS_CLIGetParameter(
            /* The command string itself. */
            pcCommandString,
            /* Return the first parameter. */
            1,
            /* Store the parameter string length. */
            &xParameter1StringLength);

    pcParameter2 = FreeRTOS_CLIGetParameter(
            /* The command string itself. */
            pcCommandString,
            /* Return the first parameter. */
            2,
            /* Store the parameter string length. */
            &xParameter2StringLength);

    if (strncmp(pcParameter1, "help", 4) == 0)
    {
        printf("\r\nPerform add operation on two integers."
                "\r\n\nUsage:"
                "\r\n  add <num1> <num2>"
                "\r\n\nIt requires the following arguments:"
                "\r\n  num1    first input interger"
                "\r\n  num2    second input interger"
                );
        return pdFALSE;
    }
    int32_t xValue1 = strtol(pcParameter1, NULL, 10);
    int32_t xValue2 = strtol(pcParameter2, NULL, 10);

    /*add the two numbers */
    int32_t xResultValue = xValue1 + xValue2;

    /* convert the result to a string */
    char cResultString[ 10 ];
    itoa(xResultValue, cResultString, 10);

    /* copy the result to the write buffer */
    strncpy(pcWriteBuffer, cResultString, xWriteBufferLen);
    return pdFALSE;
}

static BaseType_t cmd_echo( char *pcWriteBuffer, size_t xWriteBufferLen,
        const char *pcCommandString )
{
    (void) xWriteBufferLen;
    int idx = 1;

    while (1)
    {
        const char *pcParameter;
        BaseType_t xParameterLength = 0;

        pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, idx++,
                &xParameterLength);
        if (!pcParameter)
        {
            break;
        }
        strncat(pcWriteBuffer, pcParameter, xParameterLength);
    }

    return pdFALSE;
}

static int ignore_key(char key)
{
    switch (key)
    {
    case KEY_TAB:
        return 1;
    default:
        return 0;
    }
}

static char get_escape(char *input)
{
    char key = *input;

    if (key != KEY_ESCAPE)
    {
        return KEY_NULL;
    }

    key = getchar();
    if (key == KEY_ARROW_MID)
    {
        key = getchar();
        switch (key)
        {
        case KEY_ARROW_UP:
        case KEY_ARROW_DOWN:
        case KEY_ARROW_RIGHT:
        case KEY_ARROW_LEFT:
            *input = KEY_NULL;
            break;
        default:
            *input = key;
            key = KEY_NULL;
            break;
        }
    }
    else
    {
        *input = key;
        key = KEY_NULL;
    }
    return key;
}

/**
 * @func: cli_task
 * @brief : demo function to implement FreeRTOS_CLI
 */
void cli_task( void *params )
{
    /*
     * Load core.rbf bitstream to configure the fpga fabric.
     * This is essential if the device boots in HPS first
     * boot flow for USB3.1 to work
     */
    load_bitstream();

    (void) params;
    int input_length = 0;
    int bs = 0;
    int history_idx = 0;
    char special_key_code = 0;

    BaseType_t xMoreDataToFollow;

//Register the command with FreeRTOS+CLI
    print_semaphore = osal_semaphore_create(NULL);
    BaseType_t xRet;
    for (unsigned int idx = 0;
            idx < sizeof(xCommandList) / sizeof(CLI_Command_Definition_t);
            idx++)
    {
        xRet = FreeRTOS_CLIRegisterCommand(&xCommandList[ idx ]);
        if (xRet == pdPASS)
            printf("\r%s : CLI command registered successfully \n",
                    xCommandList[ idx ].pcCommand);
        else
            printf("%s : Register failed\n", xCommandList[ idx ].pcCommand);
    }

    libfcs_init("log_err");
    while (1)
    {
        printf("\r\nAGILEX5# ");
        //Clear input buffer
        input_length = 0;
        memset(input_line, 0, MAX_INPUT_LENGTH);

        bs = 1;
        history_idx = latest_index;
        special_key_code = 0;

        while (input_length < MAX_OUTPUT_LENGTH)
        {
            input_line[ input_length ] = getchar();

            /*Check for keys to ignore*/
            if (ignore_key(input_line[ input_length ]))
            {
                continue;
            }

            /*Abort command CTRL+C*/
            if (input_line[ input_length ] == KEY_ETX)
            {
                input_length = 0; bs = 1;
                history_idx = latest_index;
                memset(input_line, 0, MAX_INPUT_LENGTH);
                printf("\x1B[2K\rAGILEX5# ");
                continue;
            }

            /*capture escaped special keys*/
            special_key_code = get_escape(&input_line[ input_length ]);
            switch (special_key_code)
            {
            case KEY_ARROW_UP:
                if (history_idx == 0)
                {
                    history_idx = MAX_HISTORY_ITEMS - 1;
                }
                else
                {
                    history_idx--;
                }
                if (history[history_idx][0] == '\0') {
                    history_idx = (history_idx + 1) % MAX_HISTORY_ITEMS;
                    special_key_code = input_line[ input_length ];
                }
                break;
            case KEY_ARROW_DOWN:
                history_idx = (history_idx + 1) % MAX_HISTORY_ITEMS;
                if (history[history_idx][0] == '\0') {
                    if (history_idx == 0)
                    {
                        history_idx = MAX_HISTORY_ITEMS - 1;
                    }
                    else
                    {
                        history_idx--;
                    }
                    special_key_code = input_line[ input_length ];
                }
                break;
            case KEY_NULL:
                /*Just breakout if special key is NULL
                 * Escape to handle default key press cases*/
                break;
            default:
                /*All other escape keys
                 * This needs to be ignored*/
                special_key_code = 0;
                continue;
            }
            /*Handle history traversal*/
            if (special_key_code)
            {
                if (history_idx == latest_index)
                {
                    continue;
                }
                memcpy(input_line, history[history_idx], MAX_INPUT_LENGTH);
                input_length = strlen(input_line);
                bs = input_length + 1;
                printf("\x1B[2K\rAGILEX5# %s",input_line);
                special_key_code = 0;
            }

            if (bs == 1)
            {
                if (input_line[ input_length ] != KEY_BACKSPACE)
                {
                    putchar(input_line[ input_length ]);
                }
            }

            if (bs > 1)
            {
                putchar(input_line[ input_length ]);
            }

            if ((input_line[ input_length ] == '\n')
                    || (input_line[ input_length ] == '\r'))
            {
                //Break out of loop if newline
                input_line[ input_length ] = 0;
                break;
            }
            else if (input_line[ input_length ] == KEY_BACKSPACE)
            {
                //Handle backspace character
                input_line[ input_length ] = 0;
                if (input_length > 0)
                {
                    printf(" \b");
                    input_length--;
                    bs--;
                }
                else
                    bs = 1;
            }
            else
            {
                input_length++;
                bs++;
            }
        }

        if (input_length == 0)
        {
            continue;
        }

        printf("\r\n");
        memset(output_data, 0, MAX_OUTPUT_LENGTH);
        memset(history[latest_index], 0, MAX_INPUT_LENGTH);
        memcpy(history[latest_index], input_line, input_length);
        latest_index = (latest_index + 1) % MAX_HISTORY_ITEMS;
        //Parse and process command
        do
        {
            xMoreDataToFollow = FreeRTOS_CLIProcessCommand(input_line,
                    output_data,
                    MAX_OUTPUT_LENGTH);
            printf("%s ", output_data); //print the output of the user entered command
        } while (xMoreDataToFollow != pdFALSE);
    }

    while (1)
    {

    }

}
void cli_demo()
{
    /* Usb task priority should be less than the other tasks */
    if (xTaskCreate(usb_task, "usb3_cli_task", configMINIMAL_STACK_SIZE * 20,
            NULL, tskIDLE_PRIORITY, NULL) !=
            pdPASS)
    {
        /* hang here */
        while (1)
            ;
    }

    if (xTaskCreate(cli_task, "cli_task1", configMINIMAL_STACK_SIZE + 110,
            NULL, tskIDLE_PRIORITY + 1, NULL) !=
            pdPASS)
    {
        /* hang here */
        while (1)
            ;
    }
    vTaskStartScheduler();
}
