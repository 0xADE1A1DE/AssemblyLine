cmake_minimum_required(VERSION 3.16)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(AssemblyLine LANGUAGES C)

set(PROGNAME AssemblyLine)
set(AUTHOR hugsy)
set(LICENSE MIT)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_TOOLKIT               "Compile the tools"                                                         ON)
option(BUILD_TEST                  "Compile the test suite"                                                    ON)


#
# Build library
#
add_subdirectory(src)


#
# Build toolkit
#
# add_subdirectory(tests)


#
# Build toolkit
#
# add_subdirectory(tools)
