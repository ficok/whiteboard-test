#include "View.hpp"
#include "PageScene.hpp"

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
