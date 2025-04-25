//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_ANIMATIONTRANSFORM_H
#define WMG_ANIMATIONTRANSFORM_H

#include <functional>
#include <utility>
#include "PULSO/Math/Vector2.h"
#include "PULSO/Math/Functions.h"
#include "PULSO/Core/Time.h"

class IAnimationTransform {
public:
    virtual ~IAnimationTransform() noexcept = default;
    virtual void update(Time deltaTime) noexcept = 0;
    [[nodiscard]] virtual bool isFinished() const noexcept = 0;
};

template <typename T>
class AnimationTransform final : public IAnimationTransform {
    AnimationTransform();

    T* attribute;
    T startValue;
    T endValue;
    Time duration;
    double elapsedTime{};
    bool finished = false;
    std::function<float(float)> easingFunction;
    std::function<void()> onFinished;

public:
    AnimationTransform(T* attribute, T startValue, T endValue, Time duration, const std::function<float(float)>& easingFunction = Easing::Linear, std::function<void()> onFinished = nullptr);

    void update(Time deltaTime) noexcept override;

    [[nodiscard]] bool isFinished() const noexcept override;
};

template<typename T>
AnimationTransform<T>::AnimationTransform() {
    static int i = 0;
    i++;
    std::cout << "AnimationTransformCount: " << i << std::endl;
}

extern template class AnimationTransform<float>;
extern template class AnimationTransform<int>;
extern template class AnimationTransform<Vector2>;

#endif //WMG_ANIMATIONTRANSFORM_H
