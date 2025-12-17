#pragma once

#include <QtTypes>

class DrawableElement;

class AddItemRequestModel {
public:
    AddItemRequestModel(qint32 pageidx, DrawableElement element)
        : pageIdx(pageIdx), element(element) {}
    qint32 pageIdx;
    DrawableElement element;
};
