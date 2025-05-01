//
// Created by ChiroYuki on 09/04/2025.
//

#include "PULSO/Graphics/Containers/SearchContainer.h"

void SearchContainer::setSearchTerm(const std::string &term) {
    searchTerm = term;
    applyFilter();
}

void SearchContainer::applyFilter() const {
    for (const auto& child : children) {
        if (auto* filterable = child.get()) {
            bool match = false;
            if (child) {
                match = true;
                break;
            }
        }
    }
}

void SearchContainer::updateLayout() {

}
