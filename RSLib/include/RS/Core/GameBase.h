//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_GAMEBASE_H
#define WMG_GAMEBASE_H


#include "RS/Core/GameBase.h"
#include "RS/Core/Events/Event.h"

#include "RS/Core/GameContext.h"
// #include "RS/Core/Rendering/SFMLRenderer.h"
#include "RS/Core/Rendering/OpenGLRenderer.h"
#include "RS/Core/Scene/SceneStack.h"

#include "RS/Core/Clock.h"
#include "RS/Core/Time.h"

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

private:
    void mainLoop();
};


#endif //WMG_GAMEBASE_H
