#pragma once

#include "Backend.hpp"
#include "Document.hpp"

class AddItemOperation;
class AddPageOperation;

class LocalBackend: public Backend {
private:
    DrawableElement* convertToElement(DrawableItem *item);
    DrawableItem* convertToItem(DrawableElement *element);
public:
    LocalBackend() = default;
    ~LocalBackend() = default;

    void addElement(const Request<AddItemRequestModel>& request) override;
    void addPage(const Request<AddPageRequestModel>) override;
};
