cmake_minimum_required(VERSION 3.31)
project(Main)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.h Source/*.hpp)
add_executable(Main ${SOURCES})
target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(Main PRIVATE sfml-graphics sfml-window sfml-system)
