//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Core/Scene/SceneStack.h"
#include "PULSO/Core/GameContext.h"

void SceneStack::setGameContext(GameContext *gameContext) {
    ctx = gameContext;
}

void SceneStack::push(std::unique_ptr<Scene> scene) {
    if (!isEmpty()) {
        getCurrent()->onExit();
        getCurrent()->clear();
    }
    scenes.push(std::move(scene));
    getCurrent()->onEnter();
    getCurrent()->setRenderer(ctx->renderer);
}

void SceneStack::pop() {
    if (isEmpty()) return;

    getCurrent()->onExit();
    getCurrent()->clear();
    scenes.pop();

    if (!isEmpty()) {
        getCurrent()->onEnter();
        getCurrent()->setRenderer(ctx->renderer);
    }
}

bool SceneStack::isEmpty() const {
    return scenes.empty();
}

void SceneStack::clear() {
    while (!isEmpty()) {
        getCurrent()->onExit();
        getCurrent()->clear();
        scenes.pop();
    }
}

void SceneStack::quit() {
    shouldQuit = true;
}

Scene* SceneStack::getCurrent() {
    return isEmpty() ? nullptr : scenes.top().get();
}

void SceneStack::onEvent(const Event &event) {
    if (isEmpty()) return;
    getCurrent()->onEvent(event);
}

void SceneStack::onUpdate(const Time time) {
    if (isEmpty()) return;
    getCurrent()->onUpdate(time);
}

void SceneStack::onRender() {
    if (isEmpty()) return;
    getCurrent()->onRender();
}
