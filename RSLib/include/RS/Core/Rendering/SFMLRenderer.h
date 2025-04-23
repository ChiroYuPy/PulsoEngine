//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SFMLRENDERER_H
#define WMG_SFMLRENDERER_H

#include "IRenderer.h"

#include <SFML/Graphics/RenderWindow.hpp>

class SFMLRenderer final : public IRenderer {
public:
    explicit SFMLRenderer();

    void clear() override;
    void clear(unsigned int color) override;

    void drawRect(Vector2& position, float width, float height, unsigned int color) override;
    void drawCircle(Vector2& position, float radius, unsigned int color) override;
    void drawText(Vector2& position, const std::string& text, unsigned int color) override;

    void display() override;
    bool shouldQuit() override;

    void pollEvents(GameContext* context) override;

    Vector2 getWindowSize() override;

private:
    sf::RenderWindow window;
};


#endif //WMG_SFMLRENDERER_H
