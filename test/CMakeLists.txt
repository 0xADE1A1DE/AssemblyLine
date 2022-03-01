set(ASSEMBLYLINE_TEST_DIR ${ASSEMBLYLINE_ROOT_DIR}/test CACHE INTERNAL "ASSEMBLYLINE_TEST_DIR")


# add_executable(run ${ASSEMBLYLINE_TEST_DIR}/run.c)
# target_include_directories(run PUBLIC ${TEST_DIR} ${ASSEMBLYLINE_SRC_DIR})
# target_link_libraries(run $<TARGET_LINKER_FILE:AssemblyLine>)
# add_custom_command(TARGET run POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_FILE:AssemblyLine> $<TARGET_FILE_DIR:run>)

enable_testing()

add_compile_definitions(DEBUG)

set(
    TEST_SOURCE_FILES

    ${ASSEMBLYLINE_TEST_DIR}/check_chunk_counting.c
    ${ASSEMBLYLINE_TEST_DIR}/invalid.c
    ${ASSEMBLYLINE_TEST_DIR}/jump.c
    ${ASSEMBLYLINE_TEST_DIR}/memory_reallocation.c
    ${ASSEMBLYLINE_TEST_DIR}/optimization_disabled.c
    ${ASSEMBLYLINE_TEST_DIR}/run.c
    ${ASSEMBLYLINE_TEST_DIR}/vector_operations.c
)


foreach(TESTFILE_SRC ${TEST_SOURCE_FILES})

    # strip the suffix
    string(REGEX REPLACE ".c$" "" TESTFILE_BIN ${TESTFILE_SRC})

    # get just the filename
    get_filename_component(TEST_TARGET_FILENAME ${TESTFILE_BIN} NAME)

    # create a target for the test binary
    add_executable(${TEST_TARGET_FILENAME} ${TESTFILE_SRC})

    add_dependencies(${TEST_TARGET_FILENAME} AssemblyLine)

    # include the source headers
    target_include_directories(
        ${TEST_TARGET_FILENAME}

        PUBLIC
        ${ASSEMBLYLINE_TEST_DIR}
        ${ASSEMBLYLINE_SRC_DIR}
    )

    # link the test binary with assemblyline
    target_link_libraries(${TEST_TARGET_FILENAME} PRIVATE $<TARGET_LINKER_FILE:AssemblyLine>)

    # create the test case that will be run by `ctest`
    add_test(
        NAME
        ${TEST_TARGET_FILENAME}
        COMMAND
        $<TARGET_FILE:${TEST_TARGET_FILENAME}>
    )

    # set the installation rule
    install(TARGETS ${TEST_TARGET_FILENAME} DESTINATION test)

endforeach()

file(
    COPY ${ASSEMBLYLINE_TEST_DIR}/
    DESTINATION asm
    FILES_MATCHING PATTERN "*.asm"
    PERMISSIONS OWNER_WRITE OWNER_READ
)
