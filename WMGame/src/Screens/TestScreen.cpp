//
// Created by adrian on 23/04/25.
//

#include "Screens/TestScreen.h"

#include <Graphics/Buttons/BeatmapButton.h>
#include <Graphics/Containers/BeatmapCarrousel.h>

TestScreen::TestScreen(GameContext* context) : Scene(context) {

}

void TestScreen::onEnter() {

    auto debugContainer = std::make_unique<DebugContainer>();
    debugContainer->setColor(Color::Cyan);
    debugContainer->setSize({256, 256});
    root->add(std::move(debugContainer));

    auto beatmapCarrousel = std::make_unique<BeatmapCarrousel>();
    root->add(std::move(beatmapCarrousel));

    // auto button = std::make_unique<BeatmapButton>();
    // button->setAnchor(Anchor::Left);
    // button->onClick = [this] { ctx->screenStack->pop(); };
    // root->add(std::move(button));
}

void TestScreen::onExit() {
}

void TestScreen::onUpdate(Time deltaTime) {
}

void TestScreen::onRender() {
}

void TestScreen::onEvent(const Event &event) {
    if (event.type == Event::Type::Closed) ctx->renderer->quitWindow();
    else if (event.type == Event::Type::KeyDown) {
        if (event.key.code == Event::Key::Escape) ctx->screenStack->pop();
    }
}
