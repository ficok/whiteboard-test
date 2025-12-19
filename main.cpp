#include "mainwindow.h"
#include "BackendManager.hpp"
#include "LocalBackend.hpp"
#include "ToolManager.hpp"
#include "StrokeTool.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BackendManager::instance()->changeBackend(new LocalBackend());
    ToolManager::instance()->activeTool(new StrokeTool());
    Document::instance()->initialize();

    MainWindow w;
    w.show();
    return a.exec();
}
