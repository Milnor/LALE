BUILDDIR=build
CCNATIVE=gcc
SAMPLEEXEC=samples/src/executable.c

# Cross Compilers
CCARM=arm-linux-gnueabi-gcc
CCMIPS=mips-linux-gnu-gcc
CCPPC=powerpc-linux-gnu-gcc
CCWIN=x86_64-w64-mingw32-gcc

hello:
	echo "Hello, World"

# Build the docker image
docker-image: Dockerfile
	docker build -t lale/multiarch:0.1.0 -f Dockerfile .

# Launch the docker container
docker-start:
	docker run -it --rm --name=lale \
	 --mount type=bind,source=${PWD},target=/src lale/multiarch:0.1.0 \
	 bash

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

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

