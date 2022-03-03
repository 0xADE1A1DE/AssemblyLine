cmake_minimum_required(VERSION 3.16)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(AssemblyLine
    LANGUAGES C
    VERSION 1.2.0
    DESCRIPTION "A C library and binary for generating machine code of x86_64 assembly language and executing on the fly."
    HOMEPAGE_URL https://github.com/0xADE1A1DE/AssemblyLine
)

include(CTest)

set(PROJECT_AUTHOR 0xADE1A1DE)
set(PROJECT_LICENSE "Apache License 2.0")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(DEBUG             "Compile with debug symbols"                       ON)
option(BUILD_TOOLKIT     "Compile the tools"                                ON)
option(BUILD_TESTING     "Compile the test suite"                           OFF)


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


if(BUILD_TESTING)
    #
    # Build toolkit
    #
    add_subdirectory(test)
endif()


#
# Populate the pkgconfig file
#
if(NOT WIN32)
    configure_file(assemblyline.pc.in assemblyline.pc @ONLY)
    install(FILES assemblyline.pc DESTINATION lib/pkgconfig/)
endif()
