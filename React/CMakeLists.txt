cmake_minimum_required(VERSION 3.31)
project(React)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE REACT_HEADERS *.hpp)
add_library(React INTERFACE)
target_include_directories(React INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
