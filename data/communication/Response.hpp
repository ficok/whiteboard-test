#pragma once

#include <QUuid>
/**
 * @brief The Response class
 * ova klasa je jedinica prenosa informacija u smeru Document -> UI.
 * za sada salje samo id operacije na koju se odnosi, id stranice ako je potrebno
 * i informaciju o tome da li je validan.
 *
 * kad se bude dodao undo/redo, morace da se salje i ceo element.
 * undo/redo bi trebalo da se salju iz dokumenta (jer je to operacija koja takodje
 * menja stanje dokumenta). tada, posto sta god da treba da se nacrta ne dolazi iz
 * user input-a, moraju da se posalju svi neophodni podaci za crtanje elementa.
 * tad bi trebalo omogucit i salje celog elementa preko Response.
 */
class Response {
private:
    bool _valid = false;
    qint32 _pageIdx;
    QUuid _pendingOpId;

public:
    Response(QUuid pendingOpId, qint32 pageIdx, bool valid)
        : _pendingOpId(pendingOpId), _pageIdx(pageIdx), _valid(valid) {}
    Response(QUuid pendingOpId, bool valid)
        : _pendingOpId(pendingOpId), _valid(valid) {}
    bool valid() const {
        return _valid;
    }
    qint32 pageIdx() const {
        return _pageIdx;
    }
    QUuid pendingOpId() const {
        return _pendingOpId;
    }
};
