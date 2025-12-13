#include "Page.hpp"
#include "DrawableElement.hpp"

qint32 Page::id() const {
    return _id;
}
void Page::id(qint32 id) {
    _id = id;
}
qint32 Page::size() const {
    return _elements.size();
}
QVector<DrawableElement *>& Page::elements() {
    return _elements;
}
void Page::addElement(DrawableElement *element) {
    // napravi deep copy elementa prvo
    _elements.push_back(element);
}
DrawableElement *Page::operator[](int idx) {
    // provera da li je idx validan
    return _elements[idx];
}
