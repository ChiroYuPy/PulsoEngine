//
// Created by ChiroYuki on 07/04/2025.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <memory>
#include <functional>
#include "PULSO/Core/Rendering/Renderer.h"
#include "PULSO/Transform/Transformable.h"
#include "PULSO/Transform/AnimationTransform.h"
#include "PULSO/Math/Rotation.h"
#include "PULSO/Math/Anchor.h"

struct Event;

enum class Axes {
    None = 0,
    X = 1 << 0,
    Y = 1 << 1,
    Both = X | Y
};

inline bool hasX(Axes axes) {
    return static_cast<int>(axes) & static_cast<int>(Axes::X);
}

inline bool hasY(Axes axes) {
    return static_cast<int>(axes) & static_cast<int>(Axes::Y);
}

class Drawable : public Transformable {
public:
    Drawable();
    virtual ~Drawable() = default;

    virtual void setRenderer(Renderer* newRenderer);

    virtual void draw();

    void debugDraw();

    void update(Time deltaTime) override;

    virtual void onEvent(const Event& event);

    virtual void updateTransform();

    virtual void setPosition(const Vector2& pos);
    [[nodiscard]] const Vector2 &getPosition() const;
    [[nodiscard]] const Vector2 &getAbsolutePosition() const;

    Vector2 getAbsoluteTopLeftCornerPosition() const;

    virtual void setSize(const Vector2& newSize);
    [[nodiscard]] const Vector2& getSize() const;
    [[nodiscard]] const Vector2& getAbsoluteSize() const;

    virtual void setOrigin(const Anchor& newOrigin);
    [[nodiscard]] const Anchor& getOrigin() const;
    [[nodiscard]] const Vector2& getOriginVector() const;

    virtual void setAnchor(const Anchor& newAnchor);
    [[nodiscard]] const Anchor& getAnchor() const;
    [[nodiscard]] const Vector2& getAnchorVector() const;

    virtual void setRotation(const Rotation& newRotation);
    [[nodiscard]] const Rotation& getRotation() const;

    virtual void setRelativeSizeAxes(const Axes& newRelativeSizeAxes);
    [[nodiscard]] const Axes& getRelativeSizeAxes() const;

    void moveTo(const Vector2& target, Time duration, const std::function<float(float)>& easingFunc) noexcept;

    void sizeTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept;

    void setParent(Drawable* p);
    [[nodiscard]] Drawable* getParent() const;

protected:
    Vector2 relativePosition; // {float, float}
    Vector2 absolutePosition; // {float, float}

    Vector2 relativeSize; // {0.0f -> inf, 0.0f -> inf}
    Vector2 absoluteSize; // {0.0f -> inf, 0.0f -> inf}

    Rotation rotation;

    Axes relativeSizeAxes = Axes::None;

    Anchor origin = Anchor::Custom; // {0.0f -> 1.0f, 0.0f -> 1.0f}
    Anchor anchor = Anchor::Custom; // {0.0f -> 1.0f, 0.0f -> 1.0f}

    Vector2 originVector = {};
    Vector2 anchorVector = {};

    Drawable* parent = nullptr; // parent container, optional

    Renderer* renderer = nullptr;
};



#endif //DRAWABLE_H
