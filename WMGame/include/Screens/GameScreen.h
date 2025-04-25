//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_GAMESCREEN_H
#define WMG_GAMESCREEN_H


#include <iostream>
#include <PULSO/Core.h>
#include <PULSO/Graphics.h>

#include "Graphics/Lane.h"
#include "Graphics/GridTest.h"

class GameScreen : public Scene {
public:
    explicit GameScreen(GameContext* context);

    void onEnter() override;

    void onExit() override;

    void onUpdate(Time deltaTime) override;

    void onRender() override;

    void onEvent(const Event& event) override;
};


#endif //WMG_GAMESCREEN_H
