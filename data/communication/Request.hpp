#pragma once

#include <utility>
#include <QUuid>

template <typename T>
class Request {
private:
    // might have lifetime issues; must outlive the request
    const T& _payload;
    QUuid _id;

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
