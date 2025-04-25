//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_COMPOSITEDRAWABLE_H
#define WMG_COMPOSITEDRAWABLE_H


#include <vector>
#include "PULSO/Graphics/Drawable.h"

class CompositeDrawable : public Drawable {
public:
    CompositeDrawable() = default;

    void add(std::shared_ptr<Drawable> drawable);

    void setRenderer(IRenderer* newRenderer) override;

    void clear();

    void draw() override;

    void update(Time deltaTime) override;

protected:
    std::vector<std::shared_ptr<Drawable>> children;
};


#endif //WMG_COMPOSITEDRAWABLE_H
