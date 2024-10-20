#include <random>
#include <algorithm>
#include "Bag.h"
#include "Factory.h"
#include "TetrisException.hpp"

using namespace model;

Bag::Bag(int width) : gettedTetro(0) {

    this->gridWidth = width;

    std::vector<Color> colors = {Color::BLUE, Color::GREEN/*, Color::PINK*/,
                                 Color::RED, Color::PURPLE, Color::YELLOW,
                                 Color::ORANGE};
    std::vector<TypeBrick> types = {TypeBrick::C, TypeBrick::J,
                                    TypeBrick::S, TypeBrick::Z,
                                    TypeBrick::T, TypeBrick::L, TypeBrick::I};

    for (int i = 0; i < colors.size(); ++i) {
        Tetromino tetromino = Factory::createTetromino(types[i], colors[i], width);
        this->shapes.push_back(tetromino);
    }
}

Bag &Bag::getInstance(int width) {
    static Bag instance(width);
    return instance;
}

void Bag::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->shapes.begin(), this->shapes.end(), g);
}

Tetromino Bag::getTetro() {
    if (this->shapes.empty()) {
        throw TetrisException("error : bag is empty");
    }
    if (this->gettedTetro == 6) {
        this->shuffle();
        this->gettedTetro = 0;
    }

    Tetromino tetromino = this->shapes[this->gettedTetro];
    this->gettedTetro++;
    return tetromino;
}

