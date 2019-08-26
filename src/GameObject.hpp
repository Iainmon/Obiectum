#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

namespace obiectum {

    struct ComponentMissingException : public exception {
	    const char * what() const throw ();
    };

    struct GameObjectMetaData {
        string name;
        string type;
        
        GameObjectMetaData();
        GameObjectMetaData(const string _name);
        GameObjectMetaData(const string _name, const string _type);
    };

    class Component;
    namespace physics {
        struct Point;
    }

    class GameObject {
        private:

        vector<Component*> components;

        public:

        static vector<GameObject*> gameObjects;
        static bool mouseClicked;
        static bool mouseUp;
        static physics::Point mouseLocation;

        GameObjectMetaData metaData;

        /*
            Constructors
         */
        GameObject();
        GameObject(const GameObjectMetaData _metaData);
        GameObject(const string _name);
        GameObject(const string _name, const string _type);


        void AddComponent(Component* _component);

        template<class T>
        T* GetComponent() {
            for (int i = 0; i < components.size(); i++)
            {
                if (dynamic_cast<T*>(components[i]) != nullptr)
                {
                    return dynamic_cast<T*>(components[i]);
                }
            }
            throw ComponentMissingException();
        }

        void setupComponents();
        void updateComponents();

        /*
            Runtime Accessors
        */
        GameObject* GameObjectByName(const string name);
        GameObject* GameObjectByType(const string type);
    };
}
