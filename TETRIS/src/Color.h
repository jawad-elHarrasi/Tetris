#ifndef TETRIS_COLOR_H
#define TETRIS_COLOR_H

#include <map>
#include <string>

namespace model {

/**
 * @brief Enumeration representing different colors for Tetris blocks.
 *
 * This enumeration defines the various colors that can be assigned to Tetris blocks.
 */
enum Color {
    BLUE,    /**< Color blue */
    GREEN,   /**< Color green */
    PINK,    /**< Color pink */
    RED,     /**< Color red */
    PURPLE,  /**< Color purple */
    YELLOW,  /**< Color yellow */
    ORANGE,  /**< Color orange */
    BLACK    /**< Color black */
};

/**
 * @brief Map containing color codes for printing colored text in the console.
 *
 * This map associates each color in the Color enumeration with its corresponding
 * ANSI escape code for colored text in the console. These codes can be used to
 * change the text color when printing to a terminal that supports ANSI escape codes.
 */
const std::map<Color, std::string> colorCodes = {
    {Color::BLUE, "\033[34m"},   /**< ANSI escape code for blue */
    {Color::GREEN, "\033[32m"},  /**< ANSI escape code for green */
    {Color::PINK, "\033[35m"},   /**< ANSI escape code for pink */
    {Color::RED, "\033[31m"},    /**< ANSI escape code for red */
    {Color::PURPLE, "\033[35m"}, /**< ANSI escape code for purple */
    {Color::YELLOW, "\033[33m"}, /**< ANSI escape code for yellow */
    {Color::ORANGE, "\033[33m"}, /**< ANSI escape code for orange */
    {Color::BLACK, "\033[30m"}   /**< ANSI escape code for black */
};

/**
 * @brief Reset code to revert text color back to default.
 *
 * This string contains the ANSI escape code that resets the text color to the terminal's default color.
 */
const std::string resetColor = "\033[0m";

} // namespace model

#endif // TETRIS_COLOR_H
