cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

#Declare build of mpags cipher main program
add_executable(mpags-cipher_initial 
	mpags-cipher_initial.cpp
	MPAGSCipher/TransformChar.cpp
	)

target_include_directories(mpags-cipher_initial 
	PRIVATE MPAGSCipher
	)

# Don't allow C++ compiler extensions
set(CMAKE_CXX_EXTENSTIONS OFF)

# Set the flags to use
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher_initial
	PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
	)