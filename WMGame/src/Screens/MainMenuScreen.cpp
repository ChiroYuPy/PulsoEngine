//
// Created by ChiroYuki on 08/04/2025.
//

#include "Screens/MainMenuScreen.h"
#include "Screens/GameScreen.h"
#include "RS/Core/Audio/Music.h"
#include "Graphics/BeatmapButton.h"

MainMenuScreen::MainMenuScreen(GameContext* context) : Scene(context) {
    music = std::make_unique<Music>("../WMGame/ressources/audio.mp3");
    std::cout << music->getCurrentTimeSeconds() << "/" << music->getLength() << std::endl;
    music->setLooping(false);
    music->seek(60.f);
    music->setVolume(1.f);
    music->setPitch(1.f);

    sound = std::make_unique<Sound>("../WMGame/ressources/ui-pop-up-243471.mp3");
    sound->setVolume(1.f);
}

void MainMenuScreen::onEnter() {
    auto circle1 = std::make_unique<Circle>(64);
    circle1->setPosition({100, 300});
    circle1->setColor(0xFF00AAFF);
    circle1->setAnchor(Anchor::Center);
    // circle1->moveTo({700, 300}, Time::millis(3000), Easing::EaseInOutQuad);

    root->addChild(std::move(circle1));

    auto button = std::make_unique<BeatmapButton>();
    button->setAnchor(Anchor::Center);

    root->addChild(std::move(button));

    // music->start();
}

void MainMenuScreen::onExit() {
}

void MainMenuScreen::onUpdate(Time deltaTime) {

}

void MainMenuScreen::onRender() {
}

void MainMenuScreen::onEvent(const Event& event) {
    if (event.type == Event::Closed) {} // ctx->quit();
    else if (event.type == Event::KeyPressed) {
        if (event.key.code == Key::Escape) {} // ctx->quit();
        else if (event.key.code == Key::A) ctx->screenStack->push(std::make_unique<GameScreen>(ctx));
        else if (event.key.code == Key::Space) sound->play();
    };
}