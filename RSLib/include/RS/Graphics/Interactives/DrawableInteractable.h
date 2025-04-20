//
// Created by ChiroYuki on 14/04/2025.
//

#ifndef WMG_DRAWABLEINTERACTABLE_H
#define WMG_DRAWABLEINTERACTABLE_H


#include "RS/Core/Events/Event.h"
#include "RS/Graphics/Containers/CompositeDrawable.h"

class DrawableInteractable : public CompositeDrawable {
public:
    virtual void onEvent(const Event& event) = 0;
};


#endif //WMG_DRAWABLEINTERACTABLE_H
