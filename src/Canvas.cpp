#include "Canvas.h"
#include "Circle.h"
#include "Scribble.h"
#include "Triangle.h"
#include "Polygon.h"
#include <GL/freeglut.h>
#include <cstdlib>
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}

void Canvas::addTriangle(float x, float y, float length, float height, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, length, height, r, g, b));
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, sides, length, r, g, b));
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::deleteSelected() {
    if (selected) {
        auto shape = std::find(shapes.begin(), shapes.end(), selected);
        if (shape != shapes.end()) {
            delete *shape;
            shapes.erase(shape);
        }
        selected = nullptr;
    }
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    if (curr){
        curr->draw();
    }
}

void Canvas::startScribble(){
    curr = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    if (curr){
        curr->addPoint(x, y, r, g, b, size);
    }
}

void Canvas::endScribble(){
    if (curr){
        shapes.push_back(curr);
        curr = nullptr;
    }
}

void Canvas::selectShapeAt(float x, float y){
    selected = nullptr;

    for (int i = shapes.size() - 1; i >= 0; i--){
        if (shapes[i]->contains(x, y)) {
            selected = shapes[i];
            selected->isSelected = true;
            break;
        }
    }

    for (Shape* shape : shapes) {
        if (shape != selected) {
            shape->isSelected = false;
        }
    }
}

void Canvas::storeLastMouse(float x, float y) {
    lastMouseX = x;
    lastMouseY = y;
}

void Canvas::dragSelectedTo(float newX, float newY){
    if (selected) {
        float dx = newX - lastMouseX;
        float dy = newY - lastMouseY;
        selected->move(dx, dy);
        storeLastMouse(newX, newY);
    }
}

void Canvas::resizeSelected(float factor) {
    if (selected) {
        selected->resize(factor);
    }
}

void Canvas::changeSelectedColor(float r, float g, float b) {
    if (selected) {
        selected->setColor(r, g, b);
    }
}

void Canvas::bringSelectedToFront() {
    if (selected) {
        auto it = std::find(shapes.begin(), shapes.end(), selected);
        if (it != shapes.end()) {
            shapes.erase(it);
            shapes.push_back(selected);
        }
    }
}

void Canvas::sendSelectedToBack() {
    if (selected) {
        auto it = std::find(shapes.begin(), shapes.end(), selected);
        if (it != shapes.end()) {
            shapes.erase(it);
            shapes.insert(shapes.begin(), selected);
        }
    }
}

void Canvas::updateSelectedShapeColor(float r, float g, float b) {
    if (selected) {
        selected->setColor(r, g, b);
    }
}

bool Canvas::hasSelection() const {
    return selected != nullptr;
}

