#include "Game.h"
#include "Bag.h"
#include "TetrisException.hpp"

using namespace model;

const std::string Game::GAME_MODIFICATION = "game modification";
const std::string Game::SCORE_MODIFICATION = "score modification";
const std::string Game::LEVEL_MODIFICATION = "level modification";
const std::string Game::REMOVED_MODIFICATION = "removed line modification";
const std::string Game::END_GAME = "end game";
const std::string Game::RAPIDE = "rapide";
const std::string Game::LENT = "lent";


Game::Game() : score(0),speed(0), level(1), lineRemoved(0), nbDown(0),grid(Grid()),
    currentTetro(Bag::getInstance(grid.getWidth()-1).getTetro()),
    previousTetro(Bag::getInstance(grid.getWidth()).getTetro()),
    end(false) {    
    speed = speedFactory(1);
    std::cout << speed << std::endl;


}

Game::Game(int n,int y) :score(0),speed(0), level(1),lineRemoved(0),nbDown(0), grid(Grid(n,y)),
    currentTetro(Bag::getInstance(grid.getWidth()-1).getTetro()),
    previousTetro(Bag::getInstance(grid.getWidth()).getTetro()),
    end(false){
    speed = speedFactory(1);
    std::cout << speed << std::endl;

}


void Game::addRandomShapes(){
    grid.randomShapes();
}

void Game::calculateScore(int lines) {

    if (lines <= 1) {
        this->score += (40 * lines + this->nbDown) * this->level;
    }
    switch (lines) {
    case 2:
        this->score += (100 * lines + this->nbDown) * this->level;
        break;
    case 3:
        this->score += (300 * lines + this->nbDown) * this->level;
        break;
    case 4:
        this->score += (1200 * lines + this->nbDown) * this->level;
        break;
    }
    notifyObservers(this, SCORE_MODIFICATION);

}

bool Game::isEnd() {
    if (this->score == 500 || this->lineRemoved == 20 || this->end) {
        notifyObservers(this, END_GAME);
        return true;
    }
    return false;
}

double Game::getSpeed(){
    return this->speed;
}


void Game::nextStep() {
    if (this->lineRemoved >= 10) {
        setLevel(this->level++);
        this->speed = speedFactory(level);
        this->lineRemoved = 0;
    }
    notifyObservers(this, GAME_MODIFICATION);
    notifyObservers(this, REMOVED_MODIFICATION);
    notifyObservers(this, LEVEL_MODIFICATION);
    notifyObservers(this, SCORE_MODIFICATION);
}

double Game::speedFactory(int level){
    switch (level) {
    case 1:
        return (60.0/60.0)*1000;
    case 2:
        return (53.0/60.0)*1000;
    case 3:
        return (49.0/60.0)*1000;
    case 4:
        return (45.0/60.0)*1000;
    case 5:
        return (41.0/60.0)*1000;
    case 6:
        return (37.0/60.0)*1000;
    case 7:
        return (33.0/60.0)*1000;
    case 8:
        return (28.0/60.0)*1000;
    case 9:
        return (23.0/60.0)*1000;
    case 10:
        return (18.0/60.0)*1000;
    case 11:
        return (13.0/60.0)*1000;
    case 12:
        return (8.0/60.0)*1000;
    case 13:
        return (9.0/60.0)*1000;
    case 14:
        return (8.0/60.0)*1000;
    case 15:
        return (7.0/60.0)*1000;
    case 16:
        return (6.0/60.0)*1000;
    case 17:
        return (5.0/60.0)*1000;
    case 18:
        return (4.0/60.0)*1000;
    case 19:
        return (3.0/60.0)*1000;
    default:
        return (2.0/60.0)*1000;
    }
}




void Game::rotate(Sens s) {
    std::vector<Position> tpos = currentTetro.getPosition();

    for(Position pos:tpos){
        if(pos.getX()==grid.getHeight()-1){
            currentTetro = Bag::getInstance(grid.getWidth()).getTetro();
            this->end = grid.addTetromino(currentTetro);
            if (end == true){
                notifyObservers(this, END_GAME);
            }
            return;
            break;
        }
    }

    std::vector<Position> occupiedPos = this->grid.aroundTetro(this->currentTetro);

    try {
        previousTetro = currentTetro;
        this->currentTetro.rotate(s, occupiedPos);

        bool rotate = true;
        for (Position &tetroPos : currentTetro.getPosition()) {
            if (tetroPos.getY() < 0 || tetroPos.getY() >=  grid.getWidth()){
                rotate = false;
            }
        }
        if (rotate){
            grid.removeTetromino(previousTetro);
            this->end = grid.addTetromino(currentTetro);
            if (end == true){
                notifyObservers(this, END_GAME);
            }
        } else {
            grid.removeTetromino(currentTetro);
            currentTetro = previousTetro;
            grid.removeTetromino(previousTetro);
            grid.addTetromino(currentTetro);
        }
    } catch (const TetrisException&) {
        calculateScore(lineRemoved);
        currentTetro = Bag::getInstance(grid.getWidth()).getTetro();
        this->nbDown = 0;
        this->end = grid.addTetromino(currentTetro);
        if (end == true){
            notifyObservers(this, END_GAME);
        }
    }
}


void Game::move(DIRECTION &d) {
    std::vector<Position> tpos = currentTetro.getPosition();


    for(Position pos:tpos){

        if(pos.getX()==grid.getHeight()/2){
            notifyObservers(this,RAPIDE);
        }
    }


    for(Position pos:tpos){
        if(pos.getX()==grid.getHeight()-1){
            calculateScore(lineRemoved);
            currentTetro = Bag::getInstance(grid.getWidth()).getTetro();
            this->nbDown = 0;
            this->end = grid.addTetromino(currentTetro);
            return;
        }
    }

    std::vector<Position> occupiedPos = this->grid.aroundTetro(this->currentTetro);
    try {
        previousTetro = currentTetro;
        this->currentTetro.move(d, occupiedPos);

        bool move = true;
        for (Position &tetroPos : currentTetro.getPosition()) {
            if (tetroPos.getY() < 0 || tetroPos.getY() >=  grid.getWidth()){
                move = false;
            }
        }
        if (move){
            grid.removeTetromino(previousTetro);
            this->end = grid.addTetromino(currentTetro);
            if (end == true){
                notifyObservers(this, END_GAME);
            }
            this->nbDown++;
        } else {
            grid.removeTetromino(currentTetro);
            currentTetro = previousTetro;
            grid.removeTetromino(previousTetro);
            grid.addTetromino(currentTetro);
        }
    } catch (const TetrisException&) {
        calculateScore(lineRemoved);
        currentTetro = Bag::getInstance(grid.getWidth()).getTetro();
        this->nbDown = 0;
        this->end = grid.addTetromino(currentTetro);
        if (end == true){
            notifyObservers(this, END_GAME);
        }
    }
}

void Game::setVitesse(std::string vitesse){

    if (vitesse == "rapide"){
        speed *= 10;
    }
    if (vitesse == "lent"){
        speed *= 10;
    }

}

int Game::getScore() const{
    return this->score;
}

int Game::getLevel() const{
    return this->level;
}

int Game::getLinesRemoved() const{
    return this->lineRemoved;
}


const Grid& Game::getGrid() const {
    return this->grid;
}
//Timer Game::getTime() {

//}

//void Game::setTime(Timer t) {

//}

void Game::setLevel(int level) {
    this->level = level;
    notifyObservers(this, LEVEL_MODIFICATION);
}

void Game::searchAndDeleteFullLines() {
    this->lineRemoved += this->grid.searchAndRemoveFullLines();

    if (this->lineRemoved % 10 == 0 && this->lineRemoved != 0 && this->level < 4){
        this->level++;
        notifyObservers(this, LEVEL_MODIFICATION);

    }

}
Tetromino Game::getTetro(){
    return currentTetro;
}





