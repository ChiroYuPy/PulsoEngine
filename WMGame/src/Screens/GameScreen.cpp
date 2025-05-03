//
// Created by ChiroYuki on 09/04/2025.
//

#include "Screens/GameScreen.h"

GameScreen::GameScreen(GameContext* context) : Scene(context) {
}

void GameScreen::onEnter() {
    auto lane = std::make_unique<Lane>();
    add(std::move(lane));

    auto griTest = std::make_unique<GridTest>();
    add(std::move(griTest));

    auto circle = std::make_unique<Circle>(24);
    circle->setPosition({0, 100});
    circle->moveTo({800, 0}, Time::millis(1000), Easing::Linear);
    add(std::move(circle));

    auto box = std::make_unique<Box>();
    box->setPosition({100, 100});
    box->setSize({100, 100});
    box->setColor(Color(0xFF00FFFF));
    add(std::move(box));
}

void GameScreen::onExit() {
}

void GameScreen::onUpdate(Time deltaTime) {
    Scene::onUpdate(deltaTime);
}

void GameScreen::onRender() {
    Container::onRender();
}

void GameScreen::onEvent(const Event &event) {
    Container::onEvent(event);
    if (event.type == Event::Type::Closed) ctx->renderer->quitWindow();
    else if (event.type == Event::Type::KeyDown) {
        if (event.key.code == Event::Key::Escape) ctx->screenStack->pop();
    }
}
