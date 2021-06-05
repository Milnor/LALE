#!/bin/bash

#cmake -H. -Boutput
#cmake --build .

mkdir -p output
cd output
cmake .. -D FRIVOLOUS=EIEIO && make
