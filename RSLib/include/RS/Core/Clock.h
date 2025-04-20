//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_CLOCK_H
#define WMG_CLOCK_H

#include <SFML/System/Time.hpp>

#include <chrono>
#include "Time.h"

class Clock {
public:
    Clock();

    [[nodiscard]] Time getElapsedTime() const;

    void restart();

private:
    std::chrono::steady_clock::time_point start;
};


#endif //WMG_CLOCK_H
