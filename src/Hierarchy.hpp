#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "GameObject.hpp"
#include "Component.hpp"

using namespace std;    

namespace obiectum {

    uint64_t micros();

    class Hierarchy {
        private:

        unsigned long long lastTime;

        static Hierarchy* hierarchy;

        void updateDeltaTime(void);

        public:

        Hierarchy();
        Hierarchy(int argc, char **argv);

        vector<GameObject *> gameObjects;

        void Add(GameObject* _gameObject);

        void AddObjects(vector<GameObject*> _gameObjects);

        static void setupAllGameObjects();
        static void updateAllGameObjects();

        static void mouseFunc(int button, int state, int x, int y);
        static void reshape(int x, int y);

        void RunMainLoop();

        #if defined(__APPLE__)
        static void APPLE_displayFunction();
        #endif
    };
}

