#pragma once

#include <utility>
#include <QUuid>

template <typename T>
class Request {
private:
    T _payload;

public:
    QUuid id;
    explicit Request(T payload)
        : _payload(std::move(payload)) {}

    const T& payload() const {
        return _payload;
    }
    void payload(const T& item) {
        _payload = std::move(payload);
    }
};
