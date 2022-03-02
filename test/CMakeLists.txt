set(ASSEMBLYLINE_TEST_DIR ${ASSEMBLYLINE_ROOT_DIR}/test CACHE INTERNAL "ASSEMBLYLINE_TEST_DIR")

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
    ${ASSEMBLYLINE_TEST_DIR}/compile_asm.c
)


foreach(TESTFILE_SRC ${TEST_SOURCE_FILES})

    # strip the suffix
    string(REGEX REPLACE ".c$" "" TESTFILE_BIN ${TESTFILE_SRC})

    # get just the filename
    get_filename_component(TEST_TARGET_FILENAME ${TESTFILE_BIN} NAME)

    if(TEST_TARGET_FILENAME STREQUAL "compile_asm" AND MSVC)
        continue()
    endif()

    # create a target for the test binary
    add_executable(${TEST_TARGET_FILENAME} ${TESTFILE_SRC})

    add_dependencies(${TEST_TARGET_FILENAME} assemblyline)

    add_compile_options(-masm=intel -O0 -fomit-frame-pointer)

    # include the source headers
    target_include_directories(
        ${TEST_TARGET_FILENAME}

        PUBLIC
        ${ASSEMBLYLINE_TEST_DIR}
        ${ASSEMBLYLINE_SRC_DIR}
    )

    # link the test binary with assemblyline
    target_link_libraries(${TEST_TARGET_FILENAME} PRIVATE $<TARGET_LINKER_FILE:assemblyline>)

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
