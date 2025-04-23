//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Containers/Container.h"

Container::Container() : CompositeDrawable() {}

void Container::updateLayout() {
    const Vector2 parentSize = getSize();
    const Vector2 parentOriginPosition = toVector2(origin);

    for (const auto& child : children) {
        Anchor anchor = child->getAnchor();
        const Vector2 anchorPosition = toVector2(anchor);

        if (anchor != Anchor::None) {
            child->setOrigin(anchor);

            child->setPosition({(anchorPosition.x - parentOriginPosition.x) * parentSize.x, (anchorPosition.y - parentOriginPosition.y) * parentSize.y});
        }
    }
}

void Container::update(const Time update) {
    CompositeDrawable::update(update);
    updateLayout();
}
