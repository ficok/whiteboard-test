#include "StrokeDraft.hpp"
#include "StrokeItem.hpp"

StrokeDraft::StrokeDraft(QColor color, qreal thickness)
    : _color(color), _thickness(thickness) {}

void StrokeDraft::update(const QPointF& pos) override {
    _points.push_back(pos);
}

DrawableElement StrokeDraft::toElement() const {
    return DrawableElement(
        QUuid::createQuuid(),
        StrokeData {
            _points, _color, _thickness
        });
}
DrawableItem* StrokeDraft::toItem() const {
    return new StrokeItem(
        StrokeData {
            _points, _color, _thickness
        });
}
