//
// Created by ChiroYuki on 14/04/2025.
//

#include "Graphics/BeatmapButton.h"
#include "RS/Graphics/Shapes/Box.h"

BeatmapButton::BeatmapButton() {
    Drawable::setSize({256, 64});

    const auto box = std::make_shared<Box>();
    box->setRelativeSizeAxes(Axes::Both);
    box->sizeTo({0.1f, 1.0f}, Time::millis(2000), Easing::EaseInOutQuad);
    addChild(box);
}