//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Core/Scene/Scene.h"
#include "PULSO/Core/GameContext.h"

Scene::Scene(GameContext *context) {
    ctx = context;
    const Vector2 windowSize = ctx->renderer->getWindowSize();

    root = std::make_unique<DebugContainer>();
    root->setSize({windowSize.x, windowSize.y});
    root->setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
    root->setOrigin(Anchor::Center);
    root->setColor(0x202020FF);
}

void Scene::updateRoot() const {
    const Vector2 windowSize = ctx->renderer->getWindowSize();

    root->setSize({windowSize.x, windowSize.y});
    root->setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
}
