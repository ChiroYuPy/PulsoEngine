//
// Created by ChiroYuki on 08/04/2025.
//


#include "RS/Core/GameBase.h"
#include "RS/Core/Audio/Music.h"

GameBase::GameBase() {
    ctx.screenStack = &sceneStack;
    ctx.renderer = &renderer;
    ctx.screenStack->setGameContext(&ctx);
    ctx.renderer->setGameContext(&ctx);
}

void GameBase::start() {
    onInit();
    mainLoop();
    onCleanup();
}

void GameBase::mainLoop() {
    Clock clock;
    while (!ctx.renderer->shouldQuit()) {

        Time deltaTime = clock.getElapsedTime();
        clock.restart();

        onFrameStart();

        ctx.renderer->pollEvents(&ctx);
        ctx.screenStack->onUpdate(deltaTime);
        ctx.screenStack->onRender();
        ctx.renderer->display();

        onFrameEnd();
    }
}

void GameBase::onInit() {}
void GameBase::onFrameStart() {}
void GameBase::onFrameEnd() {}
void GameBase::onCleanup() {}
