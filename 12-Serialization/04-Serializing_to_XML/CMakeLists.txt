cmake_minimum_required(VERSION 3.16)

project(04-Serializing_to_XML LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(04-Serializing_to_XML
  main.cpp
  test.h test.cpp
  converter.h converter.cpp
)
target_link_libraries(04-Serializing_to_XML Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 04-Serializing_to_XML
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
