//
// Created by adrian on 26/04/25.
//

#include "PULSO/Math/Rotation.h"

#include <cmath>

Rotation::Rotation() : angleDegrees(0.0f) {}

Rotation::Rotation(const float angle) : angleDegrees(normalizeAngle(angle)) {}

[[nodiscard]] float Rotation::getAngle() const {
    return angleDegrees;
}

void Rotation::setAngle(const float angle) {
    angleDegrees = normalizeAngle(angle);
}

void Rotation::addRotation(const float deltaAngle) {
    angleDegrees = normalizeAngle(angleDegrees + deltaAngle);
}

Rotation Rotation::operator+(const Rotation& other) const {
    return Rotation(angleDegrees + other.angleDegrees);
}

Rotation& Rotation::operator+=(const Rotation& other) {
    angleDegrees = normalizeAngle(angleDegrees + other.angleDegrees);
    return *this;
}

Rotation Rotation::operator-(const Rotation& other) const {
    return Rotation(angleDegrees - other.angleDegrees);
}

Rotation& Rotation::operator-=(const Rotation& other) {
    angleDegrees = normalizeAngle(angleDegrees - other.angleDegrees);
    return *this;
}

bool Rotation::operator==(const Rotation& other) const {
    return angleDegrees == other.angleDegrees;
}

bool Rotation::operator!=(const Rotation& other) const {
    return angleDegrees != other.angleDegrees;
}

float Rotation::normalizeAngle(float angle) {
    angle = std::fmod(angle, 360.0f);
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}