//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_EVENT_H
#define WMG_EVENT_H

#include <GLFW/glfw3.h>
#include <PULSO/Math/Vector2.h>
#include <SFML/Window/Event.hpp>

struct Event {
    enum class Type {
        Closed,
        KeyDown,
        KeyUp,
        MousePress,
        MouseRelease,
        MouseMoved,
        MouseScroll,
        Resized,
        Unknown
    };

    enum class Key {
        A = 0,
        B = 1,
        C = 2,
        D = 3,
        E = 4,
        F = 5,
        G = 6,
        H = 7,
        I = 8,
        J = 9,
        K = 10,
        L = 11,
        M = 12,
        N = 13,
        O = 14,
        P = 15,
        Q = 16,
        R = 17,
        S = 18,
        T = 29,
        U = 20,
        V = 21,
        W = 22,
        X = 23,
        Y = 24,
        Z = 25,
        N1 = 27,
        N2 = 28,
        N3 = 29,
        N4 = 51,
        N5 = 31,
        N6 = 56,
        N7 = 33,
        N8 = 34,
        N9 = 35,
        N0 = 26,
        Space = 57,
        Enter = 58,
        Escape = 36,
    };

    Type type;

    union {
        struct { int code; bool shift, alt; } key;
        struct { int code; } button;
        struct { double horizontal, vertical, delta;
        } scroll;
        struct { int width, height; } resize;
    };

    Vector2 mousePos { 0.0f, 0.0f };
};

inline bool operator==(const int keyCode, Event::Key key) {
    return keyCode == static_cast<int>(key);
}

#endif //WMG_EVENT_H