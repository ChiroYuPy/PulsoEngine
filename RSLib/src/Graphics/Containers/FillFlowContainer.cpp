//
// Created by ChiroYuki on 12/04/2025.
//

#include "RS/Graphics/Containers/FillFlowContainer.h"

FillFlowContainer::FillFlowContainer() {

}

void FillFlowContainer::setDirection(Direction newDirection) {
    direction = newDirection;
}

void FillFlowContainer::setSpacing(const float newSpacing) {
    spacing = newSpacing;
}

void FillFlowContainer::update(Time deltaTime) {
    Container::update(deltaTime);
    updateLayout();
}

void FillFlowContainer::updateLayout() {
    if (direction == Direction::None) throw std::runtime_error("direction can't be None, please set a direction with setDirection()");

    Vector2 cursor = {0, 0};
    Vector2 containerSize = getSize();

    float totalSizeDirection = 0.0f;
    for (const auto& child : children) {
        Vector2 size = child->getSize();
        totalSizeDirection += (direction == Direction::Horizontal ? size.x : size.y) + spacing;
    }
    if (!children.empty()) totalSizeDirection -= spacing;

    if (direction == Direction::Horizontal) cursor.x = - totalSizeDirection * 0.5f;
    else cursor.y = - totalSizeDirection * 0.5f;

    for (const auto& child : children) {
        Vector2 size = child->getSize();
        Vector2 pos = {0, 0};

        if (direction == Direction::Horizontal) {
            pos.x = cursor.x + size.x * 0.5f;
            // pos.y = containerSize.y * 0.5f - size.y * 0.5f;
            pos.y = 0.f;
            cursor.x += size.x + spacing;
        } else {
            // pos.x = containerSize.x * 0.5f - size.x * 0.5f;
            pos.x = 0.f;
            pos.y = cursor.y + size.y * 0.5f;
            cursor.y += size.y + spacing;
        }

        child->setPosition(pos);
    }
}

