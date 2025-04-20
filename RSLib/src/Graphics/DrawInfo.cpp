//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/DrawInfo.h"

DrawInfo::DrawInfo() : position(0.0f, 0.0f) {}

void DrawInfo::setPosition(Vector2 newPosition) {
    position = newPosition;
}

const Vector2& DrawInfo::getPosition() const {
    return position;
}

const BoundingBox &DrawInfo::getBoundingBox() const {
    return boundingBox;
}

DrawInfo DrawInfo::operator+(const DrawInfo &other) const {
    DrawInfo transform;
    transform.setPosition(getPosition() + other.getPosition());
    return transform;
}
