#pragma once

#include <QGraphicsScene>
#include <QHash>
#include <QUuid>
#include "PageSize.hpp"

class DrawableItem;
class Operation;
class Response;
class Controller;
/**
 * @brief The PageScene class
 * ovde se radi renderovanje.
 *
 * sadrzi mapu operacija koje su izvrsene ali ih dokument jos nije
 * potvrdio.
 *
 * prosledjuje mouse eventove aktivnoj alatki.
 */
class PageScene: public QGraphicsScene {
    Q_OBJECT
private:
    qint32 _pageIdx;
    /**
     * @brief _pageSize
     * opisuje format stranice
     */
    PageSize _pageSize;
    /**
     * @brief _stash
     * kolekcija koja sadrzi operacije za optimisticno crtanje
     */
    QHash<QUuid, Operation *> _stash;
    /**
     * @brief _controller
     * kontroler vezan za stranicu. PageScene own-uje ovo i mora da ga
     * obrise u destruktoru.
     */
    Controller* _controller;
    /**
     * @brief initialize
     * pravi kontroler (koji destruktor mora da obrise) i
     * povezuje slot sa signalom iz dokumenta (koji destruktor razvezuje)
     */
    void initialize();
    /**
     * @brief configureScene
     * postavlja scene rectangle
     */
    void configureScene();

public:
    explicit PageScene(QObject* parent = nullptr);
    explicit PageScene(PageSize pageSize, qint32 pageIdx, QObject* parent = nullptr);
    ~PageScene();

    qint32 pageIdx() const;
    void pageIdx(qint32 id) { _pageIdx = id; }
    /**
     * @brief addOperation
     * @param op
     * operacija koju aktivan tool napravi.
     * prilikom dodavanja operacije u stash, odmah se radi i commit
     * (to ce da promeni scenu u skladu sa operacijom).
     */
    void addOperation(Operation* op);

    Controller& controller() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;

public slots:
    /**
     * @brief receiveResponse
     * @param response
     * prima signale od dokumenta. ti signali imaju veze sa dodavanjem, menjanjem i brisanjem
     * itema.
     * ukoliko dokument kaze da operacija nije validna, ovde se radi rollback
     * operacije i oslobadjanje njene memorije.
     * ako jeste validna, onda se samo oslobadja njena memorija.
     * ako je opracija sadrzala pokazivac na neki Item, njegova memorija se ne oslobadja.
     * njega sada own-uje scena.
     * verovatno bi bilo dobro da cuvamo kolekciju itema koji su na sceni.
     */
    void receiveResponse(const Response& response);
};
