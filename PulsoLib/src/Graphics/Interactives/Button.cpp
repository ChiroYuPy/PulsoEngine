//
// Created by ChiroYuki on 14/04/2025.
//

#include "PULSO/Graphics/Interactives/Button.h"

#include <PULSO/Core/Event/Event.h>

bool Button::isHovered() const {
    return hovered;
}

bool Button::isPressed() const {
    return pressed;
}

void Button::onEvent(const Event& event) {
    switch (event.type) {
        case Event::Type::MousePress:
            if (isContains(event.mousePos.x, event.mousePos.y)) {
                pressed = true;
                onPress();
                if (onClick) onClick();
            }
        break;

        case Event::Type::MouseRelease:
            if (pressed && isContains(event.mousePos.x, event.mousePos.y)) {
                onRelease(); // Lâché sur le bouton
            }
        pressed = false;
        break;

        case Event::Type::MouseMoved:
            if (isContains(event.mousePos.x, event.mousePos.y)) {
                if (!hovered) {
                    hovered = true;
                    onHoverEnter();
                }
            } else {
                if (hovered) {
                    hovered = false;
                    onHoverExit();
                }
            }
        break;

        default:
            break;
    }
}

bool Button::isContains(const float x, const float y) const {
    const Vector2 min = absolutePosition - Vector2(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);
    const Vector2 max = min + absoluteSize;
    return (min.x < x && x < max.x) && (min.y < y && y < max.y);
}