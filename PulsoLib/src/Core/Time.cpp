//
// Created by ChiroYuki on 09/04/2025.
//

#include "PULSO/Core/Time.h"

Time::Time() : duration(Duration(0)) {}

Time::Time(double seconds) : duration(Duration(seconds)) {}

double Time::asSeconds() const {
    return duration.count();
}

double Time::asMilliseconds() const {
    return duration.count() * 1000.0;
}

Time Time::seconds(double s) {
    return Time(s);
}

Time Time::millis(double ms) {
    return Time(ms / 1000.0);
}

Time Time::operator+(const Time &other) const {
    return Time(asSeconds() + other.asSeconds());
}

Time Time::operator-(const Time &other) const {
    return Time(asSeconds() - other.asSeconds());
}

Time Time::operator*(double scalar) const {
    return Time(duration * scalar);
}

Time Time::operator/(double scalar) const {
    if (scalar == 0.0) throw std::runtime_error("Division by zero in Time::operator/");
    return Time(duration / scalar);
}

Time Time::operator-() const {
    return Time(-duration);
}

Time &Time::operator+=(const Time &other) {
    duration += other.duration;
    return *this;
}

Time &Time::operator-=(const Time &other) {
    duration -= other.duration;
    return *this;
}

Time &Time::operator*=(double scalar) {
    duration *= scalar;
    return *this;
}

Time& Time::operator/=(double scalar) {
    if (scalar == 0.0) throw std::runtime_error("Division by zero in Time::operator/=");
    duration /= scalar;
    return *this;
}

bool Time::operator==(const Time &other) const {
    return duration == other.duration;
}

bool Time::operator!=(const Time &other) const {
    return duration != other.duration;
}

bool Time::operator<(const Time &other) const {
    return duration < other.duration;
}

bool Time::operator<=(const Time &other) const {
    return duration <= other.duration;
}

bool Time::operator>(const Time &other) const {
    return duration > other.duration;
}

bool Time::operator>=(const Time &other) const {
    return duration >= other.duration;
}

Time::Time(Time::Duration dur) : duration(dur) {}