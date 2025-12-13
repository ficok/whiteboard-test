#include "BackendManager.hpp"
#include "Backend.hpp"
#include "DrawableElement.hpp"
#include "DrawableItem.hpp"

BackendManager* BackendManager::_instance = nullptr;
BackendManager::BackendManager() {}
BackendManager::BackendManager(Backend* backend)
    : _backend(backend) {}
BackendManager::~BackendManager() {
    delete _backend;
}

BackendManager* BackendManager::instance() {
    if (_instance == nullptr)
        _instance = new BackendManager();
    return _instance;
}

void BackendManager::changeBackend(Backend* newBackend) {
    delete _backend;
    _backend = nullptr;
    _backend = newBackend;
}
Response<DrawableItem *> BackendManager::addElement(Request<QPair<qint32, DrawableItem *>> request) {
    return _backend->addElement(request);
}
ResponseBase BackendManager::addPage() {
    return _backend->addPage();
}
