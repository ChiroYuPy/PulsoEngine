//
// Created by ChiroYuki on 08/04/2025.
//

#include "MyGame.h"

void WMGame::onInit() {
    renderer.setMode(1920, 1080, "WMGame - Made with PulsoEngine", 330);
    sceneStack.push(std::make_unique<MainMenuScreen>(&ctx));
}

void WMGame::onFrameStart() {

}

void WMGame::onFrameEnd() {

}

void WMGame::onCleanup() {

}