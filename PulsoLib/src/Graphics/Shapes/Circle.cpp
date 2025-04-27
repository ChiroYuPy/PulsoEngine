//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Shapes/Circle.h"

Circle::Circle(const float radius) : radius(radius) {
    relativeSize = {radius * 2.f, radius * 2.f};
}

void Circle::draw() {
    Drawable::draw();
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(absolutePosition.x, absolutePosition.y);
    circle.setFillColor(sf::Color(color.toInteger()));
    circle.setOrigin(radius, radius);
    circle.setRotation(rotation.getAngle());
    if (renderer) renderer->draw(circle);
}
