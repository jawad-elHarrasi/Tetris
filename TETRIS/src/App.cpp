#include "controller.h"
#include "firstwindow.h"
#include "mainwindow.h"
#include "qapplication.h"
int main(int argc, char *argv[]){

    controller::TetrisController controller;

    QApplication application(argc, argv);

    firstWindow myWindow(controller);

    myWindow.show();

    return application.exec();
}
