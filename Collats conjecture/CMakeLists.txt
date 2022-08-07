cmake_minimum_required(VERSION 3.10)

#project_name
project(collatz_conjecture)

add_executable(collatz_conj MACOSX_BUNDLE collatz_conj.cpp)
set_target_properties(
	collatz_conj PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	COMPILE_FLAGS "-m64"
	LINK_FLAGS "-m64"
	OSX_ARCHITECTURES "arm64;x86_64"
)
