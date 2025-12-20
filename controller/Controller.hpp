#pragma once

#include "Request.hpp"
#include <QPair>
#include <QtTypes>

class DrawableElement;
class DrawableItem;
class AddItemRequestModel;
class AddPageRequestModel;

/**
 * @brief The Controller class
 * kontroler klasa prenosi zahteve od UI do Backend-a.
 * u svojoj najosnovnijoj formi, metode koje postoje
 * u Backend-u moraju da postoje i ovde, preferabilno istog
 * imena da bi se znalo tacno koja kojoj odgovara.
 * naravno, ako LocalBackend ima neke svoje privatne metode,
 * one ne treba da postoje ovde i obrnuto.
 * ja ocekujem da ce ovde da bude samo jednostavno prenosenje
 * podataka; logika se radi u LocalBackend.
 */
class Controller {
private:

public:
    Controller() = default;
    ~Controller() = default;

    void addElement(const Request<AddItemRequestModel>& request);
    // Response<DrawableItem *> editElement(const Request<QPair<qint32, DrawableItem *>>& request);
    // Response removeElement(const Request<QPair<qint32, DrawableItem *>>& request);
    void addPage(const Request<AddPageRequestModel>& request);
    // Response removePage(const Request<qint32>& request);
};
