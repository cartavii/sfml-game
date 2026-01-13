cmake_minimum_required(VERSION 3.31)
project(ImGui)

file(GLOB_RECURSE IMGUI_SOURCES Source/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES})
target_include_directories(ImGui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
