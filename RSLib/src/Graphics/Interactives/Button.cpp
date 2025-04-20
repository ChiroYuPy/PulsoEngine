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

bool Button::isContains(float x, float y) {
    Vector2 position = getPosition();
    Vector2 originVector = toVector2(origin);
    float minX = position.x - size.x * originVector.x;
    float minY = position.y - size.y * originVector.y;
    float maxX = position.x + size.x * (1 - originVector.x);
    float maxY = position.y + size.y * (1 - originVector.y);
    return (minX < x < maxX) && (minY < y < maxY);
}
