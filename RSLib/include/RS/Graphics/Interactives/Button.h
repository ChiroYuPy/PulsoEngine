//
// Created by ChiroYuki on 14/04/2025.
//

#ifndef WMG_BUTTON_H
#define WMG_BUTTON_H


#include "DrawableInteractable.h"

class Button : public DrawableInteractable {
public:
    std::function<void()> onClick;

    void onEvent(const Event& event) override;

    bool isContains(float x, float y);

    [[nodiscard]] bool isHovered() const;
    [[nodiscard]] bool isPressed() const;

private:
    bool hovered = false;
    bool pressed = false;
};


#endif //WMG_BUTTON_H
