#ifndef TETRIS_EXCEPTION_H
#define TETRIS_EXCEPTION_H

#include <stdexcept>
#include <string>

namespace model {
/**
 * @brief The TetrisException struct represents an exception specific to the Tetris game.
 *
 * The TetrisException struct inherits from std::logic_error and is used to handle
 * exceptions that occur during the execution of the Tetris game.
 */
struct TetrisException : std::logic_error {
    /**
     * @brief Constructor for the TetrisException struct.
     *
     * Constructs a TetrisException object with the specified error message.
     *
     * @param s The error message describing the exception.
     */
    inline TetrisException(const std::string& s = "") : std::logic_error(s) {}
};
}
#endif // TETRIS_EXCEPTION_H
