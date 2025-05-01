//
// Created by ChiroYuki on 10/04/2025.
//

#include "PULSO/Core/Rendering/Renderer.h"

#include <PULSO/Core/Event/EventManager.h>

void Renderer::setGameContext(GameContext *gameContext) {
    ctx = gameContext;
}

Renderer::Renderer() {
    fbWidth = 800;
    fbHeight = 600;
    window.create(sf::VideoMode(fbWidth, fbHeight), "Rhythm Game");
    window.setFramerateLimit(165);
}

void Renderer::onWindowResize(const unsigned int width, const unsigned int height) {
    fbWidth  = width;
    fbHeight = height;

    sf::View view = window.getView();
    view.setSize(static_cast<float>(width), static_cast<float>(height));
    view.setCenter(static_cast<float>(width) / 2.f, static_cast<float>(height) / 2.f);
    window.setView(view);
}

void Renderer::draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

void Renderer::clear() {
    window.clear(sf::Color::Black);
}

void Renderer::clear(const unsigned int color) {
    window.clear(sf::Color(color));
}

void Renderer::display() {
    window.display();
}

bool Renderer::shouldQuit() const {
    return !window.isOpen();
}

void Renderer::quitWindow() {
    window.close();
}

void Renderer::pollEvents() {
    sf::Event sfmlEvent{};

    while (window.pollEvent(sfmlEvent)) {
        auto event = Event();
        const sf::Vector2 sfmlMousePos = sf::Mouse::getPosition(window);
        mousePos = { static_cast<float>(sfmlMousePos.x), static_cast<float>(sfmlMousePos.y) };
        event.mousePos = { mousePos.x, mousePos.y };

        switch (sfmlEvent.type) {
            case sf::Event::Closed:
                event.type = Event::Type::Closed;
            break;
            case sf::Event::KeyPressed:
                event.type = Event::Type::KeyDown;
                event.key.code = sfmlEvent.key.code;
                event.key.shift = sfmlEvent.key.shift;
                event.key.alt = sfmlEvent.key.alt;
                std::cout << event.key.code << std::endl;
            break;
            case sf::Event::KeyReleased:
                event.type = Event::Type::KeyUp;
                event.key.code = sfmlEvent.key.code;
                event.key.shift = sfmlEvent.key.shift;
                event.key.alt = sfmlEvent.key.alt;
            break;
            case sf::Event::MouseButtonPressed:
                event.type = Event::Type::MousePress;
                event.button.code = sfmlEvent.mouseButton.button;
            break;
            case sf::Event::MouseButtonReleased:
                event.type = Event::Type::MouseRelease;
                event.button.code = sfmlEvent.mouseButton.button;
            break;
            case sf::Event::MouseMoved:
                event.type = Event::Type::MouseMoved;
            break;
            case sf::Event::MouseWheelScrolled:
                event.type = Event::Type::MouseScroll;
                event.scroll.horizontal = sfmlEvent.mouseWheelScroll.x;
                event.scroll.vertical = sfmlEvent.mouseWheelScroll.y;
                event.scroll.delta = sfmlEvent.mouseWheelScroll.delta;
            break;
            case sf::Event::Resized:
                event.type = Event::Type::Resized;
                onWindowResize(sfmlEvent.size.width, sfmlEvent.size.height);
            break;
            default:
                event.type = Event::Type::Unknown;
            break;
        }

    if (ctx && ctx->eventDispacher && event.type != Event::Type::Unknown)
        ctx->eventDispacher->addEvent(event);
    }
}

void Renderer::setMode(const unsigned int width, const unsigned int height, const std::string& caption, const unsigned int maxFps) {
    fbWidth = width;
    fbHeight = height;
    window.setSize({width, height});
    window.setTitle(caption);
    window.setFramerateLimit(maxFps);
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition({static_cast<int>(desktop.width / 2 - width / 2), static_cast<int>(desktop.height / 2 - height / 2)});
}

Vector2 Renderer::getWindowSize() const {
    return { static_cast<float>(fbWidth), static_cast<float>(fbHeight) };
}

