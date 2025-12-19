#include "LocalBackend.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"
#include "AddItemRequestModel.hpp"
#include "AddPageRequestModel.hpp"
#include "AddItemOperation.hpp"
#include "AddPageOperation.hpp"
#include "EditItemOperation.hpp"

void LocalBackend::addElement(const Request<AddItemRequestModel>& request) {
    auto requestModel = request.payload();
    auto pageIdx = requestModel.pageIdx;
    auto element = requestModel.element;
    auto no_elements = (*Document::instance())[pageIdx].size();
    element.id = no_elements;
    Document::instance()->addElement(request.id(), pageIdx, element);
}
void LocalBackend::addPage(const Request<AddPageRequestModel>& request) {
    auto newPage = new Page();
    newPage->id(Document::instance()->size());
    Document::instance()->addPage(request.id(), newPage);
}
