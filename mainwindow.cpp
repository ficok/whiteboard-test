#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _scene = new PageScene(this);
    _scene->pageIdx(0);
    _scene->setSceneRect(0,0,1000,1000);
    _view = new View(this);
    _view->_pageScenes.push_back(_scene);
    _view->currentPageIdx(0);
    _view->setScene(_scene);
    _view->setRenderHint(QPainter::Antialiasing);
    _view->setDragMode(QGraphicsView::NoDrag);

    setCentralWidget(_view);
    _scene->addRect(50,50,100,100, QPen(Qt::black), QBrush(Qt::red));
}

MainWindow::~MainWindow()
{
    delete ui;
}
