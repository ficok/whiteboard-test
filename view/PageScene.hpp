#pragma once

#include <QGraphicsScene>

class DrawableItem;

class PageScene: public QGraphicsScene {
private:
    qint32 _pageIdx;

public:
    PageScene(QObject* parent = nullptr);
    PageScene(qint32 pageIdx, QObject* parent = nullptr);
    ~PageScene() = default;

    qint32 pageIdx() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;
};
