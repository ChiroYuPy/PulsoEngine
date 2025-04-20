//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_DRAWINFO_H
#define WMG_DRAWINFO_H


#include "RS/Math/Vector2.h"
#include "RS/Math/BoundingBox.h"

class DrawInfo {
public:
    DrawInfo();

    void setPosition(Vector2 newPosition);
    [[nodiscard]] const Vector2& getPosition() const;

    [[nodiscard]] const BoundingBox &getBoundingBox() const;

    DrawInfo operator+(const DrawInfo& other) const;

private:
    Vector2 position;

    BoundingBox boundingBox;
};


#endif //WMG_DRAWINFO_H
