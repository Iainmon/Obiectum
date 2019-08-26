#include <iostream>
#include "../Obiectum.hpp"
#include "Components.hpp"

using namespace std;
using namespace obiectum;
using namespace components;
using namespace collidables;
using namespace physics;


vector<Collidable*> Collidable::collidables = vector<Collidable*>();

void Collidable::Setup(void) {
    Collidable::collidables.push_back(this);
}

void Collidable::Update(void) {
    
}
