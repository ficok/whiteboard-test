#pragma once

#include <QtTypes>
#include <QVector>
#include <QUuid>

class Page;
class ResponseBase;
class DrawableElement;

class Document {
private:
    static Document* _instance;
    Document() = default;
    ~Document();

    Document(const Document& other) = delete;
    Document& operator=(const Document& other) = delete;
    Document(Document&& other) = delete;
    Document& operator =(Document&& other) = delete;

    QVector<Page *> _pages;
public:
    static Document& instance();
    Page& operator[](int idx);
    qint32 size() const;

    void addPage(QUuid requestId, Page* page);
    void addElement(QUuid requestId, qint32 pageIdx, DrawableElement* element);

signals:
    void sendResponse(const ResponseBase& response);
};
