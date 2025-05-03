//
// Created by ChiroYuki on 08/04/2025.
//

#include "MyGame.h"

void WMGame::onInit() {
    renderer.setMode(800, 600, "WMGame - Made with PulsoEngine", 120);
    sceneStack.push(std::make_unique<MainMenuScreen>(&ctx));
}

void WMGame::onFrameStart() {
    ctx.renderer->clear();
}

void WMGame::onFrameEnd() {
    // std::cout << 1.f / deltaTime.asSeconds() << std::endl;
}

void WMGame::onCleanup() {

}