cmake_minimum_required(VERSION 3.10)
project(Leaver_lib)

set(SOURCES
   Leaver.cpp
)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Leaver_lib SHARED ${SOURCES})



