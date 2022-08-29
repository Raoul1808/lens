cmake_minimum_required(VERSION 3.23)
project(lens)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/SDL)
add_subdirectory(external/glad)
add_subdirectory(external/imgui-cmake)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(lens ${SOURCES})
target_include_directories(lens PRIVATE src/)
target_link_libraries(lens PRIVATE SDL2 ${CMAKE_DL_LIBS} Glad ImGui)
