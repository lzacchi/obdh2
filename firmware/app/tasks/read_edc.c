/*
 * read_edc.h
 * 
 * Copyright The OBDH 2.0 Contributors.
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
 * along with OBDH 2.0. If not, see <http:/\/www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief Read EDC task implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.8.23
 * 
 * \date 2020/08/16
 * 
 * \addtogroup read_edc
 * \{
 */

#include <system/sys_log/sys_log.h>
#include <devices/payload/payload.h>

#include "read_edc.h"
#include "startup.h"

xTaskHandle xTaskReadEDCHandle;

pl_edc_hk_raw_t edc_hk_buf = {0};

void vTaskReadEDC(void)
{
    static payload_t pl_edc_active = PAYLOAD_EDC_0;

    /* Wait startup task to finish */
    xEventGroupWaitBits(task_startup_status, TASK_STARTUP_DONE, pdFALSE, pdTRUE, pdMS_TO_TICKS(TASK_READ_EDC_INIT_TIMEOUT_MS));

    while(1)
    {
        TickType_t last_cycle = xTaskGetTickCount();

        if (payload_get_data(pl_edc_active, PAYLOAD_EDC_RAW_HK, edc_hk_buf.buffer, &edc_hk_buf.length) != 0)
        {
            sys_log_print_event_from_module(SYS_LOG_INFO, TASK_READ_EDC_NAME, "Error reading the housekeeping data!");
            sys_log_new_line();
        }

        vTaskDelayUntil(&last_cycle, pdMS_TO_TICKS(TASK_READ_EDC_PERIOD_MS));
    }
}

/** \} End of read_edc group */
