#include <cmath>
#include <iostream>

#include <Obiectum.hpp>

using namespace std;
using namespace obiectum;
using namespace physics;

class WallBounce : public Component {
  private:
    components::Transform *transform;
    float *raidius;

  public:
    void Setup(void) override {
        transform = gameObject->GetComponent<components::Transform>();
        raidius = &gameObject->GetComponent<components::drawables::Circle>()->raidius;
    }
    void Update(void) override {

        const Vector2D screenSize = components::Drawable::getScreenSize();

        if (transform->position.x - (*raidius) <= 0 || transform->position.x + (*raidius) >= screenSize.x) {
            transform->velocity.x *= -1;
            ClampCoordinate(&transform->position.x, transform->velocity.x, screenSize.x);
        }
        if (transform->position.y - (*raidius) <= 0 || transform->position.y + (*raidius) >= screenSize.y) {
            transform->velocity.y *= -1;
            ClampCoordinate(&transform->position.y, transform->velocity.y, screenSize.y);
        }
    }
    
    void ClampCoordinate(float *axis, const float velocity, const float screenAxisLength) {
        if (velocity > 0) {
            *axis = *raidius + 1;
        } else {
            *axis = screenAxisLength - *raidius - 1;
        }
    }
};