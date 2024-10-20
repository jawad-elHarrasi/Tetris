#include "Tetromino.h"
#include "Game.h"
#include "TetrisException.hpp"

using namespace model;


Tetromino::Tetromino(Color color, TypeBrick type, int width, std::vector<Position> tetromino) :
    tetromino(tetromino),
    rotationBase(tetromino[0].getPosition()),
    type(type),
    color(color),
    width(width) {}

void Tetromino::rotate(Sens sens, std::vector<Position> &occupiedPos) {
    if (sens == Sens::CLOCKWISE){
        for (Position &p : tetromino) {
            int newX = rotationBase.getX() + (p.getY() - rotationBase.getY());
            int newY = rotationBase.getY() - (p.getX() - rotationBase.getX());
            if (newX < 0 || newY < 0){
                throw TetrisException("negative position");
            }
            p.setX(newX);
            p.setY(newY);
        }
    }else{
        for (Position &p : tetromino) {
            int newX = rotationBase.getX() - (p.getY() - rotationBase.getY());
            int newY = rotationBase.getY() + (p.getX() - rotationBase.getX());
            p.setX(newX);
            p.setY(newY);
        }
    }

    for (Position &tetroPos : this->tetromino) {
        for (Position &occupied : occupiedPos) {
            if (tetroPos.getX() == occupied.getX() && tetroPos.getY() == occupied.getY()){
                throw TetrisException("error : tetro can't rotate");
            }
        }
    }


}

void Tetromino::move(DIRECTION &d, std::vector<Position> &occupiedPos) {
    for (Position &p: tetromino) {
        p += d;
    }

    rotationBase = tetromino.at(0).getPosition();

    for (Position &tetroPos : this->tetromino) {

        for (Position &occupied : occupiedPos) {
            if (tetroPos.getX() == occupied.getX() && tetroPos.getY() == occupied.getY()){
                throw TetrisException("error : tetro can't move");
            }
        }
    }

}

Color Tetromino::getColor() const{
    return this->color;
}

std::vector<Position> Tetromino::getPosition() const{
    return this->tetromino;
}

void Tetromino::printTetrominoShape() const {
    int maxX = 0;
    int maxY = 0;

    for ( const Position &p : tetromino) {
        maxX = std::max(maxX, p.getX());
        maxY = std::max(maxY, p.getY());
    }

    std::vector<std::vector<char>> grid(maxX + 1, std::vector<char>(maxY + 1, ' '));

    for (const Position &p : tetromino) {
        grid[p.getX()][p.getY()] = 'X';
    }

    for (int i = 0; i <= maxX; ++i) {
        for (int j = 0; j <= maxY; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


