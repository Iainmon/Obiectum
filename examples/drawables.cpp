#include <iostream>
#include <cmath>

#include <Obiectum.hpp>

using namespace std;
using namespace obiectum;
using namespace physics;

class WallBounce : public Component
{
private:
    components::Transform *transform;
    int* raidius;

public:
    void Setup(void) override
    {
        transform = gameObject->GetComponent<components::Transform>();
        raidius = &gameObject->GetComponent<components::drawables::Circle>()->raidius;
    }
    void Update(void) override
    {

        const Vector2D screenSize = components::Drawable::getScreenSize();

        if (transform->position.x - (*raidius) < 0 || transform->position.x + (*raidius) > screenSize.x)
        {
            transform->velocity.x *= -1;
        }
        if (transform->position.y - (*raidius) < 0 || transform->position.y + (*raidius) > screenSize.y)
        {
            transform->velocity.y *= -1;
        }
    }
};

class LSDShifter : public Component
{
public:
    components::Transform *transform;

    Color *color;
    int* raidius;

    Color newColor;

    int colorSpeed = 1;

    void Setup(void) override
    {
        transform = gameObject->GetComponent<components::Transform>();

        color = &gameObject->GetComponent<components::drawables::Circle>()->color;

        raidius = &gameObject->GetComponent<components::drawables::Circle>()->raidius;

        newColor = Color(255, 0, 0);
    }
    void Update(void) override
    {
        CycleColors();

        color->r = newColor.r;
        color->g = newColor.g;
        color->b = newColor.b;

        *raidius = (int)PingPong(newColor.r, 100) + 10;
    }
    void CycleColors(void)
    {
        HSVColor tempColor = RGBToHSV(newColor);
        tempColor.h = (int)transform->position.y % 360;
        newColor = HSVColorToRGB(tempColor);
    }

    float PingPong(const float value, const float max)
    {
        if (value < 0)
        {
            return 0;
        }
        if (value <= max)
        {
            return value;
        }
        return max;
    }
};

class Spawner : public Component
{
public:
    Hierarchy *hierarchyRefference;
    GameObject *currentObject;
    components::drawables::Line *brush;

    void Setup(void) override
    {
        brush = new components::drawables::Line();
    }

    void Update(void) override
    {
        if (GameObject::mouseClicked && currentObject == nullptr)
        {

            GameObject *gm1 = new GameObject();
            gm1->AddComponent(new components::Transform());
            gm1->AddComponent(new components::RigidBody());
            gm1->AddComponent(new components::drawables::Circle());
            gm1->AddComponent(new LSDShifter());
            gm1->AddComponent(new WallBounce());
            gm1->AddComponent(brush);
            //gm1->AddComponent(new components::drawables::ForceLines());

            components::Transform *transform = gm1->GetComponent<components::Transform>();
            transform->position = Vector2D(GameObject::mouseLocation.x, GameObject::mouseLocation.y);
            transform->velocity = Vector2D(0, 0);

            components::RigidBody *rb = gm1->GetComponent<components::RigidBody>();
            rb->mass = 1;

            gm1->setupComponents();

            hierarchyRefference->Add(gm1);

            currentObject = gm1;
        }
        if (GameObject::mouseUp && currentObject != nullptr)
        {
            GameObject *gm1 = currentObject;
            components::Transform *transform = gm1->GetComponent<components::Transform>();
            transform->velocity = Vector2D(GameObject::mouseLocation.x, GameObject::mouseLocation.y) - transform->position;
            currentObject = nullptr;
        }
    }

    void SetHierarchyRefference(Hierarchy *_hierarchyRefference)
    {
        hierarchyRefference = _hierarchyRefference;
    }
};

int main(int argc, char **argv)
{

    Hierarchy *h = new Hierarchy(argc, argv);

    GameObject *gm1 = new GameObject();
    gm1->AddComponent(new components::Transform());
    gm1->AddComponent(new components::RigidBody());
    gm1->AddComponent(new components::drawables::Circle());
    gm1->AddComponent(new components::drawables::ForceLines());

    components::Transform *transform = gm1->GetComponent<components::Transform>();
    transform->position = Vector2D(100, 1);
    transform->velocity = Vector2D(0, 0);
    cout << transform->position.magnitude() << endl;

    components::RigidBody *rb = gm1->GetComponent<components::RigidBody>();
    rb->mass = 100;

    GameObject *gm2 = new GameObject();
    gm2->AddComponent(new Spawner);
    Spawner *spawner = gm2->GetComponent<Spawner>();
    spawner->SetHierarchyRefference(h);

    //h->Add(gm1);
    h->Add(gm2);

    h->RunMainLoop();

    return 0;
}