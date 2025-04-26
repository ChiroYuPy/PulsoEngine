//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SCENE_H
#define WMG_SCENE_H


#include <memory>
#include <PULSO/Graphics/Containers/DebugContainer.h>

#include "PULSO/Core/Event/Event.h"
#include "PULSO/Core/Time.h"

class GameContext;

class Scene {
public:
    explicit Scene(GameContext* context);
    virtual ~Scene() = default;

    virtual void onEnter() {}
    virtual void onExit() {}

    virtual void onRender() = 0;
    virtual void onUpdate(Time deltaTime) = 0;
    virtual void onEvent(const Event& event) = 0;

    void updateRoot() const;

    std::unique_ptr<DebugContainer> root;

protected:
    GameContext* ctx = nullptr;
};


#endif //WMG_SCENE_H
