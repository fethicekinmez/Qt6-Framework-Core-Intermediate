cmake_minimum_required(VERSION 3.16)

project(02-Move_to_Thread LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(02-Move_to_Thread
  main.cpp
  task.h task.cpp
)
target_link_libraries(02-Move_to_Thread Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 02-Move_to_Thread
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
