//
// Created by ChiroYuki on 07/04/2025.
//

#include "PULSO/Graphics/Drawable.h"

#include <PULSO/Core/Color.h>

Drawable::Drawable() : relativePosition(0, 0), relativeSize(1.f, 1.f) {
    Drawable::setOrigin(Anchor::Center);
}

Drawable::~Drawable() {

}

void Drawable::setRenderer(Renderer* newRenderer) {
    renderer = newRenderer;
}

void Drawable::draw() {

}

void Drawable::update(const Time deltaTime) {
    Transformable::update(deltaTime);
    updateTransform();
}

void Drawable::onEvent(const Event& event) {

}

void Drawable::updateTransform() {
    absolutePosition = relativePosition;

    absoluteSize = relativeSize;

    if (parent) {
        absolutePosition += parent->getAbsolutePosition();
        const Vector2 parentSize = parent->getSize(); // parent size

        // size or relativeSizeAxes processing
        if (hasX(relativeSizeAxes)) absoluteSize.x = parentSize.x * relativeSize.x;
        if (hasY(relativeSizeAxes)) absoluteSize.y = parentSize.y * relativeSize.y;
    }
}

void Drawable::setPosition(const Vector2 &newPosition) {
    relativePosition = newPosition;
}

const Vector2& Drawable::getPosition() const {
    return relativePosition;
}

const Vector2& Drawable::getAbsolutePosition() const {
    return absolutePosition;
}

Vector2 Drawable::getAbsoluteTopLeftCornerPosition() const {
    const Vector2 originVectorSized = {originVector.x * absoluteSize.x, originVector.y * absoluteSize.y};
    return absolutePosition - originVectorSized;
}

void Drawable::setSize(const Vector2 &newSize) {
    relativeSize = newSize;
}

const Vector2& Drawable::getSize() const {
    return relativeSize;
}

const Vector2& Drawable::getAbsoluteSize() const {
    return absoluteSize;
}

void Drawable::setOrigin(const Anchor &newOrigin) {
    origin = newOrigin;
    originVector = toVector2(origin);
}

const Anchor& Drawable::getOrigin() const {
    return origin;
}

const Vector2& Drawable::getOriginVector() const {
    return originVector;
}

void Drawable::setAnchor(const Anchor &newAnchor) {
    anchor = newAnchor;
    anchorVector = toVector2(anchor);
}

const Anchor& Drawable::getAnchor() const {
    return anchor;
}

const Vector2& Drawable::getAnchorVector() const {
    return anchorVector;
}

void Drawable::setRotation(const Rotation& newRotation) {
    rotation = newRotation;
}

const Rotation& Drawable::getRotation() const {
    return rotation;
}

void Drawable::setParent(Drawable *newParent) {
    parent = newParent;
}

Drawable* Drawable::getParent() const {
    return parent;
}

void Drawable::setRelativeSizeAxes(const Axes &newRelativeSizeAxes) {
    relativeSizeAxes = newRelativeSizeAxes;
}

const Axes &Drawable::getRelativeSizeAxes() const {
    return relativeSizeAxes;
}

void Drawable::moveTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept {
    auto animation = std::make_unique<AnimationTransform<Vector2>>(&relativePosition, relativePosition, target, duration, easingFunc);
    addAnimation(std::move(animation));
}

void Drawable::sizeTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept {
    auto animation = std::make_unique<AnimationTransform<Vector2>>(&relativeSize, relativeSize, target, duration, easingFunc);
    addAnimation(std::move(animation));
}

//TODO Interaction & Comportement utilisateur :
/*
 * - Ajouter onHover() : changement d’apparence ou déclenchement d’un événement si la souris est au-dessus.
 * - Ajouter onFocus() : gestion du focus clavier pour navigation ou actions contextuelles.
 * - Possibilité de définir des zones de hit personnalisées (hitbox ≠ drawbox).
 * - Ajout d’un système d’ID ou de nom pour référencer facilement certains éléments dans l’UI.
 */

//TODO Dessin et effets visuels :
/*
 * - Supporter l’opacité (alpha) et transitions d’alpha (fade in/out).
 * - Ajout d’un système de thème ou de style (bordures, ombres, arrondis…).
 * - Support d’un contour ou effet glow au survol ou focus.
 * - Ajout de visuels dynamiques (par ex : ripple effect sur clic).
 * - Ajout d’animations de transformation (rotation, scale, bounce).
 */

//TODO Layout et alignement :
/*
 * - Système de layout automatique : VerticalLayout, HorizontalLayout, GridLayout.
 * - Gestion du padding et du margin entre enfants.
 * - Support pour un "fill parent" ou "auto-size to content".
 * - Positionnement absolu et relatif mélangé pour des cas complexes.
 */

//TODO Accessibilité et UX :
/*
 * - Navigation au clavier (Tab, flèches, Enter).
 * - Système de focus visuel et vocalisation pour l’accessibilité.
 * - Gestion des Tooltips (infobulles contextuelles).
 * - Support de touches raccourcies (shortcut keys).
 */

//TODO Organisation interne :
/*
 * - Ajout de `handleEvent(const Event&, Vec2 parentPos)` dans Drawable.
 * - Ajout d’un bool `hovered`, `focused`, `pressed` dans la classe.
 * - Délégation automatique des événements aux enfants dans une UI arborescente.
 * - Système de signal/slot (ou callbacks) pour interagir entre composants (comme Qt).
 */
