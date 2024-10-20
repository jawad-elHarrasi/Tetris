// gameoverdialog.h
#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class GameOverDialog : public QDialog {
    Q_OBJECT
public:
    GameOverDialog(int score, int level, QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Game Over");

        QLabel *label = new QLabel("Merci et au revoir\n\nScore: " + QString::number(score) + "\nLevel: " + QString::number(level), this);
        QPushButton *closeButton = new QPushButton("Fermer", this);

        connect(closeButton, &QPushButton::clicked, this, &GameOverDialog::accept);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(closeButton);
        setLayout(layout);
    }
};

#endif // GAMEOVERDIALOG_H
