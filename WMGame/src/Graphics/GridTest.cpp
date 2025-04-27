//
// Created by ChiroYuki on 12/04/2025.
//

#include "Graphics/GridTest.h"

GridTest::GridTest() : GridContainer(4, 4) {
    setAnchor(Anchor::Center);
    setSize({256, 256});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution sizeDist(24.0f, 48.0f);
    std::uniform_int_distribution colorDist(0, 255);

    for (int i = 0; i < 16; i++) {
        float width = sizeDist(gen);
        float height = sizeDist(gen);
        float radius = sizeDist(gen) / 2.f;

        auto box = std::make_shared<Circle>(radius);

        const int r = colorDist(gen);
        const int g = colorDist(gen);
        const int b = colorDist(gen);
        constexpr int a = 255;

        const Color color(r, g, b, a);
        box->setColor(color);

        add(box);
    }
}