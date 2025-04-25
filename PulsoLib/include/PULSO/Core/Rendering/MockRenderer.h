//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_MOCKRENDERER_H
#define WMG_MOCKRENDERER_H


#include "IRenderer.h"

class MockRenderer final : public IRenderer {
public:
    explicit MockRenderer();

    void clear() override;
    void clear(unsigned int color) override;

    void drawRect(Vector2& position, float width, float height, unsigned int color) override;
    void drawCircle(Vector2& position, float radius, unsigned int color) override;
    void drawText(Vector2& position, const std::string& text, unsigned int color) override;

    void display() override;
    bool shouldQuit() override;

    void pollEvents() override;

    Vector2 getWindowSize() override;
};


#endif //WMG_MOCKRENDERER_H
