#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"
#include "Response.hpp"
#include "Backend.hpp"

class DrawableItem;
class DrawableElement;

class BackendManager {
private:
    Backend* _backend;
    static BackendManager* _instance;
    BackendManager();
    BackendManager(Backend* backend);
    ~BackendManager();

    BackendManager(const BackendManager& other) = delete;
    BackendManager& operator =(const BackendManager& other) = delete;
    BackendManager(BackendManager&& other) = delete;
    BackendManager& operator =(BackendManager&& other) = delete;
public:
    static BackendManager& instance();
    Backend& backend() const;
    void changeBackend(Backend* newBackend);
};
