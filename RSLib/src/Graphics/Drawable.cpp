//
// Created by ChiroYuki on 07/04/2025.
//

#include "RS/Graphics/Drawable.h"

#include <iostream>

int Drawable::totalCount = 0;

Drawable::Drawable() : relativePosition(0, 0), anchor(Anchor::Center), origin(Anchor::Center), size(1, 1), parent(nullptr), drawInfo() {
    drawInfo = DrawInfo();
    totalCount++;
    // std::cout << "Drawable created (total: " << totalCount << ")" << std::endl;
}

Drawable::~Drawable() {
    totalCount--;
    // std::cout << "Drawable destroyed (total: " << totalCount << ")" << std::endl;
}

void Drawable::setRenderer(IRenderer* newRenderer) {
    renderer = newRenderer;
}

int Drawable::getTotalCount() {
    return totalCount;
}

void Drawable::draw() {

}

void Drawable::update(Time deltaTime) {
    Transformable::update(deltaTime);
    updateTransform();
}

void Drawable::updateTransform() {
    DrawInfo relativeTransform;
    relativeTransform.setPosition(relativePosition);

    if (parent) {
        Vector2 parentSize = parent->getSize();
        if (hasX(relativeSizeAxes)) size.x = parentSize.x;
        if (hasY(relativeSizeAxes)) size.y = parentSize.y;

        drawInfo = relativeTransform + parent->getDrawInfo();
    }
    else drawInfo = relativeTransform;
}

void Drawable::setPosition(const Vector2 &newPosition) {
    relativePosition = newPosition;
}

const Vector2& Drawable::getPosition() const {
    return relativePosition;
}

void Drawable::setAnchor(const Anchor &newAnchor) {
    anchor = newAnchor;
}

const Anchor& Drawable::getAnchor() const {
    return anchor;
}

void Drawable::setParent(Drawable *newParent) {
    parent = newParent;
}

Drawable* Drawable::getParent() const {
    return parent;
}

const DrawInfo& Drawable::getDrawInfo() {
    return drawInfo;
}

void Drawable::setSize(const Vector2 &newSize) {
    size = newSize;
}

const Vector2& Drawable::getSize() const {
    return size;
}

void Drawable::setRelativeSizeAxes(const Axes &newRelativeSizeAxes) {
    relativeSizeAxes = newRelativeSizeAxes;
}

const Axes &Drawable::getRelativeSizeAxes() const {
    return relativeSizeAxes;
}

void Drawable::moveTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept {
    auto animation = std::make_unique<AnimationTransform<Vector2>>(&relativePosition, relativePosition, target, duration, easingFunc);
    addAnimation(std::move(animation));
}
