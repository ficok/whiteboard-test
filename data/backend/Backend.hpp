#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"

class DrawableElement;
class DrawableItem;
class AddItemRequestModel;
class AddPageRequestModel;

class Backend {
public:
    virtual ~Backend() = default;

    virtual void addElement(const Request<AddItemRequestModel>& request) = 0;
    virtual void addPage(const Request<AddPageRequestModel>& request) = 0;
};
