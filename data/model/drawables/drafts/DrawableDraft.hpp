#pragma once

#include "DrawableElement.hpp"
#include "DrawableItem.hpp"

class DrawableDraft {
public:
    virtual ~DrawableDraft() = default;
    virtual void update(const QPointF& scenePos) = 0;
    virtual DrawableElement toElement() const = 0;
};
