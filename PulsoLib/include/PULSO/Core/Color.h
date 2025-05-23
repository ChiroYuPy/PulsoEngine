//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_COLOR_H
#define WMG_COLOR_H



#include <cstdint>

class Color {
public:
    constexpr Color() = default;

    constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);

    constexpr explicit Color(std::uint32_t color);

    [[nodiscard]] constexpr std::uint32_t toInteger() const;

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Purple;
    static const Color Orange;
    static const Color Pink;
    static const Color Lime;
    static const Color Teal;
    static const Color Navy;
    static const Color Olive;
    static const Color Brown;
    static const Color SkyBlue;
    static const Color Gold;

    static const Color Transparent;
    static const Color TransparentBlack;
    static const Color TransparentWhite;
    static const Color TransparentRed;
    static const Color TransparentGreen;
    static const Color TransparentBlue;
    static const Color TransparentYellow;
    static const Color TransparentMagenta;
    static const Color TransparentCyan;
    static const Color TransparentPurple;
    static const Color TransparentOrange;
    static const Color TransparentPink;
    static const Color TransparentLime;
    static const Color TransparentTeal;
    static const Color TransparentNavy;
    static const Color TransparentOlive;
    static const Color TransparentBrown;
    static const Color TransparentSkyBlue;
    static const Color TransparentGold;

    std::uint8_t r{};
    std::uint8_t g{};
    std::uint8_t b{};
    std::uint8_t a{255};
};

[[nodiscard]] constexpr bool operator==(Color left, Color right);

[[nodiscard]] constexpr bool operator!=(Color left, Color right);

[[nodiscard]] constexpr Color operator+(Color left, Color right);

[[nodiscard]] constexpr Color operator-(Color left, Color right);

[[nodiscard]] constexpr Color operator*(Color left, Color right);

constexpr Color& operator+=(Color& left, Color right);

constexpr Color& operator-=(Color& left, Color right);

constexpr Color& operator*=(Color& left, Color right);

#include "Color.inl"



#endif //WMG_COLOR_H
