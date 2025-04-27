//
// Created by adrian on 11/03/25.
//

#ifndef LERP_H
#define LERP_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

template <typename T>
class Lerp {
public:
    static T lerp(const T& a, const T& b, float t) {
        return a + (b - a) * t;
    }
};

template <typename T>
class Lerp<sf::Vector2<T>> {
public:
    static sf::Vector2<T> lerp(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2, float t) {
        return sf::Vector2<T>(
            Lerp<T>::lerp(v1.x, v2.x, t),
            Lerp<T>::lerp(v1.y, v2.y, t)
        );
    }
};

template <>
class Lerp<Color> {
public:
    static Color lerp(const Color& c1, const Color& c2, const float t) {
        return {
            static_cast<sf::Uint8>(Lerp<float>::lerp(c1.r, c2.r, t)),
            static_cast<sf::Uint8>(Lerp<float>::lerp(c1.g, c2.g, t)),
            static_cast<sf::Uint8>(Lerp<float>::lerp(c1.b, c2.b, t)),
            static_cast<sf::Uint8>(Lerp<float>::lerp(c1.a, c2.a, t))
        };
    }
};

#endif //LERP_H
