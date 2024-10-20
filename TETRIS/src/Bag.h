#ifndef BAG_H
#define BAG_H

#include "Tetromino.h"
#include <vector>

namespace model {

/**
 * @brief The Bag class represents a bag containing Tetromino shapes used in Tetris game.
 *
 * The Bag class ensures that Tetromino shapes are drawn in a random order,
 * with each shape appearing once before reshuffling the bag.
 */
class Bag {
private:
    std::vector<Tetromino> shapes; /**< Vector to hold Tetromino shapes in the bag */
    int gettedTetro; /**< Counter to keep track of the number of Tetrominos taken from the bag */
    int gridWidth; /**< Width of the game grid */

    /**
     * @brief Constructor for the Bag class.
     *
     * @param width Width of the game grid.
     */
    Bag(int width);

    /**
     * @brief Shuffles the Tetromino shapes in the bag.
     *
     * This method shuffles the `shapes` vector to ensure that the Tetromino
     * shapes are drawn in a random order. It is called internally to reshuffle
     * the bag when all shapes have been drawn once.
     */
    void shuffle();

public:
    /**
     * @brief Deleted copy constructor.
     *
     * This constructor is deleted to prevent copying of the Bag instance.
     */
    Bag(const Bag &) = delete;

    /**
     * @brief Deleted copy assignment operator.
     *
     * This operator is deleted to prevent copying of the Bag instance.
     */
    Bag &operator=(const Bag &) = delete;

    /**
     * @brief Deleted move constructor.
     *
     * This constructor is deleted to prevent moving of the Bag instance.
     */
    Bag(Bag &&) = delete;

    /**
     * @brief Deleted move assignment operator.
     *
     * This operator is deleted to prevent moving of the Bag instance.
     */
    Bag &operator=(Bag &&) = delete;

    /**
     * @brief Returns the singleton instance of the Bag class.
     *
     * This method provides access to the single instance of the Bag class.
     * If the instance does not exist, it is created with the specified grid width.
     *
     * @param width Width of the game grid.
     * @return Reference to the singleton instance of the Bag class.
     */
    static Bag &getInstance(int width);

    /**
     * @brief Retrieves a Tetromino from the bag.
     *
     * This method returns a Tetromino object from the bag. When all Tetromino
     * shapes have been drawn once, the bag is reshuffled to provide a new
     * random order of shapes.
     *
     * @return Tetromino object retrieved from the bag.
     */
    Tetromino getTetro();
};

} // namespace model

#endif // BAG_H
