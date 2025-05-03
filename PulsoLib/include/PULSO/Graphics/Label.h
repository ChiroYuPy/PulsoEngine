//
// Created by ChiroYuki on 03/05/2025.
//

#ifndef WMG_LABEL_H
#define WMG_LABEL_H


#include "PULSO/Graphics/Shapes/Shape.h"

class Label : public Shape {
public:
    Label();

    void setText(const std::string& text);
    [[nodiscard]] const std::string& getText() const;

    void setFontSize(const unsigned int newFontSize);
    [[nodiscard]] unsigned int getFontSize() const;

    void onRender() override;

private:
    unsigned int fontSize;
    std::string text;
    sf::Font font;
};

#endif //WMG_LABEL_H
