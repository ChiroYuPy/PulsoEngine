//
// Created by ChiroYuki on 08/04/2025.
//

#include "Screens/MainMenuScreen.h"
#include "PULSO/Graphics/Label.h"

#include <Screens/TestScreen.h>

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

    // Un conteneur principal géant
    auto rootBox = std::make_unique<DebugContainer>();
    rootBox->setAnchor(Anchor::Center);
    rootBox->setSize({512, 512});
    rootBox->setColor(Color(0xFF222222));

    // Un conteneur en haut à gauche
    auto topLeftBox = std::make_unique<DebugContainer>();
    topLeftBox->setAnchor(Anchor::TopLeft);
    topLeftBox->setSize({128, 128});
    topLeftBox->setColor(Color(0xFFFFAAAA));

    // Un sous conteneur centré dans topLeftBox
    auto nestedTopLeft = std::make_unique<DebugContainer>();
    nestedTopLeft->setAnchor(Anchor::Center);
    nestedTopLeft->setSize({64, 64});
    nestedTopLeft->setColor(Color(0xFFAAFFAA));

    topLeftBox->add(std::move(nestedTopLeft));
    rootBox->add(std::move(topLeftBox));

    // Un conteneur en haut à droite avec un cercle
    auto topRightBox = std::make_unique<DebugContainer>();
    topRightBox->setAnchor(Anchor::TopRight);
    topRightBox->setSize({128, 128});
    topRightBox->setColor(Color(0xFFAAAAFF));

    auto circle = std::make_unique<Circle>(32);
    circle->setAnchor(Anchor::Center);
    circle->setColor(Color(0xFFFFFF00));
    circle->setPosition({0, 0});
    topRightBox->add(std::move(circle));

    rootBox->add(std::move(topRightBox));

    // Bas au centre, une pile de trois boîtes imbriquées
    auto bottomBox = std::make_unique<DebugContainer>();
    bottomBox->setAnchor(Anchor::Bottom);
    bottomBox->setSize({160, 160});
    bottomBox->setColor(Color(0xFFFFAAFF));

    auto inner1 = std::make_unique<DebugContainer>();
    inner1->setAnchor(Anchor::TopLeft);
    inner1->setSize({96, 96});
    inner1->setColor(Color(0xFFAAFFFF));

    auto inner2 = std::make_unique<DebugContainer>();
    inner2->setAnchor(Anchor::BottomRight);
    inner2->setSize({48, 48});
    inner2->setRotation(Rotation(45));
    inner2->setColor(Color(0xFF00FFAA));

    inner1->add(std::move(inner2));
    bottomBox->add(std::move(inner1));
    rootBox->add(std::move(bottomBox));

    root->add(std::move(rootBox));

    sound = std::make_unique<Sound>("../WMGame/ressources/ui-pop-up-243471.mp3");
    sound->setVolume(1.f);

    auto label1 = std::make_unique<Label>();
    label1->setText("Test Text");
    label1->setFontSize(32);
    root->add(std::move(label1));

    auto button = std::make_unique<BeatmapButton>(Color::TransparentBlue);
    button->onClick = [this] { ctx->screenStack->push(std::make_unique<TestScreen>(ctx)); };
    root->add(std::move(button));

    std::cout << "nb: " << root->size() << std::endl;
}


void MainMenuScreen::onExit() {

}

void MainMenuScreen::onUpdate(Time deltaTime) {

}

void MainMenuScreen::onRender() {

}

void MainMenuScreen::onEvent(const Event& event) {
    if (event.type == Event::Type::Closed) ctx->renderer->quitWindow();
    else if (event.type == Event::Type::KeyDown) {
        if (event.key.code == Event::Key::Escape) ctx->renderer->quitWindow();
        else if (event.key.code == Event::Key::A) ctx->screenStack->push(std::make_unique<GameScreen>(ctx));
        else if (event.key.code == Event::Key::Z) ctx->screenStack->push(std::make_unique<TestScreen>(ctx));
        else if (event.key.code == Event::Key::Space) sound->play();
    }
}