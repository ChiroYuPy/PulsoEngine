//
// Created by ChiroYuki on 08/04/2025.
//

#include "RS/Graphics/Shapes/Shape.h"

Shape::Shape() : color(0xFFFFFFFF) {}

void Shape::setColor(unsigned int newColor) {
    color = newColor;
}

unsigned int Shape::getColor() const {
    return color;
}