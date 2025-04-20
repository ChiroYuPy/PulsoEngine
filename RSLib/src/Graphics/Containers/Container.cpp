//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Containers/Container.h"

Container::Container() : CompositeDrawable() {}

void Container::updateLayout() {
    for (const auto& child : children) {
        Vector2 anchor = toVector2(child->getAnchor());
        Vector2 containerSize = getSize();
        child->setPosition({containerSize.x * anchor.x, containerSize.y * anchor.y});
    }
}

void Container::update(Time update) {
    CompositeDrawable::update(update);
    updateLayout();
}
