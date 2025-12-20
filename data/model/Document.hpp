#pragma once

#include <QtTypes>
#include <QVector>
#include <QUuid>
#include <QObject>
#include <QDebug>

class Page;
class Response;
class DrawableElement;
/**
 * @brief The Document class
 * cuva istinsko stanje dokumenta preko liste stranica.
 * singleton, radi univerzalnog pristupa i osiguranja da se uvek pristupa
 * istim podacima.
 * osim cuvanja stanja, nakon azuriranja salje odgovarajuc
 * signal da obavesti UI o uspehu operacije.
 * signal prenosi Response objekat koji sadrzi QUuid operacije i info
 * o validnosti operacije. ako operacija nije bila validna (nije se izvrsila
 * ispravno/uopste), UI mora da obrise te izmene - u suprotnom ne bi odrazavao
 * pravo stanje dokumenta.
 *
 * Document mora da nudi metode za menjanje stanja (add element, add page,
 * edit element, remove element itd).
 * ovde metode treba da urade tacno dve stvari:
 * 1. da sacuvaju podatke koje dobiju, bez bilo kakvog drugog izracunavanja
 * 2. da posalju odgovarajuc signal u UI
 *
 * ako postoji potrebe za nekim izracunavanjem pre nego sto se item sacuva, to se
 * radi u odgovarajucoj Backend klasi.
 */
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
    /**
     * @brief initialize
     * radi inicijalizaciju dokumenta: dodaje prvu stranicu.
     * ovo je dodato kad sam resavao onaj problem koji sam imao i mozda nije
     * idealno resenje ovako "rucno" inicijalizovati. ako neko ima
     * bolju ideju, nek kaze
     */
    void initialize();

signals:
    /**
     * @brief sendSceneResponse
     * @param response
     * salje odgovor sceni. povezivanje/razvezivanje se radi u konstruktoru/destruktoru
     * scene.
     * koristi se za promene vezane za elemente (dodavanje, menjanje, brisanje...)
     */
    void sendSceneResponse(const Response& response);
    /**
     * @brief sendViewResponse
     * @param response
     * salje odgovor pogledu. povezivanje/razvezivanje se radi u konstruktoru/destruktoru
     * pogleda.
     * koristi se za promene vezane za stranice (dodavanje, brisanje, menjanje orijentacije
     * i sta god dodamo za stranice)
     */
    void sendViewResponse(const Response& response);
};
