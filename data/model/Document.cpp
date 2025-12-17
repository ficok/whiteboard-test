#include "Document.hpp"
#include "Page.hpp"
#include "DrawableElement.hpp"
#include "Response.hpp"

Document* Document::_instance = nullptr;

Document::~Document() {
    for (int i = 0; i < _pages.size(); ++i)
        delete _pages[i];
}

Document* Document::instance() {
    if (_instance == nullptr)
        _instance = new Document();
    return _instance;
}

Page& Document::operator [](int idx) {
    return *_pages[idx];
}
qint32 Document::size() const {
    return _pages.size();
}
void Document::addElement(QUuid requestId, qint32 pageIdx, DrawableElement element) {
    _pages[pageIdx]->addElement(element);
    Response response(requestId, pageIdx, true);
    emit sendResponse(response);
}
void Document::addPage(QUuid requestId, Page* page) {
    _pages.push_back(page);
    Response response(requestId, true);
    emit sendResponse(response);
}
