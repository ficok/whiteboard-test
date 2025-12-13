#include "Controller.hpp"
#include "DrawableItem.hpp"
#include "BackendManager.hpp"

Response<DrawableItem *> Controller::addElement(const Request<QPair<qint32, DrawableItem *>>& request) {
    auto response = BackendManager::instance()->addElement(request);
    return response;
}
ResponseBase Controller::addPage() {
    auto response = BackendManager::instance()->addPage();
    return response;
}
