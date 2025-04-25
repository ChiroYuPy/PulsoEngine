//
// Created by ChiroYuki on 12/04/2025.
//

#include "PULSO/Math/Anchor.h"

static const Vector2 anchorOffsets[] = {
        {0.0f, 0.0f},   // TopLeft
        {0.5f, 0.0f},   // TopCentre
        {1.0f, 0.0f},   // TopRight
        {0.0f, 0.5f},   // CentreLeft
        {0.5f, 0.5f},   // Center
        {1.0f, 0.5f},   // CentreRight
        {0.0f, 1.0f},   // BottomLeft
        {0.5f, 1.0f},   // BottomCentre
        {1.0f, 1.0f}    // BottomRight
};

Vector2 toVector2(Anchor &anchor) {
    return anchorOffsets[static_cast<int>(anchor)];
}