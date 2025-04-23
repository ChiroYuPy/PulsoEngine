//
// Created by adrian on 21/04/25.
//

#include "RS/Graphics/Containers/DebugContainer.h"

DebugContainer::DebugContainer() : color(0xBBBBBBFF) {}

void DebugContainer::draw() {
  Vector2 drawPos = absolutePosition - Vector2(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);
  if (renderer) renderer->drawRect(drawPos, absoluteSize.x, absoluteSize.y, color);
  // if (renderer) renderer->drawCircle(absolutePosition, 2, 0xFFFFFFFF);
  Container::draw();
}

void DebugContainer::setColor(const unsigned int newColor) {
  color = newColor;
}

unsigned int DebugContainer::getColor() const {
  return color;
}