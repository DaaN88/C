cmake_minimum_required(VERSION 3.10)

#project name
project(Raceev_lab_1)

add_executable(CmakeBegin MACOSX_BUNDLE cmake_begin.cpp)
set_target_properties(
	CmakeBegin PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	COMPILE_FLAGS "-m64"
	LINK_FLAGS "-m64"
	OSX_ARCHITECTURES "arm64;x86_64"
)
