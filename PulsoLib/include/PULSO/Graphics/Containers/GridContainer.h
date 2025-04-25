//
// Created by ChiroYuki on 12/04/2025.
//

#ifndef WMG_GRIDCONTAINER_H
#define WMG_GRIDCONTAINER_H

#include "Container.h"
#include <vector>

class GridContainer : public Container {
public:
    explicit GridContainer(int rows, int columns, float spacing = 0.0f);

    void setRows(int newRows);
    void setColumns(int newColumns);
    void setSpacing(float newSpacing);

    void updateLayout() override;

private:
    int rows;
    int columns;
    float spacing;
};

#endif //WMG_GRIDCONTAINER_H
