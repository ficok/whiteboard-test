#pragma once

#include "DrawableData.hpp"
#include "DrawableItem.hpp"

class RectangleDraft;

class RectangleItem final: public DrawableItem {
private:
    RectangleData _data;

public:
    explicit RectangleItem(const RectangleData& data);
    QRectF boundingRect() const override;
    void sync(RectangleData data);
    void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget) override;
};
