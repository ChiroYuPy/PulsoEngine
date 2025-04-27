//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SHAPE_H
#define WMG_SHAPE_H


#include <PULSO/Core/Color.h>

#include "PULSO/Math/Vector2.h"
#include "PULSO/Graphics/Drawable.h"

class Shape : public Drawable {
public:
    Shape();

    void setColor(Color newColor);

    [[nodiscard]] Color getColor() const;

    void colorTo(const Color &target, Time duration, const std::function<float(float)> &easingFunc) noexcept;

protected:
    Color color;
};


#endif //WMG_SHAPE_H
