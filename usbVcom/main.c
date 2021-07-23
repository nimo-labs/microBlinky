/*
 * This file is part of the microBlinky distribution (https://github.com/nimo-labs/microBlinky).
 * Copyright (c) 2021 Nimolabs Ltd. www.nimo.uk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* Microcontroller */
#include "NuMicro.h"

/* Project configuration */
#include "nimolib.h"

/* Books */
#include <microNimo.h>
#include <gpio.h>
#include <delay.h>
#include <usbVcom.h>
#include <printf.h>



void main(void)
{
    uint32_t counter = 0;
    uint32_t loopLastTicks = 0;

    GPIO_PIN_DIR(MN_LED_PORT, MN_LED_PIN, GPIO_DIR_OUT);
    GPIO_PIN_OUT(MN_LED_PORT, MN_LED_PIN, GPIO_OUT_LOW);

    delaySetup(DELAY_BASE_MILLI_SEC); /*Clock timer at 1mS*/
    usbVcomInit();

    delayMs(2000);

    printf("Hello from microNimo\r\n");

    printf("Counting...\r\n");

    loopLastTicks = delayGetTicks();

    while (1)
    {
        if(delayMillis(loopLastTicks, 2000))
        {
            loopLastTicks = delayGetTicks();
            printf("%ld\r\n", counter);
            counter ++;
        }
    }
}

void vcomRecv(uint8_t *data, uint32_t size)
{
    if(size > 0) /* Ensure that data was recieved*/
    {
        if('A' == data[0])
        {
            GPIO_PIN_TGL(MN_LED_PORT, MN_LED_PIN); /*If the user pressed the letter A then toggle the user LED*/
        }
    }
}