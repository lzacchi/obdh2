/*
 * logger_uart.c
 * 
 * Copyright (C) 2019, SpaceLab.
 * 
 * This file is part of OBDH 2.0.
 * 
 * OBDH 2.0 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * OBDH 2.0 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with OBDH 2.0. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief Logger device UART implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/11/2019
 * 
 * \defgroup logger_uart UART
 * \ingroup logger
 * \{
 */

#include <drivers/uart/uart.h>

#include "logger.h"

bool logger_uart_init()
{
    uart_config_t config;

    config.baudrate     = 115200;
    config.data_bits    = 8;
    config.parity       = UART_NO_PARITY;
    config.stop_bits    = UART_ONE_STOP_BIT;

    return uart_init(UART_PORT_2, config) == 0 ? true : false;
}

void logger_uart_write_byte(uint8_t byte)
{
    uart_write(UART_PORT_2, &byte, 1);
}

//! \} End of logger_uart group
