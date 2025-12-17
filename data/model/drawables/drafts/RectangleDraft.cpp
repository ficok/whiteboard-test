#include "RectangleDraft.hpp"
#include "RectangleItem.hpp"

RectangleDraft::RectangleDraft(QColor stroke, QColor fill, qreal width)
    : _stroke(stroke), _fill(fill), _width(width) {}

void RectangleDraft::begin(const QPointF& start) {
    _start = start;
    _end = start;
}
void RectangleDraft::update(const QPointF& pos) {
    _end = pos;
}

DrawableElement RectangleDraft::toElement() const {
    return DrawableElement(
        RectangleData {
            QRectF(_start, _end).normalized(),
                _stroke, _fill, _width
        });
}
RectangleData RectangleDraft::data() const {
    const QRectF rect = QRectF(_start, _end).normalized();
    return RectangleData {
            rect, _stroke, _fill, _width
    };
}
