#include "firstwindow.h"
#include "mainwindow.h"
#include "ui_firstwindow.h"

firstWindow::firstWindow(controller::TetrisController &ctrl, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstWindow)
    , controller(ctrl)
{
    ui->setupUi(this);

    // Connectez le signal clicked du bouton "Submit" à la fonction correspondante
    connect(ui->submitBtn, &QPushButton::clicked, this, &firstWindow::onSubmitButtonClicked);
}

firstWindow::~firstWindow()
{
    delete ui;
}

void firstWindow::onSubmitButtonClicked()
{
    bool isRandomChecked = ui->randomRadio->isChecked();
    bool defaultDim = ui->defaultDim->isChecked();
    int height = ui->height->value();
    int width = ui->width->value();

    mainWindow =  std::make_unique<MainWindow>(this->controller, width, height, isRandomChecked, defaultDim);

    this->close();

    mainWindow->show();

}
