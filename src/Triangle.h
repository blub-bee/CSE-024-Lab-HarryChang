#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    float x;
    float y;
    float base;
    float height;
    float r;
    float g;
    float b;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) override;
    void move(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    void getColor(float& rOut, float& gOut, float& bOut) const override;
};

#endif