#ifndef BLOCK_H
#define BLOCK_H

#include "Position.h"
#include "Color.h"

namespace model {

/**
 * @brief The Block class represents a single block in the game grid.
 *
 * Each block has a position, color, and a flag indicating whether it is occupied or not.
 */
class Block {
private:
    bool occupied; /**< Flag indicating whether the block is occupied or not */
    Color color; /**< Color of the block */
    Position position; /**< Position of the block on the game grid */

public:
    /**
     * @brief Constructor for the Block class.
     *
     * Initializes a block with the given row, column, and color. The block is unoccupied by default.
     *
     * @param row Row position of the block.
     * @param col Column position of the block.
     * @param color Color of the block.
     */
    Block(int row, int col, Color color);

    /**
     * @brief Gets the position of the block.
     *
     * @return Position object representing the position of the block.
     */
    Position getPosition();

    /**
     * @brief Gets the color of the block.
     *
     * @return Color object representing the color of the block.
     */
    Color getColor() const;

    /**
     * @brief Sets the occupation status of the block.
     *
     * @param occupied True if the block is occupied, false otherwise.
     */
    void setOccupied(bool occupied);

    /**
     * @brief Checks if the block is occupied.
     *
     * @return True if the block is occupied, false otherwise.
     */
    bool isOccupied() const;

    /**
     * @brief Sets the color of the block.
     *
     * @param color Color to set for the block.
     */
    void setColor(Color color);
};

} // namespace model

#endif // BLOCK_H
