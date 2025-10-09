/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Sample application for gpio
 */

/**
 * @file gpio_sample.c
 * @brief Sample Application for GPIO
 */

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "osal_log.h"
#include "socfpga_gpio.h"
#include "socfpga_gpio_reg.h"
#include "socfpga_defines.h"

/**
 * @defgroup gpio_sample GPIO
 * @ingroup samples
 *
 * Sample application for GPIO driver
 *
 * @details
 * @section gpio_desc Description
 * This sample application demonstrates the functionality of the GPIO driver
 * with human interaction. It configures a GPIO pin as an input connected to
 * a push button and another GPIO pin as an output connected to an LED.
 * When the user presses and holds the push button, the application detects
 * the input signal and turns on the LED. Releasing the button turns the LED off.
 *
 * @section gpio_pre Prerequisites
 * - The GPIO pins used as input and output shall be set in respective macros
 * - The Arm Trusted Firmware (ATF) must configure the pinmux registers such that
 * the pins connected to the LED and push button are configured as GPIO.
 *
 * @section gpio_param Configurable Parameters
 * - The led pin can be configured in @c LED_PIN macro.
 * - The push button pin can be configured in @c PB_PIN macro.
 *
 * @section gpio_how_to How to Run
 * 1. Follow the common README instructions to build and flash the application.
 * 2. Run the application on the board.
 * 3. Output can be observed in the UART terminal.
 * 4. Press and hold the push button.
 * 5. Release the push button and repeat the step 4.
 *
 * @section gpio_result Expected Results
 * - The LED should turn ON while the button is pressed.
 */

/* Test configurations */

#define PB_PIN         GPIO1_PIN4
#define LED_PIN        GPIO0_PIN11
#define PINMUX_GPIO    (0x08U)
#define PINMUX_MASK    (0x0FU)

/*
 * @brief Check if the pin is configured as gpio in pinmux
 */
static bool is_pin_gpio(uint8_t pin)
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
        printf("\n\r Configuring pinmux reg");
        /* Change pin functionality to gpio */
        reg_val = RD_REG32(PINMUX_REG(pin));
        reg_val = (reg_val & ~PINMUX_MASK) | PINMUX_GPIO;
        WR_REG32(PINMUX_REG(LED_PIN), reg_val);
    }
}

/**
 * @brief Open GPIO pins and configure them.
 * Write back the received push button state to the led.
 */
void gpio_task(void)
{
    uint8_t val;
    gpio_handle_t led;
    gpio_handle_t pushbtn;
    int led_config;
    int btn_config;
    int ret;
    uint8_t is_button_pressed = 0;

    PRINT("GPIO sample application");

    /* open the GPIO pins for push button and LED */

    PRINT("Opening and configuring the GPIO pins ...");

    config_pinmux(LED_PIN);
    led = gpio_open(LED_PIN);

    config_pinmux(PB_PIN);
    pushbtn = gpio_open(PB_PIN);

    if ((led == NULL) || (pushbtn == NULL))
    {
        ERROR("Unable to open the gpio pins");
        return;
    }

    /* Configure the LED pin as output */
    led_config = GPIO_DIR_OUT;
    ret = gpio_ioctl(led, SET_GPIO_DIR, &led_config);

    if ((ret != 0))
    {
        ERROR("Configuring the gpio pin failed");
        gpio_close(led);
        return;
    }

    /* Configure the Push button pin as output */
    btn_config = GPIO_DIR_IN;
    ret = gpio_ioctl(pushbtn, SET_GPIO_DIR, &btn_config);
    if ((ret != 0))
    {
        ERROR("Configuring the gpio pin failed");
        gpio_close(pushbtn);
        return;
    }

    PRINT("Done.");

    PRINT("Hold / release the push button. Verify the push button state"
            " is reflected on the LED");

    /* Continuously read the push button and write the state to the LED pin */
    while (true)
    {
        gpio_read_sync(pushbtn, &val);
        if (val == 0U)
        {
            is_button_pressed = 1;
            PRINT("Button Pressed");
            gpio_write_sync(led, 1);
        }
        else
        {
            if (is_button_pressed == 1)
            {
                PRINT("Button Released");
                is_button_pressed = 0;
            }
            gpio_write_sync(led, 0);
        }
        osal_task_delay(10);
    }
}
