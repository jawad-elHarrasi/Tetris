#ifndef DIRECTION_H
#define DIRECTION_H

#include <utility>

namespace model {
using DIRECTION = std::pair<int, int>;
/**
 * @brief The Direction struct represents movement directions in a 2D grid.
 *
 * The Direction struct provides predefined direction vectors for movement
 * in different directions within a 2D grid.
 */
struct Direction {
    /**
     * @brief Pair representing movement direction downwards.
     *
     * The first component represents the change in row (y-coordinate),
     * and the second component represents the change in column (x-coordinate).
     */
    inline static std::pair<int, int> DOWN {1, 0};

    /**
     * @brief Pair representing movement direction to the left.
     *
     * The first component represents the change in row (y-coordinate),
     * and the second component represents the change in column (x-coordinate).
     */
    inline static std::pair<int, int> LEFT {0, -1};

    /**
     * @brief Pair representing movement direction to the right.
     *
     * The first component represents the change in row (y-coordinate),
     * and the second component represents the change in column (x-coordinate).
     */
    inline static std::pair<int, int> RIGHT {0, 1};
};

}

#endif // DIRECTION_H
