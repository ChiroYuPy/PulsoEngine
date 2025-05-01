//
// Created by adrian on 29/04/25.
//

#include "Graphics/Containers/BeatmapCarrousel.h"

#include <Graphics/Buttons/BeatmapButton.h>
#include <PULSO/Graphics/Containers/BoxContainer.h>

BeatmapCarrousel::BeatmapCarrousel() {
    Drawable::setSize({256, 256});

    auto box = std::make_unique<BoxContainer>();
    box->setSize({128, 512});

    constexpr int size = 8;
    for (int i = 0; i < size; i++) {
        auto button = std::make_unique<BeatmapButton>();
        button->setSize({96, 32});
        button->setAnchor(Anchor::Center);
        box->add(std::move(button));
    }

    add(std::move(box));
}
