//
// Created by ChiroYuki on 14/04/2025.
//

#include "Graphics/BeatmapButton.h"
#include "RS/Graphics/Shapes/Box.h"

BeatmapButton::BeatmapButton() {
    setSize({256, 64});

    auto box = std::make_shared<Box>();
    box->setRelativeSizeAxes(Axes::Both);
    addChild(box);
}