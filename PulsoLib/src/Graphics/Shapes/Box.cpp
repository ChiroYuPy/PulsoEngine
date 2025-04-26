//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Shapes/Box.h"

Box::Box() {
    relativeSize = {1.f, 1.f};
}

void Box::setSize(const Vector2 &newSize) {
    Drawable::setSize(newSize);
}

void Box::draw() {
    Drawable::draw();
    sf::RectangleShape box;
    box.setSize({absoluteSize.x, absoluteSize.y});
    box.setPosition(absolutePosition.x, absolutePosition.y);
    box.setFillColor(sf::Color(color));
    box.setOrigin(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);
    box.setRotation(rotation.getAngle());
    if (renderer) renderer->draw(box);
}
