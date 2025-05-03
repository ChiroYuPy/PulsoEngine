//
// Created by ChiroYuki on 09/04/2025.
//

#include "PULSO/Transform/Transformable.h"

void Transformable::addAnimation(std::unique_ptr<IAnimationTransform> animationTransform) noexcept {
    animationTransforms.push_back(std::move(animationTransform));
}

void Transformable::onUpdate(Time deltaTime) {
    for (auto it = animationTransforms.begin(); it != animationTransforms.end();) {
        (*it)->update(deltaTime);
        if ((*it)->isFinished())
            it = animationTransforms.erase(it);
        else
            ++it;
    }
}
