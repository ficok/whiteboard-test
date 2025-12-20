#pragma once

#include <QSizeF>
/**
 * @brief The PageSize class
 * daje opcije za format stranice.
 * ovaj infinite je dao ChatGPT i iskreno se bojim da ga probam
 */
struct PageSize {
    QSizeF size;
    bool infinite = false;

    static PageSize A4() {
        return { QSizeF(210., 297.), false };
    }

    static PageSize Infinite() {
        return { QSizeF(0., 0.), true };
    }
};
