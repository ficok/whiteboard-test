#pragma once

#include <QUuid>

class Response {
private:
    bool _valid = false;
    qint32 _pageIdx;
    QUuid _operationId;

public:
    Response(QUuid operationId, qint32 pageIdx, bool valid)
        : _operationId(operationId), _pageIdx(pageIdx), _valid(valid) {}
    Response(QUuid operationId, bool valid)
        : _operationId(operationId), _valid(valid) {}
    bool valid() const {
        return _valid;
    }
    qint32 pageIdx() const {
        return _pageIdx;
    }
    QUuid operationId() const {
        return _operationId;
    }
};
