#include "View.hpp"
#include "PageScene.hpp"

View::View(QWidget *parent)
    : QGraphicsView(parent) {}
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
