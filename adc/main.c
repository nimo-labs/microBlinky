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

/* Project configuration */
#include "nimolib.h"

/* Books */
#include <microNimo.h>
#include <delay.h>
#include <usbVcom.h>
#include <printf.h>
#include <adc.h>

void main(void)
{
    uint32_t battV = 0;
    uint32_t loopLastTicks = 0;

    delaySetup(DELAY_BASE_MILLI_SEC); /*Clock timer at 1mS*/
    usbVcomInit();
    adcInit();

    delayMs(2000);

    printf("microNimo ADC example\r\n");

    loopLastTicks = delayGetTicks();

    while (1)
    {
        if(delayMillis(loopLastTicks, 2000))
        {
            battV=adcReadChanSingle(MN_BATTV_ADC_CHAN);
            battV = (battV * 3298) / 4096;
            battV *= 126;
            battV = battV / 100;

            loopLastTicks = delayGetTicks();
            printf("Battery voltage: %ldmV\r\n", battV);
        }
    }
}
