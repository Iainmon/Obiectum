#include <iostream>
#include <vector>
#include <chrono>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#include <GL/glut.h>
#endif

#include "GameObject.hpp"
#include "Component.hpp"

#include "Hierarchy.hpp"

using namespace std;
using namespace obiectum;

uint64_t obiectum::micros()
{
    uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                                                                            now()
                                                                                .time_since_epoch())
                    .count();
    return us;
}

void Hierarchy::updateDeltaTime(void) {
    const unsigned long long now = micros();
    Component::deltaTime = ((float)((now - lastTime) / 1000000.0f));
    lastTime = now;
}

Hierarchy* Hierarchy::hierarchy = nullptr;

Hierarchy::Hierarchy() {
    lastTime = micros();
    hierarchy = this;
}

void Hierarchy::Add(GameObject* _gameObject) {
    gameObjects.push_back(_gameObject);
}

void Hierarchy::AddObjects(vector<GameObject*> _gameObjects)
{
    gameObjects.insert(_gameObjects.end(), _gameObjects.begin(), _gameObjects.end());
}

void Hierarchy::setupAllGameObjects() {
    for (unsigned int i = 0; i < hierarchy->gameObjects.size(); i++) {
        hierarchy->gameObjects[i]->setupComponents();
    }
}

void Hierarchy::updateAllGameObjects() {

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    //glutSetOption(GLUT_MULTISAMPLE, 8);
    glEnable(GL_MULTISAMPLE);

    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);

    hierarchy->updateDeltaTime();

    for (unsigned int i = 0; i < hierarchy->gameObjects.size(); i++) {
        hierarchy->gameObjects[i]->updateComponents();
    }

    glFlush();
}

void Hierarchy::RunMainLoop() {

    #if defined(__APPLE__)
    glutDisplayFunc(Hierarchy::APPLE_displayFunction);
    #endif
    glutIdleFunc(Hierarchy::updateAllGameObjects);

    setupAllGameObjects();

    glutMainLoop();

}
#if defined(__APPLE__)
void Hierarchy::APPLE_displayFunction() {}
#endif