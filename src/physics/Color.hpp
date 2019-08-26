#pragma once

namespace obiectum
{
namespace physics
{

using namespace std;

struct Color
{

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color();

    //Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
    Color(uint8_t _r, uint8_t _g, uint8_t _b);
    Color(int _r, int _g, int _b, int _a);

    static Color ColorFromHSV(const uint8_t h, const uint8_t s, const uint8_t v);

    static const Color Red;
    static const Color Green;
    static const Color Blue;

    static const Color Yellow;
    static const Color Cyan;
    static const Color Magenta;

    static const Color White;
    static const Color Black;
    static const Color Grey;
};
class HSVColor
{
public:
    double h;
    double s;
    double v;

    HSVColor(double h, double s, double v);

    bool Equals(HSVColor HSVColor);
};
double Min(double a, double b);
double Max(double a, double b);
HSVColor RGBToHSV(Color rgb);
Color HSVColorToRGB(HSVColor hsv);
} // namespace physics
} // namespace obiectum