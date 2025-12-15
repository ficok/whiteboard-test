#include "LocalBackend.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"
#include "AddItemOperation.hpp"
#include "AddPageOperation.hpp"
#include "EditItemOperation.hpp"
#include "AddItemRequestModel.hpp"
#include "AddPageRequestModel.hpp"

void LocalBackend::addElement(const Request<AddItemRequestModel> request) {
    auto& document = Document::instance();
    auto requestModel = request.payload();
    auto pageIdx = requestModel.pageIdx;
    auto element = requestModel.element;
    auto no_elements = document[pageIdx].size();
    element->id(no_elements);
    document.addElement(request.id, pageIdx, element);
}
void LocalBackend::addPage(const Request<AddPageRequestModel> request) {
    auto& document = Document::instance();
    auto newPage = new Page();
    newPage->id(document.size());
    document.addPage(request.id, newPage);
}
