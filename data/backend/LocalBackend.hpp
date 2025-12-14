#pragma once

#include "Backend.hpp"
#include "Document.hpp"

class LocalBackend: public Backend {
private:
    DrawableElement* convertToElement(DrawableItem *item);
    DrawableItem* convertToItem(DrawableElement *element);
public:
    LocalBackend() = default;
    ~LocalBackend() = default;

    Response<DrawableItem *> addElement(const Request<QPair<qint32, DrawableItem *>>& request) override;
    ResponseBase addPage() override;
};
