/*
 * edc.c
 * 
 * Copyright (C) 2019, SpaceLab.
 * 
 * This file is part of OBDH 2.0.
 * 
 * OBDH 2.0 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * OBDH 2.0 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with OBDH 2.0. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief EDC driver implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 27/10/2019
 * 
 * \addtogroup edc
 * \{
 */

#include "edc.h"

int edc_init()
{
    return -1;
}

int edc_write_cmd(edc_cmd_t cmd)
{
    uint8_t cmd_str[6];
    uint16_t cmd_str_len = 1;

    cmd_str[0] = cmd.id;

    switch(cmd.id)
    {
        case EDC_CMD_RTC_SET:
            cmd_str[1] = (uint8_t)(cmd.param >> 0);
            cmd_str[2] = (uint8_t)(cmd.param >> 8);
            cmd_str[3] = (uint8_t)(cmd.param >> 16);
            cmd_str[4] = (uint8_t)(cmd.param >> 24);
            cmd_str_len = 5;
            break;
        case EDC_CMD_PTT_POP:           break;
        case EDC_CMD_PTT_PAUSE:         break;
        case EDC_CMD_PTT_RESUME:        break;
        case EDC_CMD_SAMPLER_START:     break;
        case EDC_CMD_GET_STATE:         break;
        case EDC_CMD_GET_PTT_PKG:       break;
        case EDC_CMD_GET_HK_PKG:        break;
        case EDC_CMD_GET_ADC_SEQ:       break;
        case EDC_CMD_ECHO:              break;
        default:
            return -1;  // Invalid command
    }

    // Transmit the command over an UART port
    return edc_uart_write(cmd_str, cmd_str_len);
}

int edc_read(uint8_t *data, uint16_t len)
{
    return -1;
}

//! \} End of edc group
