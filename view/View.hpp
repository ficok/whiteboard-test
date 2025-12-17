#pragma once

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class PageScene;

class View: public QGraphicsView {
private:

    qint32 _currentPageIdx;

public:
    // temp
    QVector<PageScene *> _pageScenes;
    View(QWidget* parent = nullptr);
    ~View();

    qint32 currentPageIdx() const;
    void currentPageIdx(qint32 pageIdx);
    PageScene* currentPageScene() const;
    void nextPage();
    void previousPage();

// protected:
//     void mousePressEvent(QMouseEvent* event) override;
//     void mouseMoveEvent(QMouseEvent* event) override;
//     void mouseReleaseEvent(QMouseEvent* event) override;
};
