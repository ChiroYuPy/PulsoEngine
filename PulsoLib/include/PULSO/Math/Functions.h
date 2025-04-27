//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_FUNCTIONS_H
#define WMG_FUNCTIONS_H

#include <cmath>

namespace Easing {

    // Linear
    constexpr float Linear(const float t) { return t; }

    // Quadratic
    constexpr float EaseInQuad(const float t) { return t * t; }
    constexpr float EaseOutQuad(const float t) { return t * (2.0f - t); }
    constexpr float EaseInOutQuad(const float t) { return (t < 0.5f) ? 2.0f * t * t : -1.0f + (4.0f - 2.0f * t) * t; }

    // Cubic
    constexpr float EaseInCubic(const float t) { return t * t * t; }
    constexpr float EaseOutCubic(const float t) { return (t - 1.0f) * (t - 1.0f) * (t - 1.0f) + 1.0f; }
    constexpr float EaseInOutCubic(const float t) {
        return (t < 0.5f)
            ? 4.0f * t * t * t
            : (t - 1.0f) * (2.0f * t - 2.0f) * (2.0f * t - 2.0f) + 1.0f;
    }

    // Quartic
    constexpr float EaseInQuart(const float t) { return t * t * t * t; }
    constexpr float EaseOutQuart(const float t) {
        const float p = t - 1.0f;
        return 1.0f - p * p * p * p;
    }
    constexpr float EaseInOutQuart(const float t) {
        return (t < 0.5f)
            ? 8.0f * t * t * t * t
            : 1.0f - 8.0f * (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * (t - 1.0f);
    }

    // Quintic
    constexpr float EaseInQuint(const float t) { return t * t * t * t * t; }
    constexpr float EaseOutQuint(const float t) {
        const float p = t - 1.0f;
        return 1.0f + p * p * p * p * p;
    }
    constexpr float EaseInOutQuint(const float t) {
        return (t < 0.5f)
            ? 16.0f * t * t * t * t * t
            : 1.0f + 16.0f * (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * (t - 1.0f);
    }

    // Sine
    inline float EaseInSine(const float t) { return 1.0f - std::cos((t * std::numbers::pi_v<float>) / 2.0f); }
    inline float EaseOutSine(const float t) { return std::sin((t * std::numbers::pi_v<float>) / 2.0f); }
    inline float EaseInOutSine(const float t) { return -(std::cos(std::numbers::pi_v<float> * t) - 1.0f) / 2.0f; }

    // Exponential
    inline float EaseInExpo(const float t) {
        return (t == 0.0f) ? 0.0f : std::pow(2.0f, 10.0f * (t - 1.0f));
    }
    inline float EaseOutExpo(const float t) {
        return (t == 1.0f) ? 1.0f : 1.0f - std::pow(2.0f, -10.0f * t);
    }
    inline float EaseInOutExpo(float t) {
        if (t == 0.0f) return 0.0f;
        if (t == 1.0f) return 1.0f;
        if (t < 0.5f) return std::pow(2.0f, 20.0f * t - 10.0f) / 2.0f;
        return (2.0f - std::pow(2.0f, -20.0f * t + 10.0f)) / 2.0f;
    }

    // Circular
    inline float EaseInCirc(const float t) {
        return 1.0f - std::sqrt(1.0f - t * t);
    }
    inline float EaseOutCirc(const float t) {
        const float p = t - 1.0f;
        return std::sqrt(1.0f - p * p);
    }
    inline float EaseInOutCirc(const float t) {
        if (t < 0.5f) {
            return (1.0f - std::sqrt(1.0f - 4.0f * t * t)) / 2.0f;
        } else {
            const float p = 2.0f * t - 2.0f;
            return (std::sqrt(1.0f - p * p) + 1.0f) / 2.0f;
        }
    }

    // Back
    inline float EaseInBack(const float t) {
        constexpr float c1 = 1.70158f;
        constexpr float c3 = c1 + 1.0f;
        return c3 * t * t * t - c1 * t * t;
    }

    inline float EaseOutBack(const float t) {
        constexpr float c1 = 1.70158f;
        constexpr float c3 = c1 + 1.0f;
        const float p = t - 1.0f;
        return 1.0f + c3 * p * p * p + c1 * p * p;
    }

} // namespace Easing

#endif //WMG_FUNCTIONS_H
