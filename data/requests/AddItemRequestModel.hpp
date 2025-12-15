#pragma once

#include <QtTypes>

class DrawableElement;

class AddItemRequestModel {
public:
    qint32 pageIdx;
    DrawableElement element;
};
