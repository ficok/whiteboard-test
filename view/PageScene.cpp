#include <QPair>
#include "PageScene.hpp"
#include "DrawableItem.hpp"
#include "ToolManager.hpp"
#include "Tool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Operation.hpp"

PageScene::PageScene(QObject* parent)
    : QGraphicsScene(parent) {}
PageScene::PageScene(qint32 pageIdx, QObject* parent)
    : QGraphicsScene(parent), _pageIdx(pageIdx) {}

qint32 PageScene::pageIdx() const {
    return _pageIdx;
}

void PageScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    auto& tool = ToolManager::instance()->activeTool();
    tool.onMousePress(e, this);
}
void PageScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
    auto& tool = ToolManager::instance()->activeTool();
    tool.onMouseMove(e, this);
}
void PageScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) {
    auto& tool = ToolManager::instance()->activeTool();
    Controller controller;
    tool.onMouseRelease(e, this, controller);
}

void PageScene::addOperation(Operation* op) {
    _stash.insert(op->id, op);
    op->commit(this);
}

void PageScene::receiveResponse(const Response& response) {
    if (response.pageIdx() != _pageIdx)
        return;

    Operation* operation = _stash[response.operationId()];
    if (!response.valid())
        operation->rollback(this);

    delete _stash[response.operationId()];
    _stash.remove(response.operationId());
}
