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


#
# Set up the instruction tests
#

if(NOT MSVC)

set(ASSEMBLYLINE_TEST_ASM_DIR ${ASSEMBLYLINE_TEST_DIR}/inc)
set(
    ASM_TEST_CASES

    test_adc
    test_adcx
    test_add
    test_adox
    test_and
    test_bextr
    test_bzhi
    test_clc
    test_cmp
    test_high_low_xmm
    test_imul
    test_lea
    test_lea_no_base
    test_movd
    test_mov
    test_movntdqa
    test_movntq
    test_movq
    test_mov_reg_imm32
    test_MOV_REG_IMM
    test_movzx
    test_mulx
    test_negative_mem_disp
    test_new_instruction
    test_nop
    test_no_ptr
    test_not
    test_or
    test_paddb
    test_paddd
    test_paddq
    test_paddw
    test_pand
    test_pmuldq
    test_pmulhuw
    test_pmulhw
    test_pmulld
    test_pmullq
    test_pmullw
    test_pmuludq
    test_por
    test_prefetch
    test_psubb
    test_psubd
    test_psubq
    test_psubw
    test_ptr
    test_pxor
    test_rdtsc
    test_rdtscp
    test_ror
    test_rorx
    test_sarx
    test_sbb
    test_setcc
    test_setc
    test_seto
    test_shld
    test_shl
    test_shlx
    test_shrd
    test_shr
    test_shrx
    test_skip_add
    test_sub
    test_test
    test_vaddpd
    test_vector_add
    test_vector_add_mem
    test_vector_float_divide
    test_vector_float_mul
    test_vector_mul
    test_vector_sub
    test_vmovupd
    test_vperm2i128
    test_vsubpd
    test_xor
    test_xorMI
    test_xorRM
    test_zero_byte_rbp
)

foreach(ASM_TEST_CASE ${ASM_TEST_CASES})
    set(SOURCE_FILE /tmp/test_${ASM_TEST_CASE}.c)

    # create the template file
    configure_file(${ASSEMBLYLINE_TEST_DIR}/compile_asm.c.in ${SOURCE_FILE})

    # create a target for the test binary
    add_executable(${ASM_TEST_CASE} ${SOURCE_FILE})

    add_dependencies(${ASM_TEST_CASE} assemblyline)
    target_compile_options(${ASM_TEST_CASE} PRIVATE -masm=intel)
    target_include_directories(${ASM_TEST_CASE} PUBLIC ${ASSEMBLYLINE_TEST_ASM_DIR} $<TARGET_PROPERTY:assemblyline,INCLUDE_DIRECTORIES>)

    # if you want a very verbose output, uncomment the following line
    add_compile_definitions(TEST_DEBUG=1)

    # link the test binary with assemblyline
    target_link_libraries(${ASM_TEST_CASE} PRIVATE $<TARGET_LINKER_FILE:assemblyline>)

    # create the test case that will be run by `ctest`
    add_test(NAME ${ASM_TEST_CASE}
        COMMAND $<TARGET_FILE:${ASM_TEST_CASE}>)

    # set the installation rule
    install(TARGETS ${ASM_TEST_CASE} DESTINATION test)

    unset(ASM_TEST_CASE)
endforeach()

endif() # NOT MSVC
