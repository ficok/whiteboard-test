#pragma once

#include <QtTypes>
#include <QVector>

class DrawableElement;

class Page {
private:
    qint32 _id;
    QVector<DrawableElement *> _elements;
public:
    Page() = default;
    ~Page();

    Page(const Page& other) = delete;
    Page& operator =(const Page& other) = delete;

    qint32 id() const;
    void id(qint32 id);

    qint32 size() const;

    QVector<DrawableElement *>& elements();
    void addElement(DrawableElement *element);
    // removeElement
    DrawableElement *operator[](int idx);
};
