//
// Created by ChiroYuki on 09/04/2025.
//

#include "RS/Core/Clock.h"

Clock::Clock() : start(std::chrono::steady_clock::now()) {}

Time Clock::getElapsedTime() const {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
    return Time(diff.count());
}

void Clock::restart() {
    start = std::chrono::steady_clock::now();
}
