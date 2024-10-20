#ifndef POSITION_H
#define POSITION_H

#include "Direction.h"
#include <ostream>

namespace model {
/**
 * @brief The Position class represents a position in a 2D grid.
 *
 * The Position class stores the coordinates (x, y) of a position in a 2D grid
 * and provides methods to manipulate and access these coordinates.
 */
class Position {
private:
    int x; /**< The x-coordinate of the position */
    int y; /**< The y-coordinate of the position */

public:
    /**
     * @brief Constructor for the Position class.
     *
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     */
    Position(int x, int y);

    /**
     * @brief Overloaded addition operator to move the position in the specified direction.
     *
     * @param d The direction in which to move the position.
     */
    void operator+(DIRECTION d);

    /**
     * @brief Overloaded subtraction operator to move the position in the opposite direction.
     *
     * @param d The direction in which to move the position.
     */
    void operator-(DIRECTION d);

    /**
     * @brief Overloaded compound assignment operator to move the position in the specified direction.
     *
     * @param d The direction in which to move the position.
     * @return Reference to the modified Position object.
     */
    Position &operator+=(DIRECTION &d);

    /**
     * @brief Gets the x-coordinate of the position.
     *
     * @return The x-coordinate of the position.
     */
    int getX() const;

    /**
     * @brief Gets the y-coordinate of the position.
     *
     * @return The y-coordinate of the position.
     */
    int getY() const;

    /**
     * @brief Sets the x-coordinate of the position.
     *
     * @param newX The new x-coordinate of the position.
     */
    void setX(int newX);

    /**
     * @brief Sets the y-coordinate of the position.
     *
     * @param newY The new y-coordinate of the position.
     */
    void setY(int newY);

    /**
     * @brief Sets the position to the specified coordinates.
     *
     * @param position The new coordinates of the position.
     */
    void setPosition(Position position);

    /**
     * @brief Gets a copy of the current position.
     *
     * @return A copy of the current position.
     */
    Position getPosition();

    /**
     * @brief Overloaded stream insertion operator to output the position coordinates.
     *
     * @param os Reference to the output stream.
     * @param position Reference to the Position object to be outputted.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Position &position);
};

}

#endif // POSITION_H
