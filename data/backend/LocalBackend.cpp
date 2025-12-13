#include "LocalBackend.hpp"
#include "Document.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"

LocalBackend::LocalBackend() {
    _document = Document::instance();
}

Response<DrawableItem *> LocalBackend::addElement(Request<QPair<qint32, DrawableItem *>> request) {
    auto pageIdx = request.payload().first;
    auto item = request.payload().second;
    auto no_elements = _document[pageIdx].size();
    auto element = convertToElement(item);
    element->id(no_elements);
    (*_document)[pageIdx]->addElement(convertToElement(item));
    auto response = Response<DrawableItem *>(item);
    response.valid(true);
    return response;
}
ResponseBase LocalBackend::addPage() {
    auto newPage = new Page();
    newPage->id(_document->size());
    _document->addPage(newPage);
    auto response = ResponseBase();
    response.valid(true);
    return response;
}

DrawableElement* LocalBackend::convertToElement(DrawableItem* item) {
    return nullptr;
}

DrawableItem* LocalBackend::convertToItem(DrawableElement* element) {
    return nullptr;
}
