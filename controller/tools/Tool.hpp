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
    /**
     * treba da napravi Operation instancu i kaze sceni
     * da je izvrsi i stashuje, a zatim da kontroleru
     * posalje zahtev za modifikaciju dokumenta.
     * @brief onMouseRelease
     * @param event
     * @param scene
     * @param controller
     */
    virtual void onMouseRelease(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene,
        Controller& controller) = 0;
};
