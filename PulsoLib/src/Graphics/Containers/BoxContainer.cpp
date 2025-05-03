//
// Created by adrian on 24/04/25.
//

#include "PULSO/Graphics/Containers/BoxContainer.h"

BoxContainer::BoxContainer() {}

void BoxContainer::updateLayout() {
    Vector2 cursor;

    float totalSize = (static_cast<float>(children.size()) - 1) * spacing;
    if (direction == Direction::Horizontal) {
        for (auto& child : children) totalSize += child->getSize().x;
        totalSize -= children.front()->getSize().x;
        cursor.x -= totalSize / 2;
    }
    else {
        for (auto& child : children) totalSize += child->getSize().y;
        totalSize -= children.front()->getSize().y;
        cursor.y -= totalSize / 2;
    }

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