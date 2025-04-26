//
// Created by ChiroYuki on 10/04/2025.
//

#include "PULSO/Core/Rendering/OpenGLRenderer.h"

#include <PULSO/Core/Event/Event.h>
#include <PULSO/Core/Event/EventManager.h>

OpenGLRenderer::OpenGLRenderer() {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW.");

    window = glfwCreateWindow(800, 600, "OpenGLRenderer", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create the GLFW window.");
    }

    glfwMakeContextCurrent(window);

    // Récupérer la taille du framebuffer et installer le callback
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    setupOrtho();
    std::cout << "OpenGLRenderer initialized ("
              << fbWidth << "×" << fbHeight << " px)" << std::endl;

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, MouseMoveCallback);
    glfwSetScrollCallback(window, ScrollCallback);

}

OpenGLRenderer::~OpenGLRenderer() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void OpenGLRenderer::setupOrtho() const {
    // Passe en projection 2D en pixels (origine en haut-gauche)
    glViewport(0, 0, fbWidth, fbHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // left, right, bottom, top, near, far
    glOrtho(0, fbWidth, fbHeight, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLRenderer::onWindowResize(const int width, const int height) {
    fbWidth  = width;
    fbHeight = height;
    setupOrtho();
}

void OpenGLRenderer::FramebufferSizeCallback(GLFWwindow* win, const int width, const int height) {
    if (const auto self = static_cast<OpenGLRenderer*>(glfwGetWindowUserPointer(win))) {
        self->onWindowResize(width, height);
    }
}


void OpenGLRenderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::clear(const unsigned int color) {
    const float r = ((color >> 24) & 0xFF) / 255.0f;
    const float g = ((color >> 16) & 0xFF) / 255.0f;
    const float b = ((color >>  8) & 0xFF) / 255.0f;
    const float a = ( color        & 0xFF) / 255.0f;
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::drawRect(Vector2& position, const float width, const float height, const unsigned int color, const float rotation) {
    const float r = ((color >> 24) & 0xFF) / 255.0f;
    const float g = ((color >> 16) & 0xFF) / 255.0f;
    const float b = ((color >> 8) & 0xFF) / 255.0f;
    const float a = (color & 0xFF) / 255.0f;

    // Appliquer la couleur
    glColor4f(r, g, b, a);

    // Sauvegarder la matrice actuelle
    glPushMatrix();

    // Appliquer la rotation autour du centre du rectangle
    glTranslatef(position.x + width / 2, position.y + height / 2, 0);  // Déplacer le centre du rectangle au point d'origine
    glRotatef(rotation, 0, 0, 1); // Effectuer la rotation sur l'axe Z
    glTranslatef(-(position.x + width / 2), -(position.y + height / 2), 0); // Revenir à la position initiale

    // Dessiner le rectangle
    glBegin(GL_QUADS);
    glVertex2f(position.x, position.y);
    glVertex2f(position.x + width, position.y);
    glVertex2f(position.x + width, position.y + height);
    glVertex2f(position.x, position.y + height);
    glEnd();

    // Restaurer la matrice
    glPopMatrix();
}

void OpenGLRenderer::drawCircle(Vector2& position, const float radius, const unsigned int color) {
    const float r = ((color >> 24) & 0xFF) / 255.0f;
    const float g = ((color >> 16) & 0xFF) / 255.0f;
    const float b = ((color >>  8) & 0xFF) / 255.0f;
    const float a = ( color        & 0xFF) / 255.0f;
    glColor4f(r, g, b, a);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(position.x, position.y);

    constexpr int SEGMENTS = 64;
    for (int i = 0; i <= SEGMENTS; i++) {
        const float theta = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(SEGMENTS);
        const float dx = cosf(theta) * radius;
        const float dy = sinf(theta) * radius;
        glVertex2f(position.x + dx, position.y + dy);
    }
    glEnd();
}

void OpenGLRenderer::drawText(Vector2& /*position*/, const std::string& /*text*/, unsigned int /*color*/) {
    // à implémenter avec FreeType ou autre
}

void OpenGLRenderer::display() {
    glfwSwapBuffers(window);
    glLoadIdentity();  // réinitialiser la matrice avant le prochain frame
}

bool OpenGLRenderer::shouldQuit() {
    return glfwWindowShouldClose(window);
}

void OpenGLRenderer::pollEvents() {
    glfwPollEvents();
}

Vector2 OpenGLRenderer::getWindowSize() {
    return { static_cast<float>(fbWidth), static_cast<float>(fbHeight) };
}

void OpenGLRenderer::KeyCallback(GLFWwindow* win, int key, const int code, const int action, const int mods) {
    const auto self = static_cast<OpenGLRenderer*>(glfwGetWindowUserPointer(win));
    if (!self || !self->ctx || !self->ctx->eventDispacher) return;

    Event event{};
    if (action == GLFW_PRESS) {
        event.type = Event::Type::KeyDown;
    }
    else if (action == GLFW_RELEASE) {
        event.type = Event::Type::KeyUp;
    }
    else {
        return;
    }

    event.mousePos = { self->mousePos.x, self->mousePos.y };
    event.key = { code, mods };
    self->ctx->eventDispacher->addEvent(event);
}

void OpenGLRenderer::MouseButtonCallback(GLFWwindow* win, const int button, const int action, const int mods) {
    const auto self = static_cast<OpenGLRenderer*>(glfwGetWindowUserPointer(win));
    if (!self || !self->ctx || !self->ctx->eventDispacher) return;

    Event event{};
    if (action == GLFW_PRESS) {
        event.type = Event::Type::MouseClick;
    }
    else if (action == GLFW_RELEASE) {
        event.type = Event::Type::MouseRelease;
    }
    else {
        return;
    }

    event.mousePos = { self->mousePos.x, self->mousePos.y };
    event.button = { button, mods };
    self->ctx->eventDispacher->addEvent(event);
}

void OpenGLRenderer::MouseMoveCallback(GLFWwindow* win, const double xpos, const double ypos) {
    const auto self = static_cast<OpenGLRenderer*>(glfwGetWindowUserPointer(win));
    if (!self || !self->ctx || !self->ctx->eventDispacher) return;

    self->mousePos.x = static_cast<float>(xpos);
    self->mousePos.y = static_cast<float>(ypos);

    Event event{};

    event.type = Event::Type::MouseMove;
    event.mousePos = { self->mousePos.x, self->mousePos.y };
    self->ctx->eventDispacher->addEvent(event);
}

void OpenGLRenderer::ScrollCallback(GLFWwindow* win, const double xo, const double yo) {
    auto self = static_cast<OpenGLRenderer*>(glfwGetWindowUserPointer(win));
    if (!self || !self->ctx || !self->ctx->eventDispacher) return;

    Event event{};
    event.type = Event::Type::MouseScroll;
    event.scroll = { xo, yo };
    event.mousePos = { self->mousePos.x, self->mousePos.y };
    self->ctx->eventDispacher->addEvent(event);
}

