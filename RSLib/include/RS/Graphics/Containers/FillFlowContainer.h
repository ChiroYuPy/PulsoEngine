//
// Created by ChiroYuki on 12/04/2025.
//

#ifndef WMG_FILLFLOWCONTAINER_H
#define WMG_FILLFLOWCONTAINER_H


enum class Direction {
    Horizontal,
    Vertical
};


#include "Container.h"

class FillFlowContainer : public Container {
public:
    explicit FillFlowContainer();

    void setDirection(Direction newDirection);
    void setSpacing(float newSpacing);

    void updateLayout() override;
    void update(Time deltaTime) override;

private:
    Direction direction = Direction::Vertical;
    float spacing = 0.0f;
};


#endif //WMG_FILLFLOWCONTAINER_H
