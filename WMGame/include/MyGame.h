//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_MYGAME_H
#define WMG_MYGAME_H


#include <RS/Core.h>

#include "Screens/MainMenuScreen.h"
#include "Screens/TestScreen.h"


class MyGame : public Game {
protected:
    void onInit() override;

    void onFrameStart() override;

    void onFrameEnd() override;

    void onCleanup() override;
};


#endif //WMG_MYGAME_H
