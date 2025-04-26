//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Containers/Container.h"

Container::Container() : CompositeDrawable() {}

void Container::updateLayout() {
    const Vector2 parentSize   = getSize();
    const Vector2 parentOrigin = getOriginVector();

    for (const auto& child : children) {
        const Anchor ca = child->getAnchor();
        const Vector2 cap = child->getAnchorVector();
        if (ca != Anchor::None) {
            const Vector2 childSize   = child->getSize();
            const Vector2 childOrigin = child->getOriginVector();

            Vector2 anchorPosition = {
                (cap.x - parentOrigin.x) * parentSize.x,
                (cap.y - parentOrigin.y) * parentSize.y
            };

            Vector2 originOffset = {
                (cap.x - childOrigin.x) * childSize.x,
                (cap.y - childOrigin.y) * childSize.y
            };

            child->setPosition(anchorPosition - originOffset);
        }
    }
}

void Container::update(const Time update) {
    CompositeDrawable::update(update);
    updateLayout();
}


/*
void Container::updateLayout() {
    const Vector2 parentSize = getSize();
    const Vector2 parentOrigin = getOriginVector();

    for (const auto& child : children) {
        const Vector2 anchorPosition = child->getAnchorVector();

        if (anchor != Anchor::None) {
            const Vector2 childSize = getSize();

            const Vector2 originPosition = child->getOriginVector();

            child->setPosition({
                (anchorPosition.x - parentOrigin.x) * parentSize.x + originPosition.x * childSize.x,
                (anchorPosition.y - parentOrigin.y) * parentSize.y + originPosition.y * childSize.y
            });

            child->setOrigin(anchor);
        }
    }
}
*/