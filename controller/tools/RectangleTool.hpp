#pragma once

#include "Tool.hpp"
#include "RectangleDraft.hpp"
#include "PageScene.hpp"

class RectangleItem;

class RectangleTool final: public Tool {
private:
    // owns
    RectangleDraft *_draft = nullptr;
    // doesn't own; scene does
    RectangleItem* _item = nullptr;
    QUuid _pendingOpId = QUuid::createUuid();

public:
    ~RectangleTool() override;

    void onMousePress(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    void onMouseMove(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    void onMouseRelease(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene,
        Controller &controller) override;
};
