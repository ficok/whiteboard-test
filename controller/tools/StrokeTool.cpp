#include "StrokeTool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "AddItemOperation.hpp"

StrokeTool::~StrokeTool() {
    if (_draft != nullptr) delete _draft;
}

void StrokeTool::onMousePress(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    _draft = new StrokeDraft(Qt::black, 2.);
    _draft->update(event->pos());

    DrawableItem* item = _draft->toItem();
    scene->beginOptimisticOperation(
        item, _pendingOpId);
}
void StrokeTool::onMouseMove(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    if (_draft == nullptr) return;

    _draft->update(event->pos());
    scene->updateOptimisticOperation(
        _pendingOpId, *_draft);
}
void StrokeTool::onMouseRelease(
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
