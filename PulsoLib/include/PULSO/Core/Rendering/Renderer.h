//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_OPENGLRENDERER_H
#define WMG_OPENGLRENDERER_H

#include <iostream>

#include <PULSO/Core/Event/Event.h>

#include <SFML/Graphics.hpp>


class GameContext;

class Renderer {
public:
    void setGameContext(GameContext *gameContext);

    explicit Renderer();

    void clear();
    void clear(unsigned int color);

    void draw(const sf::Drawable& drawable);

    void display();
    bool shouldQuit() const;

    void quitWindow();

    void pollEvents();

    void setMode(unsigned int width, unsigned int height, const std::string &caption, unsigned int maxFps);

    Vector2 getWindowSize() const;

private:
    unsigned int fbWidth{}, fbHeight{};

    Vector2 mousePos;

    void onWindowResize(int unsigned width, int unsigned height);

    GameContext* ctx = nullptr;

    sf::RenderWindow window;
};


#endif //WMG_OPENGLRENDERER_H
