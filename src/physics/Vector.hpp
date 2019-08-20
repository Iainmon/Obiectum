#pragma once

#include <iostream>
#include <string>
#include <cmath>

namespace obiectum {
namespace physics {

struct Vector2D
{

    float x, y;

    Vector2D(float _x, float _y);
    Vector2D();

    float magnitude() const;

    Vector2D normalized();

    void flip();

    Vector2D &operator+=(const Vector2D &rhs);
    Vector2D &operator-=(const Vector2D &rhs);

    Vector2D operator-();
    Vector2D operator+();

    Vector2D operator+(const Vector2D &rhs);
    Vector2D operator-(const Vector2D &rhs);

    // Arythmatical Operators
    Vector2D operator+(const float rhs);
    Vector2D operator*(const float rhs);
    Vector2D operator/(const float rhs);

    // Comparative Operators
    bool operator<(const Vector2D &rhs);
    bool operator>(const Vector2D &rhs);
    bool operator<=(const Vector2D &rhs);
    bool operator>=(const Vector2D &rhs);

    void operator=(const Vector2D &rhs);

    std::string info();
};
} // namespace physics
} // namespace obiectum