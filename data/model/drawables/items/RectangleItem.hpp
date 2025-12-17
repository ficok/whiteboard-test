#pragma once

#include "DrawableData.hpp"
#include "DrawableItem.hpp"


class RectangleItem final: public DrawableItem {
private:
    RectangleData _data;

public:
    explicit RectangleItem(const RectangleData& data);
    QRectF boundingRect() const override;
    void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget) override;
};
