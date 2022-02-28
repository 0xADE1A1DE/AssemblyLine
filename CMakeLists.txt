cmake_minimum_required(VERSION 3.16)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(AssemblyLine LANGUAGES C VERSION 1.2.0)

set(PROGRAM_NAME AssemblyLine)
set(PROGRAM_AUTHOR hugsy)
set(PROGRAM_LICENSE "Apache License 2.0")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(DEBUG             "Compile with debug symbols"                       ON)
option(BUILD_TOOLKIT     "Compile the tools"                                ON)
option(BUILD_TEST        "Compile the test suite"                           OFF)


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
