#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) override;
    void move(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    void getColor(float& rOut, float& gOut, float& bOut) const override;
};

#endif