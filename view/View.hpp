#pragma once

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include "Response.hpp"

class PageScene;

class View: public QGraphicsView {
    Q_OBJECT
private:
    qint32 _currentPageIdx;

    void refitScene();

public:
    // temp
    QVector<PageScene *> _pageScenes;
    explicit View(QWidget* parent = nullptr);
    ~View();

    qint32 currentPageIdx() const;
    void currentPageIdx(qint32 pageIdx);
    PageScene* currentPageScene() const;
    void nextPage();
    void previousPage();

protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void receiveResponse(const Response& response);
// protected:
//     void mousePressEvent(QMouseEvent* event) override;
//     void mouseMoveEvent(QMouseEvent* event) override;
//     void mouseReleaseEvent(QMouseEvent* event) override;
};
