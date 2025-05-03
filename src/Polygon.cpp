#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Polygon::Polygon(float x, float y, int sides, float length, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->sides = sides;
    this->length = length;
    this->r = r;
    this->g = g;
    this->b = b;
}

void drawHighlightPolygon(float x, float y, int sides, float length) {
    glColor3f(1.0f, 1.0f, 0.0f); // bright yellow
    glLineWidth(2.5f);
    glBegin(GL_LINE_LOOP);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + cos(theta) * length, y + sin(theta) * length);
        }
    glEnd();
}

void Polygon::draw() {
    if (isSelected) {
        drawHighlightPolygon(x, y, sides, length + 0.01f); // slight glow offset
    }

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
        }
    glEnd();
}


bool Polygon::contains(float mx, float my) {
    // Simple bounding circle check
    float dx = mx - x;
    float dy = my - y;
    float radius = length;
    return dx * dx + dy * dy <= radius * radius;
}

void Polygon::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Polygon::resize(float factor) {
    length *= factor;
}

void Polygon::setColor(float newR, float newG, float newB) {
    r = newR;
    g = newG;
    b = newB;
}

void Polygon::getColor(float& rOut, float& gOut, float& bOut) const {
    rOut = r;
    gOut = g;
    bOut = b;
}