#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"
#include "AddItemRequestModel.hpp"
#include "AddPageRequestModel.hpp"

class DrawableElement;
class DrawableItem;

class Backend {
public:
    virtual ~Backend() = default;

    virtual void addElement(const Request<AddItemRequestModel>& request) = 0;
    virtual void addPage(const Request<AddPageRequestModel>& request) = 0;
};
