//
// Created by adrian on 29/04/25.
//

#include "Graphics/Containers/BeatmapCarrousel.h"

#include <Graphics/Buttons/BeatmapButton.h>
#include <PULSO/Graphics/Containers/BoxContainer.h>

BeatmapCarrousel::BeatmapCarrousel() {
    constexpr int buttonWidth = 320;
    constexpr int buttonHeight = 64;
    constexpr int spacing = 8;
    constexpr int nbButtons = 32;

    auto boxContainer = std::make_unique<BoxContainer>();
    for (int i = 0; i < nbButtons; i++) {
        auto button = std::make_unique<BeatmapButton>(Color::TransparentRed);
        button->setSize({buttonWidth, buttonHeight});
        button->setAnchor(Anchor::Center);
        boxContainer->add(std::move(button));
    }

    setSize({buttonWidth, 320.f});
    boxContainer->setSize({buttonWidth, (buttonHeight * nbButtons) + spacing * (nbButtons - 1)});
    boxContainer->setSpacing(spacing);
    boxContainer->setDirection(Direction::Vertical);
    add(std::move(boxContainer));
}
