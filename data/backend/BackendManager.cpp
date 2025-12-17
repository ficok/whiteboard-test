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
    if (_backend != nullptr) {
        delete _backend;
        _backend = nullptr;
    }
    _backend = newBackend;
}

Backend& BackendManager::backend() const {
    return *_backend;
}
