#pragma once

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include "Response.hpp"

class PageScene;
/**
 * @brief The View class
 * sadrzi sve stranice koje trenutno postoje i bavi se viewport-om.
 * ovde se radi dodavanje, menjanje stranica, dodavanje podesavanja bitnih za
 * renderovanje i postavljanje scene u view.
 *
 * predstavlja widget koji sadrzi papir po kom se crta.
 */
class View: public QGraphicsView {
    Q_OBJECT
private:
    qint32 _currentPageIdx;
    /**
     * @brief refitScene
     * helper funkcija koja po potrebni postavlja scenu u view widget
     */
    void refitScene();

public:
    /**
     * @brief _pageScenes
     * ne znam da li treba da bude vektor, ali lista scena treba da postoji svakako.
     * u brzini sam stavio ovde, treba da bude privatna sa get metodom.
     */
    QVector<PageScene *> _pageScenes;
    explicit View(QWidget* parent = nullptr);
    ~View();

    qint32 currentPageIdx() const;
    /**
     * @brief currentPageIdx
     * @param pageIdx
     * postavlja indeks trenutne stranice i radi refitScene
     */
    void currentPageIdx(qint32 pageIdx);
    PageScene* currentPageScene() const;
    void nextPage();
    void previousPage();

protected:
    /**
     * @brief resizeEvent
     * @param event
     * prosledjuje ovo glavnoj resizeEvent metodi i radi refitScene
     */
    void resizeEvent(QResizeEvent* event) override;

public slots:
    /**
     * @brief receiveResponse
     * @param response
     * ovde ce view da prima signale od Document-a.
     * ovo ce imati veze sa dodavanjem, brisanjem i menjanjem stranica.
     */
    void receiveResponse(const Response& response);
};
