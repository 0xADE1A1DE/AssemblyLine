include (GenerateExportHeader)

set(
    HEADER_FILES

    ./assembler.h
    ./common.h
    ./encoder.h
    ./enums.h
    ./instr_parser.h
    ./instruction_data.h
    ./instructions.h
    ./parser.h
    ./prefix.h
    ./reg_parser.h
    ./registers.h
    ./tokenizer.h
)

set(
    SOURCE_FILES

    ./assembler.c
    ./assemblyline.c
    ./encoder.c
    ./instr_parser.c
    ./instructions.c
    ./parser.c
    ./prefix.c
    ./reg_parser.c
    ./registers.c
    ./tokenizer.c
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
    set(
        LINKING_LIBS

        m
    )
endif()

target_include_directories(AssemblyLine PUBLIC src/)
target_sources(AssemblyLine PUBLIC src/)

GENERATE_EXPORT_HEADER(
    AssemblyLine
    BASE_NAME AssemblyLine
    EXPORT_MACRO_NAME AssemblyLine_EXPORT
    EXPORT_FILE_NAME assemblyline_export.hpp
    STATIC_DEFINE assemblyline_built_as_static
)

target_link_libraries(AssemblyLine PRIVATE ${LINKING_LIBS})
