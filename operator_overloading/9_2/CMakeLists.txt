# Устанавливаем минимальную версию CMake
set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

# Задаем имя проекта
project(MyProject)

# Добавляем исполняемый файл и исходный код для сборки
add_executable(9_2 main.cpp)