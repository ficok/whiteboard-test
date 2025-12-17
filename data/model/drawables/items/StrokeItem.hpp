#pragma once

#include "DrawableData.hpp"
#include "DrawableItem.hpp"

class StrokeItem final: public DrawableItem {
private:
    StrokeData _data;
    QPainterPath _path;
    void rebuildPath();

public:
    explicit StrokeItem(const StrokeData& data);
    QRectF boundingRect() const override;
    void sync(StrokeData data);
    void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget) override;
};
