#include <iostream>

#include <Obiectum.hpp>


using namespace std;
using namespace obiectum;
using namespace physics;


class Triangle: public components::Drawable {
    public:

        Tuple<Vector2D, Vector2D, Vector2D> offset;

        void Setup(void) {
            Drawable::Setup();
        }
        void Draw(void) {

        }

        void SetOffset(Tuple<Vector2D, Vector2D, Vector2D> _offset) {
            offset = _offset;
        }
};


int main(int argc, char **argv)
{

    Hierarchy* h = new Hierarchy(argc, argv);
    
    GameObject* gm1 = new GameObject();
        gm1->AddComponent(new components::Transform());
        gm1->AddComponent(new components::RigidBody());
        gm1->AddComponent(new components::drawables::Circle());
        gm1->AddComponent(new components::drawables::ForceLines());

        components::Transform* transform = gm1->GetComponent<components::Transform>();
        transform->position = Vector2D(100, 1);
        transform->velocity = Vector2D(0, 0);
        cout << transform->position.magnitude() << endl;

        components::RigidBody* rb = gm1->GetComponent<components::RigidBody>();
        rb->mass = 100;

    h->Add(gm1);

    h->RunMainLoop();

    return 0;
}