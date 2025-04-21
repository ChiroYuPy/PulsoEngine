//
// Created by ChiroYuki on 07/04/2025.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <memory>
#include <functional>
#include "RS/Core/Rendering/IRenderer.h"
#include "RS/Transform/Transformable.h"
#include "RS/Transform/AnimationTransform.h"
#include "DrawInfo.h"
#include "RS/Math/Anchor.h"

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
    virtual ~Drawable();

    static int getTotalCount();

    virtual void setRenderer(IRenderer* newRenderer);

    virtual void draw();

    void update(Time deltaTime) override;

    virtual void updateTransform();

    virtual void setPosition(const Vector2& pos);
    [[nodiscard]] const Vector2& getPosition() const;

    virtual void setAnchor(const Anchor& newAnchor);
    [[nodiscard]] const Anchor& getAnchor() const;

    virtual void setSize(const Vector2& newSize);
    [[nodiscard]] const Vector2& getSize() const;

    virtual void setRelativeSizeAxes(const Axes& newRelativeSizeAxes);
    [[nodiscard]] const Axes& getRelativeSizeAxes() const;

    void moveTo(const Vector2& target, Time duration, const std::function<float(float)>& easingFunc) noexcept;

    void sizeTo(const Vector2 &target, Time duration, const std::function<float(float)> &easingFunc) noexcept;

    void setParent(Drawable* p);
    [[nodiscard]] Drawable* getParent() const;

    const DrawInfo& getDrawInfo() const;

protected:
    Vector2 relativePosition; // {float, float}
    Axes relativePositionAxes = Axes::None;

    Vector2 size; // {0.0f -> inf, 0.0f -> inf}
    Axes relativeSizeAxes = Axes::None;

    Anchor origin = Anchor::None; // {0.0f -> 1.0f, 0.0f -> 1.0f}
    Anchor anchor = Anchor::None; // {0.0f -> 1.0f, 0.0f -> 1.0f}

    DrawInfo drawInfo; // calculated parameter to draw a shape
    Drawable* parent = nullptr; // parent container, optional

    IRenderer* renderer = nullptr;

private:
    static int totalCount;
};



#endif //DRAWABLE_H
