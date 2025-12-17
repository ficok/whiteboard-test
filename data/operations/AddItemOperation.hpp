#pragma once

#include "Operation.hpp"
#include "PageScene.hpp"

class DrawableItem;

class AddItemOperation: public Operation {
public:
    AddItemOperation(QUuid id, DrawableItem* item)
        : Operation(id), item(item) {}
    DrawableItem* item;

    void commit(PageScene* scene) override {
        scene->addItem(item);
    }
    void rollback(PageScene* scene) override {
        scene->removeItem(item);
        delete item;
    }
};
