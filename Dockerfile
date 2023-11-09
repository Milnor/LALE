FROM ubuntu:22.04
LABEL Description="Cross-Architecture build environment"

ENV HOME / root

SHELL ["/bin/bash", "-c"]

# I don't know if gcc-11-multilib and libc-dev were necessary.
# Removing --no-install-recommends fixed the problem I was 
# having with cross-compilation


RUN apt-get update && apt-get -y install \
    build-essential \
    cmake \
    gcc \
    gcc-11-multilib \
    gcc-arm-linux-gnueabi \
    gcc-mips-linux-gnu \
    gcc-powerpc-linux-gnu \
    gcc-mingw-w64 \
    gdb \
    libc-dev

