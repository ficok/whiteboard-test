#pragma once

#include <QVector>
#include <QColor>
#include <QtTypes>
#include <QPointF>
#include <QRectF>
/**
 * @brief The StrokeData class
 * podaci neophodni za pravljenje StrokeItem (ili
 * Pen, samo sam ga ja glupo nazvao)
 */
struct StrokeData {
    QVector<QPointF> points;
    QColor color;
    qreal thickness;
};
/**
 * @brief The RectangleData class
 * podaci neophodni za pravljenje RectangleItem
 */
struct RectangleData {
    QRectF rect;
    QColor strokeColor;
    QColor fillColor;
    qreal strokeThickness;
};

/**
 * std::variant je neka c++-ova pametna unija.
 * DrawableData je samo ime za tu uniju, i to samo da bi
 * bilo manje pisanja kasnije; funkcionalno ovo using DrawableData
 * ne mora da postoji.
 *
 * std::variant garantuje da ce u trenutku rada programa DrawableData
 * biti tacno jednog tipa iz liste.
 *
 * pre nego sto se pokrene program, imamo samo deklaraciju
 * struct DrawableElement {
 *   DrawableData data;
 * }
 *
 * kad radi program i kad pisemo, pravi se konkretan tip elementa (na primer,
 * Pen (ili Stroke, kako sam ja nazvao)). taj Pen sadrzi StrokeData.
 * kad se taj element sacuva u dokumentu, DrawableData iz DrawableElement
 * ce u stvari da predstavlja StrokeData.
 * interno to funkcionise tako sto std::variant u sebi sadrzi index izabranog tipa,
 * koji se pretpostavljam postavi kad pozovemo konstruktor DrawableElement i prosledimo
 * StrokeData
 */
using DrawableData = std::variant<
    StrokeData,
    RectangleData
    >;
