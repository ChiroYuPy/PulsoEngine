//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_TEXT_H
#define WMG_TEXT_H


#include "Shape.h"

class Text : public Shape {
public:
    explicit Text(std::string& text);

    void draw() override;

    std::string text;
};


#endif //WMG_TEXT_H
