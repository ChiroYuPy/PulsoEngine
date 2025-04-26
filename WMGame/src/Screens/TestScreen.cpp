//
// Created by adrian on 23/04/25.
//

#include "Screens/TestScreen.h"

TestScreen::TestScreen(GameContext* context) : Scene(context) {

}

void TestScreen::onEnter() {
    auto outerContainer = std::make_unique<DebugContainer>();
    outerContainer->setSize({210, 210});
    outerContainer->setAnchor(Anchor::TopLeft);

    auto innerContainer = std::make_unique<DebugContainer>();
    innerContainer->setSize({128, 128});
    innerContainer->setAnchor(Anchor::Center);
    innerContainer->setOrigin(Anchor::TopLeft);
    innerContainer->setColor(0xFF55FFFF);

    auto innerInnerContainer = std::make_unique<DebugContainer>();
    innerInnerContainer->setSize({48, 48});
    innerInnerContainer->setAnchor(Anchor::Bottom);
    innerInnerContainer->setColor(0xFF5555FF);

    // objects concatenate
    innerContainer->add(std::move(innerInnerContainer));
    outerContainer->add(std::move(innerContainer));
    root->add(std::move(outerContainer));
}

void TestScreen::onExit() {
}

void TestScreen::onUpdate(Time deltaTime) {
}

void TestScreen::onRender() {
}

void TestScreen::onEvent(const Event &event) {
    if (event.type == Event::Type::Closed) {} // ctx->quit();
    else if (event.type == Event::Type::KeyDown) {
        if (event.key.code == Event::Key::Escape) ctx->screenStack->pop();
    }
}
