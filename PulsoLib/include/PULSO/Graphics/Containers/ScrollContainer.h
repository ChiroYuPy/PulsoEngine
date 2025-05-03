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

protected:
    float distanceDecayDrag = 6.f; // rate with which the target position is approached after ending a drag
    float distanceDecayScroll = 10.f; // rate with which the target position is approached after scrolling
    float distanceDecayJump = 8.f; // rate with which the target position is approached after jumping to a specific location

    float scrollDistance = 80.f;
    float clampExtension = 500.f; // maximum distance which objets can scroll after the edge of the ScrollContainer

private:

  float distanceDecay = 0.f; // the current distanceDecay

  Vector2 currentPosition{};
  Vector2 targetPosition{};

  Vector2 availableContent{};
  Vector2 displayableContent{};

  [[nodiscard]] Vector2 getScrollExtent() const;

  void updateLayout() override;

  void onEvent(const Event& event) override;

  void onUpdate(Time deltaTime) override;
};



#endif //SCROLLCONTAINER_H
