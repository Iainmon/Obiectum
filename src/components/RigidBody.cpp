#include <iostream>
#include "../Obiectum.hpp"
#include "Components.hpp"

using namespace std;
using namespace obiectum;
using namespace components;
using namespace physics;


void RigidBody::Setup(void)
{
    transform = gameObject->GetComponent<Transform>();
}

void RigidBody::Update(void)
{
    //Vector2D force = Vector2D(0, mass * -9.81);
    //Vector2D acceleration = Vector2D(force.x / mass, force.y / mass);
    Vector2D acceleration = Vector2D(0, (mass * 9.81) / mass);
    transform->velocity += acceleration * deltaTime;
    transform->position += transform->velocity * deltaTime;
}