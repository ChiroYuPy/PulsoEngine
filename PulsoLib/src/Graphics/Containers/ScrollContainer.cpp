//
// Created by adrian on 29/04/25.
//

#include "PULSO/Graphics/Containers/ScrollContainer.h"

ScrollContainer::ScrollContainer() {

}

Vector2 ScrollContainer::getScrollExtent() const {
  const Vector2 scrollContainerSize = getAbsoluteSize();
  return {availableContent.x - scrollContainerSize.x, availableContent.y - scrollContainerSize.y};
}

void ScrollContainer::update(Time deltaTime) {
    Container::update(deltaTime);
    distanceDecay = distanceDecayScroll;
    currentPosition += (targetPosition - currentPosition) * distanceDecay * deltaTime.asSeconds();
}

void ScrollContainer::updateLayout() {
  const auto onlyChild = children.front();
  availableContent = onlyChild->getAbsoluteSize();

  const float yOffset = - currentPosition.y - absoluteSize.y * 0.5f;
  onlyChild->setPosition({0, yOffset - (1 - onlyChild->getAbsoluteSize().y) * onlyChild->getOriginVector().y});
}

void ScrollContainer::onEvent(const Event& event) {
  Container::onEvent(event);
  if (event.type == Event::Type::MouseScroll) {
    targetPosition.y -= static_cast<float>(event.scroll.delta) * scrollDistance;

    const Vector2 extent = getScrollExtent();

    targetPosition.x = std::clamp(targetPosition.x, 0.f, extent.x);
    targetPosition.y = std::clamp(targetPosition.y, 0.f, extent.y);

    updateLayout();
  }
}