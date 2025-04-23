//
// Created by ChiroYuki on 07/04/2025.
//

#include "RS/Graphics/Drawable.h"

Drawable::Drawable() : relativePosition(0, 0), relativeSize(1.f, 1.f) {
    Drawable::setOrigin(Anchor::Center);
}

Drawable::~Drawable() {

}

void Drawable::setRenderer(IRenderer* newRenderer) {
    renderer = newRenderer;
}

void Drawable::draw() {

}

void Drawable::update(Time deltaTime) {
    Transformable::update(deltaTime);
    updateTransform();
}

void Drawable::updateTransform() {
    std::cout << originVector.x << " " << originVector.y << std::endl;

    absolutePosition = relativePosition;

    absoluteSize = relativeSize;

    if (parent) {
        absolutePosition += parent->getAbsolutePosition();
        const Vector2 parentSize = parent->getSize(); // parent size

        // size or relativeSizeAxes processing
        if (hasX(relativeSizeAxes)) absoluteSize.x = parentSize.x * relativeSize.x;
        if (hasY(relativeSizeAxes)) absoluteSize.y = parentSize.y * relativeSize.y;
    }
}

void Drawable::setPosition(const Vector2 &newPosition) {
    relativePosition = newPosition;
}

const Vector2& Drawable::getPosition() const {
    return relativePosition;
}

const Vector2& Drawable::getAbsolutePosition() const {
    return absolutePosition;
}

void Drawable::setSize(const Vector2 &newSize) {
    relativeSize = newSize;
}

const Vector2& Drawable::getSize() const {
    return relativeSize;
}

const Vector2& Drawable::getAbsoluteSize() const {
    return absoluteSize;
}

void Drawable::setOrigin(const Anchor &newOrigin) {
    origin = newOrigin;
    originVector = toVector2(origin);
}

const Anchor& Drawable::getOrigin() const {
    return anchor;
}

void Drawable::setAnchor(const Anchor &newAnchor) {
    anchor = newAnchor;
    anchorVector = toVector2(anchor);
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

void Drawable::sizeTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept {
    auto animation = std::make_unique<AnimationTransform<Vector2>>(&relativeSize, relativeSize, target, duration, easingFunc);
    addAnimation(std::move(animation));
}