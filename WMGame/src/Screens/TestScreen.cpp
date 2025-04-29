//
// Created by adrian on 23/04/25.
//

#include "Screens/TestScreen.h"

#include <Graphics/Buttons/BeatmapButton.h>
#include <Graphics/Buttons/FilterableButton.h>
#include <PULSO/Graphics/Containers/SearchContainer.h>

TestScreen::TestScreen(GameContext* context) : Scene(context) {

}

void TestScreen::onEnter() {

    auto searchContainer = std::make_unique<SearchContainer>();

    for (int i = 0; i < 50; i++) {
        auto searchButton = std::make_unique<FilterableButton>();
        searchContainer->add(std::move(searchButton));
    }

    searchContainer->setSearchTerm("");

    root->add(std::move(searchContainer));

    auto button = std::make_unique<BeatmapButton>();
    button->setAnchor(Anchor::Left);
    button->onClick = [this] { ctx->screenStack->pop(); };
    root->add(std::move(button));
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
