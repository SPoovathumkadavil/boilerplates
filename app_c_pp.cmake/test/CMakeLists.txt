# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

cmake_minimum_required(VERSION 3.16)

project([[name]]Tests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Tests ----

enable_testing()

file(GLOB_RECURSE [[name]]_test_sources "src/*.cpp")
add_executable([[name]]_test ${[[name]]_test_sources})
target_link_libraries([[name]]_test 
  PRIVATE
  GTest::gtest_main
  [[name]]_lib)
target_compile_features([[name]]_test PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests([[name]]_test)

# ---- add resource files ----

file(GLOB_RECURSE test_resources "resources/*")
file(COPY ${test_resources}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources)

# ---- End-of-file commands ----

add_folders(Test)
