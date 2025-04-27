//
// Created by ChiroYuki on 14/04/2025.
//

#ifndef WMG_BUTTON_H
#define WMG_BUTTON_H


#include <PULSO/Graphics/Containers/Container.h>

class Button : public Container {
public:
    std::function<void()> onClick;

    void onEvent(const Event& event) override;

    bool isContains(float x, float y) const;

    [[nodiscard]] bool isHovered() const;
    [[nodiscard]] bool isPressed() const;

    virtual void onPress() {}
    virtual void onRelease() {}
    virtual void onHoverEnter() {}
    virtual void onHoverExit() {}

private:
    bool hovered = false;
    bool pressed = false;
};


#endif //WMG_BUTTON_H
