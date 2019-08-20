#include <iostream>
#include <string>
#include <cmath>

#include "Vector.hpp"

using namespace obiectum;
using namespace physics;

Vector2D::Vector2D(float _x, float _y)
{
    x = _x;
    y = _y;
}
Vector2D::Vector2D()
{
    x = 0.0f;
    y = 0.0f;
}

float Vector2D::magnitude() const
{
    return sqrt((x * x) + (y * y));
}

Vector2D Vector2D::normalized()
{
    float mag = magnitude();
    float nx = x / mag;
    float ny = y / mag;

    return Vector2D(nx, ny);
}

void Vector2D::flip()
{
    const float tmpY = y;
    y = x;
    x = tmpY;
}

Vector2D& Vector2D::operator+=(const Vector2D &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector2D Vector2D::operator-()
{
    x = -x;
    y = -y;
    return Vector2D(x, y);
}
Vector2D Vector2D::operator+()
{
    x = +x;
    y = +y;
    return Vector2D(x, y);
}

Vector2D Vector2D::operator+(const Vector2D &rhs)
{
    return Vector2D(this->x + rhs.x, this->y + rhs.y);
}
Vector2D Vector2D::operator-(const Vector2D &rhs)
{
    return Vector2D(this->x - rhs.x, this->y - rhs.y);
}

Vector2D Vector2D::operator+(const float rhs)
{
    return Vector2D(this->x + rhs, this->y + rhs);
}
Vector2D Vector2D::operator*(const float rhs)
{
    return Vector2D(this->x * rhs, this->y * rhs);
}
Vector2D Vector2D::operator/(const float rhs)
{
    return Vector2D(this->x / rhs, this->y / rhs);
}
bool Vector2D::operator<(const Vector2D &rhs)
{
    if (magnitude() < rhs.magnitude())
    {
        return true;
    }
    return false;
}
bool Vector2D::operator>(const Vector2D &rhs)
{
    if (magnitude() > rhs.magnitude())
    {
        return true;
    }
    return false;
}
bool Vector2D::operator<=(const Vector2D &rhs)
{
    if (magnitude() <= rhs.magnitude())
    {
        return true;
    }
    return false;
}
bool Vector2D::operator>=(const Vector2D &rhs)
{
    if (magnitude() >= rhs.magnitude())
    {
        return true;
    }
    return false;
}

void Vector2D::operator=(const Vector2D &rhs)
{
    x = rhs.x;
    y = rhs.y;
}

std::string Vector2D::info()
{
    return "X : " + std::to_string(x) + " Y : " + std::to_string(y) + " Magnitude : " + std::to_string(magnitude());

}
// std::ostream& operator<<(std::ostream& output, const Vector2D& rhs)
// {
//     output << "X : " << rhs.x << " Y : " << rhs.y << " Magnitude : " << rhs.magnitude();
//     return output;
// }