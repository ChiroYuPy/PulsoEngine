//
// Created by ChiroYuki on 10/04/2025.
//

#include "RS/Graphics/Shapes/Text.h"

Text::Text(std::string& text) : text(text) {
}

void Text::draw() {
    Drawable::draw();
}
