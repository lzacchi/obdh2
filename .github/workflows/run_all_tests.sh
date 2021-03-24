#!/bin/bash

# cd ../../../.github/workflows/
# cd ../../firmware/tests/devices/

./current_sensor_unit_test | grep -q "FAILED" && { echo "There were failed tests"; exit 1; }

# echo "PASSED"
