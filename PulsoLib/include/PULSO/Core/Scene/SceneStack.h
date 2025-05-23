//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SCENESTACK_H
#define WMG_SCENESTACK_H


#include <memory>
#include <stack>
#include "Scene.h"
#include "PULSO/Core/Time.h"

class SceneStack {
public:
    void setGameContext(GameContext* gameContext);

    void push(std::unique_ptr<Scene> scene);
    void pop();
    bool isEmpty() const;
    void clear();
    void quit();

    void onEvent(const Event &event);
    void onUpdate(Time time);
    void onRender();

    Scene* getCurrent();

private:
    std::stack<std::unique_ptr<Scene>> scenes;
    bool shouldQuit = false;
    GameContext* ctx = nullptr;
};


#endif //WMG_SCENESTACK_H
