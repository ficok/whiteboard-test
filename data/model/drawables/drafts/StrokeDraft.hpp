#pragma once

#include "DrawableDraft.hpp"

class StrokeDraft final: public DrawableDraft {
private:
    QVector<QPointF> _points;
    QColor _color;
    qreal _thickness;

public:
    StrokeDraft(QColor color, qreal thickness);
    void update(const QPointF &scenePos) override;

    StrokeData data() const;
    DrawableElement toElement() const override;
};
