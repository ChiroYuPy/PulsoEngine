//
// Created by ChiroYuki on 11/04/2025.
//

#include "Graphics/Lane.h"

Lane::Lane() {
    setDirection(Direction::Horizontal);
    Drawable::setAnchor(Anchor::Center);
    Drawable::setSize({256, 256});

    std::random_device rd;
    std::mt19937 gen(0 /* rd() */);
    std::uniform_real_distribution sizeDist(24.0f, 48.0f);
    std::uniform_int_distribution colorDist(0, 255);

    for (int i = 0; i < 16; i++) {
        float width = sizeDist(gen);
        float height = sizeDist(gen);

        auto box = std::make_shared<Box>();
        box->setSize({width, height});

        const int r = colorDist(gen);
        const int g = colorDist(gen);
        const int b = colorDist(gen);
        const int a = 255;

        const uint32_t color = (r << 24) | (g << 16) | (b << 8) | a;
        box->setColor(color);

        addChild(box);
    }
}