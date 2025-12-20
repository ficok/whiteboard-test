#pragma once

#include "Backend.hpp"
#include "Document.hpp"
#include "AddItemRequestModel.hpp"
#include "AddPageRequestModel.hpp"
#include "Request.hpp"
/**
 * @brief The LocalBackend class
 * konkretna implementacija logike komunikacije sa backend-om.
 * ova varijanta je samo za lokalne sesije na racunaru.
 *
 * ako hocete da dodate editElement npr, morate prvo da dodate
 * potpis virtuelne funkcije u Backend.hpp,
 * a onda ovde da dodate
 * void editElement(const Request<EditItemRequestModel>& request) override
 * i u cpp fajlu da implementirate.
 *
 * implementacije funkcija ovde samo treba da na najklasicniji nacin dodaju
 * elemente u vektor/mapu, sta god da koristimo za cuvanje stranica i elemenata.
 * za to treba da pozovu odgovarajuce metode koje nudi Document klasa.
 * metode u Document klasi treba samo da ubace element u svoju kolekciju
 * i posalju odgovarajuc signal.
 * ako je potrebno izracunati nesto pre toga (na primer, id elementa
 * ili sta god), to se radi u ovim metodama; Dokument mora da primi samo
 * gotove informacije koje moze samo da sacuva i posalje odgovor, bez da radi bilo sta drugo.
 */
class LocalBackend: public Backend {
private:
    DrawableElement* convertToElement(DrawableItem *item);
    DrawableItem* convertToItem(DrawableElement *element);
public:
    LocalBackend() = default;
    ~LocalBackend() = default;

    void addElement(const Request<AddItemRequestModel>& request) override;
    void addPage(const Request<AddPageRequestModel>& request) override;
};
