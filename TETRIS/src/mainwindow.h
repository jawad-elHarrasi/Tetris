#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Observer.h"
#include "controller.h"
#include <QMainWindow>
#include <QtWidgets/QGraphicsScene>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class represents the main window of the Tetris game.
 *
 * This class is responsible for displaying the game interface, handling user input,
 * and updating the game grid. It also acts as an observer to receive updates from the game.
 */
class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     *
     * @param ctrl Reference to the TetrisController object.
     * @param largeurZoneJeu Width of the game area.
     * @param hauteurZoneJeu Height of the game area.
     * @param randomShapes Flag indicating whether to use random shapes.
     * @param defaultDim Flag indicating whether to use default dimensions.
     * @param parent Pointer to the parent widget.
     */
    explicit MainWindow(controller::TetrisController &ctrl, int largeurZoneJeu, int hauteurZoneJeu, bool randomShapes, bool defaultDim, QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow();

    /**
     * @brief Updates the game grid display.
     *
     * @param grid Reference to the current game grid.
     */
    void updateGrid(const model::Grid &grid);

    /**
     * @brief Updates the MainWindow based on notifications from the observed game.
     *
     * @param newVal Pointer to the updated game object.
     * @param message Notification message indicating the type of update.
     */
    void update(model::Game *newVal, std::string message) override;

    /**
     * @brief Handles key press events to control the game.
     *
     * @param event Pointer to the key event.
     */
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;                            /**< UI object for the main window */
    controller::TetrisController &controller;      /**< Reference to the TetrisController */
    QGraphicsScene _scene;                         /**< Scene for rendering the game graphics */

    /**
     * @brief Handles the focus out event.
     *
     * @param event Pointer to the focus event.
     */
    void focusOutEvent(QFocusEvent *event) override;
};

#endif // MAINWINDOW_H
