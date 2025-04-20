//
// Created by ChiroYuki on 09/04/2025.
//

#include "RS/Graphics/Containers/IFilterable.h"

std::vector<std::string> IFilterable::getFilterTerms() {
    return {};
}

void IFilterable::setFiltered(bool isFiltered) {
    filtered = isFiltered;
}

bool IFilterable::isFiltered() const {
    return filtered;
}
