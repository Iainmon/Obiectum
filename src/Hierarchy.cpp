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
#include "Physics.hpp"

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

Hierarchy::Hierarchy(int argc, char **argv) {
    lastTime = micros();
    hierarchy = this;
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Obiectum Drawables Example");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glClearColor(0,0,0,0);

}
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

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //glutSetOption(GLUT_MULTISAMPLE, 8);
    glEnable(GL_MULTISAMPLE);
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);


    hierarchy->updateDeltaTime();

    for (unsigned int i = 0; i < hierarchy->gameObjects.size(); i++) {
        hierarchy->gameObjects[i]->updateComponents();
    }

    glFlush();
}

void Hierarchy::mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        GameObject::mouseClicked = true;
        GameObject::mouseUp = false;
        GameObject::mouseLocation = physics::Point(x, y);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        GameObject::mouseClicked = false;
        GameObject::mouseUp = true;
        GameObject::mouseLocation = physics::Point(x, y);
	}
}

void Hierarchy::reshape(int x, int y) {
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}


void Hierarchy::RunMainLoop() {

    #if defined(__APPLE__)
    glutDisplayFunc(Hierarchy::APPLE_displayFunction);
    #endif
    glutIdleFunc(Hierarchy::updateAllGameObjects);

    glutMouseFunc(Hierarchy::mouseFunc);
    glutReshapeFunc(Hierarchy::reshape);

    setupAllGameObjects();

    glutMainLoop();

}
#if defined(__APPLE__)
void Hierarchy::APPLE_displayFunction() {}
#endif