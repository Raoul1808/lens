cmake_minimum_required(VERSION 3.23)
project(lens)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/SDL)
add_subdirectory(external/glad)
add_subdirectory(external/imgui-cmake)
add_subdirectory(external/glm)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(lens ${SOURCES})
target_include_directories(lens PRIVATE src/)
target_include_directories(lens PUBLIC external/stb)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(SDL2_LIBS SDL2main SDL2)
else()
    set(SDL2_LIBS SDL2)
endif()

target_link_libraries(lens PRIVATE ${SDL2_LIBS} ${CMAKE_DL_LIBS} Glad ImGui glm)

file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)
