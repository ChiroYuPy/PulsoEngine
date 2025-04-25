//
// Created by ChiroYuki on 08/04/2025.
//

#include <valarray>
#include "PULSO/Math/Vector2.h"

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& other) const {
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return {x - other.x, y - other.y};
}

Vector2 Vector2::operator*(float scalar) const {
    return {x * scalar, y * scalar};
}

Vector2 Vector2::operator/(float scalar) const {
    return {x / scalar, y / scalar};
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const {
    return !(*this == other);
}

float Vector2::length() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalized() const {
    float len = length();
    return len != 0 ? *this / len : Vector2(0, 0);
}

float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

void Vector2::print() const {
    std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
}