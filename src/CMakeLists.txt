set(ASSEMBLYLINE_SRC_DIR ${ASSEMBLYLINE_ROOT_DIR}/src CACHE INTERNAL "ASSEMBLYLINE_SRC_DIR")

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


add_library(AssemblyLine SHARED ${SOURCE_FILES})

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

target_include_directories(AssemblyLine PUBLIC ${ASSEMBLYLINE_SRC_DIR}/)
target_sources(AssemblyLine PRIVATE ${ASSEMBLYLINE_SRC_DIR}/)

GENERATE_EXPORT_HEADER(
    AssemblyLine
    BASE_NAME AssemblyLine
    EXPORT_MACRO_NAME AssemblyLine_EXPORT
    EXPORT_FILE_NAME assemblyline_export.hpp
    STATIC_DEFINE assemblyline_built_as_static
)

target_link_libraries(AssemblyLine PUBLIC ${LINKING_LIBS})
