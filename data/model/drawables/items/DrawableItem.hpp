#pragma once

#include <QGraphicsItem>
#include <QUuid>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include "DrawableData.hpp"

class DrawableElement;
/**
 * @brief The DrawableItem class
 * ova klasa se crta direktno na sceni.
 * implementira QGraphicsItem::paint, QGraphicsItem::boundingRect i sta god
 * je neophodno pored toga.
 * drugim recima, svaka konkretna item klasa zna kako treba da se crta.
 * ovo je primer Strategy/Policy obrazca.
 *
 * konkretne implementacije moraju da sadrze odgovarajucu sync(XData) funkciju,
 * koja dobija nove podatke (od XDraft) i crta ih. sync funkcija sluzi
 * za azuriranje itema na sceni, bez da mora cela scena da se renderuje iznova.
 * sync() na kraju mora da pozove update() metodu.
 */
class DrawableItem: public QGraphicsItem {
public:
    virtual ~DrawableItem() = default;
    /**
     * @brief elementId
     * veza izmedju item-a i elementa koji ga predstavlja u dokumentu.
     * trenutno su razlicitog tipa (element sadrzi qint32 id) i to je greska,
     * treba se odluciti da li ce elementi da imaju QUuid ili qint32 za id;
     * ja sam krenuo sa QUuid, ali sam presao na id jer sam cuvao elemente u
     * vektoru i zeleo sam da budu poredjani po redosledu dodavanja u dokument.
     * mozda za to nema potrebe doduse, jer ce redosled dodavanja da bude odrzan
     * u command history verovatno.
     */
    QUuid elementId;
};
