#pragma once

#include <QtTypes>
#include "DrawableElement.hpp"
/**
 * @brief The AddItemRequestModel class
 * primer klase koja se prosledjue kao payload u Request.
 * mora da sadrzi sve potrebne informacije da bi se promena ispravno uradila u dokumentu.
 * za dodavnje novog elementa, to su stranica i podaci.
 */
class AddItemRequestModel {
public:
    qint32 pageIdx;
    DrawableElement element;

    AddItemRequestModel(qint32 pageIdx, DrawableElement element)
        : pageIdx(pageIdx), element(element) {}
};
