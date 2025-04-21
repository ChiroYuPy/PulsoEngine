//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Shapes/Box.h"

Box::Box() {
    size = {1.f, 1.f};
}

void Box::setSize(const Vector2 &newSize) {
    Drawable::setSize(newSize);
}

void Box::draw() {
    Drawable::draw();
    if (renderer) renderer->drawRect(drawInfo, size.x, size.y, color);
}
