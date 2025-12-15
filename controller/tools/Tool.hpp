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
     * mora da uradi naredne stvari:
     * 1. pravi DrawableDraft, sto predstavlja kanonski oblik elementa
     * 2. pravi Operation instancu i stavlja je u stash scene za optimisticno crtanje
     * 3. konvertuje DrawableDraft u DrawableElement i predaje kontroleru
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
