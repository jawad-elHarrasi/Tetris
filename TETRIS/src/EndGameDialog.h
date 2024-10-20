#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
 * @brief The EndGameDialog class represents a dialog displayed at the end of the game.
 *
 * The EndGameDialog class provides a user interface to display the final score and a message
 * to the player, along with a button to close the dialog.
 */
class EndGameDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the EndGameDialog class.
     *
     * Initializes the dialog with a parent widget.
     *
     * @param parent Parent widget of the dialog. Defaults to nullptr.
     */
    EndGameDialog(QWidget *parent = nullptr);

    /**
     * @brief Sets the score to be displayed in the dialog.
     *
     * This method updates the score label with the provided score.
     *
     * @param score The final score to be displayed.
     */
    void setScore(int score);

private:
    QLabel *scoreLabel; /**< Label to display the final score */
    QLabel *messageLabel; /**< Label to display a message to the player */
    QPushButton *closeButton; /**< Button to close the dialog */

private slots:
    /**
     * @brief Slot function to handle the close button click event.
     *
     * This method is called when the close button is clicked, and it closes the dialog.
     */
    void onCloseButtonClicked();
};

#endif // ENDGAMEDIALOG_H
