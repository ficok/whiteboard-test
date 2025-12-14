#pragma once

#include <QUuid>

class ResponseBase {
protected:
    bool _valid = false;
public:
    QUuid id;
    qint32 pageIdx;

    ResponseBase() {}
    ResponseBase(QUuid requestId, bool valid)
        : id(requestId), _valid(valid) {}
    ResponseBase(QUuid id, qint32 pageIdx, bool valid)
        : id(id), pageIdx(pageIdx), _valid(valid) {}

    bool valid() const {
        return _valid;
    }
    void valid(bool value) {
        _valid = value;
    }
};
