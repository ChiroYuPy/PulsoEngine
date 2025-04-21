//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_SEARCHCONTAINER_H
#define WMG_SEARCHCONTAINER_H


#include "Container.h"
#include "IFilterable.h"

class SearchContainer : public Container {
    std::string searchTerm;

public:
    void updateLayout() override;

    void setSearchTerm(const std::string& term);

    void applyFilter();
};


#endif //WMG_SEARCHCONTAINER_H
