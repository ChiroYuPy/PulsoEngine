//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_MYGAME_H
#define WMG_MYGAME_H


#include <PULSO/Core.h>

#include "Screens/MainMenuScreen.h"
#include "Screens/TestScreen.h"


class WMGame : public Game {
protected:
    void onInit() override;

    void onFrameStart() override;

    void onFrameEnd() override;

    void onCleanup() override;
};


#endif //WMG_MYGAME_H
