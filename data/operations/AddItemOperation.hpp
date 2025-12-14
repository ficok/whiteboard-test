#pragma once

#include "Operation.hpp"

class DrawableItem;

class AddItemOperation: public Operation {
public:
    DrawableItem* item;

};
