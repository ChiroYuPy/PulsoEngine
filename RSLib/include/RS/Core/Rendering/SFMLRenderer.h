//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SFMLRENDERER_H
#define WMG_SFMLRENDERER_H

#include "IRenderer.h"

#include <SFML/Graphics/RenderWindow.hpp>

class SFMLRenderer : public IRenderer {
public:
    explicit SFMLRenderer();

    void clear() override;
    void clear(unsigned int color) override;

    void drawRect(DrawInfo& transform, float width, float height, unsigned int color) override;
    void drawCircle(DrawInfo& transform, float radius, unsigned int color) override;
    void drawText(DrawInfo& transform, const std::string& text, unsigned int color) override;

    void display() override;
    bool shouldQuit() override;

    void pollEvents(GameContext* context) override;

    Vector2 getWindowSize() override;

private:
    sf::RenderWindow window;
};


#endif //WMG_SFMLRENDERER_H
