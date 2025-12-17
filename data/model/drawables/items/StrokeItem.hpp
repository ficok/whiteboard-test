#pragma once

#include "DrawableData.hpp"
#include "DrawableItem.hpp"

class StrokeItem final: public DrawableItem {
private:
    StrokeData _data;
    QRectF _bounding;

public:
    explicit StrokeItem(const StrokeData& data);
    QRectF boundingRect() const override;
    void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget) override;
};
