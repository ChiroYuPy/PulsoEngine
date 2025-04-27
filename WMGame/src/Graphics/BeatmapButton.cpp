//
// Created by ChiroYuki on 14/04/2025.
//

#include "Graphics/BeatmapButton.h"

#include <PULSO/Core/Color.h>

BeatmapButton::BeatmapButton() {
    animDuration = Time::millis(128);
    Drawable::setSize({400, 200});

    boxShape = std::make_shared<Box>();
    boxShape->setColor(Color::White);
    boxShape->setRelativeSizeAxes(Axes::Both);
    boxShape->setAnchor(Anchor::Left);
    add(boxShape);
}

void BeatmapButton::onPress() {

}

void BeatmapButton::onRelease() {

}

void BeatmapButton::onHoverEnter() {
    boxShape->sizeTo({0.9f, 0.9f}, animDuration, Easing::EaseOutSine);
    boxShape->colorTo(Color(0x00FF00FF), animDuration, Easing::EaseInOutSine);
}

void BeatmapButton::onHoverExit() {
    boxShape->sizeTo({1.0f, 1.0f}, animDuration, Easing::EaseInOutQuad);
    boxShape->colorTo(Color(0xFFFFFFFF), animDuration, Easing::EaseInOutSine);
}