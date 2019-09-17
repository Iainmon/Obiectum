#include <cmath>
#include <iostream>

#include <Obiectum.hpp>

using namespace std;
using namespace obiectum;
using namespace physics;

class TrippyColors : public Component {
  public:
    components::Transform *transform;

    Color *color;

    Color newColor;

    int colorSpeed = 1;

    void Setup(void) override {
        transform = gameObject->GetComponent<components::Transform>();

        color = &gameObject->GetComponent<components::drawables::Circle>()->color;

        newColor = Color(255, 0, 0);
    }
    void Update(void) override {
        CycleColors();

        *color = newColor;
    }
    void CycleColors(void) {
        HSVColor tempColor = RGBToHSV(newColor);
        tempColor.h = (int)(transform->position.y) % 360;
        newColor = HSVColorToRGB(tempColor);
    }
};