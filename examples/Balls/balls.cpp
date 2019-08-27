#include <cmath>
#include <iostream>

#include <Obiectum.hpp>

#include "RandomShrink.cpp"
#include "TrippyColors.cpp"
#include "WallBounce.cpp"

using namespace std;
using namespace obiectum;
using namespace physics;

class Spawner : public Component {
  public:
    Hierarchy *hierarchyRefference;
    GameObject *currentObject;

    void Setup(void) override {}

    void Update(void) override {

        // Checks if the mouse was clicked
        if (GameObject::mouseClicked && currentObject == nullptr) {

            // Creates a new GameObject, and assigns it's components.
            GameObject *go = new GameObject();
            go->AddComponent(new components::Transform());
            go->AddComponent(new components::RigidBody());
            go->AddComponent(new components::drawables::Circle());
            go->AddComponent(new components::drawables::ForceLines());
            go->AddComponent(new TrippyColors());
            go->AddComponent(new WallBounce());
            go->AddComponent(new RandomShrink());

            // Runs the setup function for all of the components
            go->setupComponents();

            // Configuring the Transform component
            components::Transform *transform = go->GetComponent<components::Transform>();
            transform->position = Vector2D(GameObject::mouseLocation.x, GameObject::mouseLocation.y);
            transform->velocity = Vector2D(0, 0);

            // Configuring the RigidBody component
            components::RigidBody *rb = go->GetComponent<components::RigidBody>();
            rb->mass = 100;

            // Configuring the Circle Drawable component
            components::drawables::Circle *circle = go->GetComponent<components::drawables::Circle>();
            circle->raidius = 1.0f;

            // Adds the component to the Hierarchy instance
            hierarchyRefference->Add(go);

            // Saves a reference to the GameObject to modify the velocity vector later
            currentObject = go;
        }

        // If the user has released left-click
        if (GameObject::mouseUp && currentObject != nullptr) {
            // Gets the reference of the saved GameObject's Transform component
            components::Transform *transform = currentObject->GetComponent<components::Transform>();
            // Sets the velocity to the direction of where the left-click was released
            transform->velocity = Vector2D(GameObject::mouseLocation.x, GameObject::mouseLocation.y) - transform->position;
            // Forgets the reference of the modified GameObject
            currentObject = nullptr;
        }
    }

    void SetHierarchyRefference(Hierarchy *_hierarchyRefference) {
        // Saves reference to the Hierarchy
        hierarchyRefference = _hierarchyRefference;
    }
};

int main(int argc, char **argv) {

    // Creates a Hierarchy instance
    Hierarchy *h = new Hierarchy(argc, argv);

    // Creates a GameObject that will act as a static controller, and adds the Spawner component to it
    GameObject *gm2 = new GameObject();
    gm2->AddComponent(new Spawner());

    // Retrives the reference to the Spawner component, and passes the reference to the Hierarchy to the Spawner
    Spawner *spawner = gm2->GetComponent<Spawner>();
    spawner->SetHierarchyRefference(h);

    // Adds the GameObject's reference to the Hierarchy so that it can be called
    h->Add(gm2);

    // Starts the OpenGL main loop
    h->RunMainLoop();

    return 0;
}