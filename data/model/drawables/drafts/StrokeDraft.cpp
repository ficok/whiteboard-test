#include "StrokeDraft.hpp"
#include "StrokeItem.hpp"

StrokeDraft::StrokeDraft(QColor color, qreal thickness)
    : _color(color), _thickness(thickness) {}

void StrokeDraft::update(const QPointF& pos) {
    _points.push_back(pos);
}

DrawableElement StrokeDraft::toElement() const {
    return DrawableElement(
        StrokeData {
            _points, _color, _thickness
        });
}
StrokeData StrokeDraft::data() const {
    return StrokeData {
        _points, _color, _thickness
    };
}
