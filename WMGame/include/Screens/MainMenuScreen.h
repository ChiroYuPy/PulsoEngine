//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_MAINMENUSCREEN_H
#define WMG_MAINMENUSCREEN_H


#include <RS/Core.h>
#include <RS/Graphics.h>
#include "RS/Core/Audio/Music.h"
#include "RS/Core/Audio/Sound.h"

#include "Screens/GameScreen.h"
#include "Graphics/BeatmapButton.h"

class MainMenuScreen : public Scene {
public:
    explicit MainMenuScreen(GameContext* context);

    void onEnter() override;

    void onExit() override;

    void onUpdate(Time deltaTime) override;

    void onRender() override;

    void onEvent(const Event& event) override;

private:
    std::unique_ptr<Music> music;
    std::unique_ptr<Sound> sound;
};


#endif //WMG_MAINMENUSCREEN_H
