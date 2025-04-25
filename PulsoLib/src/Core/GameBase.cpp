//
// Created by ChiroYuki on 08/04/2025.
//


#include "PULSO/Core/GameBase.h"
#include "PULSO/Core/Audio/Music.h"

GameBase::GameBase() {
    ctx.screenStack = &sceneStack;
    ctx.renderer = &renderer;
    ctx.eventDispacher = &eventManager;
    ctx.screenStack->setGameContext(&ctx);
    ctx.renderer->setGameContext(&ctx);
    ctx.eventDispacher->setGameContext(&ctx);
}

void GameBase::start() {
    onInit();
    mainLoop();
    onCleanup();
}

void GameBase::mainLoop() {
    Clock clock;
    while (!ctx.renderer->shouldQuit()) {

        const Time deltaTime = clock.getElapsedTime();
        clock.restart();

        onFrameStart();

        ctx.eventDispacher->clearEvents();
        ctx.renderer->pollEvents();
        for (auto event : ctx.eventDispacher->getEvents()) ctx.screenStack->onEvent(event);
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
