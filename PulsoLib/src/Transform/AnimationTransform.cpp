//
// Created by ChiroYuki on 09/04/2025.
//

#include "PULSO/Transform/AnimationTransform.h"

template<typename T>
void AnimationTransform<T>::update(Time deltaTime) noexcept {
    if (finished) return;

    const double dt = deltaTime.asSeconds();
    const double dur = duration.asSeconds();

    elapsedTime += dt;

    if (elapsedTime >= dur) {
        elapsedTime = dur;
    }

    const float t = (dur > 0.f) ? elapsedTime / dur : 1.f;

    *attribute = Lerp<T>::lerp(startValue, endValue, easingFunction(t));

    if (t >= 1.0) {
        finished = true;
        if (onFinished) onFinished();
    }
}

template<typename T>
bool AnimationTransform<T>::isFinished() const noexcept { return finished; }

template<typename T>
AnimationTransform<T>::AnimationTransform(T *attribute, T startValue, T endValue, Time duration, const std::function<float(float)> &easingFunction, std::function<void()> onFinished)
: attribute(attribute), startValue(startValue), endValue(endValue), duration(duration), easingFunction(easingFunction), onFinished(std::move(onFinished)) {}

template class AnimationTransform<float>;
template class AnimationTransform<int>;
template class AnimationTransform<Vector2>;
template class AnimationTransform<Color>;