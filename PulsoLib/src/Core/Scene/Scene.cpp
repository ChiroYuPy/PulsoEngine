//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Core/Scene/Scene.h"
#include "PULSO/Core/GameContext.h"

Scene::Scene(GameContext *context) {
    ctx = context;
    const Vector2 windowSize = ctx->renderer->getWindowSize();

    setSize({windowSize.x, windowSize.y});
    setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
    setOrigin(Anchor::Center);
}

void Scene::onUpdate(Time deltaTime) {
    Container::onUpdate(deltaTime);
    const Vector2 windowSize = ctx->renderer->getWindowSize();

    setSize({windowSize.x, windowSize.y});
    setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
}