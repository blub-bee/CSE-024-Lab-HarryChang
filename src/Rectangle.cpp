#include "Rectangle.h"
#include <GL/freeglut.h>


Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    width = 0.2;
    height = 0.2;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    if (isSelected) {
        glColor3f(1.0, 1.0, 0.0);
        glLineWidth(2.5f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x - width / 2, y + height / 2);
            glVertex2f(x + width / 2, y + height / 2);
            glVertex2f(x + width / 2, y - height / 2);
            glVertex2f(x - width / 2, y - height / 2);
        glEnd();
    }

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - width / 2, y + height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x - width / 2, y - height / 2);
    glEnd();
}


bool Rectangle::contains(float mx, float my) {
    return mx >= x - width / 2 && mx <= x + width / 2 && my >= y - height / 2 && my <= y + height / 2;
}

void Rectangle::move(float dx, float dy){
    x += dx;
    y += dy;
}

void Rectangle::resize(float factor){
    width *= factor;
    height *= factor;
}

void Rectangle::setColor(float newR, float newG, float newB){
    r = newR;
    g = newG;
    b = newB;
}

void Rectangle::getColor(float& rOut, float& gOut, float& bOut) const{
    rOut = r;
    gOut = g;
    bOut = b;
}