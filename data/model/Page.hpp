#pragma once

#include <QtTypes>
#include <QVector>

class DrawableElement;
/**
 * @brief The Page class
 * model stranice.
 * za sada, cuva samo elemente na stranici. pored ovoga, mozda moze da ima
 * orijentaciju, format, boju...
 * postoji PageSize.hpp u view folderu koji bi mozda mogao da se cuva ovde.
 * ako se to doda, moraju da se izmene i AddPageRequestModel da prenosi to,
 * kao i LocalBackend::addPage
 */
class Page {
private:
    qint32 _id;
    /**
     * @brief _elements
     * da li je bolje da ovo bude QHash? verovatno
     * trenutno nije iz razloga koji sam zaboravio
     */
    QVector<DrawableElement> _elements;

public:
    Page() = default;
    ~Page() = default;

    Page(const Page& other) = delete;
    Page& operator =(const Page& other) = delete;

    qint32 id() const;
    void id(qint32 id);

    qint32 size() const;

    QVector<DrawableElement>& elements();
    void addElement(DrawableElement element);
    // removeElement
    const DrawableElement& operator[](int idx);
};
