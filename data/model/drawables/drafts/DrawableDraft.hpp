#pragma once

#include "DrawableElement.hpp"
#include "DrawableItem.hpp"
/**
 * @brief The DrawableDraft class
 * ova klasa je posrednik izmedju DrawableElement i DrawableItem.
 * sustina je sledeca:
 * mouse press, move i release event-ovi u XTool prave XDraft na osnovu
 * podataka iz eventa (pozicija kursora).
 * na press, XDraft napravi XItem i posalje ga sceni. scena iscrta XItem.
 * na move, XDraft azurira sebe i prosledi nove podatke XItem-u. XItem se azurira.
 * na release, XDraft iz konacnih podataka na pravi DrawableElement koji sadrzi
 * XData i salje u dokument na cuvanje.
 *
 * zbog cega postoji posrednik uopste?
 * postoji kako bi se razdvojio posao:
 * - Item sluzi iskljucivo za crtanje na sceni
 * - Element sluzi iskljucivo za cuvanje stanja
 * - Draft posreduje izmedju.
 */
class DrawableDraft {
public:
    virtual ~DrawableDraft() = default;
    virtual void update(const QPointF& scenePos) = 0;
    virtual DrawableElement toElement() const = 0;
};
