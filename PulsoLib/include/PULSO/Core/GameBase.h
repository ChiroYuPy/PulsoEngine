//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_GAMEBASE_H
#define WMG_GAMEBASE_H

#include "PULSO/Core/GameContext.h"
#include "PULSO/Core/Rendering/OpenGLRenderer.h"
#include "PULSO/Core/Scene/SceneStack.h"
#include "PULSO/Core/Event/EventManager.h"

#include "PULSO/Core/Clock.h"
#include "PULSO/Core/Time.h"

#include <memory>


class GameBase {
public:
    GameBase();
    virtual ~GameBase() = default;

    void start();

protected:
    virtual void onInit();          // Before the first while
    virtual void onFrameStart();    // Before events, update, render
    virtual void onFrameEnd();      // After events, update, render
    virtual void onCleanup();       // On the last while

    GameContext ctx;
    SceneStack sceneStack;
    OpenGLRenderer renderer;
    EventManager eventManager;

private:
    void mainLoop();
};


#endif //WMG_GAMEBASE_H
