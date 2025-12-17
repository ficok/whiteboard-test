#pragma once

#include "DrawableItem.hpp"
#include "DrawableElement.hpp"
#include "StrokeItem.hpp"

class DrawableFactory {
public:
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
