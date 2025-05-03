//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_BOX_H
#define WMG_BOX_H


#include "Shape.h"

class Box : public Shape {
public:
    Box();

    void setSize(const Vector2& newSize) override;

    void onRender() override;
};


#endif //WMG_BOX_H
