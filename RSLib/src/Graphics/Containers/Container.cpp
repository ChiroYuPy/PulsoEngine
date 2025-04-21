//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Containers/Container.h"

Container::Container() : CompositeDrawable() {}

void Container::updateLayout() {
    for (const auto& child : children) {
        Anchor anchor = child->getAnchor();
        const Vector2 anchorPosition = toVector2(anchor);
        const Vector2 containerSize = getSize();
        if (anchor != Anchor::None) child->setPosition({containerSize.x * anchorPosition.x, containerSize.y * anchorPosition.y});
    }
}

void Container::update(Time update) {
    CompositeDrawable::update(update);
    updateLayout();
}
