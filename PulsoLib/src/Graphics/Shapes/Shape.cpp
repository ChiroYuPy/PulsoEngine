//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Shapes/Shape.h"

#include <PULSO/Core/Color.h>

Shape::Shape() : color() {}

void Shape::setColor(const Color newColor) {
    color = newColor;
}

Color Shape::getColor() const {
    return color;
}

void Shape::colorTo(const Color &target, Time duration, const std::function<float(float)> &easingFunc) noexcept {
    auto animation = std::make_unique<AnimationTransform<Color>>(&color, color, target, duration, easingFunc);
    addAnimation(std::move(animation));
}