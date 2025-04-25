//
// Created by ChiroYuki on 09/04/2025.
//

#ifndef WMG_IFILTERABLE_H
#define WMG_IFILTERABLE_H


#include <vector>
#include <string>

class IFilterable {
public:
    virtual ~IFilterable() = default;

    virtual std::vector<std::string> getFilterTerms();

    void setFiltered(bool filtered);
    [[nodiscard]] bool isFiltered() const;

private:
    bool filtered = false;
};



#endif //WMG_IFILTERABLE_H
