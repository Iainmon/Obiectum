#include <iostream>

#include "Color.hpp"

using namespace std;
using namespace obiectum;
using namespace physics;

Color::Color() {
    r = 255;
    g = 255;
    b = 255;
    a = 0;
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a = 255) {
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
Color::Color(uint8_t _r, uint8_t _g, uint8_t _b) {
    r = _r;
    g = _g;
    b = _b;
    a = 255;
}
Color::Color(int _r, int _g, int _b, int _a = 255) {
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

const Color Color::Red = Color(255, 0, 0);
const Color Color::Green = Color(0, 255, 0);
const Color Color::Blue = Color(0, 0, 255);

const Color Color::Yellow = Color(255, 255, 0);
const Color Color::Cyan = Color(0, 255, 255);
const Color Color::Magenta = Color(255, 0, 255);

const Color Color::White = Color(255, 255, 255);
const Color Color::Black = Color(0, 0, 0);
const Color Color::Grey = Color(255, 255, 255, 128);
