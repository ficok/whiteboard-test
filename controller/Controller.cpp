#include "Controller.hpp"
#include "DrawableItem.hpp"
#include "BackendManager.hpp"
#include "Backend.hpp"

Response<DrawableItem *> Controller::addElement(const Request<QPair<qint32, DrawableItem *>>& request) {
    auto& backend = BackendManager::instance().backend();
    auto response = backend.addElement(request);
    return response;
}
ResponseBase Controller::addPage() {
    auto& backend = BackendManager::instance().backend();
    auto response = backend.addPage();
    return response;
}
