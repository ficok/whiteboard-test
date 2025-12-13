#pragma once

#include "Backend.hpp"

class Document;

class LocalBackend: public Backend {
private:
    Document* _document;

    DrawableElement* convertToElement(DrawableItem *item);
    DrawableItem* convertToItem(DrawableElement *element);
public:
    LocalBackend();
    Response<DrawableItem *> addElement(Request<QPair<qint32, DrawableItem *>> request) override;
    ResponseBase addPage() override;
};
