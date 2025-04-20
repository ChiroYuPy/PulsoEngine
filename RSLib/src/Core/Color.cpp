//
// Created by ChiroYuki on 09/04/2025.
//

#include "RS/Core/Color.h"

Color::Color() : r(0), g(0), b(0), a(255) {}

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : r(red), g(green), b(blue), a(alpha) {}

Color Color::fromHex(const std::string &hex) {
    std::string value = hex;
    if (!value.empty() && value[0] == '#') {
        value.erase(0, 1);
    }

    if (value.size() != 6 && value.size() != 8)
        throw std::invalid_argument("La couleur hex doit être au format RRGGBB ou RRGGBBAA");

    unsigned int number;
    std::istringstream iss(value);
    iss >> std::hex >> number;

    if (value.size() == 6) {
        unsigned char red   = (number >> 16) & 0xFF;
        unsigned char green = (number >> 8) & 0xFF;
        unsigned char blue  = number & 0xFF;
        return {red, green, blue, 255};
    } else {
        unsigned char red   = (number >> 24) & 0xFF;
        unsigned char green = (number >> 16) & 0xFF;
        unsigned char blue  = (number >> 8) & 0xFF;
        unsigned char alpha = number & 0xFF;
        return {red, green, blue, alpha};
    }
}

Color Color::fromRGB(unsigned char red, unsigned char green, unsigned char blue) {
    return {red, green, blue};
}

std::string Color::toString() const {
    std::ostringstream oss;
    oss << "Color(R: " << static_cast<int>(r)
        << ", G: " << static_cast<int>(g)
        << ", B: " << static_cast<int>(b)
        << ", A: " << static_cast<int>(a) << ")";
    return oss.str();
}
