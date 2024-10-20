#include "Position.h"


using namespace model;
Position::Position(int x, int y) : x(x), y(y) {}

void Position::operator+(DIRECTION d) {

}

void Position::operator-(DIRECTION d) {

}


int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int newX) {
    this->x = newX;
}

void Position::setY(int newY){
    this->y = newY;
}

Position Position::getPosition()  {
    return *this;
}


void Position::setPosition(Position position) {
    x = position.getX();
    y = position.getY();
}

Position &Position::operator+=(DIRECTION & d) {
    x += d.first;
    y += d.second;
    return *this;
}



std::ostream &operator<<(std::ostream &os,  const Position &position) {
    os << "Position : (" << position.getX() << ", " << position.getY() << ")";
    return os;
}

