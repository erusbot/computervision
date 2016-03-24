cmake_minimum_required(VERSION 2.8)
project(computer_vision)

set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")
set (LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set (EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

include_directories (sample)
add_subdirectory (sample)
