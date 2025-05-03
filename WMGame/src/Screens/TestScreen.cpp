//
// Created by adrian on 23/04/25.
//

#include "Screens/TestScreen.h"

#include <Graphics/Buttons/BeatmapButton.h>
#include <Graphics/Containers/BeatmapCarrousel.h>

TestScreen::TestScreen(GameContext* context) : Scene(context) {

}

void TestScreen::onEnter() {

    auto beatmapCarrousel = std::make_unique<BeatmapCarrousel>();
    add(std::move(beatmapCarrousel));

    auto button = std::make_unique<BeatmapButton>(Color::Purple);
    button->setAnchor(Anchor::Left);
    button->onClick = [this] { ctx->screenStack->pop(); };
    add(std::move(button));
}

void TestScreen::onExit() {
}

void TestScreen::onUpdate(Time deltaTime) {
    Scene::onUpdate(deltaTime);
}

void TestScreen::onRender() {
    Container::onRender();
}

void TestScreen::onEvent(const Event &event) {
    Container::onEvent(event);
    if (event.type == Event::Type::Closed) ctx->renderer->quitWindow();
    else if (event.type == Event::Type::KeyDown) {
        if (event.key.code == Event::Key::Escape) ctx->screenStack->pop();
    }
}
