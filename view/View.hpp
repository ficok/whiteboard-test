#pragma once

#include <QGraphicsView>

class PageScene;

class View: public QGraphicsView {
private:
    QVector<PageScene *> _pageScenes;
    qint32 _currentPageIdx;

public:
    View(QGraphicsView* parent)
        : QGraphicsView(parent) {}
    qint32 currentPageIdx() const;
    void currentPageIdx(qint32 pageIdx);
    void nextPage();
    void previousPage();
};
