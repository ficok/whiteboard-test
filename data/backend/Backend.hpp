#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"
#include "Response.hpp"

class DrawableElement;
class DrawableItem;

class Backend {
public:
    virtual ~Backend() = default;

    virtual Response<DrawableItem *> addElement(const Request<QPair<qint32, DrawableItem *>>& request) = 0;
    virtual ResponseBase addPage(const Request<AddPageOperation*> request) = 0;
};
