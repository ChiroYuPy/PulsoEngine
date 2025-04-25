//
// Created by adrian on 24/04/25.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <functional>
#include <unordered_map>
#include <vector>
#include <PULSO/Graphics/Drawable.h>

#include "PULSO/Core/GameContext.h"

#include "Event.h"


class EventManager {
public:
    void addEvent(const Event &event);

    void clearEvents();

    const std::vector<Event> &getEvents() const;

    void setGameContext(GameContext *gameContext);

protected:
    GameContext* ctx = nullptr;

private:
    std::vector<Event> events;
};



#endif //EVENTMANAGER_H
