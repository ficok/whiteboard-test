#include "Controller.hpp"
#include "DrawableItem.hpp"
#include "BackendManager.hpp"
#include "Backend.hpp"

Response<DrawableItem *> Controller::addElement(const Request<QPair<qint32, DrawableItem *>>& request) {
    auto& backend = BackendManager::instance().backend();
    backend.addElement(request);
}
ResponseBase Controller::addPage() {
    auto& backend = BackendManager::instance().backend();
    backend.addPage(request);
}
