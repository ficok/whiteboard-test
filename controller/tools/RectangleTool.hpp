#pragma once

#include "Tool.hpp"
#include "RectangleDraft.hpp"
#include "PageScene.hpp"

class RectangleTool final: public Tool {
private:
    RectangleDraft *_draft = nullptr;
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
