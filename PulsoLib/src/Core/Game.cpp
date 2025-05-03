//
// Created by ChiroYuki on 08/04/2025.
//


#include "PULSO/Core/Game.h"
#include "PULSO/Core/Audio/Music.h"

Game::Game() {
    ctx.screenStack = &sceneStack;
    ctx.renderer = &renderer;
    ctx.eventDispacher = &eventManager;
    ctx.screenStack->setGameContext(&ctx);
    ctx.renderer->setGameContext(&ctx);
    ctx.eventDispacher->setGameContext(&ctx);
}

void Game::start() {
    onInit();
    mainLoop();
    onCleanup();
}

void Game::mainLoop() {
    while (!ctx.renderer->shouldQuit()) {

        deltaTime = clock.getElapsedTime();
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