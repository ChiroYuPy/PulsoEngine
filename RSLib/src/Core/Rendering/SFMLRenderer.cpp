//
// Created by ChiroYuki on 08/04/2025.
//

#include <SFML/Graphics.hpp>
#include "RS/Core/Rendering/SFMLRenderer.h"
#include "RS/Core/GameBase.h"

SFMLRenderer::SFMLRenderer() : window(sf::VideoMode(800, 600), "WMG") {
    window.setFramerateLimit(60);
}

void SFMLRenderer::clear() {
    window.clear(sf::Color::Black);
}

void SFMLRenderer::clear(unsigned int color) {
    window.clear(sf::Color(color));
}

void SFMLRenderer::drawRect(Vector2& position, const float width, const float height, const unsigned int color) {
    sf::RectangleShape rect({width, height});
    rect.setPosition(position.x, position.y);
    rect.setFillColor(sf::Color(color));
    window.draw(rect);
}

void SFMLRenderer::drawCircle(Vector2& position, float radius, const unsigned int color) {
    sf::CircleShape circle(radius);
    circle.setPosition(position.x, position.y);
    circle.setFillColor(sf::Color(color));
    circle.setOrigin({radius, radius});
    window.draw(circle);
}

void SFMLRenderer::drawText(Vector2& position, const std::string &text, unsigned int color) {

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
