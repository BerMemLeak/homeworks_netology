cmake_minimum_required(VERSION 3.0)
project(main_proj VERSION 0.1 LANGUAGES CXX)
include_directories(Leaver)
add_executable(main_proj main.cpp)
add_subdirectory(Leaver)

target_link_libraries(main_proj Leaver_lib)
