#pragma once

#include <QObject>
#include <QGraphicsSceneMouseEvent>

class PageScene;
class DrawableItem;
class Controller;

class Tool: public QObject {
    Q_OBJECT
private:
    DrawableItem* _draft;

public:
    explicit Tool(QObject* parent = nullptr)
        : QObject(parent) {}
    virtual ~Tool() = default;

    virtual void onMousePress(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene) = 0;
    virtual void onMouseMove(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene) = 0;
    virtual DrawableItem* onMouseRelease(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene,
        Controller& controller) = 0;
};
