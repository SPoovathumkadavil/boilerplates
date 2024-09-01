cmake_minimum_required(VERSION 3.16)

project([[name]]Tests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

enable_testing()

# ---- Tests ----

file(GLOB_RECURSE [[name]]_test_sources "src/*.cpp")
add_executable([[name]]_test ${[[name]]_test_sources})
target_link_libraries([[name]]_test 
  PRIVATE
  GTest::gtest_main
  [[name]]::[[name]])
target_compile_features([[name]]_test PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests([[name]]_test)

# ---- End-of-file commands ----

add_folders(Test)
