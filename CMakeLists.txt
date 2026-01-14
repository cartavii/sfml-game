cmake_minimum_required(VERSION 3.31)
project(SFML)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Externals)

add_subdirectory(Core)
add_subdirectory(Random)
add_subdirectory(React)
add_subdirectory(Main)
