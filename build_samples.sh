#!/usr/bin/env bash

# Download cross-toolchains (if needed) and build
#  sample binaries for LALE to parse.

# TODO: incorporate into CMakeLists.txt or replace entirely

# Two lists because executables and install packages
#  are mostly named differently
compilers=(gcc mips-linux-gnu-gcc x86_64-w64-mingw32-gcc)
installers=(gcc gcc-mips-linux-gnu gcc-mingw-w64)
binaries=(native_elf mips_elf win.exe)

for i in "${!compilers[@]}"; do
    "${compilers[i]}" --version 2>&1 /dev/null
    if [ $? -ne 0 ]; then
        sudo apt install "${installers[i]}"
    else
        echo "[+] found ${compilers[i]}"
    fi
    "${compilers[i]}" samples/src/executable.c -o build/"${binaries[i]}"
done

