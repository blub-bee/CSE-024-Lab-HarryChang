#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);

    bringToFrontButton->color(FL_BACKGROUND_COLOR);
    sendToBackButton->color(FL_BACKGROUND_COLOR);

    increaseSizeButton->color(FL_BACKGROUND_COLOR);
    decreaseSizeButton->color(FL_BACKGROUND_COLOR);

    selectorButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == SENDTOBACK) {
        bringToFrontButton->color(FL_WHITE);
    }
    else if (tool == SENDTOFRONT) {
        sendToBackButton->color(FL_WHITE);
    }
    else if (tool == PLUS) {
        increaseSizeButton->color(FL_WHITE);
    }
    else if (tool == MINUS) {
        decreaseSizeButton->color(FL_WHITE);
    }
    else if (tool == SELECTOR) {
        selectorButton->color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();
    action = NONE;

    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER;
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        tool = POLYGON;
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }
    else if (sender == bringToFrontButton) {
        action = FRONT;
    }
    else if (sender == sendToBackButton) {
        action = BACK;
    }
    else if (sender == increaseSizeButton){
        action = INCREASE;
    }
    else if (sender == decreaseSizeButton){
        action = DECREASE;
    }
    else if (sender == selectorButton) {
        tool = SELECTOR;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton        = new Image(x, y +   0, 50, 40, "./assets/pencil.png");
    eraserButton        = new Image(x, y +  40, 50, 40, "./assets/eraser.png");
    circleButton        = new Image(x, y +  80, 50, 40, "./assets/circle.png");
    triangleButton      = new Image(x, y + 120, 50, 40, "./assets/triangle.png");
    rectangleButton     = new Image(x, y + 160, 50, 40, "./assets/rectangle.png");
    polygonButton       = new Image(x, y + 200, 50, 40, "./assets/polygon.png");
    selectorButton      = new Image(x, y + 240, 50, 40, "./assets/mouse.png");
    clearButton         = new Image(x, y + 280, 50, 40, "./assets/clear.png");
    bringToFrontButton  = new Image(x, y + 320, 50, 40, "./assets/bring-to-front.png");
    sendToBackButton    = new Image(x, y + 360, 50, 40, "./assets/send-to-back.png");
    increaseSizeButton  = new Image(x, y + 400, 50, 40, "./assets/minus.png");
    decreaseSizeButton  = new Image(x, y + 440, 50, 40, "./assets/plus.png");

    tool = PENCIL;
    action = NONE;

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    bringToFrontButton->box(FL_BORDER_BOX);
    sendToBackButton->box(FL_BORDER_BOX);

    increaseSizeButton->box(FL_BORDER_BOX);
    decreaseSizeButton->box(FL_BORDER_BOX);
    selectorButton->box(FL_BORDER_BOX);    

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);

    ON_CLICK(bringToFrontButton, Toolbar::onClick);
    ON_CLICK(sendToBackButton, Toolbar::onClick);

    ON_CLICK(increaseSizeButton, Toolbar::onClick);
    ON_CLICK(decreaseSizeButton, Toolbar::onClick);

    ON_CLICK(selectorButton, Toolbar::onClick);    
}