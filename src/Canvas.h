#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* curr;
    Shape* selected = nullptr;
    float lastMouseX = 0, lastMouseY = 0;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b);

    void addCircle(float x, float y, float r, float g, float b);

    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);

    void deselectAllShapes();

    void clear();

    void startScribble();

    void updateScribble(float x, float y, float r, float g, float b, int size);

    void endScribble();

    void render();

    void selectShapeAt(float x, float y);
    void storeLastMouse(float x, float y);
    void dragSelectedTo(float newX, float newY);
    void resizeSelected(float factor);
    void changeSelectedColor(float r, float g, float b);
    void bringSelectedToFront();
    void sendSelectedToBack();
    void updateSelectedShapeColor(float r, float g, float b);
    bool hasSelection() const;
};

#endif