cmake_minimum_required(VERSION 3.23)
project(lens)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/SDL)

add_executable(lens main.cpp)
target_link_libraries(lens PRIVATE SDL2)
