#pragma once

#include <QGraphicsScene>
#include <QHash>
#include <QUuid>

class DrawableItem;
class Operation;
class Response;

class PageScene: public QGraphicsScene {
    Q_OBJECT
private:
    qint32 _pageIdx;
    QHash<QUuid, Operation *> _stash;

public:
    PageScene(QObject* parent = nullptr);
    PageScene(qint32 pageIdx, QObject* parent = nullptr);
    ~PageScene() = default;

    qint32 pageIdx() const;
    void pageIdx(qint32 id) { _pageIdx = id; }

    void addOperation(Operation* op);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;

public slots:
    void receiveResponse(const Response& response);
};
