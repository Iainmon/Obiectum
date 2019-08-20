#include <iostream>
#include <string>
#include <vector>

#include "Component.hpp"
#include "GameObject.hpp"

using namespace std;
using namespace obiectum;

const char *AssignmentException::what() const throw()
{
    return "Same instance of a Component cannot be assigned to more than one GameObject";
}

/*
    Constructors
*/
Component::Component()
{
    isAssigned = false;
}

Component::Component(GameObject *_gameObject)
{
    gameObject = _gameObject;
    isAssigned = true;
}

/*
    Assigns the Component's parent GameObject
*/
void Component::Assign(GameObject *_gameObject)
{
    if (!isAssigned)
    {
        gameObject = _gameObject;
        isAssigned = true;
    }
    else
    {
        throw AssignmentException();
    }
}

/*
    This function is called before the first draw time.
*/
void Component::Setup(void)
{
}

/*
    This function is called whenever the screen is ready to update.
*/
void Component::Update(void)
{
}

/*
    Initializes all static variables for this class.
*/
float Component::deltaTime = 0.0f;
