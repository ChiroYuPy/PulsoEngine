//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_EVENT_H
#define WMG_EVENT_H

#include <SFML/Graphics.hpp>

/*
enum class Key {
    None,
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,        // Alpha
    N0, N1, N2, N3, N4, N5, N6, N7, N8, N9,                                             // Nums
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,                                 // Function keys
    Left, Right, Up, Down,                                                            // Directions
    Escape, Enter, Space, Backspace, Tab,                                            // Control keys
    Shift, Ctrl, Alt,                                                               // Modifier keys
    Comma, Period, Slash, Semicolon, Colon, Apostrophe, Quote,                     // Punctuation keys
    Minus, Equal, LeftBracket, RightBracket, Backslash,                           // Punctuation / Symbol keys
    CapsLock, NumLock, ScrollLock,                                               // Lock keys
    Home, End, PageUp, PageDown, ArrowLeft, ArrowRight, ArrowUp, ArrowDown,     // Navigation keys
    Insert, Delete                                                             // Other keys
};

enum class EventType {
    WindowClosed,
    KeyPressed,
    KeyRelease
};

struct Event {
    EventType type;
    Key key;
    long unicode;
};
*/


using Event = sf::Event;

using Key = sf::Keyboard::Key;

#endif //WMG_EVENT_H
