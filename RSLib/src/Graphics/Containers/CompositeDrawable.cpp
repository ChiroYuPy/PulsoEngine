//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Containers/CompositeDrawable.h"

void CompositeDrawable::add(std::shared_ptr<Drawable> drawable) {
    drawable->setParent(this);
    children.push_back(std::move(drawable));
}

void CompositeDrawable::clear() {
    children.clear();
}

void CompositeDrawable::draw() {
    for (const auto& child : children) child->draw();
}

void CompositeDrawable::update(Time deltaTime) {
    Drawable::update(deltaTime);
    for (const auto& child : children) child->update(deltaTime);
}

void CompositeDrawable::setRenderer(IRenderer *newRenderer) {
    Drawable::setRenderer(newRenderer);
    for (const auto& child : children) child->setRenderer(renderer);
}
