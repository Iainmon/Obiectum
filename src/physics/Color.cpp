#include <iostream>
#include <cmath>

#include "Color.hpp"

using namespace std;
using namespace obiectum;
using namespace physics;

Color::Color()
{
    r = 255;
    g = 255;
    b = 255;
    a = 0;
}

// Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a = 255)
// {
//     r = _r;
//     g = _g;
//     b = _b;
//     a = _a;
// }
Color::Color(uint8_t _r, uint8_t _g, uint8_t _b)
{
    r = _r;
    g = _g;
    b = _b;
    a = 255;
}
Color::Color(int _r, int _g, int _b, int _a = 255)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
// Color::Color(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255)
// {
//     r = _r;
//     g = _g;
//     b = _b;
//     a = _a;
// }

const Color Color::Red = Color(255, 0, 0);
const Color Color::Green = Color(0, 255, 0);
const Color Color::Blue = Color(0, 0, 255);

const Color Color::Yellow = Color(255, 255, 0);
const Color Color::Cyan = Color(0, 255, 255);
const Color Color::Magenta = Color(255, 0, 255);

const Color Color::White = Color(255, 255, 255);
const Color Color::Black = Color(0, 0, 0);
const Color Color::Grey = Color(255, 255, 255, 128);

double physics::Min(double a, double b)
{
    return a <= b ? a : b;
}

double physics::Max(double a, double b)
{
    return a >= b ? a : b;
}

HSVColor::HSVColor(double h, double s, double v)
{
    h = h;
    s = s;
    v = v;
}

bool HSVColor::Equals(HSVColor HSVColor)
{
    return (h == HSVColor.h) && (s == HSVColor.s) && (v == HSVColor.v);
}

HSVColor physics::RGBToHSV(Color rgb)
{
    HSVColor out = HSVColor(0, 0, 0);
    double min, max, delta;

    min = rgb.r < rgb.g ? rgb.r : rgb.g;
    min = min < rgb.b ? min : rgb.b;

    max = rgb.r > rgb.g ? rgb.r : rgb.g;
    max = max > rgb.b ? max : rgb.b;

    out.v = max; // v
    delta = max - min;
    if (delta < 0.00001)
    {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }
    if (max > 0.0)
    {                          // NOTE: if Max is == 0, this divide would cause a crash
        out.s = (delta / max); // s
    }
    else
    {
        // if max is 0, then r = g = b = 0
        // s = 0, v is undefined
        out.s = 0.0;
        out.h = NAN; // its now undefined
        return out;
    }
    if (rgb.r >= max)                   // > is bogus, just keeps compilor happy
        out.h = (rgb.g - rgb.b) / delta; // between yellow & magenta
    else if (rgb.g >= max)
        out.h = 2.0 + (rgb.b - rgb.r) / delta; // between cyan & yellow
    else
        out.h = 4.0 + (rgb.r - rgb.g) / delta; // between magenta & cyan

    out.h *= 60.0; // degrees

    if (out.h < 0.0)
        out.h += 360.0;

    return out;
}

Color physics::HSVColorToRGB(HSVColor hsv)
{
    double hh, p, q, t, ff;
    long i;
    Color out;

    if (hsv.s <= 0.0)
    { // < is bogus, just shuts up warnings
        out.r = hsv.v;
        out.g = hsv.v;
        out.b = hsv.v;
        return out;
    }
    hh = hsv.h;
    if (hh >= 360.0)
        hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = hsv.v * (1.0 - hsv.s);
    q = hsv.v * (1.0 - (hsv.s * ff));
    t = hsv.v * (1.0 - (hsv.s * (1.0 - ff)));

    switch (i)
    {
    case 0:
        out.r = hsv.v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = hsv.v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = hsv.v;
        out.b = t;
        break;

    case 3:
        out.r = p;
        out.g = q;
        out.b = hsv.v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = hsv.v;
        break;
    case 5:
    default:
        out.r = hsv.v;
        out.g = p;
        out.b = q;
        break;
    }
    return out;
}