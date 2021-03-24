#!/bin/bash

firmware/tests/devices/current_sensor_unit_test | grep -q "FAILED" && { exit 255; }
