//
// Created by adrian on 21/04/25.
//

#ifndef DEBUGCONTAINER_H
#define DEBUGCONTAINER_H


#include "Container.h"


class DebugContainer : public Container {
public:
    DebugContainer();

    void draw() override;

    void setColor(unsigned int newColor);
    [[nodiscard]] unsigned int getColor() const;

protected:
    unsigned int color;
};



#endif //DEBUGCONTAINER_H
