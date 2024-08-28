cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    [[name]]
    VERSION 0.1.0
    DESCRIPTION ""
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    [[name]]_lib OBJECT
    src/lib.cpp
)

target_include_directories(
    [[name]]_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features([[name]]_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable([[name]]_exe src/main.cpp)
add_executable([[name]]::exe ALIAS [[name]]_exe)

set_property(TARGET [[name]]_exe PROPERTY OUTPUT_NAME [[name]])

target_compile_features([[name]]_exe PRIVATE cxx_std_17)

target_link_libraries([[name]]_exe PRIVATE [[name]]_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT [[name]]_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of project"
  )
endif()

include(cmake/dev-mode.cmake)
