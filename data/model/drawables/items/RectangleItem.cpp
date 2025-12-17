#include "RectangleItem.hpp"
#include "RectangleDraft.hpp"

RectangleItem::RectangleItem(const RectangleData& data)
    : _data(data) {}
QRectF RectangleItem::boundingRect() const {
    return _data.rect;
}
void RectangleItem::sync(RectangleData data) {
    _data = data;
    prepareGeometryChange();
    update();
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
