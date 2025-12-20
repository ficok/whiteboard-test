#include "StrokeTool.hpp"
#include "StrokeItem.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "AddItemOperation.hpp"
#include "AddItemRequestModel.hpp"

StrokeTool::~StrokeTool() {
    if (_draft != nullptr) delete _draft;
}

void StrokeTool::onMousePress(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    _draft = new StrokeDraft(Qt::black, 2.);
    _draft->update(event->scenePos());

    _item = new StrokeItem(_draft->data());
    AddItemOperation* op = new AddItemOperation(_pendingOpId, scene->pageIdx(), _item);
    scene->addOperation(op);
}
void StrokeTool::onMouseMove(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    if (!_draft) return;

    _draft->update(event->scenePos());
    this->_item->sync(_draft->data());
}
void StrokeTool::onMouseRelease(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    if (!_draft) return;

    AddItemRequestModel requestModel(scene->pageIdx(), _draft->toElement());
    Request<AddItemRequestModel> request(_pendingOpId, requestModel);
    scene->controller().addElement(request);

    delete _draft;
    _draft = nullptr;
}
