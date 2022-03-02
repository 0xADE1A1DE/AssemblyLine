set(ASSEMBLYLINE_SRC_DIR ${ASSEMBLYLINE_ROOT_DIR}/src CACHE INTERNAL "ASSEMBLYLINE_SRC_DIR")
set(ASSEMBLYLINE_MAN_DIR ${ASSEMBLYLINE_ROOT_DIR}/man CACHE INTERNAL "ASSEMBLYLINE_MAN_DIR")

include (GenerateExportHeader)

set(
    HEADER_FILES

    ${ASSEMBLYLINE_SRC_DIR}/assembler.h
    ${ASSEMBLYLINE_SRC_DIR}/common.h
    ${ASSEMBLYLINE_SRC_DIR}/encoder.h
    ${ASSEMBLYLINE_SRC_DIR}/enums.h
    ${ASSEMBLYLINE_SRC_DIR}/instr_parser.h
    ${ASSEMBLYLINE_SRC_DIR}/instruction_data.h
    ${ASSEMBLYLINE_SRC_DIR}/instructions.h
    ${ASSEMBLYLINE_SRC_DIR}/parser.h
    ${ASSEMBLYLINE_SRC_DIR}/prefix.h
    ${ASSEMBLYLINE_SRC_DIR}/reg_parser.h
    ${ASSEMBLYLINE_SRC_DIR}/registers.h
    ${ASSEMBLYLINE_SRC_DIR}/tokenizer.h
)

set(
    SOURCE_FILES

    ${ASSEMBLYLINE_SRC_DIR}/assembler.c
    ${ASSEMBLYLINE_SRC_DIR}/assemblyline.c
    ${ASSEMBLYLINE_SRC_DIR}/encoder.c
    ${ASSEMBLYLINE_SRC_DIR}/instr_parser.c
    ${ASSEMBLYLINE_SRC_DIR}/instructions.c
    ${ASSEMBLYLINE_SRC_DIR}/parser.c
    ${ASSEMBLYLINE_SRC_DIR}/prefix.c
    ${ASSEMBLYLINE_SRC_DIR}/reg_parser.c
    ${ASSEMBLYLINE_SRC_DIR}/registers.c
    ${ASSEMBLYLINE_SRC_DIR}/tokenizer.c
)

configure_file(
    "${ASSEMBLYLINE_SRC_DIR}/config.h.in"
    "${ASSEMBLYLINE_SRC_DIR}/config.h"
)

add_library(assemblyline SHARED ${SOURCE_FILES})

if (MSVC)
    add_compile_options(/W3 /WX /Wall /sdl /guard:cf /guard:ehcont /CETCOMPAT)
    set(
        LINKING_LIBS

        kernel32.lib
        ntdll.lib
    )
else()
    add_compile_definitions(_GNU_SOURCE=1)
    add_compile_options(-Wall -Wextra -std=gnu99 -fPIC)

    if(DEBUG)
        add_compile_options(-ggdb)
    endif(DEBUG)

    set(
        LINKING_LIBS

        m
    )
endif()

#
# Linking directives
#
target_include_directories(assemblyline PUBLIC ${ASSEMBLYLINE_SRC_DIR}/)
target_sources(assemblyline PRIVATE ${ASSEMBLYLINE_SRC_DIR}/)

GENERATE_EXPORT_HEADER(
    assemblyline
    BASE_NAME assemblyline
    EXPORT_MACRO_NAME assemblyline_export
    EXPORT_FILE_NAME assemblyline_export.hpp
    STATIC_DEFINE assemblyline_built_as_static
)

target_link_libraries(assemblyline PUBLIC ${LINKING_LIBS})
set_target_properties(
    assemblyline
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

#
# Install directives
#
install(TARGETS assemblyline DESTINATION lib)
install(FILES ${ASSEMBLYLINE_SRC_DIR}/assemblyline.h DESTINATION include)

if(NOT WIN32)
    install(FILES ${ASSEMBLYLINE_MAN_DIR}/asmline.1 DESTINATION man/man1)
    install(FILES ${ASSEMBLYLINE_MAN_DIR}/libassemblyline.3 DESTINATION man/man3)
endif()
