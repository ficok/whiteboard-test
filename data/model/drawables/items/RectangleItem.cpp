#include "RectangleItem.hpp"

RectangleItem::RectangleItem(const RectangleData& data)
    : _data(data) {}
void RectangleItem::boundingRect() const {
    return _data.rect;
}
void RectangleItem::paint(
    QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    QPen pen(_data.strokeColor, _data.strokeThickness);
    painter->setPen(pen);
    painter->setBrush(_data.fillColor);
    painter->drawRect(_data.rect);
}
