#pragma once

#include <QGraphicsScene>
#include <QHash>
#include <QUuid>

class DrawableItem;
class Operation;
class ResponseBase;

class PageScene: public QGraphicsScene, public QObject {
    Q_OBJECT
private:
    qint32 _pageIdx;
    QHash<QUuid, Operation *> _stash;

public:
    PageScene(QObject* parent = nullptr);
    PageScene(qint32 pageIdx, QObject* parent = nullptr);
    ~PageScene() = default;

    qint32 pageIdx() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;

public slots:
    void receiveResponse(const ResponseBase& response);
};
