#ifndef FACTORY_H
#define FACTORY_H

#include "Tetromino.h"

namespace model {
/**
 * @brief The Factory class provides a method to create Tetromino objects.
 *
 * The Factory class contains a static method to create Tetromino objects
 * based on the specified type, color, and width.
 */
class Factory {
public:
    /**
     * @brief Creates a Tetromino object of the specified type, color, and width.
     *
     * @param type The type of Tetromino to create.
     * @param color The color of the Tetromino.
     * @param width The width of the game grid.
     * @return The created Tetromino object.
     */
    static Tetromino createTetromino(TypeBrick type, Color color, int width);

private:
    /**
     * @brief Initializes the positions of the Tetromino bricks based on the specified type and width.
     *
     * @param type The type of Tetromino.
     * @param width The width of the game grid.
     * @return A vector containing the initial positions of the Tetromino bricks.
     */
    static std::vector<Position> init_tab_position(TypeBrick type, int width);
};
}
#endif // FACTORY_H
