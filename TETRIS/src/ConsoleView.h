#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "Grid.h"
#include "Game.h"
#include "Observer.h"
#include <utility> // Include for std::pair
#include <string> // Include for std::string

using namespace model;

namespace view {
/**
 * @brief The ConsoleView class provides methods to interact with and display game-related information in the console.
 *
 * The ConsoleView class is responsible for displaying the game grid, game state (score and level),
 * and providing user interaction via the console.
 */
class ConsoleView : public Observer {
public:
    /**
     * @brief Displays the game grid in the console.
     *
     * @param grid Reference to the Grid object representing the game grid.
     */
    static void displayGrid(const Grid &grid);
    /**
     * @brief Displays the current game level in the console.
     *
     * @param level The current level of the game.
     */
    static void displayGameLevel(const int &level);
    /**
     * @brief Displays the current game score in the console.
     *
     * @param score The current score of the game.
     */
    static void displayGameScore(const int &score);

    /**
     * @brief Displays help information in the console.
     */
    static void displayHelp();

    /**
     * @brief ask if the user want to full the grid with some of random tetros
     *
     * @return True if the user want to full it false in the othre case
     */
    static bool randomTeros();

    /**
     * @brief Displays a welcome message and prompts the user to choose grid dimensions.
     *
     * @return A pair containing the chosen number of rows and columns for the game grid.
     */
    std::pair<int, int> displayHello();

private:
    /**
     * @brief Checks if a given string represents a valid number.
     *
     * @param str String to be checked.
     * @return True if the string represents a valid number, false otherwise.
     */
    static bool isNumber(const std::string& str);

    /**
     * @brief Updates the view based on a notification from the observed object (Game).
     *
     * This method is called whenever the observed object (Game) notifies its observers
     * about changes in game state.
     *
     * @param message Message indicating the type of modification.
     * @param args Additional arguments related to the modification.
     */
    //void update(std::string message, std::any &args) override;
};

}

#endif // CONSOLEVIEW_H
