#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "controller.h"
#include "mainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class firstWindow; }
QT_END_NAMESPACE

/**
 * @brief The firstWindow class represents the initial window displayed to the user.
 *
 * This class is responsible for handling the initial user interface, such as getting input from the user
 * to start the game, and then transitioning to the main game window.
 */
class firstWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the firstWindow class.
     *
     * Initializes the first window with a reference to the TetrisController and an optional parent widget.
     *
     * @param ctrl Reference to the TetrisController instance.
     * @param parent Parent widget of the first window. Defaults to nullptr.
     */
    firstWindow(controller::TetrisController &ctrl, QWidget *parent = nullptr);

    /**
     * @brief Destructor for the firstWindow class.
     */
    ~firstWindow();

private slots:
    /**
     * @brief Slot function to handle the submit button click event.
     *
     * This method is called when the submit button is clicked. It collects user input, initializes the game,
     * and transitions to the main game window.
     */
    void onSubmitButtonClicked();

private:
    Ui::firstWindow *ui; /**< Pointer to the user interface object for the first window */
    std::unique_ptr<MainWindow> mainWindow; /**< Unique pointer to the main game window */
    controller::TetrisController &controller; /**< Reference to the TetrisController instance */
};

#endif // FIRSTWINDOW_H
