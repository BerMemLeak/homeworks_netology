cmake_minimum_required(VERSION 3.27)
project(1)

set(CMAKE_CXX_STANDARD 20)

add_executable(1
        main.cpp
        Shape/Inherited_figures/Circle/Circle.h
        Shape/Inherited_figures/Cube/Cube.h
        Shape/Inherited_figures/Cylinder/Cylinder.h
        Shape/Inherited_figures/Line/Line.h
        Shape/Inherited_figures/Square/Square.h
        Shape/shape.h
        Shape/shape.cpp
        Shape/Inherited_figures/Circle/Circle.cpp
        Shape/Inherited_figures/Cube/Cube.cpp
        Shape/Inherited_figures/Cylinder/Cylinder.cpp
        Shape/Inherited_figures/Line/Line.cpp
        Shape/Inherited_figures/Square/Square.cpp
)
