#include <iostream>
#include <string>
#include <cmath>

#include "Vector.hpp"
#include "Point.hpp"

using namespace obiectum;
using namespace physics;

Point::Point(float _x, float _y)
{
    x = _x;
    y = _y;
}
Point::Point()
{
    x = 0.0f;
    y = 0.0f;
}
Point::Point(const Vector2D &_vector) {
    x = _vector.x;
    y = _vector.y;
}

float Point::distance(const Point &_point) const {
    const float dx = x - _point.x;
    const float dy = y - _point.y;
    return sqrt( (dx*dx) + (dy*dy) );
}



Point& Point::operator+=(const Point &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}
Point& Point::operator-=(const Point &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Point Point::operator-()
{
    x = -x;
    y = -y;
    return Point(x, y);
}
Point Point::operator+()
{
    x = +x;
    y = +y;
    return Point(x, y);
}

Point Point::operator+(const Point &rhs)
{
    return Point(this->x + rhs.x, this->y + rhs.y);
}
Point Point::operator-(const Point &rhs)
{
    return Point(this->x - rhs.x, this->y - rhs.y);
}

Point Point::operator+(const float rhs)
{
    return Point(this->x + rhs, this->y + rhs);
}
Point Point::operator*(const float rhs)
{
    return Point(this->x * rhs, this->y * rhs);
}
Point Point::operator/(const float rhs)
{
    return Point(this->x / rhs, this->y / rhs);
}

void Point::operator=(const Point &rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Point::operator Vector2D() const {
    return Vector2D(x, y);
}