#pragma once

class ResponseBase {
protected:
    bool _valid = false;
public:
    ResponseBase() {}
    ResponseBase(bool valid)
        : _valid(valid) {}

    bool valid() const {
        return _valid;
    }
    void valid(bool value) {
        _valid = value;
    }
};
