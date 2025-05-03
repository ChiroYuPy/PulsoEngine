//
// Created by ChiroYuki on 03/05/2025.
//

#include "PULSO/Graphics/Label.h"

Label::Label() : fontSize(12) {
    font = sf::Font();
    font.loadFromFile(R"(C:\Users\ChiroYuki\CLionProjects\WMG\WMGame\ressources\Rubik-Bold.ttf)");
}

void Label::setText(const std::string &newText) {
    text = newText;
}

const std::string &Label::getText() const {
    return text;
}

void Label::draw() {
    Drawable::draw();
    sf::Text textSprite;
    textSprite.setString(text);
    textSprite.setCharacterSize(fontSize);
    textSprite.setFont(font);
    sf::FloatRect bounds = textSprite.getLocalBounds();
    relativeSize = Vector2(bounds.width, bounds.height);
    textSprite.setPosition(absolutePosition.x, absolutePosition.y);
    textSprite.setFillColor(sf::Color(color.toInteger()));
    textSprite.setOrigin(
            bounds.left + bounds.width * originVector.x,
            bounds.top + bounds.height * originVector.y
    );
    textSprite.setRotation(rotation.getAngle());
    if (renderer) renderer->draw(textSprite);
}

void Label::setFontSize(const unsigned int newFontSize) {
    fontSize = newFontSize;
}

unsigned int Label::getFontSize() const {
    return fontSize;
}
