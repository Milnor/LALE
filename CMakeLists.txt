cmake_minimum_required(VERSION 3.17)
project(LALE 
	VERSION			0.1.0
	DESCRIPTION		"do sth. with Win and Linux executables"
	LANGUAGES		C
)

# The main program
add_executable(lale src/lale.c)

# Trivial binaries for testing purposes
add_library(silly
	SHARED
		src/silly.c
)
add_executable(program src/trivial.c)
target_link_libraries(program silly)
