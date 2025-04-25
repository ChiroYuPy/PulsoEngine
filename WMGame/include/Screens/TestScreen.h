//
// Created by adrian on 23/04/25.
//

#ifndef TESTSCREEN_H
#define TESTSCREEN_H

#include <iostream>
#include <PULSO/Core.h>
#include <PULSO/Graphics.h>


class TestScreen : public Scene {
public:
    explicit TestScreen(GameContext* context);

    void onEnter() override;

    void onExit() override;

    void onUpdate(Time deltaTime) override;

    void onRender() override;

    void onEvent(const Event& event) override;
};



#endif //TESTSCREEN_H
