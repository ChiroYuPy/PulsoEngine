//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_GAME_H
#define WMG_GAME_H

#include "PULSO/Core/GameContext.h"
#include "PULSO/Core/Rendering/Renderer.h"
#include "PULSO/Core/Scene/SceneStack.h"
#include "PULSO/Core/Event/EventManager.h"

#include "PULSO/Core/Clock.h"
#include "PULSO/Core/Time.h"

#include <memory>


class Game {
public:
    Game();
    virtual ~Game() = default;

    void start();

protected:
    virtual void onInit() = 0;          // Before the first while
    virtual void onFrameStart() = 0;    // Before events, update, render
    virtual void onFrameEnd() = 0;      // After events, update, render
    virtual void onCleanup() = 0;       // On the last while

    GameContext ctx;
    SceneStack sceneStack;
    Renderer renderer;
    EventManager eventManager;

    Clock clock;
    Time deltaTime;

private:
    void mainLoop();
};


#endif //WMG_GAME_H
