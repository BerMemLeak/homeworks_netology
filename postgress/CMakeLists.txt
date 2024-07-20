cmake_minimum_required(VERSION 3.27)
project(postgress)

add_subdirectory("/usr/local/Cellar/libpqxx-7.9.1 2" libpqxx-build)

set(CMAKE_CXX_STANDARD 17)

add_executable(postgress main.cpp)
target_link_libraries(postgress pqxx)