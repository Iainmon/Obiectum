#include <iostream>
#include "../Obiectum.hpp"
#include "Components.hpp"

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#include <GL/glut.h>
#endif

using namespace std;
using namespace obiectum;
using namespace components;
using namespace physics;

bool Drawable::isSetup = false;

void Drawable::hrect(const float x1, const float y1, const float x2, const float y2, const Color color = Color::Cyan)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}
void Drawable::rect(const float x1, const float y1, const float x2, const float y2, const Color color = Color::Cyan)
{
    glColor3f(color.r, color.g, color.b);
    glRectf(x1, y1, x2, y2);
}
void Drawable::line(const float x1, const float y1, const float x2, const float y2, const Color color = Color::Cyan) {
    glBegin(GL_LINES);
        glColor3i(color.r, color.g, color.b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}
void Drawable::fcircle(float x, float y, float radius, const Color color = Color::Cyan, const int triangles = 20)
{
    int i;

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(color.r, color.g, color.b, color.a);

    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangles; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangles)),
            y + (radius * sin(i * twicePi / triangles)));
    }
    glEnd();
}

void Drawable::circle(float cx, float cy, float r, const Color color = Color::Cyan, int num_segments = 10)
{

    float theta = 2 * 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta); //calculate the tangential factor

    float radial_factor = cosf(theta); //calculate the radial factor

    float x = r; //we start at angle = 0

    float y = 0;

    glBegin(GL_LINE_LOOP);
    glColor3f(color.r, color.g, color.b);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy); //output vertex

        //calculate the tangential vector
        //remember, the radial vector is (x, y)
        //to get the tangential vector we flip those coordinates and negate one of them

        float tx = -y;
        float ty = x;

        //add the tangential vector

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void Drawable::ChangeColor(const Color _color) {
    this->color = _color;
}

Vector2D Drawable::getScreenSize()
{
    return physics::Vector2D(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void Drawable::Setup(void)
{
    transform = gameObject->GetComponent<Transform>();
}

void Drawable::Update(void)
{
    Draw();
}

using namespace drawables;

void Circle::Setup(void)
{
    detail = 100;
    raidius = 200;
    //color = Color::Blue;
    Drawable::Setup();
}

void Circle::Draw(void)
{
    fcircle(transform->position.x, transform->position.y, raidius, color, detail);
}

void Square::Setup(void)
{
    offset = Vector2D(0, 0);
    diameter = 200.0f;
    color = Color::Blue;
    Drawable::Setup();
}
void Square::Draw(void)
{
    const float halfDiameter = diameter / 2;
    rect(transform->position.x - halfDiameter + offset.x, transform->position.y - halfDiameter + offset.y, transform->position.x + halfDiameter + offset.x, transform->position.y + halfDiameter + offset.y);
}
void Square::Center(const Vector2D _offset = Vector2D(0, 0))
{
    offset = _offset;
}

void Line::Setup(void)
{
    color = Color::Red;
    Drawable::Setup();
}
// void Line::Draw(void) {
//     line(transform->position.x + startingOffset.x, transform->position.y + startingOffset.y, transform->position.x + endingOffset.x, transform->position.y + endingOffset.y, color);
// }
void Line::Draw(void) {
    line(startingOffset.x, startingOffset.y, endingOffset.x, endingOffset.y, color);
}

void Line::DrawLine(const float x1, const float y1, const float x2, const float y2, const Color color = Color::Cyan) {
    glBegin(GL_LINES);
        glColor3i(color.r, color.g, color.b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void ForceLines::Setup(void) {
    Drawable::Setup();
}
void ForceLines::Draw(void) {
    line(transform->position.x, transform->position.y, transform->position.x + transform->velocity.x, transform->position.y, Color::Blue);
    line(transform->position.x, transform->position.y, transform->position.x, transform->position.y + transform->velocity.y, Color::Green);
}