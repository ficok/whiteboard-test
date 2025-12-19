#pragma once

#include "Tool.hpp"
#include "StrokeDraft.hpp"
#include "PageScene.hpp"

class StrokeItem;

class StrokeTool final: public Tool {
private:
    // owns
    StrokeDraft* _draft = nullptr;
    // doesn't own; scene does
    StrokeItem* _item = nullptr;
    QUuid _pendingOpId = QUuid::createUuid();

public:
    ~StrokeTool() override;

    void onMousePress(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    void onMouseMove(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    void onMouseRelease(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
};
