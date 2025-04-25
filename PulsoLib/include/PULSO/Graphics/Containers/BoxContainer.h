//
// Created by adrian on 24/04/25.
//

#ifndef BOXCONTAINER_H
#define BOXCONTAINER_H


#include "Container.h"


enum Direction {
  Vertical,
  Horizontal
};


class BoxContainer : public Container {
public:
    explicit BoxContainer();

    void updateLayout() override;

private:
    Direction direction = Vertical;
    int spacing = 10;
};


#endif //BOXCONTAINER_H
