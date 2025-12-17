#include "StrokeItem.hpp"
#include "QPainterPath"

StrokeItem::StrokeItem(const StrokeData& data)
    : _data(data) {}

QRectF StrokeItem::boundingRect() const {
    return _path.boundingRect();
}
void StrokeItem::sync(StrokeData data) {
    _data = data;
    rebuildPath();
    update();
}

void StrokeItem::rebuildPath() {
    _path = QPainterPath();
    if (_data.points.empty()) return;

    _path.moveTo(_data.points[0]);
    for (int i = 1; i < _data.points.size(); ++i)
        _path.lineTo(_data.points[i]);
}

void StrokeItem::paint(
    QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    QPen pen(_data.color, _data.thickness);
    painter->setPen(pen);
    painter->drawPath(_path);
}
