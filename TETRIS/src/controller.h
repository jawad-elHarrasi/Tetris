#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include <QWidget>
#include <memory>
#include <QKeyEvent>
#include <QTimer>

namespace controller {

/**
 * @brief The TetrisController class handles the game logic and user interface.
 *
 * The TetrisController class is responsible for managing the game state (using the Game class),
 * updating the user interface, and handling user input to control the game.
 */
class TetrisController : public QObject {
    Q_OBJECT
private:
    std::unique_ptr<model::Game> game; /**< Unique pointer to the Game instance managing game state */
    QTimer autoDownTimer; /**< Timer to handle automatic downward movement of Tetrominos */

public:
    /**
     * @brief Default constructor for the TetrisController class.
     *
     * Initializes the game state and user interface.
     */
    TetrisController();

    /**
     * @brief Launches the Tetris game with specified parameters.
     *
     * @param height Height of the game grid.
     * @param width Width of the game grid.
     * @param random Boolean flag to indicate if Tetromino generation should be random.
     * @param defaultDim Boolean flag to indicate if default dimensions should be used.
     * @param obs Observer to notify of game events.
     */
    void lunchGame(int height, int width, bool random, bool defaultDim, Observer *obs);

    /**
     * @brief Adds an observer to the game.
     *
     * @param obs Observer to be added.
     */
    void addObserver(Observer *obs);

    /**
     * @brief Runs the Tetris game.
     *
     * This method starts the game loop and handles user input to control the game.
     */
    void run();

    /**
     * @brief Handles key press events.
     *
     * This method processes user input to control the game.
     *
     * @param event Pointer to the QKeyEvent object.
     */
    void keyPressEvent(QKeyEvent *event);
    void setVitesse(std::string vitesse);

private slots:
    /**
     * @brief Slot function for handling automatic downward movement of Tetrominos.
     *
     * This method is connected to the QTimer and moves the current Tetromino down at regular intervals.
     */
    void autoDown();
};

} // namespace controller

#endif // CONTROLLER_H
