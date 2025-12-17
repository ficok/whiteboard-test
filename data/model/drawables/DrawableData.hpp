#pragma once

#include <QVector>
#include <QColor>
#include <QtTypes>
#include <QPointF>
#include <QRectF>

struct StrokeData {
    QVector<QPointF> points;
    QColor color;
    qreal thickness;
};

struct RectangleData {
    QRectF rect;
    QColor strokeColor;
    QColor fillColor;
    qreal strokeThickness;
};

using DrawableData = std::variant<
    StrokeData,
    RectangleData
    >;
