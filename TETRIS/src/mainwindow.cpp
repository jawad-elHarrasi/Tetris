#include "mainwindow.h"
#include "EndGameDialog.h"
#include "qlabel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(controller::TetrisController &ctrl, int largeurZoneJeu, int hauteurZoneJeu, bool randomShapes, bool defaultDim, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    controller(ctrl)
    ,_scene(this)
{
    ui->setupUi(this);

    QRect viewContentsRect = ui->graphicsView->contentsRect();

    this->setFocus();


    int tailleBloc = 20; // taille d'un bloc en pixels


    int largeurTotale = largeurZoneJeu * tailleBloc;
    int hauteurTotale = hauteurZoneJeu * tailleBloc;


    qreal x = (viewContentsRect.width() - largeurTotale) / 2;
    qreal y = (viewContentsRect.height() - hauteurTotale) / 2;


    _scene.addRect(x, y, largeurTotale, hauteurTotale, QPen(Qt::black), QBrush(Qt::gray));


    for (int i = 0; i < largeurZoneJeu; ++i) {
        for (int j = 0; j < hauteurZoneJeu; ++j) {
            qreal blocX = x + i * tailleBloc;
            qreal blocY = y + j * tailleBloc;

            _scene.addRect(blocX, blocY, tailleBloc, tailleBloc, QPen(Qt::white), QBrush(Qt::black));
        }
    }

    controller.lunchGame(hauteurZoneJeu, largeurZoneJeu, randomShapes, defaultDim, this);// false pour l'instant il faut juste changer les param du mainWindow

    ui->graphicsView->setScene(&_scene);
}

void MainWindow::updateGrid(const model::Grid &grid){
    _scene.clear();

    int gridSizeX = grid.getWidth();
    int gridSizeY = grid.getHeight();

    int blockSize = 20;

    for (int i = 0; i < gridSizeX; ++i) {
        for (int j = 0; j < gridSizeY; ++j) {
            qreal blockX = i * blockSize;
            qreal blockY = j * blockSize;

            if (grid.grid[j][i].isOccupied()) {
                QGraphicsRectItem *blockItem = _scene.addRect(blockX, blockY, blockSize, blockSize, QPen(Qt::white), QColor(Qt::red) /*QBrush(QColor(grid.grid[j][i].getColor())*/);
            } else {
                _scene.addRect(blockX, blockY, blockSize, blockSize, QPen(Qt::white), QBrush(Qt::black));
            }
        }
    }


    ui->graphicsView->setScene(&_scene);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    try {

        if (event->type() == QEvent::KeyPress){
            controller.keyPressEvent(event);
        }

    } catch (...) {
        std::cout << "erreur" << std::endl;
    }

}

void MainWindow::update(model::Game *newVal, std::string message){

    std::cout << message << std::endl;

    if (message == model::Game::GAME_MODIFICATION) {

        updateGrid(newVal->getGrid());

    } else if (message == model::Game::LEVEL_MODIFICATION) {

        int level = newVal->getLevel();
        ui->levelLabel->setText("Level : " + QString::number(level));

    } else if (message == model::Game::REMOVED_MODIFICATION) {

        int lines = newVal->getLinesRemoved();
        ui->linesLabel->setText("Lines : " + QString::number(lines));

    } else if (message == model::Game::SCORE_MODIFICATION) {

        int score = newVal->getScore();
        ui->scoreLabel->setText("Score : " + QString::number(score));

    } else if (message == model::Game::END_GAME) {

        EndGameDialog endGameDialog(this);
        endGameDialog.setScore(newVal->getScore());

        endGameDialog.exec();

        this->close();
    } else if (message == model::Game::LENT){
        controller.setVitesse("lent");
    }
    else if (message == model::Game::RAPIDE){
        std::cout << "je suis la" << std::endl;
        controller.setVitesse("rapide");
    }

}





void MainWindow::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    this->setFocus();
}





MainWindow::~MainWindow()
{
    delete ui;
}

