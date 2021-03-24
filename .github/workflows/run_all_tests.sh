#!/bin/bash

firmware/tests/devices/temp_sensor_unit_test | grep -q "FAILED" && { exit 255; }
