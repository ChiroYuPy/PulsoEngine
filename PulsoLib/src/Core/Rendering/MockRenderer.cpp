//
// Created by ChiroYuki on 10/04/2025.
//

#include "PULSO/Core/Rendering/MockRenderer.h"

MockRenderer::MockRenderer() {
    std::cout << "MockRenderer::MockRenderer" << std::endl;
}

void MockRenderer::clear() {
    std::cout << "MockRenderer::clear" << std::endl;
}

void MockRenderer::clear(unsigned int color) {
    std::cout << "MockRenderer::clear" << std::endl;
}

void MockRenderer::drawRect(Vector2& position, float width, float height, unsigned int color) {
    std::cout << "MockRenderer::drawRect" << std::endl;
}

void MockRenderer::drawCircle(Vector2& position, float radius, unsigned int color) {
    std::cout << "MockRenderer::drawCircle" << std::endl;
}

void MockRenderer::drawText(Vector2& position, const std::string &text, unsigned int color) {
    std::cout << "MockRenderer::drawText" << std::endl;
}

void MockRenderer::display() {
    std::cout << "MockRenderer::display" << std::endl;
}

void MockRenderer::pollEvents() {
    std::cout << "MockRenderer::pollEvents" << std::endl;
}

Vector2 MockRenderer::getWindowSize() {
    std::cout << "MockRenderer::getWindowSize" << std::endl;
    return {};
}

bool MockRenderer::shouldQuit() {
    std::cout << "MockRenderer::shouldQuit" << std::endl;
    return false;
}
