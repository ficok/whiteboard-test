#pragma once

#include <QtTypes>
#include "DrawableData.hpp"
#include <QUuid>

/**
 * @brief The DrawableElement class
 * podaci za pojedinacne elemente na sceni. informacija o elementu se u stvari
 * sadrzi u DrawableData.
 *
 * struct i klasa su sustinski isti, osim sto
 * - default pristup struct-u je public, klasi je private
 * - default pristup nasledjivanjem struct-u je public, klasi je private
 *
 * struct obicno predstavlja pasivne podatke i modele za podatke,
 * a klasa ponasanje, ownership i finiju kontrolu zivotnog ciklusa
 * posto DrawableElement predstavlja imutabilne podatke koji cine stanje
 * dokumenta, struct je ovde jasniji izbor.
 */
struct DrawableElement {
    qint32 id;
    DrawableData data;

    DrawableElement(DrawableData data)
        : data(std::move(data)) {}
};
