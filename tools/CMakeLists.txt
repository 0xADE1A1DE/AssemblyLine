set(ASSEMBLYLINE_TOOLS_DIR ${ASSEMBLYLINE_ROOT_DIR}/tools CACHE INTERNAL "ASSEMBLYLINE_TOOLS_DIR")

if(MSVC)
    set(
        SOURCE_FILES

        ${ASSEMBLYLINE_TOOLS_DIR}/getopt.c
        ${ASSEMBLYLINE_TOOLS_DIR}/asmline.c
    )

    set(
        HEADER_DIRS

        ${ASSEMBLYLINE_SRC_DIR}
        ${ASSEMBLYLINE_TOOLS_DIR}
    )
else()
    set(
        SOURCE_FILES

        ${ASSEMBLYLINE_TOOLS_DIR}/asmline.c
    )

    set(
        HEADER_DIRS

        ${ASSEMBLYLINE_SRC_DIR}
    )

    if(DEBUG)
        add_compile_options(-ggdb)
    endif(DEBUG)
endif()

add_executable(asmline ${SOURCE_FILES})

add_dependencies(asmline assemblyline)

target_include_directories(asmline PUBLIC ${HEADER_DIRS})

target_link_libraries(asmline $<TARGET_LINKER_FILE:assemblyline>)

add_custom_command(
    TARGET asmline POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:assemblyline>
    $<TARGET_FILE_DIR:asmline>
)

install(TARGETS asmline DESTINATION bin)
