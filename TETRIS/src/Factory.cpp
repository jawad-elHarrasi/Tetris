#include "Factory.h"
#include "TetrisException.hpp"

using namespace model;

Tetromino Factory::createTetromino(TypeBrick type, Color color, int width) {
    std::vector<Position> positions = init_tab_position(type, width);
    switch (type) {
        case TypeBrick::C:
            return Tetromino(color, type, width, positions);
        case TypeBrick::J:
            return Tetromino(color, type, width, positions);
        case TypeBrick::S:
            return Tetromino(color, type, width, positions);
        case TypeBrick::Z:
            return Tetromino(color, type, width, positions);
        case TypeBrick::T:
            return Tetromino(color, type, width, positions);
        case TypeBrick::L:
            return Tetromino(color, type, width, positions);
        case TypeBrick::I:
            return Tetromino(color, type, width, positions);
        default:
            throw TetrisException("error : factory : createTetromino");

    }
}

std::vector<Position> Factory::init_tab_position(TypeBrick type, int width) {
    std::vector<Position> tetromino;
    switch (type) {
        case TypeBrick::C :
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(0, width / 2 + 1));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(1, width / 2 + 1));
            break;
        case TypeBrick::J:
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(2, width / 2));
            tetromino.push_back(Position(2, width / 2 - 1));
            break;

        case TypeBrick::S:
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(0, width / 2 - 1));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(1, width / 2 + 1));

            break;
        case TypeBrick::Z:
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(0, width / 2 + 1));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(1, width / 2 - 1));
            break;
        case TypeBrick::T:
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(1, width / 2 - 1));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(1, width / 2 + 1));
            break;
        case TypeBrick::L:
            tetromino.push_back(Position(0, width / 2 - 1));
            tetromino.push_back(Position(1, width / 2 - 1));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(1, width / 2 + 1));
            break;
        case TypeBrick::I:
            tetromino.push_back(Position(0, width / 2));
            tetromino.push_back(Position(1, width / 2));
            tetromino.push_back(Position(2, width / 2));
            tetromino.push_back(Position(3, width / 2));
            break;
    }
    return tetromino;

};
