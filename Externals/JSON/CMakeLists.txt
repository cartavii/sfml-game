cmake_minimum_required(VERSION 3.31)
project(JSON)

add_library(JSON INTERFACE)
target_include_directories(JSON INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
