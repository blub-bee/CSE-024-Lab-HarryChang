#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point: public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;

    void draw() override;
    bool contains(float mx, float my) override;
    void move(float dx, float dy) override;
    void resize(float factor) override;
    void setColor(float r, float g, float b) override;
    void getColor(float& rOut, float& gOut, float& bOut) const override;
};

#endif