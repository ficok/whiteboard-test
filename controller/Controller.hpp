#pragma once

#include "Request.hpp"
#include <QPair>
#include <QtTypes>

class DrawableElement;
class DrawableItem;
class AddItemRequestModel;
class AddPageRequestModel;

class Controller {
private:

public:
    Controller() = default;
    ~Controller() = default;

    void addElement(const Request<AddItemRequestModel>& request);
    // Response<DrawableItem *> editElement(const Request<QPair<qint32, DrawableItem *>>& request);
    // Response removeElement(const Request<QPair<qint32, DrawableItem *>>& request);
    void addPage(const Request<AddPageRequestModel>& request);
    // Response removePage(const Request<qint32>& request);
};
