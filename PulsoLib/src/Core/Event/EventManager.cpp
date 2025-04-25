//
// Created by adrian on 24/04/25.
//

#include "PULSO/Core/Event/EventManager.h"

void EventManager::addEvent(const Event& event) {
    events.push_back(event);
}

void EventManager::clearEvents() {
    events.clear();
}

const std::vector<Event>& EventManager::getEvents() const {
    return events;
}

void EventManager::setGameContext(GameContext *gameContext) {
    ctx = gameContext;
}