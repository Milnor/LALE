cmake_minimum_required(VERSION 3.22)

project(LALE 
	VERSION			0.1.1
	DESCRIPTION		"Vivisect PE/ELF Executables"
	LANGUAGES		C
)

#[=[
option(FRIVOLOUS "put whatever you want here" OFF)
message(STATUS "Frivolous variable = ${FRIVOLOUS}")

set(MAKE_LIBS OFF)
message(STATUS "Make libraries? ${MAKE_LIBS}")

message("C compiler flags: ${CMAKE_C_FLAGS}")

set(CMAKE_C_LANG_TIDY "clang-tidy;-checks=*")

#]=]

# The main program
add_executable(lale src/lale.c)

add_executable(executable 
	       EXCLUDE_FROM_ALL
	       samples/src/executable.c
)

add_library(library		SHARED
	    EXCLUDE_FROM_ALL
	    samples/src/library.c
)

