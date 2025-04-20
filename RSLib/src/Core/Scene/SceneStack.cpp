//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Core/Scene/SceneStack.h"

void SceneStack::setGameContext(GameContext *gameContext) {
    ctx = gameContext;
}

void SceneStack::push(std::unique_ptr<Scene> scene) {
    if (!scenes.empty()) scenes.top()->onExit();
    scene->onEnter();
    scenes.push(std::move(scene));
}

void SceneStack::pop() {
    if (scenes.empty()) return;

    scenes.top()->onExit();
    scenes.pop();

    if (!scenes.empty()) scenes.top()->onEnter();
}

Scene *SceneStack::getTop() {
    return scenes.empty() ? nullptr : scenes.top().get();
}

bool SceneStack::isEmpty() {
    return scenes.empty();
}

void SceneStack::clear() {
    while (!scenes.empty()) {
        scenes.top()->onExit();
        scenes.pop();
    }
}

void SceneStack::quit() {
    shouldQuit = true;
}
