#include "controller.h"
#include "ConsoleView.h"
#include "TetrisException.hpp"
#include "keyboardAndStringConvert/keyboard.hpp"
#include "qwidget.h"
#include <iostream>


using namespace controller;
using namespace model;
using namespace view;

TetrisController::TetrisController() {
    connect(&autoDownTimer, SIGNAL(timeout()), this, SLOT(autoDown()));
    //     std::pair<int,int> dimensions =  this->view.displayHello();

    //     this->view = std::make_unique<MainWindow>(dimensions.first, dimensions.second);


    //     if (dimensions.first == 0){
    //        game = std::make_unique<Game>();
    // } else {
    //         game = std::make_unique<Game>(dimensions.first, dimensions.second);
    //     }

    //     if (this->view.randomTeros()){
    //        game->addRandomShapes();
    //     }
    //     game->registerObserver(&this->view);
    //     run();
}

void TetrisController::lunchGame(int height, int width, bool random, bool defaultDim, Observer * obs){

    if (defaultDim){
        game = std::make_unique<Game>();
    }else{
        game = std::make_unique<Game>(height, width);
    }
    if (random){
        game->addRandomShapes();
    }
    game->registerObserver(obs);
    game->nextStep();
    autoDownTimer.start(game->getSpeed());

}


void TetrisController::setVitesse(std::string vitesse){
    if (vitesse == "rapide"){
        game->setVitesse("rapide");
    }
    if (vitesse == "lent"){
        game->setVitesse("lent");
    }
}


void TetrisController::run() {

    char userInput;
    Tetromino t = game->getTetro();
    Grid grid = game->getGrid();
    grid.addTetromino(t);
    view::ConsoleView::displayGrid(game->getGrid());

    while (true) {

        game->searchAndDeleteFullLines();
        view::ConsoleView::displayHelp();


        try {
            he2b::esi::dev4::lineFromKbd(userInput);
        } catch (...) {

        }

        std::cout << std::endl;
        std::cout << std::endl;

        switch (userInput) {
        case 'W':
            game->rotate(Sens::CLOCKWISE);
            game->move(Direction::DOWN);
            break;

        case 'C':
            game->rotate(Sens::COUNTER_CLOCKWISE);
            game->move(Direction::DOWN);
            break;
        case 'L':
            try {
                game->move(Direction::LEFT);
                game->move(Direction::DOWN);
            } catch (const TetrisException&) {
                std::cout << "can't move left";
            }
            break;
        case 'D':
            try {
                game->move(Direction::DOWN);
            } catch (const TetrisException&) {
                std::cout << "can't move down";
            }
            break;
        case 'R':
            try {
                game->move(Direction::RIGHT);
                game->move(Direction::DOWN);
            } catch (const TetrisException&) {
                std::cout << "can't move right";
            }
            break;
        case 'Q':
            std::cout << "THANK YOU AND GOODBYE" << std::endl;
            return;
        default:
            std::cout << "Invalid input! Use W, A, S, D to move or Q to quit." << std::endl;
            break;
        }

        game->nextStep();

        if (game->isEnd()) {
            std::cout << "YOU LOSE" << std::endl;
            std::cout << "THANK YOU AND GOODBYE" << std::endl;
            return;
        }
    }
}
void TetrisController::addObserver(Observer* obs){
    this->game->registerObserver(obs);
}

void TetrisController::keyPressEvent(QKeyEvent *event) {
    autoDownTimer.stop();

    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch (key) {

    case Qt::Key_W:
        game->rotate(Sens::CLOCKWISE);
        break;
    case Qt::Key_X:
        game->rotate(Sens::COUNTER_CLOCKWISE);
        break;
    case Qt::Key_Q:
        exit(0);
        break;

    case Qt::Key_Right:
        game->move(Direction::RIGHT);
        break;

    case Qt::Key_Left:
        game->move(Direction::LEFT);
        break;

    case Qt::Key_Down:
        game->move(Direction::DOWN);
        break;

    default:
        std::cout << "Invalid input! Use arrow keys or Q to quit." << std::endl;
        break;
    }

    game->searchAndDeleteFullLines();
    game->nextStep();
    game->isEnd();


    autoDownTimer.start(game->getSpeed());
}

void TetrisController::autoDown() {
    try {
        game->move(Direction::DOWN);
        game->searchAndDeleteFullLines();
        game->isEnd();
        game->nextStep();
    } catch (const TetrisException&) {
        std::cout << "can't move down";
    }
}
