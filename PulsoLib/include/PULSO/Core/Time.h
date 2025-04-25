//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_TIME_H
#define WMG_TIME_H


#include <chrono>

class Time {
public:
    using Duration = std::chrono::duration<double>;

    Time();
    explicit Time(double seconds);

    [[nodiscard]] double asSeconds() const;

    [[nodiscard]] double asMilliseconds() const;

    static Time seconds(double s);

    static Time millis(double ms);

    Time operator+(const Time& other) const;

    Time operator-(const Time& other) const;

    Time operator*(double scalar) const;

    Time operator/(double scalar) const;

    Time operator-() const;

    Time& operator+=(const Time& other);

    Time& operator-=(const Time& other);

    Time& operator*=(double scalar);

    Time& operator/=(double scalar);

    bool operator==(const Time& other) const;

    bool operator!=(const Time& other) const;

    bool operator<(const Time& other) const;

    bool operator<=(const Time& other) const;

    bool operator>(const Time& other) const;

    bool operator>=(const Time& other) const;

private:
    explicit Time(Duration dur);

    Duration duration;
};


#endif //WMG_TIME_H
