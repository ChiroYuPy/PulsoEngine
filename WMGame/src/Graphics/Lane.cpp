//
// Created by ChiroYuki on 11/04/2025.
//

#include "Graphics/Lane.h"

Lane::Lane() {
    setDirection(Direction::Horizontal);
    setAnchor(Anchor::Center);
    setSize({256, 256});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> sizeDist(24.0f, 48.0f);
    std::uniform_int_distribution<int> colorDist(0, 255);

    for (int i = 0; i < 16; i++) {
        float width = sizeDist(gen);
        float height = sizeDist(gen);
        float radius = sizeDist(gen) / 2.f;

        auto box = std::make_shared<Box>();
        box->setSize({width, height});

        int r = colorDist(gen);
        int g = colorDist(gen);
        int b = colorDist(gen);
        int a = 255;

        uint32_t color = (r << 24) | (g << 16) | (b << 8) | a;
        box->setColor(color);

        addChild(box);
    }
}