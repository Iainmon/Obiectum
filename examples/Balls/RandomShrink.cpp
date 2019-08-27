#include <cmath>
#include <iostream>

#include <Obiectum.hpp>

using namespace std;
using namespace obiectum;
using namespace physics;

class RandomShrink : public Component {
  private:
    Color *color;
    float *radius;
    float *mass;

    float PingPong(const float value, const float max) {
        if (value < 0) {
            return 0;
        }
        if (value <= max) {
            return value;
        }
        return max;
    }

  public:
    void Setup(void) override {
        color = &gameObject->GetComponent<components::drawables::Circle>()->color;
        radius = &gameObject->GetComponent<components::drawables::Circle>()->raidius;
        mass = &gameObject->GetComponent<components::RigidBody>()->mass;
    }
    void Update(void) override {
        *radius = PingPong(color->g, 100) + 10;
        *mass = *radius;
    }
};