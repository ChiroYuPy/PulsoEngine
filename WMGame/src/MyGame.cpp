//
// Created by ChiroYuki on 08/04/2025.
//

#include "MyGame.h"

void MyGame::onInit() {
    sceneStack.push(std::make_unique<MainMenuScreen>(&ctx));

}

void MyGame::onFrameStart() {
    Game::onFrameStart();
}

void MyGame::onFrameEnd() {
    Game::onFrameEnd();
}

void MyGame::onCleanup() {
}