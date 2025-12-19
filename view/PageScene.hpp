#pragma once

#include <QGraphicsScene>
#include <QHash>
#include <QUuid>
#include "PageSize.hpp"

class DrawableItem;
class Operation;
class Response;
class Controller;

class PageScene: public QGraphicsScene {
    Q_OBJECT
private:
    qint32 _pageIdx;
    PageSize _pageSize;
    QHash<QUuid, Operation *> _stash;
    Controller* _controller;

    void initialize();
    void configureScene();

public:
    explicit PageScene(QObject* parent = nullptr);
    explicit PageScene(PageSize pageSize, qint32 pageIdx, QObject* parent = nullptr);
    ~PageScene();

    qint32 pageIdx() const;
    void pageIdx(qint32 id) { _pageIdx = id; }

    void addOperation(Operation* op);

    Controller& controller() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;

public slots:
    void receiveResponse(const Response& response);
};
