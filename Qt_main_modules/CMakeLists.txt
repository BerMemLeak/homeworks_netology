cmake_minimum_required(VERSION 3.16)

project(Qt_main_modules LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Network)

add_executable(Qt_main_modules
  main.cpp
)
target_link_libraries(Qt_main_modules Qt${QT_VERSION_MAJOR}::Core Qt6::Network)

include(GNUInstallDirs)
install(TARGETS Qt_main_modules
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
