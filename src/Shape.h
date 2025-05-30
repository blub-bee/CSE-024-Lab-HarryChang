#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

class Shape{

public:
    bool isSelected = false;

    virtual void draw() = 0;
    virtual bool contains(float x, float y) = 0;
    virtual void move(float dx, float dy) = 0;
    virtual void resize(float factor) = 0;
    virtual void setColor(float r, float g, float b) = 0;
    virtual void getColor(float& r, float& g, float& b) const = 0;

    virtual ~Shape(){}
};

#endif