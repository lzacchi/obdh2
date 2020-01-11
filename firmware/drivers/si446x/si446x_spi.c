/*
 * si446x_spi.c
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
 * \brief Si446x SPI driver implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 29/07/2017
 * 
 * \defgroup si446x_spi SPI
 * \ingroup si446x
 * \{
 */

#include <stdint.h>

#include <drivers/spi/spi.h>

#include "si446x_config.h"
#include "si446x_reg.h"

uint8_t si446x_spi_transfer(uint8_t byte)
{
    uint8_t buf;

    spi_transfer(0, 0, &byte, &buf, 1);

    return buf;
}

void si446x_spi_write_byte(uint8_t byte)
{
    spi_write(0, 0, &byte, 1);
}

void si446x_spi_write(uint8_t *data, uint16_t size)
{
    spi_write(0, 0, data, size);
}

void si446x_spi_read(uint8_t *data, uint16_t size)
{
    spi_read(0, 0, data, size);
}

//! \} End of si446x group
