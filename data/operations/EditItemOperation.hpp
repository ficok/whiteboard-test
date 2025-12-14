#pragma once

#include "Operation.hpp"

class DrawableItem;

class EditItemOperation: public Operation {
public:
    DrawableItem* original;
    DrawableItem* modified;

};
