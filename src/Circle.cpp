#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b) {
    this->x = x; 
    this->y = y; 
    radius = 0.1;
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void drawHighlight(float x, float y, float radius = 0.05f) {
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(2.5f);
    float inc = 3.14159f / 32;
    glBegin(GL_LINE_LOOP);
    for (float angle = 0; angle < 2 * 3.14159f; angle += inc) {
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void Circle::draw() {
    if (isSelected) {
        drawHighlight(x, y, radius + 0.02f);
    }

    glColor3f(r, g, b);
    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
    for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
        glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
    }
    glEnd();
}


bool Circle::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    return (dx * dx + dy * dy) <= (radius * radius);
}

void Circle::move(float dx, float dy){
    x += dx;
    y += dy;
}

void Circle::resize(float factor){
    radius *= factor;
}

void Circle::setColor(float newR, float newG, float newB){
    r = newR;
    g = newG;
    b = newB;
}

void Circle::getColor(float& rOut, float& gOut, float& bOut) const{
    rOut = r;
    gOut = g;
    bOut = b;
}