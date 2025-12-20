#pragma once

#include "DrawableItem.hpp"
#include "DrawableElement.hpp"
#include "StrokeItem.hpp"
#include "RectangleItem.hpp"

class DrawableFactory {
public:
    /**
     * @brief create
     * @param element
     * @return konkretan DrawableItem*
     *
     * ovo je factory metoda koja ume na osnovu konkretnog DrawableData
     * da napravi odgovarajuc DrawableItem.
     *
     * std::visit je metoda koja ide zajedno sa std::variant.
     * std::variant kod nas je lista mogucih tipova za podatke.
     * mozemo da uporedimo ovo sa enum-om: umesto da smo imali
     * DataTypeEnum { Stroke, Rectangle, ... } i radili
     * if (type == DataTypeEnum.Stroke) { return new StrokeItem }
     * else if (type == DataTypeEnum.Rectangle) { ... }
     * koristimo std::variant umesto enuma, a std::visit je
     * za std::variant ispravan nacin radjenja if-else.
     *
     * [](auto&& data) -> DrawableItem* {} je lambda funkcija
     * (ili anonimna funkcija).
     * ako vas zanimaju detalji ove lambda funkcije (kao ovi
     * std::decay_t, decltype, constexpr itd) objasnite ChatGPT-ju
     * poentu ove funkcije i paste-ujte mu je i trazite da objasni svaki njen deo.
     * bice vam lakse i svakako on zna bolje nego ja + nije toliko bitno za celu arhitekturu.
     *
     * takodje: ovo se za sada nigde ne koristi, ali je ideja da se koristi
     * u PageScene. ako dokument u svom Response bude slao i ceo DrawableElement,
     * u sceni ce pomocu ove funkcije da se od njega napravi konkretan
     * DrawableItem.
     * recimo, undo/redo bi trebalo da se salju iz dokumenta (jer je to operacija koja takodje
     * menja stanje dokumenta). tada, posto sta god da treba da se nacrta ne dolazi iz
     * user input-a, moraju da se posalju svi neophodni podaci za crtanje elementa.
     * tad bi se u response-u poslao DrawableElement i u slot-u scene bi se
     * pozvala ova factory funkcija da napravi drawable item.
     */
    static DrawableItem* create(const DrawableElement& element) {
        return std::visit([](auto&& data) -> DrawableItem* {
            using ElementDataType = std::decay_t<decltype(data)>;

            if constexpr (std::is_same_v<ElementDataType, StrokeData>) {
                return new StrokeItem(data);
            }
            else if constexpr (std::is_save_v<ElementDataType, RectangleData>) {
                return new RectangleItem(data);
            }
            else {
                static_assert(always_false<T>, "Nonexisting DrawableData type");
            }
        }, element.data);
    }

private:
    template <typename>
    static constexpr bool always_false = false;
};
