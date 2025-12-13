#pragma once

#include <QGraphicsScene>

class DrawableItem;

class PageScene: public QGraphicsScene {
private:
    qint32 _pageIdx;
    QVector<DrawableItem *> _items;

public:
    PageScene(qint32 pageIdx);

    qint32 pageIdx() const;
    QVector<DrawableItem *>& items();
    void addItem(DrawableItem *item);
    void removeItem(DrawableItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;
};
