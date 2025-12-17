#pragma once

#include "DrawableData.hpp"
#include "DrawableDraft.hpp"
#include "DrawableElement.hpp"

class RectangleDraft final: public DrawableDraft {
private:
    QPointF _start;
    QPointF _end;
    QColor _stroke;
    QColor _fill;
    qreal _width;

public:
    RectangleDraft(QColor stroke, QColor fill, qreal width);
    void begin(const QPointF& start);
    void update(const QPointF& pos) override;

    RectangleData data() const;
    DrawableElement toElement() const override;
};
