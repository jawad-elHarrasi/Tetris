#include <iostream>
#include "consoleview.h"
#include "Grid.h"
#include "keyboardAndStringConvert/keyboard.hpp"
#include <utility>

using namespace model;
using namespace std;

void view::ConsoleView::displayGrid(const Grid &grid) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << grid << endl;
}

void view::ConsoleView::displayGameLevel(const int &level){
    std::cout << "Level: " << level << std::endl;
}
void view::ConsoleView::displayGameScore(const int &score){
    std::cout << "Score: " << score << std::endl;
}

std::pair<int, int> view::ConsoleView::displayHello() {

    cout << "WELCOM TO TETRIS GAME" << endl;

    std::pair<int, int> dimensions;
    bool validInput = false;

    while (!validInput) {
        cout << "Do you want to choose the grid dimensions? (yes/no): ";
        string choice;
        he2b::esi::dev4::lineFromKbd(choice);

        if(choice == "yes") {
            string rows, cols;

            cout << "Enter the number of rows: ";
            he2b::esi::dev4::lineFromKbd(rows);

            int row;
            while (!isNumber(rows)){
                cout << "invalid input please try again : ";
                he2b::esi::dev4::lineFromKbd(rows);
            }

            row = std::stoi(rows);

            while (row < 10){
                cout << "dimention not allowd please try again";
                he2b::esi::dev4::lineFromKbd(rows);

                while (!isNumber(rows)){
                    cout << "invalid input please try again : ";
                    he2b::esi::dev4::lineFromKbd(rows);
                }
                row = std::stoi(rows);
            }


            cout << "Enter the number of columns: ";
            he2b::esi::dev4::lineFromKbd(cols);

            int col;
            while (!isNumber(cols)){
                cout << "invalid input please try again : ";
                he2b::esi::dev4::lineFromKbd(cols);
            }

            col = std::stoi(cols);

            while (col < 20){
                cout << "dimention not allowd please try again : ";
                he2b::esi::dev4::lineFromKbd(cols);

                while (!isNumber(cols)){
                    cout << "invalid input please try again : " ;
                    he2b::esi::dev4::lineFromKbd(cols);
                }
                col = std::stoi(cols);
            }


            dimensions = std::make_pair(row, col);
            validInput = true;

        } else if(choice == "no") {

            dimensions = std::make_pair(0, 0);
            validInput = true;

        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    }

    return dimensions;
}

bool view::ConsoleView::randomTeros(){
    cout << "do you want to initialise the grid with random shapes (yes/no) : ";

    bool validInput = false;


    while (!validInput) {
        string choice;
        he2b::esi::dev4::lineFromKbd(choice);

        if(choice == "yes") {
            return true;
        } else if(choice == "no") {
            return false;
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    }
    return false;

}

void view::ConsoleView::displayHelp() {
    std::cout << "Enter your move:\n";
    std::cout << "  D: Move the tetromino down\n";
    std::cout << "  R: Move the tetromino right\n";
    std::cout << "  W: Rotate the tetromino clockwise\n";
    std::cout << "  C: Rotate the tetromino counterclockwise\n";
    std::cout << "  L: Move the tetromino left\n";
    std::cout << "  Q: Quit the game\n";
    std::cout << "Your choice (D/R/W/C/L/Q): ";
}


// void Observer::update(const std::string &message,const model::Grid &grid) {
//     if (message == Game::GAME_MODIFICATION) {
//             view::ConsoleView::displayGrid(grid);

//     }

// }
// void Observer::update(const std::string &message, const int &args) {
//     if (message == Game::SCORE_MODIFICATION ) {
//             view::ConsoleView::displayGameScore(args);
//     } else if (message == Game::LEVEL_MODIFICATION) {
//             view::ConsoleView::displayGameLevel(args);
//     }
// }

bool view::ConsoleView::isNumber(const std::string& str) {
    std::istringstream iss(str);
    int n;
    if (iss >> n) {
        char c;
        if (iss >> c) {
            return false;
        }
        return true;
    }
    return false;
}

