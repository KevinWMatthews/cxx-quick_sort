cmake_minimum_required(VERSION 3.5.1)
project(quick_sort VERSION 0.0.1)

enable_language(CXX)

option(COMPILE_UNIT_TESTS "Compile unit tests" ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if(COMPILE_UNIT_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
