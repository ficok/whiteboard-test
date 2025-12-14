#include "LocalBackend.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"
#include "AddItemOperation.hpp"
#include "EditItemOperation.hpp"

void LocalBackend::addElement(const Request<QPair<qint32, AddItemOperation *>>& request) {
    auto& document = Document::instance();
    auto pageIdx = request.payload().first;
    auto operation = request.payload().second;
    auto item = operation->item;
    auto no_elements = document[pageIdx].size();
    auto element = convertToElement(operation->item);
    element->id(no_elements);
    document.addElement(request.id, pageIdx, convertToElement(item));
}
void LocalBackend::addPage(const Request<AddPageOperation *> request) {
    auto& document = Document::instance();
    auto newPage = new Page();
    newPage->id(document.size());
    document.addPage(request.id, newPage);
}

DrawableElement* LocalBackend::convertToElement(DrawableItem* item) {
    return nullptr;
}

DrawableItem* LocalBackend::convertToItem(DrawableElement* element) {
    return nullptr;
}
