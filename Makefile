BUILDDIR=build
CCNATIVE=gcc
SAMPLEEXEC=samples/src/executable.c
SHELL:=/bin/bash

# Cross Compilers
CCARM=arm-linux-gnueabi-gcc
CCMIPS=mips-linux-gnu-gcc
CCPPC=powerpc-linux-gnu-gcc
CCWIN=x86_64-w64-mingw32-gcc

DOCKER_RUN_PARAMS=-it --rm --name=lale \
	 --mount type=bind,source=${PWD},target=/src lale/multiarch:0.1.0

lale:
	docker run ${DOCKER_RUN_PARAMS} \
		bash -c \ 
		"cd src && cmake -S . -B $(BUILDDIR) && cmake --build $(BUILDDIR)"

# Build the docker image
docker-image: Dockerfile
	docker build -t lale/multiarch:0.1.0 -f Dockerfile .

# Launch the docker container
docker-start:
	docker run ${DOCKER_RUN_PARAMS}

# Placeholders for executable formats I either don't have the hardware to
#  compile or that don't exist yet
fakes: hello_mac hello_she

samples: hello_native64 hello_native32 hello_arm hello_mips hello_ppc hello_win

hello_win: $(SAMPLEEXEC)
	$(CCWIN) $(SAMPLEEXEC) -o $(BUILDDIR)/win.exe

hello_arm: $(SAMPLEEXEC)
	$(CCARM) $(SAMPLEEXEC) -o $(BUILDDIR)/arm

hello_mips: $(SAMPLEEXEC)
	$(CCMIPS) $(SAMPLEEXEC) -o $(BUILDDIR)/mips

hello_ppc: $(SAMPLEEXEC)
	$(CCPPC) $(SAMPLEEXEC) -o $(BUILDDIR)/ppc

hello_native32: $(SAMPLEEXEC)
	$(CCNATIVE) $(SAMPLEEXEC) -m32 -o $(BUILDDIR)/native32

hello_native64: $(SAMPLEEXEC)
	mkdir -p $(BUILDDIR)
	$(CCNATIVE) $(SAMPLEEXEC) -o $(BUILDDIR)/native64

hello_mac:
	mkdir -p $(BUILDDIR)
	echo -en "\xfe\xed\xfa\xce" > $(BUILDDIR)/mac
	dd bs=1 count=128 if=/dev/zero >> $(BUILDDIR)/mac

hello_she:
	echo -en "\x1a\x1eSHE" > $(BUILDDIR)/she
	dd bs=1 count=128 if=/dev/zero >> $(BUILDDIR)/she

.PHONY: clean
clean:
	docker run ${DOCKER_RUN_PARAMS} \
		bash -c \
		"cd src && \
		rm -rf $(BUILDDIR)"

