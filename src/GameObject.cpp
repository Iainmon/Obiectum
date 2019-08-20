#include <iostream>
#include <string>
#include <vector>

#include "GameObject.hpp"
#include "Component.hpp"

using namespace std;
using namespace obiectum;

const char * ComponentMissingException::what() const throw ()
{
    return "The component could not be found for this GameObject.";
}

GameObjectMetaData::GameObjectMetaData() {
    name = "Generic_GameObject";
    type = "GameObject";
}
GameObjectMetaData::GameObjectMetaData(const string _name) {
    name = _name;
    type = _name;
}
GameObjectMetaData::GameObjectMetaData(const string _name, const string _type) {
    name = _name;
    type = _type;
}

/*
    Constructors
*/
GameObject::GameObject() {
    GameObject::gameObjects.push_back(this);
}
GameObject::GameObject(const GameObjectMetaData _metaData) {
    GameObject::gameObjects.push_back(this);
    metaData = _metaData;
}
GameObject::GameObject(const string _name) {
    GameObject::gameObjects.push_back(this);
    metaData = GameObjectMetaData(_name);
}
GameObject::GameObject(const string _name, const string _type) {
    GameObject::gameObjects.push_back(this);
    metaData = GameObjectMetaData(_name, _type);
}
/*
    Static Assignment
*/
vector<GameObject*> GameObject::gameObjects = vector<GameObject*>();
/*
    Adds the new component to the array of components
*/
void GameObject::AddComponent(Component* _component) {
    _component->Assign(this);
    components.push_back(_component);
}

void GameObject::updateComponents() {
    for (int i = 0; i < components.size(); i++) {
        components[i]->Update();
    }
}
void GameObject::setupComponents() {
    for (int i = 0; i < components.size(); i++) {
        components[i]->Setup();
    }
}

/*
    Runtime Accessors
*/

GameObject* GameObjectByName(const string &name) {
    for (int i = 0; i < GameObject::gameObjects.size(); i++) {
        if (GameObject::gameObjects[i]->metaData.name == name) {
            return GameObject::gameObjects[i];
        }
    }
    return nullptr;
}
GameObject* GameObjectByType(const string &type) {
    for (int i = 0; i < GameObject::gameObjects.size(); i++) {
        if (GameObject::gameObjects[i]->metaData.type == type) {
            return GameObject::gameObjects[i];
        }
    }
    return nullptr;
}