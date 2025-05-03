#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"
#include "Canvas.h"

class ColorSelector : public bobcat::Group {
    bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;
    bobcat::Button* rgbColorButton;

    Canvas* canvas = nullptr;

    COLOR color;
    void deselectAllColors();
    void visualizeSelectedColor();
    void onClick(bobcat::Widget* sender);

public:
    float rgbR = 0.0;
    float rgbG = 0.0;
    float rgbB = 0.0;

    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;
    
    void setCanvas(Canvas* c);

    friend struct AppTest;
};

#endif