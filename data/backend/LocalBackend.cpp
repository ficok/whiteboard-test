#include "LocalBackend.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"

Response<DrawableItem *> LocalBackend::addElement(const Request<QPair<qint32, DrawableItem *>>& request) {
    auto& document = Document::instance();
    auto pageIdx = request.payload().first;
    auto item = request.payload().second;
    auto no_elements = document[pageIdx].size();
    auto element = convertToElement(item);
    element->id(no_elements);
    document[pageIdx].addElement(convertToElement(item));
    auto response = Response<DrawableItem *>(item);
    response.valid(true);
    return response;
}
ResponseBase LocalBackend::addPage() {
    auto& document = Document::instance();
    auto newPage = new Page();
    newPage->id(document.size());
    document.addPage(newPage);
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
