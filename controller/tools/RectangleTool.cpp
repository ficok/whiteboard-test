#include "RectangleTool.hpp"
#include "Controller.hpp"
#include "Request.hpp"
#include "AddItemRequestModel.hpp"
#include "AddItemOperation.hpp"
#include "RectangleItem.hpp"

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

    _item = new RectangleItem(_draft->data());
    AddItemOperation* op = new AddItemOperation(_pendingOpId, _item);
    scene->addOperation(op);
}
void RectangleTool::onMouseMove(
    QGraphicsSceneMouseEvent *event,
    PageScene *scene) {
    if (!_draft) return;
    _draft->update(event->pos());
    _item->sync(_draft->data());
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
