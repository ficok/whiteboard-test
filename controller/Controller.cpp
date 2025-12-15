#include "Controller.hpp"
#include "DrawableItem.hpp"
#include "BackendManager.hpp"
#include "Backend.hpp"

void Controller::addElement(const Request<AddItemRequestModel>& request) {
    auto& backend = BackendManager::instance().backend();
    backend.addElement(request);
}
void Controller::addPage(const Request<AddPageRequestModel>& request) {
    auto& backend = BackendManager::instance().backend();
    backend.addPage(request);
}
