//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_IRENDERER_H
#define WMG_IRENDERER_H

#include <RS/Math/Vector2.h>

#include "RS/Core/GameContext.h"

class GameBase;

class IRenderer {
public:
    virtual ~IRenderer() = default;

    void setGameContext(GameContext* gameContext);

    virtual void clear() = 0;
    virtual void clear(unsigned int color) = 0;

    virtual void drawRect(Vector2& position, float width, float height, unsigned int color) = 0;
    virtual void drawCircle(Vector2& position, float radius, unsigned int color) = 0;
    virtual void drawText(Vector2& position, const std::string& text, unsigned int color) = 0;

    virtual void display() = 0;
    virtual bool shouldQuit() = 0;

    virtual void pollEvents(GameContext* context) = 0;

    virtual Vector2 getWindowSize() = 0;

protected:
    GameContext* ctx = nullptr;
};

#endif //WMG_IRENDERER_H
