#pragma once

#include <QUuid>

class PageScene;

/**
 * @brief The Operation class
 * bitno je asinhrono azurirati UI. ako saljemo podatke za cuvanje u dokument i
 * onda cekamo odgovor o uspehu, moze da se desi zamrzavanje UI-a dok se sve to desi
 * (na primer, ako neko koristi program na slabijem racunaru).
 * medjutim, ne mozemo ni samo da crtamo direktno u scenu bez da se konsultujemo sa
 * dokumentom - sta ako mi nesto iscrtamo na sceni, ali se to ne sacuva u dokumentu?
 *
 * potrebno je naci resenje koje ispunjava:
 * 1. instant crtanje
 * 2. cekanje odgovora dokumenta o uspehu operacije
 *
 * ovo se obezbedjuje "optimisticnim renderovanjem/crtanjem":
 * - odmah renderuj ono sto sam crtao
 * - ali ostavi prostora za brisanje toga, ukoliko operacija ispadne nevalidna
 *
 * ova klasa je jedinica optimisticnog renderovanja. konkretne implementacije sadrze
 * na primer Item koji se crta (pogledati AddItemOperation) i
 * id operacije (dokument ce da posalje signal sa info o uspehu i id operacije na koju se odnosi,
 * koji sluzi za nalazenje operacije i njenog brisanja)
 *
 * commit i rollback omogucavaju ispunjavanje operacije ako je uspesna, to jest brisanje ako nije
 * neke od ovih operacija verovatno treba da imaju dva itema.
 * na primer, EditItem bi sadrzao podatke za crtanje originalnog stanja itema i novo stanje
 * itema.
 */
class Operation {
public:
    QUuid id;
    Operation(QUuid id): id(id) {}
    virtual ~Operation() = default;
    /**
     * @brief commit
     * @param scene
     * poziva se cim se operacija doda sceni. ako je operacija AddItem,
     * onda commit treba da crta item na sceni; ako je RemoveItem, onda ga brise.
     */
    virtual void commit(PageScene* scene) = 0;
    /**
     * @brief rollback
     * @param scene
     * poziva se samo ako dokument posalje signal da operacija nije uspesna.
     * rollback radi suprotno od commit.
     */
    virtual void rollback(PageScene* scene) = 0;
};
