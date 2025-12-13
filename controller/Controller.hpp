#pragma once

#include "Request.hpp"
#include "Response.hpp"
#include <QPair>
#include <QtTypes>

class DrawableElement;
class DrawableItem;

class Controller {
private:

public:
    Response<DrawableItem *> addElement(const Request<QPair<qint32, DrawableItem *>>& request);
    Response<DrawableItem *> editElement(const Request<QPair<qint32, DrawableItem *>>& request);
    ResponseBase removeElement(const Request<QPair<qint32, DrawableItem *>>& request);
    ResponseBase addPage();
    ResponseBase removePage(const Request<qint32>& request);
};
