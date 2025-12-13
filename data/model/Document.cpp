#include "Document.hpp"
#include "Page.hpp"

Document* Document::_instance = nullptr;

Document* Document::instance() {
    if (_instance == nullptr)
        _instance = new Document();

    return _instance;
}

Document::Document() {}
Document::~Document() {}

QVector<Page *>& Document::pages() {
    return _pages;
}
Page* Document::operator [](int idx) {
    return _pages[idx];
}
qint32 Document::size() const {
    return _pages.size();
}
void Document::addPage(Page *page) {
    _pages.push_back(page);
}
