//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_VECTOR2_H
#define WMG_VECTOR2_H


#include <iostream>

struct Vector2 {
    float x, y;

    Vector2();
    Vector2(float x, float y);

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    [[nodiscard]] float length() const;
    [[nodiscard]] Vector2 normalized() const;
    [[nodiscard]] float dot(const Vector2& other) const;

    void print() const;
};


#endif //WMG_VECTOR2_H
