#!/bin/bash

config-pin 9.12 in+

g++ led.cpp GPIO.cpp -o button_read.cgi -lcgicc -pthread

echo "Program has been built"
