#pragma once

#include "Operation.hpp"
#include "PageScene.hpp"

#include <QtTypes>

class DrawableItem;

class AddItemOperation: public Operation {
public:
    qint32 pageIdx;
    AddItemOperation(QUuid id, qint32 pageIdx, DrawableItem* item)
        : Operation(id), pageIdx(pageIdx), item(item) {}
    DrawableItem* item;

    void commit(PageScene* scene) override {
        scene->addItem(item);
    }
    void rollback(PageScene* scene) override {
        scene->removeItem(item);
        delete item;
    }
};
