#pragma once

#include <iostream>
#include <string>
#include <cmath>

namespace obiectum {
namespace physics {

struct Point;

struct Vector2D
{

    float x, y;

    Vector2D(float _x, float _y);
    Vector2D();
    Vector2D(const Point &_point);

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

    operator Point() const;

    std::string info();
};
} // namespace physics
} // namespace obiectum