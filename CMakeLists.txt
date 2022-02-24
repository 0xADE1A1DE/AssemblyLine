cmake_minimum_required(VERSION 3.16)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(AssemblyLine LANGUAGES C)

set(PROGNAME AssemblyLine)
set(AUTHOR hugsy)
set(LICENSE MIT)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_TOOLKIT               "Compile the tools"                                                         ON)
option(BUILD_TEST                  "Compile the test suite"                                                    ON)


set(ASSEMBLYLINE_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})


#
# Build library
#
add_subdirectory(src)


if(BUILD_TOOLKIT)
    #
    # Build toolkit
    #
    add_subdirectory(tools)
endif()


if(BUILD_TEST)
    #
    # Build toolkit
    #
    add_subdirectory(test)
endif()
