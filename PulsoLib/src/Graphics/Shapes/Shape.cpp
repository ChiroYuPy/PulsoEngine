//
// Created by ChiroYuki on 08/04/2025.
//

#include "PULSO/Graphics/Shapes/Shape.h"

Shape::Shape() : color(0xFFFFFFFF) {}

void Shape::setColor(const unsigned int newColor) {
    color = newColor;
}

unsigned int Shape::getColor() const {
    return color;
}