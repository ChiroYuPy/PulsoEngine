//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_CIRCLE_H
#define WMG_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
public:
    Circle(float radius);

    void draw() override;


    float radius;
};


#endif //WMG_CIRCLE_H
