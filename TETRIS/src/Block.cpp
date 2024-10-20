#include "Block.h"

using namespace model;
Block::Block(int row, int col, Color color) :
        occupied(false),
        color(color),
        position(Position(row, col)) {

}


Position Block::getPosition() {
    return this->position;
}


void Block::setOccupied(bool occupied) {
    this->occupied = occupied;
}

bool Block::isOccupied() const{
    return this->occupied;
}

Color Block::getColor() const {
    return this->color;
}

void Block::setColor(Color color) {
    this->color = color;
}
