//
// Created by ChiroYuki on 09/04/2025.
//

#include "RS/Graphics/Containers/SearchContainer.h"

void SearchContainer::setSearchTerm(const std::string &term) {
    searchTerm = term;
    applyFilter();
}

void SearchContainer::applyFilter() {
    for (const auto& child : children) {
        auto* filterable = dynamic_cast<IFilterable*>(child.get());
        if (filterable) {
            bool match = false;
            for (const auto& keyword : filterable->getFilterTerms()) {
                if (keyword.find(searchTerm) != std::string::npos) {
                    match = true;
                    break;
                }
            }
            filterable->setFiltered(!match);
        }
    }
}

void SearchContainer::updateLayout() {

}
