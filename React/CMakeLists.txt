cmake_minimum_required(VERSION 3.31)
project(React)

set(CMAKE_CXX_STANDARD 20)

# Добавляем все заголовочные файлы из всех подпапок
file(GLOB_RECURSE REACT_HEADERS *.hpp)

add_library(React INTERFACE)

# Добавляем include директорию рекурсивно (корень + все подпапки)
target_include_directories(React INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Source>
)
