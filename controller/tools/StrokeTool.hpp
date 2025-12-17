#pragma once

#include "Tool.hpp"
#include "StrokeDraft.hpp"
#include "PageScene.hpp"

class StrokeTool final: Tool {
private:
    StrokeDraft* _draft = nullptr;
    QUuid _pendingOpId = QUuid::createQuuid();

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
        PageScene *scene,
        Controller &controller) override;
};
