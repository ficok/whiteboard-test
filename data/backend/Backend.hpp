#pragma once

#include <QtTypes>
#include <QPair>
#include "Request.hpp"
#include "AddItemRequestModel.hpp"
#include "AddPageRequestModel.hpp"

class DrawableElement;
class DrawableItem;
/**
 * @brief The Backend class
 * apstraktna klasa za backend.
 * omogucava postavljanje vise razlicitih logika/nacina pristupa dokumentu.
 * jedino sto cemo mi imati je LocalBackend koji komunicira direktno sa
 * Document klasom i dodaje, menja i brise podatke iz nje.
 *
 * U TEORIJI (nemojte da se ljutite samo objasnjam poentu ovog raslojavanja)
 * dakle *u teoriji* bi postojao RemoteBackend za klijent server jer bi se tu drugacije
 * radila komunikacija sa dokumentom. u teoriji
 *
 * u praksi, ovde se samo nalaze potpisi metoda koje koristimo za komunikaciju sa dokumentom.
 * dakle, ako neko bude implementirao editElement ili removeElement, ovde ce da doda potpis funkcije
 * virtual void editElement(const Request<EditItemRequestModel>& request) = 0
 * i posle mora da ga override-uje u LocalBackend.hpp i implementira u LocalBackend.cpp.
 */
class Backend {
public:
    virtual ~Backend() = default;

    virtual void addElement(const Request<AddItemRequestModel>& request) = 0;
    virtual void addPage(const Request<AddPageRequestModel>& request) = 0;
};
