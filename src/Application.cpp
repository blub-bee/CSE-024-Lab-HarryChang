#include "Application.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, 1, 1, 1, 14);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 6, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == SELECTOR) {
        canvas->selectShapeAt(mx, my);
        canvas->storeLastMouse(mx, my);
        canvas->redraw();
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    //enum TOOL {PENCIL, ERASER, CIRCLE, TRIANGLE, RECTANGLE, POLYGON, SENDTOFRONT, SENDTOBACK, PLUS, MINUS, SELECTOR};

    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == SELECTOR) {
        canvas->dragSelectedTo(mx, my);
        canvas->redraw();
    }
}


void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
    }
    else if (action == INCREASE) {
        canvas->resizeSelected(0.8f);
    }
    else if (action == DECREASE) {
        canvas->resizeSelected(1.2f);
    }
    else if (action == FRONT) {
        canvas->bringSelectedToFront();
    }
    else if (action == BACK) {
        canvas->sendSelectedToBack();
    }

    Color c = colorSelector->getColor();
    canvas->changeSelectedColor(c.getR(), c.getG(), c.getB());

    canvas->redraw();
}


Application::Application() {
    window = new Window(25, 75, 550, 550, "Project");

    toolbar = new Toolbar(0, 0, 50, 550);
    toolbar->box(FL_BORDER_BOX);
    canvas = new Canvas(50, 0, 500, 500);
    colorSelector = new ColorSelector(50, 500, 500, 50);
    colorSelector->box(FL_BORDER_BOX);
    colorSelector->setCanvas(canvas);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    window->show();
}