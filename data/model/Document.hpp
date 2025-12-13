#pragma once

#include <QtTypes>
#include <QVector>

class Page;

class Document {
private:
    static Document *_instance;
    Document();
    ~Document();

    Document(const Document& other) = delete;
    Document &operator=(const Document& other) = delete;

    QVector<Page *> _pages;
public:
    static Document* instance();

    QVector<Page *>& pages();
    Page* operator[](int idx);
    qint32 size() const;

    void addPage(Page *page);
};
