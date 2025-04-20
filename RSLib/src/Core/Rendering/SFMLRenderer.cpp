//
// Created by ChiroYuki on 08/04/2025.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "RS/Core/Rendering/SFMLRenderer.h"
#include "RS/Core/GameBase.h"
#include "RS/Graphics/DrawInfo.h"

SFMLRenderer::SFMLRenderer() : window(sf::VideoMode(800, 600), "WMG") {
    window.setFramerateLimit(60);
}

void SFMLRenderer::clear() {
    window.clear(sf::Color::Black);
}

void SFMLRenderer::clear(unsigned int color) {
    window.clear(sf::Color(color));
}

void SFMLRenderer::drawRect(DrawInfo& transform, float width, float height, unsigned int color) {
    sf::RectangleShape rect({width, height});

    Vector2 position = transform.getPosition();

    rect.setPosition(position.x, position.y);
    rect.setOrigin({width / 2.0f, height / 2.0f});
    rect.setFillColor(sf::Color(color));

    window.draw(rect);
}

void SFMLRenderer::drawCircle(DrawInfo& transform, float radius, unsigned int color) {
    sf::CircleShape circle(radius);

    Vector2 position = transform.getPosition();

    circle.setPosition(position.x, position.y);
    circle.setOrigin({radius, radius});
    circle.setFillColor(sf::Color(color));

    window.draw(circle);
}

void SFMLRenderer::drawText(DrawInfo &transform, const std::string &text, unsigned int color) {

}

void SFMLRenderer::display() {
    window.display();
}

bool SFMLRenderer::shouldQuit() {
    return !window.isOpen();
}

void SFMLRenderer::pollEvents(GameContext* context) {
    sf::Event sfEvent{};
    while (window.pollEvent(sfEvent)) {
        ctx->screenStack->getTop()->onEvent(sfEvent);
    }
}

Vector2 SFMLRenderer::getWindowSize() {
    sf::Vector2u windowSize = window.getSize();
    return {static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)};
}
