#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Observable.h"
#include "Tetromino.h"
#include "Sens.h"
#include "Direction.h"

namespace model {
/**
 * @brief The Game class represents the core logic of the Tetris game.
 *
 * The Game class manages the game state, including the score, level, game grid,
 * current and previous Tetrominoes, and handles game actions such as rotation,
 * movement, and line clearing.
 */
class Game : public Observable {
private :
    int score;
    double speed;
    int level;
    int lineRemoved;
    int nbDown;
    Grid grid;
    Tetromino currentTetro;
    Tetromino previousTetro;
    bool end;


public:

    static const std::string GAME_MODIFICATION;
    static const std::string SCORE_MODIFICATION;
    static const std::string LEVEL_MODIFICATION;
    static const std::string REMOVED_MODIFICATION;
    static const std::string END_GAME;
    static const std::string RAPIDE;
    static const std::string LENT;


    /**
     * @brief Default constructor for the Game class.
     */
    Game();

    /**
     * @brief Constructor for the Game class with specified dimensions for the game grid.
     *
     * @param n Number of rows for the game grid.
     * @param y Number of columns for the game grid.
     */
    Game(int n, int y);

    /**
     * @brief Calculates the score based on the number of lines cleared.
     *
     * @param lines The number of lines cleared in a single step.
     */
    void calculateScore(int lines);

    /**
     * @brief Checks if the game has ended.
     *
     * @return True if the game has ended, false otherwise.
     */
    bool isEnd();

    /**
     * @brief Moves the game to the next step.
     *
     * This method is responsible for handling the movement of Tetrominoes,
     * clearing full lines, and updating the game state.
     */
    void nextStep();


    /**
     * @brief Rotates the current Tetromino in the specified direction.
     *
     * @param s The direction of rotation (clockwise or counterclockwise).
     */
    void rotate(Sens s);

    /**
     * @brief Moves the current Tetromino in the specified direction.
     *
     * @param d The direction of movement (left, right, or down).
     */
    void move(DIRECTION &d);

    /**
     * @brief Gets the current score of the game.
     *
     * @return The current score of the game.
     */
    int getScore() const;

    /**
     * @brief Gets the current level of the game.
     *
     * @return The current level of the game.
     */
    int getLevel() const;


    void setVitesse(std::string vitesse);

    /**
     * @brief Gets the total number of lines removed from the grid.
     *
     * @return The total number of lines removed from the grid.
     */
    int getLinesRemoved() const;

    /**
     * @brief Gets a reference to the game grid.
     *
     * @return A reference to the game grid.
     */
    const Grid &getGrid() const;

    /**
     * @brief Sets the level of the game.
     *
     * @param lvl The level to set for the game.
     */
    void setLevel(int lvl);

    /**
     * @brief Initializes the grid with random shapes.
     *
     * This method fills the grid with random shapes when starting the game.
     */
    void addRandomShapes();

    /**
     * @brief Searches for and deletes full lines from the game grid.
     */
    void searchAndDeleteFullLines();

    /**
     * @brief Gets the current Tetromino in play.
     *
     * @return The current Tetromino in play.
     */
    Tetromino getTetro();


    /**
     * @brief return the speed coresponding to the level
     * @param level
     * @return
     */
    double speedFactory(int level);

    /**
     * @brief Gets a the speed for the auto down.
     *
     */
    double getSpeed();
};

}

#endif // GAME_H
