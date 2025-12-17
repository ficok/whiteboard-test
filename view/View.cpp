#include "View.hpp"
#include "PageScene.hpp"

View::View(QWidget *parent)
    : QGraphicsView(parent) {
    // Enable mouse tracking so scene receives mouse move events even if no button is pressed
    setMouseTracking(true);

    // Optional: nicer rendering
    setRenderHint(QPainter::Antialiasing);
}
View::~View() {
    for (int i = 0; i < _pageScenes.size(); ++i)
        delete _pageScenes[i];
}

qint32 View::currentPageIdx() const {
    return _currentPageIdx;
}
void View::currentPageIdx(qint32 pageIdx) {
    _currentPageIdx = pageIdx;
    setScene(_pageScenes[_currentPageIdx]);
}
void View::nextPage() {
    if (_currentPageIdx + 1 < _pageScenes.size())
        setScene(_pageScenes[++_currentPageIdx]);
}
void View::previousPage() {
    if (_currentPageIdx - 1 >= 0)
        setScene(_pageScenes[--_currentPageIdx]);
}
// void View::mousePressEvent(QMouseEvent* event) {
//     if (scene()) {
//         QGraphicsSceneMouseEvent e(QEvent::GraphicsSceneMousePress);
//         e.setScenePos(mapToScene(event->pos()));
//         e.setButton(event->button());
//         e.setButtons(event->buttons());
//         e.setModifiers(event->modifiers());
//         scene()->mousePressEvent(&e);
//     }
// }
// void View::mouseMoveEvent(QMouseEvent* event) {
//     if (scene()) {
//         QGraphicsSceneMouseEvent e(QEvent::GraphicsSceneMouseMove);
//         e.setScenePos(mapToScene(event->pos()));
//         e.setButton(event->button());
//         e.setButtons(event->buttons());
//         e.setModifiers(event->modifiers());
//         scene()->mousePressEvent(&e);
//     }
// }
// void View::mouseReleaseEvent(QMouseEvent* event) {
//     if (scene()) {
//         QGraphicsSceneMouseEvent e(QEvent::GraphicsSceneMouseRelease);
//         e.setScenePos(mapToScene(event->pos()));
//         e.setButton(event->button());
//         e.setButtons(event->buttons());
//         e.setModifiers(event->modifiers());
//         scene()->mousePressEvent(&e);
//     }
// }
