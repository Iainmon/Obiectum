#pragma once


namespace obiectum {
    namespace physics {

        using namespace std;

        struct Color {

            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
            
            Color();

            Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
            Color(uint8_t _r, uint8_t _g, uint8_t _b);
            Color(int _r, int _g, int _b, int _a);

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
    }
}