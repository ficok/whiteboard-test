#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QPoint>
#include <QtTypes>
#include <QWidget>

class DrawableElement;

class DrawableItem: public QGraphicsItem {
private:
    QPointF _startPoint;
    DrawableElement *_element; // ?
    QPainterPath _path;
    QRectF _bounding;


public:
    DrawableItem(const QPointF& startPoint);
    QRectF boundingRect() const override;
};
