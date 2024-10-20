#include <catch2/catch_test_macros.hpp>
#include "Grid.h"
#include "Tetromino.h"
#include "Position.h"

TEST_CASE("Testting the addTetroMéthode") {

    std::vector<model::Position> tetrominoPos;
    tetrominoPos.push_back(model::Position(0, 10 / 2));
    tetrominoPos.push_back(model::Position(0, 10 / 2 + 1));
    tetrominoPos.push_back(model::Position(1, 10 / 2));
    tetrominoPos.push_back(model::Position(1, 10 / 2 + 1));


    model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);

    SECTION("Adding a tetromino with unoccupied positions") {
        model::Grid grid(10, 10);
        bool result = grid.addTetromino(tetromino);
        REQUIRE(result == false); //false = il l'a poser

    }

    SECTION("Adding a tetromino when the grid is full") {
        model::Grid grid(10, 10);
        model::Tetromino tetromino2(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);

        for (int var = 0; var < 10; ++var) {
            for (int col = 0; col < 10; ++col) {
                grid.grid[var][col].setOccupied(true);
            }
        }
        bool result = grid.addTetromino(tetromino2);
        REQUIRE(result == true); //true = il a pas poser

    }



}
TEST_CASE("Testing the remove line méthdoe ") {

    SECTION("test delete line") {
        model::Grid grid(10, 10);

        for (int var = 0; var < grid.getWidth(); ++var) {
            grid.grid[2][var].setOccupied(true);
        }

        grid.searchAndRemoveFullLines();
        for (int var = 0; var < grid.getWidth(); ++var) {
            REQUIRE(grid.grid[2][var].isOccupied() == false);
        }

    }
    SECTION("test delete line and make blocks fall") {
        model::Grid grid(10, 10);


        for (int var = 0; var < grid.getWidth(); ++var) {
            if (var%2==0){
                grid.grid[2][var].setOccupied(true);
            }
        }

        for (int var = 0; var < grid.getWidth(); ++var) {
            grid.grid[3][var].setOccupied(true);
        }

        grid.searchAndRemoveFullLines();

        for (int var = 0; var < grid.getWidth(); ++var) {
            if (var%2==0){
                REQUIRE(grid.grid[3][var].isOccupied() == true);

            }
            if (var % 2 != 0){
                REQUIRE(grid.grid[3][var].isOccupied() == false);
            }
        }
    }


}
TEST_CASE("test for the isInside méthode") {

    SECTION("the Tetro is inside the grid") {
        std::vector<model::Position> tetrominoPos;
        tetrominoPos.push_back(model::Position(0, 10 / 2));
        tetrominoPos.push_back(model::Position(0, 10 / 2 + 1));
        tetrominoPos.push_back(model::Position(1, 10 / 2));
        tetrominoPos.push_back(model::Position(1, 10 / 2 + 1));
        model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);
        model::Grid grid(10,10);

        bool result = grid.isInside(tetromino);

        REQUIRE(result == true);

    }
    SECTION("the Tetro is not inside the grid") {
        std::vector<model::Position> tetrominoPos;
        tetrominoPos.push_back(model::Position(12, 10 / 2));
        tetrominoPos.push_back(model::Position(12, 10 / 2 + 1));
        tetrominoPos.push_back(model::Position(13, 10 / 2));
        tetrominoPos.push_back(model::Position(13, 10 / 2 + 1));
        model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);
        model::Grid grid(10,10);

        bool result = grid.isInside(tetromino);

        REQUIRE(result == false);

    }
}
TEST_CASE("test pour deleteShape ") {

    SECTION("remove a shape"){

        std::vector<model::Position> tetrominoPos;
        tetrominoPos.push_back(model::Position(0, 10 / 2));
        tetrominoPos.push_back(model::Position(0, 10 / 2 + 1));
        tetrominoPos.push_back(model::Position(1, 10 / 2));
        tetrominoPos.push_back(model::Position(1, 10 / 2 + 1));
        model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);
        model::Grid grid(10,10);

        grid.addTetromino(tetromino);

        grid.removeTetromino(tetromino);

        REQUIRE(grid.grid[0][10 / 2].isOccupied() == false);
        REQUIRE(grid.grid[0][0 / 2 + 1].isOccupied() == false);
        REQUIRE(grid.grid[1][0 / 2].isOccupied() == false);
        REQUIRE(grid.grid[1][0 / 2 + 1].isOccupied() == false);

    }

}
TEST_CASE("test pour aroundTetro ") {

    SECTION("around tero"){
        std::vector<model::Position> tetrominoPos;
        tetrominoPos.push_back(model::Position(5, 10 / 2));
        tetrominoPos.push_back(model::Position(5, 10 / 2 + 1));
        tetrominoPos.push_back(model::Position(6, 10 / 2));
        tetrominoPos.push_back(model::Position(6, 10 / 2 + 1));
        model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);
        model::Grid grid(20,20);

        grid.addTetromino(tetromino);
        std::vector<model::Position> around =grid.aroundTetro(tetromino);

        REQUIRE(around.size() == 0);
    }

    SECTION("around tero"){
        std::vector<model::Position> tetrominoPos;
        tetrominoPos.push_back(model::Position(5, 10 / 2));
        tetrominoPos.push_back(model::Position(5, 10 / 2 + 1));
        tetrominoPos.push_back(model::Position(6, 10 / 2));
        tetrominoPos.push_back(model::Position(6, 10 / 2 + 1));
        model::Tetromino tetromino(model::Color::BLUE,model::TypeBrick::J,10,tetrominoPos);
        model::Grid grid(20,20);

        grid.grid[7][5].setOccupied(true);

        grid.addTetromino(tetromino);
        std::vector<model::Position> around =grid.aroundTetro(tetromino);

        REQUIRE(around.size() == 1);
        REQUIRE(around[0].getX() == 7);
        REQUIRE(around[0].getY() == 5);
    }

}














