//
// Created by ChiroYuki on 14/04/2025.
//

#include "RS/Graphics/Interactives/Button.h"

bool Button::isHovered() const {
    return hovered;
}

bool Button::isPressed() const {
    return pressed;
}

void Button::onEvent(const Event &event) {
    if (event.type == Event::MouseButtonPressed) {
        pressed = true;
    }

    else if (event.type == Event::MouseButtonReleased) {
        if (isPressed() && isContains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y))) {
            if (onClick) onClick();
        }
        pressed = false;
    };
}

bool Button::isContains(const float x, const float y) {
    const Vector2 originVector = toVector2(origin);
    const float minX = absolutePosition.x - absoluteSize.x * originVector.x;
    const float minY = absolutePosition.y - absoluteSize.y * originVector.y;
    const float maxX = absolutePosition.x + absoluteSize.x * (1 - originVector.x);
    const float maxY = absolutePosition.y + absoluteSize.y * (1 - originVector.y);
    return minX < x < maxX && minY < y < maxY;
}
