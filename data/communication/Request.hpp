#pragma once

#include <utility>
#include <QUuid>

/**
 * @brief The Request class
 * Request klasa je samo jedinica prenosa informacija u smeru UI -> Document.
 * mora da salje:
 * - payload (sto je neki konkretan RequestModel; za detalje pogledati
 *   AddItemRequestModel); payload predstavlja podatke koji ce da se iskoriste
 *   za menjanje dokumenta
 * - pendingOpId, koji je id operacije dodate u scenu. preko ovog id-ja ce dokument
 *   da posalje Response za odgovarajucu operaciju.
 */
template <typename T>
class Request {
private:
    T _payload;
    QUuid _pendingOpId;

public:
    explicit Request(QUuid pendingOpId, T payload)
        : _pendingOpId(pendingOpId), _payload(std::move(payload)) {}

    const T& payload() const {
        return _payload;
    }

    const QUuid& pendingOpId() const {
        return _pendingOpId;
    }
};
