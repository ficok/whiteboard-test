#include <QPair>
#include "PageScene.hpp"
#include "DrawableItem.hpp"
#include "ToolManager.hpp"
#include "Tool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "Response.hpp"

PageScene::PageScene(qint32 pageIdx)
    : _pageIdx(pageIdx) {}

qint32 PageScene::pageIdx() const {
    return _pageIdx;
}
QVector<DrawableItem *>& PageScene::items() {
    return _items;
}
void PageScene::addItem(DrawableItem *item) {
    _items.append(item);
    addItem(item);
}
void PageScene::removeItem(DrawableItem *item) {
    // kako brisati iz vektora?
    removeItem(item);
}

void PageScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    auto tool = ToolManager::instance()->activeTool();
    if (tool)
        tool->onMousePress(e, this);
    else
        QGraphicsScene::mousePressEvent(e);
}
void PageScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
    auto tool = ToolManager::instance()->activeTool();
    if (tool)
        tool->onMouseMove(e, this);
    else
        QGraphicsScene::mouseMoveEvent(e);
}
void PageScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) {
    auto tool = ToolManager::instance()->activeTool();
    if (tool) {
        auto draft = tool->onMouseRelease(e, this);
        if (!draft) return;

        auto controller = new Controller();
        auto requestModel = QPair<qint32, DrawableItem*>(_pageIdx, draft);
        auto request = Request<QPair<qint32, DrawableItem*>>(requestModel);
        auto response = controller->addElement(request);
        if (response.valid()) {
            addItem(response.payload());
        }
        else {
            removeItem(draft);
        }
    }
    else
        QGraphicsScene::mouseReleaseEvent(e);
}
