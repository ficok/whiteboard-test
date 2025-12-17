#pragma once

#include <QtTypes>
#include "DrawableData.hpp"
#include <QUuid>

/**
 * struct i klasa su sustinski isti, osim sto
 * - default pristup struct-u je public, klasi je private
 * - default pristup nasledjivanjem struct-u je public, klasi je private
 * struct obicno predstavlja pasivne podatke i modele za podatke,
 * klasa ponasanje, ownership i finiju kontrolu zivotnog ciklusa
 * posto DrawableElement predstavlja imutabilne podatke koji su "istina"
 * za dokument, struct je bolji ovde
 * @brief The DrawableElement class
 */
struct DrawableElement {
    QUuid id;
    DrawableData data;

    DrawableData(QUuid id, DrawableData data)
        : id(std::move(id)), data(std::move(data)) {}
};
