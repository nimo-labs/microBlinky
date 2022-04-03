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

#define UP_CLK 48000000

/* usbVcom */
#define USB_BUFFER_SIZE 64
#define SIMPLE_VCOM_TX_BUFSIZE 100 /* TX buffer size */

/* Printf */
#define PRINTF_BUFF_SIZE 100
#define PRINTF_UART PRINTF_USB_VCOM
