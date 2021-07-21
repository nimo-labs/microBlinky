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
#include "system.h"

/* Books */
#include <gpio.h>
#include <delay.h>



void main(void)
{
    GPIO_PIN_DIR(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_DIR_OUT);
    GPIO_PIN_OUT(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_OUT_LOW);

    delaySetup(DELAY_BASE_MILLI_SEC); /*Clock timer at 1mS*/

    while (1)
    {
        GPIO_PIN_TGL(LED_BLUE_PORT, LED_BLUE_PIN);
        delayMs(2000);
    }
}