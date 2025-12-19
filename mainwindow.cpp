#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Controller.hpp"
#include "AddPageRequestModel.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _view = new View(this);
    setCentralWidget(_view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
