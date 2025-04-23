//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Shapes/Box.h"

Box::Box() {
    relativeSize = {1.f, 1.f};
}

void Box::setSize(const Vector2 &newSize) {
    Drawable::setSize(newSize);
}

void Box::draw() {
    Drawable::draw();
    Vector2 drawPos = absolutePosition - Vector2(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);

    if (renderer) renderer->drawRect(drawPos, absoluteSize.x, absoluteSize.y, color);
}
