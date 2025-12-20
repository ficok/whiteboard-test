#pragma once

#include "Tool.hpp"
#include "StrokeDraft.hpp"
#include "PageScene.hpp"

class StrokeItem;

class StrokeTool final: public Tool {
private:
    /**
     * @brief _draft
     * Draft objekat: on se menja prilikom rada alatke, zatim
     * azurira Stroke i konvertuje se u DrawableElement sa StrokeData.
     * Tool own-uje draft. mora da ga obrise na kraju rada, ali u release
     * funkciji, ne u destruktoru! tool je ziv dok god je aktivan u menadzeru, tako
     * da mora rucno da se obrise draft.
     */
    StrokeDraft* _draft = nullptr;
    /**
     * @brief _item
     * Item objekat koji se crta. PageScene/Operation mu je owner, ovde je samo
     * da bi move metoda mogla da ga azurira u hodu, radi efikasnog update-ovanja scene.
     */
    StrokeItem* _item = nullptr;
    /**
     * @brief _pendingOpId
     * id operacije koja se dodaje za optimisitcno renderovanje.
     * Tool u press metodi pravi taj id i nadalje se on prosledjuje i operaciji, i
     * Request-u i preko Request-a Document-u.
     */
    QUuid _pendingOpId = QUuid::createUuid();

public:
    ~StrokeTool() override;
    /**
     * @brief onMousePress
     * @param event
     * @param scene
     * 0. napravi pending id
     * 1. napravi draft sa inicijalnim informacijama
     * 2. napravi item od tih informacija
     * 3. napravi operaciju sa pending id i item-om
     * 4. daj je sceni
     */
    void onMousePress(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    /**
     * @brief onMouseMove
     * @param event
     * @param scene
     * 1. azuriraj draft na osnovu podataka iz event-a
     * 2. sync-uj item sa draft podacima
     */
    void onMouseMove(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
    /**
     * @brief onMouseRelease
     * @param event
     * @param scene
     * 1. napravi zahtev za backend
     * 2. posalji ga preko kontrolera
     * 3. oslobodi memoriju draft-a
     */
    void onMouseRelease(
        QGraphicsSceneMouseEvent *event,
        PageScene *scene) override;
};
