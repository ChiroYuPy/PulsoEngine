//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_TRANSFORMABLE_H
#define WMG_TRANSFORMABLE_H


#include <memory>
#include "AnimationTransform.h"
#include "PULSO/Core/Time.h"


class Transformable {
public:
    void addAnimation(std::unique_ptr<IAnimationTransform> animationTransform) noexcept;

    virtual void update(Time deltaTime);

private:
    std::vector<std::unique_ptr<IAnimationTransform>> animationTransforms;
};


#endif //WMG_TRANSFORMABLE_H
