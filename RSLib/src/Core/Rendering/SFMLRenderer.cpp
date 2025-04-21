//
// Created by ChiroYuki on 08/04/2025.
//

#include <SFML/Graphics.hpp>
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

void SFMLRenderer::drawRect(DrawInfo& transform, const float width, const float height, const unsigned int color) {
    const Vector2 position = transform.getPosition();
    const Vector2 size = transform.getSize();

    sf::RectangleShape rect({size.x, size.y});

    rect.setPosition(position.x, position.y);
    rect.setOrigin({size.x / 2.0f, size.y / 2.0f});
    rect.setFillColor(sf::Color(color));

    window.draw(rect);
}

void SFMLRenderer::drawCircle(DrawInfo& transform, float radius, const unsigned int color) {
    sf::CircleShape circle(radius);

    const Vector2 position = transform.getPosition();

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
