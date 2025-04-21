//
// Created by adrian on 21/04/25.
//

#ifndef DEBUGCONTAINER_H
#define DEBUGCONTAINER_H


#include "Container.h"


class DebugContainer : public Container {
    std::string searchTerm;

public:
    void updateLayout() override;

    void setSearchTerm(const std::string& term);

    void applyFilter();
};



#endif //DEBUGCONTAINER_H
