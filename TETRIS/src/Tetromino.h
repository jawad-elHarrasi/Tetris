#ifndef TETROMINO_H
#define TETROMINO_H

#include "Position.h"
#include "Color.h"
#include "TypeBrick.h"
#include "Direction.h"
#include "Sens.h"
#include <iostream>
#include <vector>

namespace model {
/**
 * @brief The Tetromino class represents a Tetromino piece in the game.
 *
 * A Tetromino is a geometric shape composed of four square blocks used in the game of Tetris.
 * The Tetromino class stores information about the Tetromino's color, type, shape, and rotation.
 */
class Tetromino {
private:
    std::vector<Position> tetromino; /**< Vector containing positions of the Tetromino's blocks */
    Position rotationBase; /**< Position representing the rotation base of the Tetromino */
    TypeBrick type; /**< The type of Tetromino */
    Color color; /**< The color of the Tetromino */
    int width; /**< The width of the Tetromino */

public:
    /**
     * @brief Constructor for the Tetromino class.
     *
     * Constructs a Tetromino object with the specified color, type, width, and shape.
     *
     * @param color The color of the Tetromino.
     * @param type The type of Tetromino.
     * @param width The width of the Tetromino.
     * @param tetromino Vector containing positions of the Tetromino's blocks.
     */
    Tetromino(Color color, TypeBrick type, int width, std::vector<Position> tetromino);

    /**
     * @brief Rotates the Tetromino in the specified direction.
     *
     * @param s The direction of rotation (clockwise or counterclockwise).
     * @param occupiedPos Vector containing positions of occupied blocks on the grid.
     */
    void rotate(Sens s, std::vector<Position> &occupiedPos);

    /**
     * @brief Moves the Tetromino in the specified direction.
     *
     * @param d The direction of movement.
     * @param occupiedPos Vector containing positions of occupied blocks on the grid.
     */
    void move(DIRECTION &d, std::vector<Position> &occupiedPos);

    /**
     * @brief Gets the color of the Tetromino.
     *
     * @return The color of the Tetromino.
     */
    Color getColor() const;

    /**
     * @brief Gets the positions of the Tetromino's blocks.
     *
     * @return Vector containing positions of the Tetromino's blocks.
     */
    std::vector<Position> getPosition() const;

    /**
     * @brief Prints the shape of the Tetromino.
     *
     * This method prints the shape of the Tetromino to the standard output.
     */
    void printTetrominoShape() const;

    /**
     * @brief Overloaded stream insertion operator to output the Tetromino.
     *
     * @param os Reference to the output stream.
     * @param tetromino Reference to the Tetromino object to be outputted.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Tetromino &tetromino);
};

}

#endif // TETROMINO_H
