#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"
#include "Response.hpp"

class Backend;
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
    BackendManager operator =(const BackendManager& other) = delete;
public:
    static BackendManager* instance();
    void changeBackend(Backend* newBackend);
    Response<DrawableItem *> addElement(Request<QPair<qint32, DrawableItem *>> request);
    ResponseBase addPage();
};
