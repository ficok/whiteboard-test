#pragma once

#include <QObject>
#include <QGraphicsSceneMouseEvent>

class PageScene;
class DrawableItem;
class Controller;
/**
 * @brief The Tool class
 * scena prosledjuje mouse event-ove aktivnom tool-u.
 * svaki konkretan tool zna sta tacno treba da radi sa tim informacijama
 * unutar svojih mouse event handler metoda.
 *
 * ovo je primer Strategy/Policy obrazca.
 *
 * pogledati StrokeTool za vise detalja.
 */
class Tool {
public:
    explicit Tool() = default;
    virtual ~Tool() = default;

    virtual void onMousePress(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene) = 0;
    virtual void onMouseMove(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene) = 0;
    virtual void onMouseRelease(
        QGraphicsSceneMouseEvent* event,
        PageScene* scene) = 0;
};
