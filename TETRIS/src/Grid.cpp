#include <iomanip>
#include <vector>
#include "Grid.h"

using namespace model;

Grid::Grid() : height(20), width(10) {
    grid.resize(height, std::vector<Block>(width, Block(0, 0, Color::YELLOW)));

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j] = Block(i, j, Color::YELLOW);
        }
    }
}

Grid::Grid(int nHeight, int nWidth) : height(nHeight), width(nWidth) {
    grid.resize(height, std::vector<Block>(width, Block(0, 0, Color::YELLOW)));

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j] = Block(i, j, Color::YELLOW);
        }
    }
}
void Grid::randomShapes() {
    srand(time(nullptr));

    for (int line = height-1; line > height-4; --line) {
        for (int col = 0; col < this->width; ++col) {
            int random = rand() % 100;
            if (random < 60) {
                grid[line][col].setOccupied(true);
            }
        }
    }
}

void Grid::deleteLines(std::vector<int> lines) {

    for (auto row : lines) {
        for (int col = 0; col < grid[row].size(); ++col) {
            grid[row][col].setOccupied(false);
        }
    }
    for (auto &deleted : lines) {
        for (int row  = deleted; row >= 0; row--) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (row != 0){
                    bool occupied = grid[row -1][col].isOccupied();
                    grid[row -1][col].setOccupied(false);
                    if (occupied){
                        grid[row][col].setOccupied(true);
                    }
                }
            }
        }
        for (auto &elem : lines) {
            elem++;
        }
    }

}

bool Grid::isInside(const Tetromino &t) {
    for (auto position : t.getPosition()) {
        if (position.getX() < 0 || position.getX() > grid.size()
            || position.getY() < 0 || position.getY() > grid[grid.size()].size()){ // grid[grid.size()].size() peut créé une erreur
            return false;
        }
    }
    return true;
}

bool Grid::isFull() {
    for (int i = 0; i < this->grid.size(); ++i) {
        if (this->grid[0][i].isOccupied()) {
            return true;
        }
    }
    return false;
}

bool Grid::addTetromino(Tetromino &t) {
    std::vector<Position> tetroPos = t.getPosition();

    if (grid[tetroPos[0].getX()][tetroPos[0].getY()].isOccupied()){
        return true;
    }
    if (grid[tetroPos[1].getX()][tetroPos[1].getY()].isOccupied()){
        return true;
    }

    for (auto position: tetroPos) {
        grid[position.getX()][position.getY()].setOccupied(true);
        grid[position.getX()][position.getY()].setColor(t.getColor());
    }
    return false;
}

void Grid::removeTetromino(Tetromino &t){
    std::vector<Position> tetroPos = t.getPosition();
    for (auto position: tetroPos) {
        grid[position.getX()][position.getY()].setOccupied(false);
        grid[position.getX()][position.getY()].setColor(Color::BLACK);//je remet la couleur de base du tableau
    }
}
int Grid::searchAndRemoveFullLines() {
    std::vector<int> fullLines;
    bool full;
    for (int i = 0; i < this->grid.size(); ++i) {
        full = true;
        for (int j = 0; j < this->grid[i].size(); ++j) {
            if (!this->grid[i][j].isOccupied()) {
                full = false;
            }
        }
        if (full) {
            fullLines.push_back(i);
        }
    }

    if (fullLines.size()>0){
        deleteLines(fullLines);
    }
    return fullLines.size();
}

bool inTheList(Position pos, const std::vector<Position> &positions) {
    for (const auto &p : positions) {
        if (pos.getX() == p.getX() && pos.getY() == p.getY()) {
            return true;
        }
    }

    return false;
}



std::vector<Position> Grid::aroundTetro(const Tetromino &t) {
    std::vector<Position> occupiedcases;

    for (auto &position : t.getPosition()) {
        for (int i = 0; i < 3; ++i) {
            Position currPos(position.getX(),position.getY());
            switch (i) {
            case 0:
                currPos.setX(currPos.getX()+1);
                if (currPos.getY()< width && currPos.getY()>=0){
                    if (grid[currPos.getX()][currPos.getY()].isOccupied()
                        && !inTheList(currPos,t.getPosition())){
                        occupiedcases.push_back(currPos);
                    }
                }
                break;
            case 1:
                currPos.setY(currPos.getY()+1);
                if (currPos.getY()< width && currPos.getY()>0){
                    if (grid[currPos.getX()][currPos.getY()].isOccupied() && !inTheList(currPos,t.getPosition())){
                        occupiedcases.push_back(currPos);
                    }
                }
                break;
            case 2:
                currPos.setY(currPos.getY()-1);
                if (currPos.getY()< width && currPos.getY()>0){
                    if (grid[currPos.getX()][currPos.getY()].isOccupied() && !inTheList(currPos,t.getPosition())){
                        occupiedcases.push_back(currPos);
                    }
                }
                break;
            }
        }
    }
    return occupiedcases;
}


int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}
std::ostream& operator<<(std::ostream& os, const Grid& grid) {
    int maxColWidth = std::to_string(grid.getWidth()).length();

    os << "   ";
    for (int j = 1; j <= grid.getWidth(); ++j) {
        os << std::setw(maxColWidth + 1) << j;
    }
    os << std::endl;
    os << "    ";
    os << std::string(grid.getWidth()*3,'-');
    os << std::endl;

    for (int i = 0; i < grid.getHeight(); ++i) {
        os << std::setw(3) << i + 1 << "|";
        for (int j = 0; j < grid.getWidth(); ++j) {
            if (!grid.grid[i][j].isOccupied())
                os << " - ";
            else
                os << " X ";
        }
        os << "|" << std::endl;
    }

    os << "    ";
    os << std::string(grid.getWidth()*3,'-');
    os << std::endl;

    return os;
}




