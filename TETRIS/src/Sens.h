#ifndef TETRIS_SENS_H
#define TETRIS_SENS_H

namespace model {
/**
 * @brief The Sens enum represents the direction of rotation for Tetrominoes.
 *
 * The Sens enum specifies two directions of rotation: clockwise and counterclockwise.
 */
enum class Sens {
    CLOCKWISE, /**< Indicates clockwise rotation */
    COUNTER_CLOCKWISE /**< Indicates counterclockwise rotation */
};
}
#endif // TETRIS_SENS_H
