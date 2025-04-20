//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_COLOR_H
#define WMG_COLOR_H


#include <string>
#include <ios>
#include <sstream>

class Color {
public:
    unsigned char r, g, b, a;

    Color();

    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);

    static Color fromHex(const std::string& hex);

    static Color fromRGB(unsigned char red, unsigned char green, unsigned char blue);

    [[nodiscard]] std::string toString() const;
};


#endif //WMG_COLOR_H
