//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Math/BoundingBox.h"

BoundingBox::BoundingBox() : min(0.0f, 0.0f), max(0.0f, 0.0f) {}

BoundingBox::BoundingBox(float minX, float minY, float maxX, float maxY) : min(minX, minY), max(maxX, maxY) {
    if (max.x < min.x or max.y < min.x) throw std::invalid_argument("Invalid BoundingBox: max values are less than min values");
}

Vector2 BoundingBox::getSize() const {
    return {max.x - min.x, max.y - min.y};
}

float BoundingBox::getWidth() const {
    return max.x - min.x;
}

float BoundingBox::getHeight() const {
    return max.y - min.y;
}

void BoundingBox::print() const {
    std::cout << "BoundingBox Min: ";
    min.print();
    std::cout << "Max: ";
    max.print();
    std::cout << std::endl;
}
