#!/bin/bash

echo "[!] Grab sample object files from book's website..."

set -x

wget https://linker.iecc.com/ch4main.lk
wget https://linker.iecc.com/ch4calif.lk
wget https://linker.iecc.com/ch4mass.lk
wget https://linker.iecc.com/ch4newyork.lk
