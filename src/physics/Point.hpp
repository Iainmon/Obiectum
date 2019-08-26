#pragma once

#include <iostream>
#include <string>
#include <cmath>

namespace obiectum {
namespace physics {

struct Vector2D;

struct Point
{

    float x, y;

    Point(float _x, float _y);
    Point();
    Point(const Vector2D &_vector);

    float distance(const Point &_point) const;

    Point &operator+=(const Point &rhs);
    Point &operator-=(const Point &rhs);

    Point operator-();
    Point operator+();

    Point operator+(const Point &rhs);
    Point operator-(const Point &rhs);

    // Arythmatical Operators
    Point operator+(const float rhs);
    Point operator*(const float rhs);
    Point operator/(const float rhs);

    void operator=(const Point &rhs);

    operator Vector2D() const;

};
} // namespace physics
} // namespace obiectum