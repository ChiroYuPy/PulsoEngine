//
// Created by adrian on 26/04/25.
//

#ifndef ROTATION_H
#define ROTATION_H



class Rotation {
public:
    Rotation();

    explicit Rotation(float angle);

    [[nodiscard]] float getAngle() const;

    void setAngle(float angle);

    void addRotation(float deltaAngle);

    Rotation operator+(const Rotation& other) const;

    Rotation& operator+=(const Rotation& other);

    Rotation operator-(const Rotation& other) const;

    Rotation& operator-=(const Rotation& other);

    bool operator==(const Rotation& other) const;

    bool operator!=(const Rotation& other) const;

private:
    float angleDegrees;

    static float normalizeAngle(float angle);
};

#endif //ROTATION_H
