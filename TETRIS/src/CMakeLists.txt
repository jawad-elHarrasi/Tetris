cmake_minimum_required(VERSION 3.5)

project(TetrisProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

add_executable(TetrisProject
        Game.cpp
        Bag.cpp
        Grid.cpp
        Block.cpp
        Position.cpp
        Tetromino.cpp
        Factory.cpp
        TetrisException.hpp
        Bag.h
        Block.h
        Factory.h
        Game.h
        Grid.h
        Position.h
        Tetromino.h
        Color.h
        Sens.h
        Direction.h
        TypeBrick.h
        ConsoleView.h
        ConsoleView.cpp
        Controller.cpp
        Controller.h
        App.cpp
        keyboardAndStringConvert/keyboard.hpp
        keyboardAndStringConvert/stringConvert.hpp
        Observer.h
        Observable.h
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        firstwindow.h
        firstwindow.cpp
        firstwindow.ui
        Observable.cpp
        EndGameDialog.h
        EndGameDialog.cpp



    )

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
target_link_libraries(TetrisProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS TetrisProject
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
