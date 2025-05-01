//
// Created by adrian on 29/04/25.
//

#ifndef SCROLLCONTAINER_H
#define SCROLLCONTAINER_H

#include "PULSO/Math/Vector2.h"
#include "PULSO/Graphics/Containers/Container.h"

class ScrollContainer : public Container {
public:
  ScrollContainer();

private:
  float scrollDistance = 80.f;
  float clampExtension = 500.f; // maximum distance which objets can scroll after the edge of the ScrollContainer

  float distanceDecayDrag = 0.0035f; // rate with which the target position is approached after ending a drag
  float distanceDecayScroll = 0.01f; // rate with which the target position is approached after scrolling
  float distanceDecayJump = 0.01f; // rate with which the target position is approached after jumping to a specific location
  float distanceDecay = 0.f; // the current distanceDecay

  Vector2 currentPosition{};
  Vector2 targetPosition{};

  Vector2 availableContent{};
  Vector2 displayableContent{};

  [[nodiscard]] Vector2 getScrollExtent() const;

  void updateLayout() override;

  void onEvent(const Event& event) override;
};



#endif //SCROLLCONTAINER_H
