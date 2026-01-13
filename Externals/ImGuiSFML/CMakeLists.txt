cmake_minimum_required(VERSION 3.31)
project(ImGuiSFML)

file(GLOB_RECURSE IMGUI_SOURCES Source/*.cpp)
add_library(ImGuiSFML STATIC ${IMGUI_SOURCES})
target_include_directories(ImGuiSFML PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(ImGuiSFML PUBLIC ImGui sfml-graphics sfml-window sfml-system)
