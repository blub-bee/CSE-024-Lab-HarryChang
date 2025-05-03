#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw() {
    if (isSelected && !points.empty()) {
        float minX = points[0]->getX(), maxX = minX;
        float minY = points[0]->getY(), maxY = minY;

        for (Point* pt : points) {
            float x = pt->getX();
            float y = pt->getY();
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }


        glColor3f(1.0f, 1.0f, 0.0f);
        glLineWidth(2.5f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(minX - 0.01f, maxY + 0.01f);
            glVertex2f(maxX + 0.01f, maxY + 0.01f);
            glVertex2f(maxX + 0.01f, minY - 0.01f);
            glVertex2f(minX - 0.01f, minY - 0.01f);
        glEnd();
    }

    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->draw();
    }
}


Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}

bool Scribble::contains(float mx, float my) {
    for (Point* pt : points) {
        if (pt->contains(mx, my)) {
            return true;
        }
    }
    return false;
}

void Scribble::move(float dx, float dy) {
    for (Point* pt : points) {
        pt->move(dx, dy);
    }
}

void Scribble::resize(float factor) {
    float cx = 0, cy = 0;
    for (Point* pt : points) {
        cx += pt->getX();
        cy += pt->getY();
    }
    if (points.empty()) return;
    cx /= points.size();
    cy /= points.size();

    for (Point* pt : points) {
        float newX = cx + (pt->getX() - cx) * factor;
        float newY = cy + (pt->getY() - cy) * factor;
        float size = pt->getSize() * factor;
        *pt = Point(newX, newY, pt->getR(), pt->getG(), pt->getB(), static_cast<int>(size));
    }
}

void Scribble::setColor(float r, float g, float b) {
    for (Point* pt : points) {
        pt->setColor(r, g, b);
    }
}

void Scribble::getColor(float& rOut, float& gOut, float& bOut) const {
    if (!points.empty()) {
        points[0]->getColor(rOut, gOut, bOut);
    } else {
        rOut = gOut = bOut = 0;
    }
}