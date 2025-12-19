#pragma once

#include <QtTypes>
#include <QVector>
#include <QUuid>
#include <QObject>
#include <QDebug>

class Page;
class Response;
class DrawableElement;

class Document: public QObject {
    Q_OBJECT
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
    static Document* instance();
    Page& operator[](int idx);
    const Page& operator[](int idx) const;
    qint32 size() const;

    void addPage(QUuid requestId, Page* page);
    void addElement(QUuid requestId, qint32 pageIdx, DrawableElement element);
    void initialize();

signals:
    void sendSceneResponse(const Response& response);
    void sendViewResponse(const Response& response);
};
