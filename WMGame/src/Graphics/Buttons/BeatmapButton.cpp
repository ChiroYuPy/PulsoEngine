//
// Created by ChiroYuki on 14/04/2025.
//

#include "Graphics/Buttons/BeatmapButton.h"

#include <PULSO/Core/Color.h>

BeatmapButton::BeatmapButton(Color color) {
    hoverColor = color;

    animDuration = Time::millis(100);
    Drawable::setSize({128, 64});

    boxShape = std::make_shared<Box>();
    boxShape->setColor(Color::TransparentWhite);
    boxShape->setRelativeSizeAxes(Axes::Both);
    boxShape->setAnchor(Anchor::Center);
    add(boxShape);
}

void BeatmapButton::onPress() {
    boxShape->colorTo(Color::TransparentCyan, animDuration, Easing::EaseInOutExpo);
}

void BeatmapButton::onRelease() {
    boxShape->colorTo(hoverColor, animDuration, Easing::EaseInOutExpo);
}

void BeatmapButton::onHoverEnter() {
    boxShape->sizeTo({0.9f, 0.9f}, animDuration, Easing::EaseInOutExpo);
    boxShape->colorTo(hoverColor, animDuration, Easing::EaseInOutExpo);
}

void BeatmapButton::onHoverExit() {
    boxShape->sizeTo({1.0f, 1.0f}, animDuration, Easing::EaseInOutSine);
    boxShape->colorTo(Color::TransparentWhite, animDuration, Easing::EaseInOutExpo);
}