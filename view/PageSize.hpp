#pragma once

#include <QSizeF>

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
