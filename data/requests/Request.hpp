#pragma once

#include <utility>
#include <QUuid>

template <typename T>
class Request {
private:
    T _payload;
    QUuid id;

public:
    explicit Request(QUuid id, const T& payload)
        : _id(id), _payload(payload) {}

    const T& payload() const {
        return _payload;
    }

    const QUuid& id() const {
        return _id;
    }
};
