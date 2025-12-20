#pragma once

#include "Operation.hpp"
#include "PageScene.hpp"

#include <QtTypes>

class DrawableItem;
/**
 * @brief The AddItemOperation class
 * dok god postoji, operacija own-uje DrawableItem.
 * posto je item dodat u scenu, ukoliko je operacija uspela,
 * brise se samo operacija, *ali ne i item*.
 * item onda treba da own-je scena, jer se tu i dalje crta.
 * ako se operacija odbija, rollback takodje treba da obrise item
 * i iz scene i da posti njegovu memoriju.
 */
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
