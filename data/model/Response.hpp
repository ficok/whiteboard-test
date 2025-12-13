#pragma once

#include <utility>
#include "ResponseBase.hpp"

template <typename T>
class Response: public ResponseBase {
private:
    T _payload;

public:
    explicit Response(T payload)
        : _payload(std::move(payload)) {}

    const T& payload() const {
        return _payload;
    }
    void payload(const T& payload) {
        _payload = std::move(payload);
    }
};
