cmake_minimum_required(VERSION 3.0)
project(GREETER_LIB VERSION 0.1 LANGUAGES CXX)
set(GREETER_LIB_sourse Greeter.h Greeter.cpp)
add_library(GREETER_LIB STATIC ${GREETER_LIB_sourse})
