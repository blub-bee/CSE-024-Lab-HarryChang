#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float base, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->base = base;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    if (isSelected) {
        glColor3f(1.0f, 1.0f, 0.0f);
        glLineWidth(2.5f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x - base / 2, y - height / 2);
            glVertex2f(x, y + height / 2);
            glVertex2f(x + base / 2, y - height / 2);
        glEnd();
    }

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - base / 2, y - height / 2);
        glVertex2f(x, y + height / 2);
        glVertex2f(x + base / 2, y - height / 2);
    glEnd();
}


bool Triangle::contains(float mx, float my){
    float x1 = x - base / 2;
    float y1 = y - height / 2;
    float x2 = x + base / 2;
    float y2 = y - height / 2;
    float x3 = x;
    float y3 = y + height / 2;

    float denominator = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
    float a = ((y2 - y3)*(mx - x3) + (x3 - x2)*(my - y3)) / denominator;
    float b = ((y3 - y1)*(mx - x3) + (x1 - x3)*(my - y3)) / denominator;
    float c = 1.0f - a - b;

    return a >= 0 && b >= 0 && c >= 0;
}

void Triangle::move(float dx, float dy){
    x += dx;
    y += dy;
}

void Triangle::resize(float factor){
    base *= factor;
    height *= factor;
}

void Triangle::setColor(float newR, float newG, float newB){
    r = newR;
    g = newG;
    b = newB;
}

void Triangle::getColor(float& rOut, float& gOut, float& bOut) const{
    rOut = r;
    gOut = g;
    bOut = b;
}