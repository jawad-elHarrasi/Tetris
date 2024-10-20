#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>
#include "Block.h"
#include "Tetromino.h"

namespace model {
/**
 * @brief The Grid class represents the game grid where Tetrominoes are placed.
 *
 * The Grid class manages the game grid, including adding Tetrominoes, removing lines,
 * and checking for full lines.
 */
class Grid {
private:
    int height; /**< The height of the game grid */
    int width; /**< The width of the game grid */

public:
    std::vector<std::vector<Block>> grid; /**< 2D vector representing the game grid */

    /**
     * @brief Default constructor for the Grid class.
     *
     * Constructs a grid with default dimensions.
     */
    Grid();

    /**
     * @brief Constructor for the Grid class with specified dimensions.
     *
     * @param nHeight The height of the grid.
     * @param nWidth The width of the grid.
     */
    Grid(int nHeight, int nWidth);

    /**
     * @brief Initializes the grid with random shapes.
     *
     * This method fills the grid with random shapes when starting the game.
     */
    void randomShapes();

    /**
     * @brief Deletes specified lines from the grid.
     *
     * @param lines Vector containing indices of lines to be deleted.
     */
    void deleteLines(std::vector<int> lines);

    /**
     * @brief Checks if the given Tetromino is completely inside the grid.
     *
     * @param t Reference to the Tetromino to be checked.
     * @return True if the Tetromino is completely inside the grid, false otherwise.
     */
    bool isInside(const Tetromino &t);

    /**
     * @brief Checks if the grid is full (no space for new Tetrominoes).
     *
     * @return True if the grid is full, false otherwise.
     */
    bool isFull();

    /**
     * @brief Adds a Tetromino to the grid.
     *
     * @param t Reference to the Tetromino to be added.
     * @return True if the Tetromino was successfully added, false otherwise.
     */
    bool addTetromino(Tetromino &t);

    /**
     * @brief Removes a Tetromino from the grid.
     *
     * @param t Reference to the Tetromino to be removed.
     */
    void removeTetromino(Tetromino &t);

    /**
     * @brief Searches for and removes full lines from the grid.
     *
     * @return The number of full lines removed.
     */
    int searchAndRemoveFullLines();

    /**
     * @brief Finds the positions around the given Tetromino.
     *
     * This method finds the positions around the Tetromino that are occupied by blocks.
     *
     * @param t Reference to the Tetromino.
     * @return Vector containing positions around the Tetromino.
     */
    std::vector<Position> aroundTetro(const Tetromino &t);

    /**
     * @brief Gets the width of the grid.
     *
     * @return The width of the grid.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the grid.
     *
     * @return The height of the grid.
     */
    int getHeight() const;

};

}

/**
 * @brief Overloaded insertion operator for outputting grid contents.
 *
 * @param os Reference to the output stream.
 * @param grid Reference to the Grid object to be outputted.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const model::Grid& grid);

#endif // GRID_H
