cmake_minimum_required(VERSION 3.5)

add_executable(tetrisTest
    GridTest.cpp
    TetrominoTest.cpp
    ../src/Game.cpp
    ../src/Bag.cpp
    ../src/Grid.cpp
    ../src/Block.cpp
    ../src/Position.cpp
    ../src/Tetromino.cpp
    ../src/Factory.cpp
    ../src/Game.h
    ../src/Bag.h
    ../src/Grid.h
    ../src/Block.h
    ../src/Position.h
    ../src/Tetromino.h
    ../src/Factory.h
    ../src/Observable.h
    ../src/Observable.cpp
    ../src/Observer.h


)
target_include_directories(tetrisTest PRIVATE
    ../src
)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(tetrisTest Catch2::Catch2WithMain)
