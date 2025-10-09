/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Implementation of CLI commands for GPIO
 */


/**
 * @defgroup cli_gpio GPIO
 * @ingroup cli
 *
 * Perform operations on gpio pins.
 *
 * @details
 * It supports the following commands:
 * - gpio set &lt;pin_num&gt; &lt;pin_state&gt;
 * - gpio get &lt;pin_num&gt;
 * - gpio help
 *
 * Typical usage:
 * - Use 'gpio set' command to change the output state.
 * - Use 'gpio get' command to read the input state.
 *
 * @section gpio_commands Commands
 * @subsection gpio_set gpio set
 * Configure a gpio pin and change its state <br>
 *
 * Usage: <br>
 * gpio set &lt;pin_num&gt; &lt;pin_state&gt; <br>
 *
 * It requires the following arguments:
 * - pin_num - GPIO pin number. Valid values are 0 to 47
 * - pin_state - Pin state as 0 or 1.
 *
 * @subsection gpio_get gpio get
 * Read the state of a gpio pin <br>
 *
 * Usage: <br>
 * gpio get &lt;pin_num&gt; <br>
 *
 * It requires the following argument:
 * - pin_num - GPIO pin number. Valid values are 0 to 47
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include "semphr.h"
#include <socfpga_uart.h>
#include <socfpga_timer.h>
#include "FreeRTOS_CLI.h"
#include "cli_app.h"
#include <socfpga_gpio.h>
#include "osal_log.h"

SemaphoreHandle_t sem_cli_gpio;
BaseType_t higher_priority_task_woken = pdFALSE;

typedef struct
{
    uint8_t pin;
    gpio_int_t int_type;
} gpio_int_event;

gpio_int_event gpio_irq_event;
BaseType_t cmd_gpio( char *write_buffer, size_t write_buffer_len,
        const char *command_string );
TaskHandle_t gpio_event_task_hdl = NULL;

void gpio_callback( uint8_t pin_state, void *user_context )
{
    (void) pin_state;
    if (strcmp(user_context, "gpio_cli") == 0)
    {
        xSemaphoreGiveFromISR(sem_cli_gpio, NULL);
    }
}

static gpio_int_t intrpt_type_char_to_val( char *ctype )
{
    gpio_int_t res = GPIO_INT_NONE;
    switch (ctype[ 0 ])
    {
    case 'l':
        res = GPIO_INT_LOW;
        break;
    case 'h':
        res = GPIO_INT_HIGH;
        break;
    case 'r':
        res = GPIO_INT_RISING;
        break;
    case 'f':
        res = GPIO_INT_FALLING;
        break;
    default:
        res = GPIO_INT_NONE;
    }
    return res;
}

/*
 * @brief Check if the pin is configured as gpio in pinmux
 */
static bool is_pin_gpio( uint8_t pin )
{
    uint32_t val;
    val = RD_REG32(PINMUX_REG(pin));
    val &= PINMUX_MASK;
    return (val == PINMUX_GPIO);
}

/*
 * @brief Configure the pin as gpio in pinmux
 */
static void config_pinmux(uint8_t pin)
{
    uint32_t reg_val;
    if (is_pin_gpio(pin) == false)
    {
        PRINT("Configuring pinmux reg");
        /* Change pin functionality to gpio */
        reg_val = RD_REG32(PINMUX_REG(pin));
        reg_val = (reg_val & ~PINMUX_MASK) | PINMUX_GPIO;
        WR_REG32(PINMUX_REG(pin), reg_val);
    }
}

/**
 * @func : gpio_event
 * @brief : prints the gpio event occurred.
 */

void gpio_event( void *params )
{

    gpio_int_event *event = (gpio_int_event*) params;
    while (1)
    {
        osal_semaphore_wait(sem_cli_gpio, portMAX_DELAY);
        switch (event->int_type)
        {
        case GPIO_INT_HIGH:
            PRINT("Level high interrupt is detected for gpio %d",
                    event->pin);
            break;
        case GPIO_INT_LOW:
            PRINT("Level low interrupt is detected for gpio %d",
                    event->pin);
            break;
        case GPIO_INT_RISING:
            PRINT("Rising edge interrupt is detected for gpio %d",
                    event->pin);
            break;
        case GPIO_INT_FALLING:
            PRINT("Falling edge interrupt is detected for gpio %d",
                    event->pin);
            break;
        default:
            break;
        }
    }
}

/**
 * @func : cmd_gpio
 * @brief : callback function to set or get gpio pinstate
 */

BaseType_t cmd_gpio( char *write_buffer, size_t write_buffer_len,
        const char *command_string )
{
    int int_type;
    int config_type;
    uint8_t pin_state;
    gpio_pin_t gpio_number;
    char ret_buffer[ 50 ] = { 0 };
    char temp_string[ 4 ] = { 0 };
    const char *parameter1;
    const char *parameter2;
    const char *parameter3;
    BaseType_t parameter1_str_len;
    BaseType_t parameter2_str_len;
    BaseType_t parameter3_str_len;
    char *context = "gpio_cli";
    const char *get_cmd = "get";
    const char *set_cmd = "set";
    const char *set_int_cmd = "setint";
    const char *close_cmd = "close";
    const char *help_cmd = "help";
    gpio_handle_t gpio_pin_hdl;
    static gpio_handle_t gpio_handle_live;
    char *endptr;
    char *space_pos;

    parameter1 = FreeRTOS_CLIGetParameter(command_string, 1,
            &parameter1_str_len);
    parameter2 = FreeRTOS_CLIGetParameter(command_string, 2,
            &parameter2_str_len);
    strncpy(temp_string, parameter1, parameter1_str_len);
    if (strcmp(temp_string, set_cmd) == 0)
    {
        if (strncmp( parameter2, "help", 4) == 0)
        {
            printf("\r\nConfigure a gpio and its state"
                    "\r\n\nUsage:"
                    "\r\n  gpio set <pin_no> <pin_state>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n pin_num     GPIO pin number. Valid values are 0 to 47"
                    "\r\n pin_state   Valid values are 0 and 1. "
                    "\r\n             0 for LOW,"
                    "\r\n             1 for HIGH."
                    );

            return pdFALSE;
        }
        parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                &parameter3_str_len);

        /* terminate string at the particular commands */
        space_pos = strchr(parameter2, ' ');
        if (space_pos != NULL)
        {
 *space_pos = '\0';
        }

        space_pos = strchr(parameter3, ' ');
        if (space_pos != NULL)
        {
 *space_pos = '\0';
        }

        if (parameter3 == NULL)
        {
            ERROR(
                    "Incorrect Command \r\n Enter 'help' to view a list of available commands.");
            return pdFAIL;
        }
        gpio_number = strtol(parameter2, &endptr, 10);
        if (endptr == parameter2)
        {
            ERROR(
                    "Incorrect Command \r\n Enter 'help' to view a list of available commands.");
            return pdFAIL;
        }
        else if (*endptr != '\0')
        {
            ERROR(
                    "Incorrect Command \r\n Enter 'help' to view a list of available commands.");
            return pdFAIL;
        }
        else
        {
            /* valid pin argument */
            pin_state = strtol(parameter3, NULL, 10);
            if (gpio_number > 47)
            {
                strncpy(write_buffer, "Invalid GPIO number",
                        strlen("Invalid GPIO number "));
                return pdFAIL;
            }
            if ((pin_state != 0) && (pin_state != 1))
            {
                strncpy(write_buffer, "Invalid GPIO pin state",
                        strlen("Invalid GPIO pin state "));
                return pdFAIL;
            }
            config_pinmux(gpio_number);
            gpio_pin_hdl = gpio_open(gpio_number);
            if (gpio_pin_hdl == NULL)
            {
                ERROR("Failed opening the Pin. Maybe already in use.");
                return pdFAIL;
            }
            config_type = GPIO_DIR_OUT;
            gpio_ioctl(gpio_pin_hdl, SET_GPIO_DIR, &config_type);
            gpio_write_sync(gpio_pin_hdl, pin_state);
            PRINT("Successfully set the GPIO state as %d", pin_state);
            gpio_close(gpio_pin_hdl);
        }
    }
    else if (strcmp(temp_string, get_cmd) == 0)
    {
        if (strncmp( parameter2, "help", 4) == 0)
        {
            printf("\r\nRead the current state of a gpio pin"
                    "\r\n\nUsage:"
                    "\r\n  gpio get <pin_no>"
                    "\r\n\nIt requires the following arguments:"
                    "\r\n pin_num    GPIO pin number. Valid values are 0 to 47"
                    );

            return pdFALSE;
        }
        gpio_number = strtol(parameter2, &endptr, 10);
        if (endptr == temp_string)
        {
            ERROR(
                    "Incorrect Command \r\n Enter 'help' to view a list of available commands.");
            return pdFAIL;
        }
        else if (*endptr != '\0')
        {
            ERROR(
                    "Incorrect Command \r\n Enter 'help' to view a list of available commands.");
            return pdFAIL;
        }
        else
        {
            if (gpio_number >= GPIO_MAX_INSTANCE)
            {
                strncpy(write_buffer, "Invalid GPIO number",
                        strlen("Invalid GPIO number "));
                return pdFAIL;
            }
            config_pinmux(gpio_number);
            gpio_pin_hdl = gpio_open(gpio_number);
            if (gpio_pin_hdl == NULL)
            {
                ERROR("Failed opening the Pin. Maybe already in use.");
                return pdFAIL;
            }
            config_type = GPIO_DIR_IN;
            gpio_ioctl(gpio_pin_hdl, SET_GPIO_DIR, &config_type);
            gpio_read_sync(gpio_pin_hdl, &pin_state);
            gpio_close(gpio_pin_hdl);
            itoa(pin_state, temp_string, 10);
            strncpy(write_buffer, temp_string, write_buffer_len);
        }
    }
    else if (strcmp(temp_string, set_int_cmd) == 0)
    {
        sem_cli_gpio = osal_semaphore_create(NULL);
        parameter3 = FreeRTOS_CLIGetParameter(command_string, 3,
                &parameter3_str_len);
        strncpy(temp_string, parameter3, parameter3_str_len);
        int_type = intrpt_type_char_to_val(temp_string);
        gpio_number = strtol(parameter2, NULL, 10);
        if (gpio_number > GPIO_MAX_INSTANCE)
        {
            strncpy(write_buffer, "Invalid GPIO number",
                    strlen("Invalid GPIO number "));
            return pdFAIL;
        }
        if ((int_type < GPIO_INT_NONE) || (int_type > GPIO_INT_HIGH))
        {
            strncpy(write_buffer, "Invalid interrupt type",
                    strlen("Invalid interrupt type "));
            return pdFAIL;
        }
        config_pinmux(gpio_number);
        gpio_pin_hdl = gpio_open(gpio_number);
        if (gpio_pin_hdl != NULL)
        {
            gpio_ioctl(gpio_pin_hdl, SET_GPIO_DIR,
                    GPIO_DIR_IN);
            gpio_set_callback(gpio_pin_hdl, gpio_callback, context);

            gpio_handle_live = gpio_pin_hdl;
            switch (int_type)
            {
            case GPIO_INT_HIGH:
                PRINT("Level high interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_LOW:
                PRINT("Level low interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_RISING:
                PRINT("Rising edge interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_FALLING:
                PRINT("Falling edge interrupt is set for gpio %d",
                        gpio_number);
                break;
            default:
                break;
            }
            gpio_irq_event.int_type = int_type;
            gpio_irq_event.pin = gpio_number;
            gpio_ioctl(gpio_pin_hdl, SET_GPIO_INT, &int_type);
            if (gpio_event_task_hdl == NULL)
            {
                if (xTaskCreate(gpio_event, "gpioEventTask",
                        configMINIMAL_STACK_SIZE, &gpio_irq_event,
                        tskIDLE_PRIORITY,
                        &gpio_event_task_hdl) != pdPASS)
                {
                    ERROR("Task creation failed.");
                }
            }
            strncpy(write_buffer, ret_buffer, strlen(ret_buffer));
        }
        else
        {
            switch (int_type)
            {
            case GPIO_INT_HIGH:
                PRINT("Level high interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_LOW:
                PRINT("Level low interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_RISING:
                PRINT("Rising edge interrupt is set for gpio %d",
                        gpio_number);
                break;
            case GPIO_INT_FALLING:
                PRINT("Falling edge interrupt is set for gpio %d",
                        gpio_number);
                break;
            default:
                break;
            }
            gpio_ioctl(gpio_handle_live, SET_GPIO_INT, &int_type);
            if (int_type == GPIO_INT_NONE)
            {
                sprintf(ret_buffer, "No interrupt is set for gpio %d",
                        gpio_number);
                vTaskDelete(gpio_event_task_hdl);
            }
            else
            {
                gpio_irq_event.int_type = int_type;
                gpio_irq_event.pin = gpio_number;
                if (xTaskCreate(gpio_event, "gpioEventTask",
                        configMINIMAL_STACK_SIZE, &gpio_irq_event,
                        tskIDLE_PRIORITY,
                        &gpio_event_task_hdl) != pdPASS)
                {
                    ERROR("Task creation failed.");
                }
            }
            strncpy(write_buffer, ret_buffer, strlen(ret_buffer));
        }
    }
    else if (strcmp(temp_string, close_cmd) == 0)
    {
        strncpy(temp_string, parameter2, parameter2_str_len);
        gpio_number = strtol(temp_string, NULL, 10);
        if (gpio_number > GPIO_MAX_INSTANCE)
        {
            strncpy(write_buffer, "Invalid GPIO number",
                    strlen("Invalid GPIO number "));
            strncpy(write_buffer, ret_buffer, strlen(ret_buffer));
            return pdFAIL;
        }

        gpio_close(gpio_handle_live);

    }
    else if (strcmp(temp_string, help_cmd) == 0)
    {
        printf("\rPerform operations on GPIOs"
                "\r\n\nIt supports the following commands:"
                "\r\n  gpio set <pin_num> <pin_state>"
                "\r\n  gpio get <pin_num>"
                "\r\n  gpio help"
                "\r\n\nTypical usage:"
                "\r\n- Use 'gpio set' to change the output state."
                "\r\n- Use 'gpio get' to read the input state."
                "\r\n\nFor help on the specific commands please do:"
                "\r\n  gpio <command> help\r\n"
                );
        return pdFAIL;
    }
    else
    {
        strncpy(write_buffer, "Invalid gpio command",
                strlen("Invalid gpio command "));
        return pdFAIL;
    }
    return pdFALSE;
}
