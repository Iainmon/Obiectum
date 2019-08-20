#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

namespace obiectum {

    struct AssignmentException : public exception {
	    const char * what() const throw ();
    };


    class GameObject;

    class Component {
        protected:

        GameObject* gameObject;
        bool isAssigned;

        public:

        static float deltaTime;
        
        Component();

        Component(GameObject* _gameObject);

        void Assign(GameObject* _gameObject);

        virtual void Setup(void);

        virtual void Update(void);
    };
}