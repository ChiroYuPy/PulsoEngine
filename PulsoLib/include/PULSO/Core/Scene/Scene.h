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

class Scene : public Container {
public:
    explicit Scene(GameContext* context);

    virtual void onEnter() {}
    virtual void onExit() {}

    virtual void onUpdate(Time deltaTime) override;

protected:
    GameContext* ctx = nullptr;
};


#endif //WMG_SCENE_H
