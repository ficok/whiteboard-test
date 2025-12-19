#include <QPair>
#include "PageScene.hpp"
#include "DrawableItem.hpp"
#include "ToolManager.hpp"
#include "Tool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Operation.hpp"
#include "Document.hpp"

PageScene::PageScene(QObject* parent)
    : QGraphicsScene(parent) {
    initialize();
}
PageScene::PageScene(PageSize pageSize, qint32 pageIdx, QObject* parent)
    : QGraphicsScene(parent), _pageSize(pageSize), _pageIdx(pageIdx) {
    initialize();
}
PageScene::~PageScene() {
    delete _controller;
    disconnect(
        Document::instance(), &Document::sendSceneResponse,
        this, &PageScene::receiveResponse);
}

void PageScene::configureScene() {
    if (_pageSize.infinite) {
        constexpr qreal extent = 1e6;
        setSceneRect(-extent, -extent, extent*2, extent*2);
    }
    else {
        setSceneRect(QRectF(QPointF(0,0), _pageSize.size));
    }
}
void PageScene::initialize() {
    _controller = new Controller();
    connect(
        Document::instance(), &Document::sendSceneResponse,
        this, &PageScene::receiveResponse);
}

qint32 PageScene::pageIdx() const {
    return _pageIdx;
}

void PageScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    auto& tool = ToolManager::instance()->activeTool();
    tool.onMousePress(e, this);
}
void PageScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
    QPointF pos = e->scenePos();

    /* don't allow the cursor to escape page */
    QRectF bounds = this->sceneRect();
    if (pos.x() < bounds.left()) pos.setX(bounds.left());
    if (pos.y() < bounds.top()) pos.setY(bounds.top());
    if (pos.x() > bounds.right()) pos.setX(bounds.right());
    if (pos.y() > bounds.bottom()) pos.setY(bounds.bottom());

    auto& tool = ToolManager::instance()->activeTool();
    tool.onMouseMove(e, this);
}
void PageScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) {
    auto& tool = ToolManager::instance()->activeTool();
    tool.onMouseRelease(e, this);
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
Controller& PageScene::controller() const {
    return *_controller;
}
