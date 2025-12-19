#include "View.hpp"
#include "PageScene.hpp"
#include "Document.hpp"

View::View(QWidget *parent)
    : QGraphicsView(parent), _currentPageIdx(0) {
    PageScene* scene = new PageScene(PageSize::A4(), _currentPageIdx, this);
    _pageScenes.push_back(scene);
    setScene(scene);
    refitScene();

    connect(
        Document::instance(), &Document::sendViewResponse,
        this, &View::receiveResponse);

    setDragMode(QGraphicsView::NoDrag);
    setMouseTracking(true);
    setRenderHint(QPainter::Antialiasing);
    setRenderHint(QPainter::Antialiasing);
    setAlignment(Qt::AlignCenter);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorViewCenter);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::NoDrag);
}
View::~View() {
    disconnect(
        Document::instance(), &Document::sendViewResponse,
        this, &View::receiveResponse);

    for (int i = 0; i < _pageScenes.size(); ++i)
        delete _pageScenes[i];
}

qint32 View::currentPageIdx() const {
    return _currentPageIdx;
}
void View::currentPageIdx(qint32 pageIdx) {
    _currentPageIdx = pageIdx;
    setScene(_pageScenes[_currentPageIdx]);
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}
void View::nextPage() {
    if (_currentPageIdx + 1 < _pageScenes.size()) {
        setScene(_pageScenes[++_currentPageIdx]);
        fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
    }
}
void View::previousPage() {
    if (_currentPageIdx - 1 >= 0) {
        setScene(_pageScenes[--_currentPageIdx]);
        fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
    }
}
void View::receiveResponse(const Response& response) {

}
void View::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);
    refitScene();
}
void View::refitScene() {
    if (scene()) fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}
