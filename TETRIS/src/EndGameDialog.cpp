#include "EndGameDialog.h"

EndGameDialog::EndGameDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    scoreLabel = new QLabel("Score : ", this);
    messageLabel = new QLabel("GAME OVER!", this);
    closeButton = new QPushButton("Close", this);
    layout->addWidget(messageLabel);
    layout->addWidget(scoreLabel);
    layout->addWidget(closeButton);
    resize(300, 150);

    connect(closeButton, &QPushButton::clicked, this, &EndGameDialog::onCloseButtonClicked);
}

void EndGameDialog::setScore(int score) {
    scoreLabel->setText("Score : " + QString::number(score));
}

void EndGameDialog::onCloseButtonClicked() {
    exit(0);
}
