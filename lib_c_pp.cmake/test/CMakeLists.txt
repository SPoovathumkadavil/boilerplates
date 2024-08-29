cmake_minimum_required(VERSION 3.14)

project([[name]]Tests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package([[name]] REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

file(GLOB_RECURSE [[name]]_test_sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable([[name]]_test ${[[name]]_test_sources})
target_link_libraries([[name]]_test PRIVATE [[name]]::[[name]])
target_compile_features([[name]]_test PRIVATE cxx_std_17)

add_test(NAME [[name]]_test COMMAND [[name]]_test)

# ---- End-of-file commands ----

add_folders(Test)
