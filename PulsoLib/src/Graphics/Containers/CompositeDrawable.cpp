//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Containers/CompositeDrawable.h"

void CompositeDrawable::add(std::shared_ptr<Drawable> drawable) {
    drawable->setParent(this);
    children.push_back(std::move(drawable));
}

void CompositeDrawable::clear() {
    children.clear();
}

unsigned int CompositeDrawable::size() const {
    return children.size();
}

void CompositeDrawable::onRender() {
    Drawable::onRender();
    for (const auto& child : children) {
        child->onRender();
    }
}

void CompositeDrawable::onUpdate(Time deltaTime) {
    Drawable::onUpdate(deltaTime);
    for (const auto& child : children) child->onUpdate(deltaTime);
}

void CompositeDrawable::onEvent(const Event& event) {
    Drawable::onEvent(event);
    for (const auto& child : children) child->onEvent(event);
}

void CompositeDrawable::setRenderer(Renderer *newRenderer) {
    Drawable::setRenderer(newRenderer);
    for (const auto& child : children) child->setRenderer(renderer);
}
