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

    void setColor(Color newColor);
    [[nodiscard]] Color getColor() const;

protected:
    Color color;
};



#endif //DEBUGCONTAINER_H
