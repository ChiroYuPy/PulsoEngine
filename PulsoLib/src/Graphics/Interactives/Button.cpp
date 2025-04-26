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

void Button::onEvent(const Event &event) {
    if (event.type == Event::Type::MouseClick) {
        pressed = true;
    }

    else if (event.type == Event::Type::MouseRelease) {
        if (isPressed() && isContains(static_cast<float>(event.mousePos.x), static_cast<float>(event.mousePos.y))) {
            if (onClick) onClick();
            std::cout << "click" << std::endl;
        }
        // std::cout << event.mousePos.x << ", " << event.mousePos.y << std::endl;
        pressed = false;
    }
}

bool Button::isContains(const float x, const float y) {
    const Vector2 min = absolutePosition - Vector2(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);
    const Vector2 max = min + absoluteSize;
    return (min.x < x && x < max.x) && (min.y < y && y < max.y);
}
