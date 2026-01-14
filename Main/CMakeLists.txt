cmake_minimum_required(VERSION 3.31)
project(Main)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MAIN_SOURCES Source/*.cpp)
add_executable(Main ${MAIN_SOURCES})
target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(Main PRIVATE JSON Core Random)
