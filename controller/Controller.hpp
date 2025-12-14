#pragma once

#include "Request.hpp"
#include "Response.hpp"
#include <QPair>
#include <QtTypes>

class DrawableElement;
class DrawableItem;
class AddItemOperation;
class AddPageOperation;

class Controller {
private:

public:
    Response<DrawableItem *> addElement(const Request<QPair<qint32, AddItemOperation *>>& request);
    // Response<DrawableItem *> editElement(const Request<QPair<qint32, DrawableItem *>>& request);
    // ResponseBase removeElement(const Request<QPair<qint32, DrawableItem *>>& request);
    ResponseBase addPage(const Request<AddPageOperation *>& request);
    // ResponseBase removePage(const Request<qint32>& request);
};
