#pragma once

#include <QtTypes>

class DrawableElement {
private:
    qint32 _id;
public:
    qint32 id() const;
    void id(qint32 id);
};
