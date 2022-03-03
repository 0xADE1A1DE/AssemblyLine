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

    if(TEST_TARGET_FILENAME STREQUAL "compile_asm")
        continue()
    endif()

    # create a target for the test binary
    add_executable(${TEST_TARGET_FILENAME} ${TESTFILE_SRC})

    add_dependencies(${TEST_TARGET_FILENAME} assemblyline)

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

    unset(TEST_TARGET_FILENAME)
endforeach()

file(
    COPY ${ASSEMBLYLINE_TEST_DIR}/
    DESTINATION asm
    FILES_MATCHING PATTERN "*.asm"
    PERMISSIONS OWNER_WRITE OWNER_READ
)



if(NOT MSVC)

set(ASSEMBLYLINE_TEST_ASM_DIR ${ASSEMBLYLINE_TEST_DIR}/inc)
set(
    ASM_TEST_CASES

    test_adc
)

foreach(ASM_TEST_CASE ${ASM_TEST_CASES})

    # create the template file
    configure_file(${ASSEMBLYLINE_TEST_DIR}/compile_asm.c.in ${ASSEMBLYLINE_TEST_DIR}/compile_asm.c)

    # create a target for the test binary
    add_executable(${ASM_TEST_CASE} ${ASSEMBLYLINE_TEST_DIR}/compile_asm.c)

    add_dependencies(${ASM_TEST_CASE} assemblyline)
    target_compile_options(${ASM_TEST_CASE} PRIVATE -masm=intel)
    target_include_directories(${ASM_TEST_CASE} PUBLIC ${ASSEMBLYLINE_TEST_ASM_DIR} $<TARGET_PROPERTY:assemblyline,INCLUDE_DIRECTORIES>)

    # link the test binary with assemblyline
    target_link_libraries(${ASM_TEST_CASE} PRIVATE $<TARGET_LINKER_FILE:assemblyline>)

    unset(ASM_TEST_CASE)
endforeach()

endif()
