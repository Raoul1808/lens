cmake_minimum_required(VERSION 3.0)
project(ImGui)

add_library(ImGui
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp)
target_include_directories(ImGui PUBLIC imgui/)
