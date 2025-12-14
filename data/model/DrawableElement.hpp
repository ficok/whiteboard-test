#pragma once

#include <QtTypes>

class DrawableElement {
private:
    qint32 _id;
public:
    DrawableElement() = default;
    ~DrawableElement() = default;

    qint32 id() const;
    void id(qint32 id);
};
