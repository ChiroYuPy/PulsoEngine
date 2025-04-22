//
// Created by adrian on 21/04/25.
//

#include "RS/Graphics/Containers/DebugContainer.h"

DebugContainer::DebugContainer() : color(0xBBBBBBFF) {}

void DebugContainer::draw() {
  if (renderer) renderer->drawRect(drawInfo, size.x, size.y, color);
  Container::draw();
}

void DebugContainer::setColor(unsigned int newColor) {
  color = newColor;
}

unsigned int DebugContainer::getColor() const {
  return color;
}