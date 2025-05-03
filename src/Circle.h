#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) override;
    void move(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    void getColor(float& rOut, float& gOut, float& bOut) const override;
};

#endif