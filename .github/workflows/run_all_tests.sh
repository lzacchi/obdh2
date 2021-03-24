#!/bin/bash

# cd ../../../.github/workflows/
# cd ../../firmware/tests/devices/

./../../firmware/tests/devices/current_sensor_unit_test | grep -q "FAILED" && { exit 255; }

# echo "PASSED"
