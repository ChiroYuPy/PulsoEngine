//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Shapes/Circle.h"

Circle::Circle(const float radius) : radius(radius) {
    relativeSize = {radius * 2.f, radius * 2.f};
}

void Circle::draw() {
    Drawable::draw();
    if (renderer) renderer->drawCircle(absolutePosition, radius, color);
}
