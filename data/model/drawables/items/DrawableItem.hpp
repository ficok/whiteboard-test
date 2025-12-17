#pragma once

#include <QGraphicsItem>
#include <QUuid>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class DrawableElement;

class DrawableItem: public QGraphicsItem {
public:
    virtual ~DrawableItem() = default;
    QUuid elementId;
};
