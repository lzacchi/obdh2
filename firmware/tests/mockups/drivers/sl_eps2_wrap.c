/*
 * sl_eps2_wrap.c
 * 
 * Copyright (C) 2021, SpaceLab.
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
 * \brief SpaceLab EPS 2.0 wrap implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.7.22
 * 
 * \date 2021/08/06
 * 
 * \addtogroup sl_eps2_wrap
 * \{
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <setjmp.h>
#include <float.h>
#include <cmocka.h>

#include "sl_eps2_wrap.h"

int __wrap_sl_eps2_init(sl_eps2_config_t config)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    return mock_type(int);
}

int __wrap_sl_eps2_check_device(sl_eps2_config_t config)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    return mock_type(int);
}

int __wrap_sl_eps2_write_reg(sl_eps2_config_t config, uint8_t adr, uint32_t val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(adr);
    check_expected(val);

    return mock_type(int);
}

int __wrap_sl_eps2_read_reg(sl_eps2_config_t config, uint8_t adr, uint32_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(adr);

    if (val != NULL)
    {
        *val = mock_type(uint32_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_data(sl_eps2_config_t config, sl_eps2_data_t *data)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (data != NULL)
    {
        data->time_counter                  = mock_type(uint32_t);
        data->temperature_uc                = mock_type(sl_eps2_temp_t);
        data->current                       = mock_type(sl_eps2_current_t);
        data->last_reset_cause              = mock_type(uint8_t);
        data->reset_counter                 = mock_type(uint16_t);
        data->solar_panel_voltage_my_px     = mock_type(sl_eps2_voltage_t);
        data->solar_panel_voltage_mx_pz     = mock_type(sl_eps2_voltage_t);
        data->solar_panel_voltage_mz_py     = mock_type(sl_eps2_voltage_t);
        data->solar_panel_current_my        = mock_type(sl_eps2_current_t);
        data->solar_panel_current_py        = mock_type(sl_eps2_current_t);
        data->solar_panel_current_mx        = mock_type(sl_eps2_current_t);
        data->solar_panel_current_px        = mock_type(sl_eps2_current_t);
        data->solar_panel_current_mz        = mock_type(sl_eps2_current_t);
        data->solar_panel_current_pz        = mock_type(sl_eps2_current_t);
        data->mppt_1_duty_cycle             = mock_type(sl_eps2_duty_cycle_t);
        data->mppt_2_duty_cycle             = mock_type(sl_eps2_duty_cycle_t);
        data->mppt_3_duty_cycle             = mock_type(sl_eps2_duty_cycle_t);
        data->solar_panel_output_voltage    = mock_type(sl_eps2_voltage_t);
        data->main_power_bus_voltage        = mock_type(sl_eps2_voltage_t);
        data->rtd_0_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_1_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_2_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_3_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_4_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_5_temperature             = mock_type(sl_eps2_temp_t);
        data->rtd_6_temperature             = mock_type(sl_eps2_temp_t);
        data->battery_voltage               = mock_type(sl_eps2_voltage_t);
        data->battery_current               = mock_type(sl_eps2_current_t);
        data->battery_average_current       = mock_type(sl_eps2_current_t);
        data->battery_acc_current           = mock_type(sl_eps2_current_t);
        data->battery_charge                = mock_type(sl_eps2_charge_t);
        data->battery_monitor_temperature   = mock_type(sl_eps2_temp_t);
        data->battery_monitor_status        = mock_type(uint8_t);
        data->battery_monitor_protection    = mock_type(uint8_t);
        data->battery_monitor_cycle_counter = mock_type(uint8_t);
        data->raac                          = mock_type(sl_eps2_charge_t);
        data->rsac                          = mock_type(sl_eps2_charge_t);
        data->rarc                          = mock_type(uint8_t);
        data->rsrc                          = mock_type(uint8_t);
        data->battery_heater_1_duty_cycle   = mock_type(sl_eps2_duty_cycle_t);
        data->battery_heater_2_duty_cycle   = mock_type(sl_eps2_duty_cycle_t);
        data->mppt_1_mode                   = mock_type(uint8_t);
        data->mppt_2_mode                   = mock_type(uint8_t);
        data->mppt_3_mode                   = mock_type(uint8_t);
        data->battery_heater_1_mode         = mock_type(uint8_t);
        data->battery_heater_2_mode         = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_time_counter(sl_eps2_config_t config, uint32_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint32_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_temp(sl_eps2_config_t config, sl_eps2_temp_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_temp_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_current(sl_eps2_config_t config, sl_eps2_current_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_current_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_reset_cause(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_reset_counter(sl_eps2_config_t config, uint16_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_solar_panel_voltage(sl_eps2_config_t config, uint8_t sp, uint16_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(sp);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_solar_panel_current(sl_eps2_config_t config, uint8_t sp, sl_eps2_current_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(sp);

    return mock_type(int);
}

int __wrap_sl_eps2_read_mppt_duty_cycle(sl_eps2_config_t config, uint8_t mppt, sl_eps2_duty_cycle_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(mppt);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_duty_cycle_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_main_bus_voltage(sl_eps2_config_t config, sl_eps2_voltage_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_voltage_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_rtd_temperature(sl_eps2_config_t config, uint8_t rtd, sl_eps2_temp_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(rtd);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_temp_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_voltage(sl_eps2_config_t config, sl_eps2_voltage_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_voltage_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_current(sl_eps2_config_t config, uint8_t cur, sl_eps2_current_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(cur);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_current_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_charge(sl_eps2_config_t config, sl_eps2_charge_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_charge_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_temp(sl_eps2_config_t config, sl_eps2_temp_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_temp_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_status(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_protection(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_cycle_counter(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_raac(sl_eps2_config_t config, sl_eps2_charge_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_charge_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_rsac(sl_eps2_config_t config, sl_eps2_charge_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_charge_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_rarc(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_battery_monitor_rsrc(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_heater_duty_cycle(sl_eps2_config_t config, uint8_t heater, sl_eps2_duty_cycle_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(heater);

    if (val != NULL)
    {
        *val = mock_type(sl_eps2_duty_cycle_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_hardware_version(sl_eps2_config_t config, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_read_firmware_version(sl_eps2_config_t config, uint32_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_set_mppt_mode(sl_eps2_config_t config, uint8_t mppt, uint8_t mode)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(mppt);
    check_expected(mode);

    return mock_type(int);
}

int __wrap_sl_eps2_get_mppt_mode(sl_eps2_config_t config, uint8_t mppt, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(mppt);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

int __wrap_sl_eps2_set_heater_mode(sl_eps2_config_t config, uint8_t heater, uint8_t mode)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(heater);
    check_expected(mode);

    return mock_type(int);
}

int __wrap_sl_eps2_get_heater_mode(sl_eps2_config_t config, uint8_t heater, uint8_t *val)
{
    check_expected(config.i2c_port);
    check_expected(config.i2c_config.speed_hz);
    check_expected(config.en_pin);
    check_expected(config.ready_pin);

    check_expected(heater);

    if (val != NULL)
    {
        *val = mock_type(uint8_t);
    }

    return mock_type(int);
}

void __wrap_sl_eps2_delay_ms(uint32_t ms)
{
    function_called();

    return;
}

/** \} End of sl_eps2_wrap group */
