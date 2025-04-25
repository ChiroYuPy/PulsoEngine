//
// Created by adrian on 24/04/25.
//

#include "PULSO/Graphics/Containers/BoxContainer.h"

BoxContainer::BoxContainer() {}

void BoxContainer::updateLayout() {
    Vector2 cursor = getPosition(); // point de départ dans le container

    for (auto& child : children) {
        child->setPosition(cursor);

        Vector2 size = child->getSize();
        if (direction == Direction::Horizontal) {
            cursor.x += size.x + spacing;
        } else {
            cursor.y += size.y + spacing;
        }
    }
}