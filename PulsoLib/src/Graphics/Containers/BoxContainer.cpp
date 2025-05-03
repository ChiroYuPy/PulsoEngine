//
// Created by adrian on 24/04/25.
//

#include "PULSO/Graphics/Containers/BoxContainer.h"

BoxContainer::BoxContainer() {}

void BoxContainer::updateLayout() {
    Vector2 totalSize;
    for (auto& child : children) totalSize += child->getSize();

    std::cout << totalSize.x << std::endl;
    Vector2 cursor;

    if (direction == Direction::Horizontal) cursor.x -= totalSize.x / 2;
    else cursor.y -= totalSize.y / 2;

    for (auto& child : children) {
        child->setPosition(cursor);
        Vector2 size = child->getSize();
        if (direction == Direction::Horizontal) cursor.x += size.x + static_cast<float>(spacing);
        else cursor.y += size.y + static_cast<float>(spacing);
    }
}

void BoxContainer::setDirection(Direction newDirection) {
    direction = newDirection;
}

void BoxContainer::setSpacing(int newSpacing) {
    spacing = newSpacing;
}