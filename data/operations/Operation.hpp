#pragma once

#include <QUuid>

class PageScene;

class Operation {
public:
    QUuid id;
    Operation(QUuid id): id(id) {}
    virtual ~Operation() = default;
    virtual void commit(PageScene* scene) = 0;
    virtual void rollback(PageScene* scene) = 0;
};
