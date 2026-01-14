cmake_minimum_required(VERSION 3.31)
project(Core)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CORE_SOURCES Source/*.cpp)
add_library(Core STATIC ${CORE_SOURCES})
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(Core PUBLIC sfml-graphics sfml-window sfml-system ImGui JSON PRIVATE ImGuiSFML)
