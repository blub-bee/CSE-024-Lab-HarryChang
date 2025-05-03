#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw() override;

    bool contains(float mx, float my) override;
    void move(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    void getColor(float& rOut, float& gOut, float& bOut) const override;

    ~Scribble();
};
#endif