//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_FUNCTIONS_H
#define WMG_FUNCTIONS_H

namespace Easing {
    inline constexpr float Linear(float t) { return t; }
    inline constexpr float EaseInQuad(float t) { return t * t; }
    inline constexpr float EaseOutQuad(float t) { return t * (2 - t); }
    inline constexpr float EaseInOutQuad(float t) { return (t < 0.5f) ? 2 * t * t : -1 + (4 - 2 * t) * t; }
}

#endif //WMG_FUNCTIONS_H
