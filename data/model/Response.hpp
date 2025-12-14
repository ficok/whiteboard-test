#pragma once

#include <utility>
#include "ResponseBase.hpp"

template <typename T>
class Response: public ResponseBase {
private:
    T* _payload;

public:
    explicit Response(T* payload)
        : _payload(payload) {}

    const T& payload() const {
        return *_payload;
    }
    void payload(T* payload) {
        if (_payload != nullptr) {
            delete _payload;
            _payload = nullptr;
        }

        _payload = payload;
    }
};
