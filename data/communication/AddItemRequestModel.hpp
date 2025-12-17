#pragma once

#include <QtTypes>
#include "DrawableElement.hpp"

class AddItemRequestModel {
public:
    qint32 pageIdx;
    DrawableElement element;

    AddItemRequestModel(qint32 pageidx, DrawableElement element)
        : pageIdx(pageIdx), element(element) {}
};
