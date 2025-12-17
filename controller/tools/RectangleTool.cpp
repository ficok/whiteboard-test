#include "RectangleTool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "AddItemRequestModel.hpp"

RectangleTool::~RectangleTool() {
    if (_draft != nullptr) delete _draft;
}

void RectangleTool::onMousePress(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    _draft = new RectangleDraft(
        Qt::black,
        Qt::transparent,
        2.0);

    _draft->begin(event->pos());

    DrawableItem* item = _draft->toItem();
    scene->beginOptimisticOperation(
        item,
        _pendingOpId);
}
void RectangleTool::onMouseMove(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    if (!_draft) return;

    _draft->update(event->pos());
    scene->updateOptimisticOperation(
        _pendingOpId,
        *_draft);
}
void RectangleTool::onMouseRelease(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene,
    Controller &controller) {
    if (_draft) return;

    AddItemRequestModel requestModel(scene->pageIdx(), _draft->toElement());
    Request<AddItemRequestModel> request(_pendingOpId, requestModel);
    controller.addElement(request);

    delete _draft;
    _draft = nullptr;
}
