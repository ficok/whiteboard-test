#pragma once

#include <QUuid>

class PageScene;

class Operation {
public:
    QUuid id;

    Operation() {
        id = QUuid::createUuid();
    }

    virtual void commit(PageScene& scene) = 0;
    virtual void rollback(PageScene& scene) = 0;
    virtual void clone() = 0;
};
