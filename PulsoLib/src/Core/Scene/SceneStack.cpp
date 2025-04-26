//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Core/Scene/SceneStack.h"
#include "PULSO/Core/GameContext.h"

void SceneStack::setGameContext(GameContext *gameContext) {
    ctx = gameContext;
}

void SceneStack::push(std::unique_ptr<Scene> scene) {
    if (!scenes.empty()) {
        scenes.top()->onExit();
        scenes.top()->root->clear();
    }
    scenes.push(std::move(scene));
    scenes.top()->onEnter();
    scenes.top()->root->setRenderer(ctx->renderer);
}

void SceneStack::pop() {
    if (scenes.empty()) return;

    scenes.top()->onExit();
    scenes.top()->root->clear();
    scenes.pop();

    if (!scenes.empty()) {
        scenes.top()->onEnter();
        scenes.top()->root->setRenderer(ctx->renderer);
    }
}

Scene *SceneStack::getTop() {
    return scenes.empty() ? nullptr : scenes.top().get();
}

bool SceneStack::isEmpty() const {
    return scenes.empty();
}

void SceneStack::clear() {
    while (!scenes.empty()) {
        scenes.top()->onExit();
        scenes.top()->root->clear();
        scenes.top()->root->clear();
        scenes.pop();
    }
}

void SceneStack::quit() {
    shouldQuit = true;
}

void SceneStack::onEvent(const Event &event) {
    if (scenes.empty()) return;
    scenes.top()->onEvent(event);
    scenes.top()->root->onEvent(event);
}

void SceneStack::onUpdate(const Time time) {
    if (scenes.empty()) return;
    scenes.top()->onUpdate(time);
    scenes.top()->updateRoot();
    scenes.top()->root->update(time);
}

void SceneStack::onRender() {
    if (scenes.empty()) return;
    ctx->renderer->clear();
    scenes.top()->onRender();
    scenes.top()->root->draw();
}
