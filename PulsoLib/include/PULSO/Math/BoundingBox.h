//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_BOUNDINGBOX_H
#define WMG_BOUNDINGBOX_H


#include "Vector2.h"

struct BoundingBox {
public:
    Vector2 min;
    Vector2 max;

    BoundingBox();
    BoundingBox(float, float, float, float);

    Vector2 getSize() const;

    float getWidth() const;

    float getHeight() const;

    void print() const;
};


#endif //WMG_BOUNDINGBOX_H
