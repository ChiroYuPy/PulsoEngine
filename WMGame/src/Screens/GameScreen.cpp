//
// Created by ChiroYuki on 09/04/2025.
//

#include "Screens/GameScreen.h"

GameScreen::GameScreen(GameContext* context) : Scene(context) {
}

void GameScreen::onEnter() {
    auto lane = std::make_unique<Lane>();
    root->add(std::move(lane));

    auto griTest = std::make_unique<GridTest>();
    root->add(std::move(griTest));

    // auto circle = std::make_unique<Circle>(24);
    // circle->setPosition({0, 100});
    // circle->moveTo({800, 0}, Time::millis(1000), Easing::Linear);
    // root->addChild(std::move(circle));

    // auto box = std::make_unique<Box>(100, 100);
    // box->setPosition({100, 100});
    // box->setColor(0xFF00FFFF);
    // root->addChild(std::move(box));
}

void GameScreen::onExit() {
}

void GameScreen::onUpdate(Time deltaTime) {
}

void GameScreen::onRender() {
}

void GameScreen::onEvent(const Event &event) {
    if (event.type == Event::Closed) {} // ctx->quit();
    else if (event.type == Event::KeyPressed) {
        if (event.key.code == Key::Escape) {} // ctx->quit();
        else if (event.key.code == Key::B) ctx->screenStack->pop();
    };
}
