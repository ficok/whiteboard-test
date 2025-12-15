#include "DrawableItem.hpp"
#include "DrawableElement.hpp"

DrawableItem::DrawableItem(const QPointF &startPoint)
    : _startPoint(startPoint) {

    /* verovatno trebe inicijalizovati i _bounding */
}
QRectF DrawableItem::boundingRect() const {
    return _bounding;
}
