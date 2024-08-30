# ---- Declare library ----

file(GLOB_RECURSE [[name]]_[[name]]_sources CONFIGURE_DEPENDS "src/[[name]]/*.cpp")
add_library(
    [[name]]_[[name]]
    ${[[name]]_[[name]]_sources}
)
add_library([[name]]::[[name]] ALIAS [[name]]_[[name]])

include(GenerateExportHeader)
generate_export_header(
    [[name]]_[[name]]
    BASE_NAME [[name]]
    EXPORT_FILE_NAME export/[[name]]/[[name]]_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions([[name]]_[[name]] PUBLIC [%C[name]%C]_STATIC_DEFINE)
endif()

set_target_properties(
    [[name]]_[[name]] PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME [[name]]
    OUTPUT_NAME [[name]]
)

target_include_directories(
    [[name]]_[[name]] ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    [[name]]_[[name]] SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features([[name]]_[[name]] PUBLIC cxx_std_17)

# ---- external libs ----

include(cmake/external-lib.cmake)
