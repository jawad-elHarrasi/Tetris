#ifndef TETRIS_TYPEBRICK_H
#define TETRIS_TYPEBRICK_H

namespace model {
/**
 * @brief The TypeBrick enum represents the different types of Tetris bricks.
 *
 * The TypeBrick enum specifies the different shapes of Tetris bricks that can appear in the game.
 */
enum class TypeBrick {
    C, /**< The C-shaped Tetris brick */
    J, /**< The J-shaped Tetris brick */
    S, /**< The S-shaped Tetris brick */
    Z, /**< The Z-shaped Tetris brick */
    T, /**< The T-shaped Tetris brick */
    L, /**< The L-shaped Tetris brick */
    I  /**< The I-shaped Tetris brick */
};
}
#endif // TETRIS_TYPEBRICK_H
