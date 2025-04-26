//
// Created by adrian on 21/04/25.
//

#include "PULSO/Graphics/Containers/DebugContainer.h"

DebugContainer::DebugContainer() : color(0xBBBBBBFF) {}

void DebugContainer::draw() {
  sf::RectangleShape box;
  box.setSize({absoluteSize.x, absoluteSize.y});
  box.setPosition(absolutePosition.x, absolutePosition.y);
  box.setFillColor(sf::Color(color));
  box.setOrigin(originVector.x * absoluteSize.x, originVector.y * absoluteSize.y);
  box.setRotation(rotation.getAngle());

  if (renderer) renderer->draw(box);
  Container::draw();
}

void DebugContainer::setColor(const unsigned int newColor) {
  color = newColor;
}

unsigned int DebugContainer::getColor() const {
  return color;
}