set(ASSEMBLYLINE_TEST_DIR ${ASSEMBLYLINE_ROOT_DIR}/test CACHE INTERNAL "ASSEMBLYLINE_TEST_DIR")

add_compile_definitions(DEBUG)

add_executable(run ${ASSEMBLYLINE_TEST_DIR}/run.c)
target_include_directories(run PUBLIC ${TEST_DIR} ${ASSEMBLYLINE_SRC_DIR})
target_link_libraries(run $<TARGET_LINKER_FILE:AssemblyLine>)
add_custom_command(TARGET run POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:AssemblyLine> $<TARGET_FILE_DIR:run>)

install(TARGETS AssemblyLine DESTINATION test)
