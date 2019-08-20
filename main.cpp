#include <iostream>

#include <Obiectum.hpp>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#include <GL/glut.h>
#endif

//#include "../components/Transform.cpp"

using namespace std;
using namespace obiectum;
using namespace physics;

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("The Universe");

    Hierarchy* h = new Hierarchy();
    
    GameObject* gm1 = new GameObject();
        gm1->AddComponent(new components::Transform());
        gm1->AddComponent(new components::RigidBody());
        gm1->AddComponent(new components::drawables::Circle());

        components::Transform* transform = gm1->GetComponent<components::Transform>();
        transform->position = Vector2D(1, 1);
        transform->velocity = Vector2D(90, 90);
        cout << transform->position.magnitude() << endl;


    h->Add(gm1);

    //h->updateAllGameObjects();

    h->RunMainLoop();

    return 0;
}