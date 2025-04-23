//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_OPENGLRENDERER_H
#define WMG_OPENGLRENDERER_H


#include "IRenderer.h"

#include <GLFW/glfw3.h>

#include <stdexcept>
#include <iostream>
#include <math.h>

class OpenGLRenderer final : public IRenderer {
public:
    explicit OpenGLRenderer();
    ~OpenGLRenderer() override;

    void clear() override;
    void clear(unsigned int color) override;

    void drawRect(Vector2& position, float width, float height, unsigned int color) override;
    void drawCircle(Vector2& position, float radius, unsigned int color) override;
    void drawText(Vector2& position, const std::string& text, unsigned int color) override;

    void display() override;
    bool shouldQuit() override;

    void pollEvents(GameContext* context) override;
    Vector2 getWindowSize() override;

private:
    GLFWwindow* window;
    int fbWidth, fbHeight;

    void setupOrtho() const;
    void onWindowResize(int width, int height);

    static void FramebufferSizeCallback(GLFWwindow* win, int width, int height);
};


#endif //WMG_OPENGLRENDERER_H
