//
// Created by ChiroYuki on 12/04/2025.
//

#ifndef WMG_ANCHOR_H
#define WMG_ANCHOR_H

#include "Vector2.h"

enum class Anchor {
    TopLeft, TopCentre, TopRight,
    CentreLeft, Center, CentreRight,
    BottomLeft, BottomCentre, BottomRight
};

Vector2 toVector2(Anchor anchor);

#endif //WMG_ANCHOR_H
