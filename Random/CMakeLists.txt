cmake_minimum_required(VERSION 3.31)
project(Random)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE RANDOM_SOURCES Source/*.cpp)
add_library(Random STATIC ${RANDOM_SOURCES})
target_include_directories(Random PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
