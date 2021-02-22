/*
 * eps.h
 * 
 * Copyright (C) 2020, SpaceLab.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with OBDH 2.0. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief EPS device definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.18
 * 
 * \date 01/02/2020
 * 
 * \defgroup eps EPS
 * \ingroup devices
 * \{
 */

#ifndef EPS_H_
#define EPS_H_

#include <stdint.h>

#define EPS_MODULE_NAME         "EPS"

/**
 * \brief EPS battery voltage.
 */
typedef struct
{
    uint32_t cell_0;                /**< Battery cell 0 voltage. */
    uint32_t cell_1;                /**< Battery cell 1 voltage. */
} eps_bat_voltage_t;

/**
 * \brief EPS data structure.
 */
typedef struct
{
    eps_bat_voltage_t bat_voltage;  /**< Battery voltage. */
    uint32_t bat_current;           /**< Battery current. */
    uint32_t bat_charge;            /**< Battery charge. */
} eps_data_t;

/**
 * \brief Initialization of the EPS device.
 *
 * \return The status/error code.
 */
int eps_init();

/**
 * \brief Gets the battery voltage from the EPS module.
 *
 * \param[in,out] bar_volt is a pointer to store the battery voltage.
 *
 * \return The status/error code.
 */
int eps_get_bat_voltage(eps_bat_voltage_t *bat_volt);

/**
 * \brief Gets the battery current from the EPS module.
 *
 * \param[in,out] bat_cur is a pointer to store the raw battery current.
 *
 * \return The status/error code.
 */
int eps_get_bat_current(uint32_t *bat_cur);

/**
 * \brief Gets the battery charge from the EPS module.
 *
 * \param[in,out] charge is a pointer to store the raw battery charge.
 *
 * \return The status/error code.
 */
int eps_get_bat_charge(uint32_t *charge);

/**
 * \brief Gets all the EPS available data.
 *
 * \param[in,out] data is a pointer to store the EPS data.
 *
 * \return The status/error code.
 */
int eps_get_data(eps_data_t *data);

#endif /* EPS_H_ */

/** \} End of eps group */
