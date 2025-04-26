//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_EVENT_H
#define WMG_EVENT_H

#include <GLFW/glfw3.h>

struct Event {
    enum class Type {
        KeyDown,
        KeyUp,
        MouseMove,
        MouseClick,
        MouseRelease,
        MouseScroll,
        Closed
    };

    enum class Key {
        A = 24,
        B = 56,
        C = 54,
        D = 40,
        E = 26,
        F = 41,
        G = 42,
        H = 43,
        I = 31,
        J = 44,
        K = 45,
        L = 46,
        M = 47,
        N = 57,
        O = 32,
        P = 33,
        Q = 38,
        R = 27,
        S = 39,
        T = 28,
        U = 30,
        V = 55,
        W = 52,
        X = 53,
        Y = 29,
        Z = 25,
        N1 = 10,
        N2 = 11,
        N3 = 12,
        N4 = 13,
        N5 = 14,
        N6 = 15,
        N7 = 16,
        N8 = 17,
        N9 = 18,
        N0 = 19,
        Space = 65,
        Enter = 36,
        Escape = 9,
    };

    Type type;

    union {
        struct { int code, mods; } key;
        struct { int button, mods; } button;
        struct { double horizontal, vertical; } scroll;
        struct { int width, height; } resize;
    };

    Vector2 mousePos { 0.0f, 0.0f };
};

inline bool operator==(const int keyCode, Event::Key key) {
    return keyCode == static_cast<int>(key);
}

#endif //WMG_EVENT_H