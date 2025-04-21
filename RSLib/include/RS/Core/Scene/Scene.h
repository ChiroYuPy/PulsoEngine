//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SCENE_H
#define WMG_SCENE_H


#include <memory>
#include "RS/Graphics/Containers/Container.h"
#include "RS/Core/Events/Event.h"
#include "RS/Core/Time.h"
#include "RS/Core/GameContext.h"

class Scene {
public:
    explicit Scene(GameContext* context);
    virtual ~Scene() = default;

    virtual void onEnter() {}
    virtual void onExit() {}

    virtual void onRender() = 0;
    virtual void onUpdate(Time deltaTime) = 0;
    virtual void onEvent(const Event& event) = 0;

    std::unique_ptr<Container> root;

protected:
    GameContext* ctx = nullptr;
};


#endif //WMG_SCENE_H
