#include "StrokeItem.hpp"

StrokeItem::StrokeItem(const StrokeData& data)
    : _data(data) {}

QRectF StrokeItem::boundingRect() const {
    return _bounding;
}
void StrokeItem::paint(
    QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    QPen pen(_data.color, _data.thickness);
    painter->setPen(pen);
    for (int i = 1; i < _data.points.size(); ++i) {
        painter->drawLine(_data.points[i - 1], _data.points[i]);
    }
}
