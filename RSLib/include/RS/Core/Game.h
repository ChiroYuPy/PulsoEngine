//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_GAME_H
#define WMG_GAME_H


#include <memory>
#include <stack>
#include "RS/Core/GameBase.h"

class Game : public GameBase {
public:
    Game() = default;
    ~Game() override = default;

protected:
    void onInit() override {}
    void onFrameStart() override {}
    void onFrameEnd() override {}
    void onCleanup() override {}
};


#endif //WMG_GAME_H
