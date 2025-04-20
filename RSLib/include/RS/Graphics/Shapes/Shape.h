//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_SHAPE_H
#define WMG_SHAPE_H


#include "RS/Math/Vector2.h"
#include "RS/Graphics/Drawable.h"

class Shape : public Drawable {
public:
    Shape();

    void setColor(unsigned int newColor);

    [[nodiscard]] unsigned int getColor() const;

protected:
    unsigned int color;
};


#endif //WMG_SHAPE_H
